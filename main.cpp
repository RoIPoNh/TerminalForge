#include <iostream>
#include <vector>
#include <string>

//Класс Account

class Account {
public:
    std::string name;
    std::string login;
    std::string password;
};

//Главная функция

int main(int argc, char* argv[]) {
    std::cout << "Terminal Forge v0.1\n";

    if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cout << "Доступные команды:\n";
        std::cout << " add    - Добавить запись\n";
        std::cout << " list   - Показать все записи\n";
        std::cout << " get    - Показать запись по имени\n";
        std::cout << " remove - Удалить запись\n";
        std::cout << " --help - Показать данную справку\n";
    }

    return 0;

}
