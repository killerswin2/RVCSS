#include <intercept.hpp>
#include "client/pointers.hpp"

using host = intercept::client::host;
using __sqf = intercept::client::__sqf;


extern "C" __declspec(dllexport) intercept::types::game_value* acctime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__acctime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* action(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__action__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionids(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionids__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionkeys(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionkeys__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionkeysex(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionkeysex__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionkeysimages(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionkeysimages__string_array__ret__text, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionkeysnames(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionkeysnames__string_array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionkeysnamesarray(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionkeysnamesarray__string_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__actionname__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* actionparams(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__actionparams__object__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* activateaddons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__activateaddons__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* activatedaddons()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__activatedaddons__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* activatekey(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__activatekey__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* activetitleeffectparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__activetitleeffectparams__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* add3denconnection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__add3denconnection__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* add3deneventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__add3deneventhandler__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* add3denlayer(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__add3denlayer__scalar__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addaction__object__array__ret__nothing_scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addbackpack(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addbackpack__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addbackpackcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addbackpackcargoglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addbackpackcargoglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addbackpackglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addbackpackglobal__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addbinocularitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addbinocularitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addcamshake(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addcamshake__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addcuratoraddons(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addcuratoraddons__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addcuratorcameraarea(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addcuratorcameraarea__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addcuratoreditableobjects(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditableobjects__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addcuratoreditingarea(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addcuratoreditingarea__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addcuratorpoints(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addcuratorpoints__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addeditorobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addeditorobject__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addeventhandler__group__array__ret__nothing_scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addforce(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addforce__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addforcegeneratorrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addforcegeneratorrtd__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addgoggles(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addgoggles__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addgroupicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addgroupicon__group__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addhandgunitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addhandgunitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addheadgear(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addheadgear__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__additem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additemcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__additemcargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additemcargoglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__additemcargoglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additempool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__additempool__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additemtobackpack(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__additemtobackpack__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additemtouniform(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__additemtouniform__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* additemtovest(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__additemtovest__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addlivestats(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addlivestats__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazine(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazine__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazineammocargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazineammocargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazinecargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazinecargoglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazinecargoglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazineglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazineglobal__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazinepool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addmagazinepool__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazines(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazines__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmagazineturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmagazineturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmenu(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmenu__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmenuitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmenuitem__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmissioneventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addmissioneventhandler__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmpeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addmpeventhandler__object__array__ret__nothing_scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addmusiceventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addmusiceventhandler__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addonfiles(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addonfiles__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addownedmine(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addownedmine__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addplayerscores(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addplayerscores__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addprimaryweaponitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addprimaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addpublicvariableeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addpublicvariableeventhandler__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addrating(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addrating__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addresources(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addresources__team_member__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addscore(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addscore__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addscoreside(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addscoreside__side__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addsecondaryweaponitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addsecondaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addswitchableunit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addswitchableunit__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addteammember(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addteammember__team_member__team_member__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addtoremainscollector(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addtoremainscollector__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addtorque(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addtorque__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* adduniform(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__adduniform__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* adduseractioneventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__adduseractioneventhandler__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addvehicle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addvehicle__group__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addvest(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addvest__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addwaypoint(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addwaypoint__group__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweapon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweapon__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponcargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponcargoglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponcargoglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponglobal__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponitem__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponpool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__addweaponpool__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponwithattachmentscargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* addweaponwithattachmentscargoglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__addweaponwithattachmentscargoglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* admin(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__admin__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* agent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__agent__team_member__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* agents()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__agents__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* agltoasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__agltoasl__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* aimedattarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__aimedattarget__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* aimpos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__aimpos__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* airdensitycurvertd()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__airdensitycurvertd__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* airdensityrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__airdensityrtd__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* airplanethrottle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__airplanethrottle__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* airportside(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__airportside__object_scalar__ret__side, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* aisfinishheal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__aisfinishheal__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alive(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__alive__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* all3denentities()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__all3denentities__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allactivetitleeffects()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allactivetitleeffects__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alladdonsinfo()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__alladdonsinfo__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allairports()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allairports__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allcontrols(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__allcontrols__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allcurators()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allcurators__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allcutlayers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allcutlayers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alldead()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__alldead__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alldeadmen()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__alldeadmen__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alldiaryrecords(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__alldiaryrecords__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alldiarysubjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__alldiarysubjects__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alldisplays()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__alldisplays__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allenv3dsoundsources()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allenv3dsoundsources__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allgroups()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allgroups__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* alllods(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__alllods__object_string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allmapmarkers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allmapmarkers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allmines()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allmines__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allmissionobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__allmissionobjects__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allobjects(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allobjects__string__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allow3dmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allow3dmode__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowcrewinimmobile(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowcrewinimmobile__object__bool_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowcuratorlogicignoreareas(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowcuratorlogicignoreareas__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowdamage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowdamage__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowdammage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowdammage__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowedservice(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__allowedservice__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowfileoperations(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowfileoperations__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowfleeing(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowfleeing__object_group__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowgetin(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowgetin__array__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowservice(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowservice__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allowsprint(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__allowsprint__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allplayers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allplayers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allsimpleobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__allsimpleobjects__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allsites()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allsites__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allturrets(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__allturrets__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allunits()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allunits__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allunitsuav()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allunitsuav__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allusers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__allusers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* allvariables(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__allvariables__location__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ambienttemperature()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__ambienttemperature__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ammo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ammo__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ammoonpylon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ammoonpylon__object__string_scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* and (intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__and__bool__code__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animate__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animatebay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animatebay__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animatedoor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animatedoor__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animatepylon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animatepylon__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animatesource(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animatesource__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animationnames(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__animationnames__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animationphase(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animationphase__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animationsourcephase(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__animationsourcephase__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* animationstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__animationstate__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* apertureparams()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__apertureparams__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* append(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__append__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* apply(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__apply__hashmap__code__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* armorypoints()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__armorypoints__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* arrayintersect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__arrayintersect__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* asltoagl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__asltoagl__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* asltoatl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__asltoatl__array__ret__array, *right_arg);
}

//extern "C" __declspec(dllexport) intercept::types::game_value* assert(intercept::types::game_value * right_arg)
//{
//	return &host::functions.invoke_raw_unary(__sqf::unary__assert__bool__ret__bool, *right_arg);
//}

extern "C" __declspec(dllexport) intercept::types::game_value* assignascargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignascargo__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignascargoindex(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignascargoindex__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignascommander(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignascommander__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignasdriver(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignasdriver__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignasgunner(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignasgunner__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignasturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignasturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assigncurator(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assigncurator__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedcommander(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedcommander__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assigneddriver(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assigneddriver__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedgroup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedgroup__object__ret__group, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedgunner(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedgunner__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assigneditems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assigneditems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedtarget(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedtarget__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedteam(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedteam__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedvehicle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedvehicle__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedvehiclerole(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedvehiclerole__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignedvehicles(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__assignedvehicles__group__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assignteam(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assignteam__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* assigntoairport(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__assigntoairport__object__object_scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* atg(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__atg__scalar_nan__ret__scalar_nan, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* atltoasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__atltoasl__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* attachedobject(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__attachedobject__location__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* attachedobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__attachedobjects__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* attachedto(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__attachedto__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* attachobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__attachobject__location__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* attachto(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__attachto__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* attackenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__attackenabled__object_group__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* awake(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__awake__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__backpack__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpackcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__backpackcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpackcontainer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__backpackcontainer__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpackitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__backpackitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpackmagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__backpackmagazines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpacks(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__backpacks__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* backpackspacefor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__backpackspacefor__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* behaviour(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__behaviour__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* benchmark()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__benchmark__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* bezierinterpolation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__bezierinterpolation__scalar__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* binocular(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__binocular__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* binocularitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__binocularitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* binocularmagazine(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__binocularmagazine__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* blufor()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__blufor__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* boundingbox(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__boundingbox__scalar__object__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* boundingboxreal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__boundingboxreal__scalar__object__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* boundingcenter(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__boundingcenter__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* brakesdisabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__brakesdisabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* breakout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__breakout__any__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* breakto(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__breakto__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* breakwith(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__breakwith__any__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* briefingname()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__briefingname__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buildingexit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__buildingexit__object__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buildingpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__buildingpos__object__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buldozer_enableroaddiag(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__buldozer_enableroaddiag__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buldozer_isenabledroaddiag()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__buldozer_isenabledroaddiag__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buldozer_loadnewroads(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__buldozer_loadnewroads__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buldozer_reloadopermap()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__buldozer_reloadopermap__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buttonaction(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__buttonaction__scalar__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* buttonsetaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__buttonsetaction__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cadetmode()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cadetmode__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* calculatepath(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__calculatepath__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* calculateplayervisibilitybyfriendly(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__calculateplayervisibilitybyfriendly__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* call(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__call__any__code__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* callextension(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__callextension__string__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camcommand(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camcommand__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camcommit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camcommit__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camcommitprepared(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camcommitprepared__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camcommitted(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__camcommitted__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camconstuctionsetparams(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camconstuctionsetparams__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camcreate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camcreate__string__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camdestroy(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__camdestroy__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cameraeffect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__cameraeffect__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cameraeffectenablehud(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__cameraeffectenablehud__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camerainterest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__camerainterest__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cameraon()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cameraon__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cameraview()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cameraview__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campaignconfigfile()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__campaignconfigfile__ret__config);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreload__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreloaded(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__campreloaded__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparebank(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparebank__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparedir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparedir__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparedive(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparedive__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparefocus(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparefocus__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparefov(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparefov__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparefovrange(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparefovrange__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparepos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparepos__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparerelpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparerelpos__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* campreparetarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__campreparetarget__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetbank(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetbank__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetdir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetdir__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetdive(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetdive__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetfocus(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetfocus__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetfov(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetfov__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetfovrange(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetfovrange__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetpos__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsetrelpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsetrelpos__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camsettarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__camsettarget__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camtarget(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__camtarget__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* camusenvg(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__camusenvg__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canadd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__canadd__string__string_array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canadditemtobackpack(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__canadditemtobackpack__object__string_array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canadditemtouniform(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__canadditemtouniform__object__string_array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canadditemtovest(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__canadditemtovest__object__string_array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cancelsimpletaskdestination(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__cancelsimpletaskdestination__task__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* candeployweapon(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__candeployweapon__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canfire(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__canfire__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canmove(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__canmove__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canslingload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__canslingload__string__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canstand(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__canstand__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cansuspend()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cansuspend__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cantriggerdynamicsimulation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__cantriggerdynamicsimulation__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canunloadincombat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__canunloadincombat__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* canvehiclecargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__canvehiclecargo__object__object__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* captive(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__captive__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* captivenum(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__captivenum__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cbchecked(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__cbchecked__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cbsetchecked(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__cbsetchecked__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* channelenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__channelenabled__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cheatsenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cheatsenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* checkaifeature(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__checkaifeature__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* checkvisibility(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__checkvisibility__array__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* civilian()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__civilian__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* classname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__classname__location__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clear3denattribute(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__clear3denattribute__any__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clear3deninventory(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clear3deninventory__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearallitemsfrombackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearallitemsfrombackpack__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearbackpackcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargo__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearbackpackcargoglobal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearbackpackcargoglobal__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearforcesrtd()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__clearforcesrtd__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cleargroupicons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__cleargroupicons__group__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearitemcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearitemcargo__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearitemcargoglobal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearitemcargoglobal__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearitempool()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__clearitempool__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearmagazinecargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargo__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearmagazinecargoglobal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearmagazinecargoglobal__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearmagazinepool()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__clearmagazinepool__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearoverlay(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearoverlay__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearradio()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__clearradio__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearweaponcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargo__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearweaponcargoglobal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__clearweaponcargoglobal__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clearweaponpool()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__clearweaponpool__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* clientowner()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__clientowner__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* closedialog(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__closedialog__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* closedisplay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__closedisplay__display__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* closeoverlay(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__closeoverlay__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* collapseobjecttree(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__collapseobjecttree__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* collect3denhistory(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__collect3denhistory__array__code__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* collectivertd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__collectivertd__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* collisiondisabledwith(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__collisiondisabledwith__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* combatbehaviour(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__combatbehaviour__group__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* combatmode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__combatmode__object_group__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandartilleryfire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandartilleryfire__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandchat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandchat__object_array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commander(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__commander__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandfire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandfire__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandfollow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandfollow__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandfsm(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandfsm__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandgetout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__commandgetout__object_array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandingmenu()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__commandingmenu__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandmove(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandmove__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandradio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandradio__object_array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandstop(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__commandstop__object_array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandsuppressivefire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandsuppressivefire__object_array__object_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandtarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandtarget__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commandwatch(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__commandwatch__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* comment(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__comment__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* commitoverlay(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__commitoverlay__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* compatibleitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__compatibleitems__string_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* compatiblemagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__compatiblemagazines__string_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* compile(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__compile__string__ret__code, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* compilefinal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__compilefinal__string__ret__code, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* compilescript(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__compilescript__array__ret__code, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* completedfsm(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__completedfsm__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* composetext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__composetext__array__ret__text, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configaccessor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__configaccessor__config__string__ret__config, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configclasses(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__configclasses__string__config__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configfile()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__configfile__ret__config);
}

extern "C" __declspec(dllexport) intercept::types::game_value* confighierarchy(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__confighierarchy__config__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__configname__config__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* confignull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__confignull__ret__config);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configof(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__configof__object__ret__config, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configproperties(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__configproperties__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configsourceaddonlist(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__configsourceaddonlist__config__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configsourcemod(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__configsourcemod__config__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* configsourcemodlist(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__configsourcemodlist__config__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* confirmsensortarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__confirmsensortarget__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* connectterminaltouav(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__connectterminaltouav__object__object__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* connecttoserver(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__connecttoserver__array__ret__nothing, *right_arg);
}


extern "C" __declspec(dllexport) intercept::types::game_value* continuewith(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__continuewith__any__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* controlnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__controlnull__ret__control);
}

extern "C" __declspec(dllexport) intercept::types::game_value* controlsgroupctrl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__controlsgroupctrl__control__scalar__ret__control, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* conversationdisabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__conversationdisabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* copyfromclipboard()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__copyfromclipboard__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* copytoclipboard(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__copytoclipboard__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* copywaypoints(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__copywaypoints__group__group__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* count(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__count__code__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* countenemy(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__countenemy__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* countfriendly(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__countfriendly__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* countside(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__countside__side__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* counttype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__counttype__string__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* countunknown(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__countunknown__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* create3dencomposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__create3dencomposition__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* create3denentity(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__create3denentity__group__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createagent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createagent__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createcenter(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createcenter__side__ret__side, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createdialog(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createdialog__array__ret__display, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* creatediarylink(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__creatediarylink__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* creatediaryrecord(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__creatediaryrecord__object__array__ret__diary_record, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* creatediarysubject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__creatediarysubject__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createdisplay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createdisplay__display__string__ret__display, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* creategeardialog(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__creategeardialog__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* creategroup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__creategroup__side_array__ret__group, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createguardedpoint(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createguardedpoint__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createhashmap()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__createhashmap__ret__hashmap);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createhashmapfromarray(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createhashmapfromarray__array__array__ret__hashmap, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createlocation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createlocation__array__ret__location, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createmarker(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createmarker__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createmarkerlocal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createmarkerlocal__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createmenu(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createmenu__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createmine(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createmine__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createmissiondisplay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createmissiondisplay__display__array__ret__display, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* creatempcampaigndisplay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__creatempcampaigndisplay__display__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createsimpleobject(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createsimpleobject__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createsimpletask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createsimpletask__object__array__ret__task, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createsite(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createsite__string__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createsoundsource(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createsoundsource__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createtask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createtask__team_member__array__ret__task, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createteam(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createteam__array__ret__team_member, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createtrigger(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createtrigger__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createunit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createunit__group__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createvehicle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createvehicle__string__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createvehiclecrew(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__createvehiclecrew__object__ret__group, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* createvehiclelocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__createvehiclelocal__string__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* crew(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__crew__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctaddheader(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctaddheader__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctaddrow(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctaddrow__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctclear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctclear__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctcursel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctcursel__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctdata__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctfindheaderrows(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctfindheaderrows__control__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctfindrowheader(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctfindrowheader__control__scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctheadercontrols(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctheadercontrols__control__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctheadercount(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctheadercount__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctremoveheaders(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctremoveheaders__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctremoverows(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctremoverows__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlactivate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlactivate__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrladdeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrladdeventhandler__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlangle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlangle__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlanimatemodel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlanimatemodel__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlanimationphasemodel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlanimationphasemodel__control__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlat__display__array__ret__control, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlautoscrolldelay(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrolldelay__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlautoscrollrewind(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollrewind__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlautoscrollspeed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlautoscrollspeed__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlbackgroundcolor(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlbackgroundcolor__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlchecked(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlchecked__control__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlclassname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlclassname__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlcommit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlcommit__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlcommitted(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlcommitted__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlcreate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlcreate__display__array__ret__control, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrldelete(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrldelete__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlenable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlenable__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlenabled__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlfade(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlfade__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlfontheight(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlfontheight__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlforegroundcolor(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlforegroundcolor__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlhtmlloaded(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlhtmlloaded__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlidc(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlidc__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlidd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlidd__display__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapanimadd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlmapanimadd__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapanimclear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimclear__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapanimcommit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimcommit__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapanimdone(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapanimdone__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapcursor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlmapcursor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapdir(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapdir__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapmouseover(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapmouseover__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapposition__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapscale(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmapscale__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapscreentoworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlmapscreentoworld__control__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapsetposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlmapsetposition__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmapworldtoscreen(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlmapworldtoscreen__control__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmodel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmodel__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmodeldirandup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmodeldirandup__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmodelscale(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmodelscale__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlmouseposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlmouseposition__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlparent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlparent__control__ret__display, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlparentcontrolsgroup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlparentcontrolsgroup__control__ret__control, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlposition__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlremovealleventhandlers(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlremovealleventhandlers__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlremoveeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlremoveeventhandler__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlscale(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlscale__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlscrollvalues(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlscrollvalues__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetactivecolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetactivecolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetangle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetangle__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetautoscrolldelay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrolldelay__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetautoscrollrewind(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollrewind__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetautoscrollspeed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetautoscrollspeed__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetbackgroundcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetbackgroundcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetchecked(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetchecked__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetdisabledcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetdisabledcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlseteventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlseteventhandler__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfade(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfade__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfocus(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlsetfocus__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfont(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfont__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth1(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth1b(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth1b__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth2(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth2b(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth2b__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth3(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth3b(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth3b__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth4(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth4b(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth4b__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth5(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth5b(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth5b__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth6(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfonth6b(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfonth6b__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheight__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheighth1(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth1__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheighth2(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth2__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheighth3(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth3__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheighth4(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth4__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheighth5(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth5__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheighth6(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheighth6__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontheightsecondary(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontheightsecondary__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontp(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontp__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontpb(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontpb__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetfontsecondary(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetfontsecondary__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetforegroundcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetforegroundcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetmodel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodel__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetmodeldirandup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodeldirandup__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetmodelscale(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmodelscale__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetmouseposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetmouseposition__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetpixelprecision(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpixelprecision__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetposition__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetpositionh(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionh__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetpositionw(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionw__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetpositionx(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositionx__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetpositiony(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetpositiony__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetscale(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscale__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetscrollvalues(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetscrollvalues__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetshadow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetshadow__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsetstructuredtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsetstructuredtext__control__text__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettext__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettextcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettextcolorsecondary(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextcolorsecondary__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettextsecondary(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextsecondary__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettextselection(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettextselection__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettooltip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltip__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettooltipcolorbox(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorbox__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettooltipcolorshade(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolorshade__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettooltipcolortext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipcolortext__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlsettooltipmaxwidth(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlsettooltipmaxwidth__control__scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlseturl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlseturl__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlseturloverlaymode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlseturloverlaymode__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlshadow(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlshadow__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlshow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrlshow__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlshown(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlshown__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlstyle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlstyle__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltext__scalar__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltextcolor(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltextcolor__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltextheight(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltextheight__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltextsecondary(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltextsecondary__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltextselection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltextselection__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltextwidth(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltextwidth__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltooltip(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltooltip__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrltype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrltype__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlurl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlurl__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlurloverlaymode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlurloverlaymode__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrlvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrlvisible__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrowcontrols(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctrowcontrols__control__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctrowcount(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ctrowcount__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctsetcursel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctsetcursel__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctsetdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctsetdata__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctsetheadertemplate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctsetheadertemplate__control__config__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctsetrowtemplate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctsetrowtemplate__control__config__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctsetvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctsetvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ctvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ctvalue__control__scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatoraddons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatoraddons__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorcamera()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__curatorcamera__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorcameraarea(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatorcameraarea__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorcameraareaceiling(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatorcameraareaceiling__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorcoef(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__curatorcoef__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatoreditableobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatoreditableobjects__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatoreditingarea(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatoreditingarea__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatoreditingareatype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatoreditingareatype__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatormouseover()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__curatormouseover__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorpoints(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatorpoints__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorregisteredobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatorregisteredobjects__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorselected()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__curatorselected__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* curatorwaypointcost(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__curatorwaypointcost__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* current3denoperation()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__current3denoperation__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentchannel()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__currentchannel__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentcommand(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentcommand__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentmagazine(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentmagazine__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentmagazinedetail(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentmagazinedetail__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentmagazinedetailturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__currentmagazinedetailturret__object__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentmagazineturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__currentmagazineturret__object__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentmuzzle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentmuzzle__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentnamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__currentnamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentpilot(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentpilot__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currenttask(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currenttask__object__ret__task, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currenttasks(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currenttasks__team_member__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentthrowable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentthrowable__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentvisionmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__currentvisionmode__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentwaypoint(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentwaypoint__group__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentweapon(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentweapon__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentweaponmode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__currentweaponmode__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentweaponturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__currentweaponturret__object__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* currentzeroing(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__currentzeroing__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cursorobject()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cursorobject__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cursortarget()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__cursortarget__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* customchat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__customchat__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* customradio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__customradio__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* customwaypointposition()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__customwaypointposition__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cutfadeout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__cutfadeout__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cutobj(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__cutobj__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cutrsc(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__cutrsc__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* cuttext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__cuttext__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* damage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__damage__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* date()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__date__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* datetonumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__datetonumber__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* daytime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__daytime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deactivatekey(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deactivatekey__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* debriefingtext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__debriefingtext__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* debugfsm(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__debugfsm__scalar__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* debuglog(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__debuglog__any__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* decaygraphvalues(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__decaygraphvalues__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* default(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__default__code__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deg(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deg__scalar_nan__ret__scalar_nan, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* delete3denentities(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__delete3denentities__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deleteat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__deleteat__hashmap__side_config__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletecenter(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletecenter__side__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletecollection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletecollection__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deleteeditorobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__deleteeditorobject__control__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletegroup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletegroup__group__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletegroupwhenempty(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__deletegroupwhenempty__group__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deleteidentity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deleteidentity__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletelocation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletelocation__location__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletemarker(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletemarker__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletemarkerlocal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletemarkerlocal__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deleterange(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__deleterange__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deleteresources(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__deleteresources__team_member__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletesite(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletesite__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletestatus(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletestatus__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deleteteam(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deleteteam__team_member__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletevehicle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletevehicle__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletevehiclecrew(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__deletevehiclecrew__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* deletewaypoint(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__deletewaypoint__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* detach(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__detach__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* detectedmines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__detectedmines__side__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_activemissionfsms()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_activemissionfsms__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_activescripts()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_activescripts__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_activesqfscripts()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_activesqfscripts__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_activesqsscripts()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_activesqsscripts__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_allmissioneventhandlers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_allmissioneventhandlers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_captureframe(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_captureframe__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_captureframetofile(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_captureframetofile__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_captureslowframe(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_captureslowframe__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_codeperformance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_codeperformance__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_deltatime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_deltatime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_drawmode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_drawmode__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_dumpcalltracetolog()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_dumpcalltracetolog__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_dumpscriptassembly(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_dumpscriptassembly__code__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_dumpterrainsynth()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_dumpterrainsynth__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_dynamicsimulationend(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_dynamicsimulationend__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_enable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__diag_enable__string__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_enabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_enabled__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_exportconfig(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_exportconfig__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_exportterrainsvg(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_exportterrainsvg__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_fps()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_fps__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_fpsmin()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_fpsmin__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_frameno()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_frameno__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_getterrainsegmentoffset(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_getterrainsegmentoffset__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_lightnewload(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_lightnewload__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_list(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_list__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_localized(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_localized__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_log(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_log__any__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_logslowframe(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_logslowframe__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_mergeconfigfile(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_mergeconfigfile__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_recordturretlimits(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_recordturretlimits__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_resetfsm()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_resetfsm__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_resetshapes()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_resetshapes__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_scope()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_scope__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_setlightnew(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_setlightnew__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_stacktrace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_stacktrace__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_ticktime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diag_ticktime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diag_toggle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__diag_toggle__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dialog()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__dialog__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diaryrecordnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__diaryrecordnull__ret__task);
}

extern "C" __declspec(dllexport) intercept::types::game_value* diarysubjectexists(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__diarysubjectexists__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* didjip()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__didjip__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* didjipowner(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__didjipowner__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* difficulty()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__difficulty__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* difficultyenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__difficultyenabled__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* difficultyenabledrtd()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__difficultyenabledrtd__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* difficultyoption(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__difficultyoption__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* direction(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__direction__location__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* directionstabilizationenabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__directionstabilizationenabled__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* directsay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__directsay__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disableai(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disableai__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disablebrakes(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disablebrakes__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disablecollisionwith(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disablecollisionwith__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disableconversation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disableconversation__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disabledebriefingstats()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__disabledebriefingstats__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disablemapindicators(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__disablemapindicators__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disablenvgequipment(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disablenvgequipment__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disableremotesensors(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__disableremotesensors__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disableserialization()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__disableserialization__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disabletiequipment(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disabletiequipment__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disableuavconnectability(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__disableuavconnectability__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* disableuserinput(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__disableuserinput__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayaddeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__displayaddeventhandler__display__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displaychild(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__displaychild__display__ret__display, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayctrl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__displayctrl__display__scalar__ret__control, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displaynull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__displaynull__ret__display);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayparent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__displayparent__display__ret__display, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayremovealleventhandlers(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__displayremovealleventhandlers__display__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayremoveeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__displayremoveeventhandler__display__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayseteventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__displayseteventhandler__display__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayuniquename(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__displayuniquename__display__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* displayupdate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__displayupdate__display__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dissolveteam(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__dissolveteam__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* distance(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__distance__array__location__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* distance2d(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__distance2d__object_array__object_array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* distancesqr(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__distancesqr__array__location__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* distributionregion()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__distributionregion__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* do3denaction(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__do3denaction__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* doartilleryfire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__doartilleryfire__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dofire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__dofire__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dofollow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__dofollow__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dofsm(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__dofsm__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dogetout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__dogetout__object_array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* domove(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__domove__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* doorphase(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__doorphase__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dostop(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__dostop__object_array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dosuppressivefire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__dosuppressivefire__object_array__object_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dotarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__dotarget__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dowatch(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__dowatch__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawarrow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawarrow__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawellipse(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawellipse__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawicon__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawicon3d(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__drawicon3d__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawlaser(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__drawlaser__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawline(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawline__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawline3d(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__drawline3d__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawlink(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawlink__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawlocation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawlocation__control__location__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawpolygon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawpolygon__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawrectangle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawrectangle__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drawtriangle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__drawtriangle__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* driver(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__driver__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* drop(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__drop__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dynamicsimulationdistance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistance__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dynamicsimulationdistancecoef(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationdistancecoef__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dynamicsimulationenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__dynamicsimulationenabled__group__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* dynamicsimulationsystemenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__dynamicsimulationsystemenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* east()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__east__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* echo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__echo__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* edit3denmissionattributes(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__edit3denmissionattributes__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* editobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__editobject__control__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* editorseteventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__editorseteventhandler__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* effectivecommander(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__effectivecommander__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* elevateperiscope(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__elevateperiscope__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* emptypositions(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__emptypositions__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableai(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableai__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableaifeature(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableaifeature__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableaimprecision(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableaimprecision__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableattack(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableattack__object_group__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableaudiofeature(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableaudiofeature__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableautostartuprtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableautostartuprtd__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableautotrimrtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableautotrimrtd__object__bool__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablecamshake(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablecamshake__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablecaustics(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablecaustics__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablechannel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablechannel__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablecollisionwith(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablecollisionwith__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablecopilot(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablecopilot__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enabledebriefingstats(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enabledebriefingstats__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablediaglegend(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablediaglegend__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enabledirectionstabilization(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enabledirectionstabilization__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enabledynamicsimulation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enabledynamicsimulation__group__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enabledynamicsimulationsystem(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enabledynamicsimulationsystem__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableenddialog()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__enableenddialog__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableengineartillery(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enableengineartillery__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableenvironment(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enableenvironment__bool_array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablefatigue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablefatigue__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablegunlights(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablegunlights__object_group__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableinfopanelcomponent(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableinfopanelcomponent__object_array__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableirlasers(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableirlasers__object_group__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablemimics(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablemimics__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablepersonturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablepersonturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableradio(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enableradio__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablereload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablereload__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableropeattach(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableropeattach__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablesatnormalondetail(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablesatnormalondetail__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablesaving(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablesaving__bool_array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablesentences(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablesentences__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablesimulation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablesimulation__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablesimulationglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablesimulationglobal__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablestamina(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablestamina__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablestressdamage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enablestressdamage__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableteamswitch(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enableteamswitch__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enabletraffic(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enabletraffic__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableuavconnectability(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableuavconnectability__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableuavwaypoints(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableuavwaypoints__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablevehiclecargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablevehiclecargo__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enablevehiclesensor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enablevehiclesensor__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enableweapondisassembly(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__enableweapondisassembly__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* endl()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__endl__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* endloadingscreen()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__endloadingscreen__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* endmission(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__endmission__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* engineon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__engineon__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enginesisonrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enginesisonrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enginespowerrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enginespowerrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enginesrpmrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enginesrpmrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* enginestorquertd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__enginestorquertd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* entities(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__entities__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* environmentenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__environmentenabled__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* environmentvolume()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__environmentvolume__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* equipmentdisabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__equipmentdisabled__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* estimatedendservertime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__estimatedendservertime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* estimatedtimeleft(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__estimatedtimeleft__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* evalobjectargument(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__evalobjectargument__control__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* everybackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__everybackpack__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* everycontainer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__everycontainer__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* exec(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__exec__any__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* execeditorscript(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__execeditorscript__control__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* execfsm(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__execfsm__any__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* execvm(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__execvm__any__string__ret__script, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* exitwith(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__exitwith__if__code__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* expecteddestination(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__expecteddestination__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* exportjipmessages(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__exportjipmessages__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* eyedirection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__eyedirection__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* eyepos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__eyepos__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* face(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__face__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* faction(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__faction__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fadeenvironment(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__fadeenvironment__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fademusic(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__fademusic__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* faderadio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__faderadio__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fadesound(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__fadesound__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fadespeech(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__fadespeech__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* failmission(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__failmission__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fileexists(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__fileexists__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fillweaponsfrompool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__fillweaponsfrompool__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* find(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__find__string__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findany(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findany__array__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findcover(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findcover__object__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* finddisplay(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__finddisplay__string__ret__display, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findeditorobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findeditorobject__control__any__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findemptyposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findemptyposition__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findemptypositionready(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findemptypositionready__array__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findif(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findif__array__code__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* findnearestenemy(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__findnearestenemy__object__object_array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* finishmissioninit()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__finishmissioninit__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* finite(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__finite__scalar_nan__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__fire__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fireattarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__fireattarget__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* firstbackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__firstbackpack__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flag(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__flag__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flaganimationphase(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__flaganimationphase__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flagowner(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__flagowner__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flagside(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__flagside__object__ret__side, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flagtexture(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__flagtexture__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flatten(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__flatten__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fleeing(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__fleeing__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flyinheight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__flyinheight__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* flyinheightasl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__flyinheightasl__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* focusedctrl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__focusedctrl__display__ret__control, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fog()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__fog__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fogforecast()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__fogforecast__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fogparams()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__fogparams__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceadduniform(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forceadduniform__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceatpositionrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__forceatpositionrtd__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcecadetdifficulty(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__forcecadetdifficulty__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcedmap()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__forcedmap__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceend()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__forceend__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceflagtexture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forceflagtexture__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcefollowroad(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forcefollowroad__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcegeneratorrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__forcegeneratorrtd__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcemap(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__forcemap__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcerespawn(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__forcerespawn__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcespeed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forcespeed__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceunicode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__forceunicode__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forcewalk(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forcewalk__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceweaponfire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forceweaponfire__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forceweatherchange()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__forceweatherchange__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* foreach(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__foreach__code__hashmap__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* foreachmember(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__foreachmember__code__team_member__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* foreachmemberagent(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__foreachmemberagent__code__team_member__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* foreachmemberteam(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__foreachmemberteam__code__team_member__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* forgettarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__forgettarget__object_group__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* format(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__format__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formation__team_member__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formationdirection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formationdirection__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formationleader(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formationleader__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formationmembers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formationmembers__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formationposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formationposition__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formationtask(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formationtask__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formattext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formattext__array__ret__text, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* formleader(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__formleader__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* freeextension(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__freeextension__string__ret__bool_nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* freelook()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__freelook__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* from(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__from__for__scalar__ret__for, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fromeditor(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__fromeditor__team_member__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fuel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__fuel__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* fullcrew(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__fullcrew__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gearidcammocount(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gearidcammocount__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gearslotammocount(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gearslotammocount__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gearslotdata(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gearslotdata__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gesturestate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gesturestate__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__get__hashmap__side_config__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denactionstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3denactionstate__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denattribute(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__get3denattribute__scalar__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3dencamera()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__get3dencamera__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denconnections(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3denconnections__any__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denentity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3denentity__scalar__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denentityid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3denentityid__any__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3dengrid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3dengrid__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3deniconsvisible()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__get3deniconsvisible__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denlayerentities(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3denlayerentities__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denlinesvisible()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__get3denlinesvisible__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denmissionattribute(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__get3denmissionattribute__string__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denmouseover()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__get3denmouseover__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* get3denselected(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__get3denselected__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getaimingcoef(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getaimingcoef__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallenv3dsoundcontrollers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallenv3dsoundcontrollers__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallenvsoundcontrollers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallenvsoundcontrollers__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallhitpointsdamage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallhitpointsdamage__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallownedmines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallownedmines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallpylonsinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallpylonsinfo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallsoundcontrollers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallsoundcontrollers__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getallunittraits(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getallunittraits__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getammocargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getammocargo__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getanimaimprecision(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getanimaimprecision__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getanimspeedcoef(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getanimspeedcoef__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getarray(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getarray__config__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getartilleryammo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getartilleryammo__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getartillerycomputersettings()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getartillerycomputersettings__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getartilleryeta(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getartilleryeta__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getassetdlcinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getassetdlcinfo__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getassignedcuratorlogic(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorlogic__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getassignedcuratorunit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getassignedcuratorunit__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getattacktarget(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getattacktarget__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getaudiooptionvolumes()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getaudiooptionvolumes__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getbackpackcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getbackpackcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getbleedingremaining(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getbleedingremaining__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getburningvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getburningvalue__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcalculateplayervisibilitybyfriendly()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getcalculateplayervisibilitybyfriendly__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcameraviewdirection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcameraviewdirection__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcargoindex(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getcargoindex__object__object__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcenterofmass(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcenterofmass__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getclientstate()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getclientstate__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getclientstatenumber()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getclientstatenumber__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcompatiblepylonmagazines(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getcompatiblepylonmagazines__string__string_scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getconnecteduav(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getconnecteduav__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getconnecteduavunit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getconnecteduavunit__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcontainermaxload(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcontainermaxload__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcorpse(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcorpse__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcruisecontrol(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcruisecontrol__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcursorobjectparams()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getcursorobjectparams__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcustomaimcoef(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcustomaimcoef__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcustomsoundcontroller(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontroller__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getcustomsoundcontrollercount(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getcustomsoundcontrollercount__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdammage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdammage__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdebriefingtext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdebriefingtext__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdescription(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdescription__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getdir__object_array__object_array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdirvisual(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getdirvisual__object_array__object_array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdiverstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdiverstate__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdlcassetsusage()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getdlcassetsusage__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdlcassetsusagebyname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdlcassetsusagebyname__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdlcs(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdlcs__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getdlcusagetime(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getdlcusagetime__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* geteditorcamera(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__geteditorcamera__control__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* geteditormode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__geteditormode__control__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* geteditorobjectscope(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__geteditorobjectscope__control__string__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getelevationoffset()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getelevationoffset__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getenginetargetrpmrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getenginetargetrpmrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getenv3dsoundcontroller(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getenv3dsoundcontroller__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getenvsoundcontroller(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getenvsoundcontroller__array__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* geteventhandlerinfo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__geteventhandlerinfo__object_group__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getfatigue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getfatigue__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getfieldmanualstartpage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getfieldmanualstartpage__display__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getforcedflagtexture(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getforcedflagtexture__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getforcedspeed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getforcedspeed__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getfriend(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getfriend__side__side__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getfsmvariable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getfsmvariable__scalar__string_array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getfuelcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getfuelcargo__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getgraphvalues(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getgraphvalues__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getgroupicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getgroupicon__group__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getgroupiconparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getgroupiconparams__group__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getgroupicons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getgroupicons__group__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gethidefrom(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__gethidefrom__object__object__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gethit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__gethit__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gethitindex(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__gethitindex__object__scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gethitpointdamage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__gethitpointdamage__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getitemcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getitemcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getlighting()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getlighting__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getlightingat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getlightingat__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getloadedmodsinfo()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getloadedmodsinfo__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmagazinecargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmagazinecargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmarkercolor(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmarkercolor__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmarkerpos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmarkerpos__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmarkersize(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmarkersize__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmarkertype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmarkertype__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmass(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmass__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmissionconfig(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmissionconfig__string__ret__config, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmissionconfigvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmissionconfigvalue__string_array__ret__array_string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmissiondlcs()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getmissiondlcs__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmissionlayerentities(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmissionlayerentities__string_scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmissionlayers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getmissionlayers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmissionpath(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmissionpath__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmodelinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getmodelinfo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmouseposition()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getmouseposition__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getmusicplayedtime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getmusicplayedtime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getnumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getnumber__config__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectargument(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getobjectargument__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectchildren(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getobjectchildren__control__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectdlc(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjectdlc__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectfov(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjectfov__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjectid__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectmaterials(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjectmaterials__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectproxy(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getobjectproxy__control__string__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectscale(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjectscale__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjecttextures(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjecttextures__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjecttype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getobjecttype__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getobjectviewdistance()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getobjectviewdistance__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getopticsmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getopticsmode__object__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getordefault(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getordefault__hashmap__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getordefaultcall(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getordefaultcall__hashmap__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getoxygenremaining(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getoxygenremaining__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpersonuseddlcs(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getpersonuseddlcs__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpilotcameradirection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getpilotcameradirection__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpilotcameraposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getpilotcameraposition__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpilotcamerarotation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getpilotcamerarotation__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpilotcameratarget(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getpilotcameratarget__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpipviewdistance()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getpipviewdistance__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getplatenumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getplatenumber__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getplayerchannel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getplayerchannel__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getplayerid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getplayerid__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getplayerscores(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getplayerscores__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getplayeruid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getplayeruid__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getplayervonvolume(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getplayervonvolume__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getpos__object_array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposasl__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposaslvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposaslvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposaslw(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposaslw__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposatl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposatl__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposatlvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposatlvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposworld(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposworld__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getposworldvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getposworldvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getpylonmagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getpylonmagazines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getreldir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getreldir__object__object_array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getrelpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getrelpos__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getremotesensorsdisabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getremotesensorsdisabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getrepaircargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getrepaircargo__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getresolution()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getresolution__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getroadinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getroadinfo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getrotorbrakertd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getrotorbrakertd__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsensortargets(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getsensortargets__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsensorthreats(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getsensorthreats__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getshadowdistance()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getshadowdistance__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getshotparents(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getshotparents__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getslingload(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getslingload__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsoundcontroller(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getsoundcontroller__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsoundcontrollerresult(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getsoundcontrollerresult__object__config__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getspeed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getspeed__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getstamina(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getstamina__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getstatvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getstatvalue__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsteamfriendsservers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getsteamfriendsservers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsubtitleoptions()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getsubtitleoptions__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getsuppression(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getsuppression__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getterraingrid()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getterraingrid__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getterrainheight(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getterrainheight__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getterrainheightasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getterrainheightasl__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getterraininfo()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getterraininfo__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gettext__config__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettextraw(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gettextraw__config__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettextureinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gettextureinfo__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettextwidth(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__gettextwidth__string__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettiparameters()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__gettiparameters__ret__hashmap);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettotaldlcusagetime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__gettotaldlcusagetime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettowparent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gettowparent__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gettrimoffsetrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gettrimoffsetrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getturretlimits(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getturretlimits__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getturretopticsmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getturretopticsmode__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getunitfreefallinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getunitfreefallinfo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getunitloadout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getunitloadout__config__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getunittrait(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getunittrait__object__string__ret__nothing_bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getunloadincombat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getunloadincombat__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getuserinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getuserinfo__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getusermfdtext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getusermfdtext__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getusermfdvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getusermfdvalue__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getvariable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__getvariable__location__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getvehiclecargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getvehiclecargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getvehicletipars(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getvehicletipars__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getvideooptions()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__getvideooptions__ret__hashmap);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getweaponcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getweaponcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getweaponsway(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getweaponsway__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getwingsorientationrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getwingsorientationrtd__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getwingspositionrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getwingspositionrtd__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* getwppos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__getwppos__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* glanceat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__glanceat__object_array__object_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* globalchat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__globalchat__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* globalradio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__globalradio__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* goggles(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__goggles__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* group(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__group__object__ret__group, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupchat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__groupchat__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupfromnetid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__groupfromnetid__string__ret__group, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupiconselectable()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__groupiconselectable__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupiconsvisible()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__groupiconsvisible__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__groupid__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupowner(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__groupowner__group__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupradio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__groupradio__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groups(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__groups__side__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupselectedunits(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__groupselectedunits__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* groupselectunit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__groupselectunit__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* grpnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__grpnull__ret__group);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gunner(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__gunner__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* gusts()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__gusts__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* halt()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__halt__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* handgunitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__handgunitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* handgunmagazine(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__handgunmagazine__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* handgunweapon(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__handgunweapon__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* handshit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__handshit__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hashvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hashvalue__object_side__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hasinterface()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__hasinterface__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* haspilotcamera(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__haspilotcamera__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hasweapon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hasweapon__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcallgroups(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hcallgroups__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcgroupparams(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hcgroupparams__object__group__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcleader(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hcleader__group__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcremoveallgroups(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hcremoveallgroups__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcremovegroup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hcremovegroup__object__group__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcselected(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hcselected__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcselectgroup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hcselectgroup__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcsetgroup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hcsetgroup__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcshowbar(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hcshowbar__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hcshownbar()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__hcshownbar__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* headgear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__headgear__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hidebody(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hidebody__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hideobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hideobject__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hideobjectglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hideobjectglobal__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hideselection(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hideselection__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hint(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hint__text_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hintc(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__hintc__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hintcadet(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hintcadet__text_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hintsilent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hintsilent__text_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hmd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hmd__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hostmission(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__hostmission__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* htmlload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__htmlload__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* hudmovementlevels()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__hudmovementlevels__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* humidity()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__humidity__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* image(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__image__string__ret__text, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* importallgroups(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__importallgroups__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* importance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__importance__location__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* in(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__in__array__location__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inarea(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__inarea__array__location__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inareaarray(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__inareaarray__array__location__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* incapacitatedstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__incapacitatedstate__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* independent()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__independent__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inflame(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__inflame__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inflamed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__inflamed__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* infopanel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__infopanel__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* infopanelcomponentenabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponentenabled__object_array__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* infopanelcomponents(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__infopanelcomponents__object_array__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* infopanels(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__infopanels__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ingameuiseteventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ingameuiseteventhandler__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inheritsfrom(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__inheritsfrom__config__ret__config, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* initambientlife()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__initambientlife__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inpolygon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__inpolygon__array__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inputaction(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__inputaction__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inputcontroller(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__inputcontroller__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inputmouse(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__inputmouse__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inrangeofartillery(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__inrangeofartillery__array__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* insert(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__insert__hashmap__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* inserteditorobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__inserteditorobject__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* insidebuilding(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__insidebuilding__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* intersect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__intersect__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* is3den()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__is3den__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* is3denmultiplayer()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__is3denmultiplayer__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* is3denpreview()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__is3denpreview__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isabletobreathe(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isabletobreathe__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isactionmenuvisible()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isactionmenuvisible__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isagent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isagent__team_member__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isaimprecisionenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isaimprecisionenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isallowedcrewinimmobile(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isallowedcrewinimmobile__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isarray(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isarray__config__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isautohoveron(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isautohoveron__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isautonomous(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isautonomous__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isautostartupenabledrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isautostartupenabledrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isautotest()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isautotest__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isautotrimonrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isautotrimonrtd__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isawake(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isawake__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isbleeding(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isbleeding__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isburning(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isburning__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isclass(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isclass__config__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* iscollisionlighton(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__iscollisionlighton__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* iscopilotenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__iscopilotenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isdamageallowed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isdamageallowed__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isdedicated()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isdedicated__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isdlcavailable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isdlcavailable__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isengineon(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isengineon__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequalref(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequalref__any__any__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequalto(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequalto__any__any__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequaltype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequaltype__any__any__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequaltypeall(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequaltypeall__any__any__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequaltypeany(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequaltypeany__any__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequaltypearray(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequaltypearray__any__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isequaltypeparams(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isequaltypeparams__any__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isfilepatchingenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isfilepatchingenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isfinal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isfinal__code_string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isflashlighton(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isflashlighton__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isflatempty(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isflatempty__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isforcedwalk(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isforcedwalk__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isformationleader(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isformationleader__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isgamefocused()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isgamefocused__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isgamepaused()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isgamepaused__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isgroupdeletedwhenempty(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isgroupdeletedwhenempty__group__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ishidden(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ishidden__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isinremainscollector(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isinremainscollector__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isinstructorfigureenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isinstructorfigureenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isirlaseron(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isirlaseron__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* iskeyactive(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__iskeyactive__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* iskindof(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__iskindof__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* islaseron(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__islaseron__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* islighton(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__islighton__object_array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* islocalized(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__islocalized__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ismanualfire(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ismanualfire__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ismarkedforcollection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ismarkedforcollection__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ismissionprofilenamespaceloaded()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__ismissionprofilenamespaceloaded__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ismultiplayer()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__ismultiplayer__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ismultiplayersolo()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__ismultiplayersolo__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isnil(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isnil__code_string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isnotequalref(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isnotequalref__any__any__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isnotequalto(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isnotequalto__any__any__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isnull(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isnull__location__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isnumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isnumber__config__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isobjecthidden(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isobjecthidden__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isobjectrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isobjectrtd__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isonroad(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isonroad__object_array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ispipenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__ispipenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isplayer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isplayer__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isrealtime(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isrealtime__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isremoteexecuted()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isremoteexecuted__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isremoteexecutedjip()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isremoteexecutedjip__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* issaving()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__issaving__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* issensortargetconfirmed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__issensortargetconfirmed__object__side__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isserver()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isserver__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isshowing3dicons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isshowing3dicons__control__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* issimpleobject(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__issimpleobject__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* issprintallowed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__issprintallowed__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isstaminaenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isstaminaenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* issteammission()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__issteammission__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* issteamoverlayenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__issteamoverlayenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isstreamfriendlyuienabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isstreamfriendlyuienabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isstressdamageenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isstressdamageenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* istext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__istext__config__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* istouchingground(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__istouchingground__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isturnedout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isturnedout__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* istuthintsenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__istuthintsenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isuavconnectable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isuavconnectable__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isuavconnected(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isuavconnected__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isuicontext()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__isuicontext__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isuniformallowed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isuniformallowed__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isvehiclecargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isvehiclecargo__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isvehicleradaron(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isvehicleradaron__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isvehiclesensorenabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__isvehiclesensorenabled__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* iswalking(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__iswalking__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isweapondeployed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isweapondeployed__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* isweaponrested(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__isweaponrested__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* itemcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__itemcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* items(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__items__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* itemswithmagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__itemswithmagazines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* join(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__join__array__object_group__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* joinas(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__joinas__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* joinassilent(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__joinassilent__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* joinsilent(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__joinsilent__array__object_group__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* joinstring(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__joinstring__array__string__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbadddatabase(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbadddatabase__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbadddatabasetargets(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbadddatabasetargets__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbaddtopic(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbaddtopic__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbhastopic(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbhastopic__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbreact(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbreact__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbremovetopic(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbremovetopic__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbtell(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbtell__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* kbwassaid(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__kbwassaid__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* keyimage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__keyimage__string_scalar__ret__text, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* keyname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__keyname__string_scalar__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* keys(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__keys__hashmap__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* knowsabout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__knowsabout__side__object__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* land(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__land__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* landat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__landat__object__object_scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* landresult(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__landresult__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* language()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__language__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lasertarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lasertarget__object__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbadd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbadd__control__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbclear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lbclear__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbcolor__control__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbcolorright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbcolorright__control__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbcursel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lbcursel__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbdata__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbdelete(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbdelete__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbisselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbisselected__control__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbpicture__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbpictureright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbpictureright__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbselection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lbselection__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetcolorright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetcolorright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetcursel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetcursel__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetdata__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicture__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicturecolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicturecolordisabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolordisabled__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicturecolorselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturecolorselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpictureright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpictureright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicturerightcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicturerightcolordisabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolordisabled__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetpicturerightcolorselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetpicturerightcolorselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetselectcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetselectcolorright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetselectcolorright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsettext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsettext__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsettextright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsettextright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsettooltip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsettooltip__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsetvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsetvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsize(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lbsize__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsort(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lbsort__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsortby(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbsortby__control_scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbsortbyvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lbsortbyvalue__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbtext__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbtextright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbtextright__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbtooltip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbtooltip__control__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lbvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lbvalue__control__scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leader(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leader__team_member__ret__team_member, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboarddeinit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboarddeinit__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardgetrows(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardgetrows__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardinit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardinit__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardrequestrowsfriends(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsfriends__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardrequestrowsglobal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobal__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardrequestrowsglobalarounduser(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardrequestrowsglobalarounduser__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardsrequestuploadscore(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscore__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardsrequestuploadscorekeepbest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardsrequestuploadscorekeepbest__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leaderboardstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__leaderboardstate__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* leavevehicle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__leavevehicle__group__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* librarycredits()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__librarycredits__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* librarydisclaimers()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__librarydisclaimers__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lifestate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lifestate__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lightattachobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lightattachobject__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lightdetachobject(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lightdetachobject__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lightison(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lightison__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lightnings()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__lightnings__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* limitspeed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__limitspeed__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* linearconversion(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__linearconversion__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* linebreak()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__linebreak__ret__text);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lineintersects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lineintersects__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lineintersectsobjs(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lineintersectsobjs__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lineintersectssurfaces(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lineintersectssurfaces__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lineintersectswith(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lineintersectswith__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* linkitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__linkitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* list(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__list__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* listobjects(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__listobjects__control__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* listremotetargets(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__listremotetargets__side__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* listvehiclesensors(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__listvehiclesensors__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ln(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ln__scalar_nan__ret__scalar_nan, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbaddarray(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lnbaddarray__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbaddcolumn(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbaddcolumn__control__scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbaddrow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbaddrow__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbclear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lnbclear__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbcolor__control__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbcolorright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbcolorright__control__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbcurselrow(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lnbcurselrow__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbdata__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbdeletecolumn(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbdeletecolumn__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbdeleterow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbdeleterow__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbgetcolumnsposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lnbgetcolumnsposition__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbpicture__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbpictureright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbpictureright__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetcolorright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolorright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetcolumnspos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetcolumnspos__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetcurselrow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetcurselrow__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetdata__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicture__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetpicturecolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetpicturecolorright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetpicturecolorselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetpicturecolorselectedright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetpicturecolorselectedright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetpictureright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetpictureright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsettext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsettext__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsettextright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsettextright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsettooltip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsettooltip__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsetvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsetvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsize(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lnbsize__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsort(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsort__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsortby(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsortby__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbsortbyvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbsortbyvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbtext__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbtextright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbtextright__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lnbvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lnbvalue__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* load(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__load__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadabs(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__loadabs__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadbackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__loadbackpack__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadconfig(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__loadconfig__string__ret__config, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadfile(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__loadfile__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadgame()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__loadgame__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadidentity(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__loadidentity__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadmagazine(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__loadmagazine__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadoverlay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__loadoverlay__control__config__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadstatus(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__loadstatus__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loaduniform(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__loaduniform__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* loadvest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__loadvest__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* local(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__local__group__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* localize(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__localize__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* localnamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__localnamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* locationnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__locationnull__ret__location);
}

extern "C" __declspec(dllexport) intercept::types::game_value* locationposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__locationposition__location__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lock(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lock__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockcamerato(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockcamerato__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockcargo__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockdriver(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockdriver__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* locked(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__locked__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockedcamerato(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockedcamerato__object__array__ret__nothing_object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockedcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockedcargo__object__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockeddriver(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lockeddriver__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockedinventory(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lockedinventory__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockedturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockedturret__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockidentity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lockidentity__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockinventory(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockinventory__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lockwp(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lockwp__object_group__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* logentities()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__logentities__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lognetwork(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lognetwork__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lognetworkterminate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__lognetworkterminate__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lookat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lookat__object_array__object_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* lookatpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__lookatpos__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinecargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinecargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazines__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesallturrets(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesallturrets__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesammo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesammo__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesammocargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesammocargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesammofull(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesammofull__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesdetail(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesdetail__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesdetailbackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailbackpack__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesdetailuniform(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailuniform__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesdetailvest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__magazinesdetailvest__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazinesturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__magazinesturret__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* magazineturretammo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__magazineturretammo__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mapanimadd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__mapanimadd__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mapanimclear()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__mapanimclear__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mapanimcommit()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__mapanimcommit__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mapanimdone()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__mapanimdone__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mapcenteroncamera(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__mapcenteroncamera__control__bool__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mapgridposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__mapgridposition__object_array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markasfinishedonsteam()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__markasfinishedonsteam__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markeralpha(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markeralpha__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markerbrush(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markerbrush__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markerchannel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markerchannel__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markercolor(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markercolor__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markerdir(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markerdir__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markerpolyline(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markerpolyline__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markerpos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markerpos__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markershadow(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markershadow__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markershape(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markershape__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markersize(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markersize__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markertext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markertext__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* markertype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__markertype__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* matrixmultiply(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__matrixmultiply__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* matrixtranspose(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__matrixtranspose__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* max(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__max__scalar_nan__scalar_nan__ret__scalar_nan, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* maxload(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__maxload__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* members(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__members__team_member__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuaction__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuadd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuadd__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuchecked(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuchecked__control__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuclear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__menuclear__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menucollapse(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menucollapse__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menudata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menudata__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menudelete(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menudelete__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuenable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuenable__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuenabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuenabled__control__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuexpand(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuexpand__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuhover(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__menuhover__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menupicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menupicture__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusetaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusetaction__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusetcheck(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusetcheck__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusetdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusetdata__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusetpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusetpicture__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusetshortcut(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusetshortcut__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusettext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusettext__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuseturl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuseturl__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusetvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusetvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menushortcut(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menushortcut__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menushortcuttext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menushortcuttext__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusize(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusize__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menusort(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menusort__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menutext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menutext__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuurl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuurl__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* menuvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__menuvalue__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* merge(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__merge__hashmap__hashmap_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* min(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__min__scalar_nan__scalar_nan__ret__scalar_nan, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mineactive(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__mineactive__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* minedetectedby(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__minedetectedby__object__side__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missiletarget(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__missiletarget__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missiletargetpos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__missiletargetpos__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionconfigfile()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionconfigfile__ret__config);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missiondifficulty()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missiondifficulty__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionend()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionend__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionname()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionname__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionnamesource()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionnamesource__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionnamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionnamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionprofilenamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionprofilenamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionstart()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionstart__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* missionversion()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__missionversion__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* mod(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__mod__scalar_nan__scalar_nan__ret__scalar_nan, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* modeltoworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__modeltoworld__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* modeltoworldvisual(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisual__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* modeltoworldvisualworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__modeltoworldvisualworld__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* modeltoworldworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__modeltoworldworld__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* modparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__modparams__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moonintensity()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__moonintensity__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moonphase(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__moonphase__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* morale(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__morale__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* move(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__move__object_group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* move3dencamera(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__move3dencamera__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveinany(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveinany__object__object__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveincargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveincargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveincommander(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveincommander__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveindriver(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveindriver__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveingunner(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveingunner__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveinturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveinturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveobjecttoend(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveobjecttoend__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveout__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* movetime(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__movetime__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* moveto(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__moveto__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* movetocompleted(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__movetocompleted__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* movetofailed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__movetofailed__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* musicvolume()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__musicvolume__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* name(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__name__location__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* namedproperties(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__namedproperties__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* namesound(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__namesound__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearentities(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nearentities__object_array__scalar_array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestbuilding(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestbuilding__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestlocation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestlocation__array__ret__location, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestlocations(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestlocations__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestlocationwithdubbing(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestlocationwithdubbing__array__ret__location, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestmines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestmines__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nearestobject__array__scalar__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestobjects__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearestterrainobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nearestterrainobjects__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearobjects(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nearobjects__object_array__scalar_array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearobjectsready(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nearobjectsready__object_array__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearroads(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nearroads__object_array__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nearsupplies(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nearsupplies__object_array__scalar_array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* neartargets(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__neartargets__object__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* needreload(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__needreload__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* needservice(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__needservice__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* netid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__netid__group__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* netobjnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__netobjnull__ret__netobject);
}

extern "C" __declspec(dllexport) intercept::types::game_value* newoverlay(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__newoverlay__control__config__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nextmenuitemindex(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__nextmenuitemindex__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nextweatherchange()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__nextweatherchange__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nil()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__nil__ret__any);
}

extern "C" __declspec(dllexport) intercept::types::game_value* nmenuitems(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__nmenuitems__control__string_scalar__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* not(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__not__bool__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* numberofenginesrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__numberofenginesrtd__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* numbertodate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__numbertodate__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* objectcurators(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__objectcurators__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* objectfromnetid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__objectfromnetid__string__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* objectparent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__objectparent__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* objnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__objnull__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* objstatus(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__objstatus__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onbriefinggroup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onbriefinggroup__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onbriefingnotes(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onbriefingnotes__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onbriefingplan(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onbriefingplan__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onbriefingteamswitch(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onbriefingteamswitch__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* oncommandmodechanged(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__oncommandmodechanged__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ondoubleclick(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ondoubleclick__control__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* oneachframe(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__oneachframe__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ongroupiconclick(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ongroupiconclick__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ongroupiconoverenter(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverenter__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ongroupiconoverleave(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ongroupiconoverleave__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onhcgroupselectionchanged(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onhcgroupselectionchanged__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onmapsingleclick(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__onmapsingleclick__any__code_string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onplayerconnected(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onplayerconnected__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onplayerdisconnected(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onplayerdisconnected__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onpreloadfinished(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onpreloadfinished__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onpreloadstarted(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onpreloadstarted__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onshownewobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__onshownewobject__control__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* onteamswitch(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__onteamswitch__code_string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* opencuratorinterface()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__opencuratorinterface__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* opendlcpage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__opendlcpage__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* opengps(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__opengps__bool__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* openmap(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__openmap__bool__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* opensteamapp(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__opensteamapp__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* openyoutubevideo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__openyoutubevideo__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* opfor()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__opfor__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* or (intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__or__bool__code__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ordergetin(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ordergetin__array__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* overcast()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__overcast__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* overcastforecast()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__overcastforecast__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* owner(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__owner__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* param(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__param__any__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* params(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__params__any__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* parsenumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__parsenumber__bool__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* parsesimplearray(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__parsesimplearray__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* parsetext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__parsetext__string__ret__text, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* parsingnamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__parsingnamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* particlesquality()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__particlesquality__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* periscopeelevation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__periscopeelevation__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pi()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__pi__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pickweaponpool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__pickweaponpool__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pitch(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__pitch__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pixelgrid()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__pixelgrid__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pixelgridbase()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__pixelgridbase__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pixelgridnouiscale()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__pixelgridnouiscale__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pixelh()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__pixelh__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pixelw()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__pixelw__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playableslotsnumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playableslotsnumber__side__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playableunits()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__playableunits__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__playaction__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playactionnow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__playactionnow__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* player()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__player__ret__object);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playerrespawntime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__playerrespawntime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playerside()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__playerside__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playersnumber(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playersnumber__side__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playgesture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__playgesture__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playmission(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playmission__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playmove(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__playmove__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playmovenow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__playmovenow__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playmusic(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playmusic__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playscriptedmission(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playscriptedmission__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playsound(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playsound__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playsound3d(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playsound3d__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* playsoundui(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__playsoundui__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pose(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__pose__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* position(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__position__location__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* positioncameratoworld(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__positioncameratoworld__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* posscreentoworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__posscreentoworld__control__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* posworldtoscreen(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__posworldtoscreen__control__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectadjust(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ppeffectadjust__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectcommit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ppeffectcommit__array__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectcommitted(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ppeffectcommitted__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectcreate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ppeffectcreate__array__ret__scalar_array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectdestroy(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ppeffectdestroy__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectenable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ppeffectenable__scalar__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ppeffectenabled__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ppeffectforceinnvg(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ppeffectforceinnvg__scalar__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* precision(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__precision__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preloadcamera(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__preloadcamera__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preloadobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__preloadobject__scalar__object_string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preloadsound(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__preloadsound__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preloadtitleobj(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__preloadtitleobj__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preloadtitlersc(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__preloadtitlersc__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preprocessfile(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__preprocessfile__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* preprocessfilelinenumbers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__preprocessfilelinenumbers__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* primaryweapon(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__primaryweapon__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* primaryweaponitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__primaryweaponitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* primaryweaponmagazine(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__primaryweaponmagazine__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* priority(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__priority__task__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* processdiarylink(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__processdiarylink__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* productversion()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__productversion__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* profilename()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__profilename__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* profilenamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__profilenamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* profilenamesteam()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__profilenamesteam__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* progressloadingscreen(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__progressloadingscreen__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* progressposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__progressposition__control__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* progresssetposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__progresssetposition__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* publicvariable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__publicvariable__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* publicvariableclient(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__publicvariableclient__scalar__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* publicvariableserver(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__publicvariableserver__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pushback(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__pushback__array__any__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* pushbackunique(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__pushbackunique__array__any__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* putweaponpool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__putweaponpool__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* queryitemspool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__queryitemspool__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* querymagazinepool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__querymagazinepool__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* queryweaponpool(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__queryweaponpool__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rad(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rad__scalar_nan__ret__scalar_nan, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiochanneladd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__radiochanneladd__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiochannelcreate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__radiochannelcreate__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiochannelinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__radiochannelinfo__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiochannelremove(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__radiochannelremove__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiochannelsetcallsign(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetcallsign__scalar__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiochannelsetlabel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__radiochannelsetlabel__scalar__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radioenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__radioenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* radiovolume()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__radiovolume__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rain()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__rain__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rainbow()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__rainbow__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rainparams()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__rainparams__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* random(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__random__scalar__scalar_array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rank(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rank__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rankid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rankid__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rating(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rating__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rectangular(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rectangular__location__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* regexfind(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__regexfind__string__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* regexmatch(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__regexmatch__string__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* regexreplace(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__regexreplace__string__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* registeredtasks(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__registeredtasks__team_member__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* registertask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__registertask__team_member__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* reload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__reload__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* reloadenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__reloadenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remotecontrol(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__remotecontrol__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remoteexec(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__remoteexec__any__array__ret__string_nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remoteexeccall(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__remoteexeccall__any__array__ret__string_nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remoteexecutedowner()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__remoteexecutedowner__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remove3denconnection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__remove3denconnection__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remove3deneventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__remove3deneventhandler__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* remove3denlayer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__remove3denlayer__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeaction__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeall3deneventhandlers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeall3deneventhandlers__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallactions(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallactions__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallassigneditems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallassigneditems__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallbinocularitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallbinocularitems__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallcontainers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallcontainers__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallcuratoraddons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoraddons__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallcuratorcameraareas(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallcuratorcameraareas__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallcuratoreditingareas(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallcuratoreditingareas__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removealleventhandlers(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removealleventhandlers__group__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallhandgunitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallhandgunitems__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallitems__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallitemswithmagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallitemswithmagazines__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallmissioneventhandlers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallmissioneventhandlers__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallmpeventhandlers(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeallmpeventhandlers__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallmusiceventhandlers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallmusiceventhandlers__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallownedmines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallownedmines__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallprimaryweaponitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallprimaryweaponitems__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallsecondaryweaponitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallsecondaryweaponitems__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removealluseractioneventhandlers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removealluseractioneventhandlers__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeallweapons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeallweapons__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removebackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removebackpack__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removebackpackglobal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removebackpackglobal__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removebinocularitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removebinocularitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removecuratoraddons(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removecuratoraddons__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removecuratorcameraarea(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removecuratorcameraarea__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removecuratoreditableobjects(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditableobjects__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removecuratoreditingarea(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removecuratoreditingarea__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removediaryrecord(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removediaryrecord__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removediarysubject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removediarysubject__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removedrawicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removedrawicon__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removedrawlinks(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removedrawlinks__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeeventhandler__group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removefromremainscollector(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removefromremainscollector__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removegoggles(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removegoggles__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removegroupicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removegroupicon__group__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removehandgunitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removehandgunitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeheadgear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeheadgear__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeitemfrombackpack(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeitemfrombackpack__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeitemfromuniform(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeitemfromuniform__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeitemfromvest(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeitemfromvest__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeitems(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeitems__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemagazine(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removemagazine__object__string_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemagazineglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removemagazineglobal__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemagazines(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removemagazines__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemagazinesturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removemagazinesturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemagazineturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removemagazineturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemenuitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removemenuitem__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemissioneventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removemissioneventhandler__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removempeventhandler(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removempeventhandler__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removemusiceventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removemusiceventhandler__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeownedmine(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeownedmine__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeprimaryweaponitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeprimaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removesecondaryweaponitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removesecondaryweaponitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removesimpletask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removesimpletask__object__task__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeswitchableunit(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeswitchableunit__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeteammember(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeteammember__team_member__team_member__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeuniform(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeuniform__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeuseractioneventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removeuseractioneventhandler__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removevest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__removevest__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeweapon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeweapon__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeweaponattachmentcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeweaponattachmentcargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeweaponcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeweaponcargo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeweaponglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeweaponglobal__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* removeweaponturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__removeweaponturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* reportremotetarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__reportremotetarget__side__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* requiredversion(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__requiredversion__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* resetcamshake()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__resetcamshake__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* resetsubgroupdirection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__resetsubgroupdirection__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* resistance()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__resistance__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* resize(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__resize__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* resources(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__resources__team_member__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* respawnvehicle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__respawnvehicle__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* restarteditorcamera(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__restarteditorcamera__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* reveal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__reveal__object_group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* revealmine(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__revealmine__side__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* reverse(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__reverse__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* reversedmousey()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__reversedmousey__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* roadat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__roadat__object_array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* roadsconnectedto(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__roadsconnectedto__object_array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* roledescription(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__roledescription__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeattachedobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropeattachedobjects__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeattachedto(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropeattachedto__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeattachenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropeattachenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeattachto(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ropeattachto__object_array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropecreate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropecreate__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropecut(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropecut__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropedestroy(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropedestroy__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropedetach(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__ropedetach__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeendposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropeendposition__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropelength(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropelength__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropes(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropes__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropesattachedto(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropesattachedto__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropesegments(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropesegments__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeunwind(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropeunwind__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* ropeunwound(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__ropeunwound__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rotorsforcesrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rotorsforcesrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* rotorsrpmrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__rotorsrpmrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* runinitscript()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__runinitscript__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* safezoneh()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__safezoneh__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* safezonew()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__safezonew__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* safezonewabs()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__safezonewabs__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* safezonex()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__safezonex__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* safezonexabs()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__safezonexabs__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* safezoney()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__safezoney__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* save3deninventory(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__save3deninventory__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* savegame()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__savegame__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* saveidentity(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__saveidentity__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* savejoysticks()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__savejoysticks__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* savemissionprofilenamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__savemissionprofilenamespace__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* saveoverlay(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__saveoverlay__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* saveprofilenamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__saveprofilenamespace__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* savestatus(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__savestatus__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* savevar(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__savevar__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* savingenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__savingenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* say(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__say__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* say2d(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__say2d__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* say3d(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__say3d__object_array__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* scopename(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__scopename__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* score(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__score__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* scoreside(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__scoreside__side__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* screenshot(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__screenshot__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* screentoworld(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__screentoworld__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* scriptdone(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__scriptdone__script__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* scriptname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__scriptname__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* scriptnull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__scriptnull__ret__script);
}

extern "C" __declspec(dllexport) intercept::types::game_value* scudstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__scudstate__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* secondaryweapon(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__secondaryweapon__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* secondaryweaponitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* secondaryweaponmagazine(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__secondaryweaponmagazine__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* select(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__select__string__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectbestplaces(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__selectbestplaces__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectdiarysubject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectdiarysubject__object__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectededitorobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__selectededitorobjects__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selecteditorobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selecteditorobject__control__string__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectionnames(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectionnames__object__string_scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectionposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectionposition__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectionvectordirandup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectionvectordirandup__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectleader(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectleader__group__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectmax(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__selectmax__array__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectmin(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__selectmin__array__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectnoplayer()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__selectnoplayer__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectplayer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__selectplayer__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectrandom(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__selectrandom__array__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectrandomweighted(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectrandomweighted__array__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectweapon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectweapon__object__array__ret__bool_nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* selectweaponturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__selectweaponturret__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sendaumessage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sendaumessage__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sendsimplecommand(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sendsimplecommand__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sendtask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sendtask__team_member__array__ret__task, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sendtaskresult(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sendtaskresult__task__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sendudpmessage(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sendudpmessage__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sentencesenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sentencesenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* servercommand(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__servercommand__string__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* servercommandavailable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__servercommandavailable__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* servercommandexecutable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__servercommandexecutable__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* servername()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__servername__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* servernamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__servernamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* servertime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__servertime__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__set__hashmap__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denattribute(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__set3denattribute__any__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denattributes(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3denattributes__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3dengrid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3dengrid__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3deniconsvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3deniconsvisible__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denlayer(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__set3denlayer__any__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denlinesvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3denlinesvisible__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denlogictype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__set3denlogictype__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denmissionattribute(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__set3denmissionattribute__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denmissionattributes(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3denmissionattributes__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denmodelsvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3denmodelsvisible__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denobjecttype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__set3denobjecttype__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* set3denselected(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__set3denselected__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setacctime(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setacctime__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setactualcollectivertd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setactualcollectivertd__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setairplanethrottle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setairplanethrottle__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setairportside(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setairportside__object_scalar__side__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setammo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setammo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setammocargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setammocargo__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setammoonpylon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setammoonpylon__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setanimspeedcoef(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setanimspeedcoef__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setaperture(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setaperture__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setaperturenew(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setaperturenew__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setarmorypoints(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setarmorypoints__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setattributes(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setattributes__text_string__array__ret__text, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setautonomous(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setautonomous__object__bool__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setbehaviour(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setbehaviour__object_group__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setbehaviourstrong(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setbehaviourstrong__object_group__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setbleedingremaining(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setbleedingremaining__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setbrakesrtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setbrakesrtd__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcamerainterest(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcamerainterest__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcamshakedefparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setcamshakedefparams__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcamshakeparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setcamshakeparams__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcamuseti(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcamuseti__bool__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcaptive(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcaptive__object__bool_scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcenterofmass(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcenterofmass__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcollisionlight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcollisionlight__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcombatbehaviour(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcombatbehaviour__group__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcombatmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcombatmode__team_member__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcompassoscillation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setcompassoscillation__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setconvoyseparation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setconvoyseparation__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcruisecontrol(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcruisecontrol__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcuratorcameraareaceiling(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcuratorcameraareaceiling__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcuratorcoef(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcuratorcoef__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcuratoreditingareatype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcuratoreditingareatype__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcuratorwaypointcost(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcuratorwaypointcost__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcurrentchannel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setcurrentchannel__scalar__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcurrenttask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcurrenttask__object__task__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcurrentwaypoint(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcurrentwaypoint__group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcustomaimcoef(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcustomaimcoef__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcustommissiondata(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setcustommissiondata__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcustomsoundcontroller(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setcustomsoundcontroller__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setcustomweightrtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setcustomweightrtd__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdamage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdamage__object__scalar_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdammage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdammage__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setdate__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdebriefingtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdebriefingtext__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdefaultcamera(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setdefaultcamera__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdestination(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdestination__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdetailmapblendpars(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setdetailmapblendpars__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdiaryrecordtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdiaryrecordtext__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdiarysubjectpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdiarysubjectpicture__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdir__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdirection(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdirection__location__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdrawicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdrawicon__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdriveonpath(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdriveonpath__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdropinterval(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdropinterval__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdynamicsimulationdistance(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistance__string__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setdynamicsimulationdistancecoef(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setdynamicsimulationdistancecoef__string__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* seteditormode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__seteditormode__control__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* seteditorobjectscope(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__seteditorobjectscope__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* seteffectcondition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__seteffectcondition__object_array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* seteffectivecommander(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__seteffectivecommander__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setenginerpmrtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setenginerpmrtd__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setface(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setface__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfaceanimation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfaceanimation__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfatigue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfatigue__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfeaturetype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfeaturetype__object__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setflaganimationphase(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setflaganimationphase__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setflagowner(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setflagowner__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setflagside(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setflagside__object__side__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setflagtexture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setflagtexture__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfog(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfog__scalar__scalar_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setforcegeneratorrtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setforcegeneratorrtd__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setformation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setformation__team_member__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setformationtask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setformationtask__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setformdir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setformdir__object_group__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfriend(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfriend__side__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfromeditor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfromeditor__team_member__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfsmvariable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfsmvariable__scalar__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfuel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfuel__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setfuelcargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setfuelcargo__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setgroupicon__group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupiconparams(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setgroupiconparams__group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupiconsselectable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsselectable__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupiconsvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setgroupiconsvisible__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupid(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setgroupid__object_group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupidglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setgroupidglobal__object_group__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgroupowner(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setgroupowner__group__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setgusts(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setgusts__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethidebehind(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sethidebehind__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sethit__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethitindex(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sethitindex__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethitpointdamage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sethitpointdamage__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethorizonparallaxcoef(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sethorizonparallaxcoef__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethudmovementlevels(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sethudmovementlevels__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sethumidity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sethumidity__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setidentity(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setidentity__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setimportance(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setimportance__location__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setinfopanel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setinfopanel__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setleader(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setleader__team_member__team_member__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightambient(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightambient__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightattenuation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightattenuation__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightbrightness(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightbrightness__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightcolor__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightconepars(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightconepars__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightdaylight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightdaylight__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightflaremaxdistance(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightflaremaxdistance__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightflaresize(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightflaresize__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightintensity(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightintensity__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightir__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightnings(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightnings__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightuseflare(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightuseflare__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlightvolumeshape(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setlightvolumeshape__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setlocalwindparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setlocalwindparams__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmagazineturretammo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmagazineturretammo__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkeralpha(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkeralpha__string__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkeralphalocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkeralphalocal__string__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerbrush(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrush__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerbrushlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerbrushlocal__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkercolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkercolor__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkercolorlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkercolorlocal__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerdir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerdir__string__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerdirlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerdirlocal__string__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerpolyline(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolyline__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerpolylinelocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerpolylinelocal__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerpos__string__object_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkerposlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkerposlocal__string__object_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkershadow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkershadow__string__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkershadowlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkershadowlocal__string__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkershape(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkershape__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkershapelocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkershapelocal__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkersize(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkersize__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkersizelocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkersizelocal__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkertext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkertext__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkertextlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkertextlocal__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkertype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkertype__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmarkertypelocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmarkertypelocal__string__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmass(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmass__object__scalar_array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmaxload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmaxload__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmimic(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmimic__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmissiletarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmissiletarget__object__object__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmissiletargetpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmissiletargetpos__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmouseposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setmouseposition__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmusiceffect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setmusiceffect__object_array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setmusiceventhandler(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setmusiceventhandler__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setname(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setname__location__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setnamesound(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setnamesound__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjectarguments(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjectarguments__control__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjectmaterial(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterial__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjectmaterialglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjectmaterialglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjectproxy(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjectproxy__control__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjectscale(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjectscale__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjecttexture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjecttexture__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjecttextureglobal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setobjecttextureglobal__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setobjectviewdistance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setobjectviewdistance__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setopticsmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setopticsmode__object__array_string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setovercast(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setovercast__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setowner(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setowner__object__scalar__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setoxygenremaining(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setoxygenremaining__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setparticlecircle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setparticlecircle__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setparticleclass(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setparticleclass__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setparticlefire(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setparticlefire__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setparticleparams(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setparticleparams__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setparticlerandom(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setparticlerandom__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpilotcameradirection(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpilotcameradirection__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpilotcamerarotation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpilotcamerarotation__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpilotcameratarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpilotcameratarget__object__object_array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpilotlight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpilotlight__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpipeffect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpipeffect__string__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpipviewdistance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setpipviewdistance__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpitch(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpitch__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setplatenumber(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setplatenumber__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setplayable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setplayable__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setplayerrespawntime(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setplayerrespawntime__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setplayervonvolume(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setplayervonvolume__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpos__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setposasl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setposasl__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setposasl2(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setposasl2__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setposaslw(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setposaslw__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setposatl(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setposatl__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setposition__location__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setposworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setposworld__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpylonloadout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpylonloadout__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setpylonspriority(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setpylonspriority__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setradiomsg(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setradiomsg__scalar__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrain(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrain__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrainbow(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrainbow__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrandomlip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrandomlip__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrank(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrank__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrectangular(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrectangular__location__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrepaircargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrepaircargo__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setrotorbrakertd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setrotorbrakertd__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setshadowdistance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setshadowdistance__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setshotparents(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setshotparents__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setside(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setside__location__side__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimpletaskalwaysvisible(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskalwaysvisible__task__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimpletaskcustomdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskcustomdata__task__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimpletaskdescription(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdescription__task__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimpletaskdestination(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsimpletaskdestination__task__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimpletasktarget(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktarget__task__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimpletasktype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsimpletasktype__task__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsimulweatherlayers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setsimulweatherlayers__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsize(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsize__location__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setskill(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setskill__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setslingload(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setslingload__object__object__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsoundeffect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsoundeffect__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setspeaker(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setspeaker__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setspeech(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setspeech__location__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setspeedmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setspeedmode__object_group__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setstamina(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setstamina__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setstaminascheme(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setstaminascheme__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setstatvalue(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setstatvalue__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsuppression(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setsuppression__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setsystemofunits(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setsystemofunits__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settargetage(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settargetage__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settaskmarkeroffset(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settaskmarkeroffset__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settaskresult(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settaskresult__task__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settaskstate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settaskstate__task__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setterraingrid(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setterraingrid__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setterrainheight(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setterrainheight__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settext__location__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settimemultiplier(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__settimemultiplier__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settiparameter(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__settiparameter__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settitleeffect(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settitleeffect__object_array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settowparent(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settowparent__object__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settrafficdensity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__settrafficdensity__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settrafficdistance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__settrafficdistance__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settrafficgap(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__settrafficgap__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settrafficspeed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__settrafficspeed__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggeractivation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggeractivation__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggerarea(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggerarea__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggerinterval(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggerinterval__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggerstatements(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggerstatements__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggertext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggertext__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggertimeout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggertimeout__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settriggertype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settriggertype__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setturretlimits(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setturretlimits__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setturretopticsmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setturretopticsmode__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* settype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__settype__location__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunconscious(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunconscious__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitability(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitability__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitcombatmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitcombatmode__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitfreefallheight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitfreefallheight__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitloadout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitloadout__object__config__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitpos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitpos__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitposweak(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitposweak__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitrank(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitrank__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunitrecoilcoefficient(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunitrecoilcoefficient__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunittrait(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunittrait__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setunloadincombat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setunloadincombat__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setuseractiontext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setuseractiontext__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setusermfdtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setusermfdtext__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setusermfdvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setusermfdvalue__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvariable(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvariable__location__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvectordir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvectordir__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvectordirandup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvectordirandup__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvectorup(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvectorup__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehicleammo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehicleammo__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehicleammodef(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehicleammodef__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclearmor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclearmor__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclecargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclecargo__object__object__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehicleid(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehicleid__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclelock(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclelock__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehicleposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehicleposition__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehicleradar(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehicleradar__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclereceiveremotetargets(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclereceiveremotetargets__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclereportownposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportownposition__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclereportremotetargets(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclereportremotetargets__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehicletipars(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehicletipars__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvehiclevarname(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvehiclevarname__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvelocity(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvelocity__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvelocitymodelspace(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvelocitymodelspace__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvelocitytransformation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvelocitytransformation__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setviewdistance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setviewdistance__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setvisibleiftreecollapsed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setvisibleiftreecollapsed__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwantedrpmrtd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwantedrpmrtd__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaves(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaves__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointbehaviour(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointbehaviour__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointcombatmode(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointcombatmode__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointcompletionradius(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointcompletionradius__array__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointdescription(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointdescription__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointforcebehaviour(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointforcebehaviour__array__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointformation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointformation__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointhouseposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointhouseposition__array__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointloiteraltitude(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiteraltitude__array__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointloiterradius(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointloiterradius__array__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointloitertype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointloitertype__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointname(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointname__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointposition__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointscript(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointscript__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointspeed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointspeed__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointstatements(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointstatements__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointtimeout(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointtimeout__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointtype(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointtype__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwaypointvisible(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwaypointvisible__array__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setweaponreloadingtime(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setweaponreloadingtime__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setweaponzeroing(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setweaponzeroing__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwind(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__setwind__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwinddir(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwinddir__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwindforce(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwindforce__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwindstr(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwindstr__scalar__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwingforcescalertd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwingforcescalertd__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* setwppos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__setwppos__array__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* show3dicons(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__show3dicons__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showchat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showchat__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showcinemaborder(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showcinemaborder__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showcommandingmenu(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showcommandingmenu__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showcompass(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showcompass__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showcuratorcompass(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showcuratorcompass__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showgps(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showgps__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showhud(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showhud__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showlegend(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__showlegend__control__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showmap(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showmap__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownartillerycomputer()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownartillerycomputer__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownchat()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownchat__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showncompass()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__showncompass__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showncuratorcompass()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__showncuratorcompass__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showneweditorobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__showneweditorobject__control__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showngps()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__showngps__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownhud()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownhud__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownmap()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownmap__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownpad()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownpad__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownradio()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownradio__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownscoretable()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownscoretable__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownsubtitles()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownsubtitles__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownuavfeed()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownuavfeed__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownwarrant()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownwarrant__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* shownwatch()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__shownwatch__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showpad(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showpad__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showradio(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showradio__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showscoretable(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showscoretable__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showsubtitles(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showsubtitles__bool__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showuavfeed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showuavfeed__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showwarrant(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showwarrant__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showwatch(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showwatch__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showwaypoint(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__showwaypoint__array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* showwaypoints(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__showwaypoints__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* side(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__side__location__ret__side, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sideambientlife()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sideambientlife__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sidechat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sidechat__object_array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sideempty()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sideempty__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sideenemy()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sideenemy__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sidefriendly()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sidefriendly__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sidelogic()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sidelogic__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sideradio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sideradio__object_array__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sideunknown()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sideunknown__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* simpletasks(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__simpletasks__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* simulationenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__simulationenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* simulclouddensity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__simulclouddensity__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* simulcloudocclusion(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__simulcloudocclusion__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* simulinclouds(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__simulinclouds__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* simulweathersync()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__simulweathersync__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* size(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__size__location__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sizeOf(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sizeof__string__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* skill(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__skill__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* skillfinal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__skillfinal__object__string__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* skiptime(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__skiptime__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sleep(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sleep__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sliderposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sliderposition__scalar__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sliderrange(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sliderrange__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* slidersetposition(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__slidersetposition__control__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* slidersetrange(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__slidersetrange__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* slidersetspeed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__slidersetspeed__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sliderspeed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__sliderspeed__scalar__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* slingloadassistantshown()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__slingloadassistantshown__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* soldiermagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__soldiermagazines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* someammo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__someammo__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sort(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__sort__array__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* soundvolume()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__soundvolume__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* spawn(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__spawn__any__code__ret__script, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* speaker(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__speaker__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* speechvolume()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__speechvolume__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* speed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__speed__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* speedmode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__speedmode__object_group__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* splitstring(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__splitstring__string__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* squadparams(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__squadparams__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* stance(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__stance__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* startloadingscreen(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__startloadingscreen__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* step(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__step__for__scalar__ret__for, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* stop(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__stop__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* stopenginertd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__stopenginertd__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* stopped(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__stopped__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* str(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__str__any__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* sunormoon()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__sunormoon__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* supportinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__supportinfo__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* suppressfor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__suppressfor__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* surfaceiswater(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__surfaceiswater__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* surfacenormal(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__surfacenormal__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* surfacetexture(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__surfacetexture__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* surfacetype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__surfacetype__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* swimindepth(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__swimindepth__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* switchableunits()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__switchableunits__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* switchaction(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__switchaction__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* switchcamera(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__switchcamera__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* switchgesture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__switchgesture__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* switchlight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__switchlight__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* switchmove(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__switchmove__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizedobjects(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__synchronizedobjects__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizedtriggers(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__synchronizedtriggers__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizedwaypoints(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__synchronizedwaypoints__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizeobjectsadd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsadd__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizeobjectsremove(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__synchronizeobjectsremove__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizetrigger(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__synchronizetrigger__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* synchronizewaypoint(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__synchronizewaypoint__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* systemchat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__systemchat__string__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* systemofunits()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__systemofunits__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* systemtime()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__systemtime__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* systemtimeutc()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__systemtimeutc__ret__array);
}


extern "C" __declspec(dllexport) intercept::types::game_value* targetknowledge(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__targetknowledge__object__object__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* targets(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__targets__group__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* targetsaggregate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__targetsaggregate__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* targetsquery(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__targetsquery__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskalwaysvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskalwaysvisible__task__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskchildren(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskchildren__task__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskcompleted(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskcompleted__task__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskcustomdata(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskcustomdata__task__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskdescription(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskdescription__task__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskdestination(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskdestination__task__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskhint(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskhint__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskmarkeroffset(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskmarkeroffset__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskname__task__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tasknull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__tasknull__ret__task);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskparent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskparent__task__ret__task, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskresult(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskresult__task__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* taskstate(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__taskstate__task__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tasktype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tasktype__task__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teammember(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__teammember__object__ret__team_member, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teammembernull()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__teammembernull__ret__team_member);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teamname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__teamname__team_member__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teams()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__teams__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teamswitch()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__teamswitch__ret__nothing);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teamswitchenabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__teamswitchenabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* teamtype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__teamtype__team_member__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* terrainintersect(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__terrainintersect__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* terrainintersectasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__terrainintersectasl__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* terrainintersectatasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__terrainintersectatasl__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* text(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__text__location__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* textlog(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__textlog__any__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* textlogformat(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__textlogformat__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tg(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tg__scalar_nan__ret__scalar_nan, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* then(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__then__if__array__ret__any, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* Time()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__time__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* timemultiplier()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__timemultiplier__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* titlecut(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__titlecut__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* titlefadeout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__titlefadeout__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* titleobj(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__titleobj__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* titlersc(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__titlersc__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* titletext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__titletext__array__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* to(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__to__for__scalar__ret__for, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* toarray(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__toarray__hashmap__bool__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tofixed(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tofixed__scalar__scalar__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* toloweransi(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__toloweransi__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tostring(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tostring__code__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* toupperansi(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__toupperansi__string__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggeractivated(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggeractivated__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggeractivation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggeractivation__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerammo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggerammo__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerarea(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggerarea__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerattachedvehicle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggerattachedvehicle__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerattachobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__triggerattachobject__object__scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerattachvehicle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__triggerattachvehicle__object__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerdynamicsimulation(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__triggerdynamicsimulation__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerinterval(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggerinterval__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggerstatements(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggerstatements__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggertext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggertext__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggertimeout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggertimeout__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggertimeoutcurrent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggertimeoutcurrent__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* triggertype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__triggertype__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* trim(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__trim__string__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* turretlocal(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__turretlocal__object__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* turretowner(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__turretowner__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* turretunit(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__turretunit__object__array__ret__object, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvadd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvadd__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvclear(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tvclear__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvcollapse(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvcollapse__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvcollapseall(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tvcollapseall__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvcount(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvcount__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvcursel(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tvcursel__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvdata__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvdelete(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvdelete__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvexpand(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvexpand__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvexpandall(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tvexpandall__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvisselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvisselected__control__array__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvpicture__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvpictureright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvpictureright__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvselection(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__tvselection__control__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetcursel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetcursel__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetdata(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetdata__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicture(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicture__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicturecolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicturecolordisabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolordisabled__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicturecolorselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturecolorselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpictureright(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpictureright__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicturerightcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicturerightcolordisabled(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolordisabled__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetpicturerightcolorselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetpicturerightcolorselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetselectcolor(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetselectcolor__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetselected(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetselected__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsettext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsettext__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsettooltip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsettooltip__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsetvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsetvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsort(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsort__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsortall(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsortall__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsortbyvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalue__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvsortbyvalueall(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvsortbyvalueall__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvtext(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvtext__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvtooltip(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvtooltip__control__array__ret__string, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* tvvalue(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__tvvalue__control__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* type(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__type__location__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* typeName(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__typename__any__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* typeof(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__typeof__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uavcontrol(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uavcontrol__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uinamespace()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__uinamespace__ret__namespace);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uisleep(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uisleep__scalar__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unassigncurator(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unassigncurator__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unassignitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__unassignitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unassignteam(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unassignteam__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unassignvehicle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unassignvehicle__object__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* underwater(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__underwater__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uniform(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uniform__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uniformcontainer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uniformcontainer__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uniformitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uniformitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uniformmagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uniformmagazines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* uniqueunititems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__uniqueunititems__object_array__ret__hashmap, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitaddons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitaddons__string__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitaimposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitaimposition__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitaimpositionvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitaimpositionvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitbackpack(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitbackpack__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitcombatmode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitcombatmode__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitisuav(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitisuav__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitpos(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitpos__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitready(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitready__object_array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitrecoilcoefficient(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unitrecoilcoefficient__object__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* units(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__units__side__ret__any, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitsbelowheight(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__unitsbelowheight__array__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unitturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__unitturret__object__object__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unlinkitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__unlinkitem__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unlockachievement(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__unlockachievement__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* unregistertask(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__unregistertask__team_member__string__ret__bool, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* updatedrawicon(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__updatedrawicon__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* updatemenuitem(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__updatemenuitem__control__array__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* updateobjecttree(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__updateobjecttree__control__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* useaiopermapobstructiontest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__useaiopermapobstructiontest__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* useaisteeringcomponent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__useaisteeringcomponent__bool__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* useaudiotimeformoves(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__useaudiotimeformoves__object__bool__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* userinputdisabled()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__userinputdisabled__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* values(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__values__hashmap__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectoradd(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectoradd__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorcos(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectorcos__array__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorcrossproduct(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectorcrossproduct__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectordiff(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectordiff__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectordir(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectordir__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectordirvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectordirvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectordistance(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectordistance__array__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectordistancesqr(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectordistancesqr__array__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectordotproduct(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectordotproduct__array__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorfromto(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectorfromto__array__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorlinearconversion(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectorlinearconversion__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectormagnitude(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectormagnitude__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectormagnitudesqr(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectormagnitudesqr__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectormodeltoworld(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworld__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectormodeltoworldvisual(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectormodeltoworldvisual__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectormultiply(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectormultiply__array__scalar__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectornormalized(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectornormalized__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorup(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectorup__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorupvisual(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vectorupvisual__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorworldtomodel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodel__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vectorworldtomodelvisual(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vectorworldtomodelvisual__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehicle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehicle__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclecargoenabled(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehiclecargoenabled__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclechat(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vehiclechat__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclemoveinfo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehiclemoveinfo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehicleradio(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__vehicleradio__object__string__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclereceiveremotetargets(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehiclereceiveremotetargets__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclereportownposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehiclereportownposition__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclereportremotetargets(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehiclereportremotetargets__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehicles()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__vehicles__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vehiclevarname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vehiclevarname__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* velocity(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__velocity__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* velocitymodelspace(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__velocitymodelspace__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* verifysignature(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__verifysignature__string__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vest(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vest__object__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vestcontainer(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vestcontainer__object__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vestitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vestitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* vestmagazines(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__vestmagazines__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* viewdistance()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__viewdistance__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visiblecompass()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__visiblecompass__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visiblegps()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__visiblegps__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visiblemap()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__visiblemap__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visibleposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__visibleposition__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visiblepositionasl(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__visiblepositionasl__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visiblescoretable()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__visiblescoretable__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* visiblewatch()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__visiblewatch__ret__bool);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waituntil(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waituntil__code__ret__nothing, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waves()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__waves__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointattachedobject(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointattachedobject__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointattachedvehicle(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointattachedvehicle__array__ret__object, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointattachobject(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__waypointattachobject__array__object_scalar__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointattachvehicle(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__waypointattachvehicle__array__object__ret__nothing, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointbehaviour(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointbehaviour__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointcombatmode(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointcombatmode__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointcompletionradius(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointcompletionradius__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointdescription(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointdescription__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointforcebehaviour(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointforcebehaviour__array__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointformation(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointformation__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointhouseposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointhouseposition__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointloiteraltitude(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointloiteraltitude__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointloiterradius(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointloiterradius__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointloitertype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointloitertype__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointname(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointname__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointposition(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointposition__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypoints(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypoints__object_group__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointscript(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointscript__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointsenableduav(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointsenableduav__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointshow(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointshow__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointspeed(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointspeed__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointstatements(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointstatements__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointtimeout(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointtimeout__array__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointtimeoutcurrent(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointtimeoutcurrent__group__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointtype(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointtype__array__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* waypointvisible(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__waypointvisible__array__ret__scalar, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponaccessories(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weaponaccessories__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponaccessoriescargo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weaponaccessoriescargo__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponcargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weaponcargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weapondirection(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weapondirection__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponinertia(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weaponinertia__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponlowered(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weaponlowered__object__ret__bool, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponreloadingtime(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weaponreloadingtime__object__array__ret__scalar, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weapons(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weapons__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponsinfo(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weaponsinfo__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponsitems(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weaponsitems__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponsitemscargo(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weaponsitemscargo__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponstate(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weaponstate__object__string__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weaponsturret(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__weaponsturret__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* weightrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__weightrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* west()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__west__ret__side);
}

extern "C" __declspec(dllexport) intercept::types::game_value* wfsidetext(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__wfsidetext__group__ret__string, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* wind()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__wind__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* winddir()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__winddir__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* windrtd()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__windrtd__ret__array);
}

extern "C" __declspec(dllexport) intercept::types::game_value* windstr()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__windstr__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* wingsforcesrtd(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__wingsforcesrtd__object__ret__array, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* with(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__with__namespace__ret__with, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* worldname()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__worldname__ret__string);
}

extern "C" __declspec(dllexport) intercept::types::game_value* worldsize()
{
	return &host::functions.invoke_raw_nular(__sqf::nular__worldsize__ret__scalar);
}

extern "C" __declspec(dllexport) intercept::types::game_value* worldtomodel(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__worldtomodel__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* worldtomodelvisual(intercept::types::game_value * left_arg, intercept::types::game_value*  right_arg)
{
	return &host::functions.invoke_raw_binary(__sqf::binary__worldtomodelvisual__object__array__ret__array, *left_arg, *right_arg);
}

extern "C" __declspec(dllexport) intercept::types::game_value* worldtoscreen(intercept::types::game_value * right_arg)
{
	return &host::functions.invoke_raw_unary(__sqf::unary__worldtoscreen__array__ret__array, *right_arg);
}

