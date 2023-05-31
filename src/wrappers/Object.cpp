
#include "headers/Object.hpp"
#include <string>
#include <vector>


namespace RV::Bindings
{
	Object::Object(const char* type, vector3 position)
	{
		_internalObject = intercept::sqf::create_vehicle({ type }, position);
	}

	//Object::Object(const char* type, vector3 position, const char** markers, int length, float placement,const char* special)
	//{
	//	std::vector<std::string> markerArray{};
	//	// convert to vector<std::string>
	//	if (markers != nullptr)
	//	{
	//		markerArray = std::vector<std::string>{markers, markers + length};
	//	}
	//	_internalObject = intercept::sqf::create_vehicle({ type }, position, markerArray, placement, {special});
	//}

	vector3 Object::get_pos()
	{
		return intercept::sqf::get_pos(_internalObject);
	}

	vector3 Object::get_pos_asl()
	{
		return intercept::sqf::get_pos_asl(_internalObject);
	}

	vector3 Object::get_pos_aslw()
	{
		return intercept::sqf::get_pos_aslw(_internalObject);
	}

	vector3 Object::get_pos_atl()
	{
		return intercept::sqf::get_pos_atl(_internalObject);
	}

	vector3 Object::get_pos_world()
	{
		return intercept::sqf::get_pos_world(_internalObject);
	}

	vector3 Object::get_rel_pos(float distance, float direction)
	{
		return intercept::sqf::get_rel_pos(_internalObject, distance, direction);
	}

	vector3 Object::model_to_world(const vector3 position)
	{
		return intercept::sqf::model_to_world(_internalObject, position);

	}

	vector3 Object::model_to_world_world(const vector3 modelPos)
	{
		return intercept::sqf::model_to_world_world(_internalObject, modelPos);
	}

	void Object::set_pos(const vector3 position)
	{
		intercept::sqf::set_pos(_internalObject, position);
	}

	void Object::set_pos_asl(const vector3 position)
	{
		intercept::sqf::set_pos_asl(_internalObject, position);
	}

	void Object::set_pos_aslw(const vector3 position)
	{
		intercept::sqf::set_pos_aslw(_internalObject, position);
	}
	void Object::set_pos_atl(const vector3 position)
	{
		intercept::sqf::set_pos_atl(_internalObject, position);
	}
	void Object::set_pos_world(const vector3 position)
	{
		intercept::sqf::set_pos_world(_internalObject, position);
	}

	vector3 Object::world_to_model(const vector3 position)
	{
		return intercept::sqf::world_to_model(_internalObject, position);
	}

	vector3 Object::world_to_model_visual(const vector3 position)
	{
		return intercept::sqf::world_to_model_visual(_internalObject, position);
	}

	const char_t* Object::type_of()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::type_of(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}

	bool Object::is_kind_of(const char* typeName)
	{
		return intercept::sqf::is_kind_of(_internalObject, { typeName });
	}

	vector3  Object::vectorUp()
	{
		return intercept::sqf::vector_up(_internalObject);
	}

	/*ARRAY  Object::animationNames()
	{
		return intercept::sqf::animation_names(_internalObject);
	}
	*/

	float  Object::currentZeroing()
	{
		return intercept::sqf::current_zeroing(_internalObject);
	}

	/*ARRAY  Object::triggerArea()
	{
		return intercept::sqf::trigger_area(_internalObject);
	}
	*/

	bool  Object::isAutoHoverOn()
	{
		return intercept::sqf::is_auto_hover_on(_internalObject);
	}

	/*ARRAY  Object::getAllHitPointsDamage()
	{
		return intercept::sqf::get_all_hit_points_damage(_internalObject);
	}
	*/

	float  Object::getObjectScale()
	{
		return intercept::sqf::get_object_scale(_internalObject);
	}

	const char_t* Object::triggerText()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::trigger_text(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}

	float  Object::getFatigue()
	{
		return intercept::sqf::get_fatigue(_internalObject);
	}

	/*ARRAY  Object::eyeDirection()
	{
		return intercept::sqf::eye_direction(_internalObject);
	}
	*/

	void  Object::fillWeaponsFromPool()
	{
		intercept::sqf::fill_weapons_from_pool(_internalObject);
	}

	/*ARRAY  Object::hcSelected()
	{
		return intercept::sqf::hc_selected(_internalObject);
	}
	*/

	bool  Object::isObjectRTD()
	{
		return intercept::sqf::is_object_rtd(_internalObject);
	}

	const char_t* Object::roleDescription()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::role_description(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}

	/*ARRAY  Object::simpleTasks()
	{
		return intercept::sqf::simple_tasks(_internalObject);
	}
	*/

	float  Object::getAmmoCargo()
	{
		return intercept::sqf::get_ammo_cargo(_internalObject);
	}

	RV::Bindings::Object* Object::flagOwner()
	{
		return new RV::Bindings::Object(intercept::sqf::flag_owner(_internalObject));
	}

	float  Object::speed()
	{
		return intercept::sqf::speed(_internalObject);
	}

	bool  Object::reloadEnabled()
	{
		return intercept::sqf::reload_enabled(_internalObject);
	}
	float  Object::rating()
	{
		return intercept::sqf::rating(_internalObject);
	}
	void  Object::hideObject()
	{
		intercept::sqf::hide_object(_internalObject);
	}
	const char_t* Object::primaryWeapon()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::primary_weapon(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::curatorCameraAreaCeiling()
	{
		return intercept::sqf::curator_camera_area_ceiling(_internalObject);
	}
	void  Object::removeVest()
	{
		intercept::sqf::remove_vest(_internalObject);
	}
	/*ARRAY  Object::formationPosition()
	{
		return intercept::sqf::formation_position(_internalObject);
	}
	*/
	bool  Object::moveToFailed()
	{
		return intercept::sqf::move_to_failed(_internalObject);
	}
	float  Object::rankId()
	{
		return intercept::sqf::rank_id(_internalObject);
	}
	void  Object::removeAllItemsWithMagazines()
	{
		intercept::sqf::remove_all_items_with_magazines(_internalObject);
	}
	/*ARRAY  Object::getAllEnv3DSoundControllers()
	{
		return intercept::sqf::get_all_env_3d_sound_controllers(_internalObject);
	}
	*/
	float  Object::getPlayerVoNVolume()
	{
		return intercept::sqf::get_player_von_volume(_internalObject);
	}
	void  Object::removeBackpackGlobal()
	{
		intercept::sqf::remove_backpack_global(_internalObject);
	}
	const char_t* Object::face()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::face(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	RV::Bindings::Object* Object::getAttackTarget()
	{

		return new RV::Bindings::Object(intercept::sqf::get_attack_target(_internalObject));
	}
	/*ARRAY  Object::getVehicleCargo()
	{
		return intercept::sqf::get_vehicle_cargo(_internalObject);
	}
	*/
	/*ARRAY  Object::getPosATL()
	{
		return intercept::sqf::get_pos_atl(_internalObject);
	}
	*/
	/*ARRAY  Object::objectCurators()
	{
		return intercept::sqf::object_curators(_internalObject);
	}
	*/
	/*ARRAY  Object::curatorEditingArea()
	{
		return intercept::sqf::curator_editing_area(_internalObject);
	}
	*/
	const char_t* Object::assignedTeam()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::assigned_team(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::vectorDirVisual()
	{
		return intercept::sqf::vector_dir_visual(_internalObject);
	}
	*/
	bool  Object::triggerActivated()
	{
		return intercept::sqf::trigger_activated(_internalObject);
	}
	void  Object::unassignVehicle()
	{
		intercept::sqf::unassign_vehicle(_internalObject);
	}
	/*ARRAY  Object::boundingBox()
	{
		return intercept::sqf::bounding_box(_internalObject);
	}
	*/
	float  Object::moveTime()
	{
		return intercept::sqf::move_time(_internalObject);
	}
	float  Object::getCustomSoundControllerCount()
	{
		return intercept::sqf::get_custom_sound_controller_count(_internalObject);
	}
	/*ARRAY  Object::getSensorTargets()
	{
		return intercept::sqf::get_sensor_targets(_internalObject);
	}
	*/
	const char_t* Object::animationState()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::animation_state(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::weaponCargo()
	{
		return intercept::sqf::weapon_cargo(_internalObject);
	}
	*/
	bool  Object::isTurnedOut()
	{
		return intercept::sqf::is_turned_out(_internalObject);
	}
	void  Object::removeAllSecondaryWeaponItems()
	{
		intercept::sqf::remove_all_secondary_weapon_items(_internalObject);
	}
	RV::Bindings::Object* Object::camTarget()
	{
		return new RV::Bindings::Object(intercept::sqf::cam_target(_internalObject));
	}
	bool  Object::isSimpleObject()
	{
		return intercept::sqf::is_simple_object(_internalObject);
	}
	/*ARRAY  Object::getCameraViewDirection()
	{
		return intercept::sqf::get_camera_view_direction(_internalObject);
	}
	*/
	float  Object::scudState()
	{
		return intercept::sqf::scud_state(_internalObject);
	}
	bool  Object::isAutoTrimOnRTD()
	{
		return intercept::sqf::is_auto_trim_on_rtd(_internalObject);
	}
	/*ARRAY  Object::boundingBoxReal()
	{
		return intercept::sqf::bounding_box_real(_internalObject);
	}
	*/
	void  Object::ropeDestroy()
	{
		intercept::sqf::rope_destroy(_internalObject);
	}
	bool  Object::isTouchingGround()
	{
		return intercept::sqf::is_touching_ground(_internalObject);
	}
	/*ARRAY  Object::taskMarkerOffset()
	{
		return intercept::sqf::task_marker_offset(_internalObject);
	}
	*/
	const char_t* Object::vest()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::vest(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	const char_t* Object::headgear()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::headgear(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::fuel()
	{
		return intercept::sqf::fuel(_internalObject);
	}
	/*ARRAY  Object::weaponsItemsCargo()
	{
		return intercept::sqf::weapons_items_cargo(_internalObject);
	}
	*/
	float  Object::getForcedSpeed()
	{
		return intercept::sqf::get_forced_speed(_internalObject);
	}
	float  Object::damage()
	{
		return intercept::sqf::damage(_internalObject);
	}
	/*ARRAY  Object::getModelInfo()
	{
		return intercept::sqf::get_model_info(_internalObject);
	}
	*/
	float  Object::getBleedingRemaining()
	{
		return intercept::sqf::get_bleeding_remaining(_internalObject);
	}
	/*ARRAY  Object::squadParams()
	{
		return intercept::sqf::squad_params(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::leader()
	{
		return new RV::Bindings::Object(intercept::sqf::leader(_internalObject));
	}
	/*ARRAY  Object::currentThrowable()
	{
		return intercept::sqf::current_throwable(_internalObject);
	}
	*/
	/*ARRAY  Object::uniformItems()
	{
		return intercept::sqf::uniform_items(_internalObject);
	}
	*/
	float  Object::getCustomAimCoef()
	{
		return intercept::sqf::get_custom_aim_coef(_internalObject);
	}
	float  Object::unitRecoilCoefficient()
	{
		return intercept::sqf::unit_recoil_coefficient(_internalObject);
	}
	void  Object::unassignCurator()
	{
		intercept::sqf::unassign_curator(_internalObject);
	}
	RV::Bindings::Object* Object::objectParent()
	{
		return new RV::Bindings::Object(intercept::sqf::object_parent(_internalObject));
	}
	void  Object::clearMagazineCargo()
	{
		intercept::sqf::clear_magazine_cargo(_internalObject);
	}
	bool  Object::canMove()
	{
		return intercept::sqf::can_move(_internalObject);
	}
	float  Object::getWingsOrientationRTD()
	{
		return intercept::sqf::get_wings_orientation_rtd(_internalObject);
	}
	bool  Object::isStaminaEnabled()
	{
		return intercept::sqf::is_stamina_enabled(_internalObject);
	}
	/*ARRAY  Object::getUserMFDText()
	{
		return intercept::sqf::get_user_mfd_text(_internalObject);
	}
	*/
	/*ARRAY  Object::weaponsItems()
	{
		return intercept::sqf::weapons_items(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::unitBackpack()
	{
		return new RV::Bindings::Object(intercept::sqf::unit_backpack(_internalObject));
	}
	void  Object::pickWeaponPool()
	{
		intercept::sqf::pick_weapon_pool(_internalObject);
	}
	RV::Bindings::Object* Object::getSlingLoad()
	{
		return new RV::Bindings::Object(intercept::sqf::get_sling_load(_internalObject));
	}
	/*ARRAY  Object::getAllPylonsInfo()
	{
		return intercept::sqf::get_all_pylons_info(_internalObject);
	}
	*/
	void  Object::reload()
	{
		intercept::sqf::reload(_internalObject);
	}
	/*ARRAY  Object::allVariables()
	{
		return intercept::sqf::all_variables(_internalObject);
	}
	*/
	const char_t* Object::speaker()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::speaker(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;

	}
	/*ARRAY  Object::weapons()
	{
		return intercept::sqf::weapons(_internalObject);
	}
	*/
	bool  Object::unitIsUAV()
	{
		return intercept::sqf::unit_is_uav(_internalObject);
	}
	RV::Bindings::Object* Object::assignedTarget()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::assigned_target(_internalObject));
	}
	RV::Bindings::Object* Object::attachedTo()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::attached_to(_internalObject));
	}
	RV::Bindings::Object* Object::effectiveCommander()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::effective_commander(_internalObject));
	}
	/*CONFIG  Object::configOf()
	{
		return intercept::sqf::config_of(_internalObject);
	}
	*/
	const char_t* Object::landResult()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::land_result(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::clearWeaponCargoGlobal()
	{
		intercept::sqf::clear_weapon_cargo_global(_internalObject);
	}
	RV::Bindings::Object* Object::assignedDriver()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::assigned_driver(_internalObject));
	}
	/*ARRAY  Object::getCruiseControl()
	{
		return intercept::sqf::get_cruise_control(_internalObject);
	}
	*/
	/*ARRAY  Object::secondaryWeaponMagazine()
	{
		return intercept::sqf::secondary_weapon_magazine(_internalObject);
	}
	*/
	float  Object::flagAnimationPhase()
	{
		return intercept::sqf::flag_animation_phase(_internalObject);
	}
	/*GROUP  Object::assignedGroup()
	{
		return intercept::sqf::assigned_group(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::getTowParent()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::get_tow_parent(_internalObject));
	}
	float  Object::getDir()
	{
		return intercept::sqf::get_dir(_internalObject);
	}
	RV::Bindings::Object* Object::uniformContainer()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::uniform_container(_internalObject));
	}
	bool  Object::isPlayer()
	{
		return intercept::sqf::is_player(_internalObject);
	}
	bool  Object::camPreloaded()
	{
		return intercept::sqf::cam_preloaded(_internalObject);
	}
	bool  Object::local()
	{
		return intercept::sqf::local(_internalObject);
	}
	/*ARRAY  Object::getVehicleTiPars()
	{
		return intercept::sqf::get_vehicle_ti_pars(_internalObject);
	}
	*/
	/*ARRAY  Object::boundingCenter()
	{
		return intercept::sqf::bounding_center(_internalObject);
	}
	*/
	bool  Object::fleeing()
	{
		return intercept::sqf::fleeing(_internalObject);
	}
	bool  Object::isCopilotEnabled()
	{
		return intercept::sqf::is_copilot_enabled(_internalObject);
	}
	float  Object::maxLoad()
	{
		return intercept::sqf::max_load(_internalObject);
	}
	const char_t* Object::uniform()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::uniform(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	const char_t* Object::WFSideText()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::wf_side_text(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::velocityModelSpace()
	{
		return intercept::sqf::velocity_model_space(_internalObject);
	}
	*/
	/*ARRAY  Object::getAllOwnedMines()
	{
		return intercept::sqf::get_all_owned_mines(_internalObject);
	}
	*/
	const char_t* Object::flagTexture()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::flag_texture(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::getFuelCargo()
	{
		return intercept::sqf::get_fuel_cargo(_internalObject);
	}
	float  Object::groupID()
	{
		return intercept::sqf::group_id(_internalObject);
	}
	/*ARRAY  Object::rotorsRpmRTD()
	{
		return intercept::sqf::rotors_rpm_rtd(_internalObject);
	}
	*/
	float  Object::captiveNum()
	{
		return intercept::sqf::captive_num(_internalObject);
	}
	/*ARRAY  Object::selectionNames()
	{
		return intercept::sqf::selection_names(_internalObject);
	}
	*/
	/*ARRAY  Object::position()
	{
		return intercept::sqf::position(_internalObject);
	}
	*/
	bool  Object::canUnloadInCombat()
	{
		return intercept::sqf::can_unload_in_combat(_internalObject);
	}
	/*ARRAY  Object::attachedObjects()
	{
		return intercept::sqf::attached_objects(_internalObject);
	}
	*/
	const char_t* Object::netId()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::net_id(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::removeAllAssignedItems()
	{
		intercept::sqf::remove_all_assigned_items(_internalObject);
	}
	bool  Object::ropeUnwound()
	{
		return intercept::sqf::rope_unwound(_internalObject);
	}
	void  Object::addSwitchableUnit()
	{
		intercept::sqf::add_switchable_unit(_internalObject);
	}
	float  Object::owner()
	{
		return intercept::sqf::owner(_internalObject);
	}
	RV::Bindings::Object* Object::driver()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::driver(_internalObject));
	}
	/*ARRAY  Object::primaryWeaponMagazine()
	{
		return intercept::sqf::primary_weapon_magazine(_internalObject);
	}
	*/
	/*ARRAY  Object::curatorEditableObjects()
	{
		return intercept::sqf::curator_editable_objects(_internalObject);
	}
	*/
	/*ARRAY  Object::assignedItems()
	{
		return intercept::sqf::assigned_items(_internalObject);
	}
	*/
	/*ARRAY  Object::groupSelectedUnits()
	{
		return intercept::sqf::group_selected_units(_internalObject);
	}
	*/
	float  Object::loadUniform()
	{
		return intercept::sqf::load_uniform(_internalObject);
	}
	bool  Object::isLaserOn()
	{
		return intercept::sqf::is_laser_on(_internalObject);
	}
	bool  Object::someAmmo()
	{
		return intercept::sqf::some_ammo(_internalObject);
	}
	bool  Object::isWeaponRested()
	{
		return intercept::sqf::is_weapon_rested(_internalObject);
	}
	bool  Object::isAimPrecisionEnabled()
	{
		return intercept::sqf::is_aim_precision_enabled(_internalObject);
	}
	RV::Bindings::Object* Object::commander()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::commander(_internalObject));
	}
	const char_t* Object::incapacitatedState()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::incapacitated_state(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::collectiveRTD()
	{
		return intercept::sqf::collective_rtd(_internalObject);
	}
	float  Object::insideBuilding()
	{
		return intercept::sqf::inside_building(_internalObject);
	}
	/*ARRAY  Object::getPylonMagazines()
	{
		return intercept::sqf::get_pylon_magazines(_internalObject);
	}
	*/
	float  Object::getAnimAimPrecision()
	{
		return intercept::sqf::get_anim_aim_precision(_internalObject);
	}
	bool  Object::canTriggerDynamicSimulation()
	{
		return intercept::sqf::can_trigger_dynamic_simulation(_internalObject);
	}
	/*ARRAY  Object::vehicleMoveInfo()
	{
		return intercept::sqf::vehicle_move_info(_internalObject);
	}
	*/
	/*ARRAY  Object::backpackMagazines()
	{
		return intercept::sqf::backpack_magazines(_internalObject);
	}
	*/
	bool  Object::weaponLowered()
	{
		return intercept::sqf::weapon_lowered(_internalObject);
	}
	float  Object::handsHit()
	{
		return intercept::sqf::hands_hit(_internalObject);
	}
	void  Object::removeAllCuratorCameraAreas()
	{
		intercept::sqf::remove_all_curator_camera_areas(_internalObject);
	}
	const char_t* Object::triggerType()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::trigger_type(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::hideBody()
	{
		intercept::sqf::hide_body(_internalObject);
	}
	/*ARRAY  Object::getPilotCameraTarget()
	{
		return intercept::sqf::get_pilot_camera_target(_internalObject);
	}
	*/
	void  Object::triggerAmmo()
	{
		intercept::sqf::trigger_ammo(_internalObject);
	}
	RV::Bindings::Object* Object::missileTarget()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::missile_target(_internalObject));
	}
	const char_t* Object::behaviour()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::trigger_type(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::getMagazineCargo()
	{
		return intercept::sqf::get_magazine_cargo(_internalObject);
	}
	*/
	const char_t* Object::lifeState()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::life_state(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::isSprintAllowed()
	{
		return intercept::sqf::is_sprint_allowed(_internalObject);
	}
	float  Object::triggerInterval()
	{
		return intercept::sqf::trigger_interval(_internalObject);
	}
	/*ARRAY  Object::triggerTimeout()
	{
		return intercept::sqf::trigger_timeout(_internalObject);
	}
	*/
	/*ARRAY  Object::units()
	{
		return intercept::sqf::units(_internalObject);
	}
	*/
	void  Object::removeAllContainers()
	{
		intercept::sqf::remove_all_containers(_internalObject);
	}
	float  Object::getObjectType()
	{
		return intercept::sqf::get_object_type(_internalObject);
	}
	/*ARRAY  Object::getTurretOpticsMode()
	{
		return intercept::sqf::get_turret_optics_mode(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::ropeAttachedTo()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::rope_attached_to(_internalObject));
	}
	bool  Object::moveToCompleted()
	{
		return intercept::sqf::move_to_completed(_internalObject);
	}
	bool  Object::canStand()
	{
		return intercept::sqf::can_stand(_internalObject);
	}
	/*ARRAY  Object::rotorsForcesRTD()
	{
		return intercept::sqf::rotors_forces_rtd(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::formationLeader()
	{
		return new RV::Bindings::Object(intercept::sqf::formation_leader(_internalObject));
	}
	const char_t* Object::getPlateNumber()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::get_plate_number(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::enginesTorqueRTD()
	{
		return intercept::sqf::engines_torque_rtd(_internalObject);
	}
	*/
	bool  Object::isEngineOn()
	{
		return intercept::sqf::is_engine_on(_internalObject);
	}
	/*ARRAY  Object::needService()
	{
		return intercept::sqf::need_service(_internalObject);
	}
	*/
	const char_t* Object::getForcedFlagTexture()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::get_forced_flag_texture(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::getPlayerScores()
	{
		return intercept::sqf::get_player_scores(_internalObject);
	}
	*/
	float  Object::skill()
	{
		return intercept::sqf::skill(_internalObject);
	}
	/*ARRAY  Object::magazineCargo()
	{
		return intercept::sqf::magazine_cargo(_internalObject);
	}
	*/
	const char_t* Object::backpack()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::backpack(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::hcRemoveAllGroups()
	{
		intercept::sqf::hc_remove_all_groups(_internalObject);
	}
	/*ARRAY  Object::getPosWorld()
	{
		return intercept::sqf::get_pos_world(_internalObject);
	}
	*/
	float  Object::getStamina()
	{
		return intercept::sqf::get_stamina(_internalObject);
	}
	float  Object::getMass()
	{
		return intercept::sqf::get_mass(_internalObject);
	}
	/*ARRAY  Object::weaponState()
	{
		return intercept::sqf::weapon_state(_internalObject);
	}
	*/
	float  Object::load()
	{
		return intercept::sqf::load(_internalObject);
	}
	float  Object::loadAbs()
	{
		return intercept::sqf::load_abs(_internalObject);
	}
	void  Object::removeSwitchableUnit()
	{
		intercept::sqf::remove_switchable_unit(_internalObject);
	}
	bool  Object::simulationEnabled()
	{
		return intercept::sqf::simulation_enabled(_internalObject);
	}
	/*ARRAY  Object::currentMagazineDetail()
	{
		return intercept::sqf::current_magazine_detail(_internalObject);
	}
	*/
	/*ARRAY  Object::unitAimPositionVisual()
	{
		return intercept::sqf::unit_aim_position_visual(_internalObject);
	}
	*/
	/*ARRAY  Object::actionIDs()
	{
		return intercept::sqf::action_ids(_internalObject);
	}
	*/
	/*ARRAY  Object::everyBackpack()
	{
		return intercept::sqf::every_backpack(_internalObject);
	}
	*/
	bool  Object::vehicleReceiveRemoteTargets()
	{
		return intercept::sqf::vehicle_receive_remote_targets(_internalObject);
	}
	/*ARRAY  Object::listVehicleSensors()
	{
		return intercept::sqf::list_vehicle_sensors(_internalObject);
	}
	*/
	const char_t* Object::currentMuzzle()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::current_muzzle(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	const char_t* Object::currentWeaponMode()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::current_weapon_mode(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::getWingsPositionRTD()
	{
		return intercept::sqf::get_wings_position_rtd(_internalObject);
	}
	const char_t* Object::name()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::name(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::ropesAttachedTo()
	{
		return intercept::sqf::ropes_attached_to(_internalObject);
	}
	*/
	bool  Object::captive()
	{
		return intercept::sqf::captive(_internalObject);
	}
	bool  Object::isWeaponDeployed()
	{
		return intercept::sqf::is_weapon_deployed(_internalObject);
	}
	void  Object::removeAllWeapons()
	{
		intercept::sqf::remove_all_weapons(_internalObject);
	}
	const char_t* Object::vehicleVarName()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::vehicle_var_name(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::triggerTimeoutCurrent()
	{
		return intercept::sqf::trigger_timeout_current(_internalObject);
	}
	RV::Bindings::Object* Object::assignedGunner()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::assigned_gunner(_internalObject));
	}
	/*ARRAY  Object::soldierMagazines()
	{
		return intercept::sqf::soldier_magazines(_internalObject);
	}
	*/
	/*ARRAY  Object::getUnitFreefallInfo()
	{
		return intercept::sqf::get_unit_freefall_info(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::getCorpse()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::get_corpse(_internalObject));
	}
	void  Object::removeUniform()
	{
		intercept::sqf::remove_uniform(_internalObject);
	}
	const char_t* Object::faction()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::faction(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::removeAllPrimaryWeaponItems()
	{
		intercept::sqf::remove_all_primary_weapon_items(_internalObject);
	}
	bool  Object::getDiverState()
	{
		return intercept::sqf::get_diver_state(_internalObject);
	}
	/*ARRAY  Object::getUnloadInCombat()
	{
		return intercept::sqf::get_unload_in_combat(_internalObject);
	}
	*/
	/*ARRAY  Object::allTurrets()
	{
		return intercept::sqf::all_turrets(_internalObject);
	}
	*/
	bool  Object::camCommitted()
	{
		return intercept::sqf::cam_committed(_internalObject);
	}
	/*TASK  Object::currentTask()
	{
		return intercept::sqf::current_task(_internalObject);
	}
	*/
	/*SIDE  Object::flagSide()
	{
		return intercept::sqf::flag_side(_internalObject);
	}
	*/
	bool  Object::isInRemainsCollector()
	{
		return intercept::sqf::is_in_remains_collector(_internalObject);
	}
	/*ARRAY  Object::magazinesAmmoCargo()
	{
		return intercept::sqf::magazines_ammo_cargo(_internalObject);
	}
	*/
	void  Object::setPlayable()
	{
		intercept::sqf::set_playable(_internalObject);
	}
	/*ARRAY  Object::getAllUnitTraits()
	{
		return intercept::sqf::get_all_unit_traits(_internalObject);
	}
	*/
	void  Object::removeAllBinocularItems()
	{
		intercept::sqf::remove_all_binocular_items(_internalObject);
	}
	/*ARRAY  Object::collisionDisabledWith()
	{
		return intercept::sqf::collision_disabled_with(_internalObject);
	}
	*/
	bool  Object::isAutonomous()
	{
		return intercept::sqf::is_autonomous(_internalObject);
	}
	const char_t* Object::handgunMagazine()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::handgun_magazine(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::getOxygenRemaining()
	{
		return intercept::sqf::get_oxygen_remaining(_internalObject);
	}
	RV::Bindings::Object* Object::vehicle()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::vehicle(_internalObject));
	}
	void  Object::removeAllActions()
	{
		intercept::sqf::remove_all_actions(_internalObject);
	}
	/*ARRAY  Object::everyContainer()
	{
		return intercept::sqf::every_container(_internalObject);
	}
	*/
	void  Object::stopEngineRTD()
	{
		intercept::sqf::stop_engine_rtd(_internalObject);
	}
	RV::Bindings::Object* Object::gunner()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::gunner(_internalObject));
	}
	RV::Bindings::Object* Object::isVehicleCargo()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::is_vehicle_cargo(_internalObject));
	}
	void  Object::lightDetachObject()
	{
		intercept::sqf::light_detach_object(_internalObject);
	}
	RV::Bindings::Object* Object::getConnectedUAVUnit()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::get_connected_uav_unit(_internalObject));
	}
	/*ARRAY  Object::getPersonUsedDLCs()
	{
		return intercept::sqf::get_person_used_dlcs(_internalObject);
	}
	*/
	bool  Object::isAllowedCrewInImmobile()
	{
		return intercept::sqf::is_allowed_crew_in_immobile(_internalObject);
	}
	/*ARRAY  Object::getDescription()
	{
		return intercept::sqf::get_description(_internalObject);
	}
	*/
	/*ARRAY  Object::ropeEndPosition()
	{
		return intercept::sqf::rope_end_position(_internalObject);
	}
	*/
	/*ARRAY  Object::items()
	{
		return intercept::sqf::items(_internalObject);
	}
	*/
	const char_t* Object::getObjectID()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::get_object_id(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::getRepairCargo()
	{
		return intercept::sqf::get_repair_cargo(_internalObject);
	}
	const char_t* Object::pitch()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::pitch(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::isVehicleRadarOn()
	{
		return intercept::sqf::is_vehicle_radar_on(_internalObject);
	}
	float  Object::cameraInterest()
	{
		return intercept::sqf::camera_interest(_internalObject);
	}
	void  Object::removeHeadgear()
	{
		intercept::sqf::remove_headgear(_internalObject);
	}
	bool  Object::lockedInventory()
	{
		return intercept::sqf::locked_inventory(_internalObject);
	}
	const char_t* Object::unitCombatMode()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::unit_combat_mode(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::isFormationLeader()
	{
		return intercept::sqf::is_formation_leader(_internalObject);
	}
	float  Object::numberOfEnginesRTD()
	{
		return intercept::sqf::number_of_engines_rtd(_internalObject);
	}
	/*ARRAY  Object::velocity()
	{
		return intercept::sqf::velocity(_internalObject);
	}
	*/
	/*ARRAY  Object::getAllSoundControllers()
	{
		return intercept::sqf::get_all_sound_controllers(_internalObject);
	}
	*/
	bool  Object::isHidden()
	{
		return intercept::sqf::is_hidden(_internalObject);
	}
	/*ARRAY  Object::aimPos()
	{
		return intercept::sqf::aim_pos(_internalObject);
	}
	*/
	/*ARRAY  Object::ropeSegments()
	{
		return intercept::sqf::rope_segments(_internalObject);
	}
	*/
	void  Object::clearWeaponCargo()
	{
		intercept::sqf::clear_weapon_cargo(_internalObject);
	}
	/*ARRAY  Object::assignedVehicleRole()
	{
		return intercept::sqf::assigned_vehicle_role(_internalObject);
	}
	*/
	float  Object::precision()
	{
		return intercept::sqf::precision(_internalObject);
	}
	/*ARRAY  Object::ropes()
	{
		return intercept::sqf::ropes(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::backpackContainer()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::backpack_container(_internalObject));
	}
	/*ARRAY  Object::vectorUpVisual()
	{
		return intercept::sqf::vector_up_visual(_internalObject);
	}
	*/
	/*ARRAY  Object::vectorDir()
	{
		return intercept::sqf::vector_dir(_internalObject);
	}
	*/
	void  Object::clearBackpackCargoGlobal()
	{
		intercept::sqf::clear_backpack_cargo_global(_internalObject);
	}
	/*ARRAY  Object::equipmentDisabled()
	{
		return intercept::sqf::equipment_disabled(_internalObject);
	}
	*/
	void  Object::removeAllHandgunItems()
	{
		intercept::sqf::remove_all_handgun_items(_internalObject);
	}
	bool  Object::curatorEditingAreaType()
	{
		return intercept::sqf::curator_editing_area_type(_internalObject);
	}
	void  Object::putWeaponPool()
	{
		intercept::sqf::put_weapon_pool(_internalObject);
	}
	float  Object::getObjectDLC()
	{
		return intercept::sqf::get_object_dlc(_internalObject);
	}
	bool  Object::lockIdentity()
	{
		return intercept::sqf::lock_identity(_internalObject);
	}
	const char_t* Object::typeOf()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::type_of(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::deleteVehicleCrew()
	{
		intercept::sqf::delete_vehicle_crew(_internalObject);
	}
	float  Object::score()
	{
		return intercept::sqf::score(_internalObject);
	}
	bool  Object::isAwake()
	{
		return intercept::sqf::is_awake(_internalObject);
	}
	RV::Bindings::Object* Object::laserTarget()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::laser_target(_internalObject));
	}
	/*ARRAY  Object::getCenterOfMass()
	{
		return intercept::sqf::get_center_of_mass(_internalObject);
	}
	*/
	const char_t* Object::stance()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::stance(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::curatorPoints()
	{
		return intercept::sqf::curator_points(_internalObject);
	}
	bool  Object::alive()
	{
		return intercept::sqf::alive(_internalObject);
	}
	/*ARRAY  Object::crew()
	{
		return intercept::sqf::crew(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::triggerAttachedVehicle()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::trigger_attached_vehicle(_internalObject));
	}
	const char_t* Object::rank()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::rank(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::getLightingAt()
	{
		return intercept::sqf::get_lighting_at(_internalObject);
	}
	*/
	float  Object::getRotorBrakeRTD()
	{
		return intercept::sqf::get_rotor_brake_rtd(_internalObject);
	}
	/*ARRAY  Object::itemsWithMagazines()
	{
		return intercept::sqf::items_with_magazines(_internalObject);
	}
	*/
	bool  Object::isBleeding()
	{
		return intercept::sqf::is_bleeding(_internalObject);
	}
	const char_t* Object::nameSound()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::name_sound(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::locked()
	{
		return intercept::sqf::locked(_internalObject);
	}
	void  Object::clearBackpackCargo()
	{
		intercept::sqf::clear_backpack_cargo(_internalObject);
	}
	/*ARRAY  Object::binocularItems()
	{
		return intercept::sqf::binocular_items(_internalObject);
	}
	*/
	float  Object::formationDirection()
	{
		return intercept::sqf::formation_direction(_internalObject);
	}
	/*ARRAY  Object::getWeaponCargo()
	{
		return intercept::sqf::get_weapon_cargo(_internalObject);
	}
	*/
	bool  Object::isAbleToBreathe()
	{
		return intercept::sqf::is_able_to_breathe(_internalObject);
	}
	RV::Bindings::Object* Object::getAssignedCuratorUnit()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::get_assigned_curator_unit(_internalObject));
	}
	bool  Object::dynamicSimulationEnabled()
	{
		return intercept::sqf::dynamic_simulation_enabled(_internalObject);
	}
	/*ARRAY  Object::hcAllGroups()
	{
		return intercept::sqf::hc_all_groups(_internalObject);
	}
	*/
	const char_t* Object::currentCommand()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::current_command(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	const char_t* Object::unitPos()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::unit_pos(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::itemCargo()
	{
		return intercept::sqf::item_cargo(_internalObject);
	}
	*/
	/*ARRAY  Object::getUserMFDValue()
	{
		return intercept::sqf::get_user_mfd_value(_internalObject);
	}
	*/
	float  Object::allowedService()
	{
		return intercept::sqf::allowed_service(_internalObject);
	}
	/*ARRAY  Object::secondaryWeaponItems()
	{
		return intercept::sqf::secondary_weapon_items(_internalObject);
	}
	*/
	float  Object::getAimingCoef()
	{
		return intercept::sqf::get_aiming_coef(_internalObject);
	}
	/*ARRAY  Object::ropeAttachedObjects()
	{
		return intercept::sqf::rope_attached_objects(_internalObject);
	}
	*/
	bool  Object::mineActive()
	{
		return intercept::sqf::mine_active(_internalObject);
	}
	const char_t* Object::handgunWeapon()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::handgun_weapon(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::synchronizedWaypoints()
	{
		return intercept::sqf::synchronized_waypoints(_internalObject);
	}
	*/
	bool  Object::vehicleCargoEnabled()
	{
		return intercept::sqf::vehicle_cargo_enabled(_internalObject);
	}
	void  Object::moveOut()
	{
		intercept::sqf::move_out(_internalObject);
	}
	float  Object::getObjectFOV()
	{
		return intercept::sqf::get_object_fov(_internalObject);
	}
	RV::Bindings::Object* Object::assignedVehicle()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::assigned_vehicle(_internalObject));
	}
	/*ARRAY  Object::expectedDestination()
	{
		return intercept::sqf::expected_destination(_internalObject);
	}
	*/
	const char_t* Object::goggles()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::goggles(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	void  Object::removeAllCuratorAddons()
	{
		intercept::sqf::remove_all_curator_addons(_internalObject);
	}
	bool  Object::isBurning()
	{
		return intercept::sqf::is_burning(_internalObject);
	}
	/*ARRAY  Object::getObjectMaterials()
	{
		return intercept::sqf::get_object_materials(_internalObject);
	}
	*/
	const char_t* Object::getPlayerUID()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::get_player_uid(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::airplaneThrottle()
	{
		return intercept::sqf::airplane_throttle(_internalObject);
	}
	const char_t* Object::binocular()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::binocular(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::getWeaponSway()
	{
		return intercept::sqf::get_weapon_sway(_internalObject);
	}
	/*ARRAY  Object::handgunItems()
	{
		return intercept::sqf::handgun_items(_internalObject);
	}
	*/
	void  Object::removeAllCuratorEditingAreas()
	{
		intercept::sqf::remove_all_curator_editing_areas(_internalObject);
	}
	/*ARRAY  Object::getPos()
	{
		return intercept::sqf::get_pos(_internalObject);
	}
	*/
	/*ARRAY  Object::curatorCameraArea()
	{
		return intercept::sqf::curator_camera_area(_internalObject);
	}
	*/
	/*ARRAY  Object::backpackCargo()
	{
		return intercept::sqf::backpack_cargo(_internalObject);
	}
	*/
	/*ARRAY  Object::getObjectTextures()
	{
		return intercept::sqf::get_object_textures(_internalObject);
	}
	*/
	/*ARRAY  Object::vestMagazines()
	{
		return intercept::sqf::vest_magazines(_internalObject);
	}
	*/
	/*ARRAY  Object::curatorAddons()
	{
		return intercept::sqf::curator_addons(_internalObject);
	}
	*/
	const char_t* Object::secondaryWeapon()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::secondary_weapon(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::getPosVisual()
	{
		return intercept::sqf::get_pos_visual(_internalObject);
	}
	*/
	void  Object::deleteCollection()
	{
		intercept::sqf::delete_collection(_internalObject);
	}
	/*ARRAY  Object::triggerStatements()
	{
		return intercept::sqf::trigger_statements(_internalObject);
	}
	*/
	/*ARRAY  Object::getPosASLW()
	{
		return intercept::sqf::get_pos_aslw(_internalObject);
	}
	*/
	/*ARRAY  Object::getPosWorldVisual()
	{
		return intercept::sqf::get_pos_world_visual(_internalObject);
	}
	*/
	bool  Object::canDeployWeapon()
	{
		return intercept::sqf::can_deploy_weapon(_internalObject);
	}
	void  Object::camDestroy()
	{
		intercept::sqf::cam_destroy(_internalObject);
	}
	float  Object::curatorWaypointCost()
	{
		return intercept::sqf::curator_waypoint_cost(_internalObject);
	}
	bool  Object::isMarkedForCollection()
	{
		return intercept::sqf::is_marked_for_collection(_internalObject);
	}
	RV::Bindings::Object* Object::getAssignedCuratorLogic()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::get_assigned_curator_logic(_internalObject));
	}
	/*ARRAY  Object::triggerActivation()
	{
		return intercept::sqf::trigger_activation(_internalObject);
	}
	*/
	void  Object::resetSubgroupDirection()
	{
		intercept::sqf::reset_subgroup_direction(_internalObject);
	}
	/*ARRAY  Object::getRoadInfo()
	{
		return intercept::sqf::get_road_info(_internalObject);
	}
	*/
	/*ARRAY  Object::vestItems()
	{
		return intercept::sqf::vest_items(_internalObject);
	}
	*/
	void  Object::switchCamera()
	{
		intercept::sqf::switch_camera(_internalObject);
	}
	RV::Bindings::Object* Object::currentPilot()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::current_pilot(_internalObject));
	}
	bool  Object::waypointsEnabledUAV()
	{
		return intercept::sqf::waypoints_enabled_uav(_internalObject);
	}
	/*ARRAY  Object::list()
	{
		return intercept::sqf::list(_internalObject);
	}
	*/
	void  Object::detach()
	{
		intercept::sqf::detach(_internalObject);
	}
	float  Object::needReload()
	{
		return intercept::sqf::need_reload(_internalObject);
	}
	bool  Object::brakesDisabled()
	{
		return intercept::sqf::brakes_disabled(_internalObject);
	}
	bool  Object::isNull()
	{
		return intercept::sqf::is_null(_internalObject);
	}
	void  Object::removeBackpack()
	{
		intercept::sqf::remove_backpack(_internalObject);
	}
	void  Object::hideObjectGlobal()
	{
		intercept::sqf::hide_object_global(_internalObject);
	}
	/*ARRAY  Object::getSensorThreats()
	{
		return intercept::sqf::get_sensor_threats(_internalObject);
	}
	*/
	/*ARRAY  Object::getBackpackCargo()
	{
		return intercept::sqf::get_backpack_cargo(_internalObject);
	}
	*/
	/*ARRAY  Object::getShotParents()
	{
		return intercept::sqf::get_shot_parents(_internalObject);
	}
	*/
	/*ARRAY  Object::curatorRegisteredObjects()
	{
		return intercept::sqf::curator_registered_objects(_internalObject);
	}
	*/
	const char_t* Object::gestureState()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::gesture_state(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::ropeAttachEnabled()
	{
		return intercept::sqf::rope_attach_enabled(_internalObject);
	}
	RV::Bindings::Object* Object::firstBackpack()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::first_backpack(_internalObject));
	}
	/*ARRAY  Object::getItemCargo()
	{
		return intercept::sqf::get_item_cargo(_internalObject);
	}
	*/
	float  Object::getBurningValue()
	{
		return intercept::sqf::get_burning_value(_internalObject);
	}
	float  Object::loadBackpack()
	{
		return intercept::sqf::load_backpack(_internalObject);
	}
	void  Object::unassignTeam()
	{
		intercept::sqf::unassign_team(_internalObject);
	}
	void  Object::removeAllOwnedMines()
	{
		intercept::sqf::remove_all_owned_mines(_internalObject);
	}
	float  Object::ropeLength()
	{
		return intercept::sqf::rope_length(_internalObject);
	}
	float  Object::getAnimSpeedCoef()
	{
		return intercept::sqf::get_anim_speed_coef(_internalObject);
	}
	/*ARRAY  Object::fullCrew()
	{
		return intercept::sqf::full_crew(_internalObject);
	}
	*/
	/*ARRAY  Object::formationMembers()
	{
		return intercept::sqf::formation_members(_internalObject);
	}
	*/
	/*ARRAY  Object::namedProperties()
	{
		return intercept::sqf::named_properties(_internalObject);
	}
	*/
	/*ARRAY  Object::visiblePosition()
	{
		return intercept::sqf::visible_position(_internalObject);
	}
	*/
	RV::Bindings::Object* Object::vestContainer()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::vest_container(_internalObject));
	}
	/*ARRAY  Object::getPilotCameraDirection()
	{
		return intercept::sqf::get_pilot_camera_direction(_internalObject);
	}
	*/
	bool  Object::conversationDisabled()
	{
		return intercept::sqf::conversation_disabled(_internalObject);
	}
	/*ARRAY  Object::getPosASL()
	{
		return intercept::sqf::get_pos_asl(_internalObject);
	}
	*/
	bool  Object::inflamed()
	{
		return intercept::sqf::inflamed(_internalObject);
	}
	/*ARRAY  Object::weaponInertia()
	{
		return intercept::sqf::weapon_inertia(_internalObject);
	}
	*/
	/*ARRAY  Object::missileTargetPos()
	{
		return intercept::sqf::missile_target_pos(_internalObject);
	}
	*/
	bool  Object::isDamageAllowed()
	{
		return intercept::sqf::is_damage_allowed(_internalObject);
	}
	bool  Object::isForcedWalk()
	{
		return intercept::sqf::is_forced_walk(_internalObject);
	}
	float  Object::currentVisionMode()
	{
		return intercept::sqf::current_vision_mode(_internalObject);
	}
	bool  Object::hasPilotCamera()
	{
		return intercept::sqf::has_pilot_camera(_internalObject);
	}
	float  Object::direction()
	{
		return intercept::sqf::direction(_internalObject);
	}
	float  Object::getSuppression()
	{
		return intercept::sqf::get_suppression(_internalObject);
	}
	RV::Bindings::Object* Object::assignedCommander()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::assigned_commander(_internalObject));
	}
	void  Object::deleteSite()
	{
		intercept::sqf::delete_site(_internalObject);
	}
	RV::Bindings::Object* Object::nearestBuilding()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::nearest_building(_internalObject));
	}
	/*ARRAY  Object::getPosATLVisual()
	{
		return intercept::sqf::get_pos_atl_visual(_internalObject);
	}
	*/
	void  Object::clearItemCargoGlobal()
	{
		intercept::sqf::clear_item_cargo_global(_internalObject);
	}
	void  Object::removeGoggles()
	{
		intercept::sqf::remove_goggles(_internalObject);
	}
	float  Object::getPlayerChannel()
	{
		return intercept::sqf::get_player_channel(_internalObject);
	}
	void  Object::clearItemCargo()
	{
		intercept::sqf::clear_item_cargo(_internalObject);
	}
	/*ARRAY  Object::UAVControl()
	{
		return intercept::sqf::uav_control(_internalObject);
	}
	*/
	bool  Object::isWalking()
	{
		return intercept::sqf::is_walking(_internalObject);
	}
	RV::Bindings::Object* Object::flag()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::flag(_internalObject));
	}
	RV::Bindings::Object* Object::formLeader()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::form_leader(_internalObject));
	}
	bool  Object::stopped()
	{
		return intercept::sqf::stopped(_internalObject);
	}
	void  Object::clearAllItemsFromBackpack()
	{
		intercept::sqf::clear_all_items_from_backpack(_internalObject);
	}
	const char_t* Object::hmd()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::hmd(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::canFire()
	{
		return intercept::sqf::can_fire(_internalObject);
	}
	const char_t* Object::binocularMagazine()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::binocular_magazine(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::isObjectHidden()
	{
		return intercept::sqf::is_object_hidden(_internalObject);
	}
	bool  Object::underwater()
	{
		return intercept::sqf::underwater(_internalObject);
	}
	/*ARRAY  Object::unitAimPosition()
	{
		return intercept::sqf::unit_aim_position(_internalObject);
	}
	*/
	float  Object::morale()
	{
		return intercept::sqf::morale(_internalObject);
	}
	void  Object::selectPlayer()
	{
		intercept::sqf::select_player(_internalObject);
	}
	const char_t* Object::combatBehaviour()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::combat_behaviour(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::isCollisionLightOn()
	{
		return intercept::sqf::is_collision_light_on(_internalObject);
	}
	const char_t* Object::formationTask()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::formation_task(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::isManualFire()
	{
		return intercept::sqf::is_manual_fire(_internalObject);
	}
	/*ARRAY  Object::wingsForcesRTD()
	{
		return intercept::sqf::wings_forces_rtd(_internalObject);
	}
	*/
	void  Object::deleteVehicle()
	{
		intercept::sqf::delete_vehicle(_internalObject);
	}
	bool  Object::isUAVConnected()
	{
		return intercept::sqf::is_uavconnected(_internalObject);
	}
	/*ARRAY  Object::getPilotCameraRotation()
	{
		return intercept::sqf::get_pilot_camera_rotation(_internalObject);
	}
	*/
	const char_t* Object::currentWeapon()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::current_weapon(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	float  Object::getDirVisual()
	{
		return intercept::sqf::get_dir_visual(_internalObject);
	}
	/*ARRAY  Object::enginesRpmRTD()
	{
		return intercept::sqf::engines_rpm_rtd(_internalObject);
	}
	*/
	void  Object::clearMagazineCargoGlobal()
	{
		intercept::sqf::clear_magazine_cargo_global(_internalObject);
	}
	/*ARRAY  Object::synchronizedObjects()
	{
		return intercept::sqf::synchronized_objects(_internalObject);
	}
	*/
	float  Object::getDammage()
	{
		return intercept::sqf::get_dammage(_internalObject);
	}
	/*ARRAY  Object::weightRTD()
	{
		return intercept::sqf::weight_rtd(_internalObject);
	}
	*/
	float  Object::loadVest()
	{
		return intercept::sqf::load_vest(_internalObject);
	}
	const char_t* Object::pose()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::pose(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::getPosASLVisual()
	{
		return intercept::sqf::get_pos_asl_visual(_internalObject);
	}
	*/
	/*ARRAY  Object::eyePos()
	{
		return intercept::sqf::eye_pos(_internalObject);
	}
	*/
	void  Object::removeAllItems()
	{
		intercept::sqf::remove_all_items(_internalObject);
	}
	bool  Object::vehicleReportOwnPosition()
	{
		return intercept::sqf::vehicle_report_own_position(_internalObject);
	}
	/*GROUP  Object::createVehicleCrew()
	{
		return intercept::sqf::create_vehicle_crew(_internalObject);
	}
	*/
	/*ARRAY  Object::uniformMagazines()
	{
		return intercept::sqf::uniform_magazines(_internalObject);
	}
	*/
	/*ARRAY  Object::backpackItems()
	{
		return intercept::sqf::backpack_items(_internalObject);
	}
	*/
	const char_t* Object::getPlayerID()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::get_player_id(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::enginesIsOnRTD()
	{
		return intercept::sqf::engines_is_on_rtd(_internalObject);
	}
	*/
	bool  Object::didJIPOwner()
	{
		return intercept::sqf::did_jipowner(_internalObject);
	}
	/*ARRAY  Object::primaryWeaponItems()
	{
		return intercept::sqf::primary_weapon_items(_internalObject);
	}
	*/
	/*ARRAY  Object::visiblePositionASL()
	{
		return intercept::sqf::visible_position_asl(_internalObject);
	}
	*/
	const char_t* Object::lightIsOn()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::light_is_on(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	/*ARRAY  Object::assignedCargo()
	{
		return intercept::sqf::assigned_cargo(_internalObject);
	}
	*/
	const char_t* Object::currentMagazine()
	{
		// do this hack and have a memory leak, that's okay for right now
		std::string temp = intercept::sqf::current_magazine(_internalObject);

		// memory leak here!!!!
		char_t* str = new char_t[temp.length() + 1];
		int rc = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, temp.c_str(), -1, str, temp.length() + 1);
		return str;
	}
	bool  Object::vehicleReportRemoteTargets()
	{
		return intercept::sqf::vehicle_report_remote_targets(_internalObject);
	}
	void  Object::forceRespawn()
	{
		intercept::sqf::force_respawn(_internalObject);
	}
	RV::Bindings::Object* Object::getConnectedUAV()
	{
		//TODO: USE INTERNAL ALLOCATOR!!!!
		return new RV::Bindings::Object(intercept::sqf::get_connected_uav(_internalObject));
	}
	bool  Object::lockedDriver()
	{
		return intercept::sqf::locked_driver(_internalObject);
	}
	/*ARRAY  Object::getPilotCameraPosition()
	{
		return intercept::sqf::get_pilot_camera_position(_internalObject);
	}
	*/

}

extern "C" __declspec(dllexport) RV::Bindings::Object * CreateGameObject(const char* type, vector3 position)
{
	return new RV::Bindings::Object(type, position);
}

extern "C" __declspec(dllexport) void DeleteGameObject(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		delete object;
	}
}

extern "C" __declspec(dllexport) vector3 GetPos(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos();
	}
}

extern "C" __declspec(dllexport) vector3 GetPosASL(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos_asl();
	}
}

extern "C" __declspec(dllexport) vector3 GetPosASLW(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos_aslw();
	}
}

extern "C" __declspec(dllexport) vector3 GetPosALT(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos_atl();
	}
}

extern "C" __declspec(dllexport) vector3 GetPosWorld(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos_world();
	}
}

extern "C" __declspec(dllexport) vector3 GetRelPos(RV::Bindings::Object * object, float distance, float direction)
{
	if (object != nullptr)
	{
		return object->get_rel_pos(distance, direction);
	}
}

extern "C" __declspec(dllexport) vector3 ModelToWorld(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		return object->model_to_world(vector);
	}
}

extern "C" __declspec(dllexport) vector3 ModelToWorldWorld(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		return object->model_to_world_world(vector);
	}
}

extern "C" __declspec(dllexport) void SetPos(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos(vector);
	}
}

extern "C" __declspec(dllexport) void SetPosASL(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos_asl(vector);
	}
}

extern "C" __declspec(dllexport) void SetPosASLW(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos_aslw(vector);
	}
}

extern "C" __declspec(dllexport) void SetPosALT(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos_atl(vector);
	}
}

extern "C" __declspec(dllexport) void SetPosWorld(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos_world(vector);
	}
}

extern "C" __declspec(dllexport) void WorldToModel(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->world_to_model(vector);
	}
}

extern "C" __declspec(dllexport) void WorldToModelVisual(RV::Bindings::Object * object, vector3 vector)
{
	if (object != nullptr)
	{
		object->world_to_model_visual(vector);
	}
}

extern "C" __declspec(dllexport) float CurrentZeroing(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentZeroing();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsAutoHoverOn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAutoHoverOn();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float GetObjectScale(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getObjectScale();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * TriggerText(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->triggerText();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetFatigue(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getFatigue();
	}
	return float{};
}

extern "C" __declspec(dllexport) void FillWeaponsFromPool(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->fillWeaponsFromPool();
	}
}

extern "C" __declspec(dllexport) bool IsObjectRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isObjectRTD();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * RoleDescription(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->roleDescription();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetAmmoCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAmmoCargo();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * FlagOwner(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->flagOwner();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float Speed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->speed();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool ReloadEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->reloadEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float Rating(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->rating();
	}
	return float{};
}

extern "C" __declspec(dllexport) void HideObject(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->hideObject();
	}
}

extern "C" __declspec(dllexport) const char_t * PrimaryWeapon(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->primaryWeapon();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float CuratorCameraAreaCeiling(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->curatorCameraAreaCeiling();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveVest(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeVest();
	}
}

extern "C" __declspec(dllexport) bool MoveToFailed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->moveToFailed();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float RankId(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->rankId();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveAllItemsWithMagazines(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllItemsWithMagazines();
	}
}

extern "C" __declspec(dllexport) float GetPlayerVoNVolume(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getPlayerVoNVolume();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveBackpackGlobal(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeBackpackGlobal();
	}
}

extern "C" __declspec(dllexport) const char_t * Face(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->face();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetAttackTarget(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAttackTarget();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * AssignedTeam(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->assignedTeam();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool TriggerActivated(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->triggerActivated();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void UnassignVehicle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->unassignVehicle();
	}
}

extern "C" __declspec(dllexport) float MoveTime(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->moveTime();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetCustomSoundControllerCount(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getCustomSoundControllerCount();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * AnimationState(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->animationState();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsTurnedOut(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isTurnedOut();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void RemoveAllSecondaryWeaponItems(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllSecondaryWeaponItems();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * CamTarget(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->camTarget();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsSimpleObject(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isSimpleObject();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float ScudState(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->scudState();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsAutoTrimOnRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAutoTrimOnRTD();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void RopeDestroy(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->ropeDestroy();
	}
}

extern "C" __declspec(dllexport) bool IsTouchingGround(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isTouchingGround();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * Vest(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vest();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * Headgear(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->headgear();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float Fuel(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->fuel();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetForcedSpeed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getForcedSpeed();
	}
	return float{};
}

extern "C" __declspec(dllexport) float Damage(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->damage();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetBleedingRemaining(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getBleedingRemaining();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * Leader(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->leader();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetCustomAimCoef(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getCustomAimCoef();
	}
	return float{};
}

extern "C" __declspec(dllexport) float UnitRecoilCoefficient(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->unitRecoilCoefficient();
	}
	return float{};
}

extern "C" __declspec(dllexport) void UnassignCurator(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->unassignCurator();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * ObjectParent(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->objectParent();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void ClearMagazineCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearMagazineCargo();
	}
}

extern "C" __declspec(dllexport) bool CanMove(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->canMove();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float GetWingsOrientationRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getWingsOrientationRTD();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsStaminaEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isStaminaEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * UnitBackpack(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->unitBackpack();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void PickWeaponPool(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->pickWeaponPool();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetSlingLoad(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getSlingLoad();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void Reload(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->reload();
	}
}

extern "C" __declspec(dllexport) const char_t * Speaker(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->speaker();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool UnitIsUAV(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->unitIsUAV();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * AssignedTarget(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->assignedTarget();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) RV::Bindings::Object * AttachedTo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->attachedTo();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) RV::Bindings::Object * EffectiveCommander(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->effectiveCommander();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * LandResult(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->landResult();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void ClearWeaponCargoGlobal(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearWeaponCargoGlobal();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * AssignedDriver(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->assignedDriver();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float FlagAnimationPhase(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->flagAnimationPhase();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetTowParent(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getTowParent();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetDir(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getDir();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * UniformContainer(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->uniformContainer();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsPlayer(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isPlayer();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool CamPreloaded(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->camPreloaded();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool Local(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->local();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool Fleeing(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->fleeing();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsCopilotEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isCopilotEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float MaxLoad(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->maxLoad();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * Uniform(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->uniform();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * WFSideText(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->WFSideText();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * FlagTexture(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->flagTexture();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetFuelCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getFuelCargo();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GroupID(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->groupID();
	}
	return float{};
}

extern "C" __declspec(dllexport) float CaptiveNum(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->captiveNum();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool CanUnloadInCombat(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->canUnloadInCombat();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * NetId(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->netId();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void RemoveAllAssignedItems(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllAssignedItems();
	}
}

extern "C" __declspec(dllexport) bool RopeUnwound(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->ropeUnwound();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void AddSwitchableUnit(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->addSwitchableUnit();
	}
}

extern "C" __declspec(dllexport) float Owner(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->owner();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * Driver(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->driver();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float LoadUniform(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->loadUniform();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsLaserOn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isLaserOn();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool SomeAmmo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->someAmmo();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsWeaponRested(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isWeaponRested();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsAimPrecisionEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAimPrecisionEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * Commander(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->commander();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * IncapacitatedState(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->incapacitatedState();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float CollectiveRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->collectiveRTD();
	}
	return float{};
}

extern "C" __declspec(dllexport) float InsideBuilding(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->insideBuilding();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetAnimAimPrecision(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAnimAimPrecision();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool CanTriggerDynamicSimulation(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->canTriggerDynamicSimulation();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool WeaponLowered(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->weaponLowered();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float HandsHit(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->handsHit();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveAllCuratorCameraAreas(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllCuratorCameraAreas();
	}
}

extern "C" __declspec(dllexport) const char_t * TriggerType(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->triggerType();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void HideBody(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->hideBody();
	}
}

extern "C" __declspec(dllexport) void TriggerAmmo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->triggerAmmo();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * MissileTarget(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->missileTarget();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * Behaviour(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->behaviour();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * LifeState(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->lifeState();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsSprintAllowed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isSprintAllowed();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float TriggerInterval(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->triggerInterval();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveAllContainers(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllContainers();
	}
}

extern "C" __declspec(dllexport) float rvGetObjectType(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getObjectType();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * RopeAttachedTo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->ropeAttachedTo();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool MoveToCompleted(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->moveToCompleted();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool CanStand(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->canStand();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * FormationLeader(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->formationLeader();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * GetPlateNumber(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getPlateNumber();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsEngineOn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isEngineOn();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * GetForcedFlagTexture(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getForcedFlagTexture();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float Skill(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->skill();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * Backpack(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->backpack();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void HcRemoveAllGroups(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->hcRemoveAllGroups();
	}
}

extern "C" __declspec(dllexport) float GetStamina(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getStamina();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetMass(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getMass();
	}
	return float{};
}

extern "C" __declspec(dllexport) float Load(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->load();
	}
	return float{};
}

extern "C" __declspec(dllexport) float LoadAbs(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->loadAbs();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveSwitchableUnit(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeSwitchableUnit();
	}
}

extern "C" __declspec(dllexport) bool SimulationEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->simulationEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool VehicleReceiveRemoteTargets(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vehicleReceiveRemoteTargets();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * CurrentMuzzle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentMuzzle();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * CurrentWeaponMode(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentWeaponMode();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetWingsPositionRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getWingsPositionRTD();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * Name(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->name();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool Captive(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->captive();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsWeaponDeployed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isWeaponDeployed();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void RemoveAllWeapons(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllWeapons();
	}
}

extern "C" __declspec(dllexport) const char_t * VehicleVarName(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vehicleVarName();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float TriggerTimeoutCurrent(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->triggerTimeoutCurrent();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * AssignedGunner(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->assignedGunner();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetCorpse(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getCorpse();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void RemoveUniform(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeUniform();
	}
}

extern "C" __declspec(dllexport) const char_t * Faction(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->faction();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void RemoveAllPrimaryWeaponItems(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllPrimaryWeaponItems();
	}
}

extern "C" __declspec(dllexport) bool GetDiverState(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getDiverState();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool CamCommitted(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->camCommitted();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsInRemainsCollector(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isInRemainsCollector();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void SetPlayable(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->setPlayable();
	}
}

extern "C" __declspec(dllexport) void RemoveAllBinocularItems(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllBinocularItems();
	}
}

extern "C" __declspec(dllexport) bool IsAutonomous(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAutonomous();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * HandgunMagazine(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->handgunMagazine();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetOxygenRemaining(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getOxygenRemaining();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * Vehicle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vehicle();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void RemoveAllActions(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllActions();
	}
}

extern "C" __declspec(dllexport) void StopEngineRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->stopEngineRTD();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * Gunner(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->gunner();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) RV::Bindings::Object * IsVehicleCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isVehicleCargo();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void LightDetachObject(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->lightDetachObject();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetConnectedUAVUnit(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getConnectedUAVUnit();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsAllowedCrewInImmobile(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAllowedCrewInImmobile();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * GetObjectID(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getObjectID();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetRepairCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getRepairCargo();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * Pitch(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->pitch();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsVehicleRadarOn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isVehicleRadarOn();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float CameraInterest(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->cameraInterest();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveHeadgear(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeHeadgear();
	}
}

extern "C" __declspec(dllexport) bool LockedInventory(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->lockedInventory();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * UnitCombatMode(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->unitCombatMode();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsFormationLeader(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isFormationLeader();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float NumberOfEnginesRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->numberOfEnginesRTD();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsHidden(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isHidden();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void ClearWeaponCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearWeaponCargo();
	}
}

extern "C" __declspec(dllexport) float Precision(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->precision();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * BackpackContainer(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->backpackContainer();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void ClearBackpackCargoGlobal(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearBackpackCargoGlobal();
	}
}

extern "C" __declspec(dllexport) void RemoveAllHandgunItems(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllHandgunItems();
	}
}

extern "C" __declspec(dllexport) bool CuratorEditingAreaType(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->curatorEditingAreaType();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void PutWeaponPool(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->putWeaponPool();
	}
}

extern "C" __declspec(dllexport) float GetObjectDLC(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getObjectDLC();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool LockIdentity(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->lockIdentity();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * TypeOf(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->typeOf();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void DeleteVehicleCrew(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->deleteVehicleCrew();
	}
}

extern "C" __declspec(dllexport) float Score(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->score();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsAwake(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAwake();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * LaserTarget(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->laserTarget();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * Stance(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->stance();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float CuratorPoints(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->curatorPoints();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool Alive(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->alive();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * TriggerAttachedVehicle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->triggerAttachedVehicle();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * Rank(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->rank();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetRotorBrakeRTD(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getRotorBrakeRTD();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsBleeding(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isBleeding();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * NameSound(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->nameSound();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float Locked(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->locked();
	}
	return float{};
}

extern "C" __declspec(dllexport) void ClearBackpackCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearBackpackCargo();
	}
}

extern "C" __declspec(dllexport) float FormationDirection(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->formationDirection();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsAbleToBreathe(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isAbleToBreathe();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetAssignedCuratorUnit(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAssignedCuratorUnit();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool DynamicSimulationEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->dynamicSimulationEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * CurrentCommand(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentCommand();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * UnitPos(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->unitPos();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float AllowedService(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->allowedService();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetAimingCoef(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAimingCoef();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool MineActive(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->mineActive();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * HandgunWeapon(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->handgunWeapon();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool VehicleCargoEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vehicleCargoEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void MoveOut(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->moveOut();
	}
}

extern "C" __declspec(dllexport) float GetObjectFOV(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getObjectFOV();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * AssignedVehicle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->assignedVehicle();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * Goggles(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->goggles();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void RemoveAllCuratorAddons(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllCuratorAddons();
	}
}

extern "C" __declspec(dllexport) bool IsBurning(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isBurning();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * GetPlayerUID(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getPlayerUID();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float AirplaneThrottle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->airplaneThrottle();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * Binocular(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->binocular();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetWeaponSway(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getWeaponSway();
	}
	return float{};
}

extern "C" __declspec(dllexport) void RemoveAllCuratorEditingAreas(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllCuratorEditingAreas();
	}
}

extern "C" __declspec(dllexport) const char_t * SecondaryWeapon(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->secondaryWeapon();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void DeleteCollection(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->deleteCollection();
	}
}

extern "C" __declspec(dllexport) bool CanDeployWeapon(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->canDeployWeapon();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void CamDestroy(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->camDestroy();
	}
}

extern "C" __declspec(dllexport) float CuratorWaypointCost(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->curatorWaypointCost();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool IsMarkedForCollection(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isMarkedForCollection();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetAssignedCuratorLogic(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAssignedCuratorLogic();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void ResetSubgroupDirection(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->resetSubgroupDirection();
	}
}

extern "C" __declspec(dllexport) void SwitchCamera(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->switchCamera();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * CurrentPilot(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentPilot();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool WaypointsEnabledUAV(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->waypointsEnabledUAV();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void Detach(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->detach();
	}
}

extern "C" __declspec(dllexport) float NeedReload(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->needReload();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool BrakesDisabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->brakesDisabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsNull(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isNull();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void RemoveBackpack(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeBackpack();
	}
}

extern "C" __declspec(dllexport) void HideObjectGlobal(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->hideObjectGlobal();
	}
}

extern "C" __declspec(dllexport) const char_t * GestureState(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->gestureState();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool RopeAttachEnabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->ropeAttachEnabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * FirstBackpack(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->firstBackpack();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetBurningValue(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getBurningValue();
	}
	return float{};
}

extern "C" __declspec(dllexport) float LoadBackpack(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->loadBackpack();
	}
	return float{};
}

extern "C" __declspec(dllexport) void UnassignTeam(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->unassignTeam();
	}
}

extern "C" __declspec(dllexport) void RemoveAllOwnedMines(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllOwnedMines();
	}
}

extern "C" __declspec(dllexport) float RopeLength(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->ropeLength();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetAnimSpeedCoef(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getAnimSpeedCoef();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * VestContainer(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vestContainer();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool ConversationDisabled(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->conversationDisabled();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool Inflamed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->inflamed();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsDamageAllowed(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isDamageAllowed();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool IsForcedWalk(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isForcedWalk();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float CurrentVisionMode(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentVisionMode();
	}
	return float{};
}

extern "C" __declspec(dllexport) bool HasPilotCamera(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->hasPilotCamera();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float Direction(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->direction();
	}
	return float{};
}

extern "C" __declspec(dllexport) float GetSuppression(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getSuppression();
	}
	return float{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * AssignedCommander(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->assignedCommander();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void DeleteSite(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->deleteSite();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * NearestBuilding(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->nearestBuilding();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void ClearItemCargoGlobal(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearItemCargoGlobal();
	}
}

extern "C" __declspec(dllexport) void RemoveGoggles(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeGoggles();
	}
}

extern "C" __declspec(dllexport) float GetPlayerChannel(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getPlayerChannel();
	}
	return float{};
}

extern "C" __declspec(dllexport) void ClearItemCargo(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearItemCargo();
	}
}

extern "C" __declspec(dllexport) bool IsWalking(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isWalking();
	}
	return bool{};
}

extern "C" __declspec(dllexport) RV::Bindings::Object * Flag(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->flag();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) RV::Bindings::Object * FormLeader(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->formLeader();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool Stopped(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->stopped();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void ClearAllItemsFromBackpack(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearAllItemsFromBackpack();
	}
}

extern "C" __declspec(dllexport) const char_t * Hmd(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->hmd();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool CanFire(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->canFire();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * BinocularMagazine(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->binocularMagazine();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsObjectHidden(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isObjectHidden();
	}
	return bool{};
}

extern "C" __declspec(dllexport) bool Underwater(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->underwater();
	}
	return bool{};
}

extern "C" __declspec(dllexport) float Morale(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->morale();
	}
	return float{};
}

extern "C" __declspec(dllexport) void SelectPlayer(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->selectPlayer();
	}
}

extern "C" __declspec(dllexport) const char_t * CombatBehaviour(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->combatBehaviour();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsCollisionLightOn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isCollisionLightOn();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * FormationTask(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->formationTask();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool IsManualFire(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isManualFire();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void DeleteVehicle(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->deleteVehicle();
	}
}

extern "C" __declspec(dllexport) bool IsUAVConnected(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->isUAVConnected();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * CurrentWeapon(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentWeapon();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) float GetDirVisual(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getDirVisual();
	}
	return float{};
}

extern "C" __declspec(dllexport) void ClearMagazineCargoGlobal(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->clearMagazineCargoGlobal();
	}
}

extern "C" __declspec(dllexport) float GetDammage(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getDammage();
	}
	return float{};
}

extern "C" __declspec(dllexport) float LoadVest(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->loadVest();
	}
	return float{};
}

extern "C" __declspec(dllexport) const char_t * Pose(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->pose();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) void RemoveAllItems(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->removeAllItems();
	}
}

extern "C" __declspec(dllexport) bool VehicleReportOwnPosition(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vehicleReportOwnPosition();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * GetPlayerID(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getPlayerID();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool DidJIPOwner(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->didJIPOwner();
	}
	return bool{};
}

extern "C" __declspec(dllexport) const char_t * LightIsOn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->lightIsOn();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) const char_t * CurrentMagazine(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->currentMagazine();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool VehicleReportRemoteTargets(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->vehicleReportRemoteTargets();
	}
	return bool{};
}

extern "C" __declspec(dllexport) void ForceRespawn(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		object->forceRespawn();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object * GetConnectedUAV(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->getConnectedUAV();
	}
	return nullptr;
}

extern "C" __declspec(dllexport) bool LockedDriver(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->lockedDriver();
	}
	return bool{};
}

