#include <iostream>   // ��� ��������� cout
#include <iomanip>   // ��� ������� setw
#include <cassert>  // ��� ������� assert
#include <string>  // �������� ��� ������
#include <time.h> // ��� ������� time, clock
#include <omp.h> // ��� ������� MPI
/*==============================================*/
using namespace std;



//#include <ctime>
//#include <cstdint>
//#include <malloc.h>
//#include <new>
//#include <cstdlib>
//#include <iostream>

//#include <cstring>

//#include <conio.h>
//#include <stdlib.h>
//#include<stdio.h>
//#include<windows.h>

//#ifdef _DEBUG
//#undef _DEBUG
//#include <omp.h>
//#define _DEBUG
//#else
//#include <omp.h>
//#endif


//#define NDEBUG // � ������ ����� ��������� ����, ����� ���������� ������������� �����

//int64_t **Attitude;
/*int64_t **Attitude = new int64_t*;*/
/*int64_t *Attitude = new int64_t[3000000000];*/
/*int64_t **Attitude = new int64_t*[size_mass];*/

class Array 
{
	public:
		int64_t **Attitude;
		Array(int _size, int64_t tuple_size, int64_t size_mass, string DEBUG)
			{		
				Attitude = new int64_t*[size_mass];
				for (int row = 0; row < _size; row++)
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
	public:void Calculation(int64_t **Att1, int64_t **Att2, int64_t size_mass, string DEBUG, int64_t Threads)
	{
		int64_t tuples_connected;
		repeat_time_start = clock();
		tuples_connected = 0;
	
		#pragma omp parallel num_threads(Threads)
		#pragma omp for reduction(+:tuples_connected)
			for (int i = 0; i < size_mass; i++)
			{
				for (int j = 0; j < size_mass; j++)
				{
					for (int x = 0; x < 2; x++)
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
		
			if (Average_result == "Y")
			{
				

			}

			


		//	repeat_time_end = clock();
		//	repeat_time_calculation = repeat_time_end - repeat_time_start;
		//	average_time[repeat] = repeat_time_calculation;
		//	   Sum_average_time = 0;
		//	   for (int i = 0; i < 50; i++)
		//	   {
		//		   Sum_average_time = Sum_average_time + average_time[i];
		//	   }
		
			repeat_time_end = clock();
			repeat_time_calculation = (repeat_time_end - repeat_time_start) / 1000;
			/*repeat_time_end = repeat_time_end / 1000;*/
			cout << "---------------------------------------------------------------------" << endl;
			cout << "������� ����� ���������� ��������� ��� ���������� ���� = " << setw(3) << repeat_time_calculation << "  ������." << endl;
			cout << "�������� ����������� = " << tuples_connected << endl;
			cout << "---------------------------------------------------------------------" << endl << endl;
		}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	int64_t tuple_size, size_mass, Threads, Average_result_number;
	string DEBUG, Average_result;
	srand(time(NULL));

	cout << "������� ���������� ���������� ? Y/N \n";
	cin >> DEBUG;
	cout << "��������� ������� ��������� ? Y/N \n";
	cin >> Average_result;
	cout << "������� ��� ��������� ���� ? \n";
	cin >> Average_result_number;
	assert(Average_result_number != NULL);

	cout << "---------------------------------------------------------------------" << endl;
	cout << "������� ���������� �������� \n";
	cin >> size_mass;
	assert(size_mass != NULL);
	cout << "������� ���������� �������� \n";
	cin >> tuple_size;
	assert(tuple_size != NULL);
	cout << "������� ���������� ����� \n";
	cin >> Threads;
	assert(Threads != NULL);
	cout << "---------------------------------------------------------------------" << endl;
	
	Array Mass1 = Array(size_mass, tuple_size, size_mass, DEBUG);
	Array Mass2 = Array(size_mass, tuple_size, size_mass, DEBUG);

	class Algorithm_for_column_store_DBMS objColumn;
	objColumn.Calculation(Mass1.Attitude, Mass2.Attitude, size_mass, DEBUG, Threads);

	system("pause");
	return 0;
}