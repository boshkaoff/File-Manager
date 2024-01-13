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
	Open = 1,
	Create = 2,
	Delete = 3,
	Rename = 4,
	Move = 5,
	Path = 6,
	Exit = 7
};

namespace F_LOGIC {


	class filesLogic
	{
	public:

		void CallMainFL(int Command);
		
		void OpenFile(const std::string program_name);
		void CreateNewFile(const std::string program_name);
		void DeleteSFile(const std::string program_name);
		void RenameFile(const std::string program_name, const std::string new_program_name);
		void MoveFileToAnotherDirectory(const std::string program_name, std::string new_path);
		void WritePath(std::string temp);
		void FileLists(std::vector<std::string>& current_files_list, std::string curr_path);

		std::string GetPath() { return current_path; }

	private:
		std::string current_path = "C:\\";
	};
}

