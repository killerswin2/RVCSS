namespace Rvcss.Orchestrator.Utilities;
internal class WasmSynchronizationContext : SynchronizationContext
{
    private bool done;
    public Exception? InnerException { get; set; }
    readonly AutoResetEvent workItemsWaiting = new(false);
    readonly Queue<Tuple<SendOrPostCallback, object?>> items = new();

    public override void Send(SendOrPostCallback d, object? state)
    {
        throw new NotSupportedException("We cannot send to our same thread");
    }

    public override void Post(SendOrPostCallback d, object? state)
    {
        lock (items)
        {
            items.Enqueue(Tuple.Create(d, state));
        }
        workItemsWaiting.Set();
    }

    public void EndMessageLoop()
    {
        Post(_ => done = true, null);
    }

    public void BeginMessageLoop()
    {
        while (!done)
        {
            Tuple<SendOrPostCallback, object?>? task = null;
            lock (items)
            {
                if (items.Count > 0)
                {
                    task = items.Dequeue();
                }
            }
            if (task is not null)
            {
                task.Item1(task.Item2);
                if (InnerException != null) // the method threw an exception
                {
                    throw new AggregateException("AsyncHelpers.Run method threw an exception.", InnerException);
                }
            }
            else
            {
                done = true;
                //workItemsWaiting.WaitOne();
            }
        }
    }

    public override SynchronizationContext CreateCopy()
    {
        return this;
    }
}


