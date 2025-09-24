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
    // ����������� ������
    Treygolnik(double s, double u1, double u2) : storona(s), ugol1(u1), ugol2(u2) {}

    // ����� ��������� ������� � ��������� �� ���������� ��������
    bool setProperties(double s, double u1, double u2) {
        if (s <= 0 || u1 <= 0 || u2 <= 0 || u1 + u2 >= 180) {
            cout << "������: ������������ �������� ������� ������������." << endl;
            return false;
        }
        storona = s;
        ugol1 = u1;
        ugol2 = u2;
        return true;
    };
    // ������� ��� ������� � ���������
    double getStorona() const { return storona; }
    double getUgol1() const { return ugol1; }
    double getUgol2() const { return ugol2; }

    // ��������:

    // 1. ����������/���������� �������� ���� �� �������� ���������� ���������
    bool izmenitUgol(int nomerUgla, double procentIzmeneniya) {
        double izmenennoeZnachenie;
        if (nomerUgla == 1) {
            izmenennoeZnachenie = ugol1 * (1 + procentIzmeneniya / 100.0);
            if (izmenennoeZnachenie <= 0 || izmenennoeZnachenie + ugol2 >= 180) {
                cout << "������: ������������ �������� ���� ����� ���������." << endl;
                return false;
            }
            ugol1 = izmenennoeZnachenie;
        }
        else if (nomerUgla == 2) {
            izmenennoeZnachenie = ugol2 * (1 + procentIzmeneniya / 100.0);
            if (izmenennoeZnachenie <= 0 || ugol1 + izmenennoeZnachenie >= 180) {
                cout << "������: ������������ �������� ���� ����� ���������." << endl;
                return false;
            }
            ugol2 = izmenennoeZnachenie;
        }
        else {
            cout << "������: �������� ����� ����." << endl;
            return false;
        }
        return true;
    }

    // 2. ���������� ����� ������, ������������� �������
    double vichislitVisotu() const {
        // ���������� �������: h = a * sin(����1) * sin(����2) / sin(����1 + ����2)
        double ugol3 = 180 - ugol1 - ugol2;
        return storona * sin(ugol1 * M_PI / 180.0) * sin(ugol2 * M_PI / 180.0) / sin(ugol3 * M_PI / 180.0);
    }

    // 3. ����������� �������� ������
    void opredelitStoroni(double& storona1, double& storona2) const {
        double ugol3 = 180 - ugol1 - ugol2;
        storona1 = storona * sin(ugol1 * M_PI / 180.0) / sin(ugol3 * M_PI / 180.0);
        storona2 = storona * sin(ugol2 * M_PI / 180.0) / sin(ugol3 * M_PI / 180.0);
    }

    // ����� ���������� � ������������
    void vivestiInformaciyu(int index) const {
        cout << "����������� #" << index << ":" << endl;
        cout << "  �������: " << storona << endl;
        cout << "  ���� 1: " << ugol1 << endl;
        cout << "  ���� 2: " << ugol2 << endl;
    }

    void vivestiVsyo() const
    {
        cout << "  �������: " << fixed << setprecision(2) << setw(10) << storona << endl;
        cout << "  ���� 1:   " << fixed << setprecision(2) << setw(10) << ugol1 << endl;
        cout << "  ���� 2:   " << fixed << setprecision(2) << setw(10) << ugol2 << endl;
    }
};

// ���������� ������� ��� ������� ����� ������ ������������ � ������������
Treygolnik ������Treugolnik();