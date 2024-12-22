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
    char city_name[100];
    union {
        long long call_time;
    };
    char city_code[30];
    long long cost_per_minute;
    char call_date[150];  
    char city_phone_number[20];
    char abonent_phone_number[20];
} ATC;
void menu();
void input_calls(ATC *atc, int count);
void display_calls(ATC *atc, int count);
void display_binary_calls(ATC *atc, int count);
void add_calls(ATC *atc, int &count, int &newCount);
void search_time_and_sum(ATC *atc, int count);
void change_atc(ATC *atc, int count);
void delete_atc(ATC *&atc, int &count);