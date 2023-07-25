namespace Rvcss.Shared.Services;
public interface IWorkerToolkit
{
    int Version { get; }
    string VersionFriendly { get; }
    string AppNamespace { get; }
    int InstanceId { get; }

    string SerializedStorageTag { get; set; }
    byte[]? SerializedStorage { get; set; }
    TimeSpan AsyncStateMachineTickRateMin { get; set; }
    double MaxComputationTimeShare { get; set; }
}
