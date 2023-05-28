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
		RV::Bindings::vector3 get_pos();
		RV::Bindings::vector3 get_pos_asl();
		RV::Bindings::vector3 get_pos_aslw();
		RV::Bindings::vector3 get_pos_atl();
		RV::Bindings::vector3 get_pos_world();
		RV::Bindings::vector3 get_rel_pos(float distance, float direction);
		RV::Bindings::vector3 model_to_world(const RV::Bindings::vector3 position);
		RV::Bindings::vector3 model_to_world_world(const RV::Bindings::vector3 modelPos);

		void set_pos(const RV::Bindings::vector3 position);
		void set_pos_asl(const RV::Bindings::vector3 position);
		void set_pos_aslw(const RV::Bindings::vector3 position);
		void set_pos_atl(const RV::Bindings::vector3 position);
		void set_pos_world(const RV::Bindings::vector3 position);
		//void set_vehicle_position(const RV::Bindings::vector3 position, char** markers, float placement, char * special);

		//RV::Bindings::vector3 unit_aim_position();
		//RV::Bindings::vector3 visible_position();
		//RV::Bindings::vector3 visible_position_asl();

		RV::Bindings::vector3 world_to_model(const RV::Bindings::vector3 position);
		RV::Bindings::vector3 world_to_model_visual(const RV::Bindings::vector3 position);

		const char* type_of();
		bool is_kind_of(const char* typeName);

		bool alive();



	};
}