#include "client.h"
void menu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Ввести клиентов(при повторном вводе база клиентов перезаписывается)\n";
    std::cout << "2. Показать клиентов\n";
    std::cout << "3. Показать клиентов(чтение из бинарного файла)\n";
    std::cout << "4. Добавить клиентов\n";
    std::cout << "5. Поиск клиентов по скидке\n";
    std::cout << "6. Удалить клиента по скидке\n";
    std::cout << "7. Обновить данные клиента по скидке\n";
    std::cout << "8. Сортировать клиентов по скидке\n";
    std::cout << "0. Выход\n";
}
void inputClients(Client *clients, int count) {
    std::ofstream ofs;
    ofs.open("client.bin", std::ios::out | std::ios::binary);
    for (int i = 0; i < count; i++) {
        std::cout << "\nВведите ФИО клиента №" << i + 1 << ": ";
        std::cin.getline(clients[i].name, sizeof(clients[i].name)); 
        std::cout << "\nВведите возраст клиента: ";
        std::cin >> clients[i].age;
        while (true) {
            if (clients[i].age > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "Введите возраст клиента: ";
                    std::cin >> clients[i].age;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "Введите возраст клиента: ";
                std::cin >> clients[i].age;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите адрес клиента: ";
        std::cin.getline(clients[i].address, sizeof(clients[i].address));
        std::cout << "\nВведите размер скидки: ";
        std::cin >> clients[i].discount;
        while (true) {
            if (clients[i].discount >= 0 && clients[i].discount <= 100) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "Введите размер скидки: ";
                    std::cin >> clients[i].discount;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "Введите размер скидки: ";
                std::cin >> clients[i].discount;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите номер бонусной карты: ";
        std::cin.getline(clients[i].discount_card_number, sizeof(clients[i].discount_card_number));
        ofs.write((char*)(&clients[i]), sizeof(Client));
    }
    ofs.close();
}
void addClients(Client *clients, int &count, int &newCount) {
    std::ofstream ofs;
    ofs.open("client.bin", std::ios::app | std::ios::binary);
    for (int i = count; i < count + newCount; i++) {
        std::cout << "\nВведите ФИО клиента №" << i+1 << ": ";
        std::cin.getline(clients[i].name, sizeof(clients[i].name));
        std::cout << "\nВведите возраст клиента: ";
        std::cin >> clients[i].age;
        while (true) {
            if (clients[i].age > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "Введите возраст клиента: ";
                    std::cin >> clients[i].age;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "Введите возраст клиента: ";
                std::cin >> clients[i].age;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите адрес клиента: ";
        std::cin.getline(clients[i].address, sizeof(clients[i].address)); 
        std::cout << "\nВведите размер скидки: ";
        std::cin >> clients[i].discount;
        while (true) {
            if (clients[i].discount >= 0 && clients[i].discount <= 100) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "Введите размер скидки: ";
                    std::cin >> clients[i].discount;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "Введите размер скидки: ";
                std::cin >> clients[i].discount;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите номер бонусной карты : ";
        std::cin.getline(clients[i].discount_card_number, sizeof(clients[i].discount_card_number)); 
        ofs.write((char*)(&clients[i]), sizeof(Client));
    }
    ofs.close();
    count += newCount;
}
void displayClients(Client *clients, int count) {
    std::cout << "\nСписок клиентов:\n";
    for (int i = 0; i < count; i++) {
        std::cout << "\nКлиент №" << i+1 << std::endl;
        std::cout << "\nФИО: " << clients[i].name;
        std::cout << "\nВозраст: " << clients[i].age;
        std::cout << "\nАдрес: " << clients[i].address;
        std::cout << "\nСкидка: " << std::fixed << std::setprecision(1) << clients[i].discount << "%";
        std::cout << "\nНомер бонусной карты: " << clients[i].discount_card_number << std::endl;
    }
}
void display_binary_Clients(Client *clients, int count) {
    std::ifstream ifs("client.bin", std::ios::binary);
    Client temp_client;
    std::cout << "\nСписок клиентов:\n";
    for (int i = 0; i < count; i++) {
        ifs.read((char*)(&temp_client),sizeof(Client));
        std::cout << "\nКлиент №" << i + 1 << std::endl;
        std::cout << "\nФИО: " << temp_client.name;
        std::cout << "\nВозраст: " << temp_client.age;
        std::cout << "\nАдрес: " << temp_client.address;
        std::cout << "\nСкидка: " << std::fixed << std::setprecision(1) << temp_client.discount << "%";
        std::cout << "\nНомер бонусной карты: " << temp_client.discount_card_number << std::endl;
    }
    ifs.close();
}
void searchClients(Client *clients, int count, float discount_for_search) {
    std::cout << "\nКлиенты, со скидкой - " << discount_for_search <<"% : ";
    for (int i = 0; i < count; i++) {
        if (clients[i].discount == discount_for_search) {
            std::cout << "\nКлиент №" << i+1;
            std::cout << "\nФИО: " << clients[i].name;
            std::cout << "\nВозраст: " << clients[i].age;
            std::cout << "\nАдрес: " << clients[i].address;
            std::cout << "\nНомер бонусной карты: " << clients[i].discount_card_number << std::endl;
        }
    }
}
void deleteClient(Client *&clients, int &count, float discount_for_search) {
    int newCount = 0;
    for (int i = 0; i < count; i++) {
        if (clients[i].discount != discount_for_search) {
            clients[newCount++] = clients[i];
        }
    }
    clients = (Client *)realloc(clients, newCount * sizeof(Client));
    count = newCount; 
    std::cout << "\nКлиенты со скидкой " << discount_for_search << "% удалены." << std::endl;
    if (newCount == 0) { remove("client.bin");}
    else {
        std::ofstream ofs;
        ofs.open("client.bin", std::ios::out | std::ios::binary);
        for (int i = 0; i < newCount; i++) {
            ofs.write((char*)(&clients[i]), sizeof(Client));
        }
     ofs.close();
    }
}
void updateClient(Client *clients, int count, float discount) {
    for (int i = 0; i < count; i++) {
        if (clients[i].discount == discount) {
            std::fstream ofs("client.bin", std::ios::in | std::ios::out | std::ios::binary);
            long long byte_sum = i * sizeof(Client);
            std::cout << "Обновите данные клиента " << clients[i].name << ": ";
            std::cout << "\nВведите ФИО клиента №" << i + 1 << ": ";
            std::cin.getline(clients[i].name, sizeof(clients[i].name)); 
            std::cout << "\nВведите возраст клиента: ";
            std::cin >> clients[i].age;
            while (true) {
                if (clients[i].age > 0) {
                    if (std::cin.peek() == '\n') {
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заново.\e[0m\n\n";
                        std::cout << "Введите возраст клиента: ";
                        std::cin >> clients[i].age;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заново.\e[0m\n\n";
                    std::cout << "Введите возраст клиента: ";
                    std::cin >> clients[i].age;
                }
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nВведите адрес клиента: ";
            std::cin.getline(clients[i].address, sizeof(clients[i].address)); 
            std::cout << "\nВведите размер скидки: ";
            std::cin >> clients[i].discount;
            while (true) {
                if (clients[i].discount >= 0 && clients[i].discount <= 100) {
                    if (std::cin.peek() == '\n') {
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заново.\e[0m\n\n";
                        std::cout << "Введите размер скидки: ";
                        std::cin >> clients[i].discount;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заново.\e[0m\n\n";
                    std::cout << "Введите размер скидки: ";
                    std::cin >> clients[i].discount;
                }
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nВведите номер бонусной карты: ";
            std::cin.getline(clients[i].discount_card_number, sizeof(clients[i].discount_card_number)); 
            ofs.seekp(byte_sum, std::ios::beg);
            ofs.write((char*)(&clients[i]), sizeof(Client));
            ofs.close();
        }
    }
}
void sortClients(Client *clients, int count) {
    for (int i = 1; i < count; i++) {
        Client key = clients[i];
        int j = i - 1;
        while (j >= 0 && clients[j].discount > key.discount) {
            clients[j + 1] = clients[j];
            j--;
        }
        clients[j + 1] = key;
    }
    std::cout << "Клиенты отсортированы по скидке.\n";
    std::ofstream ofs;
    ofs.open("client.bin", std::ios::out | std::ios::binary);
    for (int i = 0; i < count; i++) {
        ofs.write((char*)(&clients[i]), sizeof(Client));
    }
    ofs.close();
}
