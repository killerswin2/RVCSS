using System.Runtime.InteropServices;
namespace RV
{

    [StructLayout(LayoutKind.Sequential)]
    public class RefBase
    {
        public IntPtr data;

    }
}