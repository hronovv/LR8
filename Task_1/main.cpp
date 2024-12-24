#include "client.h"
#pragma pack(1)
int main() {
    remove("atc.txt");
    int newCount = 0;
    int count = 0;
    Client* clients = nullptr;
    short option;
    float discount_for_search;
    while (true) {
        menu();
        std::cout << "Выберите опцию: ";
        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Введите количество клиентов: ";
                std::cin >> count;
                while (true) {
                    if (count > 0) {
                        if (std::cin.peek() == '\n') {
                            break;
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                            std::cout << "Введите количество клиентов: ";
                            std::cin >> count;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "Введите количество клиентов: ";
                        std::cin >> count;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                inputClients(clients, count);
                break;
            case 2:
                displayClients(clients, count);
                break;
            case 3:
                display_binary_Clients(clients, count);
                break;
            case 4:
                std::cout << "Введите количество новых клиентов: ";
                std::cin >> newCount;
                while (true) {
                    if (newCount > 0) {
                        if (std::cin.peek() == '\n') {
                            break;
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                            std::cout << "Введите новых клиентов: ";
                            std::cin >> newCount;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "Введите новых клиентов: ";
                        std::cin >> newCount;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                addClients(clients, count, newCount);
                break;
            case 5:
                std::cout << "Введите размер скидки для поиска: ";
                std::cin >> discount_for_search;
                while (true) {
                    if (discount_for_search >= 0 && discount_for_search <= 100) {
                        if (std::cin.peek() == '\n') {
                            break;
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                            std::cout << "Введите размер скидки для поиска: ";
                            std::cin >> discount_for_search;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "Введите размер скидки для поиска: ";
                        std::cin >> discount_for_search;
                    }
                }
                std::cin.ignore();
                searchClients(clients, count, discount_for_search);
                break;
            case 6:
                std::cout << "Введите размер скидки для удаления: ";
                std::cin >> discount_for_search;
                while (true) {
                    if (discount_for_search >= 0 && discount_for_search <= 100) {
                        if (std::cin.peek() == '\n') {
                            break;
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                            std::cout << "Введите размер скидки для удаления: ";
                            std::cin >> discount_for_search;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "Введите размер скидки для удаления: ";
                        std::cin >> discount_for_search;
                    }
                }
                std::cin.ignore();
                deleteClient(clients, count, discount_for_search);
                break;
            case 7:
                std::cout << "Введите размер скидки клиента для обновления: ";
                std::cin >> discount_for_search;
                while (true) {
                    if (discount_for_search >= 0 && discount_for_search <= 100) {
                        if (std::cin.peek() == '\n') {
                            break;
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                            std::cout << "Введите размер скидки клиента для обновления: ";
                            std::cin >> discount_for_search;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "Введите размер скидки клиента для обновления: ";
                        std::cin >> discount_for_search;
                    }
                }
                std::cin.ignore();
                updateClient(clients, count, discount_for_search);
                break;
            case 8:
                sortClients(clients, count);
                break;
            case 0:
                free(clients);
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
    return 0;
}