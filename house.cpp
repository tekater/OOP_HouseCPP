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

 class House {

 };

 class Flats {
     int number;
     int residents;

     
 public:
     Human* man;
     explicit Flats( Human* pepl,int num, int res) :number{ num }, residents{ res } {
         man = new Human[res];
         for (int i = 0; i < res; i++) {
             man[i].setName( pepl[i].getName() );
         }
         
     };
     Flats() :Flats(man, 1, 1) {};

     void setNum(int num) {
         number = num;
     }
     void setRes(int res) {
         residents = res;
     }
     void setHuman(Human& h,int index) {
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

     }

 };

int main() {

    setlocale(0, "");
    srand(time(NULL));

    Human h[3]{
        Human{"Олег",22},
        Human{"Вадим",22},
        Human{"НеВадим",22}
    };

    Flats f{h,12,3};
    f.print();
    f.setHuman(h[2], 1);
    cout << "\n";

    //f.man[0].setName("Вася");
    f.print();
}
