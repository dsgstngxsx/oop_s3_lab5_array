#include <iostream>

using namespace std;

template <typename T>
class arrays
{
private:
	T* arr;
	int size;
	int capacity;

	void increase()
	{
		capacity++;
		T* newArr = new T[capacity]; 
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i]; 
		}
		delete[] arr; //������� ������ ������
		arr = newArr; //��������� ��������� �� ������
	}
public:
	arrays(int initialCapacity = 1) : size(0), capacity(initialCapacity)
	{
		arr = new T[capacity];
	}
	~arrays()
	{
		delete[] arr;
	}
	void add(T element)
	{
		if (size >= capacity) //���� ������ ������� ������ ��� ����� ���������������
		{
			increase(); //����������� ���������������
		}
		arr[size] = element; //��������� ����� ������� � ����� �������
		size++; // ����������� ������� ������
	}
	void enter(int n)
	{
		if (n <= 0)
		{
			while (true)
			{
				cout << "The amount of the elements must be > 0" << std::endl;
				cout << "How many elements: ";
				cin >> n;
				if (n > 0) break; 
			}
		}

		for (int i = 0; i < n; i++)
		{
			T value; 
			cout << "Enter the element " << (i + 1) << ": ";
			cin >> value;
			add(value); // ��������� �������
		}
	}
	void new_elemenets()
	{
		int m;
		cout << "\nhow many of the new elements: ";
		cin >> m;

		if (m <= 0)
		{
			cout << "\nthe amount of the new elements must be > 0" << endl;
			new_elemenets();
		}

		for (int i = 0; i < m; i++)
		{
			T value;
			cout << "enter the new elements " << (i + 1) << ": ";
			cin >> value;
			add(value);

		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//����� �����������
	arrays copy() const
	{
		arrays arr2(size); //������2 � �������� ��� � ������� �������
		for (int i = 0; i < size; i++)
		{
			arr2.add(arr[i]); //��������� �������� �� ������� � ����� ������
		}
		return arr2;

	}

	//������� ��������
	void double_arr(const arrays& arr3) //(������ �� ������)
	{
		cout << "\nin which space do you want to place the copy of array? " << endl;
		int pos;

	here:

		cin >> pos;

		if (pos <= 0 || pos > size + 1) //���� ����� �� �������
		{
			cout << "wrong position" << endl;
			goto here;
		}

		while (size + arr3.size > capacity) //���� ����� �������� �������� ������ ���������������
		{
			increase(); //�� ����������� ��������������� 
		}
		for (int i = size - 1; i >= pos - 1; i--) // �������� ������ ����� �������1 
		{
			arr[i + arr3.size] = arr[i]; //�������� �������1 ���������� �� ����� �������
		}
		for (int i = 0; i < arr3.size; i++) //�������� �������� �������2 � ������1
		{
			arr[pos - 1 + i] = arr3.arr[i]; //�������� �������� �������2 � �������
		}
		size += arr3.size; //���������� ������ ������� 
	}
	T maxim()
	{
		T maxim = arr[0]; //������ ������� ������������
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > maxim) //���� ��������� ������� ������ �������������
			{
				maxim = arr[i]; //�� ���� ���� ������� ������������
			}
		}
		return maxim;
	}
};

void line()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~";
}
int main() {

	arrays<float> myArray; //������� ����� ������ 
	int n; //���-�� ���������

	cout << "how many elements: ";
	cin >> n;

	myArray.enter(n); //������ ��������

	cout << "\narray: ";
	myArray.print(); //����� ������� �� �����

	line();

	arrays<float> arr2 = myArray.copy(); //������� ������2, ������� ����� �������� ������ �������

	cout << "\ncopy of array: ";

	arr2.print(); //����� ����� �� �����

	line();
	cout << endl;

	myArray.new_elemenets(); //� ������ ������ ��������� ����� �������� � �����
	cout << "\nfinal array: ";

	myArray.print(); //����� ������������ �������

	line();
	cout << endl;

	myArray.double_arr(arr2); //������� ����� � ����������� ������

	cout << "\ndouble: ";

	myArray.print(); //����� �������� ������� 

	line();
	 //����� ����. �������� � ������� �������
	cout << "\nthe max element is : " << myArray.maxim() << endl; //����� ����.��������
	return 0;
}