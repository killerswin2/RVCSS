using Rvcss.Shared.Entities;
using Rvcss.Shared.Services;

using Xunit.Abstractions;

namespace Rvcss.Orchestrator.Tests.StressTests;

public class AckermannFunctionTest
{
    public AckermannFunctionTest(ITestOutputHelper output)
    {
        this.output = output;
    }
    readonly ITestOutputHelper output;

    [Theory]
    [InlineData(0, 0, 1)]
    [InlineData(0, 1, 2)]
    [InlineData(0, 2, 3)]
    [InlineData(0, 3, 4)]
    [InlineData(0, 4, 5)]
    [InlineData(1, 0, 2)]
    [InlineData(1, 1, 3)]
    [InlineData(1, 2, 4)]
    [InlineData(1, 3, 5)]
    [InlineData(1, 4, 6)]
    [InlineData(2, 0, 3)]
    [InlineData(2, 1, 5)]
    [InlineData(2, 2, 7)]
    [InlineData(2, 3, 9)]
    [InlineData(2, 4, 11)]
    [InlineData(3, 0, 5)]
    [InlineData(3, 1, 13)]
    [InlineData(3, 2, 29)]
    [InlineData(3, 3, 61)]
    [InlineData(3, 4, 125)]
    [InlineData(3, 5, 253)]
    [InlineData(3, 6, 509)]
    [InlineData(3, 7, 1021)]
    [InlineData(3, 8, 2045)]
    // Disabled for speedy completion
    //[InlineData(3, 9, 4093)]
    //[InlineData(3, 10, 8189)]
    // Rest are uncomputable with default stack size.
    //[InlineData(3, 11, 16381)]
    //[InlineData(3, 12, 32765)]
    //[InlineData(3, 13, 65533)]
    //[InlineData(3, 14, 131069)]
    [InlineData(4, 0, 13)]
    // Rest are uncomputable with default stack size.
    //[InlineData(4, 1, 65533)]
    //[InlineData(5, 0, 65533)]
    public void AckermannProducesExpectedResults(int m, int n, int result)
    {
        // Act
        int actualResult = AckermannRunner.Ackermann(m, n);
        // Assert
        Assert.Equal(result, actualResult);
    }

    [Theory]
    [InlineData(0, 0, 1)]
    [InlineData(0, 1, 2)]
    [InlineData(0, 2, 3)]
    [InlineData(0, 3, 4)]
    [InlineData(0, 4, 5)]
    [InlineData(1, 0, 2)]
    [InlineData(1, 1, 3)]
    [InlineData(1, 2, 4)]
    [InlineData(1, 3, 5)]
    [InlineData(1, 4, 6)]
    [InlineData(2, 0, 3)]
    [InlineData(2, 1, 5)]
    [InlineData(2, 2, 7)]
    [InlineData(2, 3, 9)]
    [InlineData(2, 4, 11)]
    [InlineData(3, 0, 5)]
    [InlineData(3, 1, 13)]
    [InlineData(3, 2, 29)]
    [InlineData(3, 3, 61)]
    [InlineData(3, 4, 125)]
    [InlineData(3, 5, 253)]
    [InlineData(3, 6, 509)]
    [InlineData(3, 7, 1021)]
    [InlineData(3, 8, 2045)]
    // Disabled for speedy completion
    //[InlineData(3, 9, 4093)]
    //[InlineData(3, 10, 8189)]
    //[InlineData(3, 11, 16381)]
    // Rest are uncomputable with default stack size.
    //[InlineData(3, 12, 32765)]
    //[InlineData(3, 13, 65533)]
    //[InlineData(3, 14, 131069)]
    [InlineData(4, 0, 13)]
    // Rest are uncomputable with default stack size.
    //[InlineData(4, 1, 65533)]
    //[InlineData(5, 0, 65533)]
    public void AckermannTailProducesExpectedResults(int m, int n, int result)
    {
        // Act
        int actualResult = AckermannRunner.AckermannTail(m, n);
        // Assert
        Assert.Equal(result, actualResult);
    }

    [Theory]
    [InlineData(0, 0, 1)]
    [InlineData(0, 1, 2)]
    [InlineData(0, 2, 3)]
    [InlineData(0, 3, 4)]
    [InlineData(0, 4, 5)]
    [InlineData(1, 0, 2)]
    [InlineData(1, 1, 3)]
    [InlineData(1, 2, 4)]
    [InlineData(1, 3, 5)]
    [InlineData(1, 4, 6)]
    [InlineData(2, 0, 3)]
    [InlineData(2, 1, 5)]
    [InlineData(2, 2, 7)]
    [InlineData(2, 3, 9)]
    [InlineData(2, 4, 11)]
    [InlineData(3, 0, 5)]
    [InlineData(3, 1, 13)]
    [InlineData(3, 2, 29)]
    [InlineData(3, 3, 61)]
    [InlineData(3, 4, 125)]
    [InlineData(3, 5, 253)]
    [InlineData(3, 6, 509)]
    [InlineData(3, 7, 1021)]
    [InlineData(3, 8, 2045)]
    // Disabled for speedy completion
    //[InlineData(3, 9, 4093)]
    //[InlineData(3, 10, 8189)]
    //[InlineData(3, 11, 16381)]
    //[InlineData(3, 12, 32765)]
    //[InlineData(3, 13, 65533)]
    //[InlineData(3, 14, 131069)]
    // Uses too large amounts of memory. Immense slow-down. Might complete, might not.
    //[InlineData(3, 15, 262141)]
    [InlineData(4, 0, 13)]
    // Disabled for speedy completion
    //[InlineData(4, 1, 65533)]
    //[InlineData(5, 0, 65533)]
    // Higher m's are uncomputable with all the storage in the world (1232 worlds to be exact).
    public void AckermannHeapProducesExpectedResults(int m, int n, int result)
    {
        // Act
        (int actualResult, int maxStackSize) = AckermannRunner.AckermannHeap(m, n);
        output.WriteLine($"Ack({m}, {n}) = {actualResult}; Max Stack: {maxStackSize}");
        // Assert
        Assert.Equal(result, actualResult);
    }


    [Theory]
    [InlineData(0, 5)]
    [InlineData(1, 13)]
    [InlineData(2, 29)]
    [InlineData(3, 61)]
    [InlineData(4, 125)]
    [InlineData(5, 253)]
    [InlineData(6, 509)]
    [InlineData(7, 1021)]
    [InlineData(8, 2045)]
    [InlineData(9, 4093)]
    [InlineData(10, 8189)]
    [InlineData(20, 8388605)]
    [InlineData(28, 2147483645)]
    [InlineData(29, 4294967293)]
    [InlineData(62, 18446744073709551615)]
    public void AckermannOf3MProducesExpectedResults(int n, ulong result)
    {
        // Act
        ulong actualResult = AckermannRunner.AckermannOf3M(n);
        if (result == 0)
        {
            output.WriteLine($"[InlineData({n}, {actualResult})]");
            return;
        }

        // Assert
        Assert.Equal(result, actualResult);
    }

    class AckermannRunner : IArmaWorker
    {
        public Task StartupAsync(ArmaWorkerArgs args, CancellationToken cancellationToken) {
            return Task.CompletedTask;
        }
        public Task EndAsync(CancellationToken cancellationToken) => Task.CompletedTask;

        /// <summary>
        /// From <see href="https://www.geeksforgeeks.org/ackermann-function/"/> C++ version. With return corrected.
        /// </summary>
        /// <param name="m"></param>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int Ackermann(int m, int n)
        {
            if (m == 0)
                return n + 1;
            if (m > 0 && n == 0)
                return Ackermann(m - 1, 1);
            if (m > 0 && n > 0)
                return Ackermann(m - 1, Ackermann(m, n - 1));
            return n + 1;
        }

        /// <summary>
        /// This only requires additional memory for one case rather than the previous three (Two of them are combined into one line).
        /// </summary>
        /// <param name="m"></param>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int AckermannTail(int m, int n)
        {
            Recurse:
            if (m > 0 && n == 0)
            {
                --m;
                n = 1;
                goto Recurse;
            }
            if (m > 0 && n > 0)
            {
                n = AckermannTail(m, n - 1);
                --m;
                goto Recurse;
            }
            return n + 1;
        }

        /// <summary>
        /// This is a version that uses the heap for storing a "stackOfM" instead of the stackOfM.<br/>
        /// Iterative improvement over <see cref="AckermannTail"/> to avoid the limited stack and utilize the computer's memory.<br/>
        /// This allows it to calculate higher returns than the call stack limited versions.<br/>
        /// Can compute Ack(4, 1) or Ack(5, 0) in around 12-15 seconds.<br/>
        /// </summary>
        /// <param name="m"></param>
        /// <param name="n"></param>
        /// <returns> In addition to the result of the ackermann's function. The maximum stack size is returned. </returns>
        public static (int ackResult, int maxStackSize) AckermannHeap(int m, int n)
        {
            // Heap allocated stack, allows for gigabytes of potential calculation.
            Stack<int> stackOfM = new();
            int maxStackSize = 0;
Recurse:
            maxStackSize = int.Max(maxStackSize, stackOfM.Count);
            if (m > 0 && n == 0)
            {
                --m;
                n = 1;
                goto Recurse;
            }
            if (m > 0 && n > 0)
            {
                stackOfM.Push(m - 1);
                --n;
                goto Recurse;
            }
            ++n;
            // If the stack has an item, it means we need to unwind the recursion.
            if (stackOfM.TryPop(out m))
                goto Recurse;
            return (n, maxStackSize);
        }

        public static ulong AckermannOf3M(int n)
        {
            return (1uL << (n + 3)) - 3;
        }
    }

}

