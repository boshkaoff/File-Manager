#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "files_logic.h"

enum UI_STATES
{
	Base = 1,
	CreateUI = 2,
	DeleteUI = 3,
	RenameUI = 4,
	MoveUI = 5,
};

namespace UI {

	class uiClass : public F_LOGIC::filesLogic
	{
	public:
		std::vector<std::string> current_files_list;
		
		void HelloPrint(std::string curr_path);
		void ShowFileList(std::string curr_path);

	private:
		bool welcome = true;
		std::string welcome_str = "Welcome! ";
		std::string help_str = " (type '/help' for commands list)";
	};
}
