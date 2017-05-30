#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <cstdint>
#include <malloc.h>
#include <new>
#include <cstdlib>

#ifdef _DEBUG
#undef _DEBUG
#include <omp.h>
#define _DEBUG
#else
#include <omp.h>
#endif

using namespace std;

int64_t size_mass;

int tuple_size = 2;

//int64_t **Attitude;
/*int64_t **Attitude = new int64_t*;*/
/*int64_t *Attitude = new int64_t[3000000000];*/

class Array {
public:
	int64_t **Attitude = new int64_t*[size_mass];
	Array(int _size)
	{
		srand(time(NULL));

		/* Attitude = new int64_t*[1000000];*/

		for (int row = 0; row < _size; row++)
		{
			Attitude[row] = new int64_t[10];
			Attitude[row][0] = row;
			for (int col = 0; col < 10; col++)
			{
				Attitude[row][col] = rand() % 100000;

				/*cout << Attitude[row][col] << " ";*/
			}
			/*  cout << endl;*/
		}
	}
};

class Algorithm_for_column_store_DBMS
{
private:

	float average_time[50], Result, repeat_time_calculation, Sum_average_time, repeat_time_start, repeat_time_end;
public:void Calculation(int64_t **Att1, int64_t **Att2)
{
	int64_t tuples_connected;
	
	repeat_time_start = clock();

	tuples_connected = 0;

#pragma omp parallel num_threads(8)
#pragma omp for reduction(+:tuples_connected)
	for (int i = 0; i < size_mass; i++)
	{
		for (int j = 0; j < size_mass; j++)
		{
			if (Att1[i][1] == Att2[j][1])
			{
				tuples_connected = tuples_connected + 1;

			}
		}
	}

	repeat_time_end = clock();

	repeat_time_end = repeat_time_end / 1000;
	cout << "______________________________________________________________________" << endl;
	cout << "Среднее время выполнения алгоритма для колоночной СУБД = " << setw(3) << repeat_time_end << "  секунд." << endl;
	cout << "Кортежей соединилось = " << tuples_connected << endl;
	cout << "______________________________________________________________________" << endl << endl;
}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите размер отношений";

	cin >> size_mass;

	Array test = Array(size_mass);
	Array test2 = Array(size_mass);

	class Algorithm_for_column_store_DBMS objColumn;
	objColumn.Calculation(test.Attitude, test2.Attitude);

	system("pause");
	return 0;
}