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


DLLEXPORT void TestGameData(game_data* data)
{
	if (data == nullptr)
	{
		return;
	}
	std::cout << "data points to: " << std::hex << data << std::endl;
}

#pragma endregion Testing

#pragma region Creation
DLLEXPORT auto_array<game_value> CreateAutoArray()
{
	return auto_array<game_value>();
}

DLLEXPORT void DeleteAutoArray(auto_array<game_value> instance)
{
	instance.~auto_array();
}


DLLEXPORT game_value CreateGameValue()
{
	game_value temp = game_value();
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value CreateGameValue(float value)
{
	game_value temp = game_value(value);
	temp.data->_refcount = 256;
	void* table = temp.data.get();
	return temp;
}

DLLEXPORT game_value CreateGameValue(bool value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value CreateGameValue(const char* value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value CreateGameValue(auto_array<game_value> array)
{
	auto temp = game_value(array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value CreateGameValue(vector2 value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value CreateGameValue(vector3 value)
{
	auto temp = game_value(value);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value CreateGameValue(game_data* data)
{
	auto temp = game_value(data);
	temp.data->_refcount = 256;
	return temp;
}


DLLEXPORT void DeleteGameData(game_data* instance)
{
	delete instance;
}

#pragma endregion Creation

#pragma region Allocators
DLLEXPORT void* Allocate(size_t size)
{
	auto temp = rv_allocator<char>::allocate(size);
	return temp;
}

DLLEXPORT void Deallocate(void* pointer)
{
	if (pointer == nullptr)
	{
		return;
	}
	rv_allocator<char>::deallocate(reinterpret_cast<char*>(pointer));
}
#pragma endregion Allocators

#pragma region GameFunctions
DLLEXPORT game_value unary__abs__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__abs__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__acos__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__acos__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__action__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__action__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__actionids__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionids__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionkeys__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeys__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionkeys__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeys__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionkeysex__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysex__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionkeysimages__string_array__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysimages__string_array__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionkeysnames__string_array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysnames__string_array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionkeysnamesarray__string_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionkeysnamesarray__string_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__actionname__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__actionname__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__activateaddons__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__activateaddons__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__activatekey__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__activatekey__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__activetitleeffectparams__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__activetitleeffectparams__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__add3denconnection__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__add3denconnection__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__add3deneventhandler__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__add3deneventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__addcamshake__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__addcamshake__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__addcuratorselected__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__addcuratorselected__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__addforcegeneratorrtd__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addforcegeneratorrtd__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__additempool__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__additempool__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__addmagazinepool__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__addmagazinepool__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__addmissioneventhandler__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addmissioneventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__addmusiceventhandler__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addmusiceventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__addonfiles__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__addonfiles__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__addswitchableunit__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__addswitchableunit__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__addtoremainscollector__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__addtoremainscollector__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__adduseractioneventhandler__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__adduseractioneventhandler__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__addweaponpool__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__addweaponpool__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__admin__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__admin__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__agent__team_member__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__agent__team_member__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__agltoasl__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__agltoasl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__aimpos__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__aimpos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__airdensityrtd__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__airdensityrtd__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__airplanethrottle__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__airplanethrottle__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__airportside__object_scalar__ret__side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__airportside__object_scalar__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__aisfinishheal__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__aisfinishheal__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__alive__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__alive__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allcontrols__display__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allcontrols__display__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allcontrols__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allcontrols__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__alldiarysubjects__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__alldiarysubjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__alllods__object_string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__alllods__object_string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allmissionobjects__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allmissionobjects__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allowedservice__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allowedservice__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allsimpleobjects__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allsimpleobjects__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allturrets__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allturrets__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allturrets__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allturrets__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__display__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__display__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__team_member__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__namespace__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__namespace__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__group__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__task__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__allvariables__location__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__allvariables__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__animationnames__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__animationnames__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__animationstate__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__animationstate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__asin__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__asin__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__asltoagl__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__asltoagl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__asltoatl__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__asltoatl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assert__bool__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assert__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedcommander__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedcommander__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assigneddriver__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assigneddriver__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedgroup__object__ret__group(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedgroup__object__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedgunner__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedgunner__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assigneditems__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assigneditems__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedtarget__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedtarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedteam__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedteam__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedvehicle__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedvehicle__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedvehiclerole__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedvehiclerole__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__assignedvehicles__group__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__assignedvehicles__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__atan__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__atan__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__atg__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__atg__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__atltoasl__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__atltoasl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__attachedobject__location__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attachedobject__location__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__attachedobjects__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attachedobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__attachedto__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attachedto__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__attackenabled__object_group__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__attackenabled__object_group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__backpack__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpack__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__backpackcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__backpackcontainer__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackcontainer__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__backpackitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__backpackmagazines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpackmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__backpacks__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__backpacks__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__behaviour__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__behaviour__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__binocular__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__binocular__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__binocularitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__binocularitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__binocularmagazine__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__binocularmagazine__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__boundingbox__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__boundingbox__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__boundingboxreal__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__boundingboxreal__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__boundingboxreal__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__boundingboxreal__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__boundingcenter__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__boundingcenter__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__brakesdisabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__brakesdisabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__breakout__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__breakout__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__breakto__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__breakto__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__breakwith__any__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__breakwith__any__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__buldozer_enableroaddiag__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__buldozer_enableroaddiag__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__buldozer_loadnewroads__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__buldozer_loadnewroads__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__buttonaction__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__buttonaction__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__buttonaction__scalar__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__buttonaction__scalar__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__buttonsetaction__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__buttonsetaction__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__calculatepath__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__calculatepath__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__calculateplayervisibilitybyfriendly__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__calculateplayervisibilitybyfriendly__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__call__code__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__call__code__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__camcommitted__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camcommitted__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__camdestroy__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__camdestroy__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__cameraeffectenablehud__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__cameraeffectenablehud__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__camerainterest__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camerainterest__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__campreloaded__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__campreloaded__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__camtarget__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__camtarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__camusenvg__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__camusenvg__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__cancelsimpletaskdestination__task__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__cancelsimpletaskdestination__task__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__candeployweapon__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__candeployweapon__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__canfire__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canfire__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__canmove__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canmove__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__canstand__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canstand__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__cantriggerdynamicsimulation__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cantriggerdynamicsimulation__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__canunloadincombat__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__canunloadincombat__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__captive__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__captive__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__captivenum__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__captivenum__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__case__any__ret__switch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__case__any__ret__switch, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__cbchecked__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cbchecked__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ceil__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ceil__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__channelenabled__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__channelenabled__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__checkaifeature__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__checkaifeature__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__classname__location__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__classname__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__clear3deninventory__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clear3deninventory__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearallitemsfrombackpack__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearallitemsfrombackpack__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearbackpackcargo__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargo__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearbackpackcargoglobal__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargoglobal__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__cleargroupicons__group__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__cleargroupicons__group__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearitemcargo__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearitemcargo__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearitemcargoglobal__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearitemcargoglobal__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearmagazinecargo__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargo__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearmagazinecargoglobal__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargoglobal__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearoverlay__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearoverlay__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearweaponcargo__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargo__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__clearweaponcargoglobal__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargoglobal__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__closedialog__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__closedialog__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__closeoverlay__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__closeoverlay__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__collapseobjecttree__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__collapseobjecttree__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__collect3denhistory__code__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__collect3denhistory__code__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__collectivertd__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__collectivertd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__collisiondisabledwith__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__collisiondisabledwith__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__combatbehaviour__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__combatbehaviour__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__combatbehaviour__group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__combatbehaviour__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__combatmode__object_group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__combatmode__object_group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__commander__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__commander__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__commandgetout__object_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__commandgetout__object_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__commandstop__object_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__commandstop__object_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__comment__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__comment__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__commitoverlay__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__commitoverlay__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__compatibleitems__string_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compatibleitems__string_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__compatiblemagazines__string_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compatiblemagazines__string_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__compile__string__ret__code(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compile__string__ret__code, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__compilefinal__code_string__ret__code(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compilefinal__code_string__ret__code, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__compilefinal__hashmap__ret__hashmap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compilefinal__hashmap__ret__hashmap, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__compilescript__array__ret__code(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__compilescript__array__ret__code, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__completedfsm__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__completedfsm__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__composetext__array__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__composetext__array__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__confighierarchy__config__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__confighierarchy__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__configname__config__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configname__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__configof__object__ret__config(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configof__object__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__configproperties__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configproperties__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__configsourceaddonlist__config__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configsourceaddonlist__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__configsourcemod__config__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configsourcemod__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__configsourcemodlist__config__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__configsourcemodlist__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__connecttoserver__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__connecttoserver__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__continuewith__any__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__continuewith__any__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__conversationdisabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__conversationdisabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__copytoclipboard__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__copytoclipboard__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__cos__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__cos__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__count__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__count__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__count__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__count__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__count__config__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__count__config__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__count__hashmap__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__count__hashmap__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__create3dencomposition__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__create3dencomposition__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__create3denentity__array__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__create3denentity__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createagent__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createagent__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createcenter__side__ret__side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createcenter__side__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createdialog__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createdialog__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createdialog__array__ret__display(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createdialog__array__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__creatediarylink__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__creatediarylink__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__creategeardialog__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__creategeardialog__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__creategroup__side_array__ret__group(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__creategroup__side_array__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__createguardedpoint__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__createguardedpoint__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__createhashmapfromarray__array__ret__hashmap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createhashmapfromarray__array__ret__hashmap, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createhashmapobject__array__ret__hashmap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createhashmapobject__array__ret__hashmap, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createlocation__array__ret__location(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createlocation__array__ret__location, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createmarker__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createmarker__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createmarkerlocal__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createmarkerlocal__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createmine__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createmine__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createsimpleobject__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createsimpleobject__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createsoundsource__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createsoundsource__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createteam__array__ret__team_member(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createteam__array__ret__team_member, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createtrigger__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createtrigger__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createvehicle__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createvehicle__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createvehiclecrew__object__ret__group(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createvehiclecrew__object__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__createvehiclelocal__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__createvehiclelocal__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__crew__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__crew__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctaddheader__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctaddheader__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctaddrow__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctaddrow__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ctclear__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctclear__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ctcursel__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctcursel__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctheadercount__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctheadercount__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ctrlactivate__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlactivate__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ctrlangle__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlangle__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlautoscrolldelay__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrolldelay__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlautoscrollrewind__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollrewind__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlautoscrollspeed__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollspeed__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlbackgroundcolor__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlbackgroundcolor__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlchecked__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlchecked__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlclassname__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlclassname__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlcommitted__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlcommitted__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrldelete__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrldelete__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ctrlenable__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlenable__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ctrlenabled__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlenabled__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlenabled__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlenabled__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlfade__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlfade__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlfontheight__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlfontheight__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlforegroundcolor__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlforegroundcolor__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlhtmlloaded__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlhtmlloaded__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlidc__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlidc__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlidd__display__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlidd__display__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ctrlmapanimclear__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimclear__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__ctrlmapanimcommit__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimcommit__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ctrlmapanimdone__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimdone__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmapdir__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapdir__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmapmouseover__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapmouseover__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmapposition__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmapscale__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmapscale__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmodel__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmodel__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmodeldirandup__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmodeldirandup__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmodelscale__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmodelscale__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlmouseposition__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlmouseposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlparent__control__ret__display(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlparent__control__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlparentcontrolsgroup__control__ret__control(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlparentcontrolsgroup__control__ret__control, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlposition__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlscale__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlscale__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlscrollvalues__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlscrollvalues__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ctrlsetfocus__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlsetfocus__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__ctrlsettext__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlsettext__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ctrlshadow__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlshadow__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ctrlshow__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ctrlshow__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ctrlshown__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlshown__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlstyle__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlstyle__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltext__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltext__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltext__scalar__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltext__scalar__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltextcolor__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextcolor__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltextheight__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextheight__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltextsecondary__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextsecondary__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltextselection__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextselection__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltextwidth__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltextwidth__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltooltip__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltooltip__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrltype__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrltype__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlurl__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlurl__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlurloverlaymode__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlurloverlaymode__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrlvisible__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrlvisible__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ctrowcount__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ctrowcount__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatoraddons__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoraddons__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatorcameraarea__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorcameraarea__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatorcameraareaceiling__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorcameraareaceiling__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatoreditableobjects__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoreditableobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatoreditingarea__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoreditingarea__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatoreditingareatype__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatoreditingareatype__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatorpoints__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorpoints__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatorregisteredobjects__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorregisteredobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatorselectionpreset__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorselectionpreset__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__curatorwaypointcost__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__curatorwaypointcost__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentcommand__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentcommand__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentmagazine__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentmagazine__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentmagazinedetail__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentmagazinedetail__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentmuzzle__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentmuzzle__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentpilot__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentpilot__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currenttask__object__ret__task(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currenttask__object__ret__task, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currenttasks__team_member__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currenttasks__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentthrowable__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentthrowable__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentvisionmode__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentvisionmode__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentvisionmode__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentvisionmode__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentwaypoint__group__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentwaypoint__group__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentweapon__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentweaponmode__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentweaponmode__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__currentzeroing__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__currentzeroing__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__cutobj__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__cutobj__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__cutrsc__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__cutrsc__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__cuttext__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__cuttext__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__damage__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__damage__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__datetonumber__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__datetonumber__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__deactivatekey__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deactivatekey__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__debriefingtext__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__debriefingtext__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__debuglog__any__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__debuglog__any__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__decaygraphvalues__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__decaygraphvalues__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__default__code__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__default__code__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__deg__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deg__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__delete3denentities__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__delete3denentities__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletecenter__side__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletecenter__side__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletecollection__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletecollection__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletegroup__group__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletegroup__group__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__deleteidentity__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deleteidentity__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__deletelocation__location__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletelocation__location__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletemarker__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletemarker__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletemarkerlocal__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletemarkerlocal__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletesite__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletesite__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__deletestatus__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__deletestatus__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__deleteteam__team_member__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deleteteam__team_member__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletevehicle__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletevehicle__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletevehiclecrew__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletevehiclecrew__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__deletewaypoint__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__deletewaypoint__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__detach__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__detach__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__detectedmines__side__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__detectedmines__side__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__diag_captureframe__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_captureframe__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_captureframetofile__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_captureframetofile__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_captureslowframe__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_captureslowframe__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__diag_codeperformance__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_codeperformance__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__diag_drawmode__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_drawmode__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_dumpscriptassembly__code__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_dumpscriptassembly__code__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_dynamicsimulationend__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_dynamicsimulationend__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__diag_enabled__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_enabled__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__diag_exportconfig__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_exportconfig__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_exportterrainsvg__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_exportterrainsvg__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__diag_getterrainsegmentoffset__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_getterrainsegmentoffset__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__diag_lightnewload__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_lightnewload__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__diag_list__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_list__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__diag_localized__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_localized__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__diag_log__any__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_log__any__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_logslowframe__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_logslowframe__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_mergeconfigfile__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_mergeconfigfile__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_recordturretlimits__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_recordturretlimits__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__diag_setlightnew__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_setlightnew__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__diag_testscriptsimplevm__code__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__diag_testscriptsimplevm__code__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__diag_toggle__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__diag_toggle__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__didjipowner__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__didjipowner__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__difficultyenabled__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__difficultyenabled__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__difficultyoption__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__difficultyoption__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__difficultyoption__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__difficultyoption__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__direction__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__direction__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__direction__location__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__direction__location__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__disablemapindicators__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__disablemapindicators__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__disableremotesensors__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__disableremotesensors__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__disableuserinput__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__disableuserinput__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__displaychild__display__ret__display(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displaychild__display__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__displayctrl__scalar__ret__control(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displayctrl__scalar__ret__control, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__displayparent__display__ret__display(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displayparent__display__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__displayuniquename__display__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__displayuniquename__display__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__displayupdate__display__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__displayupdate__display__ret__nothing, right_arg);
}

DLLEXPORT void unary__dissolveteam__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__dissolveteam__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__do3denaction__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__do3denaction__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__dogetout__object_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__dogetout__object_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__dostop__object_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__dostop__object_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__drawicon3d__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__drawicon3d__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__drawlaser__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__drawlaser__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__drawline3d__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__drawline3d__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__driver__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__driver__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__drop__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__drop__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__dynamicsimulationdistance__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistance__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__dynamicsimulationdistancecoef__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistancecoef__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__dynamicsimulationenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__dynamicsimulationenabled__group__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationenabled__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__echo__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__echo__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__edit3denmissionattributes__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__edit3denmissionattributes__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__effectivecommander__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__effectivecommander__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__enableaudiofeature__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enableaudiofeature__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__enablecamshake__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablecamshake__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enablecaustics__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablecaustics__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enabledebriefingstats__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enabledebriefingstats__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__enablediaglegend__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablediaglegend__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enabledynamicsimulationsystem__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enabledynamicsimulationsystem__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enableengineartillery__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enableengineartillery__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enableenvironment__bool_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enableenvironment__bool_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__enableradio__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enableradio__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enablesatnormalondetail__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablesatnormalondetail__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enablesaving__bool_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablesaving__bool_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__enablesentences__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablesentences__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enablestressdamage__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enablestressdamage__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enableteamswitch__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enableteamswitch__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enabletraffic__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enabletraffic__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__enableweapondisassembly__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__enableweapondisassembly__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__endmission__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__endmission__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__enginesisonrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginesisonrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__enginespowerrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginespowerrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__enginesrpmrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginesrpmrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__enginestorquertd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__enginestorquertd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__entities__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__entities__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__entities__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__entities__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__equipmentdisabled__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__equipmentdisabled__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__estimatedtimeleft__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__estimatedtimeleft__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__everybackpack__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__everybackpack__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__everycontainer__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__everycontainer__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__execfsm__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__execfsm__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__execvm__string__ret__script(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__execvm__string__ret__script, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__exp__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__exp__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__expecteddestination__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__expecteddestination__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__exportjipmessages__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__exportjipmessages__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__eyedirection__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__eyedirection__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__eyepos__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__eyepos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__face__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__face__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__faction__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__faction__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__failmission__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__failmission__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__fileexists__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fileexists__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__fillweaponsfrompool__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__fillweaponsfrompool__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__finddisplay__scalar__ret__display(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__finddisplay__scalar__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__finddisplay__string__ret__display(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__finddisplay__string__ret__display, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__finite__scalar_nan__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__finite__scalar_nan__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__firstbackpack__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__firstbackpack__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__flag__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flag__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__flaganimationphase__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flaganimationphase__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__flagowner__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flagowner__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__flagside__object__ret__side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flagside__object__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__flagtexture__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flagtexture__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__flatten__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__flatten__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__fleeing__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fleeing__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__floor__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__floor__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__focusedctrl__display__ret__control(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__focusedctrl__display__ret__control, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__for__string__ret__for(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__for__string__ret__for, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__for__array__ret__for(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__for__array__ret__for, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__forceatpositionrtd__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forceatpositionrtd__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__forcecadetdifficulty__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forcecadetdifficulty__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__forcegeneratorrtd__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__forcegeneratorrtd__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__forcemap__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__forcemap__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__forcerespawn__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__forcerespawn__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__forceunicode__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__forceunicode__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__format__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__format__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formation__object_group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formation__object_group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formation__team_member__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formation__team_member__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formationdirection__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationdirection__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formationleader__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationleader__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formationmembers__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationmembers__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formationposition__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formationtask__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formationtask__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formattext__array__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formattext__array__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__formleader__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__formleader__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__freeextension__string__ret__bool_nothing(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__freeextension__string__ret__bool_nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__fromeditor__team_member__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fromeditor__team_member__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__fuel__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fuel__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__fullcrew__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fullcrew__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__fullcrew__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__fullcrew__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gearidcammocount__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gearidcammocount__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gearslotammocount__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gearslotammocount__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gearslotdata__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gearslotdata__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gesturestate__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gesturestate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__get3denactionstate__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denactionstate__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__get3denconnections__any__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denconnections__any__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__get3denentity__scalar__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denentity__scalar__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__get3denentityid__any__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denentityid__any__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__get3dengrid__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__get3dengrid__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__get3denlayerentities__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denlayerentities__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__get3denselected__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__get3denselected__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getaimingcoef__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getaimingcoef__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallenv3dsoundcontrollers__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallenv3dsoundcontrollers__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallenvsoundcontrollers__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallenvsoundcontrollers__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallhitpointsdamage__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallhitpointsdamage__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallownedmines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallownedmines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallpylonsinfo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallpylonsinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallsoundcontrollers__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallsoundcontrollers__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getallunittraits__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getallunittraits__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getammocargo__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getammocargo__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getanimaimprecision__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getanimaimprecision__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getanimspeedcoef__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getanimspeedcoef__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getarray__config__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getarray__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getartilleryammo__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getartilleryammo__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getassetdlcinfo__object_string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassetdlcinfo__object_string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getassetdlcinfo__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassetdlcinfo__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getassignedcuratorlogic__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorlogic__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getassignedcuratorunit__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorunit__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getattacktarget__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getattacktarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getbackpackcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getbackpackcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getbleedingremaining__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getbleedingremaining__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getburningvalue__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getburningvalue__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcameraviewdirection__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcameraviewdirection__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcenterofmass__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcenterofmass__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getconnecteduav__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getconnecteduav__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getconnecteduavunit__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getconnecteduavunit__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcontainermaxload__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcontainermaxload__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcorpse__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcorpse__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcruisecontrol__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcruisecontrol__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcustomaimcoef__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcustomaimcoef__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcustomsoundcontroller__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontroller__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getcustomsoundcontrollercount__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontrollercount__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdammage__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdammage__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdebriefingtext__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdebriefingtext__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdescription__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdescription__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdir__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdir__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdirvisual__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdirvisual__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdiverstate__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdiverstate__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdlcassetsusagebyname__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdlcassetsusagebyname__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdlcs__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdlcs__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getdlcusagetime__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getdlcusagetime__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__geteditorcamera__control__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__geteditorcamera__control__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__geteditormode__control__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__geteditormode__control__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getenginetargetrpmrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getenginetargetrpmrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__geteventhandlerinfo__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__geteventhandlerinfo__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getfatigue__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getfatigue__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getfieldmanualstartpage__display__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getfieldmanualstartpage__display__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getforcedflagtexture__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getforcedflagtexture__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getforcedspeed__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getforcedspeed__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getfuelcargo__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getfuelcargo__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getgraphvalues__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getgraphvalues__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getgroupiconparams__group__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getgroupiconparams__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getgroupicons__group__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getgroupicons__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getitemcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getitemcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getlightingat__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getlightingat__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmagazinecargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmagazinecargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmarkercolor__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkercolor__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmarkerpos__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkerpos__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmarkerpos__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkerpos__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmarkersize__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkersize__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmarkertype__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmarkertype__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmass__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmass__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmissionconfig__string__ret__config(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionconfig__string__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmissionconfigvalue__string_array__ret__array_string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionconfigvalue__string_array__ret__array_string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmissionlayerentities__string_scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionlayerentities__string_scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmissionpath__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmissionpath__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getmodelinfo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getmodelinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getnumber__config__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getnumber__config__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjectdlc__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectdlc__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjectfov__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectfov__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjectid__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjectmaterials__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectmaterials__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjectscale__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjectscale__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjecttextures__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjecttextures__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getobjecttype__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getobjecttype__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getoxygenremaining__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getoxygenremaining__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpersonuseddlcs__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpersonuseddlcs__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpilotcameradirection__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameradirection__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpilotcameraopticsmode__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameraopticsmode__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpilotcameraposition__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameraposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpilotcamerarotation__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcamerarotation__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpilotcameratarget__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpilotcameratarget__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getplatenumber__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplatenumber__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getplayerchannel__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayerchannel__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getplayerid__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayerid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getplayerscores__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayerscores__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getplayeruid__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayeruid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getplayervonvolume__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getplayervonvolume__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpos__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpos__location__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpos__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposasl__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposasl__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposaslvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposaslvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposaslw__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposaslw__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposatl__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposatl__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposatlvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposatlvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposworld__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposworld__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getposworldvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getposworldvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getpylonmagazines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getpylonmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getrepaircargo__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getrepaircargo__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getroadinfo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getroadinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getrotorbrakertd__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getrotorbrakertd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getsensortargets__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getsensortargets__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getsensorthreats__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getsensorthreats__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getshotparents__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getshotparents__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getslingload__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getslingload__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getstamina__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getstamina__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getstatvalue__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getstatvalue__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getsuppression__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getsuppression__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getterrainheight__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getterrainheight__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getterrainheightasl__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getterrainheightasl__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gettext__config__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettext__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gettextraw__config__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettextraw__config__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gettextureinfo__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettextureinfo__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gettowparent__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettowparent__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gettrimoffsetrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gettrimoffsetrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getturretopticsmode__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getturretopticsmode__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getunitfreefallinfo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunitfreefallinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getunitloadout__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunitloadout__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getunitloadout__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunitloadout__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getunitloadout__config__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunitloadout__config__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getunloadincombat__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getunloadincombat__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getuserinfo__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getuserinfo__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getusermfdtext__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getusermfdtext__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getusermfdvalue__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getusermfdvalue__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getvehiclecargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getvehiclecargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getvehicletipars__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getvehicletipars__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getweaponcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getweaponcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getweaponsway__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getweaponsway__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getwingsorientationrtd__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getwingsorientationrtd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getwingspositionrtd__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getwingspositionrtd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__getwppos__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__getwppos__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__goggles__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__goggles__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__goto__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__goto__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__group__object__ret__group(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__group__object__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__groupfromnetid__string__ret__group(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupfromnetid__string__ret__group, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__groupid__group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupid__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__groupid__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupid__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__groupowner__group__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupowner__group__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__groups__side__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groups__side__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__groupselectedunits__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__groupselectedunits__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__gunner__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__gunner__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__handgunitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handgunitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__handgunmagazine__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handgunmagazine__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__handgunweapon__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handgunweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__handshit__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__handshit__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__hashvalue__object_side__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hashvalue__object_side__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__haspilotcamera__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__haspilotcamera__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__hcallgroups__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcallgroups__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__hcleader__group__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcleader__group__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__hcremoveallgroups__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hcremoveallgroups__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__hcselected__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hcselected__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__hcshowbar__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hcshowbar__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__headgear__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__headgear__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__hidebody__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hidebody__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__hideobject__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hideobject__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__hideobjectglobal__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hideobjectglobal__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__hint__text_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hint__text_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__hintc__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hintc__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__hintcadet__text_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hintcadet__text_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__hintsilent__text_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hintsilent__text_string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__hmd__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__hmd__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__hostmission__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__hostmission__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__if__bool__ret__if(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__if__bool__ret__if, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__image__string__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__image__string__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__importallgroups__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__importallgroups__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__importance__location__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__importance__location__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__incapacitatedstate__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__incapacitatedstate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__inflamed__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inflamed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__infopanel__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__infopanel__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__infopanels__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__infopanels__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ingameuiseteventhandler__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ingameuiseteventhandler__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__inheritsfrom__config__ret__config(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inheritsfrom__config__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__inputaction__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputaction__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__inputcontroller__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputcontroller__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__inputmouse__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputmouse__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__inputmouse__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__inputmouse__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__insidebuilding__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__insidebuilding__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isabletobreathe__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isabletobreathe__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isagent__team_member__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isagent__team_member__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isaimprecisionenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isaimprecisionenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isallowedcrewinimmobile__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isallowedcrewinimmobile__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isarray__config__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isarray__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isautohoveron__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautohoveron__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isautonomous__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautonomous__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isautostartupenabledrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautostartupenabledrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isautotrimonrtd__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isautotrimonrtd__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isawake__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isawake__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isbleeding__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isbleeding__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isburning__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isburning__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isclass__config__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isclass__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__iscollisionlighton__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iscollisionlighton__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__iscopilotenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iscopilotenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isdamageallowed__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isdamageallowed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isdlcavailable__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isdlcavailable__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isengineon__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isengineon__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isfinal__any__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isfinal__any__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isforcedwalk__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isforcedwalk__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isformationleader__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isformationleader__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isgroupdeletedwhenempty__group__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isgroupdeletedwhenempty__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ishidden__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ishidden__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isinremainscollector__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isinremainscollector__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__iskeyactive__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iskeyactive__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__islaseron__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__islaseron__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__islighton__object_array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__islighton__object_array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__islocalized__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__islocalized__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ismanualfire__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ismanualfire__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ismarkedforcollection__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ismarkedforcollection__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnil__code_string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnil__code_string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__group__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__script__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__script__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__config__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__display__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__display__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__team_member__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__team_member__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__netobject__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__netobject__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__task__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__task__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__diary_record__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__diary_record__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnull__location__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnull__location__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isnumber__config__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isnumber__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isobjecthidden__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isobjecthidden__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isobjectrtd__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isobjectrtd__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isonroad__object_array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isonroad__object_array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isplayer__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isplayer__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isplayer__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isplayer__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isrealtime__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isrealtime__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isshowing3dicons__control__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isshowing3dicons__control__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__issimpleobject__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__issimpleobject__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__issprintallowed__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__issprintallowed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isstaminaenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isstaminaenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__istext__config__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__istext__config__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__istouchingground__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__istouchingground__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isturnedout__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isturnedout__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isuavconnected__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isuavconnected__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isvehiclecargo__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isvehiclecargo__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isvehicleradaron__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isvehicleradaron__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__iswalking__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__iswalking__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isweapondeployed__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isweapondeployed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isweapondeployed__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isweapondeployed__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__isweaponrested__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__isweaponrested__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__itemcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__itemcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__items__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__items__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__itemswithmagazines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__itemswithmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__keyimage__string_scalar__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__keyimage__string_scalar__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__keyname__string_scalar__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__keyname__string_scalar__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__keys__hashmap__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__keys__hashmap__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__landresult__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__landresult__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lasertarget__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lasertarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbadd__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbadd__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lbclear__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbclear__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbclear__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbclear__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lbcolor__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbcolor__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbcolorright__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbcolorright__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbcursel__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbcursel__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbcursel__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbcursel__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbdata__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbdata__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lbdelete__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbdelete__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lbpicture__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbpicture__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbpictureright__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbpictureright__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbselection__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbselection__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lbsetcolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetcolor__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetcolorright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetcolorright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetcursel__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetcursel__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetdata__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetdata__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetpicture__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetpicture__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetpicturecolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetpicturecolor__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetpicturecolordisabled__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetpicturecolordisabled__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetpicturecolorselected__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetpicturecolorselected__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetpictureright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetpictureright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetselectcolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetselectcolor__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetselectcolorright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetselectcolorright__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lbsettext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbsettext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lbsettooltip__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsettooltip__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsetvalue__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsetvalue__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lbsize__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbsize__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbsize__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbsize__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lbsort__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsort__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsort__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsort__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsort__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsort__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsortbyvalue__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsortbyvalue__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__lbsortbyvalue__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lbsortbyvalue__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lbtext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbtext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbtextright__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbtextright__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbtooltip__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbtooltip__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lbvalue__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lbvalue__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leader__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leader__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leader__group__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leader__group__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leader__team_member__ret__team_member(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leader__team_member__ret__team_member, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboarddeinit__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboarddeinit__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardgetrows__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardgetrows__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardinit__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardinit__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardrequestrowsfriends__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsfriends__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardrequestrowsglobal__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobal__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardrequestrowsglobalarounduser__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobalarounduser__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardsrequestuploadscore__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscore__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__leaderboardstate__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__leaderboardstate__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lifestate__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lifestate__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lightdetachobject__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lightdetachobject__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lightison__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lightison__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__linearconversion__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__linearconversion__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lineintersects__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersects__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lineintersectsobjs__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersectsobjs__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lineintersectssurfaces__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersectssurfaces__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lineintersectswith__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lineintersectswith__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__list__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__list__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__listremotetargets__side__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__listremotetargets__side__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__listvehiclesensors__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__listvehiclesensors__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ln__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ln__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbaddarray__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbaddarray__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbaddcolumn__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbaddcolumn__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbaddrow__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbaddrow__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lnbclear__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbclear__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbclear__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbclear__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lnbcolor__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbcolor__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbcolorright__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbcolorright__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbcurselrow__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbcurselrow__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbcurselrow__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbcurselrow__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbdata__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbdata__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lnbdeletecolumn__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbdeletecolumn__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbdeleterow__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbdeleterow__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lnbgetcolumnsposition__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbgetcolumnsposition__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbgetcolumnsposition__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbgetcolumnsposition__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbpicture__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbpicture__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbpictureright__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbpictureright__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lnbsetcolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetcolor__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetcolorright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetcolorright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetcolumnspos__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetcolumnspos__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetcurselrow__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetcurselrow__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetdata__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetdata__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetpicture__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetpicture__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetpicturecolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetpicturecolor__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetpicturecolorright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetpicturecolorright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetpicturecolorselected__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetpicturecolorselected__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetpicturecolorselectedright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetpicturecolorselectedright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetpictureright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetpictureright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsettext__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsettext__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsettextright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsettextright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsettooltip__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsettooltip__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsetvalue__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsetvalue__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lnbsize__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbsize__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbsize__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbsize__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lnbsort__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsort__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__lnbsortbyvalue__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lnbsortbyvalue__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__lnbtext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbtext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbtextright__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbtextright__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lnbvalue__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lnbvalue__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__load__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__load__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__loadabs__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadabs__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__loadbackpack__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadbackpack__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__loadconfig__string__ret__config(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadconfig__string__ret__config, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__loadcuratorselectionpreset__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__loadcuratorselectionpreset__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__loadfile__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadfile__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__loaduniform__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loaduniform__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__loadvest__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__loadvest__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__local__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__local__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__local__group__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__local__group__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__localize__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__localize__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__locationposition__location__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__locationposition__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__locked__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__locked__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lockeddriver__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lockeddriver__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lockedinventory__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lockedinventory__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lockidentity__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lockidentity__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__log__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__log__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__lognetwork__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__lognetwork__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__lognetworkterminate__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__lognetworkterminate__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__magazinecargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinecargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazines__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazines__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesallturrets__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesallturrets__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesammo__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesammo__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesammocargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesammocargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesammofull__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesammofull__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesdetail__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetail__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesdetailbackpack__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailbackpack__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesdetailuniform__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailuniform__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__magazinesdetailvest__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailvest__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__mapanimadd__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__mapanimadd__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__mapcenteroncamera__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__mapcenteroncamera__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__mapgridposition__object_array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__mapgridposition__object_array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markeralpha__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markeralpha__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerbrush__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerbrush__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerchannel__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerchannel__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markercolor__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markercolor__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerdir__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerdir__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerdrawpriority__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerdrawpriority__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerpolyline__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerpolyline__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerpos__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerpos__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markerpos__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markerpos__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markershadow__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markershadow__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markershape__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markershape__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markersize__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markersize__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markertext__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markertext__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__markertype__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__markertype__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__matrixtranspose__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__matrixtranspose__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__maxload__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__maxload__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__members__team_member__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__members__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menuaction__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuaction__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menuadd__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuadd__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menuchecked__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuchecked__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__menuclear__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menuclear__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__menuclear__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menuclear__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__menucollapse__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menucollapse__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__menudata__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menudata__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__menudelete__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menudelete__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menuenable__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menuenable__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__menuenabled__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuenabled__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__menuexpand__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menuexpand__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__menuhover__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuhover__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menuhover__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuhover__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menupicture__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menupicture__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__menusetaction__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusetaction__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menusetcheck__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusetcheck__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menusetdata__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusetdata__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menusetpicture__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusetpicture__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menusetshortcut__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusetshortcut__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menusettext__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusettext__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menuseturl__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menuseturl__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__menusetvalue__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusetvalue__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__menushortcut__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menushortcut__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menushortcuttext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menushortcuttext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menusize__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menusize__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__menusort__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__menusort__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__menutext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menutext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menuurl__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuurl__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__menuvalue__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__menuvalue__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__mineactive__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__mineactive__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__missiletarget__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__missiletarget__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__missiletargetpos__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__missiletargetpos__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__modparams__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__modparams__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__moonphase__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__moonphase__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__morale__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__morale__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__move3dencamera__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__move3dencamera__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__moveout__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__moveout__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__movetime__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__movetime__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__movetocompleted__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__movetocompleted__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__movetofailed__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__movetofailed__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__name__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__name__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__name__location__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__name__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__namedproperties__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__namedproperties__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__namesound__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__namesound__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestbuilding__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestbuilding__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestbuilding__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestbuilding__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestlocation__array__ret__location(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestlocation__array__ret__location, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestlocations__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestlocations__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestlocationwithdubbing__array__ret__location(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestlocationwithdubbing__array__ret__location, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestmines__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestmines__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestobject__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestobject__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestobjects__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestobjects__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nearestterrainobjects__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nearestterrainobjects__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__needreload__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__needreload__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__needservice__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__needservice__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__netid__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__netid__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__netid__group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__netid__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__nextmenuitemindex__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__nextmenuitemindex__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__not__bool__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__not__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__numberofenginesrtd__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__numberofenginesrtd__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__numbertodate__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__numbertodate__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__objectcurators__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__objectcurators__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__objectfromnetid__string__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__objectfromnetid__string__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__objectparent__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__objectparent__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__onbriefinggroup__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onbriefinggroup__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onbriefingnotes__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onbriefingnotes__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onbriefingplan__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onbriefingplan__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onbriefingteamswitch__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onbriefingteamswitch__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__oncommandmodechanged__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__oncommandmodechanged__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__oneachframe__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__oneachframe__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__ongroupiconclick__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ongroupiconclick__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__ongroupiconoverenter__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverenter__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__ongroupiconoverleave__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverleave__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onhcgroupselectionchanged__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onhcgroupselectionchanged__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onmapsingleclick__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onmapsingleclick__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onplayerconnected__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onplayerconnected__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onplayerdisconnected__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onplayerdisconnected__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onpreloadfinished__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onpreloadfinished__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onpreloadstarted__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onpreloadstarted__code_string__ret__nothing, right_arg);
}

DLLEXPORT void unary__onteamswitch__code_string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__onteamswitch__code_string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__opendlcpage__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__opendlcpage__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__opengps__bool__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__opengps__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__openmap__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__openmap__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__openmap__bool__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__openmap__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__opensteamapp__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__opensteamapp__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__openyoutubevideo__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__openyoutubevideo__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__owner__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__owner__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__param__array__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__param__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__params__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__params__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__parsenumber__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsenumber__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__parsenumber__bool__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsenumber__bool__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__parsesimplearray__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsesimplearray__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__parsetext__string__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__parsetext__string__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__pickweaponpool__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__pickweaponpool__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__pitch__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__pitch__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__playableslotsnumber__side__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playableslotsnumber__side__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__playersnumber__side__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playersnumber__side__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__playmission__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__playmission__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__playmusic__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__playmusic__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__playmusic__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__playmusic__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__playscriptedmission__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__playscriptedmission__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__playsound__string__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsound__string__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__playsound__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsound__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__playsound3d__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsound3d__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__playsoundui__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__playsoundui__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__pose__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__pose__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__position__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__position__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__position__location__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__position__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__positioncameratoworld__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__positioncameratoworld__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ppeffectcommitted__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectcommitted__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ppeffectcommitted__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectcommitted__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ppeffectcreate__array__ret__scalar_array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectcreate__array__ret__scalar_array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ppeffectdestroy__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ppeffectdestroy__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__ppeffectdestroy__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ppeffectdestroy__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ppeffectenabled__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectenabled__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ppeffectenabled__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ppeffectenabled__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__precision__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__precision__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__preloadcamera__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadcamera__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__preloadsound__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadsound__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__preloadtitleobj__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadtitleobj__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__preloadtitlersc__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preloadtitlersc__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__preprocessfile__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preprocessfile__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__preprocessfilelinenumbers__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__preprocessfilelinenumbers__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__primaryweapon__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__primaryweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__primaryweaponitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__primaryweaponitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__primaryweaponmagazine__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__primaryweaponmagazine__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__priority__task__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__priority__task__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__private__string_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__private__string_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__processdiarylink__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__processdiarylink__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__progressloadingscreen__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__progressloadingscreen__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__progressposition__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__progressposition__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__publicvariable__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__publicvariable__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__publicvariableserver__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__publicvariableserver__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__putweaponpool__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__putweaponpool__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__queryitemspool__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__queryitemspool__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__querymagazinepool__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__querymagazinepool__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__queryweaponpool__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__queryweaponpool__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rad__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rad__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__radiochannelcreate__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__radiochannelcreate__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__radiochannelinfo__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__radiochannelinfo__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__random__array__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__random__array__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__random__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__random__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rank__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rank__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rankid__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rankid__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rating__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rating__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rectangular__location__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rectangular__location__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__registeredtasks__team_member__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__registeredtasks__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__reload__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__reload__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__reloadenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__reloadenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__remotecontrolled__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remotecontrolled__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__remoteexec__array__ret__string_nothing(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remoteexec__array__ret__string_nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__remoteexeccall__array__ret__string_nothing(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remoteexeccall__array__ret__string_nothing, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__remove3denconnection__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__remove3denconnection__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__remove3deneventhandler__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__remove3deneventhandler__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__remove3denlayer__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__remove3denlayer__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__removeall3deneventhandlers__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeall3deneventhandlers__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallactions__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallactions__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallassigneditems__object_array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallassigneditems__object_array__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallbinocularitems__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallbinocularitems__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallcontainers__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallcontainers__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallcuratoraddons__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoraddons__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallcuratorcameraareas__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallcuratorcameraareas__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallcuratoreditingareas__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoreditingareas__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallhandgunitems__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallhandgunitems__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallitems__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallitems__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallitemswithmagazines__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallitemswithmagazines__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallmissioneventhandlers__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallmissioneventhandlers__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallmusiceventhandlers__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallmusiceventhandlers__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallownedmines__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallownedmines__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallprimaryweaponitems__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallprimaryweaponitems__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallsecondaryweaponitems__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallsecondaryweaponitems__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removealluseractioneventhandlers__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removealluseractioneventhandlers__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeallweapons__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeallweapons__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removebackpack__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removebackpack__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removebackpackglobal__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removebackpackglobal__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removefromremainscollector__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removefromremainscollector__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__removegoggles__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removegoggles__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeheadgear__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeheadgear__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removemissioneventhandler__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removemissioneventhandler__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__removemusiceventhandler__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removemusiceventhandler__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeswitchableunit__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeswitchableunit__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeuniform__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeuniform__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__removeuseractioneventhandler__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removeuseractioneventhandler__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__removevest__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__removevest__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__requiredversion__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__requiredversion__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__resetsubgroupdirection__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__resetsubgroupdirection__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__resources__team_member__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__resources__team_member__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__restarteditorcamera__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__restarteditorcamera__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__reverse__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__reverse__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__reverse__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__reverse__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__roadat__object_array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__roadat__object_array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__roadsconnectedto__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__roadsconnectedto__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__roledescription__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__roledescription__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropeattachedobjects__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeattachedobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropeattachedto__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeattachedto__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropeattachenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeattachenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropecreate__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropecreate__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ropecut__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ropecut__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__ropedestroy__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ropedestroy__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ropeendposition__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeendposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropelength__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropelength__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropes__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropes__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropesattachedto__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropesattachedto__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__ropesegments__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropesegments__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__ropeunwind__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__ropeunwind__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__ropeunwound__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__ropeunwound__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rotorsforcesrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rotorsforcesrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__rotorsrpmrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__rotorsrpmrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__round__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__round__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__save3deninventory__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__save3deninventory__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__saveoverlay__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__saveoverlay__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__savevar__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__savevar__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__scopename__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__scopename__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__score__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__score__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__scoreside__side__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scoreside__side__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__screenshot__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__screenshot__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__screentoworld__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__screentoworld__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__scriptdone__script__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scriptdone__script__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__scriptname__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__scriptname__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__scudstate__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__scudstate__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__secondaryweapon__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__secondaryweapon__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__secondaryweaponitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__secondaryweaponmagazine__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponmagazine__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__selectbestplaces__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectbestplaces__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__selectededitorobjects__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__selectededitorobjects__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__selectionnames__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectionnames__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__selectionposition__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectionposition__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__selectmax__array__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectmax__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__selectmin__array__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectmin__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__selectplayer__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__selectplayer__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__selectrandom__array__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectrandom__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__selectrandomweighted__array__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__selectrandomweighted__array__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__sendaumessage__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__sendaumessage__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__sendudpmessage__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sendudpmessage__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__servercommand__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__servercommand__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__servercommandavailable__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__servercommandavailable__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__servercommandexecutable__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__servercommandexecutable__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__set3denattributes__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__set3denattributes__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__set3dengrid__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__set3dengrid__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__set3deniconsvisible__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__set3deniconsvisible__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__set3denlinesvisible__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__set3denlinesvisible__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__set3denmissionattributes__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__set3denmissionattributes__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__set3denmodelsvisible__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__set3denmodelsvisible__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__set3denselected__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__set3denselected__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setacctime__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setacctime__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setaperture__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setaperture__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setaperturenew__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setaperturenew__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setarmorypoints__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setarmorypoints__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setcamshakedefparams__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setcamshakedefparams__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setcamshakeparams__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setcamshakeparams__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setcompassoscillation__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setcompassoscillation__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setcuratorselected__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setcuratorselected__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__setcurrentchannel__scalar__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcurrentchannel__scalar__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__setcustommissiondata__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setcustommissiondata__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__setcustomsoundcontroller__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setcustomsoundcontroller__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__setdate__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setdate__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setdefaultcamera__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setdefaultcamera__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setdetailmapblendpars__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setdetailmapblendpars__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setgroupiconsselectable__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsselectable__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__setgroupiconsvisible__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsvisible__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__sethorizonparallaxcoef__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__sethorizonparallaxcoef__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__sethudmovementlevels__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__sethudmovementlevels__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__sethumidity__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__sethumidity__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__setinfopanel__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setinfopanel__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__setlocalwindparams__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setlocalwindparams__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setmouseposition__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setmouseposition__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setmusiceventhandler__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setmusiceventhandler__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setobjectviewdistance__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setobjectviewdistance__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setobjectviewdistance__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setobjectviewdistance__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setpipviewdistance__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setpipviewdistance__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setplayable__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setplayable__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__setplayerrespawntime__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setplayerrespawntime__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setrain__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setrain__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setrain__config__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setrain__config__ret__nothing, right_arg);
}

DLLEXPORT void unary__setshadowdistance__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setshadowdistance__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setsimulweatherlayers__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setsimulweatherlayers__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setstaminascheme__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setstaminascheme__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__setstatvalue__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__setstatvalue__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__setsystemofunits__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setsystemofunits__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setterraingrid__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setterraingrid__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setterrainheight__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setterrainheight__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__settimemultiplier__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__settimemultiplier__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__settiparameter__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__settiparameter__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__settrafficdensity__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__settrafficdensity__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__settrafficdistance__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__settrafficdistance__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__settrafficgap__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__settrafficgap__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__settrafficspeed__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__settrafficspeed__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setviewdistance__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setviewdistance__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__setwind__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setwind__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__setwinddir__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__setwinddir__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__showchat__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showchat__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showcinemaborder__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showcinemaborder__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showcommandingmenu__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showcommandingmenu__string__ret__nothing, right_arg);
}

DLLEXPORT void unary__showcompass__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showcompass__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showcuratorcompass__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showcuratorcompass__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showgps__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showgps__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showhud__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showhud__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showhud__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showhud__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__showmap__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showmap__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showpad__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showpad__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showradio__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showradio__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showscoretable__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showscoretable__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__showsubtitles__bool__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__showsubtitles__bool__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__showuavfeed__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showuavfeed__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showwarrant__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showwarrant__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showwatch__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showwatch__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__showwaypoints__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__showwaypoints__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__side__object__ret__side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__side__object__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__side__group__ret__side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__side__group__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__side__location__ret__side(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__side__location__ret__side, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__simpletasks__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simpletasks__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__simulationenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulationenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__simulclouddensity__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulclouddensity__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__simulcloudocclusion__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulcloudocclusion__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__simulinclouds__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__simulinclouds__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sin__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sin__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__size__location__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__size__location__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sizeof__string__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sizeof__string__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__skill__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__skill__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__skiptime__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__skiptime__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__sleep__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__sleep__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__sliderposition__control__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderposition__control__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sliderposition__scalar__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderposition__scalar__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sliderrange__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderrange__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sliderrange__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderrange__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__slidersetposition__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__slidersetposition__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__slidersetrange__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__slidersetrange__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__slidersetspeed__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__slidersetspeed__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__sliderspeed__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderspeed__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sliderspeed__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sliderspeed__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__soldiermagazines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__soldiermagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__someammo__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__someammo__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__soundparams__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__soundparams__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__speaker__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__speaker__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__speed__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__speed__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__speedmode__object_group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__speedmode__object_group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__sqrt__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__sqrt__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__squadparams__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__squadparams__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__stance__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__stance__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__startloadingscreen__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__startloadingscreen__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__stopenginertd__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__stopenginertd__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__stopped__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__stopped__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__stopsound__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__stopsound__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__str__any__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__str__any__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__supportinfo__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__supportinfo__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__surfaceiswater__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfaceiswater__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__surfacenormal__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfacenormal__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__surfacetexture__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfacetexture__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__surfacetype__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__surfacetype__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__switch__any__ret__switch(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__switch__any__ret__switch, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__switchcamera__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__switchcamera__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__synchronizedobjects__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedobjects__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__synchronizedtriggers__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedtriggers__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__synchronizedwaypoints__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedwaypoints__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__synchronizedwaypoints__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__synchronizedwaypoints__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__systemchat__string__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__systemchat__string__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tan__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tan__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskalwaysvisible__task__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskalwaysvisible__task__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskchildren__task__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskchildren__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskcompleted__task__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskcompleted__task__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskcustomdata__task__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskcustomdata__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskdescription__task__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskdescription__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskdestination__task__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskdestination__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__taskhint__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__taskhint__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__taskmarkeroffset__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskmarkeroffset__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskname__task__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskname__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskparent__task__ret__task(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskparent__task__ret__task, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskresult__task__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskresult__task__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__taskstate__task__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__taskstate__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tasktype__task__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tasktype__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__teammember__object__ret__team_member(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__teammember__object__ret__team_member, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__teamname__team_member__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__teamname__team_member__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__teamtype__team_member__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__teamtype__team_member__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__terminate__script__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__terminate__script__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__terrainintersect__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terrainintersect__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__terrainintersectasl__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terrainintersectasl__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__terrainintersectatasl__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__terrainintersectatasl__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__text__string__ret__text(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__text__string__ret__text, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__text__location__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__text__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__textlog__any__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__textlog__any__ret__nothing, right_arg);
}

DLLEXPORT void unary__textlogformat__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__textlogformat__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tg__scalar_nan__ret__scalar_nan(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tg__scalar_nan__ret__scalar_nan, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__throw__any__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__throw__any__ret__nothing, right_arg);
}

DLLEXPORT void unary__titlecut__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__titlecut__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__titlefadeout__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__titlefadeout__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__titleobj__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__titleobj__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__titlersc__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__titlersc__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__titletext__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__titletext__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__toarray__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toarray__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__toarray__hashmap__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toarray__hashmap__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__tofixed__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tofixed__scalar__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tolower__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tolower__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__toloweransi__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toloweransi__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tostring__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tostring__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tostring__code__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tostring__code__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__toupper__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toupper__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__toupperansi__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__toupperansi__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggeractivated__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggeractivated__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggeractivation__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggeractivation__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__triggerammo__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__triggerammo__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__triggerarea__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerarea__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggerattachedvehicle__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerattachedvehicle__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggerinterval__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerinterval__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggerstatements__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggerstatements__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggertext__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertext__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggertimeout__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertimeout__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggertimeoutcurrent__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertimeoutcurrent__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__triggertype__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__triggertype__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__trim__string__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__trim__string__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__try__code__ret__exception(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__try__code__ret__exception, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvadd__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvadd__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__tvclear__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvclear__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvclear__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvclear__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvcollapse__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvcollapse__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvcollapseall__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvcollapseall__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvcollapseall__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvcollapseall__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tvcount__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvcount__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvcursel__scalar__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvcursel__scalar__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvcursel__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvcursel__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvdata__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvdata__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__tvdelete__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvdelete__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvexpand__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvexpand__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvexpandall__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvexpandall__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvexpandall__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvexpandall__control__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tvpicture__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvpicture__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvpictureright__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvpictureright__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvselection__control__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvselection__control__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__tvsetcursel__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetcursel__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsetdata__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetdata__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsetpicture__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetpicture__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsetpicturecolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetpicturecolor__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsetpictureright__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetpictureright__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsetpicturerightcolor__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetpicturerightcolor__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tvsettext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvsettext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__tvsettooltip__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsettooltip__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsetvalue__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsetvalue__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsort__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsort__array__ret__nothing, right_arg);
}

DLLEXPORT void unary__tvsortbyvalue__array__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__tvsortbyvalue__array__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__tvtext__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvtext__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvtooltip__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvtooltip__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__tvvalue__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__tvvalue__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__type__task__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__type__task__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__type__location__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__type__location__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__typename__any__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__typename__any__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__typeof__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__typeof__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__uavcontrol__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uavcontrol__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__uisleep__scalar__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__uisleep__scalar__ret__nothing, right_arg);
}

DLLEXPORT void unary__unassigncurator__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__unassigncurator__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__unassignteam__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__unassignteam__object__ret__nothing, right_arg);
}

DLLEXPORT void unary__unassignvehicle__object__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__unassignvehicle__object__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__underwater__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__underwater__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__uniform__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniform__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__uniformcontainer__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniformcontainer__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__uniformitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniformitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__uniformmagazines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniformmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__uniqueunititems__object_array__ret__hashmap(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__uniqueunititems__object_array__ret__hashmap, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitaddons__string__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitaddons__string__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitaimposition__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitaimposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitaimpositionvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitaimpositionvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitbackpack__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitbackpack__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitcombatmode__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitcombatmode__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitisuav__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitisuav__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitpos__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitpos__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitready__object_array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitready__object_array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unitrecoilcoefficient__object__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unitrecoilcoefficient__object__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__units__group__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__units__group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__units__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__units__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__units__side__ret__any(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__units__side__ret__any, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__unlockachievement__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__unlockachievement__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__updateobjecttree__control__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__updateobjecttree__control__ret__nothing, right_arg);
}

DLLEXPORT void unary__useaiopermapobstructiontest__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__useaiopermapobstructiontest__bool__ret__nothing, right_arg);
}

DLLEXPORT void unary__useaisteeringcomponent__bool__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__useaisteeringcomponent__bool__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__values__hashmap__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__values__hashmap__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectordir__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectordir__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectordirvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectordirvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectorlinearconversion__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorlinearconversion__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectormagnitude__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectormagnitude__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectormagnitudesqr__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectormagnitudesqr__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectornormalized__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectornormalized__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectorside__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorside__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectorsidevisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorsidevisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectorup__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorup__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vectorupvisual__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vectorupvisual__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehicle__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehicle__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehiclecargoenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclecargoenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehiclemoveinfo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclemoveinfo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehiclereceiveremotetargets__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclereceiveremotetargets__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehiclereportownposition__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclereportownposition__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehiclereportremotetargets__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclereportremotetargets__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vehiclevarname__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vehiclevarname__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__velocity__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__velocity__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__velocitymodelspace__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__velocitymodelspace__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__verifysignature__string__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__verifysignature__string__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vest__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vest__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vestcontainer__object__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vestcontainer__object__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vestitems__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vestitems__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__vestmagazines__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__vestmagazines__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__visibleposition__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__visibleposition__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__visiblepositionasl__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__visiblepositionasl__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void unary__waituntil__code__ret__nothing(game_value right_arg)
{
	host::functions.invoke_raw_unary(__sqf::unary__waituntil__code__ret__nothing, right_arg);
}

DLLEXPORT game_value unary__waterdamaged__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waterdamaged__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointattachedobject__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointattachedobject__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointattachedvehicle__array__ret__object(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointattachedvehicle__array__ret__object, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointbehaviour__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointbehaviour__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointcombatmode__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointcombatmode__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointcompletionradius__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointcompletionradius__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointdescription__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointdescription__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointforcebehaviour__array__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointforcebehaviour__array__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointformation__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointformation__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointhouseposition__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointhouseposition__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointloiteraltitude__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointloiteraltitude__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointloiterradius__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointloiterradius__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointloitertype__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointloitertype__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointname__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointname__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointposition__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointposition__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypoints__object_group__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypoints__object_group__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointscript__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointscript__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointsenableduav__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointsenableduav__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointshow__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointshow__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointspeed__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointspeed__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointstatements__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointstatements__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointtimeout__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointtimeout__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointtimeoutcurrent__group__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointtimeoutcurrent__group__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointtype__array__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointtype__array__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__waypointvisible__array__ret__scalar(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__waypointvisible__array__ret__scalar, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponcargo__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponcargo__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weapondisassemblyenabled__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weapondisassemblyenabled__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponinertia__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponinertia__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponlowered__object__ret__bool(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponlowered__object__ret__bool, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weapons__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weapons__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponsitems__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponsitems__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponsitemscargo__object_array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponsitemscargo__object_array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponstate__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponstate__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weaponstate__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weaponstate__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__weightrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__weightrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__wfsidetext__side__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__wfsidetext__side__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__wfsidetext__object__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__wfsidetext__object__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__wfsidetext__group__ret__string(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__wfsidetext__group__ret__string, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__while__code__ret__while(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__while__code__ret__while, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__wingsforcesrtd__object__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__wingsforcesrtd__object__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__with__namespace__ret__with(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__with__namespace__ret__with, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value unary__worldtoscreen__array__ret__array(game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_unary(__sqf::unary__worldtoscreen__array__ret__array, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__action__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__action__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__actionparams__object__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__actionparams__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__add3denlayer__scalar__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__add3denlayer__scalar__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__addaction__object__array__ret__nothing_scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addaction__object__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__addbackpack__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addbackpack__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addbackpackcargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addbackpackcargoglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargoglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addbackpackglobal__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addbackpackglobal__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addbinocularitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addbinocularitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addcuratoraddons__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addcuratoraddons__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addcuratorcameraarea__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addcuratorcameraarea__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addcuratoreditableobjects__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditableobjects__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addcuratoreditingarea__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditingarea__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addcuratorpoints__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addcuratorpoints__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__addeditorobject__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addeditorobject__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__addeventhandler__object__array__ret__nothing_scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addeventhandler__object__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__addeventhandler__group__array__ret__nothing_scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addeventhandler__group__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__addforce__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addforce__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addgoggles__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addgoggles__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__addgroupicon__group__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addgroupicon__group__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__addhandgunitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addhandgunitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addheadgear__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addheadgear__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__additem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__additem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__additemcargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__additemcargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__additemcargoglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__additemcargoglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__additemtobackpack__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__additemtobackpack__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__additemtouniform__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__additemtouniform__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__additemtovest__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__additemtovest__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addlivestats__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addlivestats__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazine__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazine__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazine__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazine__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazineammocargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazineammocargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazinecargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazinecargoglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargoglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazineglobal__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazineglobal__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazines__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazines__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addmagazineturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addmagazineturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__addmenu__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmenu__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__addmenuitem__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmenuitem__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__addmpeventhandler__object__array__ret__nothing_scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addmpeventhandler__object__array__ret__nothing_scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__addownedmine__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addownedmine__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addplayerscores__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addplayerscores__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addprimaryweaponitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addprimaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addpublicvariableeventhandler__string__code__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addpublicvariableeventhandler__string__code__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addpublicvariableeventhandler__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addpublicvariableeventhandler__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addrating__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addrating__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addresources__team_member__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addresources__team_member__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addscore__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addscore__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addscoreside__side__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addscoreside__side__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addsecondaryweaponitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addsecondaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addteammember__team_member__team_member__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addteammember__team_member__team_member__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addtorque__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addtorque__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__adduniform__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__adduniform__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addvehicle__group__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addvehicle__group__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addvest__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addvest__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__addwaypoint__group__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__addwaypoint__group__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__addweapon__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweapon__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponcargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponcargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponcargoglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponcargoglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponglobal__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponglobal__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponitem__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponitem__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponwithattachmentscargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__addweaponwithattachmentscargoglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargoglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__aimedattarget__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__aimedattarget__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__alldiaryrecords__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__alldiaryrecords__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__allobjects__scalar__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allobjects__scalar__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__allobjects__string__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__allobjects__string__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__allow3dmode__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allow3dmode__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowcrewinimmobile__object__bool_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowcrewinimmobile__object__bool_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowcuratorlogicignoreareas__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowcuratorlogicignoreareas__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowdamage__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowdamage__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowdammage__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowdammage__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowfileoperations__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowfileoperations__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowfleeing__object_group__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowfleeing__object_group__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowgetin__array__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowgetin__array__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowservice__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowservice__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__allowsprint__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__allowsprint__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ammo__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ammo__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ammoonpylon__object__string_scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ammoonpylon__object__string_scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__and__bool__bool__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__and__bool__bool__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__and__bool__code__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__and__bool__code__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__animate__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__animate__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__animatebay__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__animatebay__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__animatedoor__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__animatedoor__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__animatepylon__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__animatepylon__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__animatesource__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__animatesource__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__animationphase__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animationphase__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__animationsourcephase__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__animationsourcephase__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__append__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__append__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__apply__array__code__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__apply__array__code__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__apply__hashmap__code__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__apply__hashmap__code__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__arrayintersect__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__arrayintersect__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__assignascargo__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignascargo__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignascargoindex__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignascargoindex__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignascommander__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignascommander__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignasdriver__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignasdriver__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignasgunner__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignasgunner__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignasturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignasturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assigncurator__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assigncurator__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assignteam__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assignteam__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__assigntoairport__object__object_scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__assigntoairport__object__object_scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__atan2__scalar_nan__scalar_nan__ret__scalar_nan(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__atan2__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__attachobject__location__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__attachobject__location__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__attachto__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__attachto__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__awake__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__awake__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__backpackspacefor__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__backpackspacefor__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__bezierinterpolation__scalar__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__bezierinterpolation__scalar__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__boundingbox__scalar__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__boundingbox__scalar__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__boundingboxreal__scalar__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__boundingboxreal__scalar__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__breakout__any__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__breakout__any__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__buildingexit__object__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__buildingexit__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__buildingpos__object__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__buildingpos__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__buttonsetaction__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__buttonsetaction__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__call__any__code__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__call__any__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__call__hashmap__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__call__hashmap__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__callextension__string__string__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__callextension__string__string__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__callextension__string__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__callextension__string__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__camcommand__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camcommand__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camcommit__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camcommit__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camcommitprepared__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camcommitprepared__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camconstuctionsetparams__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camconstuctionsetparams__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__camcreate__string__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__camcreate__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__cameraeffect__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__cameraeffect__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreload__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreload__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparebank__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparebank__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparedir__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparedir__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparedive__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparedive__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparefocus__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparefocus__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparefov__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparefov__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparefovrange__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparefovrange__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparepos__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparepos__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparerelpos__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparerelpos__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparetarget__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparetarget__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__campreparetarget__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__campreparetarget__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetbank__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetbank__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetdir__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetdir__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetdive__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetdive__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetfocus__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetfocus__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetfov__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetfov__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetfovrange__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetfovrange__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetpos__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetpos__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsetrelpos__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsetrelpos__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsettarget__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsettarget__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__camsettarget__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__camsettarget__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__canadd__object__string_array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadd__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canadd__string__string_array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadd__string__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canadditemtobackpack__object__string_array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadditemtobackpack__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canadditemtouniform__object__string_array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadditemtouniform__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canadditemtovest__object__string_array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canadditemtovest__object__string_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canslingload__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canslingload__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canslingload__string__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canslingload__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__canvehiclecargo__object__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__canvehiclecargo__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__catch__exception__code__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__catch__exception__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__cbsetchecked__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__cbsetchecked__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__checkaifeature__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__checkaifeature__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__checkvisibility__array__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__checkvisibility__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__clear3denattribute__any__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__clear3denattribute__any__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__closedisplay__display__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__closedisplay__display__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__collect3denhistory__array__code__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__collect3denhistory__array__code__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandartilleryfire__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandchat__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandchat__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandfire__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandfire__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandfollow__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandfollow__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandfsm__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandfsm__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandmove__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandmove__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandradio__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandradio__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandsuppressivefire__object_array__object_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandsuppressivefire__object_array__object_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandtarget__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandtarget__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandwatch__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandwatch__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__commandwatch__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__commandwatch__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__configaccessor__config__string__ret__config(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__configaccessor__config__string__ret__config, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__configclasses__string__config__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__configclasses__string__config__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__confirmsensortarget__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__confirmsensortarget__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__connectterminaltouav__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__connectterminaltouav__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__controlsgroupctrl__control__scalar__ret__control(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__controlsgroupctrl__control__scalar__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__copywaypoints__group__group__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__copywaypoints__group__group__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__count__code__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__count__code__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__countenemy__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countenemy__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__countfriendly__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countfriendly__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__countside__side__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countside__side__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__counttype__string__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__counttype__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__countunknown__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__countunknown__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__create3denentity__group__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__create3denentity__group__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__creatediaryrecord__object__array__ret__diary_record(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__creatediaryrecord__object__array__ret__diary_record, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__creatediarysubject__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__creatediarysubject__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createdisplay__display__string__ret__display(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createdisplay__display__string__ret__display, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createhashmapfromarray__array__array__ret__hashmap(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createhashmapfromarray__array__array__ret__hashmap, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__createmenu__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__createmenu__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__createmissiondisplay__display__string__ret__display(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createmissiondisplay__display__string__ret__display, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createmissiondisplay__display__array__ret__display(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createmissiondisplay__display__array__ret__display, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__creatempcampaigndisplay__display__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__creatempcampaigndisplay__display__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__createsimpletask__object__array__ret__task(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createsimpletask__object__array__ret__task, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createsite__string__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createsite__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createtask__team_member__array__ret__task(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createtask__team_member__array__ret__task, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__createunit__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__createunit__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__createunit__group__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createunit__group__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createvehicle__string__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createvehicle__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createvehiclecrew__group__object__ret__group(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createvehiclecrew__group__object__ret__group, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createvehiclecrew__side__object__ret__group(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createvehiclecrew__side__object__ret__group, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__createvehiclelocal__string__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__createvehiclelocal__string__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ctdata__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctdata__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ctfindheaderrows__control__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctfindheaderrows__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ctfindrowheader__control__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctfindrowheader__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ctheadercontrols__control__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctheadercontrols__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctremoveheaders__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctremoveheaders__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctremoverows__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctremoverows__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrladdeventhandler__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrladdeventhandler__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctrlanimatemodel__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlanimatemodel__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrlanimationphasemodel__control__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlanimationphasemodel__control__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ctrlat__display__array__ret__control(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlat__display__array__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__ctrlchecked__control__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlchecked__control__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctrlcommit__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlcommit__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrlcreate__display__array__ret__control(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlcreate__display__array__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctrlenable__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlenable__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlmapanimadd__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlmapanimadd__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlmapcursor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlmapcursor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrlmapscreentoworld__control__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapscreentoworld__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctrlmapsetposition__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlmapsetposition__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrlmapworldtoscreen__control__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlmapworldtoscreen__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctrlremovealleventhandlers__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlremovealleventhandlers__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlremoveeventhandler__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlremoveeventhandler__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetactivecolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetactivecolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetangle__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetangle__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetautoscrolldelay__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrolldelay__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetautoscrollrewind__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollrewind__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetautoscrollspeed__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollspeed__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetbackgroundcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetbackgroundcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetchecked__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetchecked__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetchecked__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetchecked__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetdisabledcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetdisabledcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlseteventhandler__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlseteventhandler__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfade__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfade__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfont__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfont__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth1__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth1b__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1b__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth2__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth2b__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2b__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth3__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth3b__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3b__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth4__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth4b__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4b__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth5__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth5b__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5b__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth6__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfonth6b__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6b__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheight__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheight__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheighth1__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth1__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheighth2__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth2__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheighth3__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth3__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheighth4__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth4__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheighth5__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth5__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheighth6__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth6__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontheightsecondary__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheightsecondary__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontp__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontp__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontp__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontp__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontpb__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontpb__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetfontsecondary__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontsecondary__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetforegroundcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetforegroundcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetmodel__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodel__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetmodeldirandup__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodeldirandup__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetmodelscale__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodelscale__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetmouseposition__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmouseposition__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetpixelprecision__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpixelprecision__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetpixelprecision__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpixelprecision__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetposition__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetposition__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetpositionh__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionh__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetpositionw__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionw__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetpositionx__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionx__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetpositiony__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositiony__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetscale__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscale__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetscrollvalues__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscrollvalues__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetshadow__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetshadow__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsetstructuredtext__control__text__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsetstructuredtext__control__text__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettext__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettext__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettextcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettextcolorsecondary__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolorsecondary__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettextsecondary__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextsecondary__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettextselection__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextselection__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettooltip__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltip__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettooltipcolorbox__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorbox__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettooltipcolorshade__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorshade__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlsettooltipcolortext__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolortext__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrlsettooltipmaxwidth__control__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipmaxwidth__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctrlseturl__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlseturl__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlseturloverlaymode__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlseturloverlaymode__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctrlshow__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctrlshow__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctrowcontrols__control__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctrowcontrols__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ctsetcursel__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctsetcursel__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctsetdata__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctsetdata__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctsetheadertemplate__control__config__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctsetheadertemplate__control__config__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctsetrowtemplate__control__config__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctsetrowtemplate__control__config__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ctsetvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ctsetvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ctvalue__control__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ctvalue__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__curatorcoef__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__curatorcoef__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__currentmagazinedetailturret__object__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentmagazinedetailturret__object__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__currentmagazineturret__object__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentmagazineturret__object__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__currentvisionmode__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentvisionmode__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__currentvisionmode__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentvisionmode__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__currentweaponturret__object__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentweaponturret__object__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__currentzeroing__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__currentzeroing__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__customchat__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__customchat__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__customradio__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__customradio__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__cutfadeout__string__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cutfadeout__string__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__cutfadeout__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__cutfadeout__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__cutobj__string__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cutobj__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__cutobj__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__cutobj__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__cutrsc__string__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cutrsc__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__cutrsc__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__cutrsc__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__cuttext__string__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__cuttext__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__cuttext__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__cuttext__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__debugfsm__scalar__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__debugfsm__scalar__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__deleteat__array__scalar__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleteat__array__scalar__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__deleteat__hashmap__side_config__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleteat__hashmap__side_config__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__deleteeditorobject__control__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__deleteeditorobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__deletegroupwhenempty__group__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__deletegroupwhenempty__group__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__deleterange__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__deleterange__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__deleteresources__team_member__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__deleteresources__team_member__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__deletevehiclecrew__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__deletevehiclecrew__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__diag_enable__string__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__diag_enable__string__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__diarysubjectexists__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__diarysubjectexists__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__directionstabilizationenabled__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__directionstabilizationenabled__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__directsay__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__directsay__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disableai__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disableai__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disablebrakes__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disablebrakes__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disablecollisionwith__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disablecollisionwith__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disableconversation__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disableconversation__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disablenvgequipment__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disablenvgequipment__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disabletiequipment__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disabletiequipment__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__disableuavconnectability__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__disableuavconnectability__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__displayaddeventhandler__display__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayaddeventhandler__display__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__displayctrl__display__scalar__ret__control(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__displayctrl__display__scalar__ret__control, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__displayremovealleventhandlers__display__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__displayremovealleventhandlers__display__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__displayremoveeventhandler__display__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__displayremoveeventhandler__display__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__displayseteventhandler__display__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__displayseteventhandler__display__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__distance__object_array__object_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distance__location__location__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance__location__location__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distance__location__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance__location__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distance__array__location__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance__array__location__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distance2d__object_array__object_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distance2d__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distancesqr__object_array__object_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distancesqr__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distancesqr__location__location__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distancesqr__location__location__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distancesqr__location__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distancesqr__location__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__distancesqr__array__location__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__distancesqr__array__location__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__do__while__code__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__do__while__code__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__do__with__code__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__do__with__code__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__do__for__code__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__do__for__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__do__switch__code__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__do__switch__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__doartilleryfire__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__doartilleryfire__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__dofire__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dofire__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__dofollow__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dofollow__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__dofsm__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dofsm__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__domove__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__domove__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__doorphase__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__doorphase__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__dosuppressivefire__object_array__object_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dosuppressivefire__object_array__object_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__dotarget__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dotarget__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__dowatch__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dowatch__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__dowatch__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__dowatch__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawarrow__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawarrow__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawellipse__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawellipse__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawicon__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawicon__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawline__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawline__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawlink__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawlink__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawlocation__control__location__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawlocation__control__location__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawpolygon__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawpolygon__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawrectangle__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawrectangle__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__drawtriangle__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__drawtriangle__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__editobject__control__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__editobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__editorseteventhandler__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__editorseteventhandler__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__elevateperiscope__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__elevateperiscope__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__else__code__code__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__else__code__code__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__emptypositions__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__emptypositions__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__enableai__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableai__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableaifeature__string__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableaifeature__string__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableaifeature__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableaifeature__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableaimprecision__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableaimprecision__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableattack__object_group__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableattack__object_group__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__enableaudiofeature__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableaudiofeature__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__enableautostartuprtd__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableautostartuprtd__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__enableautotrimrtd__object__bool__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableautotrimrtd__object__bool__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__enablechannel__scalar__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablechannel__scalar__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablechannel__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablechannel__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablecollisionwith__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablecollisionwith__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablecopilot__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablecopilot__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enabledirectionstabilization__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enabledirectionstabilization__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enabledynamicsimulation__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enabledynamicsimulation__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enabledynamicsimulation__group__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enabledynamicsimulation__group__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablefatigue__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablefatigue__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablegunlights__object_group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablegunlights__object_group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__enableinfopanelcomponent__object_array__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__enableinfopanelcomponent__object_array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__enableirlasers__object_group__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableirlasers__object_group__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablemimics__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablemimics__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablepersonturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablepersonturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablereload__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablereload__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableropeattach__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableropeattach__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablesimulation__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablesimulation__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablesimulationglobal__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablesimulationglobal__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablestamina__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablestamina__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableuavconnectability__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableuavconnectability__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableuavwaypoints__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableuavwaypoints__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablevehiclecargo__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablevehiclecargo__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enablevehiclesensor__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enablevehiclesensor__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__enableweapondisassembly__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__enableweapondisassembly__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__engineon__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__engineon__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__evalobjectargument__control__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__evalobjectargument__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__exec__any__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__exec__any__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__execeditorscript__control__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__execeditorscript__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__execfsm__any__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__execfsm__any__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__execvm__any__string__ret__script(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__execvm__any__string__ret__script, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__exitwith__if__code__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__exitwith__if__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__fadeenvironment__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__fadeenvironment__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__fademusic__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__fademusic__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__faderadio__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__faderadio__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__fadesound__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__fadesound__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__fadespeech__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__fadespeech__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__find__array__any__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__find__array__any__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__find__string__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__find__string__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__find__string__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__find__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findany__array__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findany__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findcover__object__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findcover__object__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findeditorobject__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findeditorobject__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findeditorobject__control__any__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findeditorobject__control__any__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findemptyposition__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findemptyposition__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findemptypositionready__array__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findemptypositionready__array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findif__array__code__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findif__array__code__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__findnearestenemy__object__object_array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__findnearestenemy__object__object_array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__fire__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__fire__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__fire__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__fire__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__fireattarget__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__fireattarget__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__flyinheight__object__scalar_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__flyinheight__object__scalar_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__flyinheightasl__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__flyinheightasl__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forceadduniform__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forceadduniform__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forceflagtexture__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forceflagtexture__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forcefollowroad__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forcefollowroad__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forcespeed__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forcespeed__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forcewalk__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forcewalk__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forceweaponfire__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forceweaponfire__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__foreach__code__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__foreach__code__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__foreach__code__hashmap__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__foreach__code__hashmap__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__foreachmember__code__team_member__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__foreachmember__code__team_member__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__foreachmemberagent__code__team_member__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__foreachmemberagent__code__team_member__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__foreachmemberteam__code__team_member__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__foreachmemberteam__code__team_member__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__foreachreversed__code__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__foreachreversed__code__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__forgettarget__object_group__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__forgettarget__object_group__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__from__for__scalar__ret__for(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__from__for__scalar__ret__for, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get__hashmap__side_config__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get__hashmap__side_config__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get3denattribute__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get3denattribute__group__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__group__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get3denattribute__array__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__array__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get3denattribute__string__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__string__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get3denattribute__scalar__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__scalar__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__get3denmissionattribute__string__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__get3denmissionattribute__string__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getartilleryeta__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getartilleryeta__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getcargoindex__object__object__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getcargoindex__object__object__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getcompatiblepylonmagazines__object__string_scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getcompatiblepylonmagazines__object__string_scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getcompatiblepylonmagazines__string__string_scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getcompatiblepylonmagazines__string__string_scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getdir__object_array__object_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getdir__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getdirvisual__object_array__object_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getdirvisual__object_array__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__geteditorobjectscope__control__string__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__geteditorobjectscope__control__string__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getenv3dsoundcontroller__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getenv3dsoundcontroller__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getenvsoundcontroller__array__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getenvsoundcontroller__array__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__geteventhandlerinfo__object_group__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__geteventhandlerinfo__object_group__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getfriend__side__side__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getfriend__side__side__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getfsmvariable__scalar__string_array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getfsmvariable__scalar__string_array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getgroupicon__group__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getgroupicon__group__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__gethidefrom__object__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethidefrom__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__gethit__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethit__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__gethitindex__object__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethitindex__object__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__gethitpointdamage__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gethitpointdamage__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getobjectargument__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getobjectargument__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getobjectchildren__control__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getobjectchildren__control__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getobjectproxy__control__string__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getobjectproxy__control__string__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getopticsmode__object__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getopticsmode__object__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getordefault__hashmap__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getordefault__hashmap__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getordefaultcall__hashmap__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getordefaultcall__hashmap__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getpos__object_array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getpos__object_array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getreldir__object__object_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getreldir__object__object_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getrelpos__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getrelpos__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getrelpos__object__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getrelpos__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getslotitemname__object__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getslotitemname__object__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getsoundcontroller__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getsoundcontroller__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getsoundcontrollerresult__object__config__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getsoundcontrollerresult__object__config__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getspeed__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getspeed__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__gettextwidth__string__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__gettextwidth__string__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getturretlimits__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getturretlimits__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__getturretopticsmode__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__getturretopticsmode__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__getunittrait__object__string__ret__nothing_bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getunittrait__object__string__ret__nothing_bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__display__string_array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__display__string_array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__control__string_array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__control__string_array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__object__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__object__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__object__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__object__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__group__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__group__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__group__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__group__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__namespace__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__namespace__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__namespace__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__namespace__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__team_member__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__team_member__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__team_member__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__team_member__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__task__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__task__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__task__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__task__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__location__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__location__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__getvariable__location__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__getvariable__location__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__glanceat__object_array__object_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__glanceat__object_array__object_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__globalchat__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__globalchat__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__globalradio__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__globalradio__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__groupchat__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__groupchat__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__groupradio__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__groupradio__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__groupselectunit__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__groupselectunit__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__hasweapon__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hasweapon__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__hcgroupparams__object__group__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__hcgroupparams__object__group__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__hcremovegroup__object__group__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hcremovegroup__object__group__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hcselectgroup__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hcselectgroup__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hcsetgroup__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hcsetgroup__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hideobject__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hideobject__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hideobjectglobal__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hideobjectglobal__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hideselection__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hideselection__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hintc__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hintc__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hintc__string__text__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hintc__string__text__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__hintc__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__hintc__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__htmlload__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__htmlload__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__in__any__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__in__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__in__string__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__in__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__in__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__in__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__in__side_config__hashmap__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__in__side_config__hashmap__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__in__array__location__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__in__array__location__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inarea__object_array__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inarea__object_array__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inarea__object_array__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inarea__object_array__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inarea__object_array__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inarea__object_array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inarea__object__location__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inarea__object__location__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inarea__array__location__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inarea__array__location__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarray__array__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarray__array__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarray__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarray__array__location__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__location__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarrayindexes__array__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarrayindexes__array__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarrayindexes__array__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarrayindexes__array__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarrayindexes__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarrayindexes__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inareaarrayindexes__array__location__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inareaarrayindexes__array__location__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__inflame__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__inflame__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__infopanelcomponentenabled__object_array__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponentenabled__object_array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__infopanelcomponents__object_array__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponents__object_array__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inpolygon__object_array__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inpolygon__object_array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__inrangeofartillery__array__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inrangeofartillery__array__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__insert__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__insert__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__insert__string__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__insert__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__insert__hashmap__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__insert__hashmap__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__inserteditorobject__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__inserteditorobject__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__intersect__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__intersect__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequalref__any__any__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequalref__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequalto__any__any__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequalto__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequaltype__any__any__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltype__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequaltypeall__any__any__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypeall__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequaltypeany__any__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypeany__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequaltypearray__any__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypearray__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isequaltypeparams__any__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isequaltypeparams__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isflashlighton__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isflashlighton__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isflatempty__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isflatempty__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isirlaseron__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isirlaseron__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__iskindof__string__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__iskindof__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__iskindof__string__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__iskindof__string__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__iskindof__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__iskindof__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__islaseron__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__islaseron__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isnotequalref__any__any__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isnotequalref__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isnotequalto__any__any__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isnotequalto__any__any__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__issensortargetconfirmed__object__side__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__issensortargetconfirmed__object__side__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isuavconnectable__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isuavconnectable__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isuniformallowed__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isuniformallowed__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__isvehiclesensorenabled__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__isvehiclesensorenabled__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__join__array__object_group__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__join__array__object_group__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__joinas__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__joinas__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__joinassilent__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__joinassilent__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__joinsilent__array__object_group__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__joinsilent__array__object_group__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__joinstring__array__string__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__joinstring__array__string__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__kbadddatabase__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbadddatabase__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__kbadddatabasetargets__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbadddatabasetargets__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__kbaddtopic__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__kbaddtopic__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__kbhastopic__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbhastopic__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__kbreact__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__kbreact__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__kbremovetopic__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__kbremovetopic__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__kbtell__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__kbtell__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__kbwassaid__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__kbwassaid__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__knowsabout__object_group__object__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__knowsabout__object_group__object__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__knowsabout__side__object__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__knowsabout__side__object__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__land__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__land__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__landat__object__object_scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__landat__object__object_scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__lasertarget__object__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lasertarget__object__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbadd__control__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbadd__control__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbcolor__control__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbcolor__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbcolorright__control__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbcolorright__control__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbdata__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbdata__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__lbdelete__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbdelete__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__lbisselected__control__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbisselected__control__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbpicture__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbpicture__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbpictureright__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbpictureright__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__lbsetcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetcolorright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetcolorright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetcursel__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetcursel__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetdata__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetdata__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicture__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicture__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicturecolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicturecolordisabled__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolordisabled__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicturecolorselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolorselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpictureright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpictureright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicturerightcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicturerightcolordisabled__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolordisabled__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetpicturerightcolorselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolorselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetselectcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetselectcolorright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolorright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsettext__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsettext__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsettextright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsettextright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsettooltip__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsettooltip__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsetvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsetvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lbsortby__control_scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lbsortby__control_scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__lbtext__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbtext__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbtextright__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbtextright__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbtooltip__control__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbtooltip__control__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lbvalue__control__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lbvalue__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__leavevehicle__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__leavevehicle__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__leavevehicle__group__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__leavevehicle__group__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lightattachobject__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lightattachobject__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__limitspeed__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__limitspeed__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__linkitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__linkitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__listobjects__control__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__listobjects__control__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbaddcolumn__control__scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbaddcolumn__control__scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbaddrow__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbaddrow__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbcolor__control__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbcolor__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbcolorright__control__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbcolorright__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbdata__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbdata__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__lnbdeletecolumn__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbdeletecolumn__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbdeleterow__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbdeleterow__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__lnbpicture__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbpicture__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbpictureright__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbpictureright__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__lnbsetcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetcolorright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolorright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetcolumnspos__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolumnspos__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetcurselrow__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetcurselrow__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetdata__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetdata__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetpicture__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicture__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetpicturecolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetpicturecolorright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetpicturecolorselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetpicturecolorselectedright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselectedright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetpictureright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetpictureright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsettext__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsettext__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsettextright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsettextright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsettooltip__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsettooltip__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsetvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsetvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsort__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsort__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsortby__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsortby__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lnbsortbyvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lnbsortbyvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__lnbtext__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbtext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbtextright__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbtextright__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lnbvalue__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lnbvalue__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__loadidentity__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__loadidentity__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__loadmagazine__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__loadmagazine__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__loadoverlay__control__config__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__loadoverlay__control__config__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__loadstatus__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__loadstatus__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__lock__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lock__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lock__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lock__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lockcamerato__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockcamerato__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lockcargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockcargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lockcargo__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockcargo__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lockdriver__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockdriver__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__lockedcamerato__object__array__ret__nothing_object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockedcamerato__object__array__ret__nothing_object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lockedcargo__object__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockedcargo__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__lockedturret__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__lockedturret__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__lockinventory__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockinventory__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lockturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lockwp__object_group__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lockwp__object_group__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lookat__object_array__object_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lookat__object_array__object_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__lookatpos__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__lookatpos__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__magazinesturret__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__magazinesturret__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__magazineturretammo__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__magazineturretammo__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__mapcenteroncamera__control__bool__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__mapcenteroncamera__control__bool__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__matrixmultiply__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__matrixmultiply__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__max__scalar_nan__scalar_nan__ret__scalar_nan(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__max__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menuaction__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuaction__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menuadd__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuadd__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menuchecked__control__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuchecked__control__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__menucollapse__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menucollapse__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__menudata__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menudata__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__menudelete__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menudelete__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menuenable__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menuenable__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__menuenabled__control__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuenabled__control__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__menuexpand__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menuexpand__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__menupicture__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menupicture__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__menusetaction__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusetaction__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menusetcheck__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusetcheck__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menusetdata__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusetdata__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menusetpicture__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusetpicture__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menusetshortcut__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusetshortcut__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menusettext__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusettext__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menuseturl__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menuseturl__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__menusetvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusetvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__menushortcut__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menushortcut__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menushortcuttext__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menushortcuttext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menusize__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menusize__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__menusort__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__menusort__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__menutext__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menutext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menuurl__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuurl__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__menuvalue__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__menuvalue__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__merge__hashmap__hashmap_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__merge__hashmap__hashmap_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__min__scalar_nan__scalar_nan__ret__scalar_nan(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__min__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__minedetectedby__object__side__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__minedetectedby__object__side__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__mod__scalar_nan__scalar_nan__ret__scalar_nan(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__mod__scalar_nan__scalar_nan__ret__scalar_nan, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__modeltoworld__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__modeltoworldvisual__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__modeltoworldvisualworld__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisualworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__modeltoworldworld__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__modeltoworldworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__move__object_group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__move__object_group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__moveinany__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__moveinany__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__moveincargo__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveincargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveincommander__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveincommander__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveindriver__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveindriver__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveingunner__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveingunner__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveinturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveinturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveobjecttoend__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveobjecttoend__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveout__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveout__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__moveto__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__moveto__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__namedproperties__object__array__ret__hashmap(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__namedproperties__object__array__ret__hashmap, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearentities__object_array__scalar_array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearentities__object_array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearestobject__array__string__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearestobject__array__string__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearestobject__array__scalar__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearestobject__array__scalar__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearobjects__object_array__scalar_array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearobjectsready__object_array__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearobjectsready__object_array__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearroads__object_array__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearroads__object_array__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__nearsupplies__object_array__scalar_array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nearsupplies__object_array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__neartargets__object__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__neartargets__object__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__newoverlay__control__config__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__newoverlay__control__config__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__nmenuitems__control__string_scalar__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__nmenuitems__control__string_scalar__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__objstatus__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__objstatus__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__ondoubleclick__control__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__ondoubleclick__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__onmapsingleclick__any__code_string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__onmapsingleclick__any__code_string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__onshownewobject__control__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__onshownewobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__or__bool__bool__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__or__bool__bool__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__or__bool__code__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__or__bool__code__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ordergetin__array__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ordergetin__array__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__param__any__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__param__any__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__params__any__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__params__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__periscopeelevation__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__periscopeelevation__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__playaction__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__playaction__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__playactionnow__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__playactionnow__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__playgesture__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__playgesture__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__playmove__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__playmove__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__playmovenow__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__playmovenow__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__posscreentoworld__control__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__posscreentoworld__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__posworldtoscreen__control__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__posworldtoscreen__control__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__ppeffectadjust__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectadjust__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectadjust__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectadjust__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectcommit__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectcommit__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectcommit__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectcommit__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectcommit__array__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectcommit__array__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectenable__string__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectenable__string__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectenable__array__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectenable__array__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectenable__scalar__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectenable__scalar__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ppeffectforceinnvg__scalar__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ppeffectforceinnvg__scalar__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__preloadobject__scalar__object_string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__preloadobject__scalar__object_string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__progresssetposition__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__progresssetposition__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__publicvariableclient__scalar__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__publicvariableclient__scalar__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__pushback__array__any__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__pushback__array__any__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__pushbackunique__array__any__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__pushbackunique__array__any__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__radiochanneladd__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__radiochanneladd__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__radiochannelremove__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__radiochannelremove__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__radiochannelsetcallsign__scalar__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetcallsign__scalar__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__radiochannelsetlabel__scalar__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetlabel__scalar__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__random__scalar__scalar_array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__random__scalar__scalar_array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__regexfind__string__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__regexfind__string__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__regexmatch__string__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__regexmatch__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__regexreplace__string__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__regexreplace__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__registertask__team_member__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__registertask__team_member__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__reload__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__reload__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__remotecontrol__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__remotecontrol__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__remoteexec__any__array__ret__string_nothing(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__remoteexec__any__array__ret__string_nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__remoteexeccall__any__array__ret__string_nothing(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__remoteexeccall__any__array__ret__string_nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__removeaction__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeaction__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removealleventhandlers__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removealleventhandlers__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removealleventhandlers__group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removealleventhandlers__group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeallmpeventhandlers__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeallmpeventhandlers__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removebinocularitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removebinocularitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removecuratoraddons__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removecuratoraddons__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removecuratorcameraarea__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removecuratorcameraarea__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removecuratoreditableobjects__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditableobjects__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removecuratoreditingarea__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditingarea__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removediaryrecord__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removediaryrecord__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removediarysubject__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removediarysubject__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removedrawicon__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removedrawicon__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removedrawlinks__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removedrawlinks__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeeventhandler__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeeventhandler__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeeventhandler__group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeeventhandler__group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removegroupicon__group__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removegroupicon__group__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removehandgunitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removehandgunitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeitemfrombackpack__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeitemfrombackpack__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeitemfromuniform__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeitemfromuniform__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeitemfromvest__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeitemfromvest__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeitems__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeitems__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemagazine__object__string_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemagazine__object__string_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemagazineglobal__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemagazineglobal__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemagazines__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemagazines__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemagazinesturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemagazinesturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemagazineturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemagazineturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemenuitem__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemenuitem__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removemenuitem__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removemenuitem__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removempeventhandler__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removempeventhandler__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeownedmine__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeownedmine__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeprimaryweaponitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeprimaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removesecondaryweaponitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removesecondaryweaponitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removesimpletask__object__task__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removesimpletask__object__task__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeteammember__team_member__team_member__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeteammember__team_member__team_member__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeweapon__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeweapon__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeweaponattachmentcargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeweaponattachmentcargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeweaponcargo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeweaponcargo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeweaponglobal__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeweaponglobal__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__removeweaponturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__removeweaponturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__reportremotetarget__side__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__reportremotetarget__side__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__resize__array__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__resize__array__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__resize__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__resize__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__respawnvehicle__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__respawnvehicle__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__reveal__object_group__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__reveal__object_group__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__reveal__object_group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__reveal__object_group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__revealmine__side__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__revealmine__side__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ropeattachto__object_array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ropeattachto__object_array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__ropedetach__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__ropedetach__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__saveidentity__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__saveidentity__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__savestatus__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__savestatus__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__say__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__say__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__say__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__say__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__say2d__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__say2d__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__say2d__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__say2d__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__say3d__object_array__string__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__say3d__object_array__string__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__say3d__object_array__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__say3d__object_array__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__select__array__scalar__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__array__scalar__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__select__array__bool__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__array__bool__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__select__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__select__array__code__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__array__code__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__select__config__scalar__ret__config(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__config__scalar__ret__config, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__select__string__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__select__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__selectdiarysubject__object__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectdiarysubject__object__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__selecteditorobject__control__string__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selecteditorobject__control__string__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__selectionnames__object__string_scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionnames__object__string_scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__selectionposition__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionposition__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__selectionposition__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionposition__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__selectionvectordirandup__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectionvectordirandup__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__selectleader__group__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__selectleader__group__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__selectrandomweighted__array__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectrandomweighted__array__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__selectweapon__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__selectweapon__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__selectweapon__object__array__ret__bool_nothing(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__selectweapon__object__array__ret__bool_nothing, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__selectweaponturret__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__selectweaponturret__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sendsimplecommand__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sendsimplecommand__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__sendtask__team_member__array__ret__task(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__sendtask__team_member__array__ret__task, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__sendtaskresult__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sendtaskresult__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__servercommand__string__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__servercommand__string__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__set__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__set__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__set__hashmap__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set__hashmap__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__set3denattribute__any__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denattribute__any__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__set3denlayer__any__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__set3denlayer__any__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__set3denlogictype__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__set3denlogictype__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__set3denmissionattribute__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__set3denmissionattribute__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__set3denobjecttype__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__set3denobjecttype__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setactualcollectivertd__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setactualcollectivertd__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setairplanethrottle__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setairplanethrottle__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setairportside__object_scalar__side__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setairportside__object_scalar__side__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setammo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setammo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setammocargo__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setammocargo__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setammoonpylon__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setammoonpylon__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setanimspeedcoef__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setanimspeedcoef__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setattributes__text_string__array__ret__text(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setattributes__text_string__array__ret__text, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__setautonomous__object__bool__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setautonomous__object__bool__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setbehaviour__object_group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setbehaviour__object_group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setbehaviourstrong__object_group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setbehaviourstrong__object_group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setbleedingremaining__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setbleedingremaining__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setbrakesrtd__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setbrakesrtd__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcamerainterest__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcamerainterest__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcamuseti__bool__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcamuseti__bool__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcaptive__object__bool_scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcaptive__object__bool_scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcenterofmass__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcenterofmass__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcollisionlight__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcollisionlight__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcombatbehaviour__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcombatbehaviour__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcombatbehaviour__group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcombatbehaviour__group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcombatmode__object_group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcombatmode__object_group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcombatmode__team_member__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcombatmode__team_member__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setconvoyseparation__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setconvoyseparation__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcruisecontrol__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcruisecontrol__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcuratorcameraareaceiling__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcuratorcameraareaceiling__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcuratorcoef__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcuratorcoef__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcuratoreditingareatype__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcuratoreditingareatype__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcuratorselectionpreset__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcuratorselectionpreset__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcuratorwaypointcost__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcuratorwaypointcost__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcurrenttask__object__task__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcurrenttask__object__task__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcurrentwaypoint__group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcurrentwaypoint__group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcustomaimcoef__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcustomaimcoef__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setcustomweightrtd__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setcustomweightrtd__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdamage__object__scalar_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdamage__object__scalar_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdammage__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdammage__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdebriefingtext__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdebriefingtext__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdestination__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdestination__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdiaryrecordtext__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdiaryrecordtext__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdiarysubjectpicture__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdiarysubjectpicture__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdir__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdir__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdirection__location__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdirection__location__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdrawicon__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdrawicon__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdriveonpath__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdriveonpath__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdropinterval__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdropinterval__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdynamicsimulationdistance__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistance__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setdynamicsimulationdistancecoef__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistancecoef__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__seteditormode__control__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__seteditormode__control__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__seteditorobjectscope__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__seteditorobjectscope__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__seteffectcondition__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__seteffectcondition__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__seteffectivecommander__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__seteffectivecommander__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setenginerpmrtd__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setenginerpmrtd__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setface__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setface__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfaceanimation__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfaceanimation__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfatigue__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfatigue__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setfeaturetype__object__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setfeaturetype__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setflaganimationphase__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setflaganimationphase__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setflagowner__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setflagowner__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setflagside__object__side__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setflagside__object__side__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setflagtexture__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setflagtexture__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfog__scalar__scalar_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfog__scalar__scalar_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setforcegeneratorrtd__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setforcegeneratorrtd__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setformation__object_group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setformation__object_group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setformation__team_member__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setformation__team_member__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setformationtask__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setformationtask__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setformdir__object_group__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setformdir__object_group__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfriend__side__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfriend__side__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfromeditor__team_member__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfromeditor__team_member__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfsmvariable__scalar__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfsmvariable__scalar__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfuel__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfuel__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setfuelcargo__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setfuelcargo__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setgroupicon__group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setgroupicon__group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setgroupiconparams__group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setgroupiconparams__group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setgroupid__object_group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setgroupid__object_group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setgroupidglobal__object_group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setgroupidglobal__object_group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setgroupowner__group__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setgroupowner__group__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setgusts__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setgusts__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sethidebehind__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sethidebehind__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sethit__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sethit__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sethitindex__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sethitindex__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sethitpointdamage__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sethitpointdamage__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setidentity__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setidentity__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setimportance__location__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setimportance__location__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setleader__team_member__team_member__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setleader__team_member__team_member__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightambient__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightambient__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightattenuation__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightattenuation__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightbrightness__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightbrightness__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightcolor__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightcolor__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightconepars__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightconepars__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightdaylight__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightdaylight__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightflaremaxdistance__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightflaremaxdistance__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightflaresize__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightflaresize__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightintensity__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightintensity__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightir__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightir__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightnings__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightnings__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightuseflare__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightuseflare__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setlightvolumeshape__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setlightvolumeshape__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmagazineturretammo__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmagazineturretammo__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkeralpha__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkeralpha__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkeralphalocal__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkeralphalocal__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerbrush__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrush__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerbrushlocal__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrushlocal__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkercolor__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkercolor__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkercolorlocal__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkercolorlocal__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerdir__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerdir__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerdirlocal__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerdirlocal__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerdrawpriority__string__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerdrawpriority__string__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerpolyline__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolyline__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerpolylinelocal__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolylinelocal__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerpos__string__object_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerpos__string__object_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkerposlocal__string__object_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkerposlocal__string__object_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkershadow__string__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkershadow__string__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkershadowlocal__string__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkershadowlocal__string__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkershape__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkershape__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkershapelocal__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkershapelocal__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkersize__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkersize__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkersizelocal__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkersizelocal__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkertext__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkertext__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkertextlocal__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkertextlocal__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkertype__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkertype__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmarkertypelocal__string__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmarkertypelocal__string__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmass__object__scalar_array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmass__object__scalar_array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmaxload__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmaxload__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmimic__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmimic__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setmissiletarget__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setmissiletarget__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setmissiletargetpos__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmissiletargetpos__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setmusiceffect__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setmusiceffect__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setname__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setname__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setname__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setname__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setname__location__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setname__location__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setnamesound__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setnamesound__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setobjectarguments__control__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectarguments__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setobjectmaterial__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterial__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setobjectmaterialglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterialglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setobjectproxy__control__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setobjectproxy__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setobjectscale__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setobjectscale__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setobjecttexture__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setobjecttexture__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setobjecttextureglobal__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setobjecttextureglobal__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setopticsmode__object__array_string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setopticsmode__object__array_string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setovercast__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setovercast__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setowner__object__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setowner__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setoxygenremaining__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setoxygenremaining__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setparticlecircle__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setparticlecircle__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setparticleclass__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setparticleclass__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setparticlefire__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setparticlefire__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setparticleparams__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setparticleparams__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setparticlerandom__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setparticlerandom__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setpilotcameradirection__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpilotcameradirection__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setpilotcameraopticsmode__object__scalar__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpilotcameraopticsmode__object__scalar__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setpilotcamerarotation__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpilotcamerarotation__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setpilotcameratarget__object__object_array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpilotcameratarget__object__object_array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setpilotlight__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpilotlight__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setpipeffect__string__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpipeffect__string__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setpitch__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpitch__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setplatenumber__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setplatenumber__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setplayervonvolume__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setplayervonvolume__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setpos__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpos__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setposasl__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setposasl__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setposasl2__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setposasl2__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setposaslw__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setposaslw__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setposatl__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setposatl__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setposition__location__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setposition__location__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setposworld__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setposworld__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setpylonloadout__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setpylonloadout__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setpylonspriority__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setpylonspriority__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setradiomsg__scalar__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setradiomsg__scalar__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrain__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrain__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrainbow__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrainbow__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrandomlip__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrandomlip__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrank__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrank__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrectangular__location__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrectangular__location__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrepaircargo__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrepaircargo__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setrotorbrakertd__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setrotorbrakertd__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setshotparents__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setshotparents__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setside__location__side__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setside__location__side__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsimpletaskalwaysvisible__task__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskalwaysvisible__task__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsimpletaskcustomdata__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskcustomdata__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsimpletaskdescription__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdescription__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsimpletaskdestination__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdestination__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsimpletasktarget__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktarget__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsimpletasktype__task__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktype__task__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsize__location__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsize__location__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setskill__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setskill__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setskill__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setskill__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setslingload__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setslingload__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setsoundeffect__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsoundeffect__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setspeaker__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setspeaker__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setspeech__location__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setspeech__location__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setspeedmode__object_group__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setspeedmode__object_group__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setstamina__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setstamina__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setsuppression__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setsuppression__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settargetage__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settargetage__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settaskmarkeroffset__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settaskmarkeroffset__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settaskresult__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settaskresult__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settaskstate__task__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settaskstate__task__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settext__location__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settext__location__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settitleeffect__object_array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settitleeffect__object_array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settowparent__object__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settowparent__object__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggeractivation__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggeractivation__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggerarea__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggerarea__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggerinterval__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggerinterval__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggerstatements__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggerstatements__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggertext__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggertext__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggertimeout__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggertimeout__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settriggertype__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settriggertype__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setturretlimits__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setturretlimits__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setturretopticsmode__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setturretopticsmode__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setturretopticsmode__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setturretopticsmode__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__settype__location__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__settype__location__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunconscious__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunconscious__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitability__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitability__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitcombatmode__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitcombatmode__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitfreefallheight__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitfreefallheight__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitloadout__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitloadout__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitloadout__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitloadout__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitloadout__object__config__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitloadout__object__config__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitpos__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitpos__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitposweak__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitposweak__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitrank__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitrank__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunitrecoilcoefficient__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunitrecoilcoefficient__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunittrait__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunittrait__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setunloadincombat__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setunloadincombat__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setuseractiontext__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setuseractiontext__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setusermfdtext__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setusermfdtext__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setusermfdvalue__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setusermfdvalue__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__display__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__display__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__group__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__group__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__namespace__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__namespace__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__team_member__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__team_member__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__task__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__task__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvariable__location__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvariable__location__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvectordir__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvectordir__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvectordirandup__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvectordirandup__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvectorup__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvectorup__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehicleammo__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehicleammo__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehicleammodef__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehicleammodef__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehiclearmor__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehiclearmor__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setvehiclecargo__object__object__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehiclecargo__object__object__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setvehicleid__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehicleid__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehiclelock__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehiclelock__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setvehicleposition__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setvehicleposition__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setvehicleradar__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehicleradar__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehiclereceiveremotetargets__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehiclereceiveremotetargets__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehiclereportownposition__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportownposition__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehiclereportremotetargets__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportremotetargets__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehicletipars__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehicletipars__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvehiclevarname__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvehiclevarname__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvelocity__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvelocity__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvelocitymodelspace__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvelocitymodelspace__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvelocitytransformation__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvelocitytransformation__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setvisibleiftreecollapsed__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setvisibleiftreecollapsed__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwantedrpmrtd__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwantedrpmrtd__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaves__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaves__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointbehaviour__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointbehaviour__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointcombatmode__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointcombatmode__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointcompletionradius__array__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointcompletionradius__array__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointdescription__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointdescription__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointforcebehaviour__array__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointforcebehaviour__array__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointformation__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointformation__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointhouseposition__array__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointhouseposition__array__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointloiteraltitude__array__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiteraltitude__array__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointloiterradius__array__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiterradius__array__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointloitertype__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointloitertype__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointname__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointname__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointposition__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointposition__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointscript__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointscript__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointspeed__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointspeed__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointstatements__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointstatements__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointtimeout__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointtimeout__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointtype__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointtype__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwaypointvisible__array__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwaypointvisible__array__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__setweaponreloadingtime__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setweaponreloadingtime__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__setweaponzeroing__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__setweaponzeroing__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__setwinddir__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwinddir__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwindforce__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwindforce__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwindstr__scalar__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwindstr__scalar__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwingforcescalertd__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwingforcescalertd__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__setwppos__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__setwppos__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__show3dicons__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__show3dicons__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__showlegend__control__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__showlegend__control__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__showneweditorobject__control__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__showneweditorobject__control__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__showwaypoint__array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__showwaypoint__array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sidechat__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sidechat__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sideradio__object_array__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sideradio__object_array__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__skill__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__skill__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__skillfinal__object__string__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__skillfinal__object__string__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__slidersetposition__control__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__slidersetposition__control__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__slidersetrange__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__slidersetrange__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__slidersetspeed__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__slidersetspeed__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__sort__array__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__sort__array__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__spawn__any__code__ret__script(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__spawn__any__code__ret__script, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__splitstring__string__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__splitstring__string__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__step__for__scalar__ret__for(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__step__for__scalar__ret__for, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__stop__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__stop__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__suppressfor__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__suppressfor__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__swimindepth__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__swimindepth__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__switchaction__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__switchaction__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__switchcamera__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__switchcamera__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__switchgesture__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__switchgesture__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__switchlight__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__switchlight__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__switchmove__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__switchmove__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__synchronizeobjectsadd__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsadd__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__synchronizeobjectsremove__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsremove__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__synchronizetrigger__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__synchronizetrigger__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__synchronizewaypoint__array__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__synchronizewaypoint__array__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__synchronizewaypoint__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__synchronizewaypoint__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__targetknowledge__object__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targetknowledge__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__targets__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targets__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__targets__group__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targets__group__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__targetsaggregate__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targetsaggregate__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__targetsquery__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__targetsquery__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__then__if__code__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__then__if__code__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__then__if__array__ret__any(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__then__if__array__ret__any, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__throw__if__any__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__throw__if__any__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__to__for__scalar__ret__for(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__to__for__scalar__ret__for, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__toarray__hashmap__bool__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__toarray__hashmap__bool__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tofixed__scalar__scalar__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tofixed__scalar__scalar__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__triggerattachobject__object__scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__triggerattachobject__object__scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__triggerattachvehicle__object__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__triggerattachvehicle__object__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__triggerdynamicsimulation__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__triggerdynamicsimulation__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__trim__string__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__trim__string__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__try__any__code__ret__exception(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__try__any__code__ret__exception, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__turretlocal__object__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__turretlocal__object__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__turretowner__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__turretowner__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__turretunit__object__array__ret__object(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__turretunit__object__array__ret__object, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tvadd__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvadd__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__tvcollapse__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvcollapse__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__tvcount__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvcount__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tvdata__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvdata__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__tvdelete__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvdelete__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvexpand__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvexpand__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__tvisselected__control__array__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvisselected__control__array__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tvpicture__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvpicture__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tvpictureright__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvpictureright__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__tvsetcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetcursel__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetcursel__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetdata__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetdata__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicture__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicture__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicturecolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicturecolordisabled__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolordisabled__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicturecolorselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolorselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpictureright__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpictureright__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicturerightcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicturerightcolordisabled__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolordisabled__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetpicturerightcolorselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolorselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetselectcolor__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetselectcolor__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetselected__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetselected__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsettext__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsettext__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsettooltip__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsettooltip__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsetvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsetvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsort__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsort__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsortall__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsortall__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsortbyvalue__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalue__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__tvsortbyvalueall__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalueall__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__tvtext__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvtext__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tvtooltip__control__array__ret__string(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvtooltip__control__array__ret__string, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__tvvalue__control__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__tvvalue__control__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__unassignitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__unassignitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__unitsbelowheight__group__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unitsbelowheight__group__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__unitsbelowheight__array__scalar__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unitsbelowheight__array__scalar__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__unitturret__object__object__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unitturret__object__object__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__unlinkitem__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__unlinkitem__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__unregistertask__team_member__string__ret__bool(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__unregistertask__team_member__string__ret__bool, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__updatedrawicon__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__updatedrawicon__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__updatemenuitem__control__array__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__updatemenuitem__control__array__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__useaudiotimeformoves__object__bool__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__useaudiotimeformoves__object__bool__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__vectoradd__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectoradd__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectorcos__array__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorcos__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectorcrossproduct__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorcrossproduct__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectordiff__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordiff__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectordistance__array__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordistance__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectordistancesqr__array__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordistancesqr__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectordotproduct__array__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectordotproduct__array__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectorfromto__array__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorfromto__array__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectormodeltoworld__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworld__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectormodeltoworldvisual__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworldvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectormultiply__array__scalar_array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectormultiply__array__scalar_array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectorworldtomodel__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodel__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__vectorworldtomodelvisual__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodelvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void binary__vehiclechat__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__vehiclechat__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__vehicleradio__object__string__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__vehicleradio__object__string__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__waypointattachobject__array__object_scalar__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__waypointattachobject__array__object_scalar__ret__nothing, left_arg, right_arg);
}

DLLEXPORT void binary__waypointattachvehicle__array__object__ret__nothing(game_value left_arg, game_value right_arg)
{
	host::functions.invoke_raw_binary(__sqf::binary__waypointattachvehicle__array__object__ret__nothing, left_arg, right_arg);
}

DLLEXPORT game_value binary__weaponaccessories__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponaccessories__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__weaponaccessoriescargo__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponaccessoriescargo__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__weapondirection__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weapondirection__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__weaponreloadingtime__object__array__ret__scalar(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponreloadingtime__object__array__ret__scalar, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__weaponsinfo__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponsinfo__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__weaponstate__object__string__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponstate__object__string__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__weaponsturret__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__weaponsturret__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__worldtomodel__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__worldtomodel__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value binary__worldtomodelvisual__object__array__ret__array(game_value left_arg, game_value right_arg)
{
	game_value temp = host::functions.invoke_raw_binary(__sqf::binary__worldtomodelvisual__object__array__ret__array, left_arg, right_arg);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__acctime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__acctime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__activatedaddons__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__activatedaddons__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__agents__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__agents__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__airdensitycurvertd__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__airdensitycurvertd__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__all3denentities__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__all3denentities__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allactivetitleeffects__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allactivetitleeffects__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__alladdonsinfo__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alladdonsinfo__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allairports__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allairports__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allcurators__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allcurators__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allcutlayers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allcutlayers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__alldead__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alldead__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__alldeadmen__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alldeadmen__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__alldisplays__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__alldisplays__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allenv3dsoundsources__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allenv3dsoundsources__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allgroups__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allgroups__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allmapmarkers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allmapmarkers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allmines__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allmines__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allplayers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allplayers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allsites__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allsites__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allunits__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allunits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allunitsuav__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allunitsuav__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__allusers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__allusers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__ambienttemperature__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ambienttemperature__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__apertureparams__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__apertureparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__armorypoints__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__armorypoints__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__benchmark__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__benchmark__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__blufor__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__blufor__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__break__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__break__ret__nothing);
}

DLLEXPORT game_value nular__briefingname__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__briefingname__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__buldozer_isenabledroaddiag__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__buldozer_isenabledroaddiag__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__buldozer_reloadopermap__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__buldozer_reloadopermap__ret__nothing);
}

DLLEXPORT game_value nular__cadetmode__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cadetmode__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__cameraon__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cameraon__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__cameraview__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cameraview__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__campaignconfigfile__ret__config()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__campaignconfigfile__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__cansuspend__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cansuspend__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__cheatsenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cheatsenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__civilian__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__civilian__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__clearforcesrtd__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__clearforcesrtd__ret__nothing);
}

DLLEXPORT void nular__clearitempool__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__clearitempool__ret__nothing);
}

DLLEXPORT void nular__clearmagazinepool__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__clearmagazinepool__ret__nothing);
}

DLLEXPORT void nular__clearradio__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__clearradio__ret__nothing);
}

DLLEXPORT void nular__clearweaponpool__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__clearweaponpool__ret__nothing);
}

DLLEXPORT game_value nular__clientowner__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__clientowner__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__commandingmenu__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__commandingmenu__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__configfile__ret__config()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__configfile__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__confignull__ret__config()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__confignull__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__continue__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__continue__ret__nothing);
}

DLLEXPORT game_value nular__controlnull__ret__control()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__controlnull__ret__control);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__copyfromclipboard__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__copyfromclipboard__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__createhashmap__ret__hashmap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__createhashmap__ret__hashmap);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__curatorcamera__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__curatorcamera__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__curatormouseover__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__curatormouseover__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__curatorselected__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__curatorselected__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__current3denoperation__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__current3denoperation__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__currentchannel__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__currentchannel__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__currentnamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__currentnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__cursorobject__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cursorobject__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__cursortarget__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__cursortarget__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__customwaypointposition__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__customwaypointposition__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__date__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__date__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__daytime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__daytime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_activemissionfsms__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activemissionfsms__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_activescripts__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activescripts__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_activesqfscripts__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activesqfscripts__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_activesqsscripts__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_activesqsscripts__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_allmissioneventhandlers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_allmissioneventhandlers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_deltatime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_deltatime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_dumpcalltracetolog__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_dumpcalltracetolog__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_dumpterrainsynth__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_dumpterrainsynth__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_fps__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_fps__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_fpsmin__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_fpsmin__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_frameno__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_frameno__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__diag_resetfsm__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__diag_resetfsm__ret__nothing);
}

DLLEXPORT void nular__diag_resetshapes__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__diag_resetshapes__ret__nothing);
}

DLLEXPORT game_value nular__diag_scope__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_scope__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_stacktrace__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_stacktrace__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diag_ticktime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diag_ticktime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__dialog__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__dialog__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__diaryrecordnull__ret__task()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__diaryrecordnull__ret__task);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__didjip__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__didjip__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__difficulty__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__difficulty__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__difficultyenabledrtd__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__difficultyenabledrtd__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__disabledebriefingstats__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__disabledebriefingstats__ret__nothing);
}

DLLEXPORT void nular__disableserialization__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__disableserialization__ret__nothing);
}

DLLEXPORT game_value nular__displaynull__ret__display()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__displaynull__ret__display);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__distributionregion__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__distributionregion__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__dynamicsimulationsystemenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__dynamicsimulationsystemenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__east__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__east__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__enableenddialog__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__enableenddialog__ret__nothing);
}

DLLEXPORT game_value nular__endl__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__endl__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__endloadingscreen__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__endloadingscreen__ret__nothing);
}

DLLEXPORT game_value nular__environmentenabled__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__environmentenabled__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__environmentvolume__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__environmentvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__estimatedendservertime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__estimatedendservertime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__exit__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__exit__ret__nothing);
}

DLLEXPORT game_value nular__false__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__false__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__finishmissioninit__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__finishmissioninit__ret__nothing);
}

DLLEXPORT game_value nular__fog__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__fog__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__fogforecast__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__fogforecast__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__fogparams__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__fogparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__forcedmap__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__forcedmap__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__forceend__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__forceend__ret__nothing);
}

DLLEXPORT void nular__forceweatherchange__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__forceweatherchange__ret__nothing);
}

DLLEXPORT game_value nular__freelook__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__freelook__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__get3dencamera__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3dencamera__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__get3deniconsvisible__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3deniconsvisible__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__get3denlinesvisible__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3denlinesvisible__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__get3denmouseover__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__get3denmouseover__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getartillerycomputersettings__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getartillerycomputersettings__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getaudiooptionvolumes__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getaudiooptionvolumes__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getcalculateplayervisibilitybyfriendly__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getcalculateplayervisibilitybyfriendly__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getclientstate__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getclientstate__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getclientstatenumber__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getclientstatenumber__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getcursorobjectparams__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getcursorobjectparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getdlcassetsusage__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getdlcassetsusage__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getelevationoffset__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getelevationoffset__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getlighting__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getlighting__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getloadedmodsinfo__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getloadedmodsinfo__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getmissiondlcs__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmissiondlcs__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getmissionlayers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmissionlayers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getmouseposition__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmouseposition__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getmusicplayedtime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getmusicplayedtime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getobjectviewdistance__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getobjectviewdistance__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getpipviewdistance__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getpipviewdistance__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getremotesensorsdisabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getremotesensorsdisabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getresolution__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getresolution__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getshadowdistance__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getshadowdistance__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getsteamfriendsservers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getsteamfriendsservers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getsubtitleoptions__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getsubtitleoptions__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getterraingrid__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getterraingrid__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getterraininfo__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getterraininfo__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__gettiparameters__ret__hashmap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__gettiparameters__ret__hashmap);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__gettotaldlcusagetime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__gettotaldlcusagetime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__getvideooptions__ret__hashmap()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__getvideooptions__ret__hashmap);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__groupiconselectable__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__groupiconselectable__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__groupiconsvisible__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__groupiconsvisible__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__grpnull__ret__group()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__grpnull__ret__group);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__gusts__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__gusts__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__halt__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__halt__ret__nothing);
}

DLLEXPORT game_value nular__hasinterface__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__hasinterface__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__hcshownbar__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__hcshownbar__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__hudmovementlevels__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__hudmovementlevels__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__humidity__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__humidity__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__independent__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__independent__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__initambientlife__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__initambientlife__ret__nothing);
}

DLLEXPORT game_value nular__is3den__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__is3den__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__is3denmultiplayer__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__is3denmultiplayer__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__is3denpreview__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__is3denpreview__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isactionmenuvisible__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isactionmenuvisible__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isautotest__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isautotest__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isdedicated__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isdedicated__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isfilepatchingenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isfilepatchingenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isgamefocused__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isgamefocused__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isgamepaused__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isgamepaused__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isinstructorfigureenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isinstructorfigureenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__ismissionprofilenamespaceloaded__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ismissionprofilenamespaceloaded__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__ismultiplayer__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ismultiplayer__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__ismultiplayersolo__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ismultiplayersolo__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__ispipenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__ispipenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isremoteexecuted__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isremoteexecuted__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isremoteexecutedjip__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isremoteexecutedjip__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__issaving__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__issaving__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isserver__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isserver__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__issteammission__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__issteammission__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__issteamoverlayenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__issteamoverlayenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isstreamfriendlyuienabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isstreamfriendlyuienabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isstressdamageenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isstressdamageenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__istuthintsenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__istuthintsenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__isuicontext__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__isuicontext__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__language__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__language__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__librarycredits__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__librarycredits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__librarydisclaimers__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__librarydisclaimers__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__lightnings__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__lightnings__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__linebreak__ret__text()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__linebreak__ret__text);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__loadgame__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__loadgame__ret__nothing);
}

DLLEXPORT game_value nular__localnamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__localnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__locationnull__ret__location()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__locationnull__ret__location);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__logentities__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__logentities__ret__nothing);
}

DLLEXPORT void nular__mapanimclear__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__mapanimclear__ret__nothing);
}

DLLEXPORT void nular__mapanimcommit__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__mapanimcommit__ret__nothing);
}

DLLEXPORT game_value nular__mapanimdone__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__mapanimdone__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__markasfinishedonsteam__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__markasfinishedonsteam__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionconfigfile__ret__config()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionconfigfile__ret__config);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missiondifficulty__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missiondifficulty__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionend__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionend__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionname__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionname__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionnamesource__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionnamesource__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionnamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionprofilenamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionprofilenamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionstart__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionstart__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__missionversion__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__missionversion__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__moonintensity__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__moonintensity__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__musicvolume__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__musicvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__netobjnull__ret__netobject()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__netobjnull__ret__netobject);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__nextweatherchange__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__nextweatherchange__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__nil__ret__any()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__nil__ret__any);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__objnull__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__objnull__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__opencuratorinterface__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__opencuratorinterface__ret__nothing);
}

DLLEXPORT game_value nular__opfor__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__opfor__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__overcast__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__overcast__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__overcastforecast__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__overcastforecast__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__parsingnamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__parsingnamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__particlesquality__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__particlesquality__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__pi__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pi__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__pixelgrid__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelgrid__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__pixelgridbase__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelgridbase__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__pixelgridnouiscale__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelgridnouiscale__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__pixelh__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelh__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__pixelw__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__pixelw__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__playableunits__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__playableunits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__player__ret__object()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__player__ret__object);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__playerrespawntime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__playerrespawntime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__playerside__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__playerside__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__productversion__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__productversion__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__profilename__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__profilename__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__profilenamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__profilenamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__profilenamesteam__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__profilenamesteam__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__radioenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__radioenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__radiovolume__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__radiovolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__rain__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__rain__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__rainbow__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__rainbow__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__rainparams__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__rainparams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__remoteexecutedowner__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__remoteexecutedowner__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__resetcamshake__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__resetcamshake__ret__nothing);
}

DLLEXPORT game_value nular__resistance__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__resistance__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__reversedmousey__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__reversedmousey__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__runinitscript__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__runinitscript__ret__nothing);
}

DLLEXPORT game_value nular__safezoneh__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezoneh__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__safezonew__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonew__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__safezonewabs__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonewabs__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__safezonex__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonex__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__safezonexabs__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezonexabs__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__safezoney__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__safezoney__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__savegame__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__savegame__ret__nothing);
}

DLLEXPORT void nular__savejoysticks__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__savejoysticks__ret__nothing);
}

