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

enum class code
{
    // main strings
    Directory,
    Welcome,
    HelpWelcome,
    TypeCommand,
    Bye,
    // success
    ConfigCreated,
    Launched,
    Created,
    // file delete
    Delete,
    SureDelete,
    InPath,
    // done
    Done,
    // file list
    FilesInCurrPath,
    LineForFilesInCurrPath,
    // errors
    ErrOpen,
    ErrFileNotExistOrRegularFile,
    ErrFile,
    ErrPath,
    ErrCreate,
    ErrCode,
    ErrExecutable,
    Err,
    IncoreectPath,
    ErrAccess,
    InvalidCommand,
    UnableGetUsername,
    ErrConfigLoad,
    START_ADMIN
};

namespace UI {

    class uiClass : public F_LOGIC::FilesLogic
    {
    public:
        std::vector<std::wstring> current_files_list;

        std::string message(code code);
        bool SetLanguage(std::string language);
        void HelloPrint(std::wstring curr_path);

    private:
        bool welcome = true;
        std::string language = "en";

        std::vector<std::wstring> language_use_;

        std::vector<std::wstring> english_{
            // main strings
            L"Your current directory is : \"",
            L"Welcome! ",
            L" (type '/help' for commands list)",
            L"Type a command",
            L"Bye!\n",
            // success
            L"Config file created: ",
            L"- App launched successfully.\n",
            L"- File created successfully.\n",
            // delete file
            L"- File deleted.\n",
            L"- Are you sure want to delete file: ",
            L"- In path: ",
            // done
            L"- Done\n",
            // file list
            L"_______________ Files In Current Path _______________\n",
            L"_____________________________________________________\n",

            // errors
            L"- Can't open config: ",
            L"- File does not exist or is not a regular file: ",
            L"- This file doesn't exist!\n",
            L"- This path doesn't exist!\n",
            L"- Failed to create file.\n",
            L"- Failed with error code: ",
            L"- File is not executable: ",
            L"- Error: ",
            L"- Incorrect Path\n",
            L"- Error accessing directory: ",
            L"- Invalid command!\n",
            L"- Fatal error: Unable to get username\n",
            L"- Can't create config file: ",
            L"- !! START PROGRAM AS ADMINISTRATOR !! -\n",

        };

        std::vector<std::wstring> chinese_{
            L"您当前的目录是：\"",
            L"欢迎！ ",
            L"（输入'/help'查看命令列表）",
            L"输入命令",
            L"再见！\n",
            // success
            L"配置文件已创建：",
            L"- 应用程序成功启动。\n",
            L"- 文件成功创建。\n",
            // delete file
            L"- 文件已删除。\n",
            L"- 您确定要删除文件：",
            L"- 在路径中：",
            // done
            L"- 完成\n",
            // file list
            L"_______________ 当前路径中的文件 _______________\n",
            L"_____________________________________________________\n",

            // errors
            L"- 无法打开配置文件：",
            L"- 文件不存在或不是常规文件：",
            L"- 此文件不存在！\n",
            L"- 此路径不存在！\n",
            L"- 无法创建文件。\n",
            L"- 失败，错误代码：",
            L"- 文件不可执行：",
            L"- 错误：",
            L"- 不正确的路径\n",
            L"- 访问目录错误：",
            L"- 无效命令！\n",
            L"- 致命错误：无法获取用户名\n",
            L"- 无法创建配置文件：",
            L"- !! 以管理员身份启动程序 !! -\n",
        };

        std::vector<std::wstring> russian_{
            L"Ваш текущий каталог: \"",
            L"Добро пожаловать! ",
            L" (введите '/help' для списка команд)",
            L"Введите команду",
            L"До свидания!\n",
            // success
            L"Файл конфигурации создан: ",
            L"- Приложение успешно запущено.\n",
            L"- Файл успешно создан.\n",
            // delete file
            L"- Файл удален.\n",
            L"- Вы уверены, что хотите удалить файл: ",
            L"- По пути: ",
            // done
            L"- Готово\n",
            // file list
            L"_______________ Файлы в текущем каталоге _______________\n",
            L"_____________________________________________________\n",

            // errors
            L"- Невозможно открыть конфигурацию: ",
            L"- Файл не существует или не является обычным файлом: ",
            L"- Этот файл не существует!\n",
            L"- Этот путь не существует!\n",
            L"- Не удалось создать файл.\n",
            L"- Сбой с кодом ошибки: ",
            L"- Файл не является исполняемым: ",
            L"- Ошибка: ",
            L"- Некорректный путь\n",
            L"- Ошибка доступа к каталогу: ",
            L"- Недопустимая команда!\n",
            L"- Фатальная ошибка: Невозможно получить имя пользователя\n",
            L"- Невозможно создать файл конфигурации: ",
            L"- !! ЗАПУСТИТЕ ПРОГРАММУ ОТ ИМЕНИ АДМИНИСТРАТОРА !! -\n",
        };

        std::vector<std::wstring> serbian_{
            L"Ваш тренутни директоријум је: \"",
            L"Добродошли! ",
            L" (унесите '/help' за списак команди)",
            L"Унесите команду",
            L"Довиђење!\n",
            // success
            L"Конфигурациони фајл је креиран: ",
            L"- Апликација успешно покренута.\n",
            L"- Фајл успешно креиран.\n",
            // delete file
            L"- Фајл је обрисан.\n",
            L"- Да ли сте сигурни да желите обрисати фајл: ",
            L"- На путањи: ",
            // done
            L"- Завршено\n",
            // file list
            L"_______________ Фајлови у тренутном путањи _______________\n",
            L"_____________________________________________________\n",

            // errors
            L"- Не могу отворити конфигурацију: ",
            L"- Фајл не постоји или није обичан фајл: ",
            L"- Овај фајл не постоји!\n",
            L"- Ова стаза не постоји!\n",
            L"- Није успело креирање фајла.\n",
            L"- Неуспех са кôдом грешке: ",
            L"- Фајл не је извршан: ",
            L"- Грешка: ",
            L"- Нетачна путања\n",
            L"- Грешка при приступу директоријуму: ",
            L"- Неважећа команда!\n",
            L"- Фатална грешка: Није могуће добити корисничко име\n",
            L"- Не могу креирати конфигурациони фајл: ",
            L"- !! ПОКРЕНИТЕ ПРОГРАМ КАО АДМИНИСТРАТОР !! -\n",
        };
    };
}