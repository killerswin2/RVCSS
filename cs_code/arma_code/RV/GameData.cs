using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;

namespace RV
{
    public static class TestGameDataReferences
    {
        public static void TestReferences()
        {
            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameData>())
            {
                Console.WriteLine("GameData is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataArray>())
            {
                Console.WriteLine("GameDataArray is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataBool>())
            {
                Console.WriteLine("GameDataBool is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataCode>())
            {
                Console.WriteLine("GameDataCode is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataConfig>())
            {
                Console.WriteLine("GameDataConfig is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataControl>())
            {
                Console.WriteLine("GameDataControl is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataDisplay>())
            {
                Console.WriteLine("GameDataDisplay is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataGroup>())
            {
                Console.WriteLine("GameDataGroup is a reference type");
            }
            
            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataHashmap>())
            {
                Console.WriteLine("GameDataHashmap is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataLocation>())
            {
                Console.WriteLine("GameDataLocation is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataNamespace>())
            {
                Console.WriteLine("GameDataNamespace is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataNothing>())
            {
                Console.WriteLine("GameDataNothing is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataNumber>())
            {
                Console.WriteLine("GameDataNumber is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataObject>())
            {
                Console.WriteLine("GameDataObject is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataRVText>())
            {
                Console.WriteLine("GameDataRVText is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataScript>())
            {
                Console.WriteLine("GameDataScript is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataSide>())
            {
                Console.WriteLine("GameDataSide is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataString>())
            {
                Console.WriteLine("GameDataString is a reference type");
            }

            if(RuntimeHelpers.IsReferenceOrContainsReferences<GameDataTeamMember>())
            {
                Console.WriteLine("GameDataTeamMember is a reference type");
            }
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameData 
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataArray
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public AutoArray data;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataBool
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public Byte val;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataCode 
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        //this is the ref pointer.
        public IntPtr codeString; 
        public AutoArray instructions; // don't use this. Unless you want to cry alot
        public Byte isFinal;   // this doesn't exist anymore, use the virtual function on the type

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataConfig
    {

        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr config;
        public AutoArray path; // don't use
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataControl
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr control;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataDisplay
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr display;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataGroup
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr group;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataHashmap
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr _table;
        public Int32 _tableCount;
        public Int32 _count;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataLocation
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr location;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNamespace
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr dummyVtable;

        // _variables
        public IntPtr _table;
        public Int32 _tableCount;
        public Int32 _count;

        public IntPtr _name;
        public Byte _1; //? okay
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNothing
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        // nothing here...
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNumber
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public float number; 

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataObject
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr _object;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataRVText
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding
        public IntPtr rv_text;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataScript
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding
        public IntPtr script;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataSide
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding
        public IntPtr side;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataString
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding
        public IntPtr rawString;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataTeamMember
    {
        public IntPtr _vtptr;
        // offset 8
        public int _refCount;
        //offset 12
        private Int32 _dummy;       // WHY ?
        //offset 16
        public IntPtr _vtptr_debug;
        //ends at 24 for padding

        public IntPtr teamMember;
    }

    public static class VTablePtrs
    {
        public static bool initialized = false;
        public static IntPtr GameValue;
        public static IntPtr GameDataArray;
        public static IntPtr GameDataBool;
        public static IntPtr GameDataCode;
        public static IntPtr GameDataConfig;
        public static IntPtr GameDataControl;
        public static IntPtr GameDataDisplay;
        public static IntPtr GameDataGroup;
        public static IntPtr GameDataHashmap;
        public static IntPtr GameDataLocation;
        public static IntPtr GameDataNamespace;
        public static IntPtr GameDataNothing;
        public static IntPtr GameDataNumber;
        public static IntPtr GameDataObject;
        public static IntPtr GameDataRVText;
        public static IntPtr GameDataScript;
        public static IntPtr GameDataSide;
        public static IntPtr GameDataString;
        public static IntPtr GameDataTeamMember;

        public delegate void AssignPointersDelegate(IntPtr buffer, int length);
        public static void AssignPointers(IntPtr buffer, int length)
        {
            unsafe {
                IntPtr* array = (IntPtr*)buffer.ToPointer();
                GameDataArray = array[0];
                GameDataBool = array[1];
                GameDataCode = array[2];
                GameDataConfig = array[3];
                GameDataControl = array[4];
                GameDataDisplay = array[5];
                GameDataGroup = array[6];
                GameDataHashmap = array[7];
                GameDataLocation = array[8];
                GameDataNamespace = array[9];
                GameDataNothing = array[10];
                GameDataNumber = array[11];
                GameDataObject = array[12];
                GameDataRVText = array[13];
                GameDataScript = array[14];
                GameDataSide = array[15];
                GameDataString = array[16];
                GameDataTeamMember = array[17];
                GameValue = array[18];
            }
            initialized = true;
            #if DEBUG
            Console.WriteLine("Pointer Locations: ");
            Console.WriteLine("GameDataArray: {0:X}", GameDataArray);
            Console.WriteLine("GameDataBool: {0:X}", GameDataBool);
            Console.WriteLine("GameDataCode: {0:X}", GameDataCode);
            Console.WriteLine("GameDataConfig: {0:X}", GameDataConfig);
            Console.WriteLine("GameDataControl: {0:X}", GameDataControl);
            Console.WriteLine("GameDataDisplay: {0:X}", GameDataDisplay);
            Console.WriteLine("GameDataGroup: {0:X}", GameDataGroup);
            Console.WriteLine("GameDataHashmap: {0:X}", GameDataHashmap);
            Console.WriteLine("GameDataLocation: {0:X}", GameDataLocation);
            Console.WriteLine("GameDataNamespace: {0:X}", GameDataNamespace);
            Console.WriteLine("GameDataNothing: {0:X}", GameDataNothing);
            Console.WriteLine("GameDataNumber: {0:X}", GameDataNumber);
            Console.WriteLine("GameDataObject: {0:X}", GameDataObject);
            Console.WriteLine("GameDataRVText: {0:X}", GameDataRVText);
            Console.WriteLine("GameDataScript: {0:X}", GameDataScript);
            Console.WriteLine("GameDataSide: {0:X}", GameDataSide);
            Console.WriteLine("GameDataString: {0:X}", GameDataString);
            Console.WriteLine("GameDataTeamMember: {0:X}", GameDataTeamMember);
            Console.WriteLine("GameValue: {0:X}", GameValue);
#endif
        }
    }
}