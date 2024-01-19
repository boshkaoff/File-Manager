#pragma once
#include <string>
#include <map>
#include <iostream>

namespace cfg {

	void FindConfigs();


	class config {
	public:
		config(std::wstring name) : language("US-en"), config_name(name) {}
		
		void SetLanguage(std::string language) { this->language = language; }
		std::string GetLanguage() const { return language; }
		void Add_Command(std::wstring command_name, std::wstring custom_command);
		std::map<std::wstring, std::wstring> Get_Commands() { return custom_commands_list; }

	private:
		std::wstring config_name;
		std::string language;
		std::map<std::wstring, std::wstring> custom_commands_list;
	};



}