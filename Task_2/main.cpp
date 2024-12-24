#include "atc.h"
int main() {
    remove("atc.txt");
    int newCount = 0;
    int count = 0;
    ATC *atc = nullptr;
    short option;
    while (true) {
        menu();
        std::cout << "Выберите опцию: ";
        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Введите количество разговоров: ";
                std::cin >> count;
                while (true) {
                    if (count > 0) {
                        if (std::cin.peek() == '\n') {
                            break;
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                            std::cout << "Введите количество разговоров: ";
                            std::cin >> count;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "Введите количество разговоров: ";
                        std::cin >> count;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                input_calls(atc, count);
                break;
            case 2:
                display_calls(atc, count);
                break;
            case 3:
                display_binary_calls(atc, count);
                break;
            case 4:
                std::cout << "Введите количество новых разговоров: ";
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
                add_calls(atc, count, newCount);
                break;
            case 5:
                search_time_and_sum(atc, count);
                break;
            case 6:
                change_atc(atc,count);
                break;
            case 7:
                delete_atc(atc,count);
                break;
            case 0:
                free(atc);
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
    return 0;
}