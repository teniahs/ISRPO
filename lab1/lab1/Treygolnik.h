#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
class Treygolnik
{
private:
    double storona;
    double ugol1;
    double ugol2;
    const double M_PI = 3.14;



public:
    // Конструктор класса
    Treygolnik(double s, double u1, double u2) : storona(s), ugol1(u1), ugol2(u2) {}

    // Метод установки свойств с проверкой на допустимые значения
    bool setProperties(double s, double u1, double u2) {
        if (s <= 0 || u1 <= 0 || u2 <= 0 || u1 + u2 >= 180) {
            cout << "Ошибка: Недопустимые значения свойств треугольника." << endl;
            return false;
        }
        storona = s;
        ugol1 = u1;
        ugol2 = u2;
        return true;
    };
    // Геттеры для доступа к свойствам
    double getStorona() const { return storona; }
    double getUgol1() const { return ugol1; }
    double getUgol2() const { return ugol2; }

    // Операции:

    // 1. Увеличение/уменьшение значения угла на заданное количество процентов
    bool izmenitUgol(int nomerUgla, double procentIzmeneniya) {
        double izmenennoeZnachenie;
        if (nomerUgla == 1) {
            izmenennoeZnachenie = ugol1 * (1 + procentIzmeneniya / 100.0);
            if (izmenennoeZnachenie <= 0 || izmenennoeZnachenie + ugol2 >= 180) {
                cout << "Ошибка: Недопустимое значение угла после изменения." << endl;
                return false;
            }
            ugol1 = izmenennoeZnachenie;
        }
        else if (nomerUgla == 2) {
            izmenennoeZnachenie = ugol2 * (1 + procentIzmeneniya / 100.0);
            if (izmenennoeZnachenie <= 0 || ugol1 + izmenennoeZnachenie >= 180) {
                cout << "Ошибка: Недопустимое значение угла после изменения." << endl;
                return false;
            }
            ugol2 = izmenennoeZnachenie;
        }
        else {
            cout << "Ошибка: Неверный номер угла." << endl;
            return false;
        }
        return true;
    }

    // 2. Вычисление длины высоты, принадлежащей стороне
    double vichislitVisotu() const {
        // Используем формулу: h = a * sin(угол1) * sin(угол2) / sin(угол1 + угол2)
        double ugol3 = 180 - ugol1 - ugol2;
        return storona * sin(ugol1 * M_PI / 180.0) * sin(ugol2 * M_PI / 180.0) / sin(ugol3 * M_PI / 180.0);
    }

    // 3. Определение значений сторон
    void opredelitStoroni(double& storona1, double& storona2) const {
        double ugol3 = 180 - ugol1 - ugol2;
        storona1 = storona * sin(ugol1 * M_PI / 180.0) / sin(ugol3 * M_PI / 180.0);
        storona2 = storona * sin(ugol2 * M_PI / 180.0) / sin(ugol3 * M_PI / 180.0);
    }

    // Вывод информации о треугольнике
    void vivestiInformaciyu(int index) const {
        cout << "Треугольник #" << index << ":" << endl;
        cout << "  Сторона: " << storona << endl;
        cout << "  Угол 1: " << ugol1 << endl;
        cout << "  Угол 2: " << ugol2 << endl;
    }

    void vivestiVsyo() const
    {
        cout << "  Сторона: " << fixed << setprecision(2) << setw(10) << storona << endl;
        cout << "  Угол 1:   " << fixed << setprecision(2) << setw(10) << ugol1 << endl;
        cout << "  Угол 2:   " << fixed << setprecision(2) << setw(10) << ugol2 << endl;
    }
};

// Объявление функции для запроса ввода данных треугольника у пользователя
Treygolnik ввестиTreugolnik();