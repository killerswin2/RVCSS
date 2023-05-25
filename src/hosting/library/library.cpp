#include "library.hpp"


#ifdef _WIN32
void Library::load_library()
{
    if (std::filesystem::exists(_path))
    {
        HMODULE h = ::LoadLibraryW(_path.c_str());
        assert(h != nullptr);
        _library = h;
    }
}
#else
void Library::load_library()
{
    if (std::filesystem::exists(_path))
    {
        void* h = dlopen(_path.c_str(), RTLD_LAZY | RTLD_LOCAL);
        assert(h != nullptr);
        _library = h;
    }
}
#endif