
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

	/*RV::Bindings::vector3 Object::get_pos()
	{
		intercept::types::vector3 RVvector3= intercept::sqf::get_pos(_internalObject);
		return { RVvector3.x, RVvector3.y, RVvector3.z };
	}

	RV::Bindings::vector3 Object::get_pos_asl()
	{
		intercept::types::vector3 RVvector3 = intercept::sqf::get_pos_asl(_internalObject);
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
	}*/
}

extern "C" __declspec(dllexport) RV::Bindings::Object* create_object(const char *type, float x, float y, float z)
{
	return new RV::Bindings::Object(type, x, y, z);
}

extern "C" __declspec(dllexport) void delete_object(RV::Bindings::Object* object)
{
	if (object != nullptr)
	{
		delete object;
	}
}