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
    public partial class Allocator
    {
        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Allocate@@YAPEAX_K@Z")]
        [UnmanagedCallConv(CallConvs = new[] {typeof(CallConvCdecl)})]
        public static partial IntPtr Allocate(int size);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Deallocate@@YAXPEAX@Z")]
        [UnmanagedCallConv(CallConvs = new[] {typeof(CallConvCdecl)})]
        public static partial IntPtr Deallocate(IntPtr pointer);

    }
}