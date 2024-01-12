#include "files_logic.h"

void CleanBuffer()
{
    while (std::cin.peek() == '\n')
        std::cin.ignore();
}

void F_LOGIC::filesLogic::CallMainFL(int Command)
{
    switch (Command) {
    case 0:
        break;
    case Open:
        OpenFile();
        break;
    case Create:
        CreateNewFile();
        break;
    case Delete:
        DeleteSFile();
        break;
    case Rename:
        RenameFile();
        break;
    case Move:
        MoveFileToAnotherDirectory();
        break;
    case Path:
        WritePath();
        break;
    default:
        std::cout << "Invalid command!" << std::endl;
        break;
    }
}

void F_LOGIC::filesLogic::OpenFile()
{
    std::cout << "Write file name with extension (like 'file_name.txt'): ";

    CleanBuffer();
    // getting file name
    std::string program_name;
    std::getline(std::cin, program_name);

    // file path correction
    std::string file_path = current_path + "\\" + program_name;
    std::replace(file_path.begin(), file_path.end(), '\\', '/');

    if (std::filesystem::exists(file_path) && std::filesystem::is_regular_file(file_path)) {

        auto file_status = std::filesystem::status(file_path);

        if ((file_status.permissions() & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) {
            HINSTANCE result = ShellExecuteA(nullptr, "open", file_path.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

            if (reinterpret_cast<uintptr_t>(result) > 32) {
                std::cout << "App launched successful." << std::endl;
            }
            else {
                std::cerr << "Failed with error code: " << reinterpret_cast<uintptr_t>(result) << std::endl;
            }
        }
        else {
            std::cerr << "File is not executable: " << file_path << std::endl;
        }
    }
    else {
        std::cerr << "File does not exist or is not a regular file: " << file_path << std::endl;
    }
}

void F_LOGIC::filesLogic::CreateNewFile()
{
    std::cout << "Write file name with extension (like 'file_name.txt'): ";

    CleanBuffer();
    //get file name
    std::string program_name;
    std::getline(std::cin, program_name);

    // file path correction
    std::string file_path = current_path + "\\" + program_name;
    std::replace(file_path.begin(), file_path.end(), '\\', '/');

    //file creation here
    std::ofstream file(file_path);

    //check fle
    if (file.is_open()) {
        file.close();
        std::cout << "File created successfully." << std::endl;
        std::cout << file_path;
    }
    else {
        std::cerr << "Failed to create file." << std::endl;
    }
}

void F_LOGIC::filesLogic::DeleteSFile()
{
    std::cout << "Write file name with extension (like 'file_name.txt'): ";

    CleanBuffer();
    //get file name
    std::string program_name;
    std::getline(std::cin, program_name);

    // file path correction
    std::string file_path = current_path + "\\" + program_name;

    if (!std::filesystem::exists(file_path)) { std::cout << "This file doesn't exist!"; return; }

    std::cout << "Are you sure want to delete file: " + program_name << std::endl;
    std::cout << "In path: " + file_path << std::endl;
    bool d;
    std::cin >> d;

    if (!d) { return; }
    try {
        // Попробуйте удалить файл
        std::filesystem::remove(file_path);
        std::cout << "File deleted." << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        // В случае ошибки выводим сообщение
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void F_LOGIC::filesLogic::RenameFile()
{
    std::cout << "Write file name with extension (like 'file_name.txt'): ";

    CleanBuffer();
    // getting file name
    std::string program_name;
    std::getline(std::cin, program_name);
    std::string file_path = current_path + "\\" + program_name;

    if (!std::filesystem::exists(file_path)) { std::cout << "This file doesn't exist!"; return; }

    std::cout << "Write new name with extension (like 'file_name.txt'): ";

    CleanBuffer();
    // getting new file name
    std::string new_program_name;
    std::getline(std::cin, new_program_name);
    std::string new_file_path = current_path + "\\" + new_program_name;

    try {
        // try to rename
        std::filesystem::rename(file_path, new_file_path);
        std::cout << "Done" << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void F_LOGIC::filesLogic::MoveFileToAnotherDirectory()
{
    std::cout << "Write file name with extension (like 'file_name.txt'): ";

    CleanBuffer();
    // getting file name
    std::string program_name;
    std::getline(std::cin, program_name);
    std::string file_path = current_path + "\\" + program_name;
    if (!std::filesystem::exists(file_path)) { std::cout << "This file doesn't exist!"; return; }

    std::cout << "Write new path";


    CleanBuffer();
    // getting new file name
    std::string new_path;
    std::getline(std::cin, new_path); 

    if (!IsPathValid(new_path)) { "This path doesn't exist!";}

    std::string new_file_path = new_path + "\\" + program_name;

    try {
        // try to rename
        std::filesystem::rename(file_path, new_file_path);
        std::cout << "Done" << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool F_LOGIC::filesLogic::IsPathValid(const std::string& path)
{
    return std::filesystem::exists(path);
}

void F_LOGIC::filesLogic::WritePath()
{
    std::cout << "Enter path: ";
    std::string temp;

    std::cin >> temp;

    // checking path is ok
    std::filesystem::path cleanedPath = std::filesystem::path(temp).lexically_normal();
    if (IsPathValid(cleanedPath.string())) {
        this->current_path = cleanedPath.string();
        std::cout << "Done!\n";
    }
    else {
        std::cout << "Incorrect Path!!\n";
    }
}

void F_LOGIC::filesLogic::FileLists(std::vector<std::string>& current_files_list, std::string curr_path)
{
    if (!current_files_list.empty())
    {
        current_files_list.clear();
    }
    try {
        for (const auto& entry : std::filesystem::directory_iterator(curr_path)) {
            current_files_list.push_back(entry.path().filename().string());
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
}


