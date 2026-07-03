# Terminal Forge

Terminal Forge — консольный менеджер паролей, написанный на C++.

Данные хранятся локально в текстовом файле. Управление осуществляется через команды в терминале.

---

## Установка

### Linux / macOS / Windows (Git Bash)

```bash
git clone git@github.com:RoIPoNh/TerminalForge.git
cd TerminalForge
g++ main.cpp -o forge
```

После компиляции:
```bash
./forge --help
```

---

## Использование

| Команда          | Описание                 |
|------------------|--------------------------|
| `./forge add`    | Добавить аккаунт         |
| `./forge list`   | Показать все аккаунты    |
| `./forge get`    | Найти аккаунт по имени   |
| `./forge remove` | Удалить аккаунт по имени |
| `./forge --help` | Справка                  |

### Пример

```bash
./forge add
Enter service name: GitHub
Enter login: mylogin
Enter password: mypassword

./forge list
1. GitHub (login: mylogin)

./forge get
Enter service name: GitHub
Found:
  Service: GitHub
  Login: mylogin
  Password: mypassword

./forge remove
Enter service name to remove: GitHub
Account "GitHub" removed.
```

---

## Архитектура

Проект состоит из одного файла `main.cpp`, содержащего:

- Класс `Account`  
  Поля: `name`, `login`, `password`.

- Глобальный вектор `accounts`  
  Хранит аккаунты в памяти.

- Функции:
  - `loadFromFile()` — загрузка из `~/.forge/accounts.txt`
  - `saveToFile()` — сохранение в `~/.forge/accounts.txt`
  - `addAccount()` — добавление
  - `listAccounts()` — список
  - `getAccount()` — поиск
  - `removeAccount()` — удаление

---

## Формат файла

Файл: `~/.forge/accounts.txt`

Каждый аккаунт занимает три строки:

```
имя_сервиса
логин
пароль
```

Пример:

```
GitHub
roi
superpassword123
Google
user@mail.com
qwerty
```

---

## Планы по развитию

- Шифрование паролей
- Экспорт в CSV
- Импорт из CSV
- Поиск по части имени
- Цветной вывод

---

## Лицензия

MIT License

---

## Автор

RoIPoNh

---

## Ссылки

- [Репозиторий](https://github.com/RoIPoNh/TerminalForge)
- [Документация C++](https://en.cppreference.com/w/)
```
