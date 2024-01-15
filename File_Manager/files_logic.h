#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <filesystem>
#include <windows.h>
#include <fstream>

enum FILE_COMMANDS
{
	Open = 0,
	Create = 1,
	Delete = 2,
	Path = 3,
	Move = 4,
	Rename = 5,
	ShowF = 6,
	HelpEn = 7,
	Clear = 9
};

namespace F_LOGIC {


	class filesLogic
	{
	public:
		
		void OpenFile(const std::string program_name) const;
		void CreateNewFile(const std::string program_name) const;
		void DeleteSFile(const std::string program_name);
		void WritePath(std::string temp);
		void ShowFileList(std::wstring curr_path);
		void RenameFile(const std::string program_name, const std::string new_program_name);
		void MoveFileToAnotherDirectory(const std::string program_name, std::string new_path);
		void FileLists(std::vector<std::wstring>& current_files_list, std::wstring curr_path);

		std::string GetPath() { return current_path; }

	private:
		std::vector<std::wstring> current_files_list;
		std::string current_path = "C:\\";
	
	};
}

