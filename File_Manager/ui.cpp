#include "ui.h"

std::string UI::uiClass::message(code code)
{
    int numero = static_cast<int>(code);

    int requiredSize = WideCharToMultiByte(CP_UTF8, 0, language_use_[numero].c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string phrase(requiredSize, 0);
    WideCharToMultiByte(CP_UTF8, 0, language_use_[numero].c_str(), -1, &phrase[0], requiredSize, nullptr, nullptr);

    // Now return the c_str() of the converted wstring
    return phrase;
}

bool UI::uiClass::SetLanguage(std::string language)
{
    if (language == "en")
    {
        this->language_use_ = english_;
        return true;
    }
    else if (language == "zh")
    {
        this->language_use_ = chinese_;
        return true;
    }
    else if (language == "ru")
    {
        this->language_use_ = russian_;
        return true;
    }
    else if (language == "sr")
    {
        this->language_use_ = serbian_;
        return true;
    }
    else
    {
        std::wcout << L"- There is an error in language initialization!!\n- Try to delete config from\n" <<
            L"- C:\\Users\\YourUserName\\Documents\n";
        this->language_use_ = english_;
        return false;
    }
}

void UI::uiClass::HelloPrint(std::wstring curr_path)
{
    int requiredSize = WideCharToMultiByte(CP_UTF8, 0, curr_path.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string file_name(requiredSize, 0);
    WideCharToMultiByte(CP_UTF8, 0, curr_path.c_str(), -1, &file_name[0], requiredSize, nullptr, nullptr);
    if (welcome) {
        std::wcout << message(code::Welcome).c_str() << message(code::Directory).c_str() << file_name.c_str() << L"\"\n";
        std::wcout << message(code::TypeCommand).c_str() << message(code::HelpWelcome).c_str() << L": ";
        welcome = false;
        return;
    }
    std::wcout << message(code::Directory).c_str() << file_name.c_str() << L"\"\n";
    std::wcout << L"Type a command: ";
}
