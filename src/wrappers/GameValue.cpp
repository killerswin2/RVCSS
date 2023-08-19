#include <intercept.hpp>
#include "client/pointers.hpp"

#include <vector>
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#define char_t wchar_t

#else
#define char_t char
#endif

#define ALIGN4(s)         (((((s)-1) >> 2) << 2) + 4)
#define ALIGN8(s)         (((((s)-1) >> 3) << 3) + 8)

#pragma push_macro("CreateDialog")
#undef CreateDialog

using host = intercept::client::host;
using __sqf = intercept::client::__sqf;

#pragma region Testing


__declspec(dllexport) void TestGameData(game_data* data)
{
	if (data == nullptr)
	{
		return;
	}
	std::cout << "data points to: " << std::hex << data << std::endl;
}

#pragma endregion Testing

#pragma region Creation
__declspec(dllexport) auto_array<game_value> CreateAutoArray()
{
	return auto_array<game_value>();
}

__declspec(dllexport) void DeleteAutoArray(auto_array<game_value> instance)
{
	instance.~auto_array();
}


__declspec(dllexport) game_value CreateGameValue()
{
	game_value temp = game_value();
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(float value)
{
	game_value temp = game_value(value);
	temp.data->_refcount = 256;
	void* table = temp.data.get();
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(bool value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(const char* value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(auto_array<game_value> array)
{
	auto temp = game_value(array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(vector2 value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(vector3 value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGameValue(game_data* data)
{
	auto temp = game_value(data);
	temp.data->_refcount = 256;
	return temp;
}


__declspec(dllexport) void DeleteGameData(game_data* instance)
{
	delete instance;
}

#pragma endregion Creation

#pragma region Allocators
__declspec(dllexport) void* Allocate(size_t size)
{
	auto temp = rv_allocator<char>::allocate(size);
	return temp;
}

__declspec(dllexport) void Deallocate(void* pointer)
{
	if (pointer == nullptr)
	{
		return;
	}
	rv_allocator<char>::deallocate(reinterpret_cast<char*>(pointer));
}
#pragma endregion Allocators

#pragma region GameFunctions
//__declspec(dllexport) game_value NearRoads(game_value pos, game_value radius)
//{
//	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearroads__object_array__scalar__ret__array, pos, radius);
//	temp.data->_refcount = 256;
//	return temp;
//}
//
//__declspec(dllexport) game_value NearestTerrainObjects(game_value right_arg)
//{
//	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestterrainobjects__array__ret__array, right_arg);
//	temp.data->_refcount = 256;
//	return temp;
//}
//
//// for testing...
//__declspec(dllexport) game_value Player()
//{
//	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__player__ret__object);
//	temp.data->_refcount = 256;
//	return temp;
//}
//
//__declspec(dllexport) game_value Str(game_value data)
//{
//	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__str__any__ret__string, data);
//	temp.data->_refcount = 256;
//	return temp;
//}

__declspec(dllexport) game_value Abs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__abs__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AccTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__acctime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Acos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__acos__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Action(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__action__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionIDs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionids__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionKeys(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeys__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionKeysEx(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysex__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionKeysImages(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysimages__string_array__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionKeysNames(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysnames__string_array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionKeysNamesArray(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysnamesarray__string_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionname__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActionParams(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__actionparams__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActivateAddons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__activateaddons__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActivatedAddons()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__activatedaddons__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActivateKey(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__activatekey__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ActiveTitleEffectParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__activetitleeffectparams__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Add3DENConnection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__add3denconnection__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Add3DENEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__add3deneventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Add3DENLayer(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__add3denlayer__scalar__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addaction__object__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddBackpack(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addbackpack__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddBackpackCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddBackpackCargoGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargoglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddBackpackGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addbackpackglobal__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddBinocularItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addbinocularitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddCamShake(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addcamshake__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddCuratorAddons(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addcuratoraddons__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddCuratorCameraArea(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addcuratorcameraarea__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddCuratorEditableObjects(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditableobjects__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddCuratorEditingArea(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditingarea__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddCuratorPoints(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addcuratorpoints__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddEditorObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addeditorobject__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addeventhandler__group__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddForce(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addforce__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddForceGeneratorRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addforcegeneratorrtd__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddGoggles(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addgoggles__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddGroupIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addgroupicon__group__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddHandgunItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addhandgunitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddHeadgear(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addheadgear__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__additem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItemCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__additemcargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItemCargoGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__additemcargoglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItemPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__additempool__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItemToBackpack(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__additemtobackpack__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItemToUniform(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__additemtouniform__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddItemToVest(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__additemtovest__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddLiveStats(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addlivestats__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazine__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazineAmmoCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazineammocargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazineCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazineCargoGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargoglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazineGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazineglobal__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazinePool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addmagazinepool__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazines(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazines__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMagazineTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmagazineturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMenu(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmenu__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMenuItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmenuitem__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMissionEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addmissioneventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMPEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmpeventhandler__object__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddMusicEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addmusiceventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddonFiles(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addonfiles__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddOwnedMine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addownedmine__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddPlayerScores(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addplayerscores__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddPrimaryWeaponItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addprimaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddPublicVariableEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addpublicvariableeventhandler__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddRating(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addrating__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddResources(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addresources__team_member__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddScore(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addscore__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddScoreSide(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addscoreside__side__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddSecondaryWeaponItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addsecondaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddSwitchableUnit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addswitchableunit__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddTeamMember(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addteammember__team_member__team_member__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddToRemainsCollector(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addtoremainscollector__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddTorque(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addtorque__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddUniform(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__adduniform__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddUserActionEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__adduseractioneventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddVehicle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addvehicle__group__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddVest(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addvest__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWaypoint(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addwaypoint__group__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeapon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweapon__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponcargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponCargoGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponcargoglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponglobal__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponitem__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addweaponpool__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponWithAttachmentsCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AddWeaponWithAttachmentsCargoGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargoglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Admin(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__admin__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Agent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__agent__team_member__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Agents()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__agents__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AGLToASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__agltoasl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AimedAtTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__aimedattarget__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AimPos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__aimpos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AirDensityCurveRTD()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__airdensitycurvertd__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AirDensityRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__airdensityrtd__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AirplaneThrottle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__airplanethrottle__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AirportSide(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__airportside__object_scalar__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AISFinishHeal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__aisfinishheal__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Alive(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__alive__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value All3DENEntities()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__all3denentities__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllActiveTitleEffects()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allactivetitleeffects__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllAddonsInfo()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alladdonsinfo__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllAirports()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allairports__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllControls(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allcontrols__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllCurators()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allcurators__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllCutLayers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allcutlayers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllDead()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alldead__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllDeadMen()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alldeadmen__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllDiaryRecords(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__alldiaryrecords__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllDiarySubjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__alldiarysubjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllDisplays()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alldisplays__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllEnv3DSoundSources()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allenv3dsoundsources__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllGroups()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allgroups__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllLODs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__alllods__object_string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllMapMarkers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allmapmarkers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllMines()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allmines__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllMissionObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allmissionobjects__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllObjects(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allobjects__string__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Allow3DMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allow3dmode__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowCrewInImmobile(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowcrewinimmobile__object__bool_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowCuratorLogicIgnoreAreas(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowcuratorlogicignoreareas__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowDamage(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowdamage__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowDammage(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowdammage__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowedService(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allowedservice__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowFileOperations(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowfileoperations__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowFleeing(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowfleeing__object_group__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowGetIn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowgetin__array__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowService(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowservice__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllowSprint(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allowsprint__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllPlayers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allplayers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllSimpleObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allsimpleobjects__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllSites()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allsites__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllTurrets(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allturrets__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllUnits()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allunits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllUnitsUAV()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allunitsuav__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllUsers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allusers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AllVariables(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AmbientTemperature()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ambienttemperature__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Ammo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ammo__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AmmoOnPylon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ammoonpylon__object__string_scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value And(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__and__bool__code__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Animate(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animate__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimateBay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animatebay__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimateDoor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animatedoor__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimatePylon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animatepylon__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimateSource(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animatesource__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimationNames(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__animationnames__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimationPhase(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animationphase__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimationSourcePhase(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animationsourcephase__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AnimationState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__animationstate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ApertureParams()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__apertureparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Append(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__append__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Apply(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__apply__hashmap__code__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ArmoryPoints()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__armorypoints__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ArrayIntersect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__arrayintersect__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Asin(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__asin__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ASLToAGL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__asltoagl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ASLToATL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__asltoatl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Assert(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assert__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignAsCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignascargo__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignAsCargoIndex(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignascargoindex__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignAsCommander(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignascommander__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignAsDriver(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignasdriver__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignAsGunner(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignasgunner__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignAsTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignasturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignCurator(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assigncurator__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedCommander(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedcommander__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedDriver(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assigneddriver__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedGroup(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedgroup__object__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedGunner(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedgunner__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assigneditems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedTarget(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedtarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedTeam(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedteam__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedVehicle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedvehicle__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedVehicleRole(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedvehiclerole__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignedVehicles(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedvehicles__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignTeam(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assignteam__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AssignToAirport(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__assigntoairport__object__object_scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Atan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__atan__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Atan2(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__atan2__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Atg(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__atg__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ATLToASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__atltoasl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AttachedObject(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attachedobject__location__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AttachedObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attachedobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AttachedTo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attachedto__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AttachObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__attachobject__location__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AttachTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__attachto__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value AttackEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attackenabled__object_group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Awake(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__awake__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Backpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpack__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BackpackCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BackpackContainer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackcontainer__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BackpackItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BackpackMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Backpacks(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpacks__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BackpackSpaceFor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__backpackspacefor__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Behaviour(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__behaviour__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Benchmark()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__benchmark__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BezierInterpolation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__bezierinterpolation__scalar__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Binocular(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__binocular__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BinocularItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__binocularitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BinocularMagazine(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__binocularmagazine__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Blufor()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__blufor__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BoundingBox(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__boundingbox__scalar__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BoundingBoxReal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__boundingboxreal__scalar__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BoundingCenter(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__boundingcenter__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BrakesDisabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__brakesdisabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Break()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__break__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BreakOut(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__breakout__any__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BreakTo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__breakto__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BreakWith(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__breakwith__any__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BriefingName()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__briefingname__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BuildingExit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__buildingexit__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value BuildingPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__buildingpos__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Buldozer_enableroaddiag(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__buldozer_enableroaddiag__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Buldozer_isenabledroaddiag()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__buldozer_isenabledroaddiag__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Buldozer_loadnewroads(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__buldozer_loadnewroads__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Buldozer_reloadopermap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__buldozer_reloadopermap__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ButtonAction(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__buttonaction__scalar__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ButtonSetAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__buttonsetaction__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CadetMode()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cadetmode__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CalculatePath(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__calculatepath__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CalculatePlayerVisibilityByFriendly(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__calculateplayervisibilitybyfriendly__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Call(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__call__any__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CallExtension(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__callextension__string__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamCommand(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camcommand__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamCommit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camcommit__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamCommitPrepared(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camcommitprepared__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamCommitted(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camcommitted__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamConstuctionSetParams(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camconstuctionsetparams__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamCreate(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camcreate__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamDestroy(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camdestroy__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CameraEffect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cameraeffect__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CameraEffectEnableHUD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cameraeffectenablehud__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CameraInterest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camerainterest__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CameraOn()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cameraon__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CameraView()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cameraview__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CampaignConfigFile()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__campaignconfigfile__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPreload(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreload__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPreloaded(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__campreloaded__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareBank(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparebank__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparedir__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareDive(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparedive__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareFocus(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparefocus__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareFov(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparefov__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareFovRange(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparefovrange__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPreparePos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparepos__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareRelPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparerelpos__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamPrepareTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__campreparetarget__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetBank(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetbank__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetdir__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetDive(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetdive__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetFocus(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetfocus__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetFov(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetfov__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetFovRange(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetfovrange__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetpos__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetRelPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsetrelpos__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamSetTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camsettarget__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamTarget(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camtarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CamUseNVG(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camusenvg__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadd__string__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanAddItemToBackpack(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadditemtobackpack__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanAddItemToUniform(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadditemtouniform__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanAddItemToVest(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadditemtovest__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CancelSimpleTaskDestination(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cancelsimpletaskdestination__task__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanDeployWeapon(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__candeployweapon__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanFire(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canfire__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanMove(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canmove__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanSlingLoad(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canslingload__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanStand(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canstand__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanSuspend()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cansuspend__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanTriggerDynamicSimulation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cantriggerdynamicsimulation__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanUnloadInCombat(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canunloadincombat__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CanVehicleCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canvehiclecargo__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Captive(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__captive__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CaptiveNum(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__captivenum__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Case(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__case__any__ret__switch, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Catch(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__catch__exception__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CbChecked(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cbchecked__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CbSetChecked(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cbsetchecked__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Ceil(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ceil__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ChannelEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__channelenabled__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CheatsEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cheatsenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CheckAIFeature(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__checkaifeature__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CheckVisibility(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__checkvisibility__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Civilian()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__civilian__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClassName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__classname__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Clear3DENAttribute(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__clear3denattribute__any__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Clear3DENInventory(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clear3deninventory__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearAllItemsFromBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearallitemsfrombackpack__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearBackpackCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargo__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearBackpackCargoGlobal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargoglobal__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearForcesRTD()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clearforcesrtd__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearGroupIcons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cleargroupicons__group__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearItemCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearitemcargo__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearItemCargoGlobal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearitemcargoglobal__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearItemPool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clearitempool__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearMagazineCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargo__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearMagazineCargoGlobal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargoglobal__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearMagazinePool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clearmagazinepool__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearOverlay(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearoverlay__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearRadio()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clearradio__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearWeaponCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargo__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearWeaponCargoGlobal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargoglobal__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClearWeaponPool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clearweaponpool__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ClientOwner()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clientowner__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CloseDialog(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__closedialog__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CloseDisplay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__closedisplay__display__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CloseOverlay(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__closeoverlay__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CollapseObjectTree(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__collapseobjecttree__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Collect3DENHistory(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__collect3denhistory__array__code__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CollectiveRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__collectivertd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CollisionDisabledWith(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__collisiondisabledwith__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CombatBehaviour(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__combatbehaviour__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CombatMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__combatmode__object_group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandArtilleryFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandChat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandchat__object_array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Commander(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__commander__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandfire__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandFollow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandfollow__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandFSM(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandfsm__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandGetOut(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__commandgetout__object_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandingMenu()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__commandingmenu__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandMove(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandmove__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandradio__object_array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandStop(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__commandstop__object_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandSuppressiveFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandsuppressivefire__object_array__object_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandtarget__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommandWatch(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__commandwatch__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Comment(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__comment__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CommitOverlay(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__commitoverlay__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CompatibleItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compatibleitems__string_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CompatibleMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compatiblemagazines__string_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Compile(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compile__string__ret__code, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CompileFinal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compilefinal__string__ret__code, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CompileScript(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compilescript__array__ret__code, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CompletedFSM(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__completedfsm__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ComposeText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__composetext__array__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Configaccessor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__configaccessor__config__string__ret__config, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigClasses(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__configclasses__string__config__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigFile()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__configfile__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigHierarchy(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__confighierarchy__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configname__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__confignull__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigOf(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configof__object__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigProperties(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configproperties__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigSourceAddonList(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configsourceaddonlist__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigSourceMod(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configsourcemod__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfigSourceModList(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configsourcemodlist__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConfirmSensorTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__confirmsensortarget__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConnectTerminalToUAV(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__connectterminaltouav__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConnectToServer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__connecttoserver__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Continue()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__continue__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ContinueWith(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__continuewith__any__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ControlNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__controlnull__ret__control);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ControlsGroupCtrl(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__controlsgroupctrl__control__scalar__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ConversationDisabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__conversationdisabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CopyFromClipboard()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__copyfromclipboard__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CopyToClipboard(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__copytoclipboard__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CopyWaypoints(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__copywaypoints__group__group__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Cos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cos__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Count(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__count__code__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CountEnemy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countenemy__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CountFriendly(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countfriendly__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CountSide(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countside__side__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CountType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__counttype__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CountUnknown(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countunknown__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Create3DENComposition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__create3dencomposition__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Create3DENEntity(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__create3denentity__group__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateAgent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createagent__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateCenter(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createcenter__side__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateDialog(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createdialog__array__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateDiaryLink(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__creatediarylink__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateDiaryRecord(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__creatediaryrecord__object__array__ret__diary_record, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateDiarySubject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__creatediarysubject__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateDisplay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createdisplay__display__string__ret__display, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGearDialog(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__creategeardialog__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGroup(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__creategroup__side_array__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateGuardedPoint(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createguardedpoint__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateHashMap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__createhashmap__ret__hashmap);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateHashMapFromArray(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createhashmapfromarray__array__array__ret__hashmap, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateLocation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createlocation__array__ret__location, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateMarker(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createmarker__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateMarkerLocal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createmarkerlocal__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateMenu(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createmenu__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateMine(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createmine__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateMissionDisplay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createmissiondisplay__display__array__ret__display, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateMPCampaignDisplay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__creatempcampaigndisplay__display__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateSimpleObject(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createsimpleobject__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateSimpleTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createsimpletask__object__array__ret__task, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateSite(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createsite__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateSoundSource(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createsoundsource__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createtask__team_member__array__ret__task, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateTeam(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createteam__array__ret__team_member, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateTrigger(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createtrigger__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateUnit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createunit__group__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateVehicle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createvehicle__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateVehicleCrew(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createvehiclecrew__object__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CreateVehicleLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createvehiclelocal__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Crew(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__crew__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtAddHeader(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctaddheader__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtAddRow(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctaddrow__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtClear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctclear__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtCurSel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctcursel__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctdata__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtFindHeaderRows(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctfindheaderrows__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtFindRowHeader(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctfindrowheader__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtHeaderControls(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctheadercontrols__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtHeaderCount(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctheadercount__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtRemoveHeaders(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctremoveheaders__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtRemoveRows(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctremoverows__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlActivate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlactivate__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAddEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrladdeventhandler__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAngle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlangle__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAnimateModel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlanimatemodel__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAnimationPhaseModel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlanimationphasemodel__control__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAt(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlat__display__array__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAutoScrollDelay(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrolldelay__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAutoScrollRewind(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollrewind__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlAutoScrollSpeed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollspeed__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlBackgroundColor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlbackgroundcolor__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlChecked(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlchecked__control__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlClassName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlclassname__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlCommit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlcommit__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlCommitted(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlcommitted__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlCreate(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlcreate__display__array__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlDelete(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrldelete__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlEnable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlenable__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlenabled__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlFade(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlfade__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlFontHeight(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlfontheight__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlForegroundColor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlforegroundcolor__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlHTMLLoaded(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlhtmlloaded__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlIDC(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlidc__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlIDD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlidd__display__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapAnimAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapanimadd__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapAnimClear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimclear__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapAnimCommit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimcommit__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapAnimDone(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimdone__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapCursor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapcursor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapDir(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapdir__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapMouseOver(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapmouseover__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapScale(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapscale__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapScreenToWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapscreentoworld__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapSetPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapsetposition__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMapWorldToScreen(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapworldtoscreen__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlModel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmodel__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlModelDirAndUp(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmodeldirandup__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlModelScale(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmodelscale__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlMousePosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmouseposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlParent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlparent__control__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlParentControlsGroup(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlparentcontrolsgroup__control__ret__control, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlRemoveAllEventHandlers(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlremovealleventhandlers__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlRemoveEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlremoveeventhandler__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlScale(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlscale__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlScrollValues(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlscrollvalues__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetActiveColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetactivecolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetAngle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetangle__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetAutoScrollDelay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrolldelay__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetAutoScrollRewind(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollrewind__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetAutoScrollSpeed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollspeed__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetBackgroundColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetbackgroundcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetChecked(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetchecked__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetDisabledColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetdisabledcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlseteventhandler__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFade(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfade__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFocus(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlsetfocus__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFont(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfont__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH1(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH1B(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1b__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH2(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH2B(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2b__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH3(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH3B(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3b__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH4(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH4B(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4b__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH5(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH5B(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5b__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH6(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontH6B(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6b__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheight__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightH1(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth1__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightH2(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth2__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightH3(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth3__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightH4(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth4__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightH5(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth5__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightH6(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth6__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontHeightSecondary(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheightsecondary__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontP(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontp__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontPB(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontpb__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetFontSecondary(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontsecondary__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetForegroundColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetforegroundcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetModel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodel__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetModelDirAndUp(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodeldirandup__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetModelScale(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodelscale__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetMousePosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmouseposition__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetPixelPrecision(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpixelprecision__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetposition__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetPositionH(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionh__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetPositionW(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionw__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetPositionX(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionx__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetPositionY(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositiony__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetScale(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscale__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetScrollValues(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscrollvalues__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetShadow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetshadow__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetStructuredText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsetstructuredtext__control__text__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettext__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTextColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTextColorSecondary(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolorsecondary__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTextSecondary(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextsecondary__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTextSelection(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextselection__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTooltip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltip__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTooltipColorBox(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorbox__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTooltipColorShade(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorshade__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTooltipColorText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolortext__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetTooltipMaxWidth(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipmaxwidth__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetURL(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlseturl__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlSetURLOverlayMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlseturloverlaymode__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlShadow(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlshadow__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlShow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlshow__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlShown(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlshown__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlStyle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlstyle__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltext__scalar__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlTextColor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextcolor__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlTextHeight(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextheight__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlTextSecondary(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextsecondary__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlTextSelection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextselection__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlTextWidth(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextwidth__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlTooltip(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltooltip__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltype__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlURL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlurl__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlURLOverlayMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlurloverlaymode__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtrlVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlvisible__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtRowControls(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrowcontrols__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtRowCount(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrowcount__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtSetCurSel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctsetcursel__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtSetData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctsetdata__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtSetHeaderTemplate(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctsetheadertemplate__control__config__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtSetRowTemplate(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctsetrowtemplate__control__config__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtSetValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctsetvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CtValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctvalue__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorAddons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoraddons__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorCamera()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__curatorcamera__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorCameraArea(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorcameraarea__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorCameraAreaCeiling(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorcameraareaceiling__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorCoef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__curatorcoef__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorEditableObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoreditableobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorEditingArea(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoreditingarea__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorEditingAreaType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoreditingareatype__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorMouseOver()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__curatormouseover__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorPoints(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorpoints__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorRegisteredObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorregisteredobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorSelected()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__curatorselected__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CuratorWaypointCost(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorwaypointcost__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Current3DENOperation()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__current3denoperation__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentChannel()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__currentchannel__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentCommand(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentcommand__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentMagazine(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentmagazine__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentMagazineDetail(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentmagazinedetail__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentMagazineDetailTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentmagazinedetailturret__object__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentMagazineTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentmagazineturret__object__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentMuzzle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentmuzzle__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__currentnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentPilot(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentpilot__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentTask(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currenttask__object__ret__task, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentTasks(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currenttasks__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentThrowable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentthrowable__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentVisionMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentvisionmode__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentWaypoint(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentwaypoint__group__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentWeapon(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentWeaponMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentweaponmode__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentWeaponTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentweaponturret__object__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CurrentZeroing(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentzeroing__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CursorObject()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cursorobject__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CursorTarget()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cursortarget__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CustomChat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__customchat__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CustomRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__customradio__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CustomWaypointPosition()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__customwaypointposition__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CutFadeOut(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cutfadeout__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CutObj(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cutobj__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CutRsc(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cutrsc__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value CutText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cuttext__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Damage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__damage__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Date()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__date__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DateToNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__datetonumber__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DayTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__daytime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeActivateKey(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deactivatekey__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DebriefingText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__debriefingtext__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DebugFSM(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__debugfsm__scalar__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DebugLog(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__debuglog__any__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DecayGraphValues(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__decaygraphvalues__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Default(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__default__code__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Deg(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deg__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Delete3DENEntities(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__delete3denentities__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteAt(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleteat__hashmap__side_config__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteCenter(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletecenter__side__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteCollection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletecollection__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteEditorObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleteeditorobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteGroup(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletegroup__group__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteGroupWhenEmpty(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deletegroupwhenempty__group__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteIdentity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deleteidentity__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteLocation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletelocation__location__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteMarker(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletemarker__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteMarkerLocal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletemarkerlocal__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteRange(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleterange__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteResources(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleteresources__team_member__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteSite(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletesite__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteStatus(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletestatus__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteTeam(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deleteteam__team_member__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteVehicle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletevehicle__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteVehicleCrew(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deletevehiclecrew__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DeleteWaypoint(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletewaypoint__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Detach(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__detach__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DetectedMines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__detectedmines__side__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_activemissionfsms()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activemissionfsms__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_activescripts()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activescripts__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_activesqfscripts()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activesqfscripts__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_activesqsscripts()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activesqsscripts__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_allmissioneventhandlers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_allmissioneventhandlers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_captureframe(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_captureframe__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_captureframetofile(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_captureframetofile__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_captureslowframe(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_captureslowframe__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_codeperformance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_codeperformance__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_deltatime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_deltatime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_drawmode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_drawmode__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_dumpcalltracetolog()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_dumpcalltracetolog__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_dumpscriptassembly(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_dumpscriptassembly__code__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_dumpterrainsynth()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_dumpterrainsynth__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_dynamicsimulationend(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_dynamicsimulationend__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_enable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__diag_enable__string__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_enabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_enabled__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_exportconfig(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_exportconfig__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_exportterrainsvg(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_exportterrainsvg__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_fps()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_fps__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_fpsmin()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_fpsmin__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_frameno()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_frameno__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_getterrainsegmentoffset(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_getterrainsegmentoffset__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_lightnewload(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_lightnewload__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_list(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_list__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_localized(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_localized__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_log(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_log__any__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_logslowframe(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_logslowframe__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_mergeconfigfile(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_mergeconfigfile__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_recordturretlimits(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_recordturretlimits__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_resetfsm()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_resetfsm__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_resetshapes()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_resetshapes__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_scope()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_scope__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_setlightnew(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_setlightnew__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_stacktrace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_stacktrace__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_ticktime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_ticktime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Diag_toggle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_toggle__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Dialog()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__dialog__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DiaryRecordNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diaryrecordnull__ret__task);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DiarySubjectExists(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__diarysubjectexists__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DidJIP()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__didjip__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DidJIPOwner(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__didjipowner__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Difficulty()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__difficulty__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DifficultyEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__difficultyenabled__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DifficultyEnabledRTD()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__difficultyenabledrtd__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DifficultyOption(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__difficultyoption__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Direction(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__direction__location__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DirectionStabilizationEnabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__directionstabilizationenabled__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DirectSay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__directsay__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableAI(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disableai__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableBrakes(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disablebrakes__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableCollisionWith(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disablecollisionwith__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableConversation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disableconversation__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableDebriefingStats()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__disabledebriefingstats__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableMapIndicators(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__disablemapindicators__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableNVGEquipment(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disablenvgequipment__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableRemoteSensors(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__disableremotesensors__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableSerialization()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__disableserialization__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableTIEquipment(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disabletiequipment__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableUAVConnectability(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__disableuavconnectability__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisableUserInput(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__disableuserinput__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayAddEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayaddeventhandler__display__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayChild(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displaychild__display__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayCtrl(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayctrl__display__scalar__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__displaynull__ret__display);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayParent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displayparent__display__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayRemoveAllEventHandlers(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayremovealleventhandlers__display__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayRemoveEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayremoveeventhandler__display__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplaySetEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayseteventhandler__display__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayUniqueName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displayuniquename__display__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DisplayUpdate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displayupdate__display__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DissolveTeam(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dissolveteam__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Distance(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance__array__location__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Distance2D(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance2d__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DistanceSqr(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distancesqr__array__location__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DistributionRegion()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__distributionregion__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Do(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__do__switch__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Do3DENAction(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__do3denaction__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoArtilleryFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__doartilleryfire__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__dofire__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoFollow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__dofollow__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoFSM(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__dofsm__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoGetOut(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dogetout__object_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoMove(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__domove__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoorPhase(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__doorphase__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoStop(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dostop__object_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoSuppressiveFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__dosuppressivefire__object_array__object_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__dotarget__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DoWatch(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__dowatch__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawArrow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawarrow__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawEllipse(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawellipse__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawicon__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawIcon3D(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__drawicon3d__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawLaser(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__drawlaser__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawLine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawline__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawLine3D(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__drawline3d__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawLink(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawlink__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawLocation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawlocation__control__location__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawPolygon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawpolygon__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawRectangle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawrectangle__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DrawTriangle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__drawtriangle__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Driver(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__driver__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Drop(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__drop__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DynamicSimulationDistance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistance__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DynamicSimulationDistanceCoef(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistancecoef__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DynamicSimulationEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationenabled__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value DynamicSimulationSystemEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__dynamicsimulationsystemenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value East()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__east__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Echo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__echo__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Edit3DENMissionAttributes(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__edit3denmissionattributes__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EditObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__editobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EditorSetEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__editorseteventhandler__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EffectiveCommander(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__effectivecommander__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ElevatePeriscope(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__elevateperiscope__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Else(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__else__code__code__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EmptyPositions(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__emptypositions__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAI(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableai__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAIFeature(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableaifeature__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAimPrecision(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableaimprecision__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAttack(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableattack__object_group__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAudioFeature(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableaudiofeature__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAutoStartUpRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableautostartuprtd__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableAutoTrimRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableautotrimrtd__object__bool__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableCamShake(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablecamshake__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableCaustics(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablecaustics__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableChannel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablechannel__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableCollisionWith(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablecollisionwith__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableCopilot(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablecopilot__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableDebriefingStats(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enabledebriefingstats__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableDiagLegend(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablediaglegend__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableDirectionStabilization(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enabledirectionstabilization__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableDynamicSimulation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enabledynamicsimulation__group__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableDynamicSimulationSystem(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enabledynamicsimulationsystem__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableEndDialog()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__enableenddialog__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableEngineArtillery(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enableengineartillery__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableEnvironment(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enableenvironment__bool_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableFatigue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablefatigue__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableGunLights(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablegunlights__object_group__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableInfoPanelComponent(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableinfopanelcomponent__object_array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableIRLasers(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableirlasers__object_group__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableMimics(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablemimics__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnablePersonTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablepersonturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableRadio(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enableradio__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableReload(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablereload__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableRopeAttach(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableropeattach__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableSatNormalOnDetail(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablesatnormalondetail__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableSaving(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablesaving__bool_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableSentences(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablesentences__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableSimulation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablesimulation__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableSimulationGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablesimulationglobal__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableStamina(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablestamina__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableStressDamage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enablestressdamage__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableTeamSwitch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enableteamswitch__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableTraffic(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enabletraffic__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableUAVConnectability(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableuavconnectability__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableUAVWaypoints(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableuavwaypoints__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableVehicleCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablevehiclecargo__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableVehicleSensor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enablevehiclesensor__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnableWeaponDisassembly(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableweapondisassembly__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Endl()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__endl__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EndLoadingScreen()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__endloadingscreen__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EndMission(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__endmission__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EngineOn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__engineon__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnginesIsOnRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginesisonrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnginesPowerRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginespowerrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnginesRpmRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginesrpmrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnginesTorqueRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginestorquertd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Entities(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__entities__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnvironmentEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__environmentenabled__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EnvironmentVolume()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__environmentvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EquipmentDisabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__equipmentdisabled__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EstimatedEndServerTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__estimatedendservertime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EstimatedTimeLeft(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__estimatedtimeleft__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EvalObjectArgument(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__evalobjectargument__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EveryBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__everybackpack__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EveryContainer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__everycontainer__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Exec(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__exec__any__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ExecEditorScript(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__execeditorscript__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ExecFSM(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__execfsm__any__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ExecVM(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__execvm__any__string__ret__script, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Exit()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__exit__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ExitWith(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__exitwith__if__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Exp(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__exp__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ExpectedDestination(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__expecteddestination__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ExportJIPMessages(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__exportjipmessages__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EyeDirection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__eyedirection__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value EyePos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__eyepos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Face(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__face__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Faction(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__faction__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FadeEnvironment(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fadeenvironment__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FadeMusic(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fademusic__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FadeRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__faderadio__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FadeSound(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fadesound__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FadeSpeech(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fadespeech__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FailMission(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__failmission__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value False()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__false__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FileExists(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fileexists__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FillWeaponsFromPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fillweaponsfrompool__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Find(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__find__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindAny(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findany__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindCover(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findcover__object__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindDisplay(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__finddisplay__string__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindEditorObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findeditorobject__control__any__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindEmptyPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findemptyposition__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindEmptyPositionReady(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findemptypositionready__array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindIf(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findif__array__code__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FindNearestEnemy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findnearestenemy__object__object_array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FinishMissionInit()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__finishmissioninit__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Finite(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__finite__scalar_nan__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Fire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fire__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FireAtTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fireattarget__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FirstBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__firstbackpack__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Flag(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flag__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FlagAnimationPhase(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flaganimationphase__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FlagOwner(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flagowner__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FlagSide(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flagside__object__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FlagTexture(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flagtexture__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Flatten(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flatten__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Fleeing(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fleeing__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Floor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__floor__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FlyInHeight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__flyinheight__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FlyInHeightASL(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__flyinheightasl__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FocusedCtrl(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__focusedctrl__display__ret__control, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Fog()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__fog__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FogForecast()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__fogforecast__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FogParams()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__fogparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value For(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__for__array__ret__for, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceAddUniform(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forceadduniform__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceAtPositionRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forceatpositionrtd__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceCadetDifficulty(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forcecadetdifficulty__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForcedMap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__forcedmap__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceEnd()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__forceend__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceFlagTexture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forceflagtexture__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceFollowRoad(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forcefollowroad__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceGeneratorRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forcegeneratorrtd__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceMap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forcemap__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceRespawn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forcerespawn__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceSpeed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forcespeed__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceUnicode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forceunicode__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceWalk(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forcewalk__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceWeaponFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forceweaponfire__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForceWeatherChange()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__forceweatherchange__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForEach(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__foreach__code__hashmap__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForEachMember(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__foreachmember__code__team_member__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForEachMemberAgent(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__foreachmemberagent__code__team_member__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForEachMemberTeam(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__foreachmemberteam__code__team_member__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ForgetTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__forgettarget__object_group__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Format(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__format__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Formation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formation__team_member__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormationDirection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationdirection__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormationLeader(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationleader__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormationMembers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationmembers__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormationPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormationTask(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationtask__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormatText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formattext__array__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FormLeader(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formleader__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FreeExtension(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__freeextension__string__ret__bool_nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FreeLook()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__freelook__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value From(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__from__for__scalar__ret__for, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FromEditor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fromeditor__team_member__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Fuel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fuel__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value FullCrew(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fullcrew__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GearIDCAmmoCount(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gearidcammocount__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GearSlotAmmoCount(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gearslotammocount__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GearSlotData(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gearslotdata__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GestureState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gesturestate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get__hashmap__side_config__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENActionState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denactionstate__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENAttribute(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__scalar__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENCamera()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3dencamera__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENConnections(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denconnections__any__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENEntity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denentity__scalar__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENEntityID(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denentityid__any__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENGrid(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3dengrid__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENIconsVisible()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3deniconsvisible__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENLayerEntities(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denlayerentities__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENLinesVisible()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3denlinesvisible__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENMissionAttribute(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denmissionattribute__string__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENMouseOver()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3denmouseover__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Get3DENSelected(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denselected__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAimingCoef(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getaimingcoef__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllEnv3DSoundControllers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallenv3dsoundcontrollers__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllEnvSoundControllers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallenvsoundcontrollers__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllHitPointsDamage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallhitpointsdamage__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllOwnedMines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallownedmines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllPylonsInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallpylonsinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllSoundControllers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallsoundcontrollers__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAllUnitTraits(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallunittraits__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAmmoCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getammocargo__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAnimAimPrecision(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getanimaimprecision__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAnimSpeedCoef(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getanimspeedcoef__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetArray(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getarray__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetArtilleryAmmo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getartilleryammo__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetArtilleryComputerSettings()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getartillerycomputersettings__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetArtilleryETA(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getartilleryeta__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAssetDLCInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassetdlcinfo__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAssignedCuratorLogic(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorlogic__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAssignedCuratorUnit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorunit__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAttackTarget(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getattacktarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetAudioOptionVolumes()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getaudiooptionvolumes__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetBackpackCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getbackpackcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetBleedingRemaining(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getbleedingremaining__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetBurningValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getburningvalue__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCalculatePlayerVisibilityByFriendly()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getcalculateplayervisibilitybyfriendly__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCameraViewDirection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcameraviewdirection__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCargoIndex(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getcargoindex__object__object__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCenterOfMass(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcenterofmass__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetClientState()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getclientstate__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetClientStateNumber()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getclientstatenumber__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCompatiblePylonMagazines(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getcompatiblepylonmagazines__string__string_scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetConnectedUAV(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getconnecteduav__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetConnectedUAVUnit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getconnecteduavunit__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetContainerMaxLoad(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcontainermaxload__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCorpse(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcorpse__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCruiseControl(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcruisecontrol__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCursorObjectParams()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getcursorobjectparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCustomAimCoef(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcustomaimcoef__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCustomSoundController(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontroller__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetCustomSoundControllerCount(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontrollercount__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDammage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdammage__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDebriefingText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdebriefingtext__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDescription(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdescription__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getdir__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDirVisual(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getdirvisual__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDiverState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdiverstate__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDLCAssetsUsage()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getdlcassetsusage__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDLCAssetsUsageByName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdlcassetsusagebyname__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDLCs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdlcs__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetDLCUsageTime(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdlcusagetime__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEditorCamera(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__geteditorcamera__control__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEditorMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__geteditormode__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEditorObjectScope(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__geteditorobjectscope__control__string__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetElevationOffset()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getelevationoffset__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEngineTargetRPMRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getenginetargetrpmrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEnv3DSoundController(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getenv3dsoundcontroller__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEnvSoundController(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getenvsoundcontroller__array__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetEventHandlerInfo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__geteventhandlerinfo__object_group__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetFatigue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getfatigue__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetFieldManualStartPage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getfieldmanualstartpage__display__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetForcedFlagTexture(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getforcedflagtexture__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetForcedSpeed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getforcedspeed__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetFriend(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getfriend__side__side__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetFSMVariable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getfsmvariable__scalar__string_array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetFuelCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getfuelcargo__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetGraphValues(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getgraphvalues__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetGroupIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getgroupicon__group__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetGroupIconParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getgroupiconparams__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetGroupIcons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getgroupicons__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetHideFrom(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethidefrom__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetHit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethit__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetHitIndex(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethitindex__object__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetHitPointDamage(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethitpointdamage__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetItemCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getitemcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetLighting()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getlighting__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetLightingAt(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getlightingat__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetLoadedModsInfo()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getloadedmodsinfo__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMagazineCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmagazinecargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMarkerColor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkercolor__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMarkerPos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkerpos__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMarkerSize(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkersize__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMarkerType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkertype__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMass(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmass__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMissionConfig(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionconfig__string__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMissionConfigValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionconfigvalue__string_array__ret__array_string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMissionDLCs()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmissiondlcs__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMissionLayerEntities(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionlayerentities__string_scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMissionLayers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmissionlayers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMissionPath(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionpath__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetModelInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmodelinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMousePosition()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmouseposition__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetMusicPlayedTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmusicplayedtime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getnumber__config__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectArgument(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getobjectargument__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectChildren(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getobjectchildren__control__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectDLC(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectdlc__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectFOV(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectfov__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectID(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectMaterials(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectmaterials__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectProxy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getobjectproxy__control__string__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectScale(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectscale__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectTextures(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjecttextures__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjecttype__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetObjectViewDistance()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getobjectviewdistance__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetOpticsMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getopticsmode__object__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetOrDefault(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getordefault__hashmap__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetOrDefaultCall(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getordefaultcall__hashmap__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetOxygenRemaining(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getoxygenremaining__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPersonUsedDLCs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpersonuseddlcs__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPilotCameraDirection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameradirection__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPilotCameraPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameraposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPilotCameraRotation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcamerarotation__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPilotCameraTarget(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameratarget__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPiPViewDistance()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getpipviewdistance__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPlateNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplatenumber__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPlayerChannel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayerchannel__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPlayerID(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayerid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPlayerScores(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayerscores__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPlayerUID(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayeruid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPlayerVoNVolume(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayervonvolume__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getpos__object_array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposasl__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosASLVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposaslvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosASLW(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposaslw__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosATL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposatl__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosATLVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposatlvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosWorld(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposworld__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPosWorldVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposworldvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetPylonMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpylonmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetRelDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getreldir__object__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetRelPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getrelpos__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetRemoteSensorsDisabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getremotesensorsdisabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetRepairCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getrepaircargo__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetResolution()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getresolution__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetRoadInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getroadinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetRotorBrakeRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getrotorbrakertd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSensorTargets(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getsensortargets__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSensorThreats(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getsensorthreats__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetShadowDistance()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getshadowdistance__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetShotParents(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getshotparents__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSlingLoad(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getslingload__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSoundController(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getsoundcontroller__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSoundControllerResult(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getsoundcontrollerresult__object__config__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSpeed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getspeed__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetStamina(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getstamina__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetStatValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getstatvalue__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSteamFriendsServers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getsteamfriendsservers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSubtitleOptions()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getsubtitleoptions__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetSuppression(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getsuppression__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTerrainGrid()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getterraingrid__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTerrainHeight(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getterrainheight__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTerrainHeightASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getterrainheightasl__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTerrainInfo()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getterraininfo__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettext__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTextRaw(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettextraw__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTextureInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettextureinfo__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTextWidth(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gettextwidth__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTIParameters()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__gettiparameters__ret__hashmap);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTotalDLCUsageTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__gettotaldlcusagetime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTowParent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettowparent__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTrimOffsetRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettrimoffsetrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTurretLimits(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getturretlimits__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetTurretOpticsMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getturretopticsmode__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUnitFreefallInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunitfreefallinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUnitLoadout(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunitloadout__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUnitTrait(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getunittrait__object__string__ret__nothing_bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUnloadInCombat(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunloadincombat__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUserInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getuserinfo__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUserMFDText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getusermfdtext__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetUserMFDValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getusermfdvalue__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetVariable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__location__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetVehicleCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getvehiclecargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetVehicleTIPars(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getvehicletipars__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetVideoOptions()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getvideooptions__ret__hashmap);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetWeaponCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getweaponcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetWeaponSway(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getweaponsway__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetWingsOrientationRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getwingsorientationrtd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetWingsPositionRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getwingspositionrtd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GetWPPos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getwppos__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GlanceAt(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__glanceat__object_array__object_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GlobalChat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__globalchat__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GlobalRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__globalradio__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Goggles(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__goggles__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Goto(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__goto__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Group(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__group__object__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupChat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__groupchat__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupFromNetId(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupfromnetid__string__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupIconSelectable()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__groupiconselectable__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupIconsVisible()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__groupiconsvisible__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupId(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupid__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupOwner(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupowner__group__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__groupradio__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Groups(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groups__side__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupSelectedUnits(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupselectedunits__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GroupSelectUnit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__groupselectunit__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value GrpNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__grpnull__ret__group);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Gunner(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gunner__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Gusts()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__gusts__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Halt()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__halt__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HandgunItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handgunitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HandgunMagazine(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handgunmagazine__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HandgunWeapon(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handgunweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HandsHit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handshit__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HashValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hashvalue__object_side__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HasInterface()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__hasinterface__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HasPilotCamera(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__haspilotcamera__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HasWeapon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hasweapon__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcAllGroups(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcallgroups__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcGroupParams(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hcgroupparams__object__group__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcLeader(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcleader__group__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcRemoveAllGroups(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcremoveallgroups__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcRemoveGroup(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hcremovegroup__object__group__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcSelected(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcselected__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcSelectGroup(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hcselectgroup__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcSetGroup(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hcsetgroup__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcShowBar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcshowbar__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HcShownBar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__hcshownbar__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Headgear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__headgear__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HideBody(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hidebody__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HideObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hideobject__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HideObjectGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hideobjectglobal__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HideSelection(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hideselection__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Hint(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hint__text_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HintC(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hintc__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HintCadet(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hintcadet__text_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HintSilent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hintsilent__text_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Hmd(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hmd__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HostMission(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hostmission__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HtmlLoad(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__htmlload__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value HUDMovementLevels()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__hudmovementlevels__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Humidity()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__humidity__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value If(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__if__bool__ret__if, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Image(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__image__string__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ImportAllGroups(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__importallgroups__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Importance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__importance__location__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value In(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__in__array__location__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InArea(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inarea__array__location__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InAreaArray(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__location__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IncapacitatedState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__incapacitatedstate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Independent()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__independent__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Inflame(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inflame__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Inflamed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inflamed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InfoPanel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__infopanel__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InfoPanelComponentEnabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponentenabled__object_array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InfoPanelComponents(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponents__object_array__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InfoPanels(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__infopanels__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InGameUISetEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ingameuiseteventhandler__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InheritsFrom(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inheritsfrom__config__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InitAmbientLife()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__initambientlife__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InPolygon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inpolygon__array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InputAction(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputaction__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InputController(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputcontroller__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InputMouse(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputmouse__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InRangeOfArtillery(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inrangeofartillery__array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Insert(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__insert__hashmap__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InsertEditorObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inserteditorobject__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value InsideBuilding(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__insidebuilding__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Intersect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__intersect__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Is3DEN()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__is3den__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Is3DENMultiplayer()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__is3denmultiplayer__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Is3DENPreview()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__is3denpreview__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAbleToBreathe(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isabletobreathe__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsActionMenuVisible()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isactionmenuvisible__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAgent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isagent__team_member__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAimPrecisionEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isaimprecisionenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAllowedCrewInImmobile(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isallowedcrewinimmobile__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsArray(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isarray__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAutoHoverOn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautohoveron__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAutonomous(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautonomous__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAutoStartUpEnabledRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautostartupenabledrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAutotest()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isautotest__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAutoTrimOnRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautotrimonrtd__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsAwake(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isawake__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsBleeding(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isbleeding__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsBurning(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isburning__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsClass(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isclass__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsCollisionLightOn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iscollisionlighton__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsCopilotEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iscopilotenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsDamageAllowed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isdamageallowed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsDedicated()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isdedicated__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsDLCAvailable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isdlcavailable__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEngineOn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isengineon__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualRef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequalref__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequalto__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltype__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualTypeAll(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypeall__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualTypeAny(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypeany__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualTypeArray(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypearray__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsEqualTypeParams(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypeparams__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsFilePatchingEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isfilepatchingenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsFinal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isfinal__code_string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsFlashlightOn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isflashlighton__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsFlatEmpty(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isflatempty__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsForcedWalk(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isforcedwalk__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsFormationLeader(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isformationleader__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsGameFocused()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isgamefocused__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsGamePaused()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isgamepaused__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsGroupDeletedWhenEmpty(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isgroupdeletedwhenempty__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsHidden(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ishidden__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsInRemainsCollector(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isinremainscollector__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsInstructorFigureEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isinstructorfigureenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsIRLaserOn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isirlaseron__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsKeyActive(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iskeyactive__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsKindOf(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__iskindof__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsLaserOn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__islaseron__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsLightOn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__islighton__object_array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsLocalized(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__islocalized__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsManualFire(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ismanualfire__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsMarkedForCollection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ismarkedforcollection__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsMissionProfileNamespaceLoaded()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ismissionprofilenamespaceloaded__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsMultiplayer()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ismultiplayer__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsMultiplayerSolo()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ismultiplayersolo__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsNil(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnil__code_string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsNotEqualRef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isnotequalref__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsNotEqualTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isnotequalto__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsNull(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__location__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnumber__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsObjectHidden(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isobjecthidden__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsObjectRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isobjectrtd__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsOnRoad(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isonroad__object_array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsPiPEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ispipenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsPlayer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isplayer__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsRealTime(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isrealtime__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsRemoteExecuted()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isremoteexecuted__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsRemoteExecutedJIP()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isremoteexecutedjip__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsSaving()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__issaving__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsSensorTargetConfirmed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__issensortargetconfirmed__object__side__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsServer()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isserver__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsShowing3DIcons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isshowing3dicons__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsSimpleObject(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__issimpleobject__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsSprintAllowed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__issprintallowed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsStaminaEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isstaminaenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsSteamMission()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__issteammission__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsSteamOverlayEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__issteamoverlayenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsStreamFriendlyUIEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isstreamfriendlyuienabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsStressDamageEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isstressdamageenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__istext__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsTouchingGround(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__istouchingground__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsTurnedOut(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isturnedout__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsTutHintsEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__istuthintsenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsUAVConnectable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isuavconnectable__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsUAVConnected(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isuavconnected__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsUIContext()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isuicontext__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsUniformAllowed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isuniformallowed__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsVehicleCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isvehiclecargo__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsVehicleRadarOn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isvehicleradaron__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsVehicleSensorEnabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isvehiclesensorenabled__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsWalking(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iswalking__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsWeaponDeployed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isweapondeployed__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value IsWeaponRested(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isweaponrested__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ItemCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__itemcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Items(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__items__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ItemsWithMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__itemswithmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Join(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__join__array__object_group__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value JoinAs(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__joinas__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value JoinAsSilent(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__joinassilent__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value JoinSilent(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__joinsilent__array__object_group__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value JoinString(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__joinstring__array__string__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbAddDatabase(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbadddatabase__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbAddDatabaseTargets(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbadddatabasetargets__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbAddTopic(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbaddtopic__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbHasTopic(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbhastopic__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbReact(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbreact__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbRemoveTopic(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbremovetopic__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbTell(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbtell__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KbWasSaid(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbwassaid__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KeyImage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__keyimage__string_scalar__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KeyName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__keyname__string_scalar__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Keys(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__keys__hashmap__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value KnowsAbout(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__knowsabout__side__object__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Land(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__land__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LandAt(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__landat__object__object_scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LandResult(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__landresult__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Language()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__language__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LaserTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lasertarget__object__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbadd__control__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbClear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbclear__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbcolor__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbColorRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbcolorright__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbCurSel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbcursel__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbdata__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbDelete(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbdelete__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbIsSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbisselected__control__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbpicture__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbPictureRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbpictureright__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSelection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbselection__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetColorRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetcolorright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetCurSel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetcursel__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetdata__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicture__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureColorDisabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolordisabled__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureColorSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolorselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpictureright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureRightColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureRightColorDisabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolordisabled__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetPictureRightColorSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolorselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetSelectColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetSelectColorRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolorright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsettext__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetTextRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsettextright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetTooltip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsettooltip__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSetValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsetvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSize(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbsize__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSort(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbsort__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSortBy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbsortby__control_scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbSortByValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbsortbyvalue__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbtext__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbTextRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbtextright__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbTooltip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbtooltip__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LbValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbvalue__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Leader(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leader__team_member__ret__team_member, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardDeInit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboarddeinit__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardGetRows(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardgetrows__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardInit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardinit__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardRequestRowsFriends(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsfriends__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardRequestRowsGlobal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobal__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardRequestRowsGlobalAroundUser(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobalarounduser__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardsRequestUploadScore(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscore__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardsRequestUploadScoreKeepBest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaderboardState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardstate__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LeaveVehicle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__leavevehicle__group__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LibraryCredits()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__librarycredits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LibraryDisclaimers()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__librarydisclaimers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LifeState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lifestate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LightAttachObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lightattachobject__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LightDetachObject(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lightdetachobject__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LightIsOn(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lightison__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Lightnings()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__lightnings__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LimitSpeed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__limitspeed__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LinearConversion(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__linearconversion__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LineBreak()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__linebreak__ret__text);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LineIntersects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersects__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LineIntersectsObjs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersectsobjs__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LineIntersectsSurfaces(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersectssurfaces__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LineIntersectsWith(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersectswith__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LinkItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__linkitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value List(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__list__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ListObjects(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__listobjects__control__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ListRemoteTargets(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__listremotetargets__side__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ListVehicleSensors(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__listvehiclesensors__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Ln(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ln__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbAddArray(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbaddarray__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbAddColumn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbaddcolumn__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbAddRow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbaddrow__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbClear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbclear__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbcolor__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbColorRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbcolorright__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbCurSelRow(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbcurselrow__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbdata__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbDeleteColumn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbdeletecolumn__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbDeleteRow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbdeleterow__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbGetColumnsPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbgetcolumnsposition__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbpicture__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbPictureRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbpictureright__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetColorRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolorright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetColumnsPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolumnspos__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetCurSelRow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetcurselrow__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetdata__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicture__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetPictureColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetPictureColorRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetPictureColorSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetPictureColorSelectedRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselectedright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetPictureRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetpictureright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsettext__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetTextRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsettextright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetTooltip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsettooltip__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSetValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsetvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSize(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbsize__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSort(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsort__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSortBy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsortby__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbSortByValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbsortbyvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbtext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbTextRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbtextright__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LnbValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbvalue__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Load(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__load__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadAbs(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadabs__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadbackpack__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadConfig(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadconfig__string__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadFile(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadfile__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadGame()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__loadgame__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadIdentity(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__loadidentity__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadMagazine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__loadmagazine__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadOverlay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__loadoverlay__control__config__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadStatus(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__loadstatus__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadUniform(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loaduniform__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LoadVest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadvest__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Local(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__local__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Localize(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__localize__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LocalNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__localnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LocationNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__locationnull__ret__location);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LocationPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__locationposition__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Lock(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lock__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockCameraTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockcamerato__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockcargo__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockDriver(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockdriver__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Locked(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__locked__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockedCameraTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockedcamerato__object__array__ret__nothing_object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockedCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockedcargo__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockedDriver(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lockeddriver__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockedInventory(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lockedinventory__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockedTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockedturret__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockIdentity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lockidentity__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockInventory(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockinventory__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LockWP(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockwp__object_group__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Log(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__log__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LogEntities()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__logentities__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LogNetwork(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lognetwork__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LogNetworkTerminate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lognetworkterminate__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LookAt(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lookat__object_array__object_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value LookAtPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lookatpos__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazineCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinecargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Magazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazines__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesAllTurrets(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesallturrets__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesAmmo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesammo__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesAmmoCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesammocargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesAmmoFull(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesammofull__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesDetail(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetail__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesDetailBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailbackpack__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesDetailUniform(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailuniform__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesDetailVest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailvest__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazinesTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__magazinesturret__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MagazineTurretAmmo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__magazineturretammo__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MapAnimAdd(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__mapanimadd__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MapAnimClear()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__mapanimclear__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MapAnimCommit()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__mapanimcommit__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MapAnimDone()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__mapanimdone__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MapCenterOnCamera(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__mapcenteroncamera__control__bool__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MapGridPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__mapgridposition__object_array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkAsFinishedOnSteam()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__markasfinishedonsteam__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerAlpha(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markeralpha__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerBrush(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerbrush__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerChannel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerchannel__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerColor(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markercolor__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerDir(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerdir__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerPolyline(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerpolyline__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerPos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerpos__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerShadow(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markershadow__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerShape(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markershape__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerSize(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markersize__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markertext__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MarkerType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markertype__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MatrixMultiply(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__matrixmultiply__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MatrixTranspose(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__matrixtranspose__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Max(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__max__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MaxLoad(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__maxload__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Members(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__members__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuaction__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuadd__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuChecked(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuchecked__control__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuClear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuclear__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuCollapse(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menucollapse__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menudata__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuDelete(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menudelete__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuEnable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuenable__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuEnabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuenabled__control__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuExpand(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuexpand__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuHover(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuhover__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menupicture__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusetaction__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetCheck(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusetcheck__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusetdata__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusetpicture__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetShortcut(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusetshortcut__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusettext__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetURL(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuseturl__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSetValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusetvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuShortcut(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menushortcut__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuShortcutText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menushortcuttext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSize(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusize__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuSort(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusort__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menutext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuURL(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuurl__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MenuValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuvalue__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Merge(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__merge__hashmap__hashmap_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Min(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__min__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MineActive(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__mineactive__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MineDetectedBy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__minedetectedby__object__side__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissileTarget(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__missiletarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissileTargetPos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__missiletargetpos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionConfigFile()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionconfigfile__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionDifficulty()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missiondifficulty__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionEnd()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionend__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionName()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionname__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionNameSource()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionnamesource__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionProfileNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionprofilenamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionStart()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionstart__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MissionVersion()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionversion__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Mod(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__mod__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ModelToWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ModelToWorldVisual(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ModelToWorldVisualWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisualworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ModelToWorldWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworldworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ModParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__modparams__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoonIntensity()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__moonintensity__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoonPhase(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__moonphase__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Morale(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__morale__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Move(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__move__object_group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Move3DENCamera(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__move3dencamera__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveInAny(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveinany__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveInCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveInCommander(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveincommander__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveInDriver(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveindriver__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveInGunner(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveingunner__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveInTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveinturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveObjectToEnd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveobjecttoend__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveOut(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveout__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveTime(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__movetime__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveto__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveToCompleted(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__movetocompleted__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MoveToFailed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__movetofailed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value MusicVolume()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__musicvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Name(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__name__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NamedProperties(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__namedproperties__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NameSound(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__namesound__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearEntities(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearentities__object_array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestBuilding(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestbuilding__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestLocation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestlocation__array__ret__location, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestLocations(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestlocations__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestLocationWithDubbing(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestlocationwithdubbing__array__ret__location, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestMines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestmines__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearestobject__array__scalar__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestobjects__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearestTerrainObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestterrainobjects__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearObjects(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearObjectsReady(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearobjectsready__object_array__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearRoads(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearroads__object_array__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearSupplies(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearsupplies__object_array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NearTargets(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__neartargets__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NeedReload(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__needreload__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NeedService(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__needservice__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NetId(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__netid__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NetObjNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__netobjnull__ret__netobject);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NewOverlay(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__newoverlay__control__config__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NextMenuItemIndex(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nextmenuitemindex__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NextWeatherChange()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__nextweatherchange__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Nil()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__nil__ret__any);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NMenuItems(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nmenuitems__control__string_scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Not(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__not__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NumberOfEnginesRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__numberofenginesrtd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value NumberToDate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__numbertodate__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ObjectCurators(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__objectcurators__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ObjectFromNetId(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__objectfromnetid__string__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ObjectParent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__objectparent__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ObjNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__objnull__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ObjStatus(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__objstatus__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnBriefingGroup(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onbriefinggroup__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnBriefingNotes(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onbriefingnotes__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnBriefingPlan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onbriefingplan__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnBriefingTeamSwitch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onbriefingteamswitch__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnCommandModeChanged(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__oncommandmodechanged__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnDoubleClick(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ondoubleclick__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnEachFrame(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__oneachframe__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnGroupIconClick(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ongroupiconclick__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnGroupIconOverEnter(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverenter__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnGroupIconOverLeave(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverleave__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnHCGroupSelectionChanged(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onhcgroupselectionchanged__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnMapSingleClick(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__onmapsingleclick__any__code_string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnPlayerConnected(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onplayerconnected__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnPlayerDisconnected(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onplayerdisconnected__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnPreloadFinished(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onpreloadfinished__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnPreloadStarted(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onpreloadstarted__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnShowNewObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__onshownewobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OnTeamSwitch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__onteamswitch__code_string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OpenCuratorInterface()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__opencuratorinterface__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OpenDLCPage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__opendlcpage__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OpenGPS(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__opengps__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OpenMap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__openmap__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OpenSteamApp(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__opensteamapp__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OpenYoutubeVideo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__openyoutubevideo__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Opfor()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__opfor__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Or(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__or__bool__code__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OrderGetIn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ordergetin__array__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Overcast()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__overcast__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value OvercastForecast()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__overcastforecast__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Owner(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__owner__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Param(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__param__any__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Params(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__params__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ParseNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsenumber__bool__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ParseSimpleArray(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsesimplearray__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ParseText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsetext__string__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ParsingNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__parsingnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ParticlesQuality()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__particlesquality__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PeriscopeElevation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__periscopeelevation__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Pi()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pi__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PickWeaponPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__pickweaponpool__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Pitch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__pitch__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PixelGrid()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelgrid__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PixelGridBase()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelgridbase__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PixelGridNoUIScale()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelgridnouiscale__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PixelH()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelh__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PixelW()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelw__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayableSlotsNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playableslotsnumber__side__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayableUnits()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__playableunits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__playaction__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayActionNow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__playactionnow__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Player()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__player__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayerRespawnTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__playerrespawntime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayerSide()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__playerside__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayersNumber(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playersnumber__side__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayGesture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__playgesture__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayMission(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playmission__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayMove(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__playmove__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayMoveNow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__playmovenow__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayMusic(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playmusic__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlayScriptedMission(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playscriptedmission__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlaySound(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsound__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlaySound3D(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsound3d__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PlaySoundUI(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsoundui__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Pose(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__pose__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Position(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__position__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PositionCameraToWorld(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__positioncameratoworld__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PosScreenToWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__posscreentoworld__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PosWorldToScreen(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__posworldtoscreen__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectAdjust(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ppeffectadjust__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectCommit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ppeffectcommit__array__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectCommitted(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectcommitted__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectCreate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectcreate__array__ret__scalar_array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectDestroy(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectdestroy__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectEnable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ppeffectenable__scalar__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectenabled__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PpEffectForceInNVG(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ppeffectforceinnvg__scalar__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Precision(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__precision__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreloadCamera(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadcamera__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreloadObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__preloadobject__scalar__object_string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreloadSound(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadsound__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreloadTitleObj(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadtitleobj__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreloadTitleRsc(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadtitlersc__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreprocessFile(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preprocessfile__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PreprocessFileLineNumbers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preprocessfilelinenumbers__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PrimaryWeapon(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__primaryweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PrimaryWeaponItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__primaryweaponitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PrimaryWeaponMagazine(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__primaryweaponmagazine__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Priority(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__priority__task__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Private(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__private__string_array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProcessDiaryLink(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__processdiarylink__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProductVersion()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__productversion__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProfileName()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__profilename__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProfileNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__profilenamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProfileNameSteam()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__profilenamesteam__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProgressLoadingScreen(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__progressloadingscreen__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProgressPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__progressposition__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ProgressSetPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__progresssetposition__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PublicVariable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__publicvariable__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PublicVariableClient(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__publicvariableclient__scalar__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PublicVariableServer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__publicvariableserver__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PushBack(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__pushback__array__any__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PushBackUnique(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__pushbackunique__array__any__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value PutWeaponPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__putweaponpool__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value QueryItemsPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__queryitemspool__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value QueryMagazinePool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__querymagazinepool__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value QueryWeaponPool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__queryweaponpool__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Rad(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rad__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioChannelAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__radiochanneladd__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioChannelCreate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__radiochannelcreate__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioChannelInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__radiochannelinfo__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioChannelRemove(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__radiochannelremove__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioChannelSetCallSign(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetcallsign__scalar__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioChannelSetLabel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetlabel__scalar__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__radioenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RadioVolume()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__radiovolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Rain()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__rain__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Rainbow()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__rainbow__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RainParams()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__rainparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Random(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__random__scalar__scalar_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Rank(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rank__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RankId(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rankid__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Rating(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rating__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Rectangular(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rectangular__location__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RegexFind(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__regexfind__string__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RegexMatch(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__regexmatch__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RegexReplace(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__regexreplace__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RegisteredTasks(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__registeredtasks__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RegisterTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__registertask__team_member__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Reload(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__reload__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ReloadEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__reloadenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoteControl(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__remotecontrol__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoteExec(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__remoteexec__any__array__ret__string_nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoteExecCall(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__remoteexeccall__any__array__ret__string_nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoteExecutedOwner()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__remoteexecutedowner__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Remove3DENConnection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remove3denconnection__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Remove3DENEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remove3deneventhandler__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Remove3DENLayer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remove3denlayer__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeaction__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAll3DENEventHandlers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeall3deneventhandlers__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllActions(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallactions__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllAssignedItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallassigneditems__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllBinocularItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallbinocularitems__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllContainers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallcontainers__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllCuratorAddons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoraddons__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllCuratorCameraAreas(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallcuratorcameraareas__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllCuratorEditingAreas(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoreditingareas__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllEventHandlers(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removealleventhandlers__group__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllHandgunItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallhandgunitems__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallitems__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllItemsWithMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallitemswithmagazines__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllMissionEventHandlers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallmissioneventhandlers__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllMPEventHandlers(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeallmpeventhandlers__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllMusicEventHandlers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallmusiceventhandlers__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllOwnedMines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallownedmines__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllPrimaryWeaponItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallprimaryweaponitems__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllSecondaryWeaponItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallsecondaryweaponitems__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllUserActionEventHandlers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removealluseractioneventhandlers__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveAllWeapons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeallweapons__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removebackpack__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveBackpackGlobal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removebackpackglobal__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveBinocularItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removebinocularitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveCuratorAddons(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removecuratoraddons__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveCuratorCameraArea(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removecuratorcameraarea__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveCuratorEditableObjects(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditableobjects__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveCuratorEditingArea(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditingarea__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveDiaryRecord(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removediaryrecord__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveDiarySubject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removediarysubject__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveDrawIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removedrawicon__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveDrawLinks(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removedrawlinks__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeeventhandler__group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveFromRemainsCollector(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removefromremainscollector__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveGoggles(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removegoggles__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveGroupIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removegroupicon__group__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveHandgunItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removehandgunitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveHeadgear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeheadgear__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveItemFromBackpack(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeitemfrombackpack__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveItemFromUniform(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeitemfromuniform__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveItemFromVest(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeitemfromvest__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveItems(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeitems__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMagazine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removemagazine__object__string_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMagazineGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removemagazineglobal__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMagazines(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removemagazines__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMagazinesTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removemagazinesturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMagazineTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removemagazineturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMenuItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removemenuitem__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMissionEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removemissioneventhandler__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMPEventHandler(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removempeventhandler__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveMusicEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removemusiceventhandler__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveOwnedMine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeownedmine__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemovePrimaryWeaponItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeprimaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveSecondaryWeaponItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removesecondaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveSimpleTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removesimpletask__object__task__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveSwitchableUnit(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeswitchableunit__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveTeamMember(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeteammember__team_member__team_member__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveUniform(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeuniform__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveUserActionEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removeuseractioneventhandler__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveVest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__removevest__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveWeapon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeweapon__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveWeaponAttachmentCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeweaponattachmentcargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveWeaponCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeweaponcargo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveWeaponGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeweaponglobal__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RemoveWeaponTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__removeweaponturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ReportRemoteTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__reportremotetarget__side__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RequiredVersion(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__requiredversion__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ResetCamShake()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__resetcamshake__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ResetSubgroupDirection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__resetsubgroupdirection__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Resistance()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__resistance__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Resize(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__resize__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Resources(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__resources__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RespawnVehicle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__respawnvehicle__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RestartEditorCamera(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__restarteditorcamera__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Reveal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__reveal__object_group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RevealMine(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__revealmine__side__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Reverse(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__reverse__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ReversedMouseY()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__reversedmousey__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RoadAt(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__roadat__object_array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RoadsConnectedTo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__roadsconnectedto__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RoleDescription(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__roledescription__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeAttachedObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeattachedobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeAttachedTo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeattachedto__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeAttachEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeattachenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeAttachTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ropeattachto__object_array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeCreate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropecreate__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeCut(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropecut__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeDestroy(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropedestroy__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeDetach(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ropedetach__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeEndPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeendposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeLength(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropelength__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Ropes(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropes__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopesAttachedTo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropesattachedto__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeSegments(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropesegments__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeUnwind(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeunwind__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RopeUnwound(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeunwound__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RotorsForcesRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rotorsforcesrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RotorsRpmRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rotorsrpmrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Round(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__round__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value RunInitScript()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__runinitscript__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SafeZoneH()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezoneh__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SafeZoneW()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonew__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SafeZoneWAbs()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonewabs__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SafeZoneX()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonex__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SafeZoneXAbs()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonexabs__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SafeZoneY()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezoney__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Save3DENInventory(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__save3deninventory__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveGame()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__savegame__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveIdentity(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__saveidentity__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveJoysticks()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__savejoysticks__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveMissionProfileNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__savemissionprofilenamespace__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveOverlay(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__saveoverlay__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveProfileNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__saveprofilenamespace__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveStatus(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__savestatus__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SaveVar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__savevar__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SavingEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__savingenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Say(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__say__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Say2D(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__say2d__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Say3D(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__say3d__object_array__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScopeName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scopename__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Score(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__score__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScoreSide(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scoreside__side__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Screenshot(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__screenshot__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScreenToWorld(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__screentoworld__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScriptDone(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scriptdone__script__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScriptName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scriptname__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScriptNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__scriptnull__ret__script);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ScudState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scudstate__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SecondaryWeapon(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__secondaryweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SecondaryWeaponItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SecondaryWeaponMagazine(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponmagazine__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Select(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectBestPlaces(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectbestplaces__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectDiarySubject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectdiarysubject__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectedEditorObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectededitorobjects__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectEditorObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selecteditorobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectionNames(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionnames__object__string_scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectionPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionposition__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectionVectorDirAndUp(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionvectordirandup__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectLeader(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectleader__group__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectMax(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectmax__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectMin(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectmin__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectNoPlayer()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__selectnoplayer__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectPlayer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectplayer__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectRandom(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectrandom__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectRandomWeighted(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectrandomweighted__array__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectWeapon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectweapon__object__array__ret__bool_nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SelectWeaponTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectweaponturret__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SendAUMessage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sendaumessage__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SendSimpleCommand(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sendsimplecommand__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SendTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sendtask__team_member__array__ret__task, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SendTaskResult(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sendtaskresult__task__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SendUDPMessage(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sendudpmessage__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SentencesEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sentencesenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ServerCommand(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__servercommand__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ServerCommandAvailable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__servercommandavailable__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ServerCommandExecutable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__servercommandexecutable__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ServerName()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__servername__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ServerNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__servernamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ServerTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__servertime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set__hashmap__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENAttribute(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denattribute__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENAttributes(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3denattributes__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENGrid(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3dengrid__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENIconsVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3deniconsvisible__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENLayer(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denlayer__any__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENLinesVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3denlinesvisible__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENLogicType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denlogictype__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENMissionAttribute(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denmissionattribute__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENMissionAttributes(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3denmissionattributes__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENModelsVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3denmodelsvisible__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENObjectType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denobjecttype__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Set3DENSelected(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3denselected__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAccTime(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setacctime__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetActualCollectiveRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setactualcollectivertd__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAirplaneThrottle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setairplanethrottle__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAirportSide(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setairportside__object_scalar__side__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAmmo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setammo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAmmoCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setammocargo__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAmmoOnPylon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setammoonpylon__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAnimSpeedCoef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setanimspeedcoef__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAperture(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setaperture__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetApertureNew(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setaperturenew__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetArmoryPoints(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setarmorypoints__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAttributes(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setattributes__text_string__array__ret__text, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetAutonomous(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setautonomous__object__bool__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetBehaviour(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setbehaviour__object_group__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetBehaviourStrong(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setbehaviourstrong__object_group__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetBleedingRemaining(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setbleedingremaining__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetBrakesRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setbrakesrtd__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCameraInterest(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcamerainterest__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCamShakeDefParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcamshakedefparams__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCamShakeParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcamshakeparams__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCamUseTI(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcamuseti__bool__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCaptive(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcaptive__object__bool_scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCenterOfMass(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcenterofmass__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCollisionLight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcollisionlight__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCombatBehaviour(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcombatbehaviour__group__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCombatMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcombatmode__team_member__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCompassOscillation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcompassoscillation__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetConvoySeparation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setconvoyseparation__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCruiseControl(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcruisecontrol__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCuratorCameraAreaCeiling(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcuratorcameraareaceiling__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCuratorCoef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcuratorcoef__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCuratorEditingAreaType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcuratoreditingareatype__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCuratorWaypointCost(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcuratorwaypointcost__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCurrentChannel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcurrentchannel__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCurrentTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcurrenttask__object__task__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCurrentWaypoint(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcurrentwaypoint__group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCustomAimCoef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcustomaimcoef__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCustomMissionData(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcustommissiondata__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCustomSoundController(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcustomsoundcontroller__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetCustomWeightRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setcustomweightrtd__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDamage(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdamage__object__scalar_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDammage(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdammage__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setdate__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDebriefingText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdebriefingtext__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDefaultCamera(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setdefaultcamera__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDestination(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdestination__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDetailMapBlendPars(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setdetailmapblendpars__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDiaryRecordText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdiaryrecordtext__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDiarySubjectPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdiarysubjectpicture__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdir__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDirection(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdirection__location__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDrawIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdrawicon__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDriveOnPath(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdriveonpath__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDropInterval(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdropinterval__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDynamicSimulationDistance(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistance__string__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetDynamicSimulationDistanceCoef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistancecoef__string__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetEditorMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__seteditormode__control__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetEditorObjectScope(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__seteditorobjectscope__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetEffectCondition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__seteffectcondition__object_array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetEffectiveCommander(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__seteffectivecommander__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetEngineRpmRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setenginerpmrtd__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFace(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setface__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFaceAnimation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfaceanimation__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFatigue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfatigue__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFeatureType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfeaturetype__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFlagAnimationPhase(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setflaganimationphase__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFlagOwner(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setflagowner__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFlagSide(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setflagside__object__side__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFlagTexture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setflagtexture__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFog(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfog__scalar__scalar_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetForceGeneratorRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setforcegeneratorrtd__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFormation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setformation__team_member__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFormationTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setformationtask__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFormDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setformdir__object_group__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFriend(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfriend__side__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFromEditor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfromeditor__team_member__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFSMVariable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfsmvariable__scalar__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFuel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfuel__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetFuelCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfuelcargo__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgroupicon__group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupIconParams(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgroupiconparams__group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupIconsSelectable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsselectable__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupIconsVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsvisible__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupId(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgroupid__object_group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupIdGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgroupidglobal__object_group__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGroupOwner(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgroupowner__group__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetGusts(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgusts__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHideBehind(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sethidebehind__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sethit__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHitIndex(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sethitindex__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHitPointDamage(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sethitpointdamage__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHorizonParallaxCoef(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sethorizonparallaxcoef__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHUDMovementLevels(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sethudmovementlevels__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetHumidity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sethumidity__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetIdentity(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setidentity__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetImportance(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setimportance__location__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetInfoPanel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setinfopanel__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLeader(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setleader__team_member__team_member__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightAmbient(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightambient__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightAttenuation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightattenuation__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightBrightness(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightbrightness__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightcolor__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightConePars(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightconepars__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightDayLight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightdaylight__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightFlareMaxDistance(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightflaremaxdistance__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightFlareSize(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightflaresize__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightIntensity(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightintensity__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightIR(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightir__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightnings(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightnings__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightUseFlare(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightuseflare__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLightVolumeShape(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setlightvolumeshape__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetLocalWindParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setlocalwindparams__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMagazineTurretAmmo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmagazineturretammo__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerAlpha(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkeralpha__string__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerAlphaLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkeralphalocal__string__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerBrush(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrush__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerBrushLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrushlocal__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkercolor__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerColorLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkercolorlocal__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerdir__string__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerDirLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerdirlocal__string__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerPolyline(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolyline__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerPolylineLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolylinelocal__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerpos__string__object_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerPosLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkerposlocal__string__object_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerShadow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkershadow__string__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerShadowLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkershadowlocal__string__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerShape(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkershape__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerShapeLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkershapelocal__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerSize(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkersize__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerSizeLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkersizelocal__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkertext__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerTextLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkertextlocal__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkertype__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMarkerTypeLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmarkertypelocal__string__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMass(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmass__object__scalar_array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMaxLoad(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmaxload__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMimic(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmimic__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMissileTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmissiletarget__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMissileTargetPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmissiletargetpos__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMousePosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setmouseposition__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMusicEffect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmusiceffect__object_array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetMusicEventHandler(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setmusiceventhandler__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetName(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setname__location__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetNameSound(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setnamesound__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectArguments(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectarguments__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectMaterial(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterial__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectMaterialGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterialglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectProxy(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectproxy__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectScale(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectscale__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectTexture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjecttexture__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectTextureGlobal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjecttextureglobal__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetObjectViewDistance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setobjectviewdistance__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetOpticsMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setopticsmode__object__array_string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetOvercast(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setovercast__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetOwner(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setowner__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetOxygenRemaining(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setoxygenremaining__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetParticleCircle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setparticlecircle__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetParticleClass(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setparticleclass__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetParticleFire(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setparticlefire__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetParticleParams(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setparticleparams__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetParticleRandom(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setparticlerandom__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPilotCameraDirection(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpilotcameradirection__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPilotCameraRotation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpilotcamerarotation__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPilotCameraTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpilotcameratarget__object__object_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPilotLight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpilotlight__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPiPEffect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpipeffect__string__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPiPViewDistance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setpipviewdistance__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPitch(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpitch__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPlateNumber(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setplatenumber__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPlayable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setplayable__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPlayerRespawnTime(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setplayerrespawntime__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPlayerVoNVolume(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setplayervonvolume__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpos__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPosASL(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setposasl__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPosASL2(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setposasl2__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPosASLW(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setposaslw__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPosATL(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setposatl__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setposition__location__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPosWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setposworld__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPylonLoadout(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpylonloadout__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetPylonsPriority(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpylonspriority__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRadioMsg(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setradiomsg__scalar__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRain(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrain__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRainbow(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrainbow__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRandomLip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrandomlip__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRank(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrank__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRectangular(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrectangular__location__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRepairCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrepaircargo__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetRotorBrakeRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setrotorbrakertd__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetShadowDistance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setshadowdistance__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetShotParents(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setshotparents__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSide(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setside__location__side__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimpleTaskAlwaysVisible(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskalwaysvisible__task__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimpleTaskCustomData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskcustomdata__task__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimpleTaskDescription(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdescription__task__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimpleTaskDestination(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdestination__task__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimpleTaskTarget(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktarget__task__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimpleTaskType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktype__task__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSimulWeatherLayers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setsimulweatherlayers__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSize(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsize__location__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSkill(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setskill__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSlingLoad(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setslingload__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSoundEffect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsoundeffect__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSpeaker(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setspeaker__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSpeech(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setspeech__location__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSpeedMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setspeedmode__object_group__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetStamina(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setstamina__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetStaminaScheme(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setstaminascheme__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetStatValue(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setstatvalue__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSuppression(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setsuppression__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetSystemOfUnits(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setsystemofunits__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTargetAge(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settargetage__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTaskMarkerOffset(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settaskmarkeroffset__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTaskResult(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settaskresult__task__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTaskState(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settaskstate__task__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTerrainGrid(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setterraingrid__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTerrainHeight(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setterrainheight__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settext__location__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTimeMultiplier(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__settimemultiplier__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTIParameter(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__settiparameter__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTitleEffect(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settitleeffect__object_array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTowParent(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settowparent__object__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTrafficDensity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__settrafficdensity__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTrafficDistance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__settrafficdistance__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTrafficGap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__settrafficgap__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTrafficSpeed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__settrafficspeed__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerActivation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggeractivation__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerArea(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggerarea__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerInterval(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggerinterval__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerStatements(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggerstatements__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggertext__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerTimeout(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggertimeout__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTriggerType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settriggertype__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTurretLimits(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setturretlimits__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetTurretOpticsMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setturretopticsmode__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__settype__location__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnconscious(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunconscious__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitAbility(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitability__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitCombatMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitcombatmode__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitFreefallHeight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitfreefallheight__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitLoadout(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitloadout__object__config__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitpos__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitPosWeak(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitposweak__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitRank(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitrank__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitRecoilCoefficient(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunitrecoilcoefficient__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnitTrait(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunittrait__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUnloadInCombat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setunloadincombat__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUserActionText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setuseractiontext__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUserMFDText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setusermfdtext__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetUserMFDValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setusermfdvalue__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVariable(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvariable__location__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVectorDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvectordir__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVectorDirAndUp(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvectordirandup__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVectorUp(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvectorup__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleAmmo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicleammo__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleAmmoDef(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicleammodef__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleArmor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclearmor__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclecargo__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleId(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicleid__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleLock(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclelock__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehiclePosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicleposition__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleRadar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicleradar__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleReceiveRemoteTargets(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclereceiveremotetargets__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleReportOwnPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportownposition__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleReportRemoteTargets(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportremotetargets__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleTIPars(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicletipars__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVehicleVarName(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclevarname__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVelocity(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvelocity__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVelocityModelSpace(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvelocitymodelspace__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVelocityTransformation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvelocitytransformation__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetViewDistance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setviewdistance__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetVisibleIfTreeCollapsed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvisibleiftreecollapsed__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWantedRPMRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwantedrpmrtd__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaves(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaves__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointBehaviour(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointbehaviour__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointCombatMode(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointcombatmode__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointCompletionRadius(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointcompletionradius__array__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointDescription(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointdescription__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointForceBehaviour(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointforcebehaviour__array__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointFormation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointformation__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointHousePosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointhouseposition__array__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointLoiterAltitude(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiteraltitude__array__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointLoiterRadius(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiterradius__array__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointLoiterType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointloitertype__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointName(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointname__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointposition__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointScript(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointscript__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointSpeed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointspeed__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointStatements(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointstatements__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointTimeout(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointtimeout__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointType(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointtype__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWaypointVisible(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwaypointvisible__array__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWeaponReloadingTime(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setweaponreloadingtime__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWeaponZeroing(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setweaponzeroing__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWind(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setwind__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWindDir(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwinddir__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWindForce(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwindforce__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWindStr(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwindstr__scalar__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWingForceScaleRTD(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwingforcescalertd__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SetWPPos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setwppos__array__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Show3DIcons(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__show3dicons__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowChat(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showchat__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowCinemaBorder(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showcinemaborder__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowCommandingMenu(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showcommandingmenu__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowCompass(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showcompass__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowCuratorCompass(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showcuratorcompass__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowGPS(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showgps__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowHUD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showhud__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowLegend(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__showlegend__control__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowMap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showmap__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownArtilleryComputer()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownartillerycomputer__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownChat()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownchat__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownCompass()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__showncompass__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownCuratorCompass()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__showncuratorcompass__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowNewEditorObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__showneweditorobject__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownGPS()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__showngps__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownHUD()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownhud__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownMap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownmap__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownPad()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownpad__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownRadio()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownradio__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownScoretable()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownscoretable__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownSubtitles()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownsubtitles__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownUAVFeed()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownuavfeed__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownWarrant()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownwarrant__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShownWatch()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownwatch__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowPad(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showpad__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowRadio(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showradio__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowScoretable(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showscoretable__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowSubtitles(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showsubtitles__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowUAVFeed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showuavfeed__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowWarrant(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showwarrant__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowWatch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showwatch__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowWaypoint(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__showwaypoint__array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ShowWaypoints(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showwaypoints__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__side__location__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideAmbientLife()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideambientlife__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideChat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sidechat__object_array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideEmpty()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideempty__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideEnemy()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideenemy__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideFriendly()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sidefriendly__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideLogic()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sidelogic__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sideradio__object_array__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SideUnknown()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideunknown__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SimpleTasks(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simpletasks__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SimulationEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulationenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SimulCloudDensity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulclouddensity__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SimulCloudOcclusion(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulcloudocclusion__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SimulInClouds(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulinclouds__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SimulWeatherSync()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__simulweathersync__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Sin(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sin__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Size(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__size__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SizeOf(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sizeof__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Skill(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__skill__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SkillFinal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__skillfinal__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SkipTime(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__skiptime__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Sleep(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sleep__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SliderPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderposition__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SliderRange(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderrange__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SliderSetPosition(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__slidersetposition__control__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SliderSetRange(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__slidersetrange__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SliderSetSpeed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__slidersetspeed__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SliderSpeed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderspeed__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SlingLoadAssistantShown()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__slingloadassistantshown__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SoldierMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__soldiermagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SomeAmmo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__someammo__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Sort(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sort__array__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SoundVolume()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__soundvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Spawn(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__spawn__any__code__ret__script, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Speaker(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__speaker__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SpeechVolume()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__speechvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Speed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__speed__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SpeedMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__speedmode__object_group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SplitString(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__splitstring__string__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Sqrt(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sqrt__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SquadParams(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__squadparams__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Stance(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__stance__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value StartLoadingScreen(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__startloadingscreen__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Step(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__step__for__scalar__ret__for, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Stop(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__stop__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value StopEngineRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__stopenginertd__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Stopped(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__stopped__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Str(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__str__any__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SunOrMoon()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sunormoon__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SupportInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__supportinfo__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SuppressFor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__suppressfor__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SurfaceIsWater(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfaceiswater__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SurfaceNormal(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfacenormal__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SurfaceTexture(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfacetexture__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SurfaceType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfacetype__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwimInDepth(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__swimindepth__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Switch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__switch__any__ret__switch, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwitchableUnits()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__switchableunits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwitchAction(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__switchaction__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwitchCamera(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__switchcamera__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwitchGesture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__switchgesture__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwitchLight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__switchlight__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SwitchMove(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__switchmove__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizedObjects(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizedTriggers(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedtriggers__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizedWaypoints(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedwaypoints__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizeObjectsAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsadd__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizeObjectsRemove(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsremove__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizeTrigger(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__synchronizetrigger__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SynchronizeWaypoint(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__synchronizewaypoint__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SystemChat(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__systemchat__string__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SystemOfUnits()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__systemofunits__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SystemTime()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__systemtime__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value SystemTimeUTC()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__systemtimeutc__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Tan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tan__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TargetKnowledge(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targetknowledge__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Targets(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targets__group__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TargetsAggregate(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targetsaggregate__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TargetsQuery(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targetsquery__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskAlwaysVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskalwaysvisible__task__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskChildren(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskchildren__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskCompleted(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskcompleted__task__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskCustomData(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskcustomdata__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskDescription(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskdescription__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskDestination(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskdestination__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskHint(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskhint__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskMarkerOffset(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskmarkeroffset__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskname__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__tasknull__ret__task);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskParent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskparent__task__ret__task, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskResult(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskresult__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskState(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskstate__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TaskType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tasktype__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TeamMember(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__teammember__object__ret__team_member, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TeamMemberNull()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teammembernull__ret__team_member);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TeamName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__teamname__team_member__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Teams()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TeamSwitch()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teamswitch__ret__nothing);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TeamSwitchEnabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teamswitchenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TeamType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__teamtype__team_member__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Terminate(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terminate__script__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TerrainIntersect(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terrainintersect__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TerrainIntersectASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terrainintersectasl__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TerrainIntersectAtASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terrainintersectatasl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__text__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TextLog(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__textlog__any__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TextLogFormat(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__textlogformat__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Tg(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tg__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Then(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__then__if__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Throw(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__throw__if__any__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Time()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__time__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TimeMultiplier()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__timemultiplier__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TitleCut(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__titlecut__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TitleFadeOut(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__titlefadeout__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TitleObj(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__titleobj__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TitleRsc(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__titlersc__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TitleText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__titletext__array__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value To(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__to__for__scalar__ret__for, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToArray(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__toarray__hashmap__bool__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToFixed(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tofixed__scalar__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToLower(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tolower__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToLowerANSI(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toloweransi__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToString(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tostring__code__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToUpper(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toupper__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ToUpperANSI(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toupperansi__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerActivated(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggeractivated__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerActivation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggeractivation__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerAmmo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerammo__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerArea(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerarea__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerAttachedVehicle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerattachedvehicle__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerAttachObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__triggerattachobject__object__scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerAttachVehicle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__triggerattachvehicle__object__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerDynamicSimulation(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__triggerdynamicsimulation__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerInterval(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerinterval__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerStatements(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerstatements__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertext__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerTimeout(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertimeout__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerTimeoutCurrent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertimeoutcurrent__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TriggerType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertype__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Trim(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__trim__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value True()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__true__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Try(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__try__any__code__ret__exception, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TurretLocal(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__turretlocal__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TurretOwner(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__turretowner__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TurretUnit(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__turretunit__object__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvadd__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvClear(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvclear__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvCollapse(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvcollapse__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvCollapseAll(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvcollapseall__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvCount(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvcount__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvCurSel(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvcursel__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvdata__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvDelete(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvdelete__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvExpand(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvexpand__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvExpandAll(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvexpandall__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvIsSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvisselected__control__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvpicture__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvPictureRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvpictureright__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSelection(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvselection__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetCurSel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetcursel__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetData(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetdata__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPicture(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicture__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureColorDisabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolordisabled__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureColorSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolorselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureRight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpictureright__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureRightColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureRightColorDisabled(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolordisabled__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetPictureRightColorSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolorselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetSelectColor(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetselectcolor__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetSelected(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetselected__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsettext__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetTooltip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsettooltip__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSetValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsetvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSort(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsort__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSortAll(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsortall__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSortByValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalue__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvSortByValueAll(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalueall__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvText(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvtext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvTooltip(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvtooltip__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TvValue(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvvalue__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Type(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__type__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TypeName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__typename__any__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value TypeOf(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__typeof__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UAVControl(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uavcontrol__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UiNamespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__uinamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UiSleep(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uisleep__scalar__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnassignCurator(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unassigncurator__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnassignItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unassignitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnassignTeam(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unassignteam__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnassignVehicle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unassignvehicle__object__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Underwater(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__underwater__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Uniform(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniform__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UniformContainer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniformcontainer__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UniformItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniformitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UniformMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniformmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UniqueUnitItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniqueunititems__object_array__ret__hashmap, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitAddons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitaddons__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitAimPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitaimposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitAimPositionVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitaimpositionvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitBackpack(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitbackpack__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitCombatMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitcombatmode__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitIsUAV(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitisuav__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitPos(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitpos__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitReady(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitready__object_array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitRecoilCoefficient(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitrecoilcoefficient__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Units(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__units__side__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitsBelowHeight(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unitsbelowheight__array__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnitTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unitturret__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnlinkItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unlinkitem__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnlockAchievement(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unlockachievement__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UnregisterTask(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unregistertask__team_member__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UpdateDrawIcon(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__updatedrawicon__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UpdateMenuItem(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__updatemenuitem__control__array__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UpdateObjectTree(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__updateobjecttree__control__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UseAIOperMapObstructionTest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__useaiopermapobstructiontest__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UseAISteeringComponent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__useaisteeringcomponent__bool__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UseAudioTimeForMoves(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__useaudiotimeformoves__object__bool__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value UserInputDisabled()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__userinputdisabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Values(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__values__hashmap__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorAdd(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectoradd__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorCos(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorcos__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorCrossProduct(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorcrossproduct__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorDiff(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordiff__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorDir(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectordir__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorDirVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectordirvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorDistance(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordistance__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorDistanceSqr(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordistancesqr__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorDotProduct(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordotproduct__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorFromTo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorfromto__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorLinearConversion(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorlinearconversion__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorMagnitude(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectormagnitude__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorMagnitudeSqr(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectormagnitudesqr__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorModelToWorld(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorModelToWorldVisual(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworldvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorMultiply(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectormultiply__array__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorNormalized(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectornormalized__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorUp(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorup__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorUpVisual(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorupvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorWorldToModel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodel__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VectorWorldToModelVisual(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodelvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Vehicle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehicle__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleCargoEnabled(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclecargoenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleChat(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vehiclechat__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleMoveInfo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclemoveinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleRadio(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vehicleradio__object__string__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleReceiveRemoteTargets(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclereceiveremotetargets__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleReportOwnPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclereportownposition__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleReportRemoteTargets(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclereportremotetargets__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Vehicles()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__vehicles__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VehicleVarName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclevarname__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Velocity(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__velocity__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VelocityModelSpace(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__velocitymodelspace__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VerifySignature(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__verifysignature__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Vest(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vest__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VestContainer(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vestcontainer__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VestItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vestitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VestMagazines(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vestmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value ViewDistance()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__viewdistance__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisibleCompass()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblecompass__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisibleGPS()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblegps__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisibleMap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblemap__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisiblePosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__visibleposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisiblePositionASL(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__visiblepositionasl__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisibleScoretable()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblescoretable__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value VisibleWatch()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblewatch__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaitUntil(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waituntil__code__ret__nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Waves()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__waves__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointAttachedObject(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointattachedobject__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointAttachedVehicle(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointattachedvehicle__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointAttachObject(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__waypointattachobject__array__object_scalar__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointAttachVehicle(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__waypointattachvehicle__array__object__ret__nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointBehaviour(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointbehaviour__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointCombatMode(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointcombatmode__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointCompletionRadius(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointcompletionradius__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointDescription(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointdescription__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointForceBehaviour(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointforcebehaviour__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointFormation(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointformation__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointHousePosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointhouseposition__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointLoiterAltitude(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointloiteraltitude__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointLoiterRadius(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointloiterradius__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointLoiterType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointloitertype__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointName(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointname__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointPosition(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointposition__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Waypoints(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypoints__object_group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointScript(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointscript__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointsEnabledUAV(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointsenableduav__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointShow(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointshow__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointSpeed(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointspeed__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointStatements(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointstatements__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointTimeout(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointtimeout__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointTimeoutCurrent(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointtimeoutcurrent__group__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointType(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointtype__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WaypointVisible(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointvisible__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponAccessories(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponaccessories__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponAccessoriesCargo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponaccessoriescargo__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponDirection(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weapondirection__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponInertia(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponinertia__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponLowered(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponlowered__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponReloadingTime(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponreloadingtime__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Weapons(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weapons__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponsInfo(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponsinfo__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponsItems(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponsitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponsItemsCargo(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponsitemscargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponState(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponstate__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeaponsTurret(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponsturret__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WeightRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weightrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value West()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__west__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WFSideText(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__wfsidetext__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value While(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__while__code__ret__while, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value Wind()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__wind__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WindDir()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__winddir__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WindRTD()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__windrtd__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WindStr()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__windstr__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WingsForcesRTD(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__wingsforcesrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value With(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__with__namespace__ret__with, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WorldName()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__worldname__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WorldSize()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__worldsize__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WorldToModel(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__worldtomodel__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WorldToModelVisual(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__worldtomodelvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

__declspec(dllexport) game_value WorldToScreen(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__worldtoscreen__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

#pragma endregion GameFunctions