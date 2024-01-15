#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "files_logic.h"

enum UI_STATES
{
    Base = 1,
    CreateUI = 2,
    DeleteUI = 3,
    RenameUI = 4,
    MoveUI = 5,
};

namespace UI {

    class uiClass : public F_LOGIC::FilesLogic
    {
    public:
        std::vector<std::wstring> current_files_list;

        void HelloPrint(std::wstring curr_path);
        void ShowFileList(std::wstring curr_path);

    private:
        bool welcome = true;
        std::wstring welcome_str = L"Welcome! ";
        std::wstring help_str = L" (type '/help' for commands list)";
    };
}