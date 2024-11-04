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
		T* newArr = new T[capacity]; // Создаем новый массив с увеличенной вместительностью
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i]; // Копируем старые элементы
		}
		delete[] arr; // Удаляем старый массив
		arr = newArr; // Обновляем указатель на массив
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
		if (size >= capacity) // Если размер массива больше или равен вместительности
		{
			increase(); // Увеличиваем вместительность
		}
		arr[size] = element; // Добавляем новый элемент в конец массива
		size++; // Увеличиваем текущий размер
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
				if (n > 0) break; // Проверяем ввод
			}
		}

		for (int i = 0; i < n; i++)
		{
			T value; // Изменено на T для поддержки различных типов
			cout << "Enter the element " << (i + 1) << ": ";
			cin >> value;
			add(value); // Добавляем элемент
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

	//метод копирования
	arrays copy() const
	{
		arrays arr2(size); //массив2 с размером как у первого массива
		for (int i = 0; i < size; i++)
		{
			arr2.add(arr[i]); //добавляем элементы из первого в новый массив
		}
		return arr2;

	}

	//вставка массивов
	void double_arr(const arrays& arr3) //(ссылка на массив)
	{
		cout << "\nin which space do you want to place the copy of array? " << endl;
		int pos;

	here:

		cin >> pos;

		if (pos <= 0 || pos > size + 1) //если вышли за пределы
		{
			cout << "wrong position" << endl;
			goto here;
		}

		while (size + arr3.size > capacity) //если сумма размеров массивов больше вместительности
		{
			increase(); //то увеличиваем вместительность 
		}
		for (int i = size - 1; i >= pos - 1; i--) // сдвигаем вправо часть массива1 
		{
			arr[i + arr3.size] = arr[i]; //элементы массива1 копируются на новые позиции
		}
		for (int i = 0; i < arr3.size; i++) //копируем элементы массива2 в массив1
		{
			arr[pos - 1 + i] = arr3.arr[i]; //копируем элементы массива2 в позицию
		}
		size += arr3.size; //обнвовляем размер массива 
	}
	T maxim()
	{
		T maxim = arr[0]; //первый элемент максимальный
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > maxim) //если следующий элемент больше максимального
			{
				maxim = arr[i]; //то этот этот элемент максимальный
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

	arrays<string> myArray; //создаем новый массив 
	int n; //кол-во элементов

	cout << "how many elements: ";
	cin >> n;

	myArray.enter(n); //вводим элементы

	cout << "\n" << "array: ";
	myArray.print(); //вывод массива на экран

	line();

	arrays<string> arr2 = myArray.copy(); //создаем массив2, который будет являться копией первого

	cout << "\n" << "copy of array: ";

	arr2.print(); //вывод копии на экран

	line();
	cout << "\n";

	myArray.new_elemenets(); //в первый массив добавляем новые элементы в конец
	cout << "\n" << "final array: ";

	myArray.print(); //вывод обновленного массива

	line();
	cout << "\n";

	myArray.double_arr(arr2); //вставка копии в обновленный массив

	cout << "\ndouble: ";

	myArray.print(); //вывод большого массива 

	line();
	 //поиск макс. элемента в большом массиве
	cout << "\n" << "the max element is : " << myArray.maxim() << endl; //вывод макс.элемента
	return 0;
}