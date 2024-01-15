#include "app.h"

void CleanBuffer()
{
    while (std::wcin.peek() == L'\n')
        std::wcin.ignore();
}

void APP::MainApp::Start()
{
    current_path = FilesLogic::GetPath();
    uiClass::HelloPrint(current_path);

    std::wstring command_line;
    std::getline(std::wcin, command_line);

    state = processCommands(command_line);

    if (state == 8)
    {
        Exit();
        std::wcout << L"Bye!" << std::endl;
        return;
    }

    MainFunc(state);
    state = 0;
}

void APP::MainApp::MainFunc(int command)
{
    switch (command) {
    case Open:
        FilesLogic::OpenFile(arg1);
        break;
    case Create:
        FilesLogic::CreateNewFile(arg1);
        break;
    case Delete:
        FilesLogic::DeleteSFile(arg1);
        break;
    case Path:
        FilesLogic::WritePath(arg1);
        break;
    case Move:
        FilesLogic::MoveFileToAnotherDirectory(arg1, arg2);
        break;
    case Rename:
        FilesLogic::RenameFile(arg1, arg2);
        break;
    case ShowF:
        FilesLogic::ShowFileList(current_path);
        break;
    case HelpEn:
        Help();
        break;
    case Clear:
        system("cls");
        break;
    default:
        std::wcout << L"- Invalid command!" << std::endl;
        break;
    }
}

void APP::MainApp::Help()
{
    for (size_t i = 0; i < command_list.size(); i++)
    {
        std::wcout << L"-\n";
        std::wcout << L"NAME: " + command_list[i] + L" | USAGE: " + command_usage[i] + L" | DESC: " + command_desc[i] << std::endl;
    }
    std::wcout << L"-\n";
}

int APP::MainApp::processCommands(std::wstring command_line)
{
    std::wistringstream check(command_line);

    if (command_line[0] != L'/') { return -1; }

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
        if (d == L'\"') {
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

int APP::MainApp::processArg(std::wstring commmand_line, int iteration, int arg_num)
{
    std::wstring cleaned_arg;
    bool started_quotes = false;
    int twise = 0;
    for (size_t iterator_for_arg = 0; iterator_for_arg < commmand_line.size(); iterator_for_arg++)
    {
        if (twise == 2) { break; }
        if (commmand_line[iterator_for_arg] == L'\"')
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