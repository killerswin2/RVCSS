#include <intercept.hpp>
#include "commands/commands.hpp"

//#include "hosting/nethostfxr/nethostfxr.hpp"
#include "CSharp/GameDataCSharp.hpp"

game_value testFunction();

// keep this global, so commands can't go out of scope.
Commands& commands = Commands::get();
//Nethostfxr host;

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
    rvcss::hosting::pre_start();
    //string_t assemblyName{STR("arma_code")};
    //string_t assemblyClassName{ STR("Printer") };
    //std::filesystem::path path{ STR("@rvcss/assembly/") };
    //host = Nethostfxr{ assemblyName, assemblyClassName,  path };
   
    //commands.addCommand("callFunction", "testFunction for C#", userFunctionWrapper<testFunction>, game_data_type::NOTHING);
}

void intercept::post_init()
{
    
}

void intercept::pre_init() {
    intercept::sqf::system_chat("The Intercept template plugin is running!");
}

game_value testFunction()
{
    //auto hello = host.get_function_pointer<void(CORECLR_DELEGATE_CALLTYPE*)(void)>(STR("EntryLocation"), STR("CustomEntryPointDelegate"));
    //hello();
    return {};
}

