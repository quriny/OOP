//Вариант 3
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int input;
	MaxHeap heap;
	MaxHeap heap1;
	MaxHeap heap2;
	MaxHeap result;
	cout << "Со сколькими кучами вы будете работать? Введите: 1(С одной) или 2(С двумя). . ." << endl;
	do {
		cin >> input;
		if (input != 1 && input != 2) {
			cout << "Введено некорректное значение. . ." << endl;
		}
	} while (input!=1 && input!=2);
	if (input==1) {
		cout << "Для начала работы программы нужно создать кучу." << endl;
		cout << "Введите максимальную вместимость кучи. . ." << endl;
	    int capacity;
		cin >> capacity;
		heap = MaxHeap(capacity);
	}
	if (input==2) {
		cout << "Для начала работы программы нужно создать две кучи." << endl;
		cout << "Введите максимальную вместимость первой кучи. . ." << endl;
		int capacity1;
		cin >> capacity1;
		heap1 = MaxHeap(capacity1);
		cout << "Введите максимальную вместимость второй кучи. . ." << endl;
		int capacity2;
		cin >> capacity2;
		heap2 = MaxHeap(capacity2);

		result = MaxHeap(capacity1+capacity2);
	}
	int button;
	int element;
	do {
		cout << "=======Меню=======" << endl;
		cout << "1.Добавить элемент." << endl;
		cout << "2.Извлечь элемент по значению." << endl;
		cout << "3.Извлечь все элементы по значению." << endl;
		cout << "4.Проверить наличие элемента(без удаления)." << endl;
		cout << "5.Объединение двух куч." << endl;
		cout << "6.Пересечение двух куч." << endl;
		cout << "7.Сравнение двух куч по размеру." << endl;
		cout << "8.Выход." << endl;
		int inputButton;
        cin >> button;
		switch (button) {
		case 1:
			if (input == 1) {
				cout << "Введите элемент который хотите добавить. . ." << endl;
				cin >> element;
				heap.insert(element);
			}
			if (input==2) {
				int input2;
				cout << "В какую кучу вы хотите добавить элемент? Введите: 1(В первую) или 2(Во вторую). . ." << endl;
				cin >> input2;
				if (input2==1) {
					cout << "Введите элемент который хотите добавить. . ." << endl;
					cin >> element;
					heap1.insert(element);
				}
				if (input2 == 2) {
					cout << "Введите элемент который хотите добавить. . ." << endl;
					cin >> element;
					heap2.insert(element);
				}
			}
			break;
		case 2:
			if (input == 1) {
				cout << "Введите значение элемента, который хотите извлечь. . ." << endl;
				cin >> element;
				heap.extract(element);
			}
			if (input == 2) {
				int input2;
				cout << "Из какой кучи вы хотите извлечь элемент? Введите: 1(В первую) или 2(Во вторую). . ." << endl;
				cin >> input2;
				if (input2 == 1) {
					cout << "Введите значение элемента, который хотите извлечь. . ." << endl;
					cin >> element;
					heap1.extract(element);
				}
				if (input2 == 2) {
					cout << "Введите значение элемента, который хотите извлечь. . ." << endl;
					cin >> element;
					heap2.extract(element);
				}
			}
			break;
		case 3:
			if (input == 1) {
				cout << "Введите значение, элементы с которым вы хотите извлечь. . ." << endl;
				cin >> element;
				heap.extractAll(element);
			}
			if (input == 2) {
				int input2;
				cout << "Из какой кучи вы хотите извлечь все элементы по значению? Введите: 1(Из первой) или 2(Из второй). . ." << endl;
				cin >> input2;
				if (input2 == 1) {
					cout << "Введите значение, элементы с которым вы хотите извлечь. . ." << endl;
					cin >> element;
					heap1.extractAll(element);
				}
				if (input2 == 2) {
					cout << "Введите значение, элементы с которым вы хотите извлечь. . ." << endl;
					cin >> element;
					heap2.extractAll(element);
				}
			}
			break;
		case 4:
			if (input == 1) {
				cout << "Введите значение, наличие которого в куче в хотите проверить. . ." << endl;
				cin >> element;
				cout << heap.contains(element) << endl;
			}
			if (input == 2) {
				int input2;
				cout << "В какой куче вы хотите проверить наличие элемента? Введите: 1(Из первой) или 2(Из второй). . ." << endl;
				cin >> input2;
				if (input2 == 1) {
					cout << "Введите значение, наличие которого в куче в хотите проверить. . ." << endl;
					cin >> element;
					cout << heap1.contains(element) << endl;
				}
				if (input2 == 2) {
					cout << "Введите значение, наличие которого в куче в хотите проверить. . ." << endl;
					cin >> element;
					cout << heap2.contains(element) << endl;
				}
			}
			break;
		case 5:
			if (input==1) {
				cout << "Для данной операции нужно две кучи. . ." << endl;
			}
			if (input==2) {
				result = heap1.unionWith(heap2);
				cout << "Ваши кучи объединены." << endl;
				cout << "Результат объединения: "<< result << endl;
			}
			break;
		case 6:
			if (input == 1) {
				cout << "Для данной операции нужно две кучи. . ." << endl;
			}
			if (input == 2) {
				result = heap1.intersectWith(heap2);
				cout << "Найдено пересечение." << endl;
				cout << "Результат пересечения: " << result << endl;
			}
			break;
		case 7:
			if (input == 1) {
				cout << "Для данной операции нужно две кучи. . ." << endl;
			}
			if (input == 2) {
				if (heap1==heap2) {
					cout << "Кучи по размеру равны." << endl;
				}
				else if (heap1<heap2) {
					cout << "Первая куча меньше." << endl;
				}
				else {
					cout << "Вторая куча меньше." << endl;
				}
			}
			break;
		default:
			cout << "Такой команды не существует. . ." << endl;
			break;
		}
	} while (button!=8);

}
