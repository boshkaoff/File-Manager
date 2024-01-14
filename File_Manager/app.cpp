#include "app.h"

void CleanBuffer()
{
    while (std::cin.peek() == '\n')
        std::cin.ignore();
}

void APP::MainApp::Start()
{
	current_path = F_LOGIC::filesLogic::GetPath();
    std::cout << "WriteUrCommand IF YOUR PATH OR NAME HAS BACKSPASES WRITE IT IN COVICHKI: ";
    std::getline(std::cin, command);
    state = processCommands(command);
	if (state == 7) { Exit(); std::cout << "Bye!"; return; }
    MainFunc(state);
	state = 0;
}

void APP::MainApp::MainFunc(int command)
{
    switch (command) {
    case Open:
        filesLogic::OpenFile(arg1);
        break;
    case Create:
        filesLogic::CreateNewFile(arg1);
        break;
    case Delete:
        filesLogic::DeleteSFile(arg1);
        break;
    case Path:
        filesLogic::WritePath(arg1);
        break;
    case Move:
        filesLogic::MoveFileToAnotherDirectory(arg1, arg2);
        break;
    case Rename:
        filesLogic::RenameFile(arg1, arg2);
        break;
    default:
        std::cout << "Invalid command!" << std::endl;
        break;
    }
}

int APP::MainApp::processCommands(std::string command_line)
{
    std::istringstream check(command_line);

    check >> command;
    bool is_exist = false;
    int i = 0;
    for (auto command_from_list : command_list)
    {
        if (command_from_list == command)
        {
            is_exist = true;
            break;
        }
        i++;
    }
    if (!is_exist) { return -1; }

    bool quotes = false;

    for (auto d : command_line)
    {
        if (d == '\"') {
            int iterator_for = 0;
            processArg(command_line, iterator_for, 0);
            processArg(command_line, iterator_for, 1);
            quotes = true;
            return i;
        }
    }

    check >> arg1 >> arg2;

    return i;
}

int APP::MainApp::processArg(std::string commmand_line, int iteration, int arg_num)
{
    std::string cleaned_arg;
    bool started_quotes = false;
    int twise = 0;
    for (size_t iterator_for_arg = 0; iterator_for_arg < commmand_line.size(); iterator_for_arg++)
    {
        if (twise == 2) { break; }
        if (commmand_line[iterator_for_arg] == '\"')
        {
            started_quotes = !started_quotes;
            twise++;
            continue;
        }

        if (started_quotes)
        {
            cleaned_arg.push_back(commmand_line[iterator_for_arg]);
        }
    }

    if (arg_num == 0) 
        arg1 = cleaned_arg;
    else
        arg2 = cleaned_arg;

    return iteration;
}


//if (i < 4)
//{
//    check >> arg1;
//    arg2 = "";
//    break;
//}
//else
//{
//    check >> arg1 >> arg2;
//    break;
//}