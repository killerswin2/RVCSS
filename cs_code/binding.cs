using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Numerics;

namespace RV
{
    public struct Ref
    {
        IntPtr _data;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameData
    {
        IntPtr _vtptr;
        // 8 bytes
        public Ref;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataArray : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataBool: GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataCode : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataConfig : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataControl : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataDisplay : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataGroup : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataHashmap : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataLocation : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNamespace : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNothing : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataNumber : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataObject : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataRVText : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataScript : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataSide : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataString : GameData
    {

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct GameDataTeamMember : GameData
    {

    }


    /// <summary>
    /// Class <c>GameValue</c> handles rv engine types and functions used by the engine.
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
	public struct GameValue
    {
        public IntPtr _vtptr;
        public GameData Data;

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@XZ", CallingConvention = __CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValue();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValueFloat@@YA?AVgame_value@types@intercept@@M@Z", CallingConvention = __CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValueFloat(float value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValueFloat@@YA?AVgame_value@types@intercept@@M@Z", CallingConvention = __CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValueInt(int value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64", EntryPoint = "?CreateGameValueBool@@YA?AVgame_value@types@intercept@@_N@Z", CallingConvention = __CallingConvention.Cdecl)]
        private static extern GameValue CreateGameValueBool(bool value);

        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern GameValue CreateGameValueString(string value);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern GameValue CreateGameValueArray(IntPtr pointer, int length);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern GameValue CreateGameValueArrayEmpty();
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern GameValue CreateGameValueVector2(Vector2 vector);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern GameValue CreateGameValueVector3(Vector3 vector);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern void FreeRVAllocation(IntPtr allocationPointer, int type);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern IntPtr GetDataString(GameValue gameValuePointer);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern int GetDataInt(GameValue gameValuePointer);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern float GetDataFloat(IntPtr gameValuePointer);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern bool GetDataBool(GameValue gameValuePointer);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern IntPtr GetDataVector2(GameValue gameValuePointer);
        //
        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern IntPtr GetDataVector3(GameValue gameValuePointer);

        public GameValue()
        {
            this = CreateGameValue();
        }

        public GameValue(float value)
        {
            this = CreateGameValueFloat(value);
        }

        public GameValue(int value)
        {
            this = CreateGameValueInt(value);
        }

        public GameValue(bool value)
        {
            this = CreateGameValueBool(value);
        }

        //public GameValue(string value)
        //{
        //    this = CreateGameValueString(value);
        //}
        //
        //public GameValue(GameValue array, int length)
        //{
        //    this = CreateGameValueArray(array._internalGameValue, length);
        //}
        //
        //public GameValue(List<int> list)
        //{
        //    _internalGameValue = CreateGameValueArrayEmpty();
        //    for (int i = 0; i < list.Count; i++)
        //    {
        //        var temp = new GameValue(list[i]);
        //        pushback(_internalGameValue, temp._internalGameValue);
        //    }
        //}
        //
        //public GameValue(IntPtr array, int length)
        //{
        //    _internalGameValue = CreateGameValueArray(array, length);
        //}
        //
        //public GameValue(Vector2 value)
        //{
        //    _internalGameValue = CreateGameValueVector2(value);
        //}
        //
        //public GameValue(Vector3 value)
        //{
        //    _internalGameValue = CreateGameValueVector3(value);
        //}
        //
        //public GameValue(IntPtr gamePointer)
        //{
        //    _internalGameValue = gamePointer;
        //}
        //
        //~GameValue()
        //{
        //    DeleteGameValue(_internalGameValue);
        //}
        //
        ///// <summary>
        ///// Method <c>GetString</c> returns a c# String type from an GameValue instance from the RV engine
        ///// </summary>
        //public static String GetString(GameValue instance)
        //{
        //    var pointer = GetDataString(instance._internalGameValue);
        //    String? message = String.Empty;
        //    if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
        //    {
        //        message = Marshal.PtrToStringUni(pointer);
        //        // free memory
        //        FreeRVAllocation(pointer, 0);
        //    }
        //    else
        //    {
        //        message = Marshal.PtrToStringUTF8(pointer);
        //        // again free memory
        //        FreeRVAllocation(pointer, 0);
        //    }
        //
        //    if (message != null)
        //    {
        //        return message;
        //    }
        //    else
        //    {
        //        return String.Empty;
        //    }
        //
        //}
        //
        ///// <summary>
        ///// Method <c>GetFloat</c> returns a c# Float type from an GameValue instance from the RV engine
        ///// </summary>
        //public static float GetFloat(GameValue instance)
        //{
        //    return GetDataFloat(instance._internalGameValue);
        //}
        //
        ///// <summary>
        ///// Method <c>GetInt</c> returns a c# Int type from an GameValue instance from the RV engine
        ///// </summary>
        //public static int GetInt(GameValue instance)
        //{
        //    return GetDataInt(instance._internalGameValue);
        //}
        //
        ///// <summary>
        ///// Method <c>GetBool</c> returns a c# Bool type from an GameValue instance from the RV engine
        ///// </summary>
        //public static bool GetBool(GameValue instance)
        //{
        //    return GetDataBool(instance._internalGameValue);
        //}
        //
        ///// <summary>
        ///// Method <c>GetVector2</c> returns a c# Vector2 type from an GameValue instance from the RV engine
        ///// </summary>
        //public static Vector2 GetVector2(GameValue instance)
        //{
        //    var pointer = GetDataVector2(instance._internalGameValue);
        //    try
        //    {
        //        var vec2 = Marshal.PtrToStructure<Vector2>(pointer);
        //        // free the memory in the pointer
        //        FreeRVAllocation(pointer, 1);
        //        return vec2;
        //    }
        //    catch (NullReferenceException exception)
        //    {
        //        String message = String.Format("Null Execetion: {0}", exception);
        //        // log the exception in the rpt.
        //        diag_log(new GameValue(message)._internalGameValue);
        //        return new Vector2(0, 0);
        //    }
        //}
        //
        ///// <summary>
        ///// Method <c>GetVector3</c> returns a c# Vector3 type from an GameValue instance from the RV engine
        ///// </summary>
        //public static Vector3 GetVector3(GameValue instance)
        //{
        //    var pointer = GetDataVector3(instance._internalGameValue);
        //    try
        //    {
        //        var vec3 = Marshal.PtrToStructure<Vector3>(pointer);
        //        // free the memory in the pointer
        //        FreeRVAllocation(pointer, 2);
        //        return vec3;
        //    }
        //    catch (NullReferenceException exception)
        //    {
        //        String message = String.Format("Null Execetion: {0}", exception);
        //        // log the exception in the rpt.
        //        diag_log(new GameValue(message)._internalGameValue);
        //        return new Vector3(0, 0, 0);
        //    }
        //}
    }
}
