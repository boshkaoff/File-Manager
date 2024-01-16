#pragma once
#include <iostream>
#include <string>
#include "ui.h"
#include "files_logic.h"
#include <vector>
#include <conio.h>

namespace APP {

	void CleanBuffer();

	class MainApp : public UI::uiClass, public F_LOGIC::FilesLogic {
	public:
		void Run() { Start(); }
		bool Is_Running() const { return is_enabled; }
		void Exit() { is_enabled = false; }
		void MainFunc(int command);
		void Help();

		int processCommands(std::wstring commmand_line);
		int processArg(std::wstring commmand_line, int iteration, int arg_num);

	private:

		int state = 0;
		std::wstring current_path = L"C:\\";
		bool is_enabled = true;
		void Start();
		wchar_t key = L' ';

		std::wstring command, arg1, arg2;

		std::vector<std::wstring> command_list{
			L"/open",
			L"/create",
			L"/delete",
			L"/cpath",
			L"/move",
			L"/rename",
			L"/showf",
			L"/help",
			L"/exit",
			L"/clear"
		};

		std::vector<std::wstring> command_usage{
			L"/open \"file name\"",
			L"/create \"file name\"",
			L"/delete \"file name\"",
			L"/cpath \"path name\"",
			L"/move \"file name\" \"new path name\"",
			L"/rename \"file name\" \"new file name\"",
			L"/showf",
			L"/help",
			L"/exit",
			L"/clear"
		};

		std::vector<std::wstring> command_desc{
			L"open a file",
			L"create a file",
			L"delete a file",
			L"change current path",
			L"move file to another path",
			L"rename file",
			L"show all files in current directory",
			L"shows all commands",
			L"exit from program",
			L"clear console output"
		};
	};
}