#include <intercept.hpp>
#include "commands/commands.hpp"

#include <windows.h>
#include "hosting/nethostfxr/nethostfxr.hpp"

#include <filesystem>


// keep this global, so commands can't go out of scope.
Commands& commands = Commands::get();

void createConsole()
{
    AllocConsole();
    FILE* fp = new FILE();
    freopen_s(&fp, "CONOUT$", "w", stdout);
}

int intercept::api_version() { //This is required for the plugin to work.
    return INTERCEPT_SDK_API_VERSION;
}

void intercept::register_interfaces() {
    
}

void intercept::pre_start() {

    createConsole();
    string_t assemblyName{STR("arma_code")};
    string_t assemblyClassName{ STR("Printer") };
    std::filesystem::path path{ STR("E:/SteamLibrary/steamapps/common/Arma 3/@rvcss/assembly/") };
    Nethostfxr host{ assemblyName, assemblyClassName,  path };
    auto hello = host.get_function_pointer<void(CORECLR_DELEGATE_CALLTYPE*)(void)>({STR("EntryLocation")});
    hello();

}

void intercept::pre_init() {
    intercept::sqf::system_chat("The Intercept template plugin is running!");
}