using System.Diagnostics;

using DotNetIsolator;

using Wasmtime;

namespace Rvcss.Orchestrator.Tests.StressTests;

public class DotNetIsolatorTests
{
    [Fact]
    public async Task LargeDataTransferTest()
    {
        // Set up the runtime
        WasiConfiguration wasiConfiguration = new WasiConfiguration()
            .WithInheritedStandardOutput()
            .WithInheritedStandardError()
            //.WithPreopenedDirectory(Path.Combine(Environment.CurrentDirectory, "\\DummyDir"), "/")
            ;
        // Start runtime
        using var host = new IsolatedRuntimeHost()
            .WithAssemblyLoader(LoadAssembly);
        using var isolatedRuntime = new IsolatedRuntime(host);


        // 1 Megabyte of bytes
        // Maximum bytes without crash: 7752419, 0b0111_0110_0100_1010_1110_0011
        const int bytesToGenerate = 0b0111_0110_0100_1010_1110_0011;
        int interations = 1;
        Random seedGenerator = new();
        Stopwatch stopwatch = new();
        IsolatedObject isolatedByteGenerator = isolatedRuntime.CreateObject<ReturnManyPseudoRandomByteGenerator>();
        GC.Collect();
        stopwatch.Restart();
        // Native Execution of random bytes
        for (int i = 0; i < interations; i++)
        {
            new ReturnManyPseudoRandomByteGenerator().GenerateBytes(1, bytesToGenerate);
        }
        TimeSpan nativeExecutionTime = stopwatch.Elapsed;
        GC.Collect();
        stopwatch.Restart();
        // Wasm Execution of random bytes
        for (int i = 0; i < interations; i++)
        {
            isolatedByteGenerator.Invoke<int, int, byte[]>("GenerateBytes", seedGenerator.Next(), bytesToGenerate);
            GC.Collect();
            await Task.Delay(TimeSpan.FromSeconds(3));
            GC.Collect();
        }
        TimeSpan isolatedExecutionTime = stopwatch.Elapsed;
        GC.Collect();
        Console.WriteLine($"Native execution time: {FormatTimeSpan(nativeExecutionTime)}");
        Console.WriteLine($"Isolated execution time: {FormatTimeSpan(isolatedExecutionTime)}");
    }



    static string FormatTimeSpan(TimeSpan timeSpan)
    {
        return timeSpan.ToString(@"h' Hours, 'm' minutes, 's' seconds, 0.'ffffff' fractional seconds'");
    }

    static byte[]? LoadAssembly(string assemblyName)
    {
        string directoryPath = Path.GetDirectoryName(typeof(IsolatedRuntimeHost)!.Assembly.Location)!;
        string path = Path.Combine(directoryPath, assemblyName + ".dll");
        return !File.Exists(path) ? null : File.ReadAllBytes(path);
    }

    class ReturnManyPseudoRandomByteGenerator
    {
        public byte[] GenerateBytes(int seed, int count)
        {
            Random random = new(seed);
            byte[] bytes = new byte[count];
            random.NextBytes(bytes);
            return bytes;
        }
    }
}