DLLEXPORT game_value nular__savemissionprofilenamespace__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__savemissionprofilenamespace__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__saveprofilenamespace__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__saveprofilenamespace__ret__nothing);
}

DLLEXPORT game_value nular__savingenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__savingenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__scriptnull__ret__script()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__scriptnull__ret__script);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__selectnoplayer__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__selectnoplayer__ret__nothing);
}

DLLEXPORT game_value nular__sentencesenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sentencesenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__servername__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__servername__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__servernamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__servernamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__servertime__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__servertime__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownartillerycomputer__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownartillerycomputer__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownchat__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownchat__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__showncompass__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__showncompass__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__showncuratorcompass__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__showncuratorcompass__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__showngps__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__showngps__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownhud__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownhud__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownmap__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownmap__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownpad__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownpad__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownradio__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownradio__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownscoretable__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownscoretable__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownsubtitles__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownsubtitles__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownuavfeed__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownuavfeed__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownwarrant__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownwarrant__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__shownwatch__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__shownwatch__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sideambientlife__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideambientlife__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sideempty__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideempty__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sideenemy__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideenemy__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sidefriendly__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sidefriendly__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sidelogic__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sidelogic__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sideunknown__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sideunknown__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__simulweathersync__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__simulweathersync__ret__nothing);
}

DLLEXPORT game_value nular__slingloadassistantshown__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__slingloadassistantshown__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__soundvolume__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__soundvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__speechvolume__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__speechvolume__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__sunormoon__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__sunormoon__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__switchableunits__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__switchableunits__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__systemofunits__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__systemofunits__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__systemtime__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__systemtime__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__systemtimeutc__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__systemtimeutc__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__tasknull__ret__task()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__tasknull__ret__task);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__teammembernull__ret__team_member()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teammembernull__ret__team_member);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__teams__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teams__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT void nular__teamswitch__ret__nothing()
{
	host::functions.invoke_raw_nular(__sqf::nular__teamswitch__ret__nothing);
}

DLLEXPORT game_value nular__teamswitchenabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__teamswitchenabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__time__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__time__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__timemultiplier__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__timemultiplier__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__true__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__true__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__uinamespace__ret__namespace()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__uinamespace__ret__namespace);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__userinputdisabled__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__userinputdisabled__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__vehicles__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__vehicles__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__viewdistance__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__viewdistance__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__visiblecompass__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblecompass__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__visiblegps__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblegps__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__visiblemap__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblemap__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__visiblescoretable__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblescoretable__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__visiblewatch__ret__bool()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__visiblewatch__ret__bool);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__waves__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__waves__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__west__ret__side()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__west__ret__side);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__wind__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__wind__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__winddir__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__winddir__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__windrtd__ret__array()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__windrtd__ret__array);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__windstr__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__windstr__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__worldname__ret__string()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__worldname__ret__string);
	temp.data->_refcount = 256;
	return temp;
}

DLLEXPORT game_value nular__worldsize__ret__scalar()
{
	game_value temp = host::functions.invoke_raw_nular(__sqf::nular__worldsize__ret__scalar);
	temp.data->_refcount = 256;
	return temp;
}


#pragma endregion GameFunctions