using System.Reflection;

using DotNetIsolator;

using Rvcss.Orchestrator.Utilities;
using Rvcss.Shared.Entities;
using Rvcss.Shared.Models;
using Rvcss.Shared.Services;

namespace Rvcss.Orchestrator.Services;
internal class WorkerToolkit : IWorkerToolkitInternal, IWorkerToolkit
{
    public WorkerToolkit()
    {
        WasmAsyncManager.Install(workerCancellationSource.Token);
        workerArgs = new() {
            Toolkit = this,
            Arma3 = null!
        };
    }
    #region Properties

    public int Version { get; set; } = -1;
    public string VersionFriendly { get; set; } = string.Empty;

    public string AppNamespace { get; } = string.Empty;
    public int InstanceId { get; } = 0;


    public string SerializedStorageTag { get; set; } = string.Empty;
    public byte[]? SerializedStorage { get; set; }
    public TimeSpan AsyncStateMachineTickRateMin { get; set; } = TimeSpan.Zero;
    public double MaxComputationTimeShare { get; set; } = 1.0;

    public void CompileAndMountWorkerFromSource(IReadOnlyCollection<CodeFile> codeFiles) => throw new NotImplementedException();
    public void DeserializeToStorage(byte[]? serializedStorage) => throw new NotImplementedException();
    public byte[]? SerializeFromStorage(long maxBytes) => throw new NotImplementedException();

    public IArmaWorker? Worker => worker;
    #endregion

    #region Public Methods
    public void End()
    {
        if (worker is not null)
            UnmountWorker();
    }
    public void EnumerateAsyncStateMachine() => WasmAsyncManager.EnumerateAsyncStateMachine();

    public void MountWorkerFromType(Type type) {
        if (worker is not null)
            UnmountWorker();
        var constructor = type.GetConstructor(Array.Empty<Type>());
        worker = constructor?.Invoke(Array.Empty<object>()) as IArmaWorker;
    }
    public void Startup()
    {
        if (isWorkerStarted || worker is null)
            return;
        isWorkerStarted = true;
        worker.StartupAsync(workerArgs, workerCancellationSource.Token);
    }

    public void UnmountWorker() {
        if (worker is null)
            return;
        if (isWorkerStarted)
        {
            worker.EndAsync(workerCancellationSource.Token);
            isWorkerStarted = false;
        }
        worker = null;
    }
    public void WorkerInvokeVoid(string methodName)
    {
        if (worker?.GetType().GetMethod(methodName) is not MethodInfo method)
            return;
        method.Invoke(worker, null);
    }

    public object? WorkerInvoke(string methodName, object?[]? @params)
    {
        if (worker?.GetType().GetMethod(methodName) is not MethodInfo method)
            return null;
        return method.Invoke(worker, @params);
    }
    #endregion

    #region Private Fields
    IArmaWorker? worker;
    bool isWorkerStarted = false;
    readonly ArmaWorkerArgs workerArgs;
    readonly CancellationTokenSource workerCancellationSource = new();
    #endregion
}
