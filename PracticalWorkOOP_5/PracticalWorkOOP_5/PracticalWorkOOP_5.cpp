//Вариант 2
#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int size; //размер массива
    cout << "Введите количетсво транспортных средств . . ." << endl;
    cin >> size;//ввод данных
    //массив указателей 
    Vehicle** vehicles = new Vehicle * [size];
    //выбор типа транспортных средств
    for (int i = 0;i<size;++i) {
        cout << "Выберите тип транспорта:" << endl;
        cout << "1 - Машина" << endl;
        cout << "2 - Велосипед" << endl;
        cout << "3 - Грузовик" << endl;
        cout << "4 - Мотоцикл" << endl;
        cout << "5 - Электрокар" << endl;
        int button;
        cin >> button;
        Vehicle* vehicle = nullptr;
        switch (button) {
        case 1:
            vehicle = new Car();
            break;
        case 2:
            vehicle = new Bicycle();
            break;
        case 3:
            vehicle = new Truck();
            break;
        case 4:
            vehicle = new Motorcycle();
            break;
        case 5:
            vehicle = new ElectricCar();
            break;
        default:
            cout << "Введено некорректное значение . . ." << endl;
            vehicle = new Car();
        }
        vehicles[i] = vehicle;
    }
    //считаем количество каждого из типов транспорта
    int carCount = 0, bicycleCount = 0, truckCount = 0, motorcycleCount = 0, electricCarCount = 0;
    for (int i = 0; i < size; ++i) {
        if (dynamic_cast<Car*>(vehicles[i])) {
            carCount++;
        }
        else if (dynamic_cast<Bicycle*>(vehicles[i])) {
            bicycleCount++;
        }
        else if (dynamic_cast<Truck*>(vehicles[i])) {
            truckCount++;
        }
        else if (dynamic_cast<Motorcycle*>(vehicles[i])) {
            motorcycleCount++;
        }
        else if (dynamic_cast<ElectricCar*>(vehicles[i])) {
            electricCarCount++;
        }
    }
    //выводим счетчики
    cout << "Счетчики:" << endl;;
    cout << "Машины: " << carCount << endl;
    cout << "Велосипеды: " << bicycleCount << endl;
    cout << "Грузовики: " << truckCount << endl;
    cout << "Мотоциклы: " << motorcycleCount << endl;
    cout << "Электрокары: " << electricCarCount << endl;
    //вывод информации по каждому из объектов 
    for (int i = 0; i < size; ++i) {
        vehicles[i]->printInfo();
    }
    //очистка памяти
    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;

}