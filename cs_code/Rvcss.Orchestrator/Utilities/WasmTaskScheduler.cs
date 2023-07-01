namespace Rvcss.Orchestrator.Utilities;

internal class WasmTaskScheduler : TaskScheduler
{
    private readonly WasmSynchronizationContext syncContext;

    public WasmTaskScheduler(WasmSynchronizationContext syncContext)
    {
        this.syncContext = syncContext;
    }

    protected override void QueueTask(Task task)
    {
        syncContext.Post(_ => TryExecuteTask(task), null);
    }

    protected override bool TryExecuteTaskInline(Task task, bool taskWasPreviouslyQueued)
    {
        return false; // ToDo try pop one item or something.
    }

    protected override IEnumerable<Task> GetScheduledTasks()
    {
        return Enumerable.Empty<Task>();
    }

    public override int MaximumConcurrencyLevel => 1;
}
