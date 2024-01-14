#pragma once
#include <iostream>
#include <string>
#include "ui.h"
#include "files_logic.h"
#include <vector>

namespace APP {

	class MainApp : public UI::uiClass, public F_LOGIC::filesLogic {
	public:
		void Run() { Start(); }
		bool Is_Running() {	return is_enabled; }
		void Exit() { is_enabled = false; }
		void MainFunc(int command);

		int processCommands(std::string commmand_line);
		int processArg(std::string commmand_line, int iteration, int arg_num);

	private:

		int state = 0;
		std::string current_path = "C:\\";
		bool is_enabled = true;
		void Start();

		std::string command, arg1, arg2;

		std::vector<std::string> command_list{
			"open",
			"create",
			"delete",
			"cpath",
			"move",
			"rename",
			"exit"
		};
	};
}