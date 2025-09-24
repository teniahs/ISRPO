// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "Treygolnik.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    vector<Treygolnik> massivTreugolnikov;
    int n;

    cout << "Введите количество треугольников: ";
    cin >> n;

    // Ввод данных для каждого треугольника
    for (int i = 0; i < n; ++i) {
        cout << "Введите данные для треугольника #" << i + 1 << ":" << endl;
        Treygolnik treugolnik = ввестиTreugolnik();
        // Проверяем, создан ли треугольник с корректными данными
        if (treugolnik.getStorona() > 0) {
            massivTreugolnikov.push_back(treugolnik);
        }
        else {
            cout << "Треугольник не был добавлен из-за некорректных данных." << endl;
        }
    }

    // Демонстрационная программа
    int vibor;
    do {
        cout << "\nВыберите действие:" << endl;
        cout << "1. Вывести информацию о всех треугольниках" << endl;
        cout << "2. Изменить угол у треугольника" << endl;
        cout << "3. Вычислить высоту треугольника" << endl;
        cout << "4. Определить значения сторон треугольника" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> vibor;

        switch (vibor) {
        case 1: {
            if (massivTreugolnikov.empty()) {
                cout << "Массив треугольников пуст." << endl;
                break;
            }
            for (size_t i = 0; i < massivTreugolnikov.size(); ++i) {
                massivTreugolnikov[i].vivestiInformaciyu(i + 1);
            }
            break;
        }
        case 2: {
            if (massivTreugolnikov.empty()) {
                cout << "Массив треугольников пуст." << endl;
                break;
            }
            int index, nomerUgla;
            double procentIzmeneniya;
            cout << "Введите номер треугольника (1-" << massivTreugolnikov.size() << "): ";
            cin >> index;
            if (index < 1 || index > massivTreugolnikov.size()) {
                cout << "Неверный номер треугольника." << endl;
                break;
            }
            cout << "Введите номер угла (1 или 2): ";
            cin >> nomerUgla;
            cout << "Введите процент изменения: ";
            cin >> procentIzmeneniya;
            if (massivTreugolnikov[index - 1].izmenitUgol(nomerUgla, procentIzmeneniya)) {
                cout << "Угол успешно изменен." << endl;
            }
            break;
        }
        case 3: {
            if (massivTreugolnikov.empty()) {
                cout << "Массив треугольников пуст." << endl;
                break;
            }
            int index;
            cout << "Введите номер треугольника (1-" << massivTreugolnikov.size() << "): ";
            cin >> index;
            if (index < 1 || index > massivTreugolnikov.size()) {
                cout << "Неверный номер треугольника." << endl;
                break;
            }
            cout << "Высота треугольника: " << massivTreugolnikov[index - 1].vichislitVisotu() << endl;
            break;
        }
        case 4: {
            if (massivTreugolnikov.empty()) {
                cout << "Массив треугольников пуст." << endl;
                break;
            }
            int index;
            cout << "Введите номер треугольника (1-" << massivTreugolnikov.size() << "): ";
            cin >> index;
            if (index < 1 || index > massivTreugolnikov.size()) {
                cout << "Неверный номер треугольника." << endl;
                break;
            }
            double storona1, storona2;
            massivTreugolnikov[index - 1].opredelitStoroni(storona1, storona2);
            cout << "Сторона 1: " << storona1 << endl;
            cout << "Сторона 2: " << storona2 << endl;
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
        }
    } while (vibor != 0);

    return 0;
}
    /// Функция для запроса ввода данных треугольника у пользователя
Treygolnik ввестиTreugolnik() {
    double s, u1, u2;
    cout << "Введите сторону: ";
    cin >> s;
    cout << "Введите угол 1: ";
    cin >> u1;
    cout << "Введите угол 2: ";
    cin >> u2;

    Treygolnik treugolnik(s, u1, u2);
    if (!treugolnik.setProperties(s, u1, u2)) {
        // Если введены некорректные данные, создаем треугольник с нулевыми значениями
        return Treygolnik(0, 0, 0);
    }

    return treugolnik;
}
    
