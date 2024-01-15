#include "ui.h"

void UI::uiClass::HelloPrint(std::wstring curr_path)
{
    std::wcout << welcome_str + L"Your current directory is : \"" + curr_path + L"\"\n";
    std::wcout << L"Type a command" + help_str + L": ";
    if (welcome) { welcome_str = L""; help_str = L""; welcome = false; }
}

void UI::uiClass::ShowFileList(std::wstring curr_path)
{
    FilesLogic::FileLists(current_files_list, curr_path);
    int file_num = 0;
    for (auto& i : current_files_list)
    {
        std::wcout << L" -| " + std::to_wstring(file_num) + L" | " + i << std::endl;
        file_num++;
    }
}