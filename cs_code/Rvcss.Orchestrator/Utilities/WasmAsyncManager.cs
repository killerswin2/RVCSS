using System.Diagnostics.CodeAnalysis;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Rvcss.Orchestrator.Utilities;

internal static class WasmAsyncManager
{
    #region Public Methods
    public static void Install(CancellationToken globalCancellationToken)
    {
        if (!IsWasm)
            return;
        if (IsInstalled)
            return;
        IsInstalled = true;

        cancellationToken = globalCancellationToken;
        synchronizationContext = new();
        SynchronizationContext.SetSynchronizationContext(synchronizationContext);
        taskScheduler = new WasmTaskScheduler(synchronizationContext);
        taskFactory = new TaskFactory(cancellationToken, TaskCreationOptions.None, TaskContinuationOptions.None, taskScheduler);

        typeof(TaskScheduler)
           .GetField("s_defaultTaskScheduler", BindingFlags.Static | BindingFlags.NonPublic)!
           .SetValue(null, taskScheduler);
    }

    public static void EnumerateAsyncStateMachine()
    {
        if (!IsInstalled)
            return;
        synchronizationContext.BeginMessageLoop();
        WasmDelay.RefreshDelayCallbacks();
    }
    #endregion

    #region Properties
    public static bool IsWasm { get; } = RuntimeInformation.OSArchitecture == Architecture.Wasm;
    [MemberNotNullWhen(true, nameof(synchronizationContext), nameof(taskScheduler), nameof(taskFactory))]
    public static bool IsInstalled { get; private set; } = false;
    #endregion

    #region Fields
    static CancellationToken cancellationToken;
    static WasmSynchronizationContext? synchronizationContext;
    static WasmTaskScheduler? taskScheduler;
    static TaskFactory? taskFactory;
    #endregion
}
