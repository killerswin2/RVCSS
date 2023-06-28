#include "Tests.hpp"
#include <catch2/catch_session.hpp>

void runAllTests()
{
	int argc = 1;
	char* argv[10] = { "arma3" };
	Catch::Session().run(argc, argv);
}


#include <intercept.hpp>

static auto_array<game_value> testAutoArray;

TEST_CASE("Checking the size of auto_array<game_value>", "[auto_array<game_value>]")
{
	REQUIRE(sizeof(auto_array<game_value>) == 24);
}

TEST_CASE("Checking game_data info", "[game_data]")
{
	REQUIRE(sizeof(game_data) == 24);
	REQUIRE(offsetof(game_data, _refcount) == 8);
}

TEST_CASE("Checking game_data_array info", "[game_data_array]")
{
	REQUIRE(sizeof(game_data_array) == 48);
	REQUIRE(offsetof(game_data_array,_refcount) == 8);
	REQUIRE(offsetof(game_data_array, data) == 24);
}

TEST_CASE("Checking game_data_bool info", "[game_data_bool]")
{
	REQUIRE(sizeof(game_data_bool) == 32);
	REQUIRE(offsetof(game_data_bool, _refcount) == 8);
	REQUIRE(offsetof(game_data_bool, val) == 24);
}

TEST_CASE("Checking game_data_code info", "[game_data_code]")
{
	REQUIRE(sizeof(game_data_code) == 64);
	REQUIRE(offsetof(game_data_code, _refcount) == 8);
	REQUIRE(offsetof(game_data_code, code_string) == 24);
	REQUIRE(offsetof(game_data_code, instructions) == 32);
	REQUIRE(offsetof(game_data_code, is_final) == 56);
}

TEST_CASE("Checking game_data_config info", "[game_data_config]")
{
	REQUIRE(sizeof(game_data_config) == 56);
	REQUIRE(offsetof(game_data_config, _refcount) == 8);
	REQUIRE(offsetof(game_data_config, config) == 24);
	REQUIRE(offsetof(game_data_config, path) == 32);
}

TEST_CASE("Checking game_data_control info", "[game_data_control]")
{
	REQUIRE(sizeof(game_data_control) == 32);
	REQUIRE(offsetof(game_data_control, _refcount) == 8);
	REQUIRE(offsetof(game_data_control, control) == 24);
}

TEST_CASE("Checking game_data_display info", "[game_data_display]")
{
	REQUIRE(sizeof(game_data_display) == 32);
	REQUIRE(offsetof(game_data_display, _refcount) == 8);
	REQUIRE(offsetof(game_data_display, display) == 24);
}

TEST_CASE("Checking game_data_group info", "[game_data_group]")
{
	REQUIRE(sizeof(game_data_group) == 32);
	REQUIRE(offsetof(game_data_group, _refcount) == 8);
	REQUIRE(offsetof(game_data_group, group) == 24);
}

TEST_CASE("Checking game_data_hashmap info", "[game_data_hashmap]")
{
	REQUIRE(sizeof(game_data_hashmap) == 40);
	REQUIRE(offsetof(game_data_hashmap, _refcount) == 8);
	REQUIRE(offsetof(game_data_hashmap, data) == 24);
}

TEST_CASE("Checking game_data_location info", "[game_data_location]")
{
	REQUIRE(sizeof(game_data_location) == 32);
	REQUIRE(offsetof(game_data_location, _refcount) == 8);
	REQUIRE(offsetof(game_data_location, location) == 24);
}

TEST_CASE("Checking game_data_namespace info", "[game_data_namespace]")
{
	REQUIRE(sizeof(game_data_namespace) == 64);
	REQUIRE(offsetof(game_data_namespace, _refcount) == 8);
	REQUIRE(offsetof(game_data_namespace, _variables) == 32);
	REQUIRE(offsetof(game_data_namespace, _name) == 48);
	REQUIRE(offsetof(game_data_namespace, _1) == 56);
}

TEST_CASE("Checking game_data_nothing info", "[game_data_nothing]")
{
	REQUIRE(sizeof(game_data_nothing) == 24);
	REQUIRE(offsetof(game_data_nothing, _refcount) == 8);
}

TEST_CASE("Checking game_data_number info", "[game_data_number]")
{
	REQUIRE(sizeof(game_data_number) == 32);
	REQUIRE(offsetof(game_data_number, _refcount) == 8);
	REQUIRE(offsetof(game_data_number, number) == 24);
}

TEST_CASE("Checking game_data_object info", "[game_data_object]")
{
	REQUIRE(sizeof(game_data_object) == 32);
	REQUIRE(offsetof(game_data_object, _refcount) == 8);
	REQUIRE(offsetof(game_data_object, object) == 24);
}

TEST_CASE("Checking game_data_rv_text info", "[game_data_rv_text]")
{
	REQUIRE(sizeof(game_data_rv_text) == 32);
	REQUIRE(offsetof(game_data_rv_text, _refcount) == 8);
	REQUIRE(offsetof(game_data_rv_text, rv_text) == 24);
}

TEST_CASE("Checking game_data_script info", "[game_data_script]")
{
	REQUIRE(sizeof(game_data_script) == 32);
	REQUIRE(offsetof(game_data_script, _refcount) == 8);
	REQUIRE(offsetof(game_data_script, script) == 24);
}

TEST_CASE("Checking game_data_side info", "[game_data_side]")
{
	REQUIRE(sizeof(game_data_side) == 32);
	REQUIRE(offsetof(game_data_side, _refcount) == 8);
	REQUIRE(offsetof(game_data_side, side) == 24);
}

TEST_CASE("Checking game_data_string info", "[game_data_string]")
{
	REQUIRE(sizeof(game_data_string) == 32);
	REQUIRE(offsetof(game_data_string, _refcount) == 8);
	REQUIRE(offsetof(game_data_string, raw_string) == 24);
}

TEST_CASE("Checking game_data_team_member info", "[game_data_team_member]")
{
	REQUIRE(sizeof(game_data_team_member) == 32);
	REQUIRE(offsetof(game_data_team_member, _refcount) == 8);
	REQUIRE(offsetof(game_data_team_member, team) == 24);
}