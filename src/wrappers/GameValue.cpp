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

using host = intercept::client::host;
using __sqf = intercept::client::__sqf;

static game_data* gameDataTestPointer = nullptr;
static game_value* gameValueTestPointer = nullptr;

void print_data(void* pointer, int length)
{
	unsigned char* tempPointer = reinterpret_cast<unsigned char*>(pointer);
	std::cout << "pointer printing\n";

	for (int i = 0; i < length; i++)
	{
		printf("%x", (unsigned char)tempPointer[i]);
	}

	std::cout << "\n";

}

__declspec(dllexport) void TestGameDataPointer(game_value instance)
{
	game_data* pointer = instance.data.get();
	if (pointer == nullptr)
	{
		std::cout << "Instance pointer is null\n";
		return;
	}

	// test ref count
	std::cout << "Instance ref count: "<< instance.data->_refcount <<"\n";
	std::cout << "Pointer ref count: " << pointer->_refcount << "\n";
	std::cout << "ref pointer points to: " << std::hex << pointer << "\n";
	//print_data(pointer, sizeof(game_data*));

	if (instance.type() == game_data_array::type_def)
	{
		for (int i = 0; i < instance.size(); i++)
		{
			std::cout << "index " << i << ": " << intercept::sqf::str(instance[i]) << "\n";
		}
	}
}

__declspec(dllexport) void TestGameAutoArray(auto_array<game_value> array)
{
	auto pointer = array.data();
	std::cout << " Array Pointer: " << std::hex << pointer << "\n";
	std::cout << " Test Pointer: " << std::hex << gameValueTestPointer << "\n";

	if (pointer != gameValueTestPointer)
	{
		std::cout << "Array pointer does not equal Test pointer!\n";
	}
	
	if (pointer == nullptr)
	{
		std::cout << "Array pointer is null\n";
		return;
	}

	print_data(pointer, sizeof(game_value) * array.size());

	game_value temp = array.get(0);
	if (temp.data.get() == nullptr)
	{
		std::cout << "data pointer is null\n";
	}

	std::cout << "Count: " << array.size() << "\n";
	for (int i = 0; i < array.size(); i++)
	{
		std::cout <<"index " << i << ": " << intercept::sqf::str(array[i]) << "\n";
	}
}

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
	std::cout << "game_data_number number: " << std::hex << reinterpret_cast<game_data_number*>(table)->number << "\n";
	gameDataTestPointer = temp.data.get();
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

__declspec(dllexport) game_value CreateGameValue(game_value* array, int length)
{
	auto temp = game_value(auto_array<game_value>(array, array + length));
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

 __declspec(dllexport) game_value CreateGameValue(game_data *data)
 {
	 auto temp = game_value(data);
	 temp.data->_refcount = 256;
	 return temp;
 }


 __declspec(dllexport) void DeleteGameValue(game_value instance)
 {
	 instance.~game_value();
 }

 // allocators
 __declspec(dllexport) void* Allocate(size_t size)
 {
	 auto temp = rv_allocator<char>::allocate(size);
	 gameValueTestPointer = reinterpret_cast<game_value*>(temp);
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

 __declspec(dllexport) game_value NearRoads(game_value pos, game_value radius)
 {
	 
	 return host::functions.invoke_raw_binary(__sqf::binary__nearroads__object_array__scalar__ret__array, pos, radius);
 }

 __declspec(dllexport) game_value NearestTerrainObjects(game_value right_arg)
 {
	 return host::functions.invoke_raw_unary(__sqf::unary__nearestterrainobjects__array__ret__array, right_arg);
 }


 