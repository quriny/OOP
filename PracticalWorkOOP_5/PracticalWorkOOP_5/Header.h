#pragma once
#include <iostream>
using namespace std;
//базовый класс (первый уровень в иерархии)
class Vehicle {
private:
	string owner; //владелец транспорта
	int speed; //скорость транспорта
public:
	Vehicle(){}
	//конструктор
	Vehicle(string owner="0", int speed=0) : owner(owner), speed(speed) {}
	//получить имя владельца
	string getOwner() {
		return owner;
	}
	//узнать скорость
	int getSpeed() {
		return speed;
	}
	//получение информации о транспорте
	virtual void printInfo() {
		cout << "Владелец данного транспортного средства: " << owner << "." << endl;
		cout << "Скорость данного транспортного средства составляет " << speed << " км в час." << endl;
	}
	//ускорение
	virtual void accelerate() {
		cout << "Ускореяемся. Текущая скорость: " << speed << " км в час." << endl;
	}
	//торможение
	virtual void brake() {
		cout << "Тормозим. Текущая скорость: " << speed << " км в час." << endl;
	}
};
//наследник базового класса (второй уровень в иерархии)
class Car : public Vehicle {
private:
	const static int MaximumSpeed=150;
	string brand;  //бренд машины
public:
	//конструктор
	Car(string owner="0", int speed=0, string brand="0") : Vehicle(owner, speed), brand(brand) {}
	//получить название бренда
	string getBrand() {
		return brand;
	}
	//переопределяем получение информации о транспорте
	void printInfo() override{
		cout << "Владелец данной машины: " << getOwner() << "." << endl;
		cout << "Скорость данной машины составляет " << getSpeed() << " км в час." << endl;
		cout << "Название бренда машины " << brand << endl;
	}
	//переопределяем ускорение
	void accelerate() override {
		cout << "Машина ускоряется. Текущая скорость: " << getSpeed() << " км в час." << endl;
	}
	//переопределяем торможение
	void brake() override{
		cout << "Машина тормозит. Текущая скорость: " << getSpeed() << " км в час." << endl;
	}
	//узнать макс скорость транспорта
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};
//наследник класса второго уровня в иерархии (третий уровень в иерархии)
class ElectricCar : public Car {
private:
	int batteryCapacity; //вместимость аккумулятора электрокара
public:
	//конструктор
	ElectricCar(string owner="0", int speed = 0, string brand = "0", int batteryCapacity = 0)
		: Car(owner, speed, brand), batteryCapacity(batteryCapacity) {}
	//переопределяем получение информации о транспорте
	void printInfo() override {
		cout << "Владелец данного электрокара: " << getOwner() << "." << endl;
		cout << "Скорость данного электрокара составляет " << getSpeed() << " км в час." << endl;
		cout << "Название бренда электрокара " << getBrand() << endl;
		cout << "Вместимость батареи " << batteryCapacity << endl;
	}
	//переопределяем ускорение
	void accelerate() override {
		cout << "Электрокар ускоряется. Текущая скорость: " << getSpeed() << " км в час." << endl;
	}
	//переопределяем торможение
	void brake() override {
		cout << "Электрокар тормозит. Текущая скорость: " << getSpeed() << " км в час." << endl;
	}
};
//наследник базового класса (второй уровень в иерархии)
class Bicycle : public Vehicle {
private:
	const static int MaximumSpeed = 30;
	int gears; //количество передач велосипеда
public:
	//конструктор
	Bicycle(string owner="0", int speed=0, int gears=0) : Vehicle(owner, speed), gears(gears) {}
	//узнать макс скорость транспорта
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};
//наследник базового класса (второй уровень в иерархии)
class Truck : public Vehicle {
private:
	const static int MaximumSpeed = 100;
	int cargoCapacity;
public:
	//конструктор
	Truck(string owner="0", int speed=0, int cargoCapacity=0) : Vehicle(owner, speed), cargoCapacity(cargoCapacity) {}
	//получение вместимости
	int getCargoCapacity() {
		return cargoCapacity;
	}
	//переопределяем получение информации
	void printInfo() override {
		cout << "Владелец данного грузовика: " << getOwner() << "." << endl;
		cout << "Скорость данного грузовика составляет " << getSpeed() << " км в час." << endl;
		cout << "Вместимость данного грузовика составляет " << cargoCapacity << endl;
	}
	//переопределяем ускорение
	void accelerate() override {
		cout << "Грузовик ускоряется. Текущая скорость: " << getSpeed() << " км в час." << endl;
	}
	//переопределяем торможение
	void brake() override {
		cout << "Грузовик тормозит. Текущая скорость: " << getSpeed() << " км в час." << endl;
	}
	//узнать макс скорость транспорта
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};
//наследник базового класса (второй уровень в иерархии)
class Motorcycle : public Vehicle {
private:
	const static int MaximumSpeed = 110;
	string type; //тип мотоцикла
public:
	//конструктор
	Motorcycle(string owner="0", int speed=0, string type="0") : Vehicle(owner, speed), type(type) {}
	//узнать макс скорость транспорта
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};