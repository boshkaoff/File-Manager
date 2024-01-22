#include "ui.h"

void UI::uiClass::HelloPrint(std::wstring curr_path)
{

    int requiredSize = WideCharToMultiByte(CP_UTF8, 0, curr_path.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string file_name(requiredSize, 0);
    WideCharToMultiByte(CP_UTF8, 0, curr_path.c_str(), -1, &file_name[0], requiredSize, nullptr, nullptr);
    std::wcout << welcome_str + L"Your current directory is : \"" << file_name.c_str() << L"\"\n";
    std::wcout << L"Type a command" + help_str + L": ";
    if (welcome) { welcome_str = L""; help_str = L""; welcome = false; }
}
