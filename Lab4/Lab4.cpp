// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Структура Train, що представляє потяг
struct Train {
    string punkt;
    int number;
    string time; 
};

// Функція для порівняння часу у форматі hh:mm
bool isEarlierTime(const string& time1, const string& time2) {
    int hour1 = stoi(time1.substr(0, 2));
    int minute1 = stoi(time1.substr(3, 2));
    int hour2 = stoi(time2.substr(0, 2));
    int minute2 = stoi(time2.substr(3, 2));

    if (hour1 < hour2) return true;
    if (hour1 == hour2 && minute1 < minute2) return true;
    return false;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int numTrains = 8;  
    Train trains[numTrains];

    // Введення даних про потяги
    for (int i = 0; i < numTrains; i++) {
        cout << "Введіть дані для потягу " << i + 1 << ":" << endl;
        cout << "Назва пункту призначення: ";
        cin.ignore();  
        getline(cin, trains[i].punkt);
        cout << "Номер потягу: ";
        cin >> trains[i].number;
        cout << "Час відправлення (hh:mm): ";
        cin >> trains[i].time;
    }

    // Впорядкування записів у масиві за зростанням номера потягу
    for (int i = 0; i < numTrains - 1; i++) {
        for (int j = i + 1; j < numTrains; j++) {
            if (trains[i].number > trains[j].number) {
                Train temp = trains[i];
                trains[i] = trains[j];
                trains[j] = temp;
            }
        }
    }
    cout << "-------------------------------------------------";
    cout << "\n";
    // Введення часу, до якого потрібно знайти потяги
    string Time;
    cout << "Введіть час, до якого ви хочете знайти потяги: ";
    cin >> Time;
    cout << "-------------------------------------------------";
    cout << "\n";
    // Виведення інформації про потяги, які відправляються до зазначеного часу
    cout << "Потяги, що відправляються до " << Time << ":" << endl;
    cout << "-------------------------------------------------";
    cout << "\n";
    bool found = false;
    for (int i = 0; i < numTrains; i++) {
        if (isEarlierTime(trains[i].time, Time)) {
            cout << "Пункт призначення: " << trains[i].punkt << ", Номер потягу: " << trains[i].number << ", Час відправлення: " << trains[i].time << endl;
            cout << "\n";
            found = true;
        }
    }

    // Якщо не знайдено потягів до зазначеного часу
    if (!found) {
        cout << "Немає потягів, що відправляються до " << Time << "." << endl;
    }

    return 0;
}
