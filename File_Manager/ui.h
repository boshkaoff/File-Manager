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
		

		void CommandList();
		int CallMainUI(std::string curr_path);
	};
}
