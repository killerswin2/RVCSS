using Rvcss.Shared.Entities;

namespace Rvcss.Shared.Services;
public interface IArmaWorker
{
    #region Methods
    public Task StartupAsync(ArmaWorkerArgs args, CancellationToken cancellationToken);
    public Task EndAsync(CancellationToken cancellationToken);
    #endregion
}
