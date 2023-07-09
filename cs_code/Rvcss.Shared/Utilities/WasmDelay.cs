namespace Rvcss.Orchestrator.Utilities;
public static class WasmDelay
{
    public static void TriggerAfter(Action callback, TimeSpan delay)
    {
        TriggerOn(callback, DateTime.Now + delay);
    }

    public static void TriggerOn(Action callback, DateTime notBefore)
    {
        if (notBefore <= DateTime.Now)
        {
            callback();
            return;
        }
        lock (@lock)
        {
            callbacks.Add((callback, notBefore));
        }
    }

    public static void RefreshDelayCallbacks()
    {
        lock (@lock)
        {
            for (int i = callbacks.Count - 1; i >= 0; i--)
            {
                (Action callback, DateTime notBefore) = callbacks[i];
                if (notBefore > DateTime.Now)
                    continue;
                callbacks.RemoveAt(i);
                callback();
            }
        }
    }

    public static Task Delay(TimeSpan delay)
    {
        var tcs = new TaskCompletionSource<bool>();
        TriggerAfter(() => tcs.SetResult(true), delay);
        return tcs.Task;
    }

    static readonly List<(Action callback, DateTime notBefore)> callbacks = new();
    static readonly object @lock = new();
}
