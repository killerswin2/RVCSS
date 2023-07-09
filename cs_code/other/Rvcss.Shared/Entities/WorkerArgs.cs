using Rvcss.Shared.Services;

namespace Rvcss.Shared.Entities;
public class ArmaWorkerArgs
{
    public required IWorkerToolkit Toolkit { get; init; }
    public required IArma3 Arma3 { get; init; }
}
