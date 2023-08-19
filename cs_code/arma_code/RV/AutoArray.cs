using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Security;

namespace RV
{

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct AutoArray
    {


        public IntPtr _data; //(this is the pointer to the generic type)
        //offset 8
        public Int32 _count;      // count
        //offset 12
        public Int32 _padding1;
        //offset 16
        public Int32 _maxItems;
        //offset 20
        public Int32 _padding2;
    }
    public partial class AutoArrayMethods
    {
        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateAutoArray@@YA?AV?$auto_array@Vgame_value@types@intercept@@V?$rv_allocator@Vgame_value@types@intercept@@@23@$0IA@@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] {typeof(CallConvCdecl)})]
        public static partial AutoArray CreateAutoArray();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteAutoArray@@YAXV?$auto_array@Vgame_value@types@intercept@@V?$rv_allocator@Vgame_value@types@intercept@@@23@$0IA@@types@intercept@@@Z")]
        [UnmanagedCallConv(CallConvs = new[] {typeof(CallConvCdecl)})]
        public static partial AutoArray DeleteAutoArray(AutoArray instance);
    }
}