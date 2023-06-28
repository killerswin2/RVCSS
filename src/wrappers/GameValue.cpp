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
	if (gameDataTestPointer == nullptr)
	{
		std::cout << "Pointer is null\n";
		return;
	}

	if (gameDataTestPointer == pointer)
	{
		std::cout << "gameDataTestPointer is equal to Instance pointer\n";
		print_data(pointer, sizeof(game_data*));
		print_data(gameDataTestPointer, sizeof(game_data*));

	}
	if (instance.type() == game_data_array::type_def)
	{
		for (int i = 0; i < instance.size(); i++)
		{
			std::cout << "index " << i << ": " << intercept::sqf::str(instance[i]) << "\n";
		}
	}
	//okay now print out value;
	float number = reinterpret_cast<game_data_number*>(gameDataTestPointer)->number;
	std::cout << "Float from pointer value is: " << number << "\n";
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

	print_data(pointer, sizeof(game_value) * array.count());

	game_value temp = array.get(0);
	if (temp.data.get() == nullptr)
	{
		std::cout << "data pointer is null\n";
	}

	std::cout << "Count: " << array.count() << "\n";
	for (int i = 0; i < array.count(); i++)
	{
		std::cout <<"index " << i << ": " << intercept::sqf::str(array[i]) << "\n";
	}
}

__declspec(dllexport) auto_array<game_value> CreateAutoArray()
{
	return auto_array<game_value>();
}

__declspec(dllexport) game_value CreateGameValue()
{
	return game_value();
}

__declspec(dllexport) game_value CreateGameValue(float value)
{
	game_value temp = game_value(value);
	void* table = temp.data.get();
	std::cout << "game_data_number number: " << std::hex << reinterpret_cast<game_data_number*>(table)->number << "\n";
	gameDataTestPointer = temp.data.get();
	return temp;
}

 __declspec(dllexport) game_value CreateGameValue(bool value)
{
	return game_value(value);
}

 __declspec(dllexport) game_value CreateGameValue(const char* value)
{
	return game_value(value);
}

 __declspec(dllexport) game_value CreateGameValue(game_value* array, int length)
 {
	 return game_value(auto_array<game_value>(array, array + length));
 }

__declspec(dllexport) game_value CreateGameValue(auto_array<game_value> array)
{
	return game_value(array);
}

 __declspec(dllexport) game_value CreateGameValue(vector2 value)
{
	return game_value(value);
}

 __declspec(dllexport) game_value CreateGameValue(vector3 value)
{
	return game_value(value);
}

 __declspec(dllexport) game_value CreateGameValue(game_data *data)
 {
	 return game_value(data);
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


 