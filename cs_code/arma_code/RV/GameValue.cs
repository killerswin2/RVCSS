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
    /// <summary>
    /// Class <c>GameValue</c> handles rv engine types and functions used by the engine.
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct GameValue
    {
        //VTablePtr
        public IntPtr _vtptr;

        //Data pointer
        public IntPtr data;

    }

    /// <summary>
    /// Class <c>GameValueMethods</c> handles rv engine functions used by the engine.
    /// </summary>
    unsafe public partial class GameValueMethods
    {
        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGameValue();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@M@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGameValue(float value);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@_N@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGameValue([MarshalAs(UnmanagedType.Bool)] bool value);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@PEBD@Z", StringMarshalling = StringMarshalling.Utf8)]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGameValue(string value);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@V?$auto_array@Vgame_value@types@intercept@@V?$rv_allocator@Vgame_value@types@intercept@@@23@$0IA@@23@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGameValue(AutoArray array);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGameValue@@YA?AVgame_value@types@intercept@@PEAVgame_data@23@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGameValue(IntPtr data);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteGameData@@YAXPEAVgame_data@types@intercept@@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial void DeleteGameValue(IntPtr instance);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TestGameData@@YAXPEAVgame_data@types@intercept@@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial void TestGameData(IntPtr instance);

        //[SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearRoads@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        //[UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        //public static partial GameValue NearRoads(GameValue obj, GameValue radius);

        //[SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Player@@YA?AVgame_value@types@intercept@@XZ")]
        //[UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        //public static partial GameValue Player();

        //[SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Str@@YA?AVgame_value@types@intercept@@V123@@Z")]
        //[UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        //public static partial GameValue Str(GameValue data);

        //[SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestTerrainObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        //[UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        //public static partial GameValue NearestTerrainObjects(GameValue data);

        #region commands
        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Abs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Abs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AccTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AccTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Acos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Acos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Action@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Action(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionIDs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionIDs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionKeys@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionKeys(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionKeysEx@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionKeysEx(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionKeysImages@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionKeysImages(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionKeysNames@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionKeysNames(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionKeysNamesArray@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionKeysNamesArray(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActionParams@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActionParams(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActivateAddons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActivateAddons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActivatedAddons@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActivatedAddons();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActivateKey@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActivateKey(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ActiveTitleEffectParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ActiveTitleEffectParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Add3DENConnection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Add3DENConnection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Add3DENEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Add3DENEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Add3DENLayer@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Add3DENLayer(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddBackpack@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddBackpack(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddBackpackCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddBackpackCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddBackpackCargoGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddBackpackCargoGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddBackpackGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddBackpackGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddBinocularItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddBinocularItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddCamShake@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddCamShake(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddCuratorAddons@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddCuratorAddons(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddCuratorCameraArea@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddCuratorCameraArea(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddCuratorEditableObjects@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddCuratorEditableObjects(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddCuratorEditingArea@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddCuratorEditingArea(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddCuratorPoints@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddCuratorPoints(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddEditorObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddEditorObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddForce@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddForce(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddForceGeneratorRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddForceGeneratorRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddGoggles@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddGoggles(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddGroupIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddGroupIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddHandgunItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddHandgunItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddHeadgear@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddHeadgear(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItemCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItemCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItemCargoGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItemCargoGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItemPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItemPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItemToBackpack@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItemToBackpack(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItemToUniform@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItemToUniform(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddItemToVest@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddItemToVest(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddLiveStats@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddLiveStats(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazineAmmoCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazineAmmoCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazineCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazineCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazineCargoGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazineCargoGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazineGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazineGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazinePool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazinePool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazines@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazines(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMagazineTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMagazineTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMenu@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMenu(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMenuItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMenuItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMissionEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMissionEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMPEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMPEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddMusicEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddMusicEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddonFiles@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddonFiles(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddOwnedMine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddOwnedMine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddPlayerScores@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddPlayerScores(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddPrimaryWeaponItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddPrimaryWeaponItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddPublicVariableEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddPublicVariableEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddRating@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddRating(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddResources@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddResources(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddScore@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddScore(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddScoreSide@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddScoreSide(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddSecondaryWeaponItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddSecondaryWeaponItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddSwitchableUnit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddSwitchableUnit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddTeamMember@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddTeamMember(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddToRemainsCollector@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddToRemainsCollector(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddTorque@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddTorque(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddUniform@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddUniform(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddUserActionEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddUserActionEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddVehicle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddVehicle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddVest@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddVest(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWaypoint@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWaypoint(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeapon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeapon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponCargoGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponCargoGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponWithAttachmentsCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponWithAttachmentsCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AddWeaponWithAttachmentsCargoGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AddWeaponWithAttachmentsCargoGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Admin@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Admin(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Agent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Agent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Agents@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Agents();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AGLToASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AGLToASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AimedAtTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AimedAtTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AimPos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AimPos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AirDensityCurveRTD@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AirDensityCurveRTD();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AirDensityRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AirDensityRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AirplaneThrottle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AirplaneThrottle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AirportSide@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AirportSide(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AISFinishHeal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AISFinishHeal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Alive@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Alive(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?All3DENEntities@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue All3DENEntities();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllActiveTitleEffects@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllActiveTitleEffects();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllAddonsInfo@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllAddonsInfo();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllAirports@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllAirports();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllControls@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllControls(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllCurators@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllCurators();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllCutLayers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllCutLayers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllDead@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllDead();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllDeadMen@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllDeadMen();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllDiaryRecords@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllDiaryRecords(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllDiarySubjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllDiarySubjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllDisplays@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllDisplays();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllEnv3DSoundSources@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllEnv3DSoundSources();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllGroups@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllGroups();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllLODs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllLODs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllMapMarkers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllMapMarkers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllMines@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllMines();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllMissionObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllMissionObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllObjects@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllObjects(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Allow3DMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Allow3DMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowCrewInImmobile@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowCrewInImmobile(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowCuratorLogicIgnoreAreas@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowCuratorLogicIgnoreAreas(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowDamage@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowDamage(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowDammage@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowDammage(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowedService@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowedService(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowFileOperations@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowFileOperations(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowFleeing@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowFleeing(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowGetIn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowGetIn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowService@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowService(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllowSprint@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllowSprint(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllPlayers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllPlayers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllSimpleObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllSimpleObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllSites@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllSites();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllTurrets@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllTurrets(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllUnits@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllUnits();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllUnitsUAV@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllUnitsUAV();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllUsers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllUsers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AllVariables@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AllVariables(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AmbientTemperature@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AmbientTemperature();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Ammo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Ammo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AmmoOnPylon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AmmoOnPylon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?And@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue And(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Animate@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Animate(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimateBay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimateBay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimateDoor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimateDoor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimatePylon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimatePylon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimateSource@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimateSource(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimationNames@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimationNames(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimationPhase@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimationPhase(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimationSourcePhase@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimationSourcePhase(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AnimationState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AnimationState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ApertureParams@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ApertureParams();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Append@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Append(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Apply@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Apply(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ArmoryPoints@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ArmoryPoints();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ArrayIntersect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ArrayIntersect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Asin@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Asin(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ASLToAGL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ASLToAGL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ASLToATL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ASLToATL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Assert@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Assert(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignAsCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignAsCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignAsCargoIndex@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignAsCargoIndex(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignAsCommander@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignAsCommander(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignAsDriver@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignAsDriver(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignAsGunner@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignAsGunner(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignAsTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignAsTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignCurator@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignCurator(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedCommander@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedCommander(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedDriver@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedDriver(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedGroup@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedGroup(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedGunner@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedGunner(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedTarget@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedTarget(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedTeam@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedTeam(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedVehicle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedVehicle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedVehicleRole@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedVehicleRole(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignedVehicles@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignedVehicles(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignTeam@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignTeam(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AssignToAirport@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AssignToAirport(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Atan@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Atan(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Atan2@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Atan2(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Atg@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Atg(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ATLToASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ATLToASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AttachedObject@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AttachedObject(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AttachedObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AttachedObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AttachedTo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AttachedTo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AttachObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AttachObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AttachTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AttachTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?AttackEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue AttackEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Awake@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Awake(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Backpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Backpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BackpackCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BackpackCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BackpackContainer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BackpackContainer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BackpackItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BackpackItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BackpackMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BackpackMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Backpacks@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Backpacks(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BackpackSpaceFor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BackpackSpaceFor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Behaviour@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Behaviour(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Benchmark@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Benchmark();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BezierInterpolation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BezierInterpolation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Binocular@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Binocular(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BinocularItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BinocularItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BinocularMagazine@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BinocularMagazine(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Blufor@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Blufor();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BoundingBox@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BoundingBox(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BoundingBoxReal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BoundingBoxReal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BoundingCenter@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BoundingCenter(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BrakesDisabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BrakesDisabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Break@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Break();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BreakOut@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BreakOut(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BreakTo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BreakTo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BreakWith@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BreakWith(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BriefingName@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BriefingName();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BuildingExit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BuildingExit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?BuildingPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue BuildingPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Buldozer_enableroaddiag@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Buldozer_enableroaddiag(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Buldozer_isenabledroaddiag@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Buldozer_isenabledroaddiag();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Buldozer_loadnewroads@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Buldozer_loadnewroads(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Buldozer_reloadopermap@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Buldozer_reloadopermap();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ButtonAction@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ButtonAction(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ButtonSetAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ButtonSetAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CadetMode@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CadetMode();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CalculatePath@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CalculatePath(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CalculatePlayerVisibilityByFriendly@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CalculatePlayerVisibilityByFriendly(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Call@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Call(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CallExtension@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CallExtension(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamCommand@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamCommand(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamCommit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamCommit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamCommitPrepared@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamCommitPrepared(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamCommitted@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamCommitted(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamConstuctionSetParams@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamConstuctionSetParams(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamCreate@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamCreate(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamDestroy@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamDestroy(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CameraEffect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CameraEffect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CameraEffectEnableHUD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CameraEffectEnableHUD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CameraInterest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CameraInterest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CameraOn@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CameraOn();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CameraView@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CameraView();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CampaignConfigFile@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CampaignConfigFile();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPreload@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPreload(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPreloaded@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPreloaded(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareBank@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareBank(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareDive@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareDive(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareFocus@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareFocus(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareFov@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareFov(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareFovRange@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareFovRange(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPreparePos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPreparePos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareRelPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareRelPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamPrepareTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamPrepareTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetBank@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetBank(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetDive@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetDive(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetFocus@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetFocus(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetFov@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetFov(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetFovRange@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetFovRange(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetRelPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetRelPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamSetTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamSetTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamTarget@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamTarget(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CamUseNVG@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CamUseNVG(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanAddItemToBackpack@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanAddItemToBackpack(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanAddItemToUniform@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanAddItemToUniform(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanAddItemToVest@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanAddItemToVest(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CancelSimpleTaskDestination@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CancelSimpleTaskDestination(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanDeployWeapon@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanDeployWeapon(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanFire@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanFire(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanMove@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanMove(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanSlingLoad@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanSlingLoad(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanStand@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanStand(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanSuspend@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanSuspend();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanTriggerDynamicSimulation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanTriggerDynamicSimulation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanUnloadInCombat@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanUnloadInCombat(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CanVehicleCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CanVehicleCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Captive@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Captive(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CaptiveNum@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CaptiveNum(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Case@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Case(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Catch@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Catch(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CbChecked@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CbChecked(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CbSetChecked@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CbSetChecked(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Ceil@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Ceil(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ChannelEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ChannelEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CheatsEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CheatsEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CheckAIFeature@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CheckAIFeature(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CheckVisibility@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CheckVisibility(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Civilian@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Civilian();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClassName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClassName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Clear3DENAttribute@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Clear3DENAttribute(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Clear3DENInventory@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Clear3DENInventory(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearAllItemsFromBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearAllItemsFromBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearBackpackCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearBackpackCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearBackpackCargoGlobal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearBackpackCargoGlobal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearForcesRTD@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearForcesRTD();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearGroupIcons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearGroupIcons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearItemCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearItemCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearItemCargoGlobal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearItemCargoGlobal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearItemPool@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearItemPool();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearMagazineCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearMagazineCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearMagazineCargoGlobal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearMagazineCargoGlobal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearMagazinePool@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearMagazinePool();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearOverlay@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearOverlay(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearRadio@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearRadio();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearWeaponCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearWeaponCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearWeaponCargoGlobal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearWeaponCargoGlobal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClearWeaponPool@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClearWeaponPool();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ClientOwner@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ClientOwner();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CloseDialog@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CloseDialog(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CloseDisplay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CloseDisplay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CloseOverlay@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CloseOverlay(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CollapseObjectTree@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CollapseObjectTree(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Collect3DENHistory@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Collect3DENHistory(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CollectiveRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CollectiveRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CollisionDisabledWith@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CollisionDisabledWith(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CombatBehaviour@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CombatBehaviour(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CombatMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CombatMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandArtilleryFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandArtilleryFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandChat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandChat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Commander@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Commander(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandFollow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandFollow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandFSM@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandFSM(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandGetOut@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandGetOut(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandingMenu@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandingMenu();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandMove@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandMove(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandStop@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandStop(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandSuppressiveFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandSuppressiveFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommandWatch@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommandWatch(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Comment@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Comment(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CommitOverlay@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CommitOverlay(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CompatibleItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CompatibleItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CompatibleMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CompatibleMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Compile@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Compile(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CompileFinal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CompileFinal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CompileScript@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CompileScript(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CompletedFSM@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CompletedFSM(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ComposeText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ComposeText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Configaccessor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Configaccessor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigClasses@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigClasses(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigFile@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigFile();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigHierarchy@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigHierarchy(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigOf@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigOf(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigProperties@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigProperties(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigSourceAddonList@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigSourceAddonList(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigSourceMod@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigSourceMod(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfigSourceModList@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfigSourceModList(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConfirmSensorTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConfirmSensorTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConnectTerminalToUAV@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConnectTerminalToUAV(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConnectToServer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConnectToServer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Continue@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Continue();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ContinueWith@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ContinueWith(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ControlNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ControlNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ControlsGroupCtrl@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ControlsGroupCtrl(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ConversationDisabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ConversationDisabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CopyFromClipboard@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CopyFromClipboard();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CopyToClipboard@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CopyToClipboard(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CopyWaypoints@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CopyWaypoints(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Cos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Cos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Count@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Count(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CountEnemy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CountEnemy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CountFriendly@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CountFriendly(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CountSide@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CountSide(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CountType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CountType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CountUnknown@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CountUnknown(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Create3DENComposition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Create3DENComposition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Create3DENEntity@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Create3DENEntity(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateAgent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateAgent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateCenter@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateCenter(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateDialog@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateDialog(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateDiaryLink@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateDiaryLink(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateDiaryRecord@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateDiaryRecord(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateDiarySubject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateDiarySubject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateDisplay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateDisplay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGearDialog@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGearDialog(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGroup@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGroup(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateGuardedPoint@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateGuardedPoint(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateHashMap@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateHashMap();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateHashMapFromArray@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateHashMapFromArray(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateLocation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateLocation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateMarker@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateMarker(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateMarkerLocal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateMarkerLocal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateMenu@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateMenu(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateMine@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateMine(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateMissionDisplay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateMissionDisplay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateMPCampaignDisplay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateMPCampaignDisplay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateSimpleObject@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateSimpleObject(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateSimpleTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateSimpleTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateSite@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateSite(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateSoundSource@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateSoundSource(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateTeam@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateTeam(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateTrigger@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateTrigger(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateUnit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateUnit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateVehicle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateVehicle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateVehicleCrew@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateVehicleCrew(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CreateVehicleLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CreateVehicleLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Crew@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Crew(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtAddHeader@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtAddHeader(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtAddRow@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtAddRow(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtClear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtClear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtCurSel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtCurSel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtFindHeaderRows@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtFindHeaderRows(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtFindRowHeader@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtFindRowHeader(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtHeaderControls@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtHeaderControls(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtHeaderCount@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtHeaderCount(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtRemoveHeaders@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtRemoveHeaders(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtRemoveRows@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtRemoveRows(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlActivate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlActivate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAddEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAddEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAngle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAngle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAnimateModel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAnimateModel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAnimationPhaseModel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAnimationPhaseModel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAt@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAt(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAutoScrollDelay@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAutoScrollDelay(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAutoScrollRewind@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAutoScrollRewind(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlAutoScrollSpeed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlAutoScrollSpeed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlBackgroundColor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlBackgroundColor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlChecked@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlChecked(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlClassName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlClassName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlCommit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlCommit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlCommitted@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlCommitted(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlCreate@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlCreate(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlDelete@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlDelete(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlEnable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlEnable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlFade@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlFade(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlFontHeight@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlFontHeight(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlForegroundColor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlForegroundColor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlHTMLLoaded@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlHTMLLoaded(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlIDC@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlIDC(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlIDD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlIDD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapAnimAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapAnimAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapAnimClear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapAnimClear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapAnimCommit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapAnimCommit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapAnimDone@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapAnimDone(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapCursor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapCursor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapDir@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapDir(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapMouseOver@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapMouseOver(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapScale@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapScale(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapScreenToWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapScreenToWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapSetPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapSetPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMapWorldToScreen@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMapWorldToScreen(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlModel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlModel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlModelDirAndUp@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlModelDirAndUp(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlModelScale@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlModelScale(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlMousePosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlMousePosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlParent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlParent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlParentControlsGroup@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlParentControlsGroup(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlRemoveAllEventHandlers@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlRemoveAllEventHandlers(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlRemoveEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlRemoveEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlScale@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlScale(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlScrollValues@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlScrollValues(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetActiveColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetActiveColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetAngle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetAngle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetAutoScrollDelay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetAutoScrollDelay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetAutoScrollRewind@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetAutoScrollRewind(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetAutoScrollSpeed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetAutoScrollSpeed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetBackgroundColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetBackgroundColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetChecked@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetChecked(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetDisabledColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetDisabledColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFade@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFade(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFocus@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFocus(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFont@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFont(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH1@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH1(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH1B@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH1B(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH2@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH2(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH2B@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH2B(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH3@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH3(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH3B@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH3B(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH4@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH4(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH4B@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH4B(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH5@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH5(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH5B@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH5B(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH6@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH6(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontH6B@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontH6B(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightH1@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightH1(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightH2@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightH2(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightH3@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightH3(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightH4@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightH4(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightH5@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightH5(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightH6@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightH6(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontHeightSecondary@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontHeightSecondary(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontP@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontP(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontPB@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontPB(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetFontSecondary@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetFontSecondary(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetForegroundColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetForegroundColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetModel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetModel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetModelDirAndUp@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetModelDirAndUp(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetModelScale@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetModelScale(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetMousePosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetMousePosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetPixelPrecision@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetPixelPrecision(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetPositionH@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetPositionH(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetPositionW@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetPositionW(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetPositionX@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetPositionX(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetPositionY@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetPositionY(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetScale@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetScale(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetScrollValues@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetScrollValues(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetShadow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetShadow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetStructuredText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetStructuredText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTextColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTextColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTextColorSecondary@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTextColorSecondary(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTextSecondary@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTextSecondary(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTextSelection@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTextSelection(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTooltip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTooltip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTooltipColorBox@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTooltipColorBox(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTooltipColorShade@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTooltipColorShade(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTooltipColorText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTooltipColorText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetTooltipMaxWidth@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetTooltipMaxWidth(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetURL@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetURL(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlSetURLOverlayMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlSetURLOverlayMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlShadow@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlShadow(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlShow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlShow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlShown@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlShown(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlStyle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlStyle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlTextColor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlTextColor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlTextHeight@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlTextHeight(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlTextSecondary@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlTextSecondary(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlTextSelection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlTextSelection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlTextWidth@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlTextWidth(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlTooltip@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlTooltip(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlURL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlURL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlURLOverlayMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlURLOverlayMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtrlVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtrlVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtRowControls@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtRowControls(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtRowCount@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtRowCount(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtSetCurSel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtSetCurSel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtSetData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtSetData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtSetHeaderTemplate@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtSetHeaderTemplate(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtSetRowTemplate@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtSetRowTemplate(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtSetValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtSetValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CtValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CtValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorAddons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorAddons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorCamera@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorCamera();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorCameraArea@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorCameraArea(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorCameraAreaCeiling@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorCameraAreaCeiling(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorCoef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorCoef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorEditableObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorEditableObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorEditingArea@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorEditingArea(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorEditingAreaType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorEditingAreaType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorMouseOver@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorMouseOver();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorPoints@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorPoints(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorRegisteredObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorRegisteredObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorSelected@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorSelected();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CuratorWaypointCost@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CuratorWaypointCost(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Current3DENOperation@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Current3DENOperation();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentChannel@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentChannel();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentCommand@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentCommand(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentMagazine@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentMagazine(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentMagazineDetail@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentMagazineDetail(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentMagazineDetailTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentMagazineDetailTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentMagazineTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentMagazineTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentMuzzle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentMuzzle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentPilot@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentPilot(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentTask@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentTask(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentTasks@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentTasks(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentThrowable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentThrowable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentVisionMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentVisionMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentWaypoint@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentWaypoint(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentWeapon@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentWeapon(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentWeaponMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentWeaponMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentWeaponTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentWeaponTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CurrentZeroing@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CurrentZeroing(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CursorObject@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CursorObject();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CursorTarget@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CursorTarget();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CustomChat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CustomChat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CustomRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CustomRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CustomWaypointPosition@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CustomWaypointPosition();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CutFadeOut@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CutFadeOut(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CutObj@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CutObj(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CutRsc@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CutRsc(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?CutText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue CutText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Damage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Damage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Date@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Date();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DateToNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DateToNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DayTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DayTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeActivateKey@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeActivateKey(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DebriefingText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DebriefingText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DebugFSM@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DebugFSM(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DebugLog@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DebugLog(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DecayGraphValues@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DecayGraphValues(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Default@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Default(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Deg@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Deg(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Delete3DENEntities@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Delete3DENEntities(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteAt@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteAt(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteCenter@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteCenter(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteCollection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteCollection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteEditorObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteEditorObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteGroup@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteGroup(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteGroupWhenEmpty@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteGroupWhenEmpty(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteIdentity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteIdentity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteLocation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteLocation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteMarker@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteMarker(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteMarkerLocal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteMarkerLocal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteRange@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteRange(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteResources@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteResources(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteSite@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteSite(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteStatus@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteStatus(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteTeam@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteTeam(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteVehicle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteVehicle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteVehicleCrew@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteVehicleCrew(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DeleteWaypoint@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DeleteWaypoint(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Detach@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Detach(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DetectedMines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DetectedMines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_activemissionfsms@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_activemissionfsms();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_activescripts@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_activescripts();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_activesqfscripts@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_activesqfscripts();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_activesqsscripts@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_activesqsscripts();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_allmissioneventhandlers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_allmissioneventhandlers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_captureframe@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_captureframe(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_captureframetofile@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_captureframetofile(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_captureslowframe@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_captureslowframe(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_codeperformance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_codeperformance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_deltatime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_deltatime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_drawmode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_drawmode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_dumpcalltracetolog@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_dumpcalltracetolog();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_dumpscriptassembly@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_dumpscriptassembly(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_dumpterrainsynth@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_dumpterrainsynth();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_dynamicsimulationend@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_dynamicsimulationend(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_enable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_enable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_enabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_enabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_exportconfig@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_exportconfig(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_exportterrainsvg@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_exportterrainsvg(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_fps@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_fps();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_fpsmin@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_fpsmin();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_frameno@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_frameno();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_getterrainsegmentoffset@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_getterrainsegmentoffset(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_lightnewload@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_lightnewload(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_list@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_list(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_localized@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_localized(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_log@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_log(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_logslowframe@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_logslowframe(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_mergeconfigfile@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_mergeconfigfile(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_recordturretlimits@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_recordturretlimits(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_resetfsm@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_resetfsm();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_resetshapes@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_resetshapes();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_scope@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_scope();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_setlightnew@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_setlightnew(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_stacktrace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_stacktrace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_ticktime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_ticktime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Diag_toggle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Diag_toggle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Dialog@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Dialog();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DiaryRecordNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DiaryRecordNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DiarySubjectExists@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DiarySubjectExists(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DidJIP@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DidJIP();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DidJIPOwner@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DidJIPOwner(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Difficulty@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Difficulty();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DifficultyEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DifficultyEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DifficultyEnabledRTD@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DifficultyEnabledRTD();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DifficultyOption@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DifficultyOption(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Direction@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Direction(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DirectionStabilizationEnabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DirectionStabilizationEnabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DirectSay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DirectSay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableAI@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableAI(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableBrakes@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableBrakes(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableCollisionWith@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableCollisionWith(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableConversation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableConversation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableDebriefingStats@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableDebriefingStats();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableMapIndicators@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableMapIndicators(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableNVGEquipment@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableNVGEquipment(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableRemoteSensors@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableRemoteSensors(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableSerialization@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableSerialization();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableTIEquipment@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableTIEquipment(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableUAVConnectability@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableUAVConnectability(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisableUserInput@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisableUserInput(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayAddEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayAddEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayChild@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayChild(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayCtrl@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayCtrl(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayParent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayParent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayRemoveAllEventHandlers@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayRemoveAllEventHandlers(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayRemoveEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayRemoveEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplaySetEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplaySetEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayUniqueName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayUniqueName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DisplayUpdate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DisplayUpdate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DissolveTeam@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DissolveTeam(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Distance@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Distance(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Distance2D@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Distance2D(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DistanceSqr@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DistanceSqr(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DistributionRegion@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DistributionRegion();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Do@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Do(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Do3DENAction@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Do3DENAction(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoArtilleryFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoArtilleryFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoFollow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoFollow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoFSM@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoFSM(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoGetOut@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoGetOut(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoMove@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoMove(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoorPhase@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoorPhase(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoStop@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoStop(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoSuppressiveFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoSuppressiveFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DoWatch@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DoWatch(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawArrow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawArrow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawEllipse@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawEllipse(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawIcon3D@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawIcon3D(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawLaser@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawLaser(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawLine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawLine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawLine3D@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawLine3D(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawLink@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawLink(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawLocation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawLocation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawPolygon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawPolygon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawRectangle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawRectangle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DrawTriangle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DrawTriangle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Driver@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Driver(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Drop@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Drop(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DynamicSimulationDistance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DynamicSimulationDistance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DynamicSimulationDistanceCoef@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DynamicSimulationDistanceCoef(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DynamicSimulationEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DynamicSimulationEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?DynamicSimulationSystemEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue DynamicSimulationSystemEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?East@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue East();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Echo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Echo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Edit3DENMissionAttributes@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Edit3DENMissionAttributes(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EditObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EditObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EditorSetEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EditorSetEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EffectiveCommander@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EffectiveCommander(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ElevatePeriscope@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ElevatePeriscope(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Else@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Else(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EmptyPositions@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EmptyPositions(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAI@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAI(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAIFeature@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAIFeature(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAimPrecision@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAimPrecision(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAttack@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAttack(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAudioFeature@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAudioFeature(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAutoStartUpRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAutoStartUpRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableAutoTrimRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableAutoTrimRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableCamShake@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableCamShake(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableCaustics@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableCaustics(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableChannel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableChannel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableCollisionWith@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableCollisionWith(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableCopilot@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableCopilot(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableDebriefingStats@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableDebriefingStats(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableDiagLegend@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableDiagLegend(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableDirectionStabilization@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableDirectionStabilization(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableDynamicSimulation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableDynamicSimulation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableDynamicSimulationSystem@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableDynamicSimulationSystem(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableEndDialog@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableEndDialog();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableEngineArtillery@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableEngineArtillery(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableEnvironment@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableEnvironment(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableFatigue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableFatigue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableGunLights@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableGunLights(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableInfoPanelComponent@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableInfoPanelComponent(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableIRLasers@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableIRLasers(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableMimics@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableMimics(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnablePersonTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnablePersonTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableRadio@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableRadio(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableReload@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableReload(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableRopeAttach@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableRopeAttach(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableSatNormalOnDetail@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableSatNormalOnDetail(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableSaving@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableSaving(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableSentences@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableSentences(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableSimulation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableSimulation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableSimulationGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableSimulationGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableStamina@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableStamina(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableStressDamage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableStressDamage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableTeamSwitch@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableTeamSwitch(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableTraffic@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableTraffic(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableUAVConnectability@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableUAVConnectability(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableUAVWaypoints@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableUAVWaypoints(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableVehicleCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableVehicleCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableVehicleSensor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableVehicleSensor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnableWeaponDisassembly@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnableWeaponDisassembly(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Endl@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Endl();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EndLoadingScreen@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EndLoadingScreen();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EndMission@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EndMission(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EngineOn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EngineOn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnginesIsOnRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnginesIsOnRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnginesPowerRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnginesPowerRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnginesRpmRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnginesRpmRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnginesTorqueRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnginesTorqueRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Entities@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Entities(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnvironmentEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnvironmentEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EnvironmentVolume@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EnvironmentVolume();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EquipmentDisabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EquipmentDisabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EstimatedEndServerTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EstimatedEndServerTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EstimatedTimeLeft@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EstimatedTimeLeft(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EvalObjectArgument@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EvalObjectArgument(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EveryBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EveryBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EveryContainer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EveryContainer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Exec@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Exec(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ExecEditorScript@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ExecEditorScript(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ExecFSM@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ExecFSM(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ExecVM@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ExecVM(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Exit@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Exit();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ExitWith@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ExitWith(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Exp@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Exp(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ExpectedDestination@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ExpectedDestination(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ExportJIPMessages@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ExportJIPMessages(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EyeDirection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EyeDirection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?EyePos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue EyePos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Face@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Face(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Faction@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Faction(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FadeEnvironment@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FadeEnvironment(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FadeMusic@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FadeMusic(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FadeRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FadeRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FadeSound@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FadeSound(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FadeSpeech@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FadeSpeech(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FailMission@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FailMission(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?False@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue False();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FileExists@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FileExists(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FillWeaponsFromPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FillWeaponsFromPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Find@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Find(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindAny@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindAny(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindCover@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindCover(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindDisplay@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindDisplay(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindEditorObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindEditorObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindEmptyPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindEmptyPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindEmptyPositionReady@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindEmptyPositionReady(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindIf@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindIf(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FindNearestEnemy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FindNearestEnemy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FinishMissionInit@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FinishMissionInit();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Finite@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Finite(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Fire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Fire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FireAtTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FireAtTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FirstBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FirstBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Flag@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Flag(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FlagAnimationPhase@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FlagAnimationPhase(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FlagOwner@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FlagOwner(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FlagSide@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FlagSide(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FlagTexture@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FlagTexture(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Flatten@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Flatten(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Fleeing@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Fleeing(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Floor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Floor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FlyInHeight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FlyInHeight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FlyInHeightASL@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FlyInHeightASL(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FocusedCtrl@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FocusedCtrl(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Fog@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Fog();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FogForecast@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FogForecast();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FogParams@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FogParams();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?For@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue For(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceAddUniform@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceAddUniform(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceAtPositionRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceAtPositionRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceCadetDifficulty@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceCadetDifficulty(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForcedMap@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForcedMap();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceEnd@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceEnd();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceFlagTexture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceFlagTexture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceFollowRoad@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceFollowRoad(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceGeneratorRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceGeneratorRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceMap@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceMap(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceRespawn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceRespawn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceSpeed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceSpeed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceUnicode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceUnicode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceWalk@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceWalk(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceWeaponFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceWeaponFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForceWeatherChange@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForceWeatherChange();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForEach@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForEach(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForEachMember@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForEachMember(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForEachMemberAgent@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForEachMemberAgent(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForEachMemberTeam@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForEachMemberTeam(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ForgetTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ForgetTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Format@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Format(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Formation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Formation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormationDirection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormationDirection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormationLeader@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormationLeader(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormationMembers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormationMembers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormationPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormationPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormationTask@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormationTask(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormatText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormatText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FormLeader@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FormLeader(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FreeExtension@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FreeExtension(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FreeLook@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FreeLook();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?From@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue From(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FromEditor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FromEditor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Fuel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Fuel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?FullCrew@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue FullCrew(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GearIDCAmmoCount@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GearIDCAmmoCount(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GearSlotAmmoCount@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GearSlotAmmoCount(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GearSlotData@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GearSlotData(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GestureState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GestureState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENActionState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENActionState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENAttribute@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENAttribute(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENCamera@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENCamera();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENConnections@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENConnections(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENEntity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENEntity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENEntityID@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENEntityID(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENGrid@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENGrid(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENIconsVisible@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENIconsVisible();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENLayerEntities@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENLayerEntities(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENLinesVisible@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENLinesVisible();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENMissionAttribute@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENMissionAttribute(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENMouseOver@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENMouseOver();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Get3DENSelected@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Get3DENSelected(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAimingCoef@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAimingCoef(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllEnv3DSoundControllers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllEnv3DSoundControllers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllEnvSoundControllers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllEnvSoundControllers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllHitPointsDamage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllHitPointsDamage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllOwnedMines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllOwnedMines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllPylonsInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllPylonsInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllSoundControllers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllSoundControllers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAllUnitTraits@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAllUnitTraits(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAmmoCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAmmoCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAnimAimPrecision@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAnimAimPrecision(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAnimSpeedCoef@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAnimSpeedCoef(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetArray@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetArray(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetArtilleryAmmo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetArtilleryAmmo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetArtilleryComputerSettings@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetArtilleryComputerSettings();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetArtilleryETA@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetArtilleryETA(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAssetDLCInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAssetDLCInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAssignedCuratorLogic@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAssignedCuratorLogic(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAssignedCuratorUnit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAssignedCuratorUnit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAttackTarget@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAttackTarget(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetAudioOptionVolumes@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetAudioOptionVolumes();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetBackpackCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetBackpackCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetBleedingRemaining@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetBleedingRemaining(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetBurningValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetBurningValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCalculatePlayerVisibilityByFriendly@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCalculatePlayerVisibilityByFriendly();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCameraViewDirection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCameraViewDirection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCargoIndex@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCargoIndex(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCenterOfMass@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCenterOfMass(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetClientState@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetClientState();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetClientStateNumber@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetClientStateNumber();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCompatiblePylonMagazines@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCompatiblePylonMagazines(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetConnectedUAV@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetConnectedUAV(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetConnectedUAVUnit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetConnectedUAVUnit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetContainerMaxLoad@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetContainerMaxLoad(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCorpse@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCorpse(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCruiseControl@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCruiseControl(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCursorObjectParams@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCursorObjectParams();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCustomAimCoef@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCustomAimCoef(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCustomSoundController@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCustomSoundController(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetCustomSoundControllerCount@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetCustomSoundControllerCount(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDammage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDammage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDebriefingText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDebriefingText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDescription@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDescription(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDirVisual@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDirVisual(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDiverState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDiverState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDLCAssetsUsage@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDLCAssetsUsage();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDLCAssetsUsageByName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDLCAssetsUsageByName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDLCs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDLCs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetDLCUsageTime@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetDLCUsageTime(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEditorCamera@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEditorCamera(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEditorMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEditorMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEditorObjectScope@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEditorObjectScope(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetElevationOffset@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetElevationOffset();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEngineTargetRPMRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEngineTargetRPMRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEnv3DSoundController@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEnv3DSoundController(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEnvSoundController@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEnvSoundController(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetEventHandlerInfo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetEventHandlerInfo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetFatigue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetFatigue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetFieldManualStartPage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetFieldManualStartPage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetForcedFlagTexture@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetForcedFlagTexture(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetForcedSpeed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetForcedSpeed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetFriend@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetFriend(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetFSMVariable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetFSMVariable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetFuelCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetFuelCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetGraphValues@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetGraphValues(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetGroupIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetGroupIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetGroupIconParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetGroupIconParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetGroupIcons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetGroupIcons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetHideFrom@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetHideFrom(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetHit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetHit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetHitIndex@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetHitIndex(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetHitPointDamage@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetHitPointDamage(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetItemCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetItemCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetLighting@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetLighting();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetLightingAt@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetLightingAt(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetLoadedModsInfo@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetLoadedModsInfo();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMagazineCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMagazineCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMarkerColor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMarkerColor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMarkerPos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMarkerPos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMarkerSize@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMarkerSize(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMarkerType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMarkerType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMass@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMass(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMissionConfig@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMissionConfig(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMissionConfigValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMissionConfigValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMissionDLCs@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMissionDLCs();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMissionLayerEntities@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMissionLayerEntities(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMissionLayers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMissionLayers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMissionPath@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMissionPath(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetModelInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetModelInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMousePosition@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMousePosition();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetMusicPlayedTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetMusicPlayedTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectArgument@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectArgument(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectChildren@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectChildren(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectDLC@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectDLC(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectFOV@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectFOV(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectID@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectID(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectMaterials@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectMaterials(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectProxy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectProxy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectScale@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectScale(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectTextures@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectTextures(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetObjectViewDistance@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetObjectViewDistance();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetOpticsMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetOpticsMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetOrDefault@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetOrDefault(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetOrDefaultCall@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetOrDefaultCall(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetOxygenRemaining@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetOxygenRemaining(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPersonUsedDLCs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPersonUsedDLCs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPilotCameraDirection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPilotCameraDirection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPilotCameraPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPilotCameraPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPilotCameraRotation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPilotCameraRotation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPilotCameraTarget@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPilotCameraTarget(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPiPViewDistance@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPiPViewDistance();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPlateNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPlateNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPlayerChannel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPlayerChannel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPlayerID@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPlayerID(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPlayerScores@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPlayerScores(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPlayerUID@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPlayerUID(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPlayerVoNVolume@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPlayerVoNVolume(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosASLVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosASLVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosASLW@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosASLW(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosATL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosATL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosATLVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosATLVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosWorld@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosWorld(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPosWorldVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPosWorldVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetPylonMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetPylonMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetRelDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetRelDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetRelPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetRelPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetRemoteSensorsDisabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetRemoteSensorsDisabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetRepairCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetRepairCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetResolution@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetResolution();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetRoadInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetRoadInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetRotorBrakeRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetRotorBrakeRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSensorTargets@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSensorTargets(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSensorThreats@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSensorThreats(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetShadowDistance@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetShadowDistance();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetShotParents@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetShotParents(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSlingLoad@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSlingLoad(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSoundController@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSoundController(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSoundControllerResult@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSoundControllerResult(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSpeed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSpeed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetStamina@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetStamina(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetStatValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetStatValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSteamFriendsServers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSteamFriendsServers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSubtitleOptions@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSubtitleOptions();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetSuppression@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetSuppression(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTerrainGrid@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTerrainGrid();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTerrainHeight@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTerrainHeight(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTerrainHeightASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTerrainHeightASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTerrainInfo@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTerrainInfo();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTextRaw@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTextRaw(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTextureInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTextureInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTextWidth@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTextWidth(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTIParameters@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTIParameters();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTotalDLCUsageTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTotalDLCUsageTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTowParent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTowParent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTrimOffsetRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTrimOffsetRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTurretLimits@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTurretLimits(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetTurretOpticsMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetTurretOpticsMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUnitFreefallInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUnitFreefallInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUnitLoadout@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUnitLoadout(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUnitTrait@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUnitTrait(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUnloadInCombat@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUnloadInCombat(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUserInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUserInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUserMFDText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUserMFDText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetUserMFDValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetUserMFDValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetVariable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetVariable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetVehicleCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetVehicleCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetVehicleTIPars@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetVehicleTIPars(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetVideoOptions@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetVideoOptions();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetWeaponCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetWeaponCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetWeaponSway@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetWeaponSway(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetWingsOrientationRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetWingsOrientationRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetWingsPositionRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetWingsPositionRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GetWPPos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GetWPPos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GlanceAt@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GlanceAt(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GlobalChat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GlobalChat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GlobalRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GlobalRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Goggles@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Goggles(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Goto@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Goto(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Group@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Group(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupChat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupChat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupFromNetId@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupFromNetId(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupIconSelectable@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupIconSelectable();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupIconsVisible@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupIconsVisible();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupId@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupId(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupOwner@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupOwner(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Groups@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Groups(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupSelectedUnits@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupSelectedUnits(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GroupSelectUnit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GroupSelectUnit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?GrpNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue GrpNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Gunner@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Gunner(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Gusts@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Gusts();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Halt@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Halt();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HandgunItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HandgunItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HandgunMagazine@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HandgunMagazine(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HandgunWeapon@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HandgunWeapon(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HandsHit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HandsHit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HashValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HashValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HasInterface@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HasInterface();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HasPilotCamera@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HasPilotCamera(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HasWeapon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HasWeapon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcAllGroups@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcAllGroups(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcGroupParams@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcGroupParams(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcLeader@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcLeader(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcRemoveAllGroups@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcRemoveAllGroups(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcRemoveGroup@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcRemoveGroup(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcSelected@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcSelected(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcSelectGroup@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcSelectGroup(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcSetGroup@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcSetGroup(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcShowBar@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcShowBar(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HcShownBar@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HcShownBar();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Headgear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Headgear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HideBody@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HideBody(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HideObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HideObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HideObjectGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HideObjectGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HideSelection@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HideSelection(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Hint@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Hint(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HintC@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HintC(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HintCadet@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HintCadet(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HintSilent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HintSilent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Hmd@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Hmd(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HostMission@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HostMission(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HtmlLoad@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HtmlLoad(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?HUDMovementLevels@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue HUDMovementLevels();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Humidity@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Humidity();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?If@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue If(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Image@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Image(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ImportAllGroups@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ImportAllGroups(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Importance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Importance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?In@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue In(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InArea@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InArea(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InAreaArray@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InAreaArray(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IncapacitatedState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IncapacitatedState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Independent@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Independent();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Inflame@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Inflame(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Inflamed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Inflamed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InfoPanel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InfoPanel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InfoPanelComponentEnabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InfoPanelComponentEnabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InfoPanelComponents@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InfoPanelComponents(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InfoPanels@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InfoPanels(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InGameUISetEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InGameUISetEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InheritsFrom@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InheritsFrom(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InitAmbientLife@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InitAmbientLife();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InPolygon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InPolygon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InputAction@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InputAction(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InputController@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InputController(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InputMouse@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InputMouse(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InRangeOfArtillery@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InRangeOfArtillery(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Insert@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Insert(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InsertEditorObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InsertEditorObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?InsideBuilding@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue InsideBuilding(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Intersect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Intersect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Is3DEN@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Is3DEN();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Is3DENMultiplayer@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Is3DENMultiplayer();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Is3DENPreview@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Is3DENPreview();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAbleToBreathe@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAbleToBreathe(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsActionMenuVisible@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsActionMenuVisible();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAgent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAgent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAimPrecisionEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAimPrecisionEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAllowedCrewInImmobile@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAllowedCrewInImmobile(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsArray@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsArray(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAutoHoverOn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAutoHoverOn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAutonomous@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAutonomous(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAutoStartUpEnabledRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAutoStartUpEnabledRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAutotest@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAutotest();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAutoTrimOnRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAutoTrimOnRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsAwake@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsAwake(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsBleeding@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsBleeding(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsBurning@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsBurning(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsClass@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsClass(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsCollisionLightOn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsCollisionLightOn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsCopilotEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsCopilotEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsDamageAllowed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsDamageAllowed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsDedicated@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsDedicated();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsDLCAvailable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsDLCAvailable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEngineOn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEngineOn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualRef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualRef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualTypeAll@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualTypeAll(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualTypeAny@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualTypeAny(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualTypeArray@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualTypeArray(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsEqualTypeParams@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsEqualTypeParams(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsFilePatchingEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsFilePatchingEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsFinal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsFinal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsFlashlightOn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsFlashlightOn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsFlatEmpty@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsFlatEmpty(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsForcedWalk@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsForcedWalk(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsFormationLeader@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsFormationLeader(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsGameFocused@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsGameFocused();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsGamePaused@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsGamePaused();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsGroupDeletedWhenEmpty@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsGroupDeletedWhenEmpty(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsHidden@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsHidden(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsInRemainsCollector@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsInRemainsCollector(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsInstructorFigureEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsInstructorFigureEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsIRLaserOn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsIRLaserOn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsKeyActive@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsKeyActive(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsKindOf@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsKindOf(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsLaserOn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsLaserOn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsLightOn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsLightOn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsLocalized@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsLocalized(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsManualFire@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsManualFire(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsMarkedForCollection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsMarkedForCollection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsMissionProfileNamespaceLoaded@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsMissionProfileNamespaceLoaded();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsMultiplayer@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsMultiplayer();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsMultiplayerSolo@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsMultiplayerSolo();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsNil@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsNil(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsNotEqualRef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsNotEqualRef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsNotEqualTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsNotEqualTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsNull@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsNull(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsObjectHidden@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsObjectHidden(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsObjectRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsObjectRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsOnRoad@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsOnRoad(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsPiPEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsPiPEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsPlayer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsPlayer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsRealTime@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsRealTime(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsRemoteExecuted@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsRemoteExecuted();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsRemoteExecutedJIP@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsRemoteExecutedJIP();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsSaving@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsSaving();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsSensorTargetConfirmed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsSensorTargetConfirmed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsServer@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsServer();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsShowing3DIcons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsShowing3DIcons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsSimpleObject@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsSimpleObject(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsSprintAllowed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsSprintAllowed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsStaminaEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsStaminaEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsSteamMission@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsSteamMission();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsSteamOverlayEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsSteamOverlayEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsStreamFriendlyUIEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsStreamFriendlyUIEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsStressDamageEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsStressDamageEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsTouchingGround@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsTouchingGround(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsTurnedOut@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsTurnedOut(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsTutHintsEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsTutHintsEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsUAVConnectable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsUAVConnectable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsUAVConnected@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsUAVConnected(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsUIContext@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsUIContext();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsUniformAllowed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsUniformAllowed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsVehicleCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsVehicleCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsVehicleRadarOn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsVehicleRadarOn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsVehicleSensorEnabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsVehicleSensorEnabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsWalking@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsWalking(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsWeaponDeployed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsWeaponDeployed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?IsWeaponRested@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue IsWeaponRested(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ItemCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ItemCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Items@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Items(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ItemsWithMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ItemsWithMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Join@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Join(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?JoinAs@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue JoinAs(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?JoinAsSilent@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue JoinAsSilent(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?JoinSilent@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue JoinSilent(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?JoinString@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue JoinString(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbAddDatabase@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbAddDatabase(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbAddDatabaseTargets@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbAddDatabaseTargets(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbAddTopic@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbAddTopic(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbHasTopic@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbHasTopic(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbReact@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbReact(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbRemoveTopic@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbRemoveTopic(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbTell@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbTell(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KbWasSaid@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KbWasSaid(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KeyImage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KeyImage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KeyName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KeyName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Keys@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Keys(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?KnowsAbout@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue KnowsAbout(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Land@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Land(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LandAt@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LandAt(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LandResult@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LandResult(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Language@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Language();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LaserTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LaserTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbClear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbClear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbColorRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbColorRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbCurSel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbCurSel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbDelete@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbDelete(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbIsSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbIsSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbPictureRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbPictureRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSelection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSelection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetColorRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetColorRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetCurSel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetCurSel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureColorDisabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureColorDisabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureColorSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureColorSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureRightColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureRightColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureRightColorDisabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureRightColorDisabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetPictureRightColorSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetPictureRightColorSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetSelectColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetSelectColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetSelectColorRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetSelectColorRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetTextRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetTextRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetTooltip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetTooltip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSetValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSetValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSize@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSize(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSort@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSort(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSortBy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSortBy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbSortByValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbSortByValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbTextRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbTextRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbTooltip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbTooltip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LbValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LbValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Leader@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Leader(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardDeInit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardDeInit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardGetRows@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardGetRows(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardInit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardInit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardRequestRowsFriends@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardRequestRowsFriends(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardRequestRowsGlobal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardRequestRowsGlobal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardRequestRowsGlobalAroundUser@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardRequestRowsGlobalAroundUser(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardsRequestUploadScore@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardsRequestUploadScore(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardsRequestUploadScoreKeepBest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardsRequestUploadScoreKeepBest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaderboardState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaderboardState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LeaveVehicle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LeaveVehicle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LibraryCredits@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LibraryCredits();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LibraryDisclaimers@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LibraryDisclaimers();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LifeState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LifeState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LightAttachObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LightAttachObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LightDetachObject@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LightDetachObject(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LightIsOn@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LightIsOn(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Lightnings@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Lightnings();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LimitSpeed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LimitSpeed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LinearConversion@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LinearConversion(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LineBreak@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LineBreak();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LineIntersects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LineIntersects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LineIntersectsObjs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LineIntersectsObjs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LineIntersectsSurfaces@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LineIntersectsSurfaces(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LineIntersectsWith@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LineIntersectsWith(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LinkItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LinkItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?List@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue List(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ListObjects@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ListObjects(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ListRemoteTargets@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ListRemoteTargets(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ListVehicleSensors@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ListVehicleSensors(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Ln@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Ln(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbAddArray@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbAddArray(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbAddColumn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbAddColumn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbAddRow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbAddRow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbClear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbClear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbColorRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbColorRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbCurSelRow@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbCurSelRow(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbDeleteColumn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbDeleteColumn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbDeleteRow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbDeleteRow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbGetColumnsPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbGetColumnsPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbPictureRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbPictureRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetColorRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetColorRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetColumnsPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetColumnsPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetCurSelRow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetCurSelRow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetPictureColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetPictureColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetPictureColorRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetPictureColorRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetPictureColorSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetPictureColorSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetPictureColorSelectedRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetPictureColorSelectedRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetPictureRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetPictureRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetTextRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetTextRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetTooltip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetTooltip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSetValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSetValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSize@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSize(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSort@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSort(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSortBy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSortBy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbSortByValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbSortByValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbTextRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbTextRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LnbValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LnbValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Load@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Load(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadAbs@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadAbs(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadConfig@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadConfig(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadFile@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadFile(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadGame@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadGame();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadIdentity@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadIdentity(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadMagazine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadMagazine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadOverlay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadOverlay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadStatus@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadStatus(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadUniform@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadUniform(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LoadVest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LoadVest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Local@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Local(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Localize@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Localize(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LocalNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LocalNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LocationNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LocationNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LocationPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LocationPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Lock@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Lock(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockCameraTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockCameraTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockDriver@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockDriver(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Locked@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Locked(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockedCameraTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockedCameraTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockedCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockedCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockedDriver@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockedDriver(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockedInventory@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockedInventory(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockedTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockedTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockIdentity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockIdentity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockInventory@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockInventory(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LockWP@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LockWP(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Log@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Log(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LogEntities@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LogEntities();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LogNetwork@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LogNetwork(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LogNetworkTerminate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LogNetworkTerminate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LookAt@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LookAt(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?LookAtPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue LookAtPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazineCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazineCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Magazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Magazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesAllTurrets@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesAllTurrets(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesAmmo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesAmmo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesAmmoCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesAmmoCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesAmmoFull@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesAmmoFull(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesDetail@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesDetail(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesDetailBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesDetailBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesDetailUniform@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesDetailUniform(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesDetailVest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesDetailVest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazinesTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazinesTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MagazineTurretAmmo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MagazineTurretAmmo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MapAnimAdd@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MapAnimAdd(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MapAnimClear@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MapAnimClear();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MapAnimCommit@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MapAnimCommit();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MapAnimDone@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MapAnimDone();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MapCenterOnCamera@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MapCenterOnCamera(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MapGridPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MapGridPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkAsFinishedOnSteam@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkAsFinishedOnSteam();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerAlpha@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerAlpha(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerBrush@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerBrush(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerChannel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerChannel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerColor@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerColor(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerDir@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerDir(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerPolyline@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerPolyline(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerPos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerPos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerShadow@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerShadow(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerShape@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerShape(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerSize@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerSize(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MarkerType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MarkerType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MatrixMultiply@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MatrixMultiply(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MatrixTranspose@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MatrixTranspose(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Max@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Max(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MaxLoad@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MaxLoad(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Members@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Members(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuChecked@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuChecked(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuClear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuClear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuCollapse@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuCollapse(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuDelete@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuDelete(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuEnable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuEnable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuEnabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuEnabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuExpand@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuExpand(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuHover@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuHover(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetCheck@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetCheck(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetShortcut@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetShortcut(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetURL@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetURL(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSetValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSetValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuShortcut@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuShortcut(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuShortcutText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuShortcutText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSize@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSize(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuSort@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuSort(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuURL@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuURL(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MenuValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MenuValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Merge@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Merge(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Min@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Min(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MineActive@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MineActive(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MineDetectedBy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MineDetectedBy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissileTarget@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissileTarget(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissileTargetPos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissileTargetPos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionConfigFile@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionConfigFile();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionDifficulty@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionDifficulty();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionEnd@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionEnd();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionName@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionName();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionNameSource@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionNameSource();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionProfileNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionProfileNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionStart@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionStart();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MissionVersion@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MissionVersion();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Mod@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Mod(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ModelToWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ModelToWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ModelToWorldVisual@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ModelToWorldVisual(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ModelToWorldVisualWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ModelToWorldVisualWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ModelToWorldWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ModelToWorldWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ModParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ModParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoonIntensity@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoonIntensity();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoonPhase@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoonPhase(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Morale@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Morale(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Move@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Move(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Move3DENCamera@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Move3DENCamera(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveInAny@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveInAny(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveInCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveInCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveInCommander@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveInCommander(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveInDriver@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveInDriver(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveInGunner@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveInGunner(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveInTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveInTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveObjectToEnd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveObjectToEnd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveOut@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveOut(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveTime@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveTime(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveToCompleted@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveToCompleted(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MoveToFailed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MoveToFailed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?MusicVolume@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue MusicVolume();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Name@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Name(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NamedProperties@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NamedProperties(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NameSound@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NameSound(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearEntities@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearEntities(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestBuilding@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestBuilding(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestLocation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestLocation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestLocations@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestLocations(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestLocationWithDubbing@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestLocationWithDubbing(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestMines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestMines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearestTerrainObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearestTerrainObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearObjects@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearObjects(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearObjectsReady@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearObjectsReady(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearRoads@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearRoads(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearSupplies@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearSupplies(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NearTargets@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NearTargets(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NeedReload@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NeedReload(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NeedService@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NeedService(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NetId@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NetId(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NetObjNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NetObjNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NewOverlay@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NewOverlay(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NextMenuItemIndex@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NextMenuItemIndex(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NextWeatherChange@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NextWeatherChange();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Nil@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Nil();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NMenuItems@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NMenuItems(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Not@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Not(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NumberOfEnginesRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NumberOfEnginesRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?NumberToDate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue NumberToDate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ObjectCurators@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ObjectCurators(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ObjectFromNetId@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ObjectFromNetId(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ObjectParent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ObjectParent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ObjNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ObjNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ObjStatus@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ObjStatus(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnBriefingGroup@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnBriefingGroup(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnBriefingNotes@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnBriefingNotes(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnBriefingPlan@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnBriefingPlan(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnBriefingTeamSwitch@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnBriefingTeamSwitch(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnCommandModeChanged@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnCommandModeChanged(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnDoubleClick@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnDoubleClick(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnEachFrame@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnEachFrame(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnGroupIconClick@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnGroupIconClick(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnGroupIconOverEnter@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnGroupIconOverEnter(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnGroupIconOverLeave@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnGroupIconOverLeave(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnHCGroupSelectionChanged@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnHCGroupSelectionChanged(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnMapSingleClick@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnMapSingleClick(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnPlayerConnected@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnPlayerConnected(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnPlayerDisconnected@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnPlayerDisconnected(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnPreloadFinished@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnPreloadFinished(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnPreloadStarted@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnPreloadStarted(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnShowNewObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnShowNewObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OnTeamSwitch@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OnTeamSwitch(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OpenCuratorInterface@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OpenCuratorInterface();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OpenDLCPage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OpenDLCPage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OpenGPS@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OpenGPS(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OpenMap@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OpenMap(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OpenSteamApp@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OpenSteamApp(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OpenYoutubeVideo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OpenYoutubeVideo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Opfor@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Opfor();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Or@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Or(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OrderGetIn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OrderGetIn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Overcast@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Overcast();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?OvercastForecast@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue OvercastForecast();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Owner@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Owner(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Param@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Param(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Params@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Params(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ParseNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ParseNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ParseSimpleArray@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ParseSimpleArray(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ParseText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ParseText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ParsingNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ParsingNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ParticlesQuality@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ParticlesQuality();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PeriscopeElevation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PeriscopeElevation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Pi@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Pi();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PickWeaponPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PickWeaponPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Pitch@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Pitch(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PixelGrid@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PixelGrid();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PixelGridBase@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PixelGridBase();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PixelGridNoUIScale@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PixelGridNoUIScale();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PixelH@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PixelH();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PixelW@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PixelW();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayableSlotsNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayableSlotsNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayableUnits@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayableUnits();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayActionNow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayActionNow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Player@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Player();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayerRespawnTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayerRespawnTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayerSide@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayerSide();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayersNumber@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayersNumber(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayGesture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayGesture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayMission@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayMission(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayMove@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayMove(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayMoveNow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayMoveNow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayMusic@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayMusic(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlayScriptedMission@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlayScriptedMission(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "PlaySound")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlaySound(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlaySound3D@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlaySound3D(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PlaySoundUI@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PlaySoundUI(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Pose@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Pose(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Position@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Position(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PositionCameraToWorld@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PositionCameraToWorld(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PosScreenToWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PosScreenToWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PosWorldToScreen@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PosWorldToScreen(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectAdjust@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectAdjust(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectCommit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectCommit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectCommitted@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectCommitted(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectCreate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectCreate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectDestroy@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectDestroy(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectEnable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectEnable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PpEffectForceInNVG@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PpEffectForceInNVG(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Precision@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Precision(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreloadCamera@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreloadCamera(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreloadObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreloadObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreloadSound@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreloadSound(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreloadTitleObj@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreloadTitleObj(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreloadTitleRsc@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreloadTitleRsc(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreprocessFile@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreprocessFile(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PreprocessFileLineNumbers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PreprocessFileLineNumbers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PrimaryWeapon@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PrimaryWeapon(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PrimaryWeaponItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PrimaryWeaponItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PrimaryWeaponMagazine@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PrimaryWeaponMagazine(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Priority@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Priority(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Private@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Private(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProcessDiaryLink@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProcessDiaryLink(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProductVersion@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProductVersion();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProfileName@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProfileName();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProfileNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProfileNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProfileNameSteam@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProfileNameSteam();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProgressLoadingScreen@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProgressLoadingScreen(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProgressPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProgressPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ProgressSetPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ProgressSetPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PublicVariable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PublicVariable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PublicVariableClient@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PublicVariableClient(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PublicVariableServer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PublicVariableServer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PushBack@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PushBack(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PushBackUnique@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PushBackUnique(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?PutWeaponPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue PutWeaponPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?QueryItemsPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue QueryItemsPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?QueryMagazinePool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue QueryMagazinePool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?QueryWeaponPool@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue QueryWeaponPool(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Rad@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Rad(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioChannelAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioChannelAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioChannelCreate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioChannelCreate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioChannelInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioChannelInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioChannelRemove@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioChannelRemove(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioChannelSetCallSign@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioChannelSetCallSign(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioChannelSetLabel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioChannelSetLabel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RadioVolume@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RadioVolume();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Rain@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Rain();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Rainbow@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Rainbow();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RainParams@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RainParams();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Random@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Random(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Rank@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Rank(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RankId@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RankId(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Rating@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Rating(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Rectangular@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Rectangular(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RegexFind@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RegexFind(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RegexMatch@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RegexMatch(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RegexReplace@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RegexReplace(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RegisteredTasks@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RegisteredTasks(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RegisterTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RegisterTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Reload@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Reload(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ReloadEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ReloadEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoteControl@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoteControl(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoteExec@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoteExec(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoteExecCall@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoteExecCall(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoteExecutedOwner@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoteExecutedOwner();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Remove3DENConnection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Remove3DENConnection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Remove3DENEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Remove3DENEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Remove3DENLayer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Remove3DENLayer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAll3DENEventHandlers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAll3DENEventHandlers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllActions@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllActions(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllAssignedItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllAssignedItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllBinocularItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllBinocularItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllContainers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllContainers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllCuratorAddons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllCuratorAddons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllCuratorCameraAreas@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllCuratorCameraAreas(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllCuratorEditingAreas@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllCuratorEditingAreas(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllEventHandlers@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllEventHandlers(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllHandgunItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllHandgunItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllItemsWithMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllItemsWithMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllMissionEventHandlers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllMissionEventHandlers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllMPEventHandlers@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllMPEventHandlers(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllMusicEventHandlers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllMusicEventHandlers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllOwnedMines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllOwnedMines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllPrimaryWeaponItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllPrimaryWeaponItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllSecondaryWeaponItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllSecondaryWeaponItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllUserActionEventHandlers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllUserActionEventHandlers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveAllWeapons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveAllWeapons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveBackpackGlobal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveBackpackGlobal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveBinocularItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveBinocularItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveCuratorAddons@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveCuratorAddons(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveCuratorCameraArea@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveCuratorCameraArea(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveCuratorEditableObjects@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveCuratorEditableObjects(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveCuratorEditingArea@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveCuratorEditingArea(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveDiaryRecord@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveDiaryRecord(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveDiarySubject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveDiarySubject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveDrawIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveDrawIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveDrawLinks@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveDrawLinks(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveFromRemainsCollector@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveFromRemainsCollector(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveGoggles@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveGoggles(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveGroupIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveGroupIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveHandgunItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveHandgunItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveHeadgear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveHeadgear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveItemFromBackpack@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveItemFromBackpack(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveItemFromUniform@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveItemFromUniform(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveItemFromVest@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveItemFromVest(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveItems@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveItems(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMagazine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMagazine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMagazineGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMagazineGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMagazines@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMagazines(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMagazinesTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMagazinesTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMagazineTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMagazineTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMenuItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMenuItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMissionEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMissionEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMPEventHandler@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMPEventHandler(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveMusicEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveMusicEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveOwnedMine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveOwnedMine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemovePrimaryWeaponItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemovePrimaryWeaponItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveSecondaryWeaponItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveSecondaryWeaponItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveSimpleTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveSimpleTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveSwitchableUnit@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveSwitchableUnit(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveTeamMember@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveTeamMember(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveUniform@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveUniform(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveUserActionEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveUserActionEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveVest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveVest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveWeapon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveWeapon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveWeaponAttachmentCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveWeaponAttachmentCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveWeaponCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveWeaponCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveWeaponGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveWeaponGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RemoveWeaponTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RemoveWeaponTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ReportRemoteTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ReportRemoteTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RequiredVersion@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RequiredVersion(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ResetCamShake@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ResetCamShake();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ResetSubgroupDirection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ResetSubgroupDirection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Resistance@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Resistance();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Resize@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Resize(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Resources@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Resources(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RespawnVehicle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RespawnVehicle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RestartEditorCamera@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RestartEditorCamera(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Reveal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Reveal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RevealMine@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RevealMine(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Reverse@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Reverse(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ReversedMouseY@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ReversedMouseY();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RoadAt@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RoadAt(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RoadsConnectedTo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RoadsConnectedTo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RoleDescription@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RoleDescription(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeAttachedObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeAttachedObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeAttachedTo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeAttachedTo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeAttachEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeAttachEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeAttachTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeAttachTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeCreate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeCreate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeCut@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeCut(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeDestroy@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeDestroy(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeDetach@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeDetach(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeEndPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeEndPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeLength@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeLength(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Ropes@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Ropes(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopesAttachedTo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopesAttachedTo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeSegments@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeSegments(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeUnwind@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeUnwind(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RopeUnwound@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RopeUnwound(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RotorsForcesRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RotorsForcesRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RotorsRpmRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RotorsRpmRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Round@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Round(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?RunInitScript@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue RunInitScript();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SafeZoneH@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SafeZoneH();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SafeZoneW@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SafeZoneW();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SafeZoneWAbs@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SafeZoneWAbs();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SafeZoneX@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SafeZoneX();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SafeZoneXAbs@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SafeZoneXAbs();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SafeZoneY@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SafeZoneY();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Save3DENInventory@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Save3DENInventory(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveGame@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveGame();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveIdentity@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveIdentity(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveJoysticks@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveJoysticks();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveMissionProfileNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveMissionProfileNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveOverlay@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveOverlay(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveProfileNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveProfileNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveStatus@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveStatus(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SaveVar@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SaveVar(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SavingEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SavingEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Say@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Say(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Say2D@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Say2D(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Say3D@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Say3D(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScopeName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScopeName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Score@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Score(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScoreSide@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScoreSide(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Screenshot@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Screenshot(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScreenToWorld@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScreenToWorld(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScriptDone@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScriptDone(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScriptName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScriptName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScriptNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScriptNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ScudState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ScudState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SecondaryWeapon@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SecondaryWeapon(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SecondaryWeaponItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SecondaryWeaponItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SecondaryWeaponMagazine@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SecondaryWeaponMagazine(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Select@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Select(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectBestPlaces@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectBestPlaces(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectDiarySubject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectDiarySubject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectedEditorObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectedEditorObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectEditorObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectEditorObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectionNames@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectionNames(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectionPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectionPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectionVectorDirAndUp@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectionVectorDirAndUp(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectLeader@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectLeader(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectMax@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectMax(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectMin@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectMin(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectNoPlayer@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectNoPlayer();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectPlayer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectPlayer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectRandom@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectRandom(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectRandomWeighted@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectRandomWeighted(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectWeapon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectWeapon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SelectWeaponTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SelectWeaponTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SendAUMessage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SendAUMessage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SendSimpleCommand@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SendSimpleCommand(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SendTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SendTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SendTaskResult@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SendTaskResult(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SendUDPMessage@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SendUDPMessage(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SentencesEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SentencesEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ServerCommand@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ServerCommand(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ServerCommandAvailable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ServerCommandAvailable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ServerCommandExecutable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ServerCommandExecutable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ServerName@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ServerName();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ServerNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ServerNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ServerTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ServerTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENAttribute@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENAttribute(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENAttributes@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENAttributes(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENGrid@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENGrid(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENIconsVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENIconsVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENLayer@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENLayer(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENLinesVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENLinesVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENLogicType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENLogicType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENMissionAttribute@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENMissionAttribute(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENMissionAttributes@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENMissionAttributes(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENModelsVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENModelsVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENObjectType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENObjectType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Set3DENSelected@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Set3DENSelected(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAccTime@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAccTime(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetActualCollectiveRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetActualCollectiveRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAirplaneThrottle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAirplaneThrottle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAirportSide@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAirportSide(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAmmo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAmmo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAmmoCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAmmoCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAmmoOnPylon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAmmoOnPylon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAnimSpeedCoef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAnimSpeedCoef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAperture@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAperture(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetApertureNew@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetApertureNew(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetArmoryPoints@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetArmoryPoints(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAttributes@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAttributes(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetAutonomous@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetAutonomous(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetBehaviour@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetBehaviour(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetBehaviourStrong@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetBehaviourStrong(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetBleedingRemaining@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetBleedingRemaining(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetBrakesRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetBrakesRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCameraInterest@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCameraInterest(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCamShakeDefParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCamShakeDefParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCamShakeParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCamShakeParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCamUseTI@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCamUseTI(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCaptive@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCaptive(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCenterOfMass@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCenterOfMass(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCollisionLight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCollisionLight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCombatBehaviour@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCombatBehaviour(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCombatMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCombatMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCompassOscillation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCompassOscillation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetConvoySeparation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetConvoySeparation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCruiseControl@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCruiseControl(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCuratorCameraAreaCeiling@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCuratorCameraAreaCeiling(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCuratorCoef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCuratorCoef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCuratorEditingAreaType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCuratorEditingAreaType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCuratorWaypointCost@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCuratorWaypointCost(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCurrentChannel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCurrentChannel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCurrentTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCurrentTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCurrentWaypoint@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCurrentWaypoint(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCustomAimCoef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCustomAimCoef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCustomMissionData@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCustomMissionData(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCustomSoundController@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCustomSoundController(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetCustomWeightRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetCustomWeightRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDamage@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDamage(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDammage@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDammage(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDebriefingText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDebriefingText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDefaultCamera@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDefaultCamera(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDestination@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDestination(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDetailMapBlendPars@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDetailMapBlendPars(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDiaryRecordText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDiaryRecordText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDiarySubjectPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDiarySubjectPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDirection@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDirection(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDrawIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDrawIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDriveOnPath@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDriveOnPath(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDropInterval@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDropInterval(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDynamicSimulationDistance@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDynamicSimulationDistance(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetDynamicSimulationDistanceCoef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetDynamicSimulationDistanceCoef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetEditorMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetEditorMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetEditorObjectScope@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetEditorObjectScope(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetEffectCondition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetEffectCondition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetEffectiveCommander@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetEffectiveCommander(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetEngineRpmRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetEngineRpmRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFace@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFace(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFaceAnimation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFaceAnimation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFatigue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFatigue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFeatureType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFeatureType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFlagAnimationPhase@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFlagAnimationPhase(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFlagOwner@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFlagOwner(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFlagSide@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFlagSide(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFlagTexture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFlagTexture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFog@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFog(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetForceGeneratorRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetForceGeneratorRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFormation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFormation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFormationTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFormationTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFormDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFormDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFriend@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFriend(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFromEditor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFromEditor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFSMVariable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFSMVariable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFuel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFuel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetFuelCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetFuelCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupIconParams@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupIconParams(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupIconsSelectable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupIconsSelectable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupIconsVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupIconsVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupId@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupId(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupIdGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupIdGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGroupOwner@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGroupOwner(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetGusts@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetGusts(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHideBehind@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHideBehind(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHitIndex@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHitIndex(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHitPointDamage@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHitPointDamage(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHorizonParallaxCoef@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHorizonParallaxCoef(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHUDMovementLevels@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHUDMovementLevels(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetHumidity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetHumidity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetIdentity@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetIdentity(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetImportance@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetImportance(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetInfoPanel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetInfoPanel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLeader@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLeader(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightAmbient@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightAmbient(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightAttenuation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightAttenuation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightBrightness@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightBrightness(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightConePars@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightConePars(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightDayLight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightDayLight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightFlareMaxDistance@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightFlareMaxDistance(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightFlareSize@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightFlareSize(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightIntensity@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightIntensity(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightIR@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightIR(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightnings@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightnings(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightUseFlare@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightUseFlare(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLightVolumeShape@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLightVolumeShape(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetLocalWindParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetLocalWindParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMagazineTurretAmmo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMagazineTurretAmmo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerAlpha@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerAlpha(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerAlphaLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerAlphaLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerBrush@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerBrush(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerBrushLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerBrushLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerColorLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerColorLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerDirLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerDirLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerPolyline@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerPolyline(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerPolylineLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerPolylineLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerPosLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerPosLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerShadow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerShadow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerShadowLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerShadowLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerShape@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerShape(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerShapeLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerShapeLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerSize@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerSize(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerSizeLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerSizeLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerTextLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerTextLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMarkerTypeLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMarkerTypeLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMass@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMass(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMaxLoad@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMaxLoad(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMimic@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMimic(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMissileTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMissileTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMissileTargetPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMissileTargetPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMousePosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMousePosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMusicEffect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMusicEffect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetMusicEventHandler@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetMusicEventHandler(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetName@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetName(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetNameSound@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetNameSound(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectArguments@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectArguments(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectMaterial@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectMaterial(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectMaterialGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectMaterialGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectProxy@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectProxy(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectScale@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectScale(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectTexture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectTexture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectTextureGlobal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectTextureGlobal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetObjectViewDistance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetObjectViewDistance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetOpticsMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetOpticsMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetOvercast@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetOvercast(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetOwner@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetOwner(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetOxygenRemaining@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetOxygenRemaining(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetParticleCircle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetParticleCircle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetParticleClass@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetParticleClass(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetParticleFire@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetParticleFire(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetParticleParams@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetParticleParams(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetParticleRandom@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetParticleRandom(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPilotCameraDirection@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPilotCameraDirection(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPilotCameraRotation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPilotCameraRotation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPilotCameraTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPilotCameraTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPilotLight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPilotLight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPiPEffect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPiPEffect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPiPViewDistance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPiPViewDistance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPitch@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPitch(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPlateNumber@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPlateNumber(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPlayable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPlayable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPlayerRespawnTime@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPlayerRespawnTime(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPlayerVoNVolume@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPlayerVoNVolume(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPosASL@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPosASL(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPosASL2@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPosASL2(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPosASLW@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPosASLW(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPosATL@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPosATL(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPosWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPosWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPylonLoadout@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPylonLoadout(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetPylonsPriority@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetPylonsPriority(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRadioMsg@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRadioMsg(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRain@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRain(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRainbow@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRainbow(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRandomLip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRandomLip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRank@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRank(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRectangular@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRectangular(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRepairCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRepairCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetRotorBrakeRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetRotorBrakeRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetShadowDistance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetShadowDistance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetShotParents@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetShotParents(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSide@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSide(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimpleTaskAlwaysVisible@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimpleTaskAlwaysVisible(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimpleTaskCustomData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimpleTaskCustomData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimpleTaskDescription@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimpleTaskDescription(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimpleTaskDestination@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimpleTaskDestination(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimpleTaskTarget@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimpleTaskTarget(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimpleTaskType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimpleTaskType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSimulWeatherLayers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSimulWeatherLayers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSize@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSize(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSkill@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSkill(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSlingLoad@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSlingLoad(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSoundEffect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSoundEffect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSpeaker@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSpeaker(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSpeech@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSpeech(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSpeedMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSpeedMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetStamina@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetStamina(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetStaminaScheme@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetStaminaScheme(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetStatValue@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetStatValue(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSuppression@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSuppression(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetSystemOfUnits@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetSystemOfUnits(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTargetAge@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTargetAge(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTaskMarkerOffset@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTaskMarkerOffset(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTaskResult@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTaskResult(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTaskState@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTaskState(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTerrainGrid@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTerrainGrid(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTerrainHeight@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTerrainHeight(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTimeMultiplier@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTimeMultiplier(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTIParameter@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTIParameter(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTitleEffect@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTitleEffect(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTowParent@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTowParent(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTrafficDensity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTrafficDensity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTrafficDistance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTrafficDistance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTrafficGap@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTrafficGap(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTrafficSpeed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTrafficSpeed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerActivation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerActivation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerArea@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerArea(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerInterval@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerInterval(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerStatements@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerStatements(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerTimeout@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerTimeout(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTriggerType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTriggerType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTurretLimits@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTurretLimits(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetTurretOpticsMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetTurretOpticsMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnconscious@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnconscious(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitAbility@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitAbility(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitCombatMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitCombatMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitFreefallHeight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitFreefallHeight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitLoadout@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitLoadout(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitPosWeak@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitPosWeak(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitRank@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitRank(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitRecoilCoefficient@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitRecoilCoefficient(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnitTrait@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnitTrait(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUnloadInCombat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUnloadInCombat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUserActionText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUserActionText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUserMFDText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUserMFDText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetUserMFDValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetUserMFDValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVariable@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVariable(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVectorDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVectorDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVectorDirAndUp@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVectorDirAndUp(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVectorUp@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVectorUp(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleAmmo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleAmmo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleAmmoDef@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleAmmoDef(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleArmor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleArmor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleId@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleId(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleLock@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleLock(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehiclePosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehiclePosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleRadar@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleRadar(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleReceiveRemoteTargets@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleReceiveRemoteTargets(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleReportOwnPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleReportOwnPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleReportRemoteTargets@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleReportRemoteTargets(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleTIPars@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleTIPars(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVehicleVarName@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVehicleVarName(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVelocity@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVelocity(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVelocityModelSpace@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVelocityModelSpace(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVelocityTransformation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVelocityTransformation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetViewDistance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetViewDistance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetVisibleIfTreeCollapsed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetVisibleIfTreeCollapsed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWantedRPMRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWantedRPMRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaves@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaves(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointBehaviour@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointBehaviour(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointCombatMode@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointCombatMode(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointCompletionRadius@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointCompletionRadius(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointDescription@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointDescription(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointForceBehaviour@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointForceBehaviour(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointFormation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointFormation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointHousePosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointHousePosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointLoiterAltitude@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointLoiterAltitude(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointLoiterRadius@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointLoiterRadius(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointLoiterType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointLoiterType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointName@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointName(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointScript@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointScript(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointSpeed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointSpeed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointStatements@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointStatements(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointTimeout@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointTimeout(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointType@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointType(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWaypointVisible@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWaypointVisible(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWeaponReloadingTime@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWeaponReloadingTime(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWeaponZeroing@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWeaponZeroing(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWind@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWind(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWindDir@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWindDir(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWindForce@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWindForce(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWindStr@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWindStr(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWingForceScaleRTD@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWingForceScaleRTD(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SetWPPos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SetWPPos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Show3DIcons@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Show3DIcons(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowChat@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowChat(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowCinemaBorder@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowCinemaBorder(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowCommandingMenu@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowCommandingMenu(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowCompass@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowCompass(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowCuratorCompass@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowCuratorCompass(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowGPS@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowGPS(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowHUD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowHUD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowLegend@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowLegend(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowMap@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowMap(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownArtilleryComputer@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownArtilleryComputer();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownChat@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownChat();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownCompass@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownCompass();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownCuratorCompass@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownCuratorCompass();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowNewEditorObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowNewEditorObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownGPS@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownGPS();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownHUD@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownHUD();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownMap@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownMap();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownPad@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownPad();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownRadio@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownRadio();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownScoretable@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownScoretable();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownSubtitles@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownSubtitles();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownUAVFeed@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownUAVFeed();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownWarrant@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownWarrant();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShownWatch@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShownWatch();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowPad@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowPad(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowRadio@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowRadio(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowScoretable@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowScoretable(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowSubtitles@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowSubtitles(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowUAVFeed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowUAVFeed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowWarrant@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowWarrant(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowWatch@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowWatch(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowWaypoint@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowWaypoint(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ShowWaypoints@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ShowWaypoints(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Side@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Side(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideAmbientLife@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideAmbientLife();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideChat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideChat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideEmpty@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideEmpty();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideEnemy@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideEnemy();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideFriendly@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideFriendly();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideLogic@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideLogic();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SideUnknown@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SideUnknown();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SimpleTasks@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SimpleTasks(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SimulationEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SimulationEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SimulCloudDensity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SimulCloudDensity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SimulCloudOcclusion@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SimulCloudOcclusion(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SimulInClouds@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SimulInClouds(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SimulWeatherSync@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SimulWeatherSync();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Sin@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Sin(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Size@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Size(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SizeOf@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SizeOf(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Skill@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Skill(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SkillFinal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SkillFinal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SkipTime@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SkipTime(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Sleep@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Sleep(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SliderPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SliderPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SliderRange@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SliderRange(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SliderSetPosition@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SliderSetPosition(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SliderSetRange@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SliderSetRange(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SliderSetSpeed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SliderSetSpeed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SliderSpeed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SliderSpeed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SlingLoadAssistantShown@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SlingLoadAssistantShown();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SoldierMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SoldierMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SomeAmmo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SomeAmmo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Sort@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Sort(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SoundVolume@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SoundVolume();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Spawn@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Spawn(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Speaker@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Speaker(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SpeechVolume@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SpeechVolume();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Speed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Speed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SpeedMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SpeedMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SplitString@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SplitString(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Sqrt@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Sqrt(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SquadParams@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SquadParams(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Stance@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Stance(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?StartLoadingScreen@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue StartLoadingScreen(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Step@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Step(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Stop@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Stop(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?StopEngineRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue StopEngineRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Stopped@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Stopped(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Str@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Str(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SunOrMoon@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SunOrMoon();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SupportInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SupportInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SuppressFor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SuppressFor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SurfaceIsWater@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SurfaceIsWater(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SurfaceNormal@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SurfaceNormal(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SurfaceTexture@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SurfaceTexture(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SurfaceType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SurfaceType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwimInDepth@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwimInDepth(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Switch@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Switch(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwitchableUnits@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwitchableUnits();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwitchAction@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwitchAction(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwitchCamera@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwitchCamera(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwitchGesture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwitchGesture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwitchLight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwitchLight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SwitchMove@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SwitchMove(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizedObjects@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizedObjects(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizedTriggers@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizedTriggers(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizedWaypoints@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizedWaypoints(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizeObjectsAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizeObjectsAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizeObjectsRemove@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizeObjectsRemove(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizeTrigger@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizeTrigger(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SynchronizeWaypoint@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SynchronizeWaypoint(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SystemChat@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SystemChat(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SystemOfUnits@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SystemOfUnits();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SystemTime@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SystemTime();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?SystemTimeUTC@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue SystemTimeUTC();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Tan@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Tan(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TargetKnowledge@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TargetKnowledge(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Targets@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Targets(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TargetsAggregate@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TargetsAggregate(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TargetsQuery@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TargetsQuery(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskAlwaysVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskAlwaysVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskChildren@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskChildren(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskCompleted@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskCompleted(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskCustomData@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskCustomData(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskDescription@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskDescription(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskDestination@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskDestination(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskHint@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskHint(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskMarkerOffset@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskMarkerOffset(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskParent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskParent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskResult@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskResult(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskState@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskState(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TaskType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TaskType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TeamMember@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TeamMember(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TeamMemberNull@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TeamMemberNull();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TeamName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TeamName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Teams@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Teams();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TeamSwitch@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TeamSwitch();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TeamSwitchEnabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TeamSwitchEnabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TeamType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TeamType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Terminate@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Terminate(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TerrainIntersect@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TerrainIntersect(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TerrainIntersectASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TerrainIntersectASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TerrainIntersectAtASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TerrainIntersectAtASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Text@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Text(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TextLog@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TextLog(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TextLogFormat@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TextLogFormat(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Tg@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Tg(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Then@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Then(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Throw@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Throw(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Time@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Time();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TimeMultiplier@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TimeMultiplier();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TitleCut@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TitleCut(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TitleFadeOut@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TitleFadeOut(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TitleObj@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TitleObj(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TitleRsc@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TitleRsc(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TitleText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TitleText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?To@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue To(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToArray@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToArray(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToFixed@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToFixed(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToLower@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToLower(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToLowerANSI@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToLowerANSI(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToString@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToString(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToUpper@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToUpper(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ToUpperANSI@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ToUpperANSI(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerActivated@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerActivated(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerActivation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerActivation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerAmmo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerAmmo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerArea@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerArea(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerAttachedVehicle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerAttachedVehicle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerAttachObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerAttachObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerAttachVehicle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerAttachVehicle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerDynamicSimulation@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerDynamicSimulation(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerInterval@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerInterval(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerStatements@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerStatements(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerTimeout@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerTimeout(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerTimeoutCurrent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerTimeoutCurrent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TriggerType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TriggerType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Trim@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Trim(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?True@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue True();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Try@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Try(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TurretLocal@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TurretLocal(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TurretOwner@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TurretOwner(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TurretUnit@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TurretUnit(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvClear@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvClear(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvCollapse@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvCollapse(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvCollapseAll@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvCollapseAll(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvCount@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvCount(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvCurSel@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvCurSel(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvDelete@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvDelete(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvExpand@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvExpand(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvExpandAll@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvExpandAll(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvIsSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvIsSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvPictureRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvPictureRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSelection@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSelection(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetCurSel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetCurSel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetData@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetData(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPicture@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPicture(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureColorDisabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureColorDisabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureColorSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureColorSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureRight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureRight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureRightColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureRightColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureRightColorDisabled@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureRightColorDisabled(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetPictureRightColorSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetPictureRightColorSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetSelectColor@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetSelectColor(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetSelected@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetSelected(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetTooltip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetTooltip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSetValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSetValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSort@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSort(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSortAll@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSortAll(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSortByValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSortByValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvSortByValueAll@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvSortByValueAll(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvText@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvText(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvTooltip@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvTooltip(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TvValue@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TvValue(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Type@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Type(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TypeName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TypeName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?TypeOf@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue TypeOf(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UAVControl@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UAVControl(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UiNamespace@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UiNamespace();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UiSleep@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UiSleep(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnassignCurator@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnassignCurator(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnassignItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnassignItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnassignTeam@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnassignTeam(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnassignVehicle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnassignVehicle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Underwater@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Underwater(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Uniform@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Uniform(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UniformContainer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UniformContainer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UniformItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UniformItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UniformMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UniformMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UniqueUnitItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UniqueUnitItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitAddons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitAddons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitAimPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitAimPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitAimPositionVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitAimPositionVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitBackpack@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitBackpack(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitCombatMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitCombatMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitIsUAV@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitIsUAV(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitPos@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitPos(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitReady@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitReady(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitRecoilCoefficient@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitRecoilCoefficient(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Units@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Units(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitsBelowHeight@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitsBelowHeight(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnitTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnitTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnlinkItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnlinkItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnlockAchievement@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnlockAchievement(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UnregisterTask@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UnregisterTask(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UpdateDrawIcon@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UpdateDrawIcon(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UpdateMenuItem@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UpdateMenuItem(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UpdateObjectTree@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UpdateObjectTree(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UseAIOperMapObstructionTest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UseAIOperMapObstructionTest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UseAISteeringComponent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UseAISteeringComponent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UseAudioTimeForMoves@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UseAudioTimeForMoves(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?UserInputDisabled@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue UserInputDisabled();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Values@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Values(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorAdd@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorAdd(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorCos@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorCos(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorCrossProduct@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorCrossProduct(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorDiff@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorDiff(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorDir@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorDir(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorDirVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorDirVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorDistance@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorDistance(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorDistanceSqr@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorDistanceSqr(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorDotProduct@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorDotProduct(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorFromTo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorFromTo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorLinearConversion@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorLinearConversion(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorMagnitude@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorMagnitude(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorMagnitudeSqr@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorMagnitudeSqr(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorModelToWorld@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorModelToWorld(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorModelToWorldVisual@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorModelToWorldVisual(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorMultiply@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorMultiply(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorNormalized@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorNormalized(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorUp@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorUp(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorUpVisual@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorUpVisual(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorWorldToModel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorWorldToModel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VectorWorldToModelVisual@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VectorWorldToModelVisual(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Vehicle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Vehicle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleCargoEnabled@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleCargoEnabled(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleChat@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleChat(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleMoveInfo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleMoveInfo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleRadio@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleRadio(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleReceiveRemoteTargets@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleReceiveRemoteTargets(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleReportOwnPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleReportOwnPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleReportRemoteTargets@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleReportRemoteTargets(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Vehicles@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Vehicles();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VehicleVarName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VehicleVarName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Velocity@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Velocity(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VelocityModelSpace@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VelocityModelSpace(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VerifySignature@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VerifySignature(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Vest@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Vest(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VestContainer@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VestContainer(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VestItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VestItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VestMagazines@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VestMagazines(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?ViewDistance@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue ViewDistance();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisibleCompass@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisibleCompass();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisibleGPS@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisibleGPS();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisibleMap@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisibleMap();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisiblePosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisiblePosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisiblePositionASL@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisiblePositionASL(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisibleScoretable@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisibleScoretable();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?VisibleWatch@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue VisibleWatch();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaitUntil@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaitUntil(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Waves@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Waves();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointAttachedObject@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointAttachedObject(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointAttachedVehicle@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointAttachedVehicle(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointAttachObject@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointAttachObject(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointAttachVehicle@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointAttachVehicle(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointBehaviour@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointBehaviour(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointCombatMode@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointCombatMode(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointCompletionRadius@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointCompletionRadius(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointDescription@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointDescription(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointForceBehaviour@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointForceBehaviour(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointFormation@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointFormation(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointHousePosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointHousePosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointLoiterAltitude@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointLoiterAltitude(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointLoiterRadius@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointLoiterRadius(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointLoiterType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointLoiterType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointName@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointName(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointPosition@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointPosition(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Waypoints@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Waypoints(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointScript@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointScript(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointsEnabledUAV@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointsEnabledUAV(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointShow@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointShow(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointSpeed@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointSpeed(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointStatements@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointStatements(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointTimeout@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointTimeout(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointTimeoutCurrent@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointTimeoutCurrent(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointType@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointType(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WaypointVisible@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WaypointVisible(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponAccessories@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponAccessories(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponAccessoriesCargo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponAccessoriesCargo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponDirection@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponDirection(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponInertia@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponInertia(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponLowered@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponLowered(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponReloadingTime@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponReloadingTime(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Weapons@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Weapons(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponsInfo@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponsInfo(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponsItems@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponsItems(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponsItemsCargo@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponsItemsCargo(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponState@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponState(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeaponsTurret@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeaponsTurret(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WeightRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WeightRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?West@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue West();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WFSideText@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WFSideText(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?While@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue While(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?Wind@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue Wind();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WindDir@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WindDir();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WindRTD@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WindRTD();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WindStr@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WindStr();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WingsForcesRTD@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WingsForcesRTD(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?With@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue With(GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WorldName@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WorldName();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WorldSize@@YA?AVgame_value@types@intercept@@XZ")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WorldSize();

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WorldToModel@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WorldToModel(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WorldToModelVisual@@YA?AVgame_value@types@intercept@@V123@0@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WorldToModelVisual(GameValue leftGameValue, GameValue rightGameValue);

        [SuppressUnmanagedCodeSecurity, LibraryImport("rvcss_x64", EntryPoint = "?WorldToScreen@@YA?AVgame_value@types@intercept@@V123@@Z")]
        [UnmanagedCallConv(CallConvs = new[] { typeof(CallConvCdecl) })]
        public static partial GameValue WorldToScreen(GameValue rightGameValue);


        #endregion commands

    }
}