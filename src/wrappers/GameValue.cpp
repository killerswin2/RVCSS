

#include <intercept.hpp>
#include "client/pointers.hpp"

#include <vector>

#ifdef _WIN32
#include <windows.h>
#define char_t wchar_t

#else
#define char_t char
#endif

#pragma warning(disable: 4996)

using host = intercept::client::host;
using __sqf = intercept::client::__sqf;

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValue()
{
	return new game_value();
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueFloat(float value)
{
	return new game_value(value);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueInt(int value)
{
	return new game_value(value);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueBool(bool value)
{
	return new game_value(value);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueString(const char* value)
{
	return new game_value(value);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueArrayEmpty()
{
	std::vector<game_value> object{};
	return new game_value(object);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueArray(intercept::types::game_value * array, int length)
{
	std::vector<game_value> object{array, array + length};
	return new game_value(object);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueVector2(intercept::types::vector2 value)
{
	return new game_value(value);
}

extern "C" __declspec(dllexport) intercept::types::game_value * CreateGameValueVector3(intercept::types::vector3 value)
{
	return new game_value(value);
}

extern "C" __declspec(dllexport) void DeleteGameValue(intercept::types::game_value * value)
{
	delete value;
}

extern "C" __declspec(dllexport) void FreeRVAllocation(void* bytes, int type)
{
	if (bytes == nullptr)
	{
		return;
	}

	switch (type)
	{
		// string
		case 0:
		{
			rv_allocator<char_t>::deallocate(reinterpret_cast<char_t*>(bytes));
			break;
		}
		// vector 2
		case 1:
		{
			rv_allocator<vector2>::deallocate(reinterpret_cast<vector2*>(bytes));
			break;
		}
		// vector 3
		case 2:
		{
			rv_allocator<vector3>::deallocate(reinterpret_cast<vector3*>(bytes));
			break;
		}
		default:
		{
			// why was this called?
			break;
		}
	}
}

extern "C" __declspec(dllexport) char_t* GetDataString(intercept::types::game_value * value)
{
	game_data* GameDataPointer = value->data.get();

	//string
	if (value->type() == game_data_string::type_def)
	{
		auto GameDataStringPointer = reinterpret_cast<game_data_string*>(GameDataPointer);
		auto stringData = GameDataStringPointer->raw_string.c_str();
		auto size = GameDataStringPointer->raw_string.size() + 1;

		char_t* str = rv_allocator<char_t>::allocate(size);
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, stringData, -1, str, size);
		return str;
	}
	else
	{
		// this is dangerous, but easy to do
		std::cout << "Not A String\n";
		return nullptr;
	}
}

extern "C" __declspec(dllexport) float GetDataFloat(intercept::types::game_value * value)
{
	game_data* GameDataPointer = value->data.get();

	//number/float
	if (value->type() == game_data_number::type_def)
	{
		auto GameDataNumberPointer = reinterpret_cast<game_data_number*>(GameDataPointer);
		return GameDataNumberPointer->number;
	}
	else
	{
		std::cout << "Not A Number\n";
		return 0.0;
	}
}

extern "C" __declspec(dllexport) int GetDataInt(intercept::types::game_value * value)
{
	return static_cast<int>(GetDataFloat(value));
}

extern "C" __declspec(dllexport) bool GetDataBool(intercept::types::game_value * value)
{
	game_data* GameDataPointer = value->data.get();

	//bool
	if (value->type() == game_data_bool::type_def)
	{
		auto GameDataBoolPointer = reinterpret_cast<game_data_bool*>(GameDataPointer);
		return GameDataBoolPointer->val;
	}
	else
	{
		std::cout << "Not A Bool\n";
		// yes this is dumb, but it's what I want to do at 11 pm
		return false;
	}
}

extern "C" __declspec(dllexport) vector2* GetDataVector2(intercept::types::game_value * value)
{
	game_data* GameDataPointer = value->data.get();

	if (value->type() == game_data_array::type_def && value->size() == 2)
	{
		vector2 temp = *value;
		return rv_allocator<vector2>::create_single(temp);
	}
	else
	{
		std::cout << "Not A Vec2\n";
		return nullptr;
	}
}

extern "C" __declspec(dllexport) vector3* GetDataVector3(intercept::types::game_value * value)
{
	game_data* GameDataPointer = value->data.get();

	if (value->type() == game_data_array::type_def && value->size() == 3)
	{
		vector3 temp = *value;
		auto pointer = rv_allocator<vector3>::create_single(temp);
		std::cout << pointer->x << " " << pointer->y << " " << pointer->z << "\n";
		return pointer;
	}
	else
	{
		std::cout << "Not A Vec3\n";
		return nullptr;
	}
}

extern "C" __declspec(dllexport) game_value * acctime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__acctime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * action(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__action__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionids(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionids__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionkeys(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionkeys__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionkeysex(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionkeysex__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionkeysimages(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionkeysimages__string_array__ret__text, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionkeysnames(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionkeysnames__string_array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionkeysnamesarray(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionkeysnamesarray__string_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__actionname__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * actionparams(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__actionparams__object__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * activateaddons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__activateaddons__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * activatedaddons()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__activatedaddons__ret__array));
}

extern "C" __declspec(dllexport) game_value * activatekey(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__activatekey__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * activetitleeffectparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__activetitleeffectparams__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * add3denconnection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__add3denconnection__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * add3deneventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__add3deneventhandler__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * add3denlayer(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__add3denlayer__scalar__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addaction__object__array__ret__nothing_scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addbackpack(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addbackpack__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addbackpackcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addbackpackcargoglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargoglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addbackpackglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addbackpackglobal__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addbinocularitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addbinocularitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addcamshake(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addcamshake__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addcuratoraddons(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addcuratoraddons__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addcuratorcameraarea(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addcuratorcameraarea__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addcuratoreditableobjects(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditableobjects__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addcuratoreditingarea(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditingarea__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addcuratorpoints(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addcuratorpoints__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addeditorobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addeditorobject__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addeventhandler__group__array__ret__nothing_scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addforce(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addforce__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addforcegeneratorrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addforcegeneratorrtd__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addgoggles(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addgoggles__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addgroupicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addgroupicon__group__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addhandgunitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addhandgunitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addheadgear(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addheadgear__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__additem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additemcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__additemcargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additemcargoglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__additemcargoglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additempool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__additempool__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additemtobackpack(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__additemtobackpack__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additemtouniform(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__additemtouniform__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * additemtovest(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__additemtovest__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addlivestats(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addlivestats__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazine(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazine__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazineammocargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazineammocargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazinecargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazinecargoglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargoglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazineglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazineglobal__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazinepool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addmagazinepool__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazines(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazines__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmagazineturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmagazineturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmenu(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmenu__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmenuitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmenuitem__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmissioneventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addmissioneventhandler__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmpeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addmpeventhandler__object__array__ret__nothing_scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addmusiceventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addmusiceventhandler__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addonfiles(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addonfiles__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addownedmine(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addownedmine__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addplayerscores(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addplayerscores__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addprimaryweaponitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addprimaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addpublicvariableeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addpublicvariableeventhandler__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addrating(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addrating__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addresources(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addresources__team_member__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addscore(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addscore__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addscoreside(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addscoreside__side__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addsecondaryweaponitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addsecondaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addswitchableunit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addswitchableunit__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addteammember(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addteammember__team_member__team_member__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addtoremainscollector(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addtoremainscollector__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addtorque(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addtorque__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * adduniform(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__adduniform__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * adduseractioneventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__adduseractioneventhandler__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addvehicle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addvehicle__group__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addvest(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addvest__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addwaypoint(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addwaypoint__group__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweapon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweapon__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponcargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponcargoglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponcargoglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponglobal__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponitem__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponpool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__addweaponpool__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponwithattachmentscargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * addweaponwithattachmentscargoglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargoglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * admin(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__admin__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * agent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__agent__team_member__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * agents()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__agents__ret__array));
}

extern "C" __declspec(dllexport) game_value * agltoasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__agltoasl__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * aimedattarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__aimedattarget__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * aimpos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__aimpos__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * airdensitycurvertd()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__airdensitycurvertd__ret__array));
}

extern "C" __declspec(dllexport) game_value * airdensityrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__airdensityrtd__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * airplanethrottle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__airplanethrottle__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * airportside(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__airportside__object_scalar__ret__side, *right_arg));
}

extern "C" __declspec(dllexport) game_value * aisfinishheal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__aisfinishheal__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * alive(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__alive__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * all3denentities()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__all3denentities__ret__array));
}

extern "C" __declspec(dllexport) game_value * allactivetitleeffects()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allactivetitleeffects__ret__array));
}

extern "C" __declspec(dllexport) game_value * alladdonsinfo()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__alladdonsinfo__ret__array));
}

extern "C" __declspec(dllexport) game_value * allairports()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allairports__ret__array));
}

extern "C" __declspec(dllexport) game_value * allcontrols(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__allcontrols__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allcurators()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allcurators__ret__array));
}

extern "C" __declspec(dllexport) game_value * allcutlayers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allcutlayers__ret__array));
}

extern "C" __declspec(dllexport) game_value * alldead()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__alldead__ret__array));
}

extern "C" __declspec(dllexport) game_value * alldeadmen()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__alldeadmen__ret__array));
}

extern "C" __declspec(dllexport) game_value * alldiaryrecords(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__alldiaryrecords__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * alldiarysubjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__alldiarysubjects__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * alldisplays()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__alldisplays__ret__array));
}

extern "C" __declspec(dllexport) game_value * allenv3dsoundsources()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allenv3dsoundsources__ret__array));
}

extern "C" __declspec(dllexport) game_value * allgroups()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allgroups__ret__array));
}

extern "C" __declspec(dllexport) game_value * alllods(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__alllods__object_string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allmapmarkers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allmapmarkers__ret__array));
}

extern "C" __declspec(dllexport) game_value * allmines()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allmines__ret__array));
}

extern "C" __declspec(dllexport) game_value * allmissionobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__allmissionobjects__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allobjects(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allobjects__string__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allow3dmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allow3dmode__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowcrewinimmobile(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowcrewinimmobile__object__bool_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowcuratorlogicignoreareas(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowcuratorlogicignoreareas__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowdamage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowdamage__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowdammage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowdammage__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowedservice(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__allowedservice__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowfileoperations(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowfileoperations__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowfleeing(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowfleeing__object_group__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowgetin(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowgetin__array__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowservice(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowservice__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allowsprint(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__allowsprint__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allplayers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allplayers__ret__array));
}

extern "C" __declspec(dllexport) game_value * allsimpleobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__allsimpleobjects__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allsites()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allsites__ret__array));
}

extern "C" __declspec(dllexport) game_value * allturrets(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__allturrets__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * allunits()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allunits__ret__array));
}

extern "C" __declspec(dllexport) game_value * allunitsuav()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allunitsuav__ret__array));
}

extern "C" __declspec(dllexport) game_value * allusers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__allusers__ret__array));
}

extern "C" __declspec(dllexport) game_value * allvariables(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__allvariables__location__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ambienttemperature()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__ambienttemperature__ret__array));
}

extern "C" __declspec(dllexport) game_value * ammo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ammo__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ammoonpylon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ammoonpylon__object__string_scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * and (game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__and__bool__code__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animate__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animatebay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animatebay__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animatedoor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animatedoor__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animatepylon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animatepylon__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animatesource(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animatesource__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animationnames(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__animationnames__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animationphase(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animationphase__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animationsourcephase(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__animationsourcephase__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * animationstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__animationstate__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * apertureparams()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__apertureparams__ret__array));
}

extern "C" __declspec(dllexport) game_value * append(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__append__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * apply(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__apply__hashmap__code__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * armorypoints()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__armorypoints__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * arrayintersect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__arrayintersect__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * asltoagl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__asltoagl__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * asltoatl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__asltoatl__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignascargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignascargo__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignascargoindex(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignascargoindex__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignascommander(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignascommander__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignasdriver(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignasdriver__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignasgunner(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignasgunner__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignasturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignasturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assigncurator(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assigncurator__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedcommander(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedcommander__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assigneddriver(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assigneddriver__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedgroup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedgroup__object__ret__group, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedgunner(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedgunner__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assigneditems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assigneditems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedtarget(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedtarget__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedteam(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedteam__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedvehicle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedvehicle__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedvehiclerole(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedvehiclerole__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignedvehicles(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__assignedvehicles__group__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assignteam(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assignteam__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * assigntoairport(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__assigntoairport__object__object_scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * atg(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__atg__scalar_nan__ret__scalar_nan, *right_arg));
}

extern "C" __declspec(dllexport) game_value * atltoasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__atltoasl__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * attachedobject(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__attachedobject__location__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * attachedobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__attachedobjects__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * attachedto(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__attachedto__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * attachobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__attachobject__location__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * attachto(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__attachto__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * attackenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__attackenabled__object_group__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * awake(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__awake__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__backpack__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpackcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__backpackcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpackcontainer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__backpackcontainer__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpackitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__backpackitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpackmagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__backpackmagazines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpacks(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__backpacks__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * backpackspacefor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__backpackspacefor__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * behaviour(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__behaviour__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * benchmark()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__benchmark__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * bezierinterpolation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__bezierinterpolation__scalar__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * binocular(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__binocular__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * binocularitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__binocularitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * binocularmagazine(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__binocularmagazine__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * blufor()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__blufor__ret__side));
}

extern "C" __declspec(dllexport) game_value * boundingbox(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__boundingbox__scalar__object__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * boundingboxreal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__boundingboxreal__scalar__object__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * boundingcenter(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__boundingcenter__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * brakesdisabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__brakesdisabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * breakout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__breakout__any__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * breakto(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__breakto__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * breakwith(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__breakwith__any__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * briefingname()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__briefingname__ret__string));
}

extern "C" __declspec(dllexport) game_value * buildingexit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__buildingexit__object__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * buildingpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__buildingpos__object__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * buldozer_enableroaddiag(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__buldozer_enableroaddiag__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * buldozer_isenabledroaddiag()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__buldozer_isenabledroaddiag__ret__bool));
}

extern "C" __declspec(dllexport) game_value * buldozer_loadnewroads(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__buldozer_loadnewroads__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * buldozer_reloadopermap()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__buldozer_reloadopermap__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * buttonaction(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__buttonaction__scalar__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * buttonsetaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__buttonsetaction__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cadetmode()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cadetmode__ret__bool));
}

extern "C" __declspec(dllexport) game_value * calculatepath(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__calculatepath__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * calculateplayervisibilitybyfriendly(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__calculateplayervisibilitybyfriendly__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * call(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__call__any__code__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * callextension(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__callextension__string__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camcommand(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camcommand__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camcommit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camcommit__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camcommitprepared(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camcommitprepared__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camcommitted(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__camcommitted__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camconstuctionsetparams(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camconstuctionsetparams__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camcreate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camcreate__string__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camdestroy(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__camdestroy__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cameraeffect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__cameraeffect__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cameraeffectenablehud(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__cameraeffectenablehud__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camerainterest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__camerainterest__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cameraon()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cameraon__ret__object));
}

extern "C" __declspec(dllexport) game_value * cameraview()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cameraview__ret__string));
}

extern "C" __declspec(dllexport) game_value * campaignconfigfile()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__campaignconfigfile__ret__config));
}

extern "C" __declspec(dllexport) game_value * campreload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreload__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreloaded(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__campreloaded__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparebank(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparebank__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparedir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparedir__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparedive(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparedive__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparefocus(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparefocus__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparefov(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparefov__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparefovrange(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparefovrange__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparepos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparepos__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparerelpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparerelpos__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * campreparetarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__campreparetarget__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetbank(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetbank__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetdir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetdir__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetdive(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetdive__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetfocus(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetfocus__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetfov(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetfov__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetfovrange(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetfovrange__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetpos__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsetrelpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsetrelpos__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camsettarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__camsettarget__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camtarget(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__camtarget__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * camusenvg(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__camusenvg__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canadd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__canadd__string__string_array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canadditemtobackpack(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__canadditemtobackpack__object__string_array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canadditemtouniform(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__canadditemtouniform__object__string_array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canadditemtovest(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__canadditemtovest__object__string_array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cancelsimpletaskdestination(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__cancelsimpletaskdestination__task__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * candeployweapon(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__candeployweapon__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canfire(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__canfire__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canmove(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__canmove__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canslingload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__canslingload__string__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canstand(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__canstand__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cansuspend()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cansuspend__ret__bool));
}

extern "C" __declspec(dllexport) game_value * cantriggerdynamicsimulation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__cantriggerdynamicsimulation__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canunloadincombat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__canunloadincombat__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * canvehiclecargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__canvehiclecargo__object__object__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * captive(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__captive__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * captivenum(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__captivenum__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cbchecked(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__cbchecked__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cbsetchecked(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__cbsetchecked__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * channelenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__channelenabled__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cheatsenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cheatsenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * checkaifeature(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__checkaifeature__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * checkvisibility(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__checkvisibility__array__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * civilian()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__civilian__ret__side));
}

extern "C" __declspec(dllexport) game_value * classname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__classname__location__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clear3denattribute(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__clear3denattribute__any__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clear3deninventory(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clear3deninventory__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearallitemsfrombackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearallitemsfrombackpack__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearbackpackcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargo__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearbackpackcargoglobal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargoglobal__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearforcesrtd()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__clearforcesrtd__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * cleargroupicons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__cleargroupicons__group__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearitemcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearitemcargo__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearitemcargoglobal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearitemcargoglobal__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearitempool()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__clearitempool__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * clearmagazinecargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargo__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearmagazinecargoglobal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargoglobal__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearmagazinepool()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__clearmagazinepool__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * clearoverlay(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearoverlay__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearradio()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__clearradio__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * clearweaponcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargo__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearweaponcargoglobal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargoglobal__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * clearweaponpool()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__clearweaponpool__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * clientowner()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__clientowner__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * closedialog(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__closedialog__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * closedisplay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__closedisplay__display__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * closeoverlay(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__closeoverlay__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * collapseobjecttree(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__collapseobjecttree__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * collect3denhistory(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__collect3denhistory__array__code__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * collectivertd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__collectivertd__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * collisiondisabledwith(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__collisiondisabledwith__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * combatbehaviour(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__combatbehaviour__group__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * combatmode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__combatmode__object_group__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandartilleryfire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandchat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandchat__object_array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commander(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__commander__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandfire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandfire__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandfollow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandfollow__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandfsm(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandfsm__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandgetout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__commandgetout__object_array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandingmenu()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__commandingmenu__ret__string));
}

extern "C" __declspec(dllexport) game_value * commandmove(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandmove__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandradio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandradio__object_array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandstop(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__commandstop__object_array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandsuppressivefire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandsuppressivefire__object_array__object_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandtarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandtarget__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commandwatch(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__commandwatch__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * comment(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__comment__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * commitoverlay(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__commitoverlay__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * compatibleitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__compatibleitems__string_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * compatiblemagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__compatiblemagazines__string_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * compile(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__compile__string__ret__code, *right_arg));
}

extern "C" __declspec(dllexport) game_value * compilefinal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__compilefinal__string__ret__code, *right_arg));
}

extern "C" __declspec(dllexport) game_value * compilescript(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__compilescript__array__ret__code, *right_arg));
}

extern "C" __declspec(dllexport) game_value * completedfsm(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__completedfsm__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * composetext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__composetext__array__ret__text, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configaccessor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__configaccessor__config__string__ret__config, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configclasses(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__configclasses__string__config__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configfile()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__configfile__ret__config));
}

extern "C" __declspec(dllexport) game_value * confighierarchy(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__confighierarchy__config__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__configname__config__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * confignull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__confignull__ret__config));
}

extern "C" __declspec(dllexport) game_value * configof(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__configof__object__ret__config, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configproperties(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__configproperties__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configsourceaddonlist(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__configsourceaddonlist__config__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configsourcemod(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__configsourcemod__config__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * configsourcemodlist(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__configsourcemodlist__config__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * confirmsensortarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__confirmsensortarget__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * connectterminaltouav(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__connectterminaltouav__object__object__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * connecttoserver(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__connecttoserver__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * continuewith(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__continuewith__any__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * controlnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__controlnull__ret__control));
}

extern "C" __declspec(dllexport) game_value * controlsgroupctrl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__controlsgroupctrl__control__scalar__ret__control, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * conversationdisabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__conversationdisabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * copyfromclipboard()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__copyfromclipboard__ret__string));
}

extern "C" __declspec(dllexport) game_value * copytoclipboard(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__copytoclipboard__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * copywaypoints(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__copywaypoints__group__group__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * count(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__count__code__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * countenemy(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__countenemy__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * countfriendly(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__countfriendly__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * countside(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__countside__side__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * counttype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__counttype__string__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * countunknown(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__countunknown__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * create3dencomposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__create3dencomposition__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * create3denentity(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__create3denentity__group__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createagent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createagent__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createcenter(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createcenter__side__ret__side, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createdialog(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createdialog__array__ret__display, *right_arg));
}

extern "C" __declspec(dllexport) game_value * creatediarylink(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__creatediarylink__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * creatediaryrecord(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__creatediaryrecord__object__array__ret__diary_record, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * creatediarysubject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__creatediarysubject__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createdisplay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createdisplay__display__string__ret__display, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * creategeardialog(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__creategeardialog__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * creategroup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__creategroup__side_array__ret__group, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createguardedpoint(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createguardedpoint__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createhashmap()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__createhashmap__ret__hashmap));
}

extern "C" __declspec(dllexport) game_value * createhashmapfromarray(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createhashmapfromarray__array__array__ret__hashmap, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createlocation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createlocation__array__ret__location, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createmarker(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createmarker__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createmarkerlocal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createmarkerlocal__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createmenu(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createmenu__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createmine(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createmine__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createmissiondisplay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createmissiondisplay__display__array__ret__display, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * creatempcampaigndisplay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__creatempcampaigndisplay__display__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createsimpleobject(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createsimpleobject__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createsimpletask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createsimpletask__object__array__ret__task, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createsite(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createsite__string__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createsoundsource(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createsoundsource__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createtask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createtask__team_member__array__ret__task, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createteam(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createteam__array__ret__team_member, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createtrigger(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createtrigger__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createunit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createunit__group__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createvehicle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createvehicle__string__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createvehiclecrew(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__createvehiclecrew__object__ret__group, *right_arg));
}

extern "C" __declspec(dllexport) game_value * createvehiclelocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__createvehiclelocal__string__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * crew(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__crew__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctaddheader(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctaddheader__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctaddrow(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctaddrow__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctclear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctclear__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctcursel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctcursel__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctdata__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctfindheaderrows(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctfindheaderrows__control__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctfindrowheader(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctfindrowheader__control__scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctheadercontrols(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctheadercontrols__control__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctheadercount(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctheadercount__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctremoveheaders(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctremoveheaders__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctremoverows(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctremoverows__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlactivate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlactivate__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrladdeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrladdeventhandler__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlangle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlangle__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlanimatemodel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlanimatemodel__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlanimationphasemodel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlanimationphasemodel__control__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlat__display__array__ret__control, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlautoscrolldelay(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrolldelay__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlautoscrollrewind(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollrewind__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlautoscrollspeed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollspeed__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlbackgroundcolor(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlbackgroundcolor__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlchecked(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlchecked__control__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlclassname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlclassname__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlcommit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlcommit__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlcommitted(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlcommitted__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlcreate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlcreate__display__array__ret__control, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrldelete(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrldelete__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlenable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlenable__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlenabled__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlfade(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlfade__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlfontheight(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlfontheight__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlforegroundcolor(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlforegroundcolor__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlhtmlloaded(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlhtmlloaded__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlidc(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlidc__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlidd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlidd__display__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapanimadd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlmapanimadd__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapanimclear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimclear__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapanimcommit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimcommit__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapanimdone(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimdone__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapcursor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlmapcursor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapdir(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapdir__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapmouseover(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapmouseover__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapposition__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapscale(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmapscale__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapscreentoworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlmapscreentoworld__control__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapsetposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlmapsetposition__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmapworldtoscreen(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlmapworldtoscreen__control__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmodel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmodel__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmodeldirandup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmodeldirandup__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmodelscale(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmodelscale__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlmouseposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlmouseposition__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlparent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlparent__control__ret__display, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlparentcontrolsgroup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlparentcontrolsgroup__control__ret__control, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlposition__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlremovealleventhandlers(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlremovealleventhandlers__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlremoveeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlremoveeventhandler__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlscale(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlscale__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlscrollvalues(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlscrollvalues__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetactivecolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetactivecolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetangle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetangle__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetautoscrolldelay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrolldelay__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetautoscrollrewind(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollrewind__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetautoscrollspeed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollspeed__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetbackgroundcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetbackgroundcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetchecked(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetchecked__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetdisabledcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetdisabledcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlseteventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlseteventhandler__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfade(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfade__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfocus(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlsetfocus__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfont(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfont__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth1(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth1b(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1b__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth2(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth2b(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2b__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth3(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth3b(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3b__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth4(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth4b(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4b__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth5(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth5b(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5b__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth6(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfonth6b(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6b__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheight__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheighth1(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth1__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheighth2(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth2__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheighth3(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth3__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheighth4(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth4__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheighth5(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth5__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheighth6(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth6__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontheightsecondary(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheightsecondary__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontp(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontp__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontpb(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontpb__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetfontsecondary(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontsecondary__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetforegroundcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetforegroundcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetmodel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodel__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetmodeldirandup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodeldirandup__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetmodelscale(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodelscale__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetmouseposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmouseposition__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetpixelprecision(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpixelprecision__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetposition__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetpositionh(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionh__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetpositionw(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionw__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetpositionx(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionx__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetpositiony(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositiony__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetscale(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscale__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetscrollvalues(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscrollvalues__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetshadow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetshadow__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsetstructuredtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsetstructuredtext__control__text__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettext__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettextcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettextcolorsecondary(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolorsecondary__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettextsecondary(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextsecondary__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettextselection(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextselection__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettooltip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltip__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettooltipcolorbox(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorbox__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettooltipcolorshade(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorshade__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettooltipcolortext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolortext__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlsettooltipmaxwidth(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipmaxwidth__control__scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlseturl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlseturl__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlseturloverlaymode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlseturloverlaymode__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlshadow(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlshadow__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlshow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrlshow__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlshown(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlshown__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlstyle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlstyle__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltext__scalar__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltextcolor(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltextcolor__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltextheight(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltextheight__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltextsecondary(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltextsecondary__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltextselection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltextselection__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltextwidth(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltextwidth__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltooltip(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltooltip__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrltype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrltype__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlurl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlurl__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlurloverlaymode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlurloverlaymode__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrlvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrlvisible__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrowcontrols(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctrowcontrols__control__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctrowcount(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ctrowcount__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctsetcursel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctsetcursel__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctsetdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctsetdata__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctsetheadertemplate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctsetheadertemplate__control__config__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctsetrowtemplate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctsetrowtemplate__control__config__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctsetvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctsetvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ctvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ctvalue__control__scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatoraddons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatoraddons__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatorcamera()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__curatorcamera__ret__object));
}

extern "C" __declspec(dllexport) game_value * curatorcameraarea(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatorcameraarea__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatorcameraareaceiling(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatorcameraareaceiling__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatorcoef(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__curatorcoef__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatoreditableobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatoreditableobjects__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatoreditingarea(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatoreditingarea__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatoreditingareatype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatoreditingareatype__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatormouseover()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__curatormouseover__ret__object));
}

extern "C" __declspec(dllexport) game_value * curatorpoints(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatorpoints__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatorregisteredobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatorregisteredobjects__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * curatorselected()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__curatorselected__ret__array));
}

extern "C" __declspec(dllexport) game_value * curatorwaypointcost(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__curatorwaypointcost__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * current3denoperation()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__current3denoperation__ret__string));
}

extern "C" __declspec(dllexport) game_value * currentchannel()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__currentchannel__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * currentcommand(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentcommand__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentmagazine(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentmagazine__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentmagazinedetail(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentmagazinedetail__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentmagazinedetailturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__currentmagazinedetailturret__object__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentmagazineturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__currentmagazineturret__object__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentmuzzle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentmuzzle__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentnamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__currentnamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * currentpilot(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentpilot__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currenttask(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currenttask__object__ret__task, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currenttasks(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currenttasks__team_member__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentthrowable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentthrowable__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentvisionmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__currentvisionmode__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentwaypoint(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentwaypoint__group__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentweapon(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentweapon__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentweaponmode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__currentweaponmode__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentweaponturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__currentweaponturret__object__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * currentzeroing(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__currentzeroing__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cursorobject()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cursorobject__ret__object));
}

extern "C" __declspec(dllexport) game_value * cursortarget()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__cursortarget__ret__object));
}

extern "C" __declspec(dllexport) game_value * customchat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__customchat__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * customradio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__customradio__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * customwaypointposition()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__customwaypointposition__ret__array));
}

extern "C" __declspec(dllexport) game_value * cutfadeout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__cutfadeout__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cutobj(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__cutobj__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cutrsc(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__cutrsc__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * cuttext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__cuttext__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * damage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__damage__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * date()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__date__ret__array));
}

extern "C" __declspec(dllexport) game_value * datetonumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__datetonumber__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * daytime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__daytime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * deactivatekey(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deactivatekey__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * debriefingtext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__debriefingtext__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * debugfsm(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__debugfsm__scalar__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * debuglog(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__debuglog__any__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * decaygraphvalues(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__decaygraphvalues__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * default(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__default__code__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deg(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deg__scalar_nan__ret__scalar_nan, *right_arg));
}

extern "C" __declspec(dllexport) game_value * delete3denentities(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__delete3denentities__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deleteat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__deleteat__hashmap__side_config__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletecenter(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletecenter__side__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletecollection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletecollection__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deleteeditorobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__deleteeditorobject__control__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletegroup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletegroup__group__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletegroupwhenempty(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__deletegroupwhenempty__group__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deleteidentity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deleteidentity__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletelocation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletelocation__location__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletemarker(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletemarker__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletemarkerlocal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletemarkerlocal__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deleterange(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__deleterange__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deleteresources(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__deleteresources__team_member__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletesite(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletesite__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletestatus(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletestatus__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deleteteam(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deleteteam__team_member__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletevehicle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletevehicle__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletevehiclecrew(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__deletevehiclecrew__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * deletewaypoint(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__deletewaypoint__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * detach(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__detach__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * detectedmines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__detectedmines__side__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_activemissionfsms()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_activemissionfsms__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_activescripts()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_activescripts__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_activesqfscripts()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_activesqfscripts__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_activesqsscripts()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_activesqsscripts__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_allmissioneventhandlers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_allmissioneventhandlers__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_captureframe(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_captureframe__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_captureframetofile(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_captureframetofile__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_captureslowframe(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_captureslowframe__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_codeperformance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_codeperformance__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_deltatime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_deltatime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * diag_drawmode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_drawmode__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_dumpcalltracetolog()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_dumpcalltracetolog__ret__bool));
}

extern "C" __declspec(dllexport) game_value * diag_dumpscriptassembly(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_dumpscriptassembly__code__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_dumpterrainsynth()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_dumpterrainsynth__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_dynamicsimulationend(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_dynamicsimulationend__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_enable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__diag_enable__string__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_enabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_enabled__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_exportconfig(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_exportconfig__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_exportterrainsvg(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_exportterrainsvg__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_fps()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_fps__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * diag_fpsmin()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_fpsmin__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * diag_frameno()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_frameno__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * diag_getterrainsegmentoffset(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_getterrainsegmentoffset__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_lightnewload(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_lightnewload__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_list(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_list__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_localized(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_localized__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_log(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_log__any__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_logslowframe(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_logslowframe__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_mergeconfigfile(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_mergeconfigfile__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_recordturretlimits(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_recordturretlimits__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_resetfsm()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_resetfsm__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * diag_resetshapes()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_resetshapes__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * diag_scope()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_scope__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * diag_setlightnew(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_setlightnew__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * diag_stacktrace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_stacktrace__ret__array));
}

extern "C" __declspec(dllexport) game_value * diag_ticktime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diag_ticktime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * diag_toggle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__diag_toggle__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dialog()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__dialog__ret__bool));
}

extern "C" __declspec(dllexport) game_value * diaryrecordnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__diaryrecordnull__ret__task));
}

extern "C" __declspec(dllexport) game_value * diarysubjectexists(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__diarysubjectexists__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * didjip()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__didjip__ret__bool));
}

extern "C" __declspec(dllexport) game_value * didjipowner(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__didjipowner__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * difficulty()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__difficulty__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * difficultyenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__difficultyenabled__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * difficultyenabledrtd()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__difficultyenabledrtd__ret__bool));
}

extern "C" __declspec(dllexport) game_value * difficultyoption(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__difficultyoption__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * direction(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__direction__location__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * directionstabilizationenabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__directionstabilizationenabled__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * directsay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__directsay__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disableai(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disableai__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disablebrakes(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disablebrakes__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disablecollisionwith(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disablecollisionwith__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disableconversation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disableconversation__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disabledebriefingstats()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__disabledebriefingstats__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * disablemapindicators(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__disablemapindicators__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disablenvgequipment(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disablenvgequipment__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disableremotesensors(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__disableremotesensors__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disableserialization()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__disableserialization__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * disabletiequipment(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disabletiequipment__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disableuavconnectability(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__disableuavconnectability__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * disableuserinput(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__disableuserinput__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayaddeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__displayaddeventhandler__display__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displaychild(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__displaychild__display__ret__display, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayctrl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__displayctrl__display__scalar__ret__control, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displaynull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__displaynull__ret__display));
}

extern "C" __declspec(dllexport) game_value * displayparent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__displayparent__display__ret__display, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayremovealleventhandlers(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__displayremovealleventhandlers__display__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayremoveeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__displayremoveeventhandler__display__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayseteventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__displayseteventhandler__display__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayuniquename(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__displayuniquename__display__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * displayupdate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__displayupdate__display__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dissolveteam(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__dissolveteam__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * distance(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__distance__array__location__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * distance2d(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__distance2d__object_array__object_array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * distancesqr(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__distancesqr__array__location__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * distributionregion()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__distributionregion__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * do3denaction(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__do3denaction__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * doartilleryfire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__doartilleryfire__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dofire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__dofire__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dofollow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__dofollow__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dofsm(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__dofsm__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dogetout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__dogetout__object_array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * domove(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__domove__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * doorphase(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__doorphase__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dostop(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__dostop__object_array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dosuppressivefire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__dosuppressivefire__object_array__object_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dotarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__dotarget__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dowatch(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__dowatch__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawarrow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawarrow__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawellipse(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawellipse__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawicon__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawicon3d(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__drawicon3d__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawlaser(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__drawlaser__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawline(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawline__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawline3d(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__drawline3d__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawlink(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawlink__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawlocation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawlocation__control__location__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawpolygon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawpolygon__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawrectangle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawrectangle__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drawtriangle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__drawtriangle__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * driver(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__driver__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * drop(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__drop__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dynamicsimulationdistance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistance__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dynamicsimulationdistancecoef(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistancecoef__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dynamicsimulationenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationenabled__group__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * dynamicsimulationsystemenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__dynamicsimulationsystemenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * east()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__east__ret__side));
}

extern "C" __declspec(dllexport) game_value * echo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__echo__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * edit3denmissionattributes(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__edit3denmissionattributes__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * editobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__editobject__control__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * editorseteventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__editorseteventhandler__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * effectivecommander(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__effectivecommander__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * elevateperiscope(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__elevateperiscope__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * emptypositions(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__emptypositions__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableai(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableai__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableaifeature(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableaifeature__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableaimprecision(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableaimprecision__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableattack(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableattack__object_group__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableaudiofeature(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableaudiofeature__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableautostartuprtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableautostartuprtd__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableautotrimrtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableautotrimrtd__object__bool__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablecamshake(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablecamshake__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablecaustics(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablecaustics__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablechannel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablechannel__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablecollisionwith(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablecollisionwith__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablecopilot(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablecopilot__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enabledebriefingstats(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enabledebriefingstats__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablediaglegend(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablediaglegend__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enabledirectionstabilization(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enabledirectionstabilization__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enabledynamicsimulation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enabledynamicsimulation__group__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enabledynamicsimulationsystem(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enabledynamicsimulationsystem__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableenddialog()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__enableenddialog__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * enableengineartillery(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enableengineartillery__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableenvironment(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enableenvironment__bool_array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablefatigue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablefatigue__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablegunlights(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablegunlights__object_group__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableinfopanelcomponent(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableinfopanelcomponent__object_array__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableirlasers(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableirlasers__object_group__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablemimics(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablemimics__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablepersonturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablepersonturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableradio(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enableradio__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablereload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablereload__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableropeattach(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableropeattach__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablesatnormalondetail(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablesatnormalondetail__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablesaving(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablesaving__bool_array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablesentences(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablesentences__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablesimulation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablesimulation__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablesimulationglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablesimulationglobal__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablestamina(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablestamina__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablestressdamage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enablestressdamage__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableteamswitch(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enableteamswitch__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enabletraffic(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enabletraffic__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableuavconnectability(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableuavconnectability__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableuavwaypoints(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableuavwaypoints__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablevehiclecargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablevehiclecargo__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enablevehiclesensor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enablevehiclesensor__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enableweapondisassembly(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__enableweapondisassembly__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * endl()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__endl__ret__string));
}

extern "C" __declspec(dllexport) game_value * endloadingscreen()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__endloadingscreen__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * endmission(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__endmission__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * engineon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__engineon__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enginesisonrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enginesisonrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enginespowerrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enginespowerrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enginesrpmrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enginesrpmrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * enginestorquertd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__enginestorquertd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * entities(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__entities__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * environmentenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__environmentenabled__ret__array));
}

extern "C" __declspec(dllexport) game_value * environmentvolume()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__environmentvolume__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * equipmentdisabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__equipmentdisabled__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * estimatedendservertime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__estimatedendservertime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * estimatedtimeleft(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__estimatedtimeleft__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * evalobjectargument(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__evalobjectargument__control__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * everybackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__everybackpack__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * everycontainer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__everycontainer__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * exec(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__exec__any__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * execeditorscript(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__execeditorscript__control__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * execfsm(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__execfsm__any__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * execvm(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__execvm__any__string__ret__script, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * expecteddestination(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__expecteddestination__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * exportjipmessages(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__exportjipmessages__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * eyedirection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__eyedirection__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * eyepos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__eyepos__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * face(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__face__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * faction(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__faction__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fadeenvironment(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__fadeenvironment__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fademusic(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__fademusic__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * faderadio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__faderadio__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fadesound(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__fadesound__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fadespeech(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__fadespeech__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * failmission(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__failmission__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fileexists(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__fileexists__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fillweaponsfrompool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__fillweaponsfrompool__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * find(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__find__string__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findany(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findany__array__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findcover(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findcover__object__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * finddisplay(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__finddisplay__string__ret__display, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findeditorobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findeditorobject__control__any__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findemptyposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findemptyposition__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findemptypositionready(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findemptypositionready__array__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findif(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findif__array__code__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * findnearestenemy(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__findnearestenemy__object__object_array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * finishmissioninit()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__finishmissioninit__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * finite(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__finite__scalar_nan__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__fire__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fireattarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__fireattarget__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * firstbackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__firstbackpack__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flag(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__flag__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flaganimationphase(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__flaganimationphase__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flagowner(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__flagowner__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flagside(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__flagside__object__ret__side, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flagtexture(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__flagtexture__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flatten(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__flatten__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fleeing(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__fleeing__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flyinheight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__flyinheight__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * flyinheightasl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__flyinheightasl__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * focusedctrl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__focusedctrl__display__ret__control, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fog()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__fog__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * fogforecast()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__fogforecast__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * fogparams()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__fogparams__ret__array));
}

extern "C" __declspec(dllexport) game_value * forceadduniform(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forceadduniform__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forceatpositionrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__forceatpositionrtd__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcecadetdifficulty(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__forcecadetdifficulty__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcedmap()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__forcedmap__ret__array));
}

extern "C" __declspec(dllexport) game_value * forceend()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__forceend__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * forceflagtexture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forceflagtexture__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcefollowroad(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forcefollowroad__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcegeneratorrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__forcegeneratorrtd__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcemap(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__forcemap__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcerespawn(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__forcerespawn__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcespeed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forcespeed__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forceunicode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__forceunicode__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forcewalk(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forcewalk__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forceweaponfire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forceweaponfire__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forceweatherchange()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__forceweatherchange__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * foreach(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__foreach__code__hashmap__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * foreachmember(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__foreachmember__code__team_member__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * foreachmemberagent(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__foreachmemberagent__code__team_member__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * foreachmemberteam(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__foreachmemberteam__code__team_member__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * forgettarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__forgettarget__object_group__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * format(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__format__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formation__team_member__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formationdirection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formationdirection__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formationleader(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formationleader__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formationmembers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formationmembers__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formationposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formationposition__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formationtask(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formationtask__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formattext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formattext__array__ret__text, *right_arg));
}

extern "C" __declspec(dllexport) game_value * formleader(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__formleader__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * freeextension(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__freeextension__string__ret__bool_nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * freelook()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__freelook__ret__bool));
}

extern "C" __declspec(dllexport) game_value * from(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__from__for__scalar__ret__for, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fromeditor(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__fromeditor__team_member__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fuel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__fuel__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * fullcrew(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__fullcrew__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gearidcammocount(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gearidcammocount__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gearslotammocount(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gearslotammocount__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gearslotdata(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gearslotdata__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gesturestate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gesturestate__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__get__hashmap__side_config__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3denactionstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3denactionstate__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3denattribute(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__scalar__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3dencamera()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__get3dencamera__ret__object));
}

extern "C" __declspec(dllexport) game_value * get3denconnections(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3denconnections__any__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3denentity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3denentity__scalar__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3denentityid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3denentityid__any__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3dengrid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3dengrid__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3deniconsvisible()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__get3deniconsvisible__ret__array));
}

extern "C" __declspec(dllexport) game_value * get3denlayerentities(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3denlayerentities__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3denlinesvisible()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__get3denlinesvisible__ret__array));
}

extern "C" __declspec(dllexport) game_value * get3denmissionattribute(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__get3denmissionattribute__string__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * get3denmouseover()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__get3denmouseover__ret__array));
}

extern "C" __declspec(dllexport) game_value * get3denselected(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__get3denselected__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getaimingcoef(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getaimingcoef__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallenv3dsoundcontrollers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallenv3dsoundcontrollers__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallenvsoundcontrollers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallenvsoundcontrollers__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallhitpointsdamage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallhitpointsdamage__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallownedmines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallownedmines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallpylonsinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallpylonsinfo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallsoundcontrollers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallsoundcontrollers__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getallunittraits(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getallunittraits__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getammocargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getammocargo__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getanimaimprecision(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getanimaimprecision__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getanimspeedcoef(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getanimspeedcoef__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getarray(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getarray__config__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getartilleryammo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getartilleryammo__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getartillerycomputersettings()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getartillerycomputersettings__ret__array));
}

extern "C" __declspec(dllexport) game_value * getartilleryeta(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getartilleryeta__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getassetdlcinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getassetdlcinfo__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getassignedcuratorlogic(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorlogic__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getassignedcuratorunit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorunit__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getattacktarget(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getattacktarget__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getaudiooptionvolumes()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getaudiooptionvolumes__ret__array));
}

extern "C" __declspec(dllexport) game_value * getbackpackcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getbackpackcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getbleedingremaining(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getbleedingremaining__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getburningvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getburningvalue__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcalculateplayervisibilitybyfriendly()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getcalculateplayervisibilitybyfriendly__ret__bool));
}

extern "C" __declspec(dllexport) game_value * getcameraviewdirection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcameraviewdirection__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcargoindex(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getcargoindex__object__object__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcenterofmass(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcenterofmass__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getclientstate()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getclientstate__ret__string));
}

extern "C" __declspec(dllexport) game_value * getclientstatenumber()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getclientstatenumber__ret__string));
}

extern "C" __declspec(dllexport) game_value * getcompatiblepylonmagazines(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getcompatiblepylonmagazines__string__string_scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getconnecteduav(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getconnecteduav__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getconnecteduavunit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getconnecteduavunit__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcontainermaxload(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcontainermaxload__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcorpse(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcorpse__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcruisecontrol(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcruisecontrol__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcursorobjectparams()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getcursorobjectparams__ret__array));
}

extern "C" __declspec(dllexport) game_value * getcustomaimcoef(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcustomaimcoef__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcustomsoundcontroller(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontroller__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getcustomsoundcontrollercount(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontrollercount__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdammage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdammage__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdebriefingtext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdebriefingtext__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdescription(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdescription__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getdir__object_array__object_array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdirvisual(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getdirvisual__object_array__object_array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdiverstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdiverstate__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdlcassetsusage()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getdlcassetsusage__ret__array));
}

extern "C" __declspec(dllexport) game_value * getdlcassetsusagebyname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdlcassetsusagebyname__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdlcs(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdlcs__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getdlcusagetime(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getdlcusagetime__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * geteditorcamera(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__geteditorcamera__control__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * geteditormode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__geteditormode__control__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * geteditorobjectscope(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__geteditorobjectscope__control__string__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getelevationoffset()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getelevationoffset__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * getenginetargetrpmrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getenginetargetrpmrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getenv3dsoundcontroller(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getenv3dsoundcontroller__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getenvsoundcontroller(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getenvsoundcontroller__array__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * geteventhandlerinfo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__geteventhandlerinfo__object_group__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getfatigue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getfatigue__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getfieldmanualstartpage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getfieldmanualstartpage__display__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getforcedflagtexture(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getforcedflagtexture__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getforcedspeed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getforcedspeed__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getfriend(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getfriend__side__side__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getfsmvariable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getfsmvariable__scalar__string_array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getfuelcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getfuelcargo__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getgraphvalues(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getgraphvalues__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getgroupicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getgroupicon__group__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getgroupiconparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getgroupiconparams__group__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getgroupicons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getgroupicons__group__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gethidefrom(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__gethidefrom__object__object__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gethit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__gethit__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gethitindex(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__gethitindex__object__scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gethitpointdamage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__gethitpointdamage__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getitemcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getitemcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getlighting()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getlighting__ret__array));
}

extern "C" __declspec(dllexport) game_value * getlightingat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getlightingat__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getloadedmodsinfo()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getloadedmodsinfo__ret__array));
}

extern "C" __declspec(dllexport) game_value * getmagazinecargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmagazinecargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmarkercolor(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmarkercolor__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmarkerpos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmarkerpos__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmarkersize(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmarkersize__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmarkertype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmarkertype__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmass(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmass__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmissionconfig(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmissionconfig__string__ret__config, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmissionconfigvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmissionconfigvalue__string_array__ret__array_string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmissiondlcs()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getmissiondlcs__ret__array));
}

extern "C" __declspec(dllexport) game_value * getmissionlayerentities(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmissionlayerentities__string_scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmissionlayers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getmissionlayers__ret__array));
}

extern "C" __declspec(dllexport) game_value * getmissionpath(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmissionpath__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmodelinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getmodelinfo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getmouseposition()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getmouseposition__ret__array));
}

extern "C" __declspec(dllexport) game_value * getmusicplayedtime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getmusicplayedtime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * getnumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getnumber__config__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectargument(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getobjectargument__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectchildren(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getobjectchildren__control__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectdlc(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjectdlc__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectfov(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjectfov__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjectid__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectmaterials(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjectmaterials__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectproxy(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getobjectproxy__control__string__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectscale(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjectscale__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjecttextures(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjecttextures__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjecttype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getobjecttype__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getobjectviewdistance()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getobjectviewdistance__ret__array));
}

extern "C" __declspec(dllexport) game_value * getopticsmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getopticsmode__object__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getordefault(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getordefault__hashmap__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getordefaultcall(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getordefaultcall__hashmap__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getoxygenremaining(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getoxygenremaining__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpersonuseddlcs(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getpersonuseddlcs__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpilotcameradirection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getpilotcameradirection__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpilotcameraposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getpilotcameraposition__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpilotcamerarotation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getpilotcamerarotation__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpilotcameratarget(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getpilotcameratarget__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpipviewdistance()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getpipviewdistance__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * getplatenumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getplatenumber__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getplayerchannel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getplayerchannel__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getplayerid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getplayerid__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getplayerscores(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getplayerscores__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getplayeruid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getplayeruid__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getplayervonvolume(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getplayervonvolume__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getpos__object_array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposasl__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposaslvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposaslvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposaslw(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposaslw__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposatl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposatl__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposatlvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposatlvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposworld(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposworld__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getposworldvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getposworldvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getpylonmagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getpylonmagazines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getreldir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getreldir__object__object_array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getrelpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getrelpos__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getremotesensorsdisabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getremotesensorsdisabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * getrepaircargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getrepaircargo__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getresolution()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getresolution__ret__array));
}

extern "C" __declspec(dllexport) game_value * getroadinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getroadinfo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getrotorbrakertd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getrotorbrakertd__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getsensortargets(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getsensortargets__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getsensorthreats(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getsensorthreats__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getshadowdistance()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getshadowdistance__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * getshotparents(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getshotparents__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getslingload(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getslingload__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getsoundcontroller(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getsoundcontroller__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getsoundcontrollerresult(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getsoundcontrollerresult__object__config__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getspeed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getspeed__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getstamina(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getstamina__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getstatvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getstatvalue__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getsteamfriendsservers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getsteamfriendsservers__ret__array));
}

extern "C" __declspec(dllexport) game_value * getsubtitleoptions()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getsubtitleoptions__ret__array));
}

extern "C" __declspec(dllexport) game_value * getsuppression(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getsuppression__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getterraingrid()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getterraingrid__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * getterrainheight(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getterrainheight__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getterrainheightasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getterrainheightasl__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getterraininfo()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getterraininfo__ret__array));
}

extern "C" __declspec(dllexport) game_value * gettext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gettext__config__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gettextraw(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gettextraw__config__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gettextureinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gettextureinfo__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gettextwidth(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__gettextwidth__string__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gettiparameters()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__gettiparameters__ret__hashmap));
}

extern "C" __declspec(dllexport) game_value * gettotaldlcusagetime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__gettotaldlcusagetime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * gettowparent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gettowparent__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gettrimoffsetrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gettrimoffsetrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getturretlimits(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getturretlimits__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getturretopticsmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getturretopticsmode__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getunitfreefallinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getunitfreefallinfo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getunitloadout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getunitloadout__config__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getunittrait(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getunittrait__object__string__ret__nothing_bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getunloadincombat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getunloadincombat__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getuserinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getuserinfo__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getusermfdtext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getusermfdtext__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getusermfdvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getusermfdvalue__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getvariable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__getvariable__location__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getvehiclecargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getvehiclecargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getvehicletipars(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getvehicletipars__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getvideooptions()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__getvideooptions__ret__hashmap));
}

extern "C" __declspec(dllexport) game_value * getweaponcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getweaponcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getweaponsway(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getweaponsway__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getwingsorientationrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getwingsorientationrtd__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getwingspositionrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getwingspositionrtd__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * getwppos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__getwppos__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * glanceat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__glanceat__object_array__object_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * globalchat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__globalchat__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * globalradio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__globalradio__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * goggles(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__goggles__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * group(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__group__object__ret__group, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupchat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__groupchat__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupfromnetid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__groupfromnetid__string__ret__group, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupiconselectable()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__groupiconselectable__ret__bool));
}

extern "C" __declspec(dllexport) game_value * groupiconsvisible()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__groupiconsvisible__ret__array));
}

extern "C" __declspec(dllexport) game_value * groupid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__groupid__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupowner(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__groupowner__group__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupradio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__groupradio__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groups(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__groups__side__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupselectedunits(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__groupselectedunits__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * groupselectunit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__groupselectunit__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * grpnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__grpnull__ret__group));
}

extern "C" __declspec(dllexport) game_value * gunner(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__gunner__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * gusts()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__gusts__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * halt()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__halt__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * handgunitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__handgunitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * handgunmagazine(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__handgunmagazine__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * handgunweapon(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__handgunweapon__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * handshit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__handshit__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hashvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hashvalue__object_side__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hasinterface()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__hasinterface__ret__bool));
}

extern "C" __declspec(dllexport) game_value * haspilotcamera(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__haspilotcamera__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hasweapon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hasweapon__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcallgroups(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hcallgroups__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcgroupparams(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hcgroupparams__object__group__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcleader(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hcleader__group__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcremoveallgroups(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hcremoveallgroups__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcremovegroup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hcremovegroup__object__group__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcselected(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hcselected__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcselectgroup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hcselectgroup__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcsetgroup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hcsetgroup__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcshowbar(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hcshowbar__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hcshownbar()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__hcshownbar__ret__bool));
}

extern "C" __declspec(dllexport) game_value * headgear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__headgear__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hidebody(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hidebody__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hideobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hideobject__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hideobjectglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hideobjectglobal__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hideselection(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hideselection__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hint(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hint__text_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hintc(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__hintc__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hintcadet(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hintcadet__text_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hintsilent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hintsilent__text_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hmd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hmd__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hostmission(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__hostmission__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * htmlload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__htmlload__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * hudmovementlevels()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__hudmovementlevels__ret__array));
}

extern "C" __declspec(dllexport) game_value * humidity()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__humidity__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * image(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__image__string__ret__text, *right_arg));
}

extern "C" __declspec(dllexport) game_value * importallgroups(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__importallgroups__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * importance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__importance__location__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * in(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__in__array__location__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inarea(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__inarea__array__location__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inareaarray(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__location__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * incapacitatedstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__incapacitatedstate__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * independent()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__independent__ret__side));
}

extern "C" __declspec(dllexport) game_value * inflame(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__inflame__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inflamed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__inflamed__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * infopanel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__infopanel__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * infopanelcomponentenabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponentenabled__object_array__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * infopanelcomponents(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponents__object_array__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * infopanels(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__infopanels__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ingameuiseteventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ingameuiseteventhandler__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inheritsfrom(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__inheritsfrom__config__ret__config, *right_arg));
}

extern "C" __declspec(dllexport) game_value * initambientlife()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__initambientlife__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * inpolygon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__inpolygon__array__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inputaction(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__inputaction__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inputcontroller(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__inputcontroller__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inputmouse(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__inputmouse__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inrangeofartillery(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__inrangeofartillery__array__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * insert(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__insert__hashmap__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * inserteditorobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__inserteditorobject__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * insidebuilding(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__insidebuilding__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * intersect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__intersect__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * is3den()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__is3den__ret__bool));
}

extern "C" __declspec(dllexport) game_value * is3denmultiplayer()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__is3denmultiplayer__ret__bool));
}

extern "C" __declspec(dllexport) game_value * is3denpreview()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__is3denpreview__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isabletobreathe(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isabletobreathe__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isactionmenuvisible()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isactionmenuvisible__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isagent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isagent__team_member__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isaimprecisionenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isaimprecisionenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isallowedcrewinimmobile(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isallowedcrewinimmobile__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isarray(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isarray__config__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isautohoveron(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isautohoveron__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isautonomous(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isautonomous__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isautostartupenabledrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isautostartupenabledrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isautotest()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isautotest__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isautotrimonrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isautotrimonrtd__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isawake(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isawake__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isbleeding(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isbleeding__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isburning(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isburning__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isclass(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isclass__config__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * iscollisionlighton(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__iscollisionlighton__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * iscopilotenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__iscopilotenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isdamageallowed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isdamageallowed__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isdedicated()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isdedicated__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isdlcavailable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isdlcavailable__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isengineon(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isengineon__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequalref(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequalref__any__any__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequalto(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequalto__any__any__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequaltype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequaltype__any__any__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequaltypeall(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequaltypeall__any__any__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequaltypeany(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequaltypeany__any__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequaltypearray(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequaltypearray__any__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isequaltypeparams(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isequaltypeparams__any__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isfilepatchingenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isfilepatchingenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isfinal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isfinal__code_string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isflashlighton(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isflashlighton__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isflatempty(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isflatempty__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isforcedwalk(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isforcedwalk__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isformationleader(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isformationleader__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isgamefocused()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isgamefocused__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isgamepaused()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isgamepaused__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isgroupdeletedwhenempty(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isgroupdeletedwhenempty__group__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ishidden(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ishidden__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isinremainscollector(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isinremainscollector__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isinstructorfigureenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isinstructorfigureenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isirlaseron(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isirlaseron__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * iskeyactive(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__iskeyactive__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * iskindof(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__iskindof__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * islaseron(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__islaseron__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * islighton(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__islighton__object_array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * islocalized(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__islocalized__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ismanualfire(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ismanualfire__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ismarkedforcollection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ismarkedforcollection__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ismissionprofilenamespaceloaded()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__ismissionprofilenamespaceloaded__ret__bool));
}

extern "C" __declspec(dllexport) game_value * ismultiplayer()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__ismultiplayer__ret__bool));
}

extern "C" __declspec(dllexport) game_value * ismultiplayersolo()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__ismultiplayersolo__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isnil(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isnil__code_string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isnotequalref(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isnotequalref__any__any__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isnotequalto(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isnotequalto__any__any__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isnull(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isnull__location__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isnumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isnumber__config__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isobjecthidden(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isobjecthidden__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isobjectrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isobjectrtd__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isonroad(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isonroad__object_array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ispipenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__ispipenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isplayer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isplayer__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isrealtime(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isrealtime__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isremoteexecuted()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isremoteexecuted__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isremoteexecutedjip()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isremoteexecutedjip__ret__bool));
}

extern "C" __declspec(dllexport) game_value * issaving()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__issaving__ret__bool));
}

extern "C" __declspec(dllexport) game_value * issensortargetconfirmed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__issensortargetconfirmed__object__side__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isserver()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isserver__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isshowing3dicons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isshowing3dicons__control__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * issimpleobject(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__issimpleobject__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * issprintallowed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__issprintallowed__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isstaminaenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isstaminaenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * issteammission()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__issteammission__ret__bool));
}

extern "C" __declspec(dllexport) game_value * issteamoverlayenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__issteamoverlayenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isstreamfriendlyuienabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isstreamfriendlyuienabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isstressdamageenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isstressdamageenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * istext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__istext__config__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * istouchingground(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__istouchingground__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isturnedout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isturnedout__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * istuthintsenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__istuthintsenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isuavconnectable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isuavconnectable__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isuavconnected(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isuavconnected__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isuicontext()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__isuicontext__ret__bool));
}

extern "C" __declspec(dllexport) game_value * isuniformallowed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isuniformallowed__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isvehiclecargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isvehiclecargo__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isvehicleradaron(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isvehicleradaron__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isvehiclesensorenabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__isvehiclesensorenabled__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * iswalking(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__iswalking__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isweapondeployed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isweapondeployed__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * isweaponrested(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__isweaponrested__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * itemcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__itemcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * items(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__items__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * itemswithmagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__itemswithmagazines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * join(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__join__array__object_group__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * joinas(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__joinas__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * joinassilent(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__joinassilent__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * joinsilent(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__joinsilent__array__object_group__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * joinstring(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__joinstring__array__string__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbadddatabase(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbadddatabase__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbadddatabasetargets(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbadddatabasetargets__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbaddtopic(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbaddtopic__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbhastopic(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbhastopic__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbreact(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbreact__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbremovetopic(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbremovetopic__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbtell(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbtell__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * kbwassaid(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__kbwassaid__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * keyimage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__keyimage__string_scalar__ret__text, *right_arg));
}

extern "C" __declspec(dllexport) game_value * keyname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__keyname__string_scalar__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * keys(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__keys__hashmap__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * knowsabout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__knowsabout__side__object__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * land(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__land__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * landat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__landat__object__object_scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * landresult(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__landresult__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * language()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__language__ret__string));
}

extern "C" __declspec(dllexport) game_value * lasertarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lasertarget__object__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbadd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbadd__control__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbclear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lbclear__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbcolor__control__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbcolorright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbcolorright__control__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbcursel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lbcursel__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbdata__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbdelete(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbdelete__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbisselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbisselected__control__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbpicture__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbpictureright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbpictureright__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbselection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lbselection__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetcolorright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetcolorright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetcursel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetcursel__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetdata__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicture__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicturecolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicturecolordisabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolordisabled__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicturecolorselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolorselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpictureright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpictureright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicturerightcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicturerightcolordisabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolordisabled__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetpicturerightcolorselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolorselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetselectcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetselectcolorright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolorright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsettext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsettext__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsettextright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsettextright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsettooltip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsettooltip__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsetvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsetvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsize(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lbsize__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsort(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lbsort__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsortby(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbsortby__control_scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbsortbyvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lbsortbyvalue__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbtext__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbtextright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbtextright__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbtooltip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbtooltip__control__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lbvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lbvalue__control__scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leader(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leader__team_member__ret__team_member, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboarddeinit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboarddeinit__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardgetrows(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardgetrows__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardinit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardinit__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardrequestrowsfriends(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsfriends__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardrequestrowsglobal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobal__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardrequestrowsglobalarounduser(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobalarounduser__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardsrequestuploadscore(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscore__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardsrequestuploadscorekeepbest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leaderboardstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__leaderboardstate__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * leavevehicle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__leavevehicle__group__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * librarycredits()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__librarycredits__ret__array));
}

extern "C" __declspec(dllexport) game_value * librarydisclaimers()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__librarydisclaimers__ret__array));
}

extern "C" __declspec(dllexport) game_value * lifestate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lifestate__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lightattachobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lightattachobject__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lightdetachobject(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lightdetachobject__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lightison(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lightison__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lightnings()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__lightnings__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * limitspeed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__limitspeed__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * linearconversion(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__linearconversion__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * linebreak()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__linebreak__ret__text));
}

extern "C" __declspec(dllexport) game_value * lineintersects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lineintersects__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lineintersectsobjs(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lineintersectsobjs__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lineintersectssurfaces(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lineintersectssurfaces__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lineintersectswith(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lineintersectswith__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * linkitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__linkitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * list(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__list__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * listobjects(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__listobjects__control__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * listremotetargets(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__listremotetargets__side__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * listvehiclesensors(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__listvehiclesensors__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ln(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ln__scalar_nan__ret__scalar_nan, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbaddarray(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lnbaddarray__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbaddcolumn(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbaddcolumn__control__scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbaddrow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbaddrow__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbclear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lnbclear__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbcolor__control__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbcolorright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbcolorright__control__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbcurselrow(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lnbcurselrow__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbdata__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbdeletecolumn(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbdeletecolumn__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbdeleterow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbdeleterow__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbgetcolumnsposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lnbgetcolumnsposition__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbpicture__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbpictureright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbpictureright__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetcolorright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolorright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetcolumnspos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolumnspos__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetcurselrow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetcurselrow__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetdata__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicture__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetpicturecolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetpicturecolorright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetpicturecolorselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetpicturecolorselectedright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselectedright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetpictureright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetpictureright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsettext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsettext__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsettextright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsettextright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsettooltip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsettooltip__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsetvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsetvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsize(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lnbsize__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsort(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsort__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsortby(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsortby__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbsortbyvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbsortbyvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbtext__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbtextright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbtextright__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lnbvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lnbvalue__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * load(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__load__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadabs(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__loadabs__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadbackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__loadbackpack__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadconfig(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__loadconfig__string__ret__config, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadfile(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__loadfile__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadgame()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__loadgame__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * loadidentity(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__loadidentity__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadmagazine(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__loadmagazine__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadoverlay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__loadoverlay__control__config__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadstatus(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__loadstatus__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loaduniform(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__loaduniform__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * loadvest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__loadvest__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * local(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__local__group__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * localize(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__localize__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * localnamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__localnamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * locationnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__locationnull__ret__location));
}

extern "C" __declspec(dllexport) game_value * locationposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__locationposition__location__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lock(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lock__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockcamerato(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockcamerato__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockcargo__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockdriver(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockdriver__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * locked(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__locked__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockedcamerato(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockedcamerato__object__array__ret__nothing_object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockedcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockedcargo__object__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockeddriver(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lockeddriver__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockedinventory(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lockedinventory__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockedturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockedturret__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockidentity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lockidentity__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockinventory(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockinventory__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lockwp(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lockwp__object_group__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * logentities()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__logentities__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * lognetwork(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lognetwork__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lognetworkterminate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__lognetworkterminate__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lookat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lookat__object_array__object_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * lookatpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__lookatpos__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinecargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinecargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazines__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesallturrets(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesallturrets__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesammo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesammo__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesammocargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesammocargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesammofull(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesammofull__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesdetail(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesdetail__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesdetailbackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailbackpack__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesdetailuniform(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailuniform__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesdetailvest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailvest__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazinesturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__magazinesturret__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * magazineturretammo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__magazineturretammo__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * mapanimadd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__mapanimadd__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * mapanimclear()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__mapanimclear__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * mapanimcommit()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__mapanimcommit__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * mapanimdone()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__mapanimdone__ret__bool));
}

extern "C" __declspec(dllexport) game_value * mapcenteroncamera(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__mapcenteroncamera__control__bool__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * mapgridposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__mapgridposition__object_array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markasfinishedonsteam()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__markasfinishedonsteam__ret__bool));
}

extern "C" __declspec(dllexport) game_value * markeralpha(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markeralpha__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markerbrush(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markerbrush__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markerchannel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markerchannel__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markercolor(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markercolor__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markerdir(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markerdir__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markerpolyline(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markerpolyline__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markerpos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markerpos__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markershadow(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markershadow__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markershape(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markershape__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markersize(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markersize__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markertext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markertext__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * markertype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__markertype__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * matrixmultiply(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__matrixmultiply__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * matrixtranspose(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__matrixtranspose__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * maxload(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__maxload__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * members(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__members__team_member__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuaction__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuadd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuadd__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuchecked(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuchecked__control__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuclear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__menuclear__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menucollapse(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menucollapse__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menudata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menudata__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menudelete(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menudelete__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuenable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuenable__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuenabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuenabled__control__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuexpand(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuexpand__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuhover(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__menuhover__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menupicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menupicture__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusetaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusetaction__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusetcheck(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusetcheck__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusetdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusetdata__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusetpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusetpicture__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusetshortcut(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusetshortcut__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusettext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusettext__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuseturl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuseturl__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusetvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusetvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menushortcut(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menushortcut__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menushortcuttext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menushortcuttext__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusize(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusize__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menusort(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menusort__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menutext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menutext__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuurl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuurl__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * menuvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__menuvalue__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * merge(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__merge__hashmap__hashmap_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * mineactive(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__mineactive__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * minedetectedby(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__minedetectedby__object__side__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * missiletarget(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__missiletarget__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * missiletargetpos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__missiletargetpos__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * missionconfigfile()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionconfigfile__ret__config));
}

extern "C" __declspec(dllexport) game_value * missiondifficulty()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missiondifficulty__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * missionend()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionend__ret__array));
}

extern "C" __declspec(dllexport) game_value * missionname()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionname__ret__string));
}

extern "C" __declspec(dllexport) game_value * missionnamesource()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionnamesource__ret__string));
}

extern "C" __declspec(dllexport) game_value * missionnamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionnamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * missionprofilenamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionprofilenamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * missionstart()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionstart__ret__array));
}

extern "C" __declspec(dllexport) game_value * missionversion()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__missionversion__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * mod(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__mod__scalar_nan__scalar_nan__ret__scalar_nan, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * modeltoworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__modeltoworld__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * modeltoworldvisual(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisual__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * modeltoworldvisualworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisualworld__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * modeltoworldworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__modeltoworldworld__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * modparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__modparams__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moonintensity()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__moonintensity__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * moonphase(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__moonphase__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * morale(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__morale__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * move(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__move__object_group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * move3dencamera(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__move3dencamera__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveinany(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveinany__object__object__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveincargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveincommander(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveincommander__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveindriver(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveindriver__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveingunner(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveingunner__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveinturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveinturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveobjecttoend(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveobjecttoend__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveout__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * movetime(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__movetime__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * moveto(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__moveto__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * movetocompleted(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__movetocompleted__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * movetofailed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__movetofailed__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * musicvolume()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__musicvolume__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * name(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__name__location__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * namedproperties(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__namedproperties__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * namesound(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__namesound__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearentities(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nearentities__object_array__scalar_array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestbuilding(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestbuilding__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestlocation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestlocation__array__ret__location, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestlocations(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestlocations__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestlocationwithdubbing(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestlocationwithdubbing__array__ret__location, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestmines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestmines__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nearestobject__array__scalar__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestobjects__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearestterrainobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nearestterrainobjects__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearobjects(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearobjectsready(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nearobjectsready__object_array__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearroads(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nearroads__object_array__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nearsupplies(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nearsupplies__object_array__scalar_array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * neartargets(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__neartargets__object__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * needreload(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__needreload__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * needservice(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__needservice__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * netid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__netid__group__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * netobjnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__netobjnull__ret__netobject));
}

extern "C" __declspec(dllexport) game_value * newoverlay(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__newoverlay__control__config__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nextmenuitemindex(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__nextmenuitemindex__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * nextweatherchange()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__nextweatherchange__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * nil()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__nil__ret__any));
}

extern "C" __declspec(dllexport) game_value * nmenuitems(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__nmenuitems__control__string_scalar__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * not(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__not__bool__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * numberofenginesrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__numberofenginesrtd__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * numbertodate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__numbertodate__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * objectcurators(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__objectcurators__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * objectfromnetid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__objectfromnetid__string__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * objectparent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__objectparent__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * objnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__objnull__ret__object));
}

extern "C" __declspec(dllexport) game_value * objstatus(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__objstatus__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onbriefinggroup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onbriefinggroup__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onbriefingnotes(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onbriefingnotes__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onbriefingplan(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onbriefingplan__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onbriefingteamswitch(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onbriefingteamswitch__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * oncommandmodechanged(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__oncommandmodechanged__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ondoubleclick(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ondoubleclick__control__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * oneachframe(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__oneachframe__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ongroupiconclick(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ongroupiconclick__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ongroupiconoverenter(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverenter__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ongroupiconoverleave(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverleave__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onhcgroupselectionchanged(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onhcgroupselectionchanged__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onmapsingleclick(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__onmapsingleclick__any__code_string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onplayerconnected(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onplayerconnected__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onplayerdisconnected(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onplayerdisconnected__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onpreloadfinished(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onpreloadfinished__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onpreloadstarted(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onpreloadstarted__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onshownewobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__onshownewobject__control__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * onteamswitch(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__onteamswitch__code_string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * opencuratorinterface()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__opencuratorinterface__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * opendlcpage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__opendlcpage__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * opengps(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__opengps__bool__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * openmap(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__openmap__bool__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * opensteamapp(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__opensteamapp__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * openyoutubevideo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__openyoutubevideo__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * opfor()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__opfor__ret__side));
}

extern "C" __declspec(dllexport) game_value * or (game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__or__bool__code__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ordergetin(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ordergetin__array__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * overcast()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__overcast__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * overcastforecast()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__overcastforecast__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * owner(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__owner__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * param(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__param__any__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * params(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__params__any__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * parsenumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__parsenumber__bool__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * parsesimplearray(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__parsesimplearray__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * parsetext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__parsetext__string__ret__text, *right_arg));
}

extern "C" __declspec(dllexport) game_value * parsingnamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__parsingnamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * particlesquality()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__particlesquality__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * periscopeelevation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__periscopeelevation__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * pi()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__pi__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * pickweaponpool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__pickweaponpool__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * pitch(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__pitch__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * pixelgrid()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__pixelgrid__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * pixelgridbase()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__pixelgridbase__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * pixelgridnouiscale()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__pixelgridnouiscale__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * pixelh()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__pixelh__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * pixelw()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__pixelw__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * playableslotsnumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playableslotsnumber__side__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playableunits()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__playableunits__ret__array));
}

extern "C" __declspec(dllexport) game_value * playaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__playaction__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playactionnow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__playactionnow__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * player()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__player__ret__object));
}

extern "C" __declspec(dllexport) game_value * playerrespawntime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__playerrespawntime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * playerside()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__playerside__ret__side));
}

extern "C" __declspec(dllexport) game_value * playersnumber(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playersnumber__side__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playgesture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__playgesture__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playmission(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playmission__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playmove(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__playmove__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playmovenow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__playmovenow__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playmusic(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playmusic__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playscriptedmission(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playscriptedmission__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playsound(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playsound__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playsound3d(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playsound3d__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * playsoundui(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__playsoundui__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * pose(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__pose__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * position(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__position__location__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * positioncameratoworld(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__positioncameratoworld__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * posscreentoworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__posscreentoworld__control__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * posworldtoscreen(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__posworldtoscreen__control__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectadjust(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ppeffectadjust__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectcommit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ppeffectcommit__array__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectcommitted(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ppeffectcommitted__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectcreate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ppeffectcreate__array__ret__scalar_array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectdestroy(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ppeffectdestroy__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectenable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ppeffectenable__scalar__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ppeffectenabled__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ppeffectforceinnvg(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ppeffectforceinnvg__scalar__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * precision(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__precision__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preloadcamera(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__preloadcamera__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preloadobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__preloadobject__scalar__object_string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preloadsound(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__preloadsound__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preloadtitleobj(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__preloadtitleobj__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preloadtitlersc(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__preloadtitlersc__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preprocessfile(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__preprocessfile__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * preprocessfilelinenumbers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__preprocessfilelinenumbers__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * primaryweapon(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__primaryweapon__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * primaryweaponitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__primaryweaponitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * primaryweaponmagazine(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__primaryweaponmagazine__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * priority(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__priority__task__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * processdiarylink(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__processdiarylink__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * productversion()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__productversion__ret__array));
}

extern "C" __declspec(dllexport) game_value * profilename()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__profilename__ret__string));
}

extern "C" __declspec(dllexport) game_value * profilenamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__profilenamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * profilenamesteam()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__profilenamesteam__ret__string));
}

extern "C" __declspec(dllexport) game_value * progressloadingscreen(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__progressloadingscreen__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * progressposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__progressposition__control__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * progresssetposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__progresssetposition__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * publicvariable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__publicvariable__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * publicvariableclient(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__publicvariableclient__scalar__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * publicvariableserver(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__publicvariableserver__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * pushback(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__pushback__array__any__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * pushbackunique(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__pushbackunique__array__any__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * putweaponpool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__putweaponpool__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * queryitemspool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__queryitemspool__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * querymagazinepool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__querymagazinepool__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * queryweaponpool(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__queryweaponpool__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rad(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rad__scalar_nan__ret__scalar_nan, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radiochanneladd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__radiochanneladd__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radiochannelcreate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__radiochannelcreate__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radiochannelinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__radiochannelinfo__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radiochannelremove(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__radiochannelremove__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radiochannelsetcallsign(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetcallsign__scalar__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radiochannelsetlabel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetlabel__scalar__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * radioenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__radioenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * radiovolume()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__radiovolume__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * rain()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__rain__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * rainbow()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__rainbow__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * rainparams()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__rainparams__ret__array));
}

extern "C" __declspec(dllexport) game_value * random(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__random__scalar__scalar_array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rank(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rank__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rankid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rankid__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rating(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rating__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rectangular(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rectangular__location__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * regexfind(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__regexfind__string__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * regexmatch(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__regexmatch__string__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * regexreplace(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__regexreplace__string__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * registeredtasks(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__registeredtasks__team_member__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * registertask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__registertask__team_member__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * reload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__reload__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * reloadenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__reloadenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * remotecontrol(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__remotecontrol__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * remoteexec(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__remoteexec__any__array__ret__string_nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * remoteexeccall(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__remoteexeccall__any__array__ret__string_nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * remoteexecutedowner()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__remoteexecutedowner__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * remove3denconnection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__remove3denconnection__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * remove3deneventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__remove3deneventhandler__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * remove3denlayer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__remove3denlayer__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeaction__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeall3deneventhandlers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeall3deneventhandlers__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallactions(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallactions__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallassigneditems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallassigneditems__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallbinocularitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallbinocularitems__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallcontainers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallcontainers__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallcuratoraddons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoraddons__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallcuratorcameraareas(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallcuratorcameraareas__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallcuratoreditingareas(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoreditingareas__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removealleventhandlers(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removealleventhandlers__group__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallhandgunitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallhandgunitems__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallitems__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallitemswithmagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallitemswithmagazines__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallmissioneventhandlers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallmissioneventhandlers__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallmpeventhandlers(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeallmpeventhandlers__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallmusiceventhandlers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallmusiceventhandlers__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallownedmines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallownedmines__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallprimaryweaponitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallprimaryweaponitems__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallsecondaryweaponitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallsecondaryweaponitems__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removealluseractioneventhandlers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removealluseractioneventhandlers__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeallweapons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeallweapons__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removebackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removebackpack__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removebackpackglobal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removebackpackglobal__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removebinocularitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removebinocularitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removecuratoraddons(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removecuratoraddons__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removecuratorcameraarea(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removecuratorcameraarea__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removecuratoreditableobjects(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditableobjects__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removecuratoreditingarea(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditingarea__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removediaryrecord(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removediaryrecord__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removediarysubject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removediarysubject__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removedrawicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removedrawicon__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removedrawlinks(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removedrawlinks__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeeventhandler__group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removefromremainscollector(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removefromremainscollector__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removegoggles(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removegoggles__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removegroupicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removegroupicon__group__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removehandgunitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removehandgunitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeheadgear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeheadgear__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeitemfrombackpack(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeitemfrombackpack__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeitemfromuniform(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeitemfromuniform__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeitemfromvest(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeitemfromvest__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeitems(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeitems__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemagazine(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removemagazine__object__string_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemagazineglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removemagazineglobal__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemagazines(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removemagazines__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemagazinesturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removemagazinesturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemagazineturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removemagazineturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemenuitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removemenuitem__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemissioneventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removemissioneventhandler__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removempeventhandler(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removempeventhandler__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removemusiceventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removemusiceventhandler__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeownedmine(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeownedmine__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeprimaryweaponitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeprimaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removesecondaryweaponitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removesecondaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removesimpletask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removesimpletask__object__task__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeswitchableunit(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeswitchableunit__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeteammember(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeteammember__team_member__team_member__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeuniform(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeuniform__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeuseractioneventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removeuseractioneventhandler__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removevest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__removevest__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeweapon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeweapon__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeweaponattachmentcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeweaponattachmentcargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeweaponcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeweaponcargo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeweaponglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeweaponglobal__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * removeweaponturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__removeweaponturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * reportremotetarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__reportremotetarget__side__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * requiredversion(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__requiredversion__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * resetcamshake()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__resetcamshake__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * resetsubgroupdirection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__resetsubgroupdirection__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * resistance()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__resistance__ret__side));
}

extern "C" __declspec(dllexport) game_value * resize(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__resize__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * resources(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__resources__team_member__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * respawnvehicle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__respawnvehicle__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * restarteditorcamera(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__restarteditorcamera__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * reveal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__reveal__object_group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * revealmine(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__revealmine__side__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * reverse(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__reverse__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * reversedmousey()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__reversedmousey__ret__bool));
}

extern "C" __declspec(dllexport) game_value * roadat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__roadat__object_array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * roadsconnectedto(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__roadsconnectedto__object_array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * roledescription(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__roledescription__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeattachedobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropeattachedobjects__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeattachedto(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropeattachedto__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeattachenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropeattachenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeattachto(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ropeattachto__object_array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropecreate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropecreate__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropecut(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropecut__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropedestroy(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropedestroy__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropedetach(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__ropedetach__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeendposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropeendposition__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropelength(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropelength__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropes(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropes__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropesattachedto(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropesattachedto__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropesegments(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropesegments__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeunwind(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropeunwind__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * ropeunwound(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__ropeunwound__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rotorsforcesrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rotorsforcesrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * rotorsrpmrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__rotorsrpmrtd__object__ret__array, *right_arg));
}


extern "C" __declspec(dllexport) game_value * runinitscript()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__runinitscript__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * safezoneh()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__safezoneh__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * safezonew()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__safezonew__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * safezonewabs()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__safezonewabs__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * safezonex()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__safezonex__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * safezonexabs()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__safezonexabs__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * safezoney()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__safezoney__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * save3deninventory(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__save3deninventory__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * savegame()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__savegame__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * saveidentity(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__saveidentity__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * savejoysticks()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__savejoysticks__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * savemissionprofilenamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__savemissionprofilenamespace__ret__bool));
}

extern "C" __declspec(dllexport) game_value * saveoverlay(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__saveoverlay__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * saveprofilenamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__saveprofilenamespace__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * savestatus(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__savestatus__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * savevar(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__savevar__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * savingenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__savingenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * say(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__say__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * say2d(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__say2d__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * say3d(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__say3d__object_array__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * scopename(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__scopename__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * score(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__score__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * scoreside(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__scoreside__side__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * screenshot(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__screenshot__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * screentoworld(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__screentoworld__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * scriptdone(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__scriptdone__script__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * scriptname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__scriptname__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * scriptnull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__scriptnull__ret__script));
}

extern "C" __declspec(dllexport) game_value * scudstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__scudstate__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * secondaryweapon(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__secondaryweapon__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * secondaryweaponitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * secondaryweaponmagazine(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponmagazine__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * Select(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__select__string__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectbestplaces(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__selectbestplaces__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectdiarysubject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectdiarysubject__object__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectededitorobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__selectededitorobjects__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selecteditorobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selecteditorobject__control__string__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectionnames(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectionnames__object__string_scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectionposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectionposition__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectionvectordirandup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectionvectordirandup__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectleader(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectleader__group__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectmax(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__selectmax__array__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectmin(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__selectmin__array__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectnoplayer()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__selectnoplayer__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * selectplayer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__selectplayer__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectrandom(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__selectrandom__array__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectrandomweighted(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectrandomweighted__array__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectweapon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectweapon__object__array__ret__bool_nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * selectweaponturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__selectweaponturret__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sendaumessage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sendaumessage__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sendsimplecommand(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sendsimplecommand__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sendtask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sendtask__team_member__array__ret__task, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sendtaskresult(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sendtaskresult__task__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sendudpmessage(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sendudpmessage__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sentencesenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sentencesenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * servercommand(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__servercommand__string__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * servercommandavailable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__servercommandavailable__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * servercommandexecutable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__servercommandexecutable__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * servername()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__servername__ret__string));
}

extern "C" __declspec(dllexport) game_value * servernamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__servernamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * servertime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__servertime__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * set(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__set__hashmap__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denattribute(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__set3denattribute__any__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denattributes(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3denattributes__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3dengrid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3dengrid__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3deniconsvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3deniconsvisible__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denlayer(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__set3denlayer__any__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denlinesvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3denlinesvisible__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denlogictype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__set3denlogictype__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denmissionattribute(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__set3denmissionattribute__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denmissionattributes(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3denmissionattributes__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denmodelsvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3denmodelsvisible__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denobjecttype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__set3denobjecttype__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * set3denselected(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__set3denselected__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setacctime(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setacctime__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setactualcollectivertd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setactualcollectivertd__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setairplanethrottle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setairplanethrottle__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setairportside(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setairportside__object_scalar__side__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setammo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setammo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setammocargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setammocargo__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setammoonpylon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setammoonpylon__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setanimspeedcoef(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setanimspeedcoef__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setaperture(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setaperture__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setaperturenew(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setaperturenew__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setarmorypoints(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setarmorypoints__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setattributes(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setattributes__text_string__array__ret__text, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setautonomous(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setautonomous__object__bool__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setbehaviour(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setbehaviour__object_group__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setbehaviourstrong(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setbehaviourstrong__object_group__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setbleedingremaining(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setbleedingremaining__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setbrakesrtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setbrakesrtd__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcamerainterest(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcamerainterest__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcamshakedefparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setcamshakedefparams__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcamshakeparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setcamshakeparams__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcamuseti(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcamuseti__bool__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcaptive(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcaptive__object__bool_scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcenterofmass(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcenterofmass__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcollisionlight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcollisionlight__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcombatbehaviour(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcombatbehaviour__group__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcombatmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcombatmode__team_member__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcompassoscillation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setcompassoscillation__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setconvoyseparation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setconvoyseparation__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcruisecontrol(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcruisecontrol__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcuratorcameraareaceiling(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcuratorcameraareaceiling__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcuratorcoef(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcuratorcoef__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcuratoreditingareatype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcuratoreditingareatype__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcuratorwaypointcost(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcuratorwaypointcost__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcurrentchannel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setcurrentchannel__scalar__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcurrenttask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcurrenttask__object__task__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcurrentwaypoint(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcurrentwaypoint__group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcustomaimcoef(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcustomaimcoef__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcustommissiondata(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setcustommissiondata__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcustomsoundcontroller(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setcustomsoundcontroller__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setcustomweightrtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setcustomweightrtd__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdamage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdamage__object__scalar_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdammage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdammage__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setdate__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdebriefingtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdebriefingtext__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdefaultcamera(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setdefaultcamera__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdestination(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdestination__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdetailmapblendpars(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setdetailmapblendpars__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdiaryrecordtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdiaryrecordtext__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdiarysubjectpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdiarysubjectpicture__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdir__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdirection(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdirection__location__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdrawicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdrawicon__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdriveonpath(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdriveonpath__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdropinterval(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdropinterval__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdynamicsimulationdistance(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistance__string__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setdynamicsimulationdistancecoef(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistancecoef__string__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * seteditormode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__seteditormode__control__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * seteditorobjectscope(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__seteditorobjectscope__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * seteffectcondition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__seteffectcondition__object_array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * seteffectivecommander(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__seteffectivecommander__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setenginerpmrtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setenginerpmrtd__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setface(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setface__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfaceanimation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfaceanimation__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfatigue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfatigue__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfeaturetype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfeaturetype__object__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setflaganimationphase(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setflaganimationphase__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setflagowner(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setflagowner__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setflagside(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setflagside__object__side__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setflagtexture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setflagtexture__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfog(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfog__scalar__scalar_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setforcegeneratorrtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setforcegeneratorrtd__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setformation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setformation__team_member__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setformationtask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setformationtask__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setformdir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setformdir__object_group__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfriend(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfriend__side__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfromeditor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfromeditor__team_member__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfsmvariable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfsmvariable__scalar__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfuel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfuel__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setfuelcargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setfuelcargo__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setgroupicon__group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupiconparams(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setgroupiconparams__group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupiconsselectable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsselectable__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupiconsvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsvisible__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupid(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setgroupid__object_group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupidglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setgroupidglobal__object_group__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgroupowner(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setgroupowner__group__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setgusts(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setgusts__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethidebehind(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sethidebehind__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sethit__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethitindex(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sethitindex__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethitpointdamage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sethitpointdamage__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethorizonparallaxcoef(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sethorizonparallaxcoef__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethudmovementlevels(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sethudmovementlevels__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sethumidity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sethumidity__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setidentity(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setidentity__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setimportance(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setimportance__location__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setinfopanel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setinfopanel__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setleader(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setleader__team_member__team_member__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightambient(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightambient__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightattenuation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightattenuation__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightbrightness(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightbrightness__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightcolor__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightconepars(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightconepars__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightdaylight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightdaylight__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightflaremaxdistance(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightflaremaxdistance__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightflaresize(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightflaresize__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightintensity(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightintensity__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightir__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightnings(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightnings__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightuseflare(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightuseflare__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlightvolumeshape(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setlightvolumeshape__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setlocalwindparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setlocalwindparams__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmagazineturretammo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmagazineturretammo__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkeralpha(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkeralpha__string__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkeralphalocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkeralphalocal__string__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerbrush(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrush__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerbrushlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrushlocal__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkercolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkercolor__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkercolorlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkercolorlocal__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerdir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerdir__string__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerdirlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerdirlocal__string__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerpolyline(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolyline__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerpolylinelocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolylinelocal__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerpos__string__object_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkerposlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkerposlocal__string__object_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkershadow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkershadow__string__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkershadowlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkershadowlocal__string__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkershape(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkershape__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkershapelocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkershapelocal__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkersize(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkersize__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkersizelocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkersizelocal__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkertext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkertext__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkertextlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkertextlocal__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkertype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkertype__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmarkertypelocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmarkertypelocal__string__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmass(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmass__object__scalar_array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmaxload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmaxload__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmimic(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmimic__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmissiletarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmissiletarget__object__object__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmissiletargetpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmissiletargetpos__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmouseposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setmouseposition__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmusiceffect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setmusiceffect__object_array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setmusiceventhandler(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setmusiceventhandler__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setname(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setname__location__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setnamesound(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setnamesound__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjectarguments(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjectarguments__control__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjectmaterial(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterial__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjectmaterialglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterialglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjectproxy(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjectproxy__control__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjectscale(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjectscale__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjecttexture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjecttexture__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjecttextureglobal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setobjecttextureglobal__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setobjectviewdistance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setobjectviewdistance__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setopticsmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setopticsmode__object__array_string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setovercast(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setovercast__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setowner(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setowner__object__scalar__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setoxygenremaining(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setoxygenremaining__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setparticlecircle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setparticlecircle__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setparticleclass(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setparticleclass__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setparticlefire(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setparticlefire__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setparticleparams(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setparticleparams__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setparticlerandom(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setparticlerandom__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpilotcameradirection(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpilotcameradirection__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpilotcamerarotation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpilotcamerarotation__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpilotcameratarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpilotcameratarget__object__object_array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpilotlight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpilotlight__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpipeffect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpipeffect__string__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpipviewdistance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setpipviewdistance__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpitch(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpitch__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setplatenumber(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setplatenumber__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setplayable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setplayable__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setplayerrespawntime(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setplayerrespawntime__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setplayervonvolume(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setplayervonvolume__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpos__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setposasl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setposasl__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setposasl2(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setposasl2__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setposaslw(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setposaslw__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setposatl(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setposatl__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setposition__location__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setposworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setposworld__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpylonloadout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpylonloadout__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setpylonspriority(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setpylonspriority__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setradiomsg(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setradiomsg__scalar__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrain(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrain__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrainbow(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrainbow__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrandomlip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrandomlip__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrank(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrank__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrectangular(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrectangular__location__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrepaircargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrepaircargo__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setrotorbrakertd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setrotorbrakertd__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setshadowdistance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setshadowdistance__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setshotparents(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setshotparents__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setside(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setside__location__side__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimpletaskalwaysvisible(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskalwaysvisible__task__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimpletaskcustomdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskcustomdata__task__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimpletaskdescription(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdescription__task__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimpletaskdestination(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdestination__task__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimpletasktarget(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktarget__task__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimpletasktype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktype__task__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsimulweatherlayers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setsimulweatherlayers__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsize(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsize__location__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setskill(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setskill__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setslingload(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setslingload__object__object__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsoundeffect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsoundeffect__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setspeaker(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setspeaker__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setspeech(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setspeech__location__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setspeedmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setspeedmode__object_group__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setstamina(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setstamina__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setstaminascheme(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setstaminascheme__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setstatvalue(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setstatvalue__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsuppression(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setsuppression__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setsystemofunits(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setsystemofunits__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settargetage(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settargetage__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settaskmarkeroffset(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settaskmarkeroffset__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settaskresult(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settaskresult__task__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settaskstate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settaskstate__task__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setterraingrid(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setterraingrid__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setterrainheight(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setterrainheight__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settext__location__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settimemultiplier(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__settimemultiplier__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settiparameter(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__settiparameter__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settitleeffect(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settitleeffect__object_array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settowparent(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settowparent__object__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settrafficdensity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__settrafficdensity__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settrafficdistance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__settrafficdistance__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settrafficgap(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__settrafficgap__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settrafficspeed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__settrafficspeed__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggeractivation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggeractivation__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggerarea(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggerarea__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggerinterval(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggerinterval__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggerstatements(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggerstatements__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggertext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggertext__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggertimeout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggertimeout__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settriggertype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settriggertype__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setturretlimits(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setturretlimits__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setturretopticsmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setturretopticsmode__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * settype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__settype__location__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunconscious(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunconscious__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitability(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitability__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitcombatmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitcombatmode__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitfreefallheight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitfreefallheight__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitloadout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitloadout__object__config__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitpos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitpos__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitposweak(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitposweak__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitrank(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitrank__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunitrecoilcoefficient(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunitrecoilcoefficient__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunittrait(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunittrait__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setunloadincombat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setunloadincombat__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setuseractiontext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setuseractiontext__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setusermfdtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setusermfdtext__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setusermfdvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setusermfdvalue__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvariable(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvariable__location__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvectordir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvectordir__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvectordirandup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvectordirandup__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvectorup(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvectorup__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehicleammo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehicleammo__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehicleammodef(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehicleammodef__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclearmor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclearmor__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclecargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclecargo__object__object__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehicleid(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehicleid__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclelock(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclelock__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehicleposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehicleposition__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehicleradar(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehicleradar__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclereceiveremotetargets(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclereceiveremotetargets__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclereportownposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportownposition__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclereportremotetargets(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportremotetargets__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehicletipars(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehicletipars__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvehiclevarname(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvehiclevarname__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvelocity(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvelocity__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvelocitymodelspace(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvelocitymodelspace__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvelocitytransformation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvelocitytransformation__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setviewdistance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setviewdistance__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setvisibleiftreecollapsed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setvisibleiftreecollapsed__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwantedrpmrtd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwantedrpmrtd__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaves(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaves__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointbehaviour(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointbehaviour__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointcombatmode(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointcombatmode__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointcompletionradius(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointcompletionradius__array__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointdescription(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointdescription__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointforcebehaviour(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointforcebehaviour__array__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointformation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointformation__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointhouseposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointhouseposition__array__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointloiteraltitude(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiteraltitude__array__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointloiterradius(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiterradius__array__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointloitertype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointloitertype__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointname(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointname__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointposition__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointscript(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointscript__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointspeed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointspeed__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointstatements(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointstatements__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointtimeout(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointtimeout__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointtype(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointtype__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwaypointvisible(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwaypointvisible__array__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setweaponreloadingtime(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setweaponreloadingtime__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setweaponzeroing(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setweaponzeroing__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwind(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__setwind__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwinddir(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwinddir__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwindforce(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwindforce__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwindstr(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwindstr__scalar__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwingforcescalertd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwingforcescalertd__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * setwppos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__setwppos__array__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * show3dicons(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__show3dicons__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showchat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showchat__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showcinemaborder(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showcinemaborder__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showcommandingmenu(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showcommandingmenu__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showcompass(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showcompass__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showcuratorcompass(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showcuratorcompass__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showgps(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showgps__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showhud(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showhud__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showlegend(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__showlegend__control__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showmap(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showmap__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * shownartillerycomputer()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownartillerycomputer__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownchat()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownchat__ret__bool));
}

extern "C" __declspec(dllexport) game_value * showncompass()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__showncompass__ret__bool));
}

extern "C" __declspec(dllexport) game_value * showncuratorcompass()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__showncuratorcompass__ret__bool));
}

extern "C" __declspec(dllexport) game_value * showneweditorobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__showneweditorobject__control__array__ret__any, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showngps()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__showngps__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownhud()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownhud__ret__array));
}

extern "C" __declspec(dllexport) game_value * shownmap()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownmap__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownpad()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownpad__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownradio()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownradio__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownscoretable()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownscoretable__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * shownsubtitles()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownsubtitles__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownuavfeed()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownuavfeed__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownwarrant()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownwarrant__ret__bool));
}

extern "C" __declspec(dllexport) game_value * shownwatch()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__shownwatch__ret__bool));
}

extern "C" __declspec(dllexport) game_value * showpad(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showpad__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showradio(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showradio__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showscoretable(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showscoretable__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showsubtitles(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showsubtitles__bool__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showuavfeed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showuavfeed__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showwarrant(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showwarrant__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showwatch(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showwatch__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showwaypoint(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__showwaypoint__array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * showwaypoints(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__showwaypoints__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * side(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__side__location__ret__side, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sideambientlife()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sideambientlife__ret__side));
}

extern "C" __declspec(dllexport) game_value * sidechat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sidechat__object_array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sideempty()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sideempty__ret__side));
}

extern "C" __declspec(dllexport) game_value * sideenemy()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sideenemy__ret__side));
}

extern "C" __declspec(dllexport) game_value * sidefriendly()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sidefriendly__ret__side));
}

extern "C" __declspec(dllexport) game_value * sidelogic()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sidelogic__ret__side));
}

extern "C" __declspec(dllexport) game_value * sideradio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sideradio__object_array__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sideunknown()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sideunknown__ret__side));
}

extern "C" __declspec(dllexport) game_value * simpletasks(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__simpletasks__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * simulationenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__simulationenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * simulclouddensity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__simulclouddensity__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * simulcloudocclusion(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__simulcloudocclusion__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * simulinclouds(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__simulinclouds__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * simulweathersync()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__simulweathersync__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * size(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__size__location__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sizeOf(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sizeof__string__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * skill(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__skill__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * skillfinal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__skillfinal__object__string__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * skiptime(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__skiptime__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sleep(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sleep__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sliderposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sliderposition__scalar__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sliderrange(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sliderrange__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * slidersetposition(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__slidersetposition__control__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * slidersetrange(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__slidersetrange__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * slidersetspeed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__slidersetspeed__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sliderspeed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__sliderspeed__scalar__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * slingloadassistantshown()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__slingloadassistantshown__ret__bool));
}

extern "C" __declspec(dllexport) game_value * soldiermagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__soldiermagazines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * someammo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__someammo__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sort(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__sort__array__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * soundvolume()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__soundvolume__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * spawn(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__spawn__any__code__ret__script, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * speaker(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__speaker__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * speechvolume()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__speechvolume__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * speed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__speed__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * speedmode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__speedmode__object_group__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * splitstring(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__splitstring__string__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * squadparams(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__squadparams__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * stance(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__stance__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * startloadingscreen(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__startloadingscreen__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * step(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__step__for__scalar__ret__for, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * stop(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__stop__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * stopenginertd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__stopenginertd__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * stopped(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__stopped__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * str(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__str__any__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * sunormoon()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__sunormoon__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * supportinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__supportinfo__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * suppressfor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__suppressfor__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * surfaceiswater(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__surfaceiswater__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * surfacenormal(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__surfacenormal__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * surfacetexture(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__surfacetexture__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * surfacetype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__surfacetype__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * swimindepth(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__swimindepth__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * switchableunits()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__switchableunits__ret__array));
}

extern "C" __declspec(dllexport) game_value * switchaction(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__switchaction__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * switchcamera(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__switchcamera__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * switchgesture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__switchgesture__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * switchlight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__switchlight__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * switchmove(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__switchmove__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizedobjects(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__synchronizedobjects__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizedtriggers(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__synchronizedtriggers__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizedwaypoints(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__synchronizedwaypoints__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizeobjectsadd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsadd__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizeobjectsremove(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsremove__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizetrigger(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__synchronizetrigger__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * synchronizewaypoint(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__synchronizewaypoint__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * systemchat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__systemchat__string__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * systemofunits()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__systemofunits__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * systemtime()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__systemtime__ret__array));
}

extern "C" __declspec(dllexport) game_value * systemtimeutc()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__systemtimeutc__ret__array));
}

extern "C" __declspec(dllexport) game_value * targetknowledge(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__targetknowledge__object__object__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * targets(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__targets__group__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * targetsaggregate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__targetsaggregate__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * targetsquery(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__targetsquery__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskalwaysvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskalwaysvisible__task__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskchildren(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskchildren__task__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskcompleted(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskcompleted__task__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskcustomdata(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskcustomdata__task__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskdescription(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskdescription__task__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskdestination(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskdestination__task__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskhint(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskhint__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskmarkeroffset(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskmarkeroffset__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskname__task__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tasknull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__tasknull__ret__task));
}

extern "C" __declspec(dllexport) game_value * taskparent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskparent__task__ret__task, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskresult(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskresult__task__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * taskstate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__taskstate__task__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tasktype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tasktype__task__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * teammember(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__teammember__object__ret__team_member, *right_arg));
}

extern "C" __declspec(dllexport) game_value * teammembernull()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__teammembernull__ret__team_member));
}

extern "C" __declspec(dllexport) game_value * teamname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__teamname__team_member__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * teams()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__teams__ret__array));
}

extern "C" __declspec(dllexport) game_value * teamswitch()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__teamswitch__ret__nothing));
}

extern "C" __declspec(dllexport) game_value * teamswitchenabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__teamswitchenabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * teamtype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__teamtype__team_member__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * Terminate(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__terminate__script__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * terrainintersect(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__terrainintersect__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * terrainintersectasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__terrainintersectasl__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * terrainintersectatasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__terrainintersectatasl__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * text(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__text__location__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * textlog(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__textlog__any__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * textlogformat(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__textlogformat__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tg(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tg__scalar_nan__ret__scalar_nan, *right_arg));
}

extern "C" __declspec(dllexport) game_value * Time()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__time__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * timemultiplier()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__timemultiplier__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * titlecut(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__titlecut__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * titlefadeout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__titlefadeout__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * titleobj(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__titleobj__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * titlersc(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__titlersc__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * titletext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__titletext__array__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * to(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__to__for__scalar__ret__for, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * toarray(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__toarray__hashmap__bool__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tofixed(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tofixed__scalar__scalar__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * toLower(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tolower__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * toloweransi(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__toloweransi__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tostring(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tostring__code__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * toUpper(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__toupper__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * toupperansi(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__toupperansi__string__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggeractivated(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggeractivated__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggeractivation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggeractivation__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerammo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggerammo__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerarea(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggerarea__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerattachedvehicle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggerattachedvehicle__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerattachobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__triggerattachobject__object__scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerattachvehicle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__triggerattachvehicle__object__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerdynamicsimulation(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__triggerdynamicsimulation__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerinterval(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggerinterval__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggerstatements(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggerstatements__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggertext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggertext__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggertimeout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggertimeout__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggertimeoutcurrent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggertimeoutcurrent__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * triggertype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__triggertype__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * trim(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__trim__string__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * turretlocal(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__turretlocal__object__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * turretowner(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__turretowner__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * turretunit(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__turretunit__object__array__ret__object, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvadd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvadd__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvclear(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tvclear__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvcollapse(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvcollapse__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvcollapseall(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tvcollapseall__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvcount(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvcount__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvcursel(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tvcursel__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvdata__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvdelete(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvdelete__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvexpand(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvexpand__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvexpandall(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tvexpandall__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvisselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvisselected__control__array__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvpicture__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvpictureright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvpictureright__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvselection(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__tvselection__control__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetcursel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetcursel__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetdata(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetdata__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicture(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicture__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicturecolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicturecolordisabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolordisabled__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicturecolorselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolorselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpictureright(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpictureright__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicturerightcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicturerightcolordisabled(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolordisabled__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetpicturerightcolorselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolorselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetselectcolor(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetselectcolor__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetselected(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetselected__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsettext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsettext__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsettooltip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsettooltip__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsetvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsetvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsort(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsort__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsortall(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsortall__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsortbyvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalue__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvsortbyvalueall(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalueall__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvtext(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvtext__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvtooltip(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvtooltip__control__array__ret__string, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * tvvalue(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__tvvalue__control__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * type(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__type__location__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * typeName(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__typename__any__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * typeof(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__typeof__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uavcontrol(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uavcontrol__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uinamespace()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__uinamespace__ret__namespace));
}

extern "C" __declspec(dllexport) game_value * uisleep(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uisleep__scalar__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unassigncurator(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unassigncurator__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unassignitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__unassignitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unassignteam(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unassignteam__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unassignvehicle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unassignvehicle__object__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * underwater(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__underwater__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uniform(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uniform__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uniformcontainer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uniformcontainer__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uniformitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uniformitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uniformmagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uniformmagazines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * uniqueunititems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__uniqueunititems__object_array__ret__hashmap, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitaddons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitaddons__string__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitaimposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitaimposition__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitaimpositionvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitaimpositionvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitbackpack(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitbackpack__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitcombatmode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitcombatmode__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitisuav(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitisuav__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitpos(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitpos__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitready(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitready__object_array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitrecoilcoefficient(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unitrecoilcoefficient__object__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * units(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__units__side__ret__any, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitsbelowheight(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__unitsbelowheight__array__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unitturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__unitturret__object__object__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unlinkitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__unlinkitem__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unlockachievement(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__unlockachievement__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * unregistertask(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__unregistertask__team_member__string__ret__bool, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * updatedrawicon(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__updatedrawicon__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * updatemenuitem(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__updatemenuitem__control__array__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * updateobjecttree(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__updateobjecttree__control__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * useaiopermapobstructiontest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__useaiopermapobstructiontest__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * useaisteeringcomponent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__useaisteeringcomponent__bool__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * useaudiotimeformoves(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__useaudiotimeformoves__object__bool__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * userinputdisabled()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__userinputdisabled__ret__bool));
}

extern "C" __declspec(dllexport) game_value * values(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__values__hashmap__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectoradd(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectoradd__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorcos(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectorcos__array__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorcrossproduct(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectorcrossproduct__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectordiff(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectordiff__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectordir(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectordir__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectordirvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectordirvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectordistance(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectordistance__array__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectordistancesqr(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectordistancesqr__array__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectordotproduct(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectordotproduct__array__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorfromto(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectorfromto__array__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorlinearconversion(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectorlinearconversion__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectormagnitude(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectormagnitude__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectormagnitudesqr(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectormagnitudesqr__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectormodeltoworld(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworld__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectormodeltoworldvisual(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworldvisual__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectormultiply(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectormultiply__array__scalar__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectornormalized(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectornormalized__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorup(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectorup__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorupvisual(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vectorupvisual__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorworldtomodel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodel__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vectorworldtomodelvisual(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodelvisual__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehicle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehicle__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehiclecargoenabled(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehiclecargoenabled__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehiclechat(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vehiclechat__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehiclemoveinfo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehiclemoveinfo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehicleradio(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__vehicleradio__object__string__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehiclereceiveremotetargets(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehiclereceiveremotetargets__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehiclereportownposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehiclereportownposition__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehiclereportremotetargets(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehiclereportremotetargets__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vehicles()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__vehicles__ret__array));
}

extern "C" __declspec(dllexport) game_value * vehiclevarname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vehiclevarname__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * velocity(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__velocity__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * velocitymodelspace(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__velocitymodelspace__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * verifysignature(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__verifysignature__string__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vest(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vest__object__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vestcontainer(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vestcontainer__object__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vestitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vestitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * vestmagazines(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__vestmagazines__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * viewdistance()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__viewdistance__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * visiblecompass()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__visiblecompass__ret__bool));
}

extern "C" __declspec(dllexport) game_value * visiblegps()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__visiblegps__ret__bool));
}

extern "C" __declspec(dllexport) game_value * visiblemap()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__visiblemap__ret__bool));
}

extern "C" __declspec(dllexport) game_value * visibleposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__visibleposition__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * visiblepositionasl(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__visiblepositionasl__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * visiblescoretable()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__visiblescoretable__ret__bool));
}

extern "C" __declspec(dllexport) game_value * visiblewatch()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__visiblewatch__ret__bool));
}

extern "C" __declspec(dllexport) game_value * waituntil(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waituntil__code__ret__nothing, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waves()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__waves__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * waypointattachedobject(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointattachedobject__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointattachedvehicle(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointattachedvehicle__array__ret__object, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointattachobject(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__waypointattachobject__array__object_scalar__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointattachvehicle(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__waypointattachvehicle__array__object__ret__nothing, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointbehaviour(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointbehaviour__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointcombatmode(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointcombatmode__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointcompletionradius(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointcompletionradius__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointdescription(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointdescription__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointforcebehaviour(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointforcebehaviour__array__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointformation(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointformation__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointhouseposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointhouseposition__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointloiteraltitude(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointloiteraltitude__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointloiterradius(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointloiterradius__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointloitertype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointloitertype__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointname(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointname__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointposition(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointposition__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypoints(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypoints__object_group__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointscript(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointscript__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointsenableduav(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointsenableduav__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointshow(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointshow__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointspeed(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointspeed__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointstatements(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointstatements__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointtimeout(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointtimeout__array__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointtimeoutcurrent(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointtimeoutcurrent__group__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointtype(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointtype__array__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * waypointvisible(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__waypointvisible__array__ret__scalar, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponaccessories(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weaponaccessories__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponaccessoriescargo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weaponaccessoriescargo__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponcargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weaponcargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weapondirection(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weapondirection__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponinertia(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weaponinertia__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponlowered(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weaponlowered__object__ret__bool, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponreloadingtime(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weaponreloadingtime__object__array__ret__scalar, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weapons(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weapons__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponsinfo(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weaponsinfo__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponsitems(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weaponsitems__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponsitemscargo(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weaponsitemscargo__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponstate(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weaponstate__object__string__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weaponsturret(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__weaponsturret__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * weightrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__weightrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * west()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__west__ret__side));
}

extern "C" __declspec(dllexport) game_value * wfsidetext(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__wfsidetext__group__ret__string, *right_arg));
}

extern "C" __declspec(dllexport) game_value * wind()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__wind__ret__array));
}

extern "C" __declspec(dllexport) game_value * winddir()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__winddir__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * windrtd()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__windrtd__ret__array));
}

extern "C" __declspec(dllexport) game_value * windstr()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__windstr__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * wingsforcesrtd(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__wingsforcesrtd__object__ret__array, *right_arg));
}

extern "C" __declspec(dllexport) game_value * with(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__with__namespace__ret__with, *right_arg));
}

extern "C" __declspec(dllexport) game_value * worldname()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__worldname__ret__string));
}

extern "C" __declspec(dllexport) game_value * worldsize()
{
	return new game_value(host::functions.invoke_raw_nular(__sqf::nular__worldsize__ret__scalar));
}

extern "C" __declspec(dllexport) game_value * worldtomodel(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__worldtomodel__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * worldtomodelvisual(game_value * left_arg, game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_binary(__sqf::binary__worldtomodelvisual__object__array__ret__array, *left_arg, *right_arg));
}

extern "C" __declspec(dllexport) game_value * worldtoscreen(game_value * right_arg)
{
	return new game_value(host::functions.invoke_raw_unary(__sqf::unary__worldtoscreen__array__ret__array, *right_arg));
}

