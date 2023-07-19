using System.Diagnostics;
using System.Runtime.CompilerServices;

using DotNetIsolator;

using Rvcss.Orchestrator.Services;
using Rvcss.Shared.Entities;
using Rvcss.Shared.Services;

using Wasmtime;

using Xunit.Abstractions;

namespace Rvcss.Orchestrator.Tests.StressTests;
public class GeneralStressTests
{
    public GeneralStressTests(ITestOutputHelper output)
    {
        this.output = output;
    }

    [Fact(Skip = "Runtime too long on DotNetIsolator")]
    public async Task PrimeSieveTest()
    {
        // Set up the runtime
        WasiConfiguration wasiConfiguration = new WasiConfiguration()
            .WithInheritedStandardOutput()
            .WithInheritedStandardError()
            ;
        // Start runtime
        using var host = new IsolatedRuntimeHost()
            .WithBinDirectoryAssemblyLoader()
            .WithWasiConfiguration(wasiConfiguration);
        using var isolatedRuntime = new IsolatedRuntime(host);
        // Create worker abstraction.
        using var mediator = Mediator.CreateFromWorkerType<PrimeSiever>(isolatedRuntime);

        int primeMaxSize = 100_000;
        output.WriteLine($"Finding Primes in domain [1-{primeMaxSize}]");
        Stopwatch stopwatch = Stopwatch.StartNew();
        int[] primeSieveResults = mediator.Invoke<int, int[]>(nameof(PrimeSiever.PrimeSieve), primeMaxSize);
        //int[] primeSieveResults = new PrimeSiever().PrimeSieve(primeMaxSize);
        stopwatch.Stop();
        output.WriteLine($"Prime Sieve Elapsed = {stopwatch.Elapsed.TotalMilliseconds}ms");
        output.WriteLine($"Primes: {string.Join(", ", primeSieveResults)}");
        await Task.Delay(TimeSpan.FromSeconds(3));

        // Dispose early to show that worker end method is called.
        mediator.Dispose();
        await Task.Delay(TimeSpan.FromSeconds(1));
    }



    static string FormatTimeSpan(TimeSpan timeSpan)
    {
        return timeSpan.ToString(@"h' Hours, 'm' minutes, 's' seconds, 0.'ffffff' fractional seconds'");
    }

    private class PrimeSiever : IArmaWorker
    {
        public async Task StartupAsync(ArmaWorkerArgs args, CancellationToken cancellationToken) { }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="maxNumber">10000000</param>
        /// <returns></returns>
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

        public async Task EndAsync(CancellationToken cancellationToken) { }
    }

    readonly ITestOutputHelper output;
}
