using Rvcss.Shared.Models;

namespace Rvcss.Orchestrator.Services;
internal interface IWorkerToolkitInternal
{
    #region Properties
    int Version { get; set; }
    string VersionFriendly { get; set; }
    #endregion
    #region Methods
    public void Startup();
    public void EnumerateAsyncStateMachine();
    public void End();
    public void MountWorkerFromType(Type type);
    public void CompileAndMountWorkerFromSource(IReadOnlyCollection<CodeFile> codeFiles);
    public void UnmountWorker();
    public byte[]? SerializeFromStorage(long maxBytes);
    public void DeserializeToStorage(byte[]? serializedStorage);
    public void WorkerInvokeVoid(string methodName);
    public object WorkerInvoke(string methodName, object?[]? @params);
    #endregion
}
