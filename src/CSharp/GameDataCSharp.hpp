#pragma once

#include <intercept.hpp>
#include <string_view>

#include "../hosting/nethostfxr/nethostfxr.hpp"
#include "../commands/commands.hpp"

namespace rvcss
{
	class hosting
	{
	public:
		static void pre_start();
	};
}

class game_data_c_sharp: public game_data
{
public:
	game_data_c_sharp(){}
	game_data_c_sharp(string_t& assemblyName, string_t& assemblyClassName, std::filesystem::path& configPath) {
		_host = Nethostfxr{ assemblyName, assemblyClassName, configPath };
	}
	void lastRefDeleted() const override { delete this; }
	const sqf_script_type& type() const override;
	~game_data_c_sharp() override {};

	bool get_as_bool() const override { return true; };
	float get_as_number() const override { return 0.f; }
	const r_string& get_as_string() const override { static r_string nm("CSharp"sv); return nm; }
	game_data* copy() const override { return new game_data_c_sharp(*this); }
	r_string to_string() const override { return r_string("CSharp"sv); }
	const char* type_as_string() const override { return "CSharp"; }
	bool is_nil() const override { return false; }
	bool can_serialize() override { return true; }
	serialization_return serialize(param_archive& ar) override;

	Nethostfxr _host;

};