using System;
using System.Runtime.InteropServices;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using RV;
namespace arma_code
{
    public static class Printer
    {
        public delegate void CustomEntryPointDelegate();
        public static void EntryLocation()
        {
            //GameValue test = new GameValue(10.0f);
            //Console.WriteLine("VTable Points to: {0:X8}", test.Data.Get().ToInt64());
            //GameDataNumber dataNumber = Marshal.PtrToStructure<GameDataNumber>(test.Data.Get());
            //float valueFromGameData = dataNumber.number;

            //ref GameDataNumber dataNumber = ref test.Data.GetAs<GameDataNumber>();
            //GameDataSafe<GameDataNumber> safeNumber = new() {Number = dataNumber};

            //Apple<GameDataNumberSafe> a = new() {Item = safeNumber};
            //safeNumber.Number.number = 20.0f;
            //dataNumber.number = 20.0f;
            //Console.WriteLine("Float value: {0}", dataNumber.number);
            //GameValue.TestGamePointer(test);

            AutoArray autoArrayTest = new AutoArray();
            GameValue.TestAutoArray(autoArrayTest);

            AutoArray auto = new AutoArray();
            unsafe
            {
                GameValue[] array = { new(20.0f), new("String!"), new(30.0f), new(new Vector3(300.31f, 2200.34f, 1516.4f)) };
                IntPtr myMemory = RealVirtualAllocator.Allocate(Marshal.SizeOf<GameValue>());
                //IntPtr myMemory = Marshal.AllocHGlobal(Marshal.SizeOf<GameValue>());
                IntPtr arrayMemory = RealVirtualAllocator.Allocate(Marshal.SizeOf<GameValue>() * 3);
                GameValue tempStruct = new(10.4f);
                Marshal.StructureToPtr<GameValue>(tempStruct, myMemory, false);
                byte[] result = new byte[array.Length * Marshal.SizeOf<GameValue>()];
                Buffer.BlockCopy(array, 0, result, 0, result.Length);
                Marshal.Copy(result, 0, arrayMemory, result.Length);
                auto.PushBack(*(GameValue*)myMemory.ToPointer());
                GameValue test2 = new(arrayMemory);
                GameValue.TestGamePointer(test2);
            }
            //GameValue.TestAutoArray(auto);

        }
        // public class Apple<T> {
        //     public required T Item;
        // }

        // public ref struct GameDataSafe<T> where T: struct {
        //      public T Number;
        // }
    }
}
