#include <iostream>   // для оператора cout
#include <iomanip>   // для функции setw
#include <cassert>  // для функции assert
#include <string>  // строчный тип данных
#include <time.h> // для функций time, clock
#include <omp.h> // для функций MPI
/*==============================================*/
using namespace std;

class Array 
{
	public:
		int64_t **Attitude;
		Array(int64_t tuple_size, int64_t size_mass, string DEBUG)
			{		
				Attitude = new int64_t*[size_mass];
				for (int row = 0; row < size_mass; row++)
					{
						Attitude[row] = new int64_t[tuple_size];
						Attitude[row][0] = row;
						for (int column = 0; column < tuple_size; column++)
						{
							Attitude[row][column] = rand() % 100000;

							if (DEBUG == "Y")
							{
								cout << Attitude[row][column] << " ";
							}
						}
						if (DEBUG == "Y")
						{
							cout << endl;
						}
					}
			}
};

class Algorithm_for_column_store_DBMS
{
	private:
			float average_time[50], Result, repeat_time_calculation, Sum_average_time, repeat_time_start, repeat_time_end;
			int64_t tuples_connected_R;

	public:void Calculation(int64_t **Att1, int64_t **Att2, int64_t size_mass, int64_t size_mass2, string DEBUG, int64_t Threads, string Average_result, int64_t Average_result_number, int64_t tuple_size)
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
						for (int j = 0; j < size_mass; j++)
						{
							for (int x = 0; x < tuple_size; x++)
							{
								if (Att1[i][x] == Att2[j][x])
								{
									tuples_connected = tuples_connected + 1;

									if (DEBUG == "Yes")
									{
										cout << Att1[i][x] << "  " << Att2[j][x] << endl;
									}
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

				float average_time_list;
				for (int i = 0; i < average_time[i]; i++)
				{
					average_time_list = average_time[i] / 1000;
					cout << "  " << average_time_list << "  секунд." << endl;
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
			
								if (DEBUG == "Yes")
								{
									cout << Att1[i][x] << "  " << Att2[j][x] << endl;
								}
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
	string DEBUG, Average_result;

	cout << "Вывести отладочную информацию ? Y/N \n";
	cin >> DEBUG;
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
	cout << "Введите количество кортежей 1 отношения \n";
	cin >> size_mass;
	assert(size_mass != NULL);
	assert(size_mass > NULL);
	cout << "Введите количество кортежей 2 отношения \n";
	cin >> size_mass2;
	assert(size_mass2 != NULL);
	assert(size_mass2 > NULL);
	cout << "Введите количество столбцов \n";
	cin >> tuple_size;
	assert(tuple_size != NULL);
	assert(tuple_size > NULL);
	cout << "Введите количество нитей \n";
	cin >> Threads;
	assert(Threads != NULL);
	assert(Threads > NULL);
	cout << "---------------------------------------------------------------------" << endl;

	Array Mass1 = Array(tuple_size, size_mass, DEBUG);
	cout << endl;
	Array Mass2 = Array(tuple_size, size_mass2, DEBUG);

	class Algorithm_for_column_store_DBMS objColumn;
	objColumn.Calculation(Mass1.Attitude, Mass2.Attitude, size_mass, size_mass2, DEBUG, Threads, Average_result, Average_result_number, tuple_size);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	string Repeat;

	class InputData start;
	start.Configuration();
	
	cout << "Повторить расчеты Y/N ?" << endl;
	cin >> Repeat;
	do {
		start.Configuration();
		cout << "Повторить расчеты Y/N ?";
		cin >> Repeat;
	}	while (Repeat == "Y");

	system("pause");
	return 0;
}
