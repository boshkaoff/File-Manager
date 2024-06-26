#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <filesystem>
#include <windows.h>
#include <fstream>
#include <locale>
#include <codecvt>

namespace F_LOGIC {

	class FilesLogic
	{
	public:
		void OpenFile(const std::wstring program_name) const;
		void CreateNewFile(const std::wstring program_name) const;
		void DeleteSFile(const std::wstring program_name);
		void WritePath(std::wstring temp);
		void ShowFileList(std::wstring curr_path);
		void RenameFile(const std::wstring program_name, const std::wstring new_program_name);
		void MoveFileToAnotherDirectory(const std::wstring program_name, std::wstring new_path);
		void FileLists(std::vector<std::wstring>& current_files_list, std::wstring curr_path);

		std::wstring GetPath() { return current_path; }

	private:
		std::vector<std::wstring> current_files_list;
		std::wstring current_path = L"C:\\";
	};
}