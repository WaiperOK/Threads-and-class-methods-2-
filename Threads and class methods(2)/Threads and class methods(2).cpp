#include <iostream>

#include <thread> // библиотека для многопоточности

#include <chrono>

#include <math.h> 

using namespace std;

class MyClass {
public:
	void DoWork()
	{

		this_thread::sleep_for(chrono::milliseconds(3000)); // имитация длительного процесса обработки данных (3000 milliseconds)

		cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STARTED\t==========\t " << endl;

		this_thread::sleep_for(chrono::milliseconds(5000)); // имитация длительного процесса обработки данных (5000 milliseconds) 

		cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STOPPED\t==========\t " << endl;
	}

	void DoWork2(int a)
	{

		this_thread::sleep_for(chrono::milliseconds(3000)); // имитация длительного процесса обработки данных (3000 milliseconds)

		cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STARTED\t==========\t " << endl;

		this_thread::sleep_for(chrono::milliseconds(5000)); // имитация длительного процесса обработки данных (5000 milliseconds) 

		cout << "DoWork2 значение парметров\t" << a << endl;

		cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STOPPED\t==========\t " << endl;
	}
	int Sum(int a, int b)
	{

		this_thread::sleep_for(chrono::milliseconds(3000)); // имитация длительного процесса обработки данных (3000 milliseconds)

		cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STARTED\t==========\t " << endl;

		this_thread::sleep_for(chrono::milliseconds(5000)); // имитация длительного процесса обработки данных (5000 milliseconds) 

		cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STOPPED\t==========\t " << endl;
		return a + b;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	MyClass m;

	thread t(&MyClass::DoWork2, m, 5);

	for (size_t i = 1; i <= 10; i++)
	{
		cout << "id потока =" << this_thread::get_id() << "\tmain works\t" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();

	return 0;
}

