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
		
		void OpenFile();
		void CreateNewFile();
		void DeleteSFile();
		void RenameFile();
		void MoveFileToAnotherDirectory();
		void WritePath();
		void FileLists(std::vector<std::string>& current_files_list, std::string curr_path);

		std::string GetPath() { return current_path; }

	private:
		std::string current_path = "C:\\";
		bool IsPathValid(const std::string& path);
	};
}

