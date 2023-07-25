using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;

using DotNetIsolator;

using Rvcss.Shared.Services;

namespace Rvcss.Orchestrator.Services;
internal class Mediator : IMediatorInternal, IMediator, IDisposable
{
    public Mediator(IsolatedRuntime isolatedRuntime, Type workerType, CancellationToken cancellationToken = default) : this(isolatedRuntime)
    {
        isolatedObject.InvokeVoid(nameof(WorkerToolkit.MountWorkerFromType), workerType);
        isolatedObject.InvokeVoid(nameof(WorkerToolkit.Startup));

        workerTask = SpawnWorkerThread(cancellationToken);
    }

    public static Mediator CreateFromWorkerType<T>(IsolatedRuntime isolatedRuntime, CancellationToken cancellationToken = default) where T : IArmaWorker
    {
        Mediator mediator = new(isolatedRuntime);
        mediator.isolatedObject.InvokeVoid(nameof(WorkerToolkit.MountWorkerFromType), typeof(T));
        mediator.isolatedObject.InvokeVoid(nameof(WorkerToolkit.Startup));

        mediator.workerTask = mediator.SpawnWorkerThread(cancellationToken);
        return mediator;
    }

    private Mediator(IsolatedRuntime isolatedRuntime)
    {
        this.isolatedRuntime = isolatedRuntime;
        isolatedObject = isolatedRuntime.CreateObject<WorkerToolkit>() ?? throw new InvalidOperationException("Unable to create object of WorkerToolkit");

        isolatedObject.InvokeVoid($"set_{nameof(WorkerToolkit.Version)}", 1);
        isolatedObject.InvokeVoid($"set_{nameof(WorkerToolkit.VersionFriendly)}", "Version 1 Test Preview");
    }

    #region Public Methods
    public void InvokeVoid(string methodName)
    {
        lock (invokeLock)
        {
            isolatedObject.InvokeVoid(nameof(IWorkerToolkitInternal.WorkerInvokeVoid), methodName);
        }
    }

    public TRes? Invoke<T0, TRes>(string methodName, T0 param0)
    {
        lock (invokeLock)
        {
            return isolatedObject.Invoke<string, object?, TRes?>(nameof(IWorkerToolkitInternal.WorkerInvoke), methodName, new object?[] { param0 });
        }
    }

    public TRes? Invoke<T0, T1, TRes>(string methodName, T0 param0, T1 param1)
    {
        lock (invokeLock)
        {
            return isolatedObject.Invoke<string, object?, TRes?>(nameof(IWorkerToolkitInternal.WorkerInvoke), methodName, new object?[] { param0, param1 });
        }
    }
    #endregion

    #region Fields
    readonly IsolatedRuntime isolatedRuntime;
    readonly object invokeLock = new();
    Task? workerTask;
    readonly IsolatedObject isolatedObject;
    readonly CancellationToken cancellationToken;
    bool isDisposed;
    long issuedCallbackIds = 0;
    #endregion
    #region Private Methods

    Task SpawnWorkerThread( CancellationToken cancellationToken)
    {
        return Task.Factory.StartNew(
            RunWorkerAndBlockThread,
            state: this,
            cancellationToken,
            TaskCreationOptions.DenyChildAttach | TaskCreationOptions.HideScheduler | TaskCreationOptions.LongRunning | TaskCreationOptions.RunContinuationsAsynchronously,
            TaskScheduler.Default
        );
    }

    static void RunWorkerAndBlockThread(object? state)
    {
        Mediator mediator = state as Mediator ?? throw new ArgumentNullException(nameof(state));
        Console.WriteLine($"Hello from StartRuntimeAsyncWorker.");
        while (!mediator.isDisposed && !mediator.cancellationToken.IsCancellationRequested)
        {
            lock (mediator.invokeLock)
            {
                mediator.isolatedObject.InvokeVoid("EnumerateAsyncStateMachine");
            }
            Task.Yield();
        }
        lock (mediator.invokeLock)
        {
            mediator.isolatedObject.InvokeVoid("End");
        }
    }

    long GetNewCallbackId()
    {
        return Interlocked.Increment(ref issuedCallbackIds);
    }

    public void Dispose()
    {
        isDisposed = true;
    }
    #endregion
}
