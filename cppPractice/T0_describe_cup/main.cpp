#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Date {
    public:
        int year;
        int month;
        int day;
};

class Cup
{
    public:
        string brand;
        Date dataBuild;
        string owner;
        string color;
        int container;
        int handler;

        int waterLeft;

    public:
        Cup(int water);
        Cup();
        ~Cup();
        int addWater(int i);
        virtual int drinkWater(int o);
};

Cup::Cup()
{
    cout << "Cup construct without param" << endl;
}

Cup::Cup(int water) : waterLeft(water)
{
    cout << "Cup constructor" << endl;
}

Cup::~Cup()
{
    cout << "Cup distructor" << endl;
}

int Cup::addWater(int i)
{
    if(waterLeft >= container) {
        cout << "err with Cup is full" << endl;
        return -100;
    }
    waterLeft = waterLeft + i;
    cout << "add water..." << endl;
    cout << "water left is: " << waterLeft << endl;
    return 0;
}

int Cup::drinkWater(int o)
{
    if(waterLeft - o <=0) {
        cout << "err with empty cup" << endl;
        return -100;
    }
    waterLeft = waterLeft - o;
    cout << "drinking water..." << endl;
    cout << "water left is: " << waterLeft << endl;

    return 0;
}

class MyCup : public Cup
{
    public:
        int cover;
       
    public:
        MyCup();
        MyCup(int w);
        ~MyCup();
        int turnON();
        int turnOFF();
        int drinkWater(int o);
};


MyCup::MyCup()
{
    cout << "My Cup constructor" << endl;
}

MyCup::MyCup(int water)
{
    waterLeft = water;
}

MyCup::~MyCup()
{
    cout << "My Cup disstructor" << endl;
}

int MyCup::turnON()
{
    cout << "do sth to turn on the cover" << endl;
    return 0;
}

int MyCup::turnOFF()
{
    cout << "do sth to turn OFF the cover" << endl;
    return 0;
}

int MyCup::drinkWater(int o)
{
    turnON();
    if(waterLeft - o <= 0) {
        cout << "Left no water..." << endl;
        turnOFF();
        return -100;
    }
    waterLeft = waterLeft - o;
    cout << "My cup drink water...." << endl;
    cout << "water left: " << waterLeft  << endl;
    turnOFF();

    return 0;
}

int main()
{
    MyCup myCup1(0);

    myCup1.brand = "Marathon";
    myCup1.container = 100;

    myCup1.addWater(100);
    myCup1.addWater(10);

    myCup1.drinkWater(80);
    myCup1.drinkWater(30);

    return 0;
}
