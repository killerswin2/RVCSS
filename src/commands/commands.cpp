#include "commands.hpp"

Commands::~Commands()
{
}


/*
 * @brief registers a sqf nular cmd in intercept
 * @author Killerswin2
 * @param name std::string_view name of sqf cmd
 * @param description std::string_view description of what the cmd does
 * @param function intercept::types::nular_function pointer to function to call
 * @param return_arg_type game_data_type return type for function pointer
 * @see intercept::client::host::register_sqf_command for intercept function
 */
void Commands::addCommand(std::string_view name, std::string_view description, intercept::types::nular_function function, game_data_type return_arg_type)
{
	m_addedCommands.push_back(intercept::client::host::register_sqf_command(name, description, function, return_arg_type));
}

/*
 * @brief registers a sqf unary cmd in intercept
 * @author Killerswin2
 * @param name std::string_view name of sqf cmd
 * @param description std::string_view description of what the cmd does
 * @param function intercept::types::nular_function pointer to function to call
 * @param return_arg_type game_data_type return type for function pointer
 * @param right_arg_type game_data_type data called to the function pointer for right side
 * @see intercept::client::host::register_sqf_command for intercept function
 */
void Commands::addCommand(std::string_view name, std::string_view description, intercept::types::unary_function function, game_data_type return_arg_type, game_data_type right_arg_type)
{
	m_addedCommands.push_back(intercept::client::host::register_sqf_command(name, description, function, return_arg_type, right_arg_type));
}

/*
 * @brief registers a sqf binary cmd in intercept
 * @author Killerswin2
 * @param name std::string_view name of sqf cmd
 * @param description std::string_view description of what the cmd does
 * @param function intercept::types::nular_function pointer to function to call
 * @param return_arg_type game_data_type return type for function pointer
 * @param left_arg_type game_data_type data called to the function pointer for left side
 * @param right_arg_type game_data_type data called to the function pointer for right side
 * @see intercept::client::host::register_sqf_command for intercept function
 */
void Commands::addCommand(std::string_view name, std::string_view description, intercept::types::binary_function function, game_data_type return_arg_type, game_data_type left_arg_type, game_data_type right_arg_type)
{
	m_addedCommands.push_back(intercept::client::host::register_sqf_command(name, description, function, return_arg_type, left_arg_type, right_arg_type));
}

/*
 * @brief Commands singleton instance
 */
Commands Commands::s_Instance;
