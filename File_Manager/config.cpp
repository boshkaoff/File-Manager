#include "config.h"  

void cfg::Config::Add_Command(std::wstring command_name, std::wstring custom_command)
{
    std::wstring keyToFind = custom_command;
    auto it = custom_commands_list.find(keyToFind);

    if (it != custom_commands_list.end()) {
        std::wcout << L"- You have already this command\n";
    }
    else {
        custom_commands_list[custom_command] = command_name;
    }
}
