#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;
class Date {
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    Date() : Date(1, 2, 2000) {};
    void print() {
        cout << day << "." << month << "." << year << "\n";
    }
    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }

    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
};


class Human {
    char* name;
    int age;

public:

    const Human(const char* uname, int year) :age{ year } {
        name = new char[strlen(uname) + 1];
        strcpy(name, uname);
    }
    Human() :Human{ "Noname",18 } {};

    void setAge(int year) {
        age = year;
    }

    void setName(const char* uname) {
        delete[] name;
        name = new char[strlen(uname) + 1];
        strcpy(name, uname);
    }

    int getAge() {
        return age;
    }
    const char* getName() {
        return name;
    }

    ~Human() {
        delete[] name;
    }
};

class Flats {
    int number;
    int residents;


public:
    Human* man;
    explicit Flats(Human* pepl, int num, int res) :number{ num }, residents{ res } {
        man = new Human[res];
        for (int i = 0; i < res; i++) {
            man[i].setName(pepl[i].getName());
        }

    };
    Flats() :Flats(man, 1, 1) {};

    void setNum(int num) {
        number = num;
    }
    void setRes(int res) {
        residents = res;
    }
    void setHuman(Human& h, int index) {
        man[index].setName(h.getName());
        man[index].setAge(h.getAge());
    }
    int getNum() {
        return number;
    }
    int getRes() {
        return residents;
    }

    void print() {
        cout << "Номер: " << number << endl;
        cout << "Проживающие: " << residents << endl;
        cout << "Жители: ";
        for (int i = 0; i < residents; i++) {
            cout << man[i].getName() << " ";
        }

    }

    ~Flats() {
        delete[] man;
    }

};

class House {
    char* addres;
    int numCounter;
    char* info;
public:
    Flats* falts;

    explicit House(Flats* fflats, const char* address, int num, const char* uinfo) {
        addres = new char[strlen(address) + 1];
        strcpy(addres, address);
        falts = new Flats[num];
        info = new char[strlen(uinfo) + 1];
        strcpy(info, uinfo);
        numCounter = num;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < falts[i].getRes(); i++) {
                falts[i].setNum(fflats[i].getNum());
                falts[i].man[j].setName(fflats[i].man[i].getName());
                falts[i].man[j].setAge(fflats[i].man[i].getAge());
                falts[i].setRes(fflats[i].getRes());
            }
        }
    }

    House() : House(falts, "Okupkino", 1, "Silents") {};


    void setAddres(const char* add) {
        delete[]addres;
        addres = new char[strlen(add) + 1];
        strcpy(addres, add);
    }
    void print() {
        cout << "Количество квартир: " << numCounter << "\n";
        cout << "Адрес: " << addres << "\n";
        cout << "Информация: " << info << "\n";

        for (int i = 0; i < numCounter; i++) {
            falts[i].print();
            cout << endl;
        }

    }
    ~House() {
        delete[] falts;
        delete[] addres;
        delete[] info;
    }
};

int main() {

    setlocale(0, "");
    srand(time(NULL));

    Human hu[3]{
        Human{"Олег",22},
        Human{"Вадим",22},
        Human{"НеВадим",22}
    };

    Human hu2[3]{
        Human{"Вадим",22},
        Human{"Маша",22},
        Human{"Олег",22}
    };


    Flats fl[2]{
        Flats{ hu,12,3 },
        Flats{hu2,13,3}
    };

    House Hom(fl, "oko",2,"silents");
    Hom.print();
}
