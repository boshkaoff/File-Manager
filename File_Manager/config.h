#pragma once
#include <string>
#include <map>
#include <iostream>

namespace cfg {

	class Config {
	public:
		
		Config() : language("US-en"), config_name("Default") {}
		
		void SetLanguage(const std::string& lang) { language = lang; }
		void SetConfigName(const std::string& name) { config_name = name; }

		std::string GetLanguage() const { return language; }
		void Add_Command(std::wstring command_name, std::wstring custom_command);
		std::map<std::wstring, std::wstring> Get_Commands() { return custom_commands_list; }

	private:
		std::string config_name;
		std::string language;
		std::map<std::wstring, std::wstring> custom_commands_list;
	public:

	};

}