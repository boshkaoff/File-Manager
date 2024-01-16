#include "ui.h"

void UI::uiClass::HelloPrint(std::wstring curr_path)
{
    std::wcout << welcome_str + L"Your current directory is : \"" + curr_path + L"\"\n";
    std::wcout << L"Type a command" + help_str + L": ";
    if (welcome) { welcome_str = L""; help_str = L""; welcome = false; }
}
