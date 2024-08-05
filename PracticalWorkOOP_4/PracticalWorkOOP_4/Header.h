#include <iostream>
using namespace std;
class MaxHeap {
private:
	int* data;       //��������� �� ������������ ������ ������
	int size;        //������� ������ ����
	int capacity;    //������������ ����������� ����
	//����� ��� ����������� ���� � ������ � �������� ����
	void heapify(int index) {
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		//������� ������ ����������� �������� ����� ����� � ��� ��������
		if (left<size && data[left]>data[largest]) {
			largest = left;
		}
		if (right<size && data[right]>data[largest]) {
			largest = right;
		}
		//���� ���������� ������� �� ������, ������ �� ������� � ���������� heapify
		if (largest!=index) {
			swap(data[index], data[largest]);
			heapify(largest);
		}
	}
public:
	//����������� �� ���������
	MaxHeap() {

	}
	//����������� � �������� ������������ 
	MaxHeap(int capacity) {
		this->capacity = capacity;
		size = 0;
		data = new int[capacity];
	}
	//���������� ��� ������������ ������
	~MaxHeap() {
		delete[] data;
	}
	//����������� �����������
	MaxHeap(const MaxHeap& other) {
		capacity = other.capacity;
		size = other.size;
		data = new int[capacity];
		for (int i = 0;i<size;++i) {
			data[i] = other.data[i];
		}
	}
	//�������� ������������
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
	//������ ��� ��������� capasity
	int getCapasity() const {
		return capacity;
	}
	//������ ��� ��������� size
	int getSize() const {
	    return size;
    }
	//������ ��� ��������� �������� �� �������
	int getValueAtIndex(int index) const {
		if (index >= 0 && index < size) {
			return data[index];
		}
		return -1; //���������� -1, ���� ������ ������������
	}
	//����� ���������� �������� � ����
	void insert(int value) {
		if (size==capacity) {
			return;
		}
		int index = size++;
		data[index] = value;
		//��������� ������� �����, ����� ������������ �������� max-heap
		while (index>0 && data[index]>data[(index-1)/2]) {
			swap(data[index], data[(index-1)/2]);
			index = (index - 1) / 2;
		}
	}
	//����� ��� ���������� �������� �� ����
	void extract(int value) {
		int i;
		for (i = 0;i<size;++i) {
			if (data[i]==value) {
				break; //������� ������ ���������� �������
			}
		}
		if (i==size) {
			return;
		}
		swap(data[i], data[--size]);
		heapify(i);
	}
	//����� ���������� ���� ��������� � �������� ���������
	void extractAll(int value) {
		for (int i = 0;i<size;++i) {
			if (data[i]==value) {
				swap(data[i], data[--size]);
				heapify(i);
				--i;
			}
		}
	}
	//����� ��� �������� ������� �������� � ����
	bool contains(int value) const {
		for (int i = 0;i<size; ++i) {
			if (data[i]==value) {
					return true;
			}
			return false;
		}
	}
	//����� ��� ����������� ���� ���
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
	//����� ��� ����������� ���� ���
	MaxHeap intersectWith(const MaxHeap& other) {
		MaxHeap result(min(size, other.size));
		for (int i = 0;i<size;++i) {
			if (other.contains(data[i]) && !result.contains(data[i])) {
				result.insert(data[i]);
			}
		}
		return result;
	}
	//�������� ��������� "������"
	bool operator>(const MaxHeap& other) const{
		return size > other.size;
	}
	//�������� ��������� "������"
	bool operator<(const MaxHeap& other)const {
		return size < other.size;
	}
	//�������� ��������� "�����"
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
	//������������� �������� ��� ������ �� �������  
	friend ostream& operator<<(ostream& os, const MaxHeap& heap) {
		for (int i = 0;i<heap.size;++i) {
			os << heap.data[i] << " ";
		}
		return os;
	}
};
