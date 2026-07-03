#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

class Account {
public:
    std::string name;
    std::string login;
    std::string password;
};

std::vector<Account> accounts;

void saveToFile() {
    std::string path = std::string(getenv("HOME")) + "/.forge/accounts.txt";
    std::ofstream file(path);
    for (const auto& acc : accounts) {
        file << acc.name << "\n";
        file << acc.login << "\n";
        file << acc.password << "\n";
    }
}

void loadFromFile() {
    std::string path = std::string(getenv("HOME")) + "/.forge/accounts.txt";
    std::ifstream file(path);
    if (!file) return;

    Account acc;
    while (std::getline(file, acc.name) && 
           std::getline(file, acc.login) && 
           std::getline(file, acc.password)) {
        accounts.push_back(acc);
    }
}

void addAccount() {
    Account acc;
    std::cout << "Enter service name (e.g., Google): ";
    std::cin >> acc.name;
    std::cout << "Enter login: ";
    std::cin >> acc.login;
    std::cout << "Enter password: ";
    std::cin >> acc.password;

    accounts.push_back(acc);
    saveToFile();
    std::cout << "✅ Account added and saved!\n";
}

void listAccounts() {
    if (accounts.empty()) {
        std::cout << "No accounts stored.\n";
        return;
    }

    std::cout << "\n--- Your accounts ---\n";
    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << i + 1 << ". " 
                  << accounts[i].name 
                  << " (login: " << accounts[i].login << ")\n";
    }
    std::cout << "----------------------\n";
}

void getAccount() {
    std::string name;
    std::cout << "Enter service name: ";
    std::cin >> name;

    for (const auto& acc : accounts) {
        if (acc.name == name) {
            std::cout << "\n✅ Found:\n";
            std::cout << "  Service: " << acc.name << "\n";
            std::cout << "  Login:   " << acc.login << "\n";
            std::cout << "  Password: " << acc.password << "\n";
            return;
        }
    }
    std::cout << "❌ No account found with name: " << name << "\n";
}

void removeAccount() {
    std::string name;
    std::cout << "Enter service name to remove: ";
    std::cin >> name;

    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].name == name) {
            accounts.erase(accounts.begin() + i);
            saveToFile();
            std::cout << "✅ Account \"" << name << "\" removed.\n";
            return;
        }
    }

    std::cout << "❌ No account found with name: " << name << "\n";
}

int main(int argc, char* argv[]) {
    loadFromFile();

    if (argc < 2) {
        std::cout << "Terminal Forge v0.3\n";
        std::cout << "Usage: forge <command>\n";
        std::cout << "Try 'forge --help' for more info.\n";
        return 0;
    }

    std::string command = argv[1];

    if (command == "--help") {
        std::cout << "Available commands:\n";
        std::cout << "  add    - Add a new account\n";
        std::cout << "  list   - Show all accounts\n";
        std::cout << "  get    - Show full account by name\n";
        std::cout << "  remove - Remove account by name\n";
        std::cout << "  --help - Show this help\n";
    } else if (command == "add") {
        addAccount();
    } else if (command == "list") {
        listAccounts();
    } else if (command == "get") {
        getAccount();
    } else if (command == "remove") {
        removeAccount();
    } else {
        std::cout << "Unknown command. Try 'forge --help'.\n";
    }

    return 0;
}
