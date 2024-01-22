#include "app.h"

// cleans buffer to get std::cin more correctly and without bugs
void APP::CleanBuffer()
{
    while (std::wcin.peek() == L'\n')
        std::wcin.ignore();
}

void APP::MainApp::Start()
{
    InitilizeConfig();

    current_path = FilesLogic::GetPath();
    uiClass::HelloPrint(current_path);

    std::wstring command_line;
    std::getline(std::wcin, command_line);

    // process command to get cmd state
    cmd_n state = processCommands(command_line);

    if (state == cmd_n::Exit)
    {
        Exit();
        std::wcout << L"Bye!" << std::endl;
        return;
    }


    MainFunc(state);
}

void APP::MainApp::MainFunc(cmd_n command)
{
    switch (command) {
    case cmd_n::Open:
        FilesLogic::OpenFile(arg1);
        break;
    case cmd_n::Create:
        FilesLogic::CreateNewFile(arg1);
        break;
    case cmd_n::Delete:
        FilesLogic::DeleteSFile(arg1);
        break;
    case cmd_n::Path:
        FilesLogic::WritePath(arg1);
        break;
    case cmd_n::Move:
        FilesLogic::MoveFileToAnotherDirectory(arg1, arg2);
        break;
    case cmd_n::Rename:
        FilesLogic::RenameFile(arg1, arg2);
        break;
    case cmd_n::ShowF:
        FilesLogic::ShowFileList(current_path);
        break;
    case cmd_n::HelpEn:
        Help();
        break;
    case cmd_n::Clear:
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
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

void APP::MainApp::InitilizeConfig(std::wstring config_file_name)
{
    if (USED_CONFIG_INITIALIZATION) { return; }
    USED_CONFIG_INITIALIZATION = true;

    // get name of windows user
#if defined(_WIN32)
    const char* usernameVar = "USERNAME";
#else
    const char* usernameVar = "USER";
#endif

    char* username = nullptr;
    size_t size;

    if (_dupenv_s(&username, &size, usernameVar) != 0 || username == nullptr) {
        std::cerr << "- Fatal error: Unable to get username\n";
        return;
    }

    // convert from const char to wstring
    int bufferSize = MultiByteToWideChar(CP_UTF8, 0, username, -1, nullptr, 0);
    std::wstring wideUsername(bufferSize, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, username, -1, &wideUsername[0], bufferSize);

    // Construct the filename
    std::wstring filename = L"C:\\Users\\" + wideUsername + L"\\OneDrive\\Documents\\" + config_file_name + L".cfg";

    std::ofstream file(filename);

    if (!file.is_open()) {
        DWORD error = GetLastError();
        std::wcerr << L"- Can't create config file: " << filename << L", Error code: " << error << std::endl;
        if (error == 5)
        {
            std::wcerr << L"- !! START PROGRAM AS ADMINISTRATOR !! -\n";
            return;
        }
        free(username);
        return;
    }

    file.close();
    std::wcout << L"Config file created: " << filename << L"\n";

    std::fstream inputFile(filename, std::ios::in | std::ios::out);

    if (!inputFile.is_open()) {
        std::wcerr << L"- Can't open config: " << filename << std::endl;
        free(username);
        return;
    }

    std::string line;
    int iteration = 0;

    while (std::getline(inputFile, line)) {

        if (iteration == 0) 
        {
            configuration.SetLanguage(line);
            iteration++;
            continue;
        }
        else if (iteration == 1)
        {
            configuration.SetConfigName(line);
            iteration++;
            continue;
        }


        iteration++;
    }

    inputFile.close();


    uiClass::SetLanguage("En-en");
    free(username);
  

}

cmd_n APP::MainApp::processCommands(std::wstring command_line)
{
    std::wistringstream check(command_line);

    if (command_line[0] != L'/') { return cmd_n::Invalid; }

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
    if (!is_exist) { return cmd_n::Invalid; }

    bool quotes = false;

    for (auto d : command_line)
    {
        if (d == L'\"') {
            int iterator_for = 0;
            processArg(command_line, iterator_for, 0);
            processArg(command_line, iterator_for, 1);
            quotes = true;
            return static_cast<cmd_n>(i);
        }
    }

    check >> arg1 >> arg2;

    return static_cast<cmd_n>(i);
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