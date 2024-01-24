#pragma once
#include <iostream>
#include <string>
#include "ui.h"
#include "files_logic.h"
#include <vector>
#include <conio.h>
#include "config.h"
#include "Windows.h"


enum class cmd_n
{
	Open,
	Create,
	Delete,
	Path,
	Move,
	Rename,
	ShowF,
	HelpEn,
	Exit,
	Clear,
	Invalid
};

namespace APP {

	void CleanBuffer();

	class MainApp : public UI::uiClass, public F_LOGIC::FilesLogic {
	public:

		MainApp() : state(cmd_n::Invalid), current_path(L"C:\\"), is_enabled(true), key(L' ') {}

		void Run() { Start(); }
		bool Is_Running() const { return is_enabled; }
		void Exit() { is_enabled = false; }
		void MainFunc(cmd_n command);
		void Help();
		void InitilizeConfig(std::wstring config_file_name = L"default");

		cmd_n processCommands(std::wstring commmand_line);
		int processArg(std::wstring commmand_line, int iteration, int arg_num);

	private:

		cmd_n state;
		std::wstring current_path;
		bool is_enabled;
		wchar_t key;
		bool USED_CONFIG_INITIALIZATION = false;

		cfg::Config configuration;

		void Start();

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