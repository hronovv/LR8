#include "atc.h"
void menu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Ввести данные разговоров на АТС(при повторном вводе данные перезаписываются)\n";
    std::cout << "2. Показать данные разговоров на АТС\n";
    std::cout << "3. Показать данные разговоров на АТС(чтение из текстового файла)\n";
    std::cout << "4. Добавить данные разговоров на АТС\n";
    std::cout << "5. Вывести общее время разговоров по городу и сумму\n";
    std::cout << "6. Изменить данные о городе\n";
    std::cout << "7. Удалить данные о городе\n";
    std::cout << "0. Выход\n";
}
void input_calls(ATC *&atc, int count) {
    atc = (ATC *)malloc(count * sizeof(ATC));
    std::ofstream ofs;
    ofs.open("atc.txt", std::ios::out);
    for (int i = 0; i < count; i++) {
        std::cout << "\nВведите название города №" << i+1 << ": ";
        std::cin.getline(atc[i].city_name, sizeof(atc[i].city_name));
        std::cout << "\nВведите время разговора(в минутах): ";
        std::cin >> atc[i].call_time;
        while (true) {
            if (atc[i].call_time > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "\nВведите время разговора(в минутах): ";
                    std::cin >> atc[i].call_time;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "\nВведите время разговора(в минутах): ";
                std::cin >> atc[i].call_time;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите код города: ";
        std::cin.getline(atc[i].city_code, sizeof(atc[i].city_code)); 
        std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
        std::cin >> atc[i].cost_per_minute;
        while (true) {
            if (atc[i].cost_per_minute > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
                    std::cin >> atc[i].cost_per_minute;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
                std::cin >> atc[i].cost_per_minute;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите дату разговора: ";
        std::cin.getline(atc[i].call_date, sizeof(atc[i].call_date));
        std::cout << "\nВведите номер телефона города: ";
        std::cin.getline(atc[i].city_phone_number, sizeof(atc[i].city_phone_number));
        std::cout << "\nВведите номер телефона абонента: ";
        std::cin.getline(atc[i].abonent_phone_number, sizeof(atc[i].abonent_phone_number));
        ofs << atc[i].city_name << std::endl <<  atc[i].call_time << std::endl << atc[i].city_code << std::endl << atc[i].cost_per_minute << std::endl << atc[i].call_date << std::endl << atc[i].city_phone_number << std::endl << atc[i].abonent_phone_number << std::endl;
    }
    ofs.close();
}
void add_calls(ATC *&atc, int &count, int &newCount) {
    atc = (ATC *)realloc(atc, (count + newCount) * sizeof(ATC));
    std::ofstream ofs;
    ofs.open("atc.txt", std::ios::app);
    for (int i = count; i < count + newCount; i++) {
        std::cout << "\nВведите название города №" << i+1 << ": ";
        std::cin.getline(atc[i].city_name, sizeof(atc[i].city_name));
        std::cout << "\nВведите время разговора(в минутах): ";
        std::cin >> atc[i].call_time;
        while (true) {
            if (atc[i].call_time > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "\nВведите время разговора(в минутах): ";
                    std::cin >> atc[i].call_time;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "\nВведите время разговора(в минутах): ";
                std::cin >> atc[i].call_time;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите код города: ";
        std::cin.getline(atc[i].city_code, sizeof(atc[i].city_code));
        std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
        std::cin >> atc[i].cost_per_minute;
        while (true) {
            if (atc[i].cost_per_minute > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
                    std::cin >> atc[i].cost_per_minute;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
                std::cin >> atc[i].cost_per_minute;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВведите дату разговора: ";
        std::cin.getline(atc[i].call_date, sizeof(atc[i].call_date));
        std::cout << "\nВведите номер телефона города: ";
        std::cin.getline(atc[i].city_phone_number, sizeof(atc[i].city_phone_number));
        std::cout << "\nВведите номер телефона абонента: ";
        std::cin.getline(atc[i].abonent_phone_number, sizeof(atc[i].abonent_phone_number));
        ofs << atc[i].city_name << std::endl <<  atc[i].call_time << std::endl << atc[i].city_code << std::endl << atc[i].cost_per_minute << std::endl << atc[i].call_date << std::endl << atc[i].city_phone_number << std::endl << atc[i].abonent_phone_number << std::endl;
    }
    ofs.close();
    count += newCount;
}
void display_calls(ATC *atc, int count) {
    std::cout << "\nДанные разговоров:\n";
    for (int i = 0; i < count; i++) {
        std::cout << "\nГород: " << atc[i].city_name;
        std::cout << "\nВремя разговора(в минутах): " << atc[i].call_time;
        std::cout << "\nКод города: " << atc[i].city_code;
        std::cout << "\nСтоимость разговора (за минуту): " << atc[i].cost_per_minute;
        std::cout << "\nДата разговора: " << atc[i].call_date;
        std::cout << "\nНомер телефона города: " << atc[i].city_phone_number;
        std::cout << "\nНомер телефона абонента: " << atc[i].abonent_phone_number << std::endl;
    }
}
void display_binary_calls(ATC *atc, int count) {
    std::ifstream ifs("atc.txt");
    std::string temp_city_name;
    long long temp_call_time;
    std::string temp_city_code;
    long long temp_cost_per_minute;
    std::string temp_call_date;  
    std::string temp_city_phone_number;
    std::string temp_abonent_phone_number;
    std::cout << "\nДанные разговоров:\n";
    for (int i = 0; i < count; i++) {
        std::getline(ifs, temp_city_name);
        ifs >> temp_call_time;
        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(ifs,temp_city_code);
        ifs >> temp_cost_per_minute;
        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(ifs,temp_call_date);
        std::getline(ifs,temp_city_phone_number);
        std::getline(ifs,temp_abonent_phone_number);
        std::cout << "\nГород: " << temp_city_name;
        std::cout << "\nВремя разговора(в минутах): " << temp_call_time;
        std::cout << "\nКод города: " << temp_city_code;
        std::cout << "\nСтоимость разговора (за минуту): " << temp_cost_per_minute;
        std::cout << "\nДата разговора: " << temp_call_date;
        std::cout << "\nНомер телефона города: " << temp_city_phone_number;
        std::cout << "\nНомер телефона абонента: " << temp_abonent_phone_number << std::endl;
    }
    ifs.close();
}
void change_atc(ATC *atc, int count) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char name_city[100];
    std::cout << "Введите название города: ";
    std::cin.getline(name_city, sizeof(name_city));
    std::ofstream ofs("atc.txt", std::ios::out);
    for (int i = 0; i < count; i++) {
        if (strcmp(name_city, atc[i].city_name) == 0) {
            std::cout << "Обновите данные города " << atc[i].city_name << ": ";
            std::cout << "\nВведите название города №" << i+1 << ": ";
            std::cin.getline(atc[i].city_name, sizeof(atc[i].city_name));
            std::cout << "\nВведите время разговора(в минутах): ";
            std::cin >> atc[i].call_time;
            while (true) {
                if (atc[i].call_time > 0) {
                    if (std::cin.peek() == '\n') {
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "\nВведите время разговора(в минутах): ";
                        std::cin >> atc[i].call_time;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "\nВведите время разговора(в минутах): ";
                    std::cin >> atc[i].call_time;
                }
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nВведите код города: ";
            std::cin.getline(atc[i].city_code, sizeof(atc[i].city_code));
            std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
            std::cin >> atc[i].cost_per_minute;
            while (true) {
                if (atc[i].cost_per_minute > 0) {
                    if (std::cin.peek() == '\n') {
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                        std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
                        std::cin >> atc[i].cost_per_minute;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\e[1;91m Введенное значение неправильное. Введите его заного.\e[0m\n\n";
                    std::cout << "\nВведите стоимость разговора в рублях(в минуту): ";
                    std::cin >> atc[i].cost_per_minute;
                }
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nВведите дату разговора: ";
            std::cin.getline(atc[i].call_date, sizeof(atc[i].call_date));
            std::cout << "\nВведите номер телефона города: ";
            std::cin.getline(atc[i].city_phone_number, sizeof(atc[i].city_phone_number));
            std::cout << "\nВведите номер телефона абонента: ";
            std::cin.getline(atc[i].abonent_phone_number, sizeof(atc[i].abonent_phone_number));
        }
        ofs << atc[i].city_name << std::endl <<  atc[i].call_time << std::endl << atc[i].city_code << std::endl << atc[i].cost_per_minute << std::endl << atc[i].call_date << std::endl << atc[i].city_phone_number << std::endl << atc[i].abonent_phone_number << std::endl;
    }
    ofs.close();
}
void search_time_and_sum(ATC *atc, int count) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char name_city[100];
    std::cout << "Введите название города: ";
    std::cin.getline(name_city, sizeof(name_city));
    unsigned long long time_sum = 0; 
    unsigned long long cost_sum = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(name_city, atc[i].city_name) == 0) {
            time_sum+=atc[i].call_time;
            cost_sum+=(atc[i].call_time*atc[i].cost_per_minute);
        }
    }
    std::cout << "\n\nОбщее время разговоров по городу " << name_city << ": " << time_sum << " минут";    
    std::cout << "\nОбщая стоимость разговоров по городу " << name_city << ": " << cost_sum << " рублей" << std::endl;
}
void delete_atc(ATC *&atc, int &count) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char name_city[100];
    std::cout << "Введите название города: ";
    std::cin.getline(name_city, sizeof(name_city));
    int newCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(name_city, atc[i].city_name) != 0) {
            atc[newCount++] = atc[i];
        }
    }
    atc = (ATC *)realloc(atc, newCount * sizeof(ATC));
    count = newCount;
    std::cout << "\nГорода с именем " << name_city << " удалены." << std::endl;
    if (newCount == 0) { remove("atc.txt");}
    else {
        std::ofstream ofs;
        ofs.open("atc.txt", std::ios::out);
        for (int i = 0; i < newCount; i++) {
            ofs << atc[i].city_name << std::endl <<  atc[i].call_time << std::endl << atc[i].city_code << std::endl << atc[i].cost_per_minute << std::endl << atc[i].call_date << std::endl << atc[i].city_phone_number << std::endl << atc[i].abonent_phone_number << std::endl; 
        }
    ofs.close();
    }
}