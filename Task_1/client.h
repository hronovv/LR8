#include <stdio.h>
#include <cstdio> 
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstddef>
typedef struct {
    char name[150]; 
    union {
        short age;
    };
    char address[200];
    float discount;
    char discount_card_number[50];
} Client;
void menu();
void inputClients(Client *&clients, int count);
void displayClients(Client *clients, int count);
void display_binary_Clients(Client *clients, int count);
void addClients(Client *&clients, int &count, int &newCount);
void searchClients(Client *clients, int count, float discount_for_search);
void deleteClient(Client *&clients, int &count, float discount_for_search);
void updateClient(Client *clients, int count, float discount);
void sortClients(Client *clients, int count);