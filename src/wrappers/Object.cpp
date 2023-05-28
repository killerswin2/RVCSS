
#include "headers/Object.hpp"
#include <string>
#include <vector>

namespace RV::Bindings
{
	Object::Object(const char* type, float x, float y, float z)
	{
		_internalObject = intercept::sqf::create_vehicle({ type }, {x,y,z});
	}

	//Object::Object(const char* type, float x, float y, float z, const char** markers, int length, float placement,const char* special)
	//{
	//	std::vector<std::string> markerArray{};
	//	// convert to vector<std::string>
	//	if (markers != nullptr)
	//	{
	//		markerArray = std::vector<std::string>{markers, markers + length};
	//	}
	//	_internalObject = intercept::sqf::create_vehicle({ type }, { x,y,z }, markerArray, placement, {special});
	//}

	RV::Bindings::vector3 Object::get_pos()
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_pos(_internalObject);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::get_pos_asl()
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_pos_asl(_internalObject);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::get_pos_aslw()
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_pos_aslw(_internalObject);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::get_pos_atl()
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_pos_atl(_internalObject);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::get_pos_world()
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_pos_world(_internalObject);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::get_rel_pos(float distance, float direction)
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_rel_pos(_internalObject, distance, direction);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::model_to_world(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 vector{position.x, position.y, position.z};
		intercept::types::vector3 RVvector3 = intercept::sqf::model_to_world(_internalObject, vector);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::model_to_world_world(const RV::Bindings::vector3 modelPos)
	{
		intercept::types::vector3 vector{modelPos.x, modelPos.y, modelPos.z};
		intercept::types::vector3 RVvector3 = intercept::sqf::model_to_world_world(_internalObject, vector);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	void Object::set_pos(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 RVvector3{position.x, position.y, position.z};
		intercept::sqf::set_pos(_internalObject, RVvector3);
	}

	void Object::set_pos_asl(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 RVvector3{position.x, position.y, position.z};
		intercept::sqf::set_pos_asl(_internalObject, RVvector3);
	}

	void Object::set_pos_aslw(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 RVvector3{position.x, position.y, position.z};
		intercept::sqf::set_pos_aslw(_internalObject, RVvector3);
	}
	void Object::set_pos_atl(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 RVvector3{position.x, position.y, position.z};
		intercept::sqf::set_pos_atl(_internalObject, RVvector3);
	}
	void Object::set_pos_world(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 RVvector3{position.x, position.y, position.z};
		intercept::sqf::set_pos_world(_internalObject, RVvector3);
	}

	RV::Bindings::vector3 Object::world_to_model(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 vector{position.x, position.y, position.z};
		intercept::types::vector3 RVvector3 = intercept::sqf::world_to_model(_internalObject, vector);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::world_to_model_visual(const RV::Bindings::vector3 position)
	{
		intercept::types::vector3 vector{position.x, position.y, position.z};
		intercept::types::vector3 RVvector3 = intercept::sqf::world_to_model_visual(_internalObject, vector);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	const char* Object::type_of()
	{
		auto type = intercept::sqf::type_of(_internalObject);
		return type.c_str();
	}

	bool Object::is_kind_of(const char* typeName)
	{
		return intercept::sqf::is_kind_of(_internalObject, { typeName });
	}

	bool Object::alive()
	{
		return intercept::sqf::alive(_internalObject);
	}
}

extern "C" __declspec(dllexport) RV::Bindings::Object* CreateGameObject(const char *type, float x, float y, float z)
{
	return new RV::Bindings::Object(type, x, y, z);
}

extern "C" __declspec(dllexport) void DeleteGameObject(RV::Bindings::Object* object)
{
	if (object != nullptr)
	{
		delete object;
	}
}

extern "C" __declspec(dllexport) RV::Bindings::vector3 GetPos(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos();
	}
}

extern "C" __declspec(dllexport) RV::Bindings::vector3 GetPosASL(RV::Bindings::Object * object)
{
	if (object != nullptr)
	{
		return object->get_pos_asl();
	}
}

extern "C" __declspec(dllexport) void SetPos(RV::Bindings::Object * object, RV::Bindings::vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos(vector);
	}
}

extern "C" __declspec(dllexport) void SetPosASL(RV::Bindings::Object * object, RV::Bindings::vector3 vector)
{
	if (object != nullptr)
	{
		object->set_pos(vector);
	}
}