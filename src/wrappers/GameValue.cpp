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

 __declspec(dllexport) intercept::types::game_value CreateGameValue()
{
	 sizeof(game_value);
	 sizeof(ref<game_data>);
	return game_value();
}

 __declspec(dllexport) intercept::types::game_value  CreateGameValueFloat(float value)
{
	return game_value(value);
}

 __declspec(dllexport) intercept::types::game_value  CreateGameValueInt(int value)
{
	return game_value(value);
}

 __declspec(dllexport) intercept::types::game_value  CreateGameValueBool(bool value)
{
	return game_value(value);
}

 __declspec(dllexport) intercept::types::game_value  CreateGameValueString(const char* value)
{
	return game_value(value);
}

 __declspec(dllexport) intercept::types::game_value CreateGameValueArrayEmpty()
{
	std::vector<game_value> object{};
	return game_value(object);
}

//__declspec(dllexport) intercept::types::game_value  CreateGameValueArray(intercept::types::game_value  array, int length)
//{

//	std::vector<game_value> object{array, array + length};
//	return  game_value(object);
//}

 __declspec(dllexport) intercept::types::game_value CreateGameValueVector2(intercept::types::vector2 value)
{
	return game_value(value);
}

 __declspec(dllexport) intercept::types::game_value CreateGameValueVector3(intercept::types::vector3 value)
{
	return game_value(value);
}

 __declspec(dllexport) void FreeRVAllocation(void* bytes, int type)
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

 __declspec(dllexport) char_t * GetDataString(intercept::types::game_value value)
{
	game_data* GameDataPointer = value.data.get();

	//string
	if (value.type() == game_data_string::type_def)
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

 __declspec(dllexport) float GetDataFloat(intercept::types::game_value value)
{
	game_data* GameDataPointer = value.data.get();

	//number/float
	if (value.type() == game_data_number::type_def)
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

 __declspec(dllexport) int GetDataInt(intercept::types::game_value value)
{
	return static_cast<int>(GetDataFloat(value));
}

 __declspec(dllexport) bool GetDataBool(intercept::types::game_value value)
{
	game_data* GameDataPointer = value.data.get();

	//bool
	if (value.type() == game_data_bool::type_def)
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

 __declspec(dllexport) vector2 GetDataVector2(intercept::types::game_value value)
{
	game_data* GameDataPointer = value.data.get();

	if (value.type() == game_data_array::type_def && value.size() == 2)
	{
		vector2 temp = value;
		return temp;
	}
	else
	{
		
		return vector2();
	}
}

 __declspec(dllexport) vector3 GetDataVector3(intercept::types::game_value value)
{
	game_data* GameDataPointer = value.data.get();

	if (value.type() == game_data_array::type_def && value.size() == 3)
	{
		vector3 temp = value;
		return temp;
	}
	else
	{
		return vector3();
	}
}

 __declspec(dllexport) game_value GetElementFromArray(intercept::types::game_value array, int index)
{
	if (array.type() != game_data_array::type_def)
	{
		// do this nasty thing
		return array;
	}

	if (array.size() < index)
	{
		return array;
	}

	return array[index];
}