#pragma once
#include <iostream>
using namespace std;
//������� ����� (������ ������� � ��������)
class Vehicle {
private:
	string owner; //�������� ����������
	int speed; //�������� ����������
public:
	Vehicle(){}
	//�����������
	Vehicle(string owner="0", int speed=0) : owner(owner), speed(speed) {}
	//�������� ��� ���������
	string getOwner() {
		return owner;
	}
	//������ ��������
	int getSpeed() {
		return speed;
	}
	//��������� ���������� � ����������
	virtual void printInfo() {
		cout << "�������� ������� ������������� ��������: " << owner << "." << endl;
		cout << "�������� ������� ������������� �������� ���������� " << speed << " �� � ���." << endl;
	}
	//���������
	virtual void accelerate() {
		cout << "�����������. ������� ��������: " << speed << " �� � ���." << endl;
	}
	//����������
	virtual void brake() {
		cout << "��������. ������� ��������: " << speed << " �� � ���." << endl;
	}
};
//��������� �������� ������ (������ ������� � ��������)
class Car : public Vehicle {
private:
	const static int MaximumSpeed=150;
	string brand;  //����� ������
public:
	//�����������
	Car(string owner="0", int speed=0, string brand="0") : Vehicle(owner, speed), brand(brand) {}
	//�������� �������� ������
	string getBrand() {
		return brand;
	}
	//�������������� ��������� ���������� � ����������
	void printInfo() override{
		cout << "�������� ������ ������: " << getOwner() << "." << endl;
		cout << "�������� ������ ������ ���������� " << getSpeed() << " �� � ���." << endl;
		cout << "�������� ������ ������ " << brand << endl;
	}
	//�������������� ���������
	void accelerate() override {
		cout << "������ ����������. ������� ��������: " << getSpeed() << " �� � ���." << endl;
	}
	//�������������� ����������
	void brake() override{
		cout << "������ ��������. ������� ��������: " << getSpeed() << " �� � ���." << endl;
	}
	//������ ���� �������� ����������
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};
//��������� ������ ������� ������ � �������� (������ ������� � ��������)
class ElectricCar : public Car {
private:
	int batteryCapacity; //����������� ������������ �����������
public:
	//�����������
	ElectricCar(string owner="0", int speed = 0, string brand = "0", int batteryCapacity = 0)
		: Car(owner, speed, brand), batteryCapacity(batteryCapacity) {}
	//�������������� ��������� ���������� � ����������
	void printInfo() override {
		cout << "�������� ������� �����������: " << getOwner() << "." << endl;
		cout << "�������� ������� ����������� ���������� " << getSpeed() << " �� � ���." << endl;
		cout << "�������� ������ ����������� " << getBrand() << endl;
		cout << "����������� ������� " << batteryCapacity << endl;
	}
	//�������������� ���������
	void accelerate() override {
		cout << "���������� ����������. ������� ��������: " << getSpeed() << " �� � ���." << endl;
	}
	//�������������� ����������
	void brake() override {
		cout << "���������� ��������. ������� ��������: " << getSpeed() << " �� � ���." << endl;
	}
};
//��������� �������� ������ (������ ������� � ��������)
class Bicycle : public Vehicle {
private:
	const static int MaximumSpeed = 30;
	int gears; //���������� ������� ����������
public:
	//�����������
	Bicycle(string owner="0", int speed=0, int gears=0) : Vehicle(owner, speed), gears(gears) {}
	//������ ���� �������� ����������
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};
//��������� �������� ������ (������ ������� � ��������)
class Truck : public Vehicle {
private:
	const static int MaximumSpeed = 100;
	int cargoCapacity;
public:
	//�����������
	Truck(string owner="0", int speed=0, int cargoCapacity=0) : Vehicle(owner, speed), cargoCapacity(cargoCapacity) {}
	//��������� �����������
	int getCargoCapacity() {
		return cargoCapacity;
	}
	//�������������� ��������� ����������
	void printInfo() override {
		cout << "�������� ������� ���������: " << getOwner() << "." << endl;
		cout << "�������� ������� ��������� ���������� " << getSpeed() << " �� � ���." << endl;
		cout << "����������� ������� ��������� ���������� " << cargoCapacity << endl;
	}
	//�������������� ���������
	void accelerate() override {
		cout << "�������� ����������. ������� ��������: " << getSpeed() << " �� � ���." << endl;
	}
	//�������������� ����������
	void brake() override {
		cout << "�������� ��������. ������� ��������: " << getSpeed() << " �� � ���." << endl;
	}
	//������ ���� �������� ����������
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};
//��������� �������� ������ (������ ������� � ��������)
class Motorcycle : public Vehicle {
private:
	const static int MaximumSpeed = 110;
	string type; //��� ���������
public:
	//�����������
	Motorcycle(string owner="0", int speed=0, string type="0") : Vehicle(owner, speed), type(type) {}
	//������ ���� �������� ����������
	static int getMaximumSpeed() {
		return MaximumSpeed;
	}
};