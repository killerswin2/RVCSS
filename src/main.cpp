#include <intercept.hpp>
#include "commands/commands.hpp"
#include "CSharp/GameDataCSharp.hpp"

#if UNIT_TESTING_BUILD
#include "Tests/Tests.hpp"
#endif

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
#if UNIT_TESTING_BUILD
    //runAllTests();
#endif
    rvcss::hosting::pre_start();
}

void intercept::post_init()
{
    
}

void intercept::pre_init() {
    intercept::sqf::system_chat("The Intercept template plugin is running!");
}


