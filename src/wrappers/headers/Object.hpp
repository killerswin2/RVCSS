#pragma once

#include <intercept.hpp>
#include "Types.hpp"

namespace RV::Bindings
{
	class __declspec(dllexport) Object
	{
	private:
		intercept::types::object _internalObject;
	public:
		Object();
		Object(const char* type, float x, float y, float z);
		//Object(const char* type, float x, float y, float z, const char** markers, int length, float placement, const char* special);
		//vector3 aim_pos();
		//vector3 eye_pos();
		//RV::Bindings::vector3 get_pos();
		//RV::Bindings::vector3 get_pos_asl();
		//vector3 get_pos_aslw();
		//vector3	get_pos_atl();
		//vector3 get_pos_world();
		//vector3 get_rel_pos(float distance, float direction);
		//vector3 model_to_world(const vector3& position);
		//vector3 model_to_world_world(const vector3& modelPos);
		//vector3 position();

		//void set_pos(const RV::Bindings::vector3 position);
		//void set_pos_asl(const RV::Bindings::vector3 position);
		//void set_pos_aslw(const vector3& position);
		//void set_pos_atl(const vector3& position);
		//void set_pos_world(const vector3& position);
		//void set_vehicle_position(const vector3& position, char** markers, float placement, char * special);

		//vector3 unit_aim_position();
		//vector3 visible_position();
		//vector3 visible_position_asl();

		//vector3 world_to_model(const vector3& position);
		//vector3 world_to_model_visual(const vector3& position);

		//const char* type_of();
		//bool is_kind_of(const char* typeName);

		//bool alive();



	};
}