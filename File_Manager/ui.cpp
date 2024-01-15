#include "ui.h"

void UI::uiClass::HelloPrint(std::string curr_path)
{
    std::cout << welcome_str + "Your current directory is : \"" + curr_path + "\"\n";
    std::cout << "Type a command" + help_str + ": ";
    if (welcome) { welcome_str = ""; help_str = ""; welcome = false; }
}

void UI::uiClass::ShowFileList(std::string curr_path)
{
    filesLogic::FileLists(current_files_list, curr_path);
    int file_num = 0;
    for (auto& i : current_files_list)
    {
        std::cout << " -| " + file_num << " | " + i << std::endl;
        file_num++;
    }
}
