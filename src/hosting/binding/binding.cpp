#include "binding.hpp"

Bindings::Bindings(string_t& assemblyName, string_t assemblyStaticClassName, std::filesystem::path& assemblyPath, load_assembly_and_get_function_pointer_fn functionPointer) : _assemblyName{ std::move(assemblyName) }, _assemblyStaticClassName{ std::move(assemblyStaticClassName) }
{
    _assemblyPath.clear();
    // check that the path exists
    assemblyPath.append(_assemblyName + STR(".dll"));
    if (std::filesystem::exists(assemblyPath))
    {
        _assemblyPath = std::filesystem::canonical(assemblyPath);
        std::wcout << _assemblyPath << STR("\n");
    }


    if (_assemblyPath.empty())
    {
        std::cout << "Path is empty\n";
    }

    _load_assembly_and_get_function_pointer = std::move(functionPointer);
}