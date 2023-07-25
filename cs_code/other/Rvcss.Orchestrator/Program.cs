using System.Diagnostics;

using DotNetIsolator;

using Rvcss.Orchestrator.Services;

using Wasmtime;

namespace HostForWasmConsole;

internal class Program
{
    static async Task Main(string[] args)
    {
        // Set up the runtime
        WasiConfiguration wasiConfiguration = new WasiConfiguration()
            .WithInheritedStandardOutput()
            .WithInheritedStandardError()
            //.WithPreopenedDirectory(Path.Combine(Environment.CurrentDirectory, "\\DummyDir"), "/")
        ;
        // Start runtime
        using var host = new IsolatedRuntimeHost()
            .WithWasiConfiguration(wasiConfiguration)
            .WithAssemblyLoader(LoadAssembly);
        using var isolatedRuntime = new IsolatedRuntime(host);
        // Create worker abstraction.
        using var mediator = Mediator.CreateFromWorkerType<Rvcss.ExampleWorker.Program>(isolatedRuntime);
        mediator.InvokeVoid(nameof(Rvcss.ExampleWorker.Program.LogThing));

        await Task.Delay(TimeSpan.FromSeconds(3));

        // Dispose early to show that worker end method is called.
        mediator.Dispose();
        await Task.Delay(TimeSpan.FromSeconds(1));
    }

    static byte[]? LoadAssembly(string assemblyName)
    {
        string directoryPath = Path.GetDirectoryName(typeof(IsolatedRuntimeHost)!.Assembly.Location)!;
        string path = Path.Combine(directoryPath, assemblyName + ".dll");
        return !File.Exists(path) ? null : File.ReadAllBytes(path);
    }
}

