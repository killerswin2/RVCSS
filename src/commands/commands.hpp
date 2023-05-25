#pragma once
#include <vector>
#include <intercept.hpp>


class Commands
{
private:
	std::vector<intercept::types::registered_sqf_function> m_addedCommands;
	Commands() {};
	static Commands s_Instance;

public:
	~Commands();
	Commands& operator=(const Commands&) = delete;
	Commands(const Commands&) = delete;
	static Commands& get()
	{
		return s_Instance;
	}

	void addCommand(std::string_view name, std::string_view description, intercept::types::nular_function function_, game_data_type return_arg_type);
	void addCommand(std::string_view name, std::string_view description, intercept::types::unary_function function_, game_data_type return_arg_type, game_data_type right_arg_type);
	void addCommand(std::string_view name, std::string_view description, intercept::types::binary_function function_, game_data_type return_arg_type, game_data_type left_arg_type, game_data_type right_arg_type);
};