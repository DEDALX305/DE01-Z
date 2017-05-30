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

int64_t **Mass1 = new int64_t*[size_mass];
int64_t **Mass2 = new int64_t*[size_mass];


const int tuple_size = 2;

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

		//for (int count = 0; count < 1000000; count++)
		//{
		// Attitude[count] = new int64_t[2];
		// for (int count_row = 0; count_row < 1000000; count_row++)
		// {
		//  Attitude[count_row][0] = count_row;
		//  Attitude[count_row][1] = rand() % 100000;

		//  /*cout << Attitude[row][col] << " ";*/
		// }
		// /*  cout << endl;*/
		//}
	}
};

//class Create_array1
//{
//public:void FilingMass()
//{
//	srand(time(NULL));
//
//	for (int count = 0; count < size_mass; count++)
//		Mass1[count] = new int64_t[2];
//	for (int count_row = 0; count_row < size_mass; count_row++)
//	{
//		Mass1[count_row][0] = count_row;
//		Mass1[count_row][1] = rand() % 1000000;
//	}
//}
//};
//
//class Create_array2
//{
//public:void FilingMass()
//{
//	srand(time(NULL));
//
//	for (int count = 0; count < size_mass; count++)
//		Mass2[count] = new int64_t[2];
//	for (int count_row = 0; count_row < size_mass; count_row++)
//	{
//		Mass2[count_row][0] = count_row;
//		Mass2[count_row][1] = rand() % 1000000;
//	}
//}
//};
//
//class Algorithm_for_relational_DBMS
//{
//private:
//
//	int64_t **Ress = new int64_t*[1000000];
//	int l;
//	float average_time[50], Result, repeat_time_calculation, Sum_average_time, repeat_time_start, repeat_time_end;
//public:void Calculation()
//{
//	int64_t tuples_connected;
//	for (int count = 0; count < 1000000; count++)
//		Ress[count] = new int64_t[4];
//
//	for (int repeat = 0; repeat < 50; repeat++)
//	{
//		repeat_time_start = clock();
//		l = 0;
//		tuples_connected = 0;
//
//#pragma omp parallel num_threads(8)
//#pragma omp for reduction(+:tuples_connected)
//		for (int i = 0; i < size_mass; i++)
//		{
//
//			for (int j = 0; j < size_mass; j++)
//			{
//				if (Mass1[i][1] == Mass2[j][1])
//				{
//
//					tuples_connected = tuples_connected + 1;
//
//					Ress[l][0] = Mass1[i][0];
//					Ress[l][1] = Mass1[i][1];
//					Ress[l][2] = Mass2[j][0];
//					Ress[l][3] = Mass2[j][1];
//					l = l + 1;
//				}
//			}
//		}
//
//		repeat_time_end = clock();
//		repeat_time_calculation = repeat_time_end - repeat_time_start;
//		average_time[repeat] = repeat_time_calculation;
//	}//repeat
//	Sum_average_time = 0;
//	for (int i = 0; i < 50; i++)
//	{
//		Sum_average_time = Sum_average_time + average_time[i];
//	}
//
//	Result = (Sum_average_time / 50) / 1000;
//	cout << "______________________________________________________________________" << endl;
//	cout << "Среднее время выполнения алгоритма для реляционной СУБД = " << setw(3) << Result << "  секунд." << endl;
//	cout << "Кортежей соединилось = " << tuples_connected << endl;
//	cout << "______________________________________________________________________" << endl << endl;
//}
//
//	   
//};

class Algorithm_for_column_store_DBMS
{
private:

	//int64_t **Ress = new int64_t*[50000];
	//int l;
	float average_time[50], Result, repeat_time_calculation, Sum_average_time, repeat_time_start, repeat_time_end;
public:void Calculation(int64_t **Att1, int64_t **Att2)
{
	int64_t tuples_connected;
	//for (int count = 0; count < sizeof(Att1); count++)
	//	Ress[count] = new int64_t[10];

	/*for (int repeat = 0; repeat < 20; repeat++)
	{*/
	repeat_time_start = clock();
	/*	l = 0;*/
	tuples_connected = 0;
	cout << Att1 << endl;
	cout << sizeof(Att1);
#pragma omp parallel num_threads(8)
#pragma omp for reduction(+:tuples_connected)
	for (int i = 0; i < size_mass; i++)
	{
		for (int j = 0; j < size_mass; j++)
		{
			if (Att1[i][1] == Att2[j][1])
			{
				tuples_connected = tuples_connected + 1;

				/*Ress[i][0] = Att1[j][2];
				Ress[i][1] = Att2[j][2];
				Ress[i][3] = Att1[j][3];*/
				//Ress[l][1] = Mass1[i][1];
				//l /*= l + 1;*/
			}
		}
	}



	repeat_time_end = clock();
	/*repeat_time_calculation = repeat_time_end - repeat_time_start;
	average_time[repeat] = repeat_time_calculation;*/
	repeat_time_end = repeat_time_end / 1000;
	cout << "______________________________________________________________________" << endl;
	cout << "Среднее время выполнения алгоритма для колоночной СУБД = " << setw(3) << repeat_time_end << "  секунд." << endl;
	cout << "Кортежей соединилось = " << tuples_connected << endl;
	cout << "______________________________________________________________________" << endl << endl;
}//repeat
 /*Sum_average_time = 0;
 for (int i = 0; i < 50; i++)
 {
 Sum_average_time = Sum_average_time + average_time[i];
 }

 Result = (Sum_average_time / 50) / 1000;*/

 //}

};


int main()
{
	setlocale(LC_ALL, "Russian");

	//class Create_array1 objArray1;
	//objArray1.FilingMass();

	//class Create_array2 objArray2;
	//objArray2.FilingMass();
	cout << "Введите размер отношений";

	cin >> size_mass;

	Array test = Array(size_mass);
	Array test2 = Array(size_mass);

	//class Algorithm_for_relational_DBMS objRelatianl;
	//objRelatianl.Calculation();

	class Algorithm_for_column_store_DBMS objColumn;
	objColumn.Calculation(test.Attitude, test2.Attitude);

	system("pause");
	return 0;
}