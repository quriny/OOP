#include <iostream>
using namespace std;
class MaxHeap {
private:
	int* data;       //указатель на динамический массив данных
	int size;        //текущий размер кучи
	int capacity;    //Максимальная вместимость кучи
	//метод для перестройки кучи с корнем в заданном узле
	void heapify(int index) {
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		//находим индекс наибольшего элемента среди корня и его потомков
		if (left<size && data[left]>data[largest]) {
			largest = left;
		}
		if (right<size && data[right]>data[largest]) {
			largest = right;
		}
		//если наибольший элемент не корень, меняем их местами и продолжаем heapify
		if (largest!=index) {
			swap(data[index], data[largest]);
			heapify(largest);
		}
	}
public:
	//конструктор по умолчанию
	MaxHeap() {

	}
	//конструктор с заданной вместимостью 
	MaxHeap(int capacity) {
		this->capacity = capacity;
		size = 0;
		data = new int[capacity];
	}
	//деструктор для освобождения памяти
	~MaxHeap() {
		delete[] data;
	}
	//конструктор копирования
	MaxHeap(const MaxHeap& other) {
		capacity = other.capacity;
		size = other.size;
		data = new int[capacity];
		for (int i = 0;i<size;++i) {
			data[i] = other.data[i];
		}
	}
	//оператор присваивания
	MaxHeap& operator=(const MaxHeap& other) {
		if (this!=&other) {
			delete[] data;
			capacity = other.capacity;
			size = other.size;
			data = new int[capacity];
			for (int i = 0;i<size;i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	//Геттер для получения capasity
	int getCapasity() const {
		return capacity;
	}
	//Геттер для получения size
	int getSize() const {
	    return size;
    }
	//Геттер для получения значения по индексу
	int getValueAtIndex(int index) const {
		if (index >= 0 && index < size) {
			return data[index];
		}
		return -1; //возвращает -1, если индекс некорректный
	}
	//метод добалвения элемента в кучу
	void insert(int value) {
		if (size==capacity) {
			return;
		}
		int index = size++;
		data[index] = value;
		//поднимаем элемент вверх, чтобы восстановить свойство max-heap
		while (index>0 && data[index]>data[(index-1)/2]) {
			swap(data[index], data[(index-1)/2]);
			index = (index - 1) / 2;
		}
	}
	//метод для извлечения элемента из кучи
	void extract(int value) {
		int i;
		for (i = 0;i<size;++i) {
			if (data[i]==value) {
				break; //Находим первый подходящий элемент
			}
		}
		if (i==size) {
			return;
		}
		swap(data[i], data[--size]);
		heapify(i);
	}
	//метод извлечения всех элементов с заданным значением
	void extractAll(int value) {
		for (int i = 0;i<size;++i) {
			if (data[i]==value) {
				swap(data[i], data[--size]);
				heapify(i);
				--i;
			}
		}
	}
	//метод для проверки наличия элемента в куче
	bool contains(int value) const {
		for (int i = 0;i<size; ++i) {
			if (data[i]==value) {
					return true;
			}
			return false;
		}
	}
	//метод для объединения двух куч
	MaxHeap unionWith(const MaxHeap& other) {
		MaxHeap result(size+other.size);
		for (int i = 0;i<size;++i) {
			result.insert(data[i]);
		}
		for (int i = 0;i<other.size;++i) {
			result.insert(other.data[i]);
		}
		return result;
	}
	//метод для пересечения двух куч
	MaxHeap intersectWith(const MaxHeap& other) {
		MaxHeap result(min(size, other.size));
		for (int i = 0;i<size;++i) {
			if (other.contains(data[i]) && !result.contains(data[i])) {
				result.insert(data[i]);
			}
		}
		return result;
	}
	//оператор сравнения "больше"
	bool operator>(const MaxHeap& other) const{
		return size > other.size;
	}
	//оператор сравнения "меньше"
	bool operator<(const MaxHeap& other)const {
		return size < other.size;
	}
	//оператор сравнения "равно"
	bool operator==(const MaxHeap& other) const{
		if (size!=other.size) {
			return false;
		}
		for (int i = 0;i<size;++i) {
			if (data[i]!=other.data[i]) {
				return false;
			}
		}
		return true;
	}
	//перегруженный оператор для вывода на консоль  
	friend ostream& operator<<(ostream& os, const MaxHeap& heap) {
		for (int i = 0;i<heap.size;++i) {
			os << heap.data[i] << " ";
		}
		return os;
	}
};
