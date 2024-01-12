#include "ui.h"

int UI::uiClass::CallMainUI(std::string curr_path)
{
    int state;
    std::string input;

    std::cout << " _______________________________\n| " << std::endl;
    std::cout << "| What do you want to do?        " << std::endl;
    std::cout << "| You are now in '" << curr_path << "'" << std::endl;
    std::cout << "|_______________________________ " << std::endl;
    F_LOGIC::filesLogic::FileLists(current_files_list, curr_path);

    int file_num = 0;
    for (auto& i : current_files_list)
    {
        std::cout << file_num << " | " << i << std::endl;
        file_num++;
    }
    CommandList();
    std::cin >> input;

    try {
        state = std::stoi(input); // str to int
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid input. Please enter a number." << std::endl;
        state = 0;
    }

    return state;
}

void UI::uiClass::CommandList()
{
    std::cout << " __________________________" << std::endl;
    std::cout << "|   Available Commands     |" << std::endl;
    std::cout << "|--------------------------|" << std::endl;
    std::cout << "| 1 | Open File            |" << std::endl;
    std::cout << "| 2 | Create File          |" << std::endl;
    std::cout << "| 3 | Delete File          |" << std::endl;
    std::cout << "| 4 | Rename File          |" << std::endl;
    std::cout << "| 5 | Move File            |" << std::endl;
    std::cout << "| 6 | Write Path           |" << std::endl;
    std::cout << "| 7 | Exit                 |" << std::endl;
    std::cout << " --------------------------" << std::endl;
}
