using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Security;
using System.Text;
using System.Numerics;
using System.Collections;

namespace RV
{
    public unsafe class RealVirtualAllocator
    {
        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?Allocate@@YAPEAX_K@Z", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Allocate(int size);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?Deallocate@@YAXPEAX@Z", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Deallocate(IntPtr pointer);

    }

    public unsafe class RealVirtualPoolAllocator
    {
        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?Allocate@@YAPEAX_K@Z", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Allocate(int size);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?Deallocate@@YAXPEAX@Z", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Deallocate(IntPtr pointer);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?Reallocate@@YAXPEAX_K@Z", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Reallocate(IntPtr pointer, int size);
    }

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct AutoArray
    {
        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateAutoArray@@YA?AV?$auto_array@Vgame_value@types@intercept@@V?$rv_allocator@Vgame_value@types@intercept@@@23@$0IA@@types@intercept@@XZ", CallingConvention = CallingConvention.Cdecl)]
        private static extern AutoArray CreateAutoArray();

        public IntPtr _data; //(this is the pointer to the generic type)
        //offset 8
        Int32 _count;      // count
        //offset 12
        Int32 _padding1;
        //offset 16
        Int32 _maxItems;
        //offset 20
        Int32 _padding2;
        public AutoArray()
        {
            this = CreateAutoArray();
        }

        public void ShrinkToFit()
        {

        }

        public void Resize()
        {

        }

        public unsafe void Reserve(int size)
        {

        }

        public void Emplace()
        {

        }

        public void EmplaceBack()
        {

        }

        public unsafe void PushBack(GameValue instance)
        {
            Console.WriteLine("data points to: {0:X8}\n", instance.Data.Get().ToInt64());
            Console.WriteLine("count: {0} maxItems: {1}\n", _count, _maxItems);
            if (_maxItems < _count || _data == IntPtr.Zero)
            {
                Grow(1);
            }

            if (_data == IntPtr.Zero)
            {
                //temp, will be removed later!
                throw new NullReferenceException();
            }
            GameValue* pointer = (GameValue*)_data.ToPointer();
            var pointerstart = &pointer[_count];
            Buffer.MemoryCopy(&instance, pointerstart, 1 * Marshal.SizeOf(typeof(GameValue)), 1 * Marshal.SizeOf(typeof(GameValue)));
            GC.Collect();
            _count++;

            Span<byte> gameValues;
            gameValues = new Span<byte>((void*)pointer, Marshal.SizeOf(typeof(GameValue)) * _count);

            Console.WriteLine("data: {0}", Convert.ToHexString(gameValues));

        }

        public void Add(GameValue instance)
        {
            PushBack(instance);
        }

        public void Grow(int size)
        {
            Console.WriteLine("Grow called!\n");
            int newSize = _maxItems + Math.Max(size, Math.Min(_maxItems, 128));
            if (_maxItems == newSize) { return; }
            IntPtr newData = IntPtr.Zero;

            if (newSize > 0 || _data == IntPtr.Zero)
            {
                Console.WriteLine("Allocation called!\n");
                newData = RealVirtualAllocator.Allocate(newSize * Marshal.SizeOf(typeof(GameValue)));
                if (newData == IntPtr.Zero)
                {
                    Console.WriteLine("Allocation returned null!\n");
                    throw new NullReferenceException();
                }
                Buffer.MemoryCopy(_data.ToPointer(), newData.ToPointer(), newSize * Marshal.SizeOf(typeof(GameValue)), _count * Marshal.SizeOf(typeof(GameValue)));

                // free the memory if it is not null
                if (_data != IntPtr.Zero)
                {
                    RealVirtualAllocator.Deallocate(_data);
                }

                _data = newData;
                _maxItems = newSize;

                // check code!
                if (_data == IntPtr.Zero)
                {
                    Console.WriteLine("_data points to zero.\n");
                }
            }
        }

        public void Erase()
        {

        }
        public void Erase(int start, int count)
        {

        }

        public void Insert(int index)
        {

        }

        public void Insert(int start, int count)
        {

        }

        public void Clear()
        {

        }

        public GameValue Get(int index)
        {
            return new GameValue();
        }

        public int Count()
        {
            return _count;
        }

        public GameValue Front()
        {
            return new GameValue();
        }

        public GameValue Back()
        {
            return new GameValue();
        }

        public Boolean IsEmpty()
        {
            return _count == 0;
        }

        public unsafe GameValue this[int i]
        {
            get
            {
                if (i >= _count)
                {
                    throw new IndexOutOfRangeException($"The Collection size is {_count} elements.");
                }
                GameValue* pointer = (GameValue*)_data.ToPointer();
                return pointer[i];
            }
            set
            {
                GameValue* pointer = (GameValue*)_data.ToPointer();
                pointer[i] = value;
            }
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public class Ref
    {
        private IntPtr data;

        public IntPtr Get()
        {
            return data;
        }

        public unsafe ref T GetAs<T>()
        {
            return ref Unsafe.AsRef<T>(data.ToPointer());
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameData
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataArray
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        AutoArray data;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataBool
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        Byte val;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataCode
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        Ref codeString;
        AutoArray instructions;    // don't use this.
        Byte isFinal;

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataConfig
    {

        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr config;
        AutoArray path; // don't use
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataControl
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr control;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataDisplay
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr display;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataGroup
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr group;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataHashmap
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr _table;
        Int32 _tableCount;
        Int32 _count;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataLocation
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr location;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNamespace
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr dummyVtable;

        // _variables
        IntPtr _table;
        Int32 _tableCount;
        Int32 _count;

        IntPtr _name;
        Byte _1; //? okay
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNothing
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        // nothing here...
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNumber
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        public float number;

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataObject
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr _object;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataRVText
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding
        IntPtr rv_text;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataScript
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding
        IntPtr script;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataSide
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding
        IntPtr side;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataString
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding
        IntPtr rawString;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataTeamMember
    {
        IntPtr _vtptr;
        // offset 8
        int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        IntPtr _vtptr_debug;
        //ends at 24 for padding

        IntPtr teamMember;
    }


    /// <summary>
    /// Class <c>GameValue</c> handles rv engine types and functions used by the engine.
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct GameValue
    {
        //VTablePtr
        public IntPtr _vtptr;

        //Data pointer
        public Ref Data;

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@XZ", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@M@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue(float value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@_N@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue(bool value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@PEBD@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue(string value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@V?$auto_array@Vgame_value@types@intercept@@V?$rv_allocator@Vgame_value@types@intercept@@@23@$0IA@@23@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue(AutoArray array);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@V?$vector2_base@M@23@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue(Vector2 vector);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@V?$vector3_base@M@23@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue(Vector3 vector);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@PEAVgame_data@23@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern unsafe GameValue CreateGameValue(GameData* data);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@PEAV123@H@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern unsafe GameValue CreateGameValue(GameValue* array, int length);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?TestGameDataPointer@@YAXVgame_value@types@intercept@@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern void TestGameDataPointer(GameValue instance);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?TestGameAutoArray@@YAXV?$auto_array@Vgame_value@types@intercept@@V?$rv_allocator@Vgame_value@types@intercept@@@23@$0IA@@types@intercept@@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern void TestGameAutoArray(AutoArray array);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?NearestTerrainObjects@@YA?AVgame_value@types@intercept@@V123@@Z", CallingConvention = CallingConvention.Cdecl)]
        private static extern GameValue NearestTerrainObjects(GameValue array);



        public GameValue()
        {
            this = CreateGameValue();
        }

        public GameValue(float value)
        {
            this = CreateGameValue(value);
        }

        public GameValue(bool value)
        {
            this = CreateGameValue(value);
        }

        public GameValue(string value)
        {
            this = CreateGameValue(value);
        }

        public GameValue(AutoArray array)
        {
            this = CreateGameValue(array);
        }

        public unsafe GameValue(GameData* data)
        {
            this = CreateGameValue(data);
        }

        public GameValue(Vector2 value)
        {
            this = CreateGameValue(value);
        }

        public GameValue(Vector3 value)
        {
            this = CreateGameValue(value);
        }

        public unsafe GameValue(GameValue* array, int size)
        {
            this = CreateGameValue(array, size);
        }

        public static void TestGamePointer(GameValue instance)
        {
            TestGameDataPointer(instance);
        }

        public static void TestAutoArray(AutoArray array)
        {
            TestGameAutoArray(array);
        }
    }
}
