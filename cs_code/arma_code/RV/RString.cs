using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;

namespace RV
{
    [StructLayout(LayoutKind.Sequential)]
    public struct RString
    {
        public Int32 _refCount;
        private Int32 _padding;
        public UInt64 _size;
        public byte _string;
    }
}