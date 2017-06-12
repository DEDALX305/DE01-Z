/*==================================================================================
Проект:			DSMPM
Тема:			Моделирование операции соединения в параллельной СУБД, выполняемой на многоядерном центральном процессоре INTEL XEON PHI
Database System on Manycore Processor Model (DSMPM)
Приложение для выполнения экспериментов на вычислительном узле суперкомпьютера
Разработчик:	Рекачинский А.И.
Руководитель:	Костенецкий П.С.
Дата изменения: 03.06.2017
===================================================================================*/
#include <iostream>   // для оператора cout
#include <iomanip>   // для функции setw
#include <cassert>  // для функции assert
#include <string>  // строчный тип данных
#include <omp.h>  // для функций MPI
#include <ctime> // для функций time, clock
/*==============================================*/
using namespace std;
#define DEBUG

class displayInfo_info
{
public:
	void output(string displayInfo, int info)
	{
		if (displayInfo == "Y")
		{
			if (info == 1)
			{
				cout << "-----------------------------Отношение S-----------------------------" << endl;
			}
			else
			{
				cout << "-----------------------------Отношение R-----------------------------" << endl;
			}
		}
	}

	void Filling_in_arrays(int64_t value, string displayInfo)
	{
		if (displayInfo == "Y")
		{
			cout << value << endl;
		}
		else {}
	}

	void Result(int64_t _Att1, int64_t _Att2)
	{
		cout << _Att1 << "  " << _Att2 << endl;
	}
};

class Array
{
public:
	int64_t **Attitude, _Attitude;
	Array(int64_t tuple_size, int64_t size_mass, string displayInfo, int info)
	{
		class displayInfo_info _displayInfo;
		if (displayInfo == "Y")
		{
			_displayInfo.output(displayInfo, info);
		}
		else {}
		Attitude = new int64_t*[size_mass];
		for (int row = 0; row < size_mass; row++)
		{
			Attitude[row] = new int64_t[tuple_size];
			Attitude[row][0] = row;
			for (int column = 0; column < tuple_size; column++)
			{
				Attitude[row][column] = rand() % 100000;

				if (displayInfo == "Y")
				{
					_Attitude = Attitude[row][column];
					_displayInfo.Filling_in_arrays(_Attitude, displayInfo);
				}
			}
		}
	}
};

class Algorithm_for_column_store_DBMS
{
private:
	float average_time[100], Result, repeat_time_calculation, Sum_average_time, repeat_time_start, repeat_time_end;
	int64_t tuples_connected_R, _Att1, _Att2;
public:
	void Calculation(int64_t **Att1, int64_t **Att2, int64_t size_mass, int64_t size_mass2, string displayInfo, int64_t Threads, string Average_result, int64_t Average_result_number, int64_t tuple_size, string FilArrays)
	{
		if (Average_result == "Y")
		{
			for (int repeat = 0; repeat < Average_result_number; repeat++)
			{
				repeat_time_start = clock();
				int64_t tuples_connected;
				tuples_connected = 0;

#pragma omp	parallel num_threads(Threads)
#pragma omp	for reduction(+:tuples_connected)
				for (int i = 0; i < size_mass; i++)
				{
					for (int j = 0; j < size_mass2; j++)
					{
						for (int x = 0; x < tuple_size; x++)
						{
							if (Att1[i][x] == Att2[j][x])
							{
								tuples_connected = tuples_connected + 1;

								if (FilArrays == "Y")
								{
									class displayInfo_info _displayInfo;
									_Att1 = Att1[i][x];
									_Att2 = Att2[j][x];
									_displayInfo.Result(_Att1, _Att2);
								}
								else {}
							}
						}
					}
				}
				repeat_time_end = clock();
				repeat_time_calculation = repeat_time_end - repeat_time_start;
				average_time[repeat] = repeat_time_calculation;
				tuples_connected_R = tuples_connected;
			}
			Sum_average_time = 0;
			for (int i = 0; i < Average_result_number; i++)
			{
				Sum_average_time = Sum_average_time + average_time[i];
			}
			Result = (Sum_average_time / 1000) / Average_result_number;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "Время выполнения повторов" << endl;
			float average_time_list;
			for (int i = 0; i < Average_result_number; i++)
			{
				average_time_list = average_time[i] / 1000;
				cout << "Проход " << i << ": " << average_time_list << "  секунд." << endl;
			}
			cout << "---------------------------------------------------------------------" << endl;
			cout << "Среднее время выполнения алгоритма = " << setw(3) << Result << "  секунд." << endl;
			cout << "Кортежей соединилось = " << tuples_connected_R << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
		else
		{
			int64_t tuples_connected;
			repeat_time_start = clock();
			tuples_connected = 0;

#pragma omp parallel num_threads(Threads)
#pragma omp for reduction(+:tuples_connected)
			for (int i = 0; i < size_mass; i++)
			{
				for (int j = 0; j < size_mass2; j++)
				{
					for (int x = 0; x < tuple_size; x++)
					{
						if (Att1[i][x] == Att2[j][x])
						{
							tuples_connected = tuples_connected + 1;

							if (FilArrays == "Y")
							{
								class displayInfo_info _displayInfo;
								_Att1 = Att1[i][x];
								_Att2 = Att2[j][x];
								_displayInfo.Result(_Att1, _Att2);
							}
							else {}
						}
					}
				}
			}
			repeat_time_end = clock();
			repeat_time_calculation = repeat_time_end - repeat_time_start;
			Result = repeat_time_calculation / 1000;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "Время выполнения алгоритма = " << setw(3) << Result << "  секунд." << endl;
			cout << "Кортежей соединилось = " << tuples_connected << endl;
			cout << "---------------------------------------------------------------------" << endl << endl;
		}
	}// Конец функции Calculation()
};

class InputData
{
public: void Configuration()
{
	int64_t tuple_size, size_mass, size_mass2, Threads, Average_result_number;
	string displayInfo, Average_result, FilArrays;

	cout << "Вывести отладочную информацию? Y/N \n";
	cin >> displayInfo;
	cout << "Вывести информацию об заполнении массивов ? Y/N" << endl;
	cin >> FilArrays;

	cout << "Посчитать средний результат ? Y/N \n";
	cin >> Average_result;
	if (Average_result == "Y")
	{
		cout << "Сколько раз повторить тест ? \n";
		cin >> Average_result_number;
		assert(Average_result_number != NULL);
		assert(Average_result_number > NULL);
	}
	else
	{
		Average_result_number = 1;
	}

	cout << "---------------------------------------------------------------------" << endl;
	cout << "Введите количество кортежей отношения S: ";
	cin >> size_mass;
	assert(size_mass != 0 & size_mass > 0);
	cout << "Введите количество кортежей отношения R: ";
	cin >> size_mass2;
	assert(size_mass2 != 0 & size_mass2 > 0);
	cout << "Введите количество столбцов: ";
	cin >> tuple_size;
	assert(tuple_size != 0 & tuple_size > 0);
	cout << "Введите количество нитей: ";
	cin >> Threads;
	assert(Threads != 0 & Threads > 0);
	//cout << "---------------------------------------------------------------------" << endl;

	Array Mass1 = Array(tuple_size, size_mass, displayInfo, 1);
	Array Mass2 = Array(tuple_size, size_mass2, displayInfo, 2);

	class Algorithm_for_column_store_DBMS objColumn;
	objColumn.Calculation(Mass1.Attitude, Mass2.Attitude, size_mass, size_mass2, displayInfo, Threads, Average_result, Average_result_number, tuple_size, FilArrays);
}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	string Repeat;

	class InputData start;
	start.Configuration();

	cout << "Повторить расчеты Y/N ? \n" << endl;
	cin >> Repeat;
	if (Repeat == "Y")
	{
		do {
			start.Configuration();
			cout << "Повторить расчеты Y/N ? \n";
			cin >> Repeat;
		} while (Repeat == "Y");
	}
	else
	{
		exit(0);
	}
	return 0;
}