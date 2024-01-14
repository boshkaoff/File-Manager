#include "ui.h"

void UI::uiClass::HelloPrint(std::string curr_path)
{
    std::cout << "Welcome! Your current directory is: \"" + curr_path + "\"\n";
    std::cout << "Type a command (type '/help' for commands list): ";
}

void UI::uiClass::ShowFileList(std::string curr_path)
{
    filesLogic::FileLists(current_files_list, curr_path);
    int file_num = 0;
    for (auto& i : current_files_list)
    {
        std::cout << file_num << " | " << i << std::endl;
        file_num++;
    }
}
