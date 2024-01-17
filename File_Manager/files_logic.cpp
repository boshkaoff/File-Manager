#include "files_logic.h"

static bool IsPathValid(const std::wstring& path)
{
    return std::filesystem::exists(path);
}

void F_LOGIC::FilesLogic::OpenFile(const std::wstring program_name) const
{
    // file path correction
    std::wstring file_path = current_path + L"\\" + program_name;
    std::replace(file_path.begin(), file_path.end(), L'\\', L'/');

    if (!std::filesystem::exists(file_path) && !std::filesystem::is_regular_file(file_path))
    {
        std::wcerr << L"- File does not exist or is not a regular file: " << file_path << std::endl;
        return;
    }

    auto file_status = std::filesystem::status(file_path);
    if ((file_status.permissions() & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) {
        HINSTANCE result = ShellExecuteW(nullptr, L"open", file_path.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

        if (reinterpret_cast<uintptr_t>(result) > 32) {
            std::wcout << L"- App launched successfully." << std::endl;
        }
        else {
            std::wcerr << L"- Failed with error code: " << reinterpret_cast<uintptr_t>(result) << std::endl;
        }
    }
    else {
        std::wcerr << L"- File is not executable: " << file_path << std::endl;
    }
}

void F_LOGIC::FilesLogic::CreateNewFile(const std::wstring program_name) const
{
    // file path correction
    std::wstring file_path = current_path + L"\\" + program_name;
    std::replace(file_path.begin(), file_path.end(), L'\\', L'/');

    // file creation here
    std::wofstream file(file_path);

    // check file
    if (file.is_open()) {
        file.close();
        std::wcout << L"- File created successfully.\n";
    }
    else {
        std::wcerr << L"- Failed to create file.\n";
    }
}

void F_LOGIC::FilesLogic::DeleteSFile(const std::wstring program_name)
{
    // file path correction
    std::wstring file_path = current_path + L"\\" + program_name;
    if (!std::filesystem::exists(file_path)) { std::wcout << L"- This file doesn't exist!"; return; }

    // check if user is sure want to delete file
    std::wcout << L"- Are you sure want to delete file: " + program_name << std::endl;
    std::wcout << L"- In path: " + file_path << std::endl;
    bool check;
    std::wcin >> check;

    if (!check) { return; }
    try {
        // Try to delete the file
        std::filesystem::remove(file_path);
        std::wcout << L"- File deleted.\n";
    }
    catch (const std::filesystem::filesystem_error& e) {
        // In case of an error, display a message
        std::wcerr << L"- Error: " << e.what() << std::endl;
    }
}

void F_LOGIC::FilesLogic::RenameFile(const std::wstring program_name, const std::wstring new_program_name)
{
    std::wstring file_path = current_path + L"\\" + program_name;
    if (!std::filesystem::exists(file_path)) { std::wcout << L"- This file doesn't exist!\n"; return; }
    std::wstring new_file_path = current_path + L"\\" + new_program_name;

    try {
        // Try to rename
        std::filesystem::rename(file_path, new_file_path);
        std::wcout << L"- Done" << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::wcerr << L"- " << e.what() << std::endl;
    }
}

void F_LOGIC::FilesLogic::MoveFileToAnotherDirectory(const std::wstring program_name, std::wstring new_path)
{
    std::wstring file_path = current_path + L"\\" + program_name;
    if (!std::filesystem::exists(file_path)) { std::wcout << L"- This file doesn't exist!\n"; return; }
    if (!IsPathValid(new_path)) { std::wcerr << L"- This path doesn't exist!\n"; }
    std::wstring new_file_path = new_path + L"\\" + program_name;

    try {
        // Try to rename
        std::filesystem::rename(file_path, new_file_path);
        std::wcout << L"- Done\n";
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::wcerr << L"- " << e.what() << std::endl;
    }
}

void F_LOGIC::FilesLogic::WritePath(const std::wstring temp)
{
    // Checking if the path is OK
    std::filesystem::path cleanedPath = std::filesystem::path(temp).lexically_normal();
    if (IsPathValid(cleanedPath.wstring())) {
        this->current_path = cleanedPath.wstring();
        std::wcout << L"- Done!\n";
    }
    else {
        std::wcerr << L"- Incorrect Path!!\n";
    }
}

void F_LOGIC::FilesLogic::FileLists(std::vector<std::wstring>& current_files_list, std::wstring curr_path)
{
    if (!current_files_list.empty())
    {
        current_files_list.clear();
    }
    try {
        for (const auto& entry : std::filesystem::directory_iterator(curr_path)) {
            current_files_list.push_back(entry.path().filename().wstring());
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::wcerr << L"- Error accessing directory: " << e.what() << std::endl;
    }
}

void F_LOGIC::FilesLogic::ShowFileList(std::wstring curr_path)
{
    FilesLogic::FileLists(current_files_list, curr_path);
    int file_num = 0;

    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);

    std::wcout << L"_______________ Files In Current Path _______________\n";
    for (auto& i : current_files_list)
    {
        int requiredSize = WideCharToMultiByte(CP_UTF8, 0, i.c_str(), -1, nullptr, 0, nullptr, nullptr);
        std::string utf8String(requiredSize, 0);
        WideCharToMultiByte(CP_UTF8, 0, i.c_str(), -1, &utf8String[0], requiredSize, nullptr, nullptr);

        std::wcout << L"- | " << utf8String.c_str() << std::endl;
        file_num++;
    }
    std::wcout << L"_____________________________________________________\n";
}