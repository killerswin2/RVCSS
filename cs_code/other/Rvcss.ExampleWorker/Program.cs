using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;
using System.Text;

using Rvcss.Orchestrator.Utilities;
using Rvcss.Shared.Entities;
using Rvcss.Shared.Services;

namespace Rvcss.ExampleWorker;

public class Program : IArmaWorker
{
    public static async Task Main()
    {
        Console.WriteLine("Hello, this app is intended to run from the HostForWasmConsole. However, this can be used as a debugging method.");


        Program isolatedWorker = new();
        _ = Task.Run(() => isolatedWorker.StartupAsync(new() { Arma3 = null!, Toolkit = new MockWorkerToolkit()}, default));
        await Task.Delay(TimeSpan.FromSeconds(1));

        isolatedWorker.SetTaskCompletionSource();

        await Task.Delay(TimeSpan.FromSeconds(1));

        // Dispose early to show that worker end method is called.
        _ = Task.Run(() => isolatedWorker.EndAsync(default));

        await Task.Delay(TimeSpan.FromSeconds(1));
    }

    class MockWorkerToolkit : IWorkerToolkit
    {
        public int Version => 1;
        public string VersionFriendly => "Mock worker";
        public string AppNamespace => "Mock AppNamespace";

        public int InstanceId => 0;

        public string SerializedStorageTag { get; set; } = string.Empty;
        public byte[]? SerializedStorage { get; set; }
        public TimeSpan AsyncStateMachineTickRateMin { get; set; } = TimeSpan.Zero;
        public double MaxComputationTimeShare { get; set; } = 1.0;
    }

    public Program()
    {
        Console.WriteLine("Hello from the Arma Worker constructor");
        args = null!;
    }

    public async Task StartupAsync(ArmaWorkerArgs args, CancellationToken cancellationToken)
    {
        this.args = args;
        Console.WriteLine("Hello from the Arma Worker app startup async");
        Console.WriteLine($"Loaded on host version: {args.Toolkit.Version}, {args.Toolkit.VersionFriendly}; runtime: {RuntimeInformation.OSArchitecture}");

        await Task.Run(() =>
        {
            Console.WriteLine($"Hello nested Task.Run.");
        }, cancellationToken);

        _ = Task.Factory.StartNew(() =>
        {
            Console.WriteLine($"Hello from Task.Factory.StartNew.");
        }, cancellationToken);

        await tcs.Task;
        Console.WriteLine("Finished awaiting tcs.Task");
        await WasmDelay.Delay(TimeSpan.FromSeconds(1));
        Console.WriteLine("Finished awaiting Task.Delay");
    }

    public void SetTaskCompletionSource()
    {
        Console.WriteLine($"Setting TaskCompletionSource!");
        tcs.SetResult();
    }

    public int[] PrimeSieve(int maxNumber)
    {
        Stopwatch stopwatch = Stopwatch.StartNew();
        bool[] primeSieveList = new bool[maxNumber - 1];

        int n = maxNumber - 1;
        int k = (int)double.Floor((n - 1) / 2.0);
        int sqrtK = (int)double.Floor(double.Sqrt(k));
        for (int i = 1; i < sqrtK; i++)
        {
            for (int j = i; (i + j + (2 * i * j)) <= k; j++)
            {
                primeSieveList[i + j + (2 * i * j)] = true;

            }
        }

        // https://t5k.org/howmany.html
        // P. Dusart, "The kth prime is greater than k(ln k+ln ln k-1) for k> 2," Math. Comp., 68:225 (January 1999)  411--415.  MR 99d:11133 (Abstract available)
        double ln(double x) => double.Log(x);
        int primeAmountUpperBound = (int)double.Ceiling(maxNumber * (ln(maxNumber) + ln(ln(maxNumber)) - 1));
        // Pre allocate space to avoid reallocaitons.
        List<int> primeList = new(primeAmountUpperBound);
        for (int index = 0; index < primeSieveList.Length; index++)
        {
            bool isNotPrime = primeSieveList[index];
            if (!isNotPrime)
                primeList.Add((index * 2) + 1);
        }
        stopwatch.Stop();
        Console.WriteLine($"In-Wasm Prime Sieve Elapsed = {stopwatch.Elapsed.TotalMilliseconds}ms");
        return Unsafe.As<int[]>(primeList);
    }

    public void LogThing()
    {
        Console.WriteLine("Thing");
    }

    public async Task EndAsync(CancellationToken cancellationToken)
    {
        Console.WriteLine("Hello from the Arma Worker app end");
        args.Toolkit.SerializedStorage = Array.Empty<byte>();
        await Task.CompletedTask;
    }


    readonly TaskCompletionSource tcs = new();
    ArmaWorkerArgs args;
}
