#include <iostream> // для оператора cout
#include <cassert>  // для функции assert

/*==============================================*/

//#include <iomanip>   // для функции setw
//#include <string>  // строчный тип данных
//#include <time.h> // для функций time, clock
//#include <omp.h> // для функций MPI
//#include <cstring>
//#include <string>
//#include <conio.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <windows.h>

#define NDEBUG

using namespace std;




class Query_manager
{
public:
	float t_1, t_2, InOut;
	void TimeFirst()
	{
		/*TimeFirst - подготовительный шаг------------------------------------------------------------------*/
		/*Константные переменные --------------------------------------------------------------*/
		t_1 = 1;
		t_2 = 1;
		/*-----------------------------------------------------------------------*/		
		InOut = t_1 + t_2;	// Время затраченное на сообщение информации о запросе менеджеру параллельных агентов t_1  и менеджеру памяти t_2.
		
	};
};

class Manager_of_parallel_agents
{
public:
	float t_g, t_f, MesAfrag, GDAfrag_t2, ProcRequest, Time_j, time_j;

	void Processing(float k1, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput)
	{
		

		/*------------------------------Processing_steps - Шаги обработки----------------------------------*/
		/*Константные переменные --------------------------------------------------------------*/
		t_g = 1; // Время затраченное на создание группы агентов.
		t_f = 1; // Время проверки свободных виртуальных процессоров. 
		GDAfrag_t2 = 1; // Время затраченное на отправку менеджером памяти адресов подфрагментов хранящихся в быстрой памяти менеджеру параллельных агентов.

		MesAfrag = 1; // Время, затраченное на сообщение адресов подфрагментов хранящихся в быстрой памяти группе параллельных агентов.

		ProcRequest = (k1 / FastMemThroughputm) * PerfParallelAgentManager; // время, затраченное на выполнение операции соединения полученных подфрагментов:
		assert(ProcRequest > NULL);
#ifdef DEBUG 
		cout << "ProcRequest " << ProcRequest << endl;
#endif
		/*------------------------------Time_j----------------------------------*/

		/*N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments;*/
		Memory_manager* objtimefirst;
		//Memory_manager* timefirst = new Memory_manager;

		objtimefirst.SizeResultantSubfragment = timefirst->SizeFragmentLarge_ratio + timefirst->Small_ratio; // Размер результирующего отношения
		assert(timefirst->SizeResultantSubfragment > NULL);
#ifdef DEBUG 
		cout << "SizeResultantSubfragment " << SizeResultantSubfragment << endl;
#endif
		timefirst->OutFragM = timefirst->SizeResultantSubfragment / MainMemThroughput; // время, затраченное на выгрузку результирующего подфрагмента из быстрой памяти в основную;
#ifdef DEBUG 
		cout << "OutFragM " << OutFragM << endl;
#endif	

		Time_j = MesAfrag + ProcRequest;
		assert(Time_j > NULL);
		/*_________________________________________________________________________________________________*/

		/*------------------------------time_j----------------------------------*/
		time_j = timefirst->OutFragM + timefirst->ClearFM + timefirst->SendAF;
		assert(time_j > NULL);
	}
};

class Memory_manager
{
public:
	float t_load, Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio, t_0;


	void TimeFirst(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
		
/*Константные переменные --------------------------------------------------------------*/
		
		ClearFM = 1; //время, затраченное на очистку быстрой памяти, задается константно;
		SendAF = 1; //время, затраченное на отправку адресов подфрагментов хранящихся в быстрой памяти менеджеру параллельных агентов.
		FragMM = 1; //указывает время, затраченное на фрагментацию данных в быстрой па-мяти;
/*-------------------------------------------------------------------------------------*/

		if (Size1 > Size2)
		{
			Large_ratio = Size1;
			Small_ratio = Size2;
		}
		else {
			Large_ratio = Size2;
			Small_ratio = Size1;
		}

		/*----------------------------Такт t_load--------------------------------------*/
		
		
		SizeFragmentLarge_ratio = ((SFastMemory - Small_ratio) - Small_ratio) / 2; // Размер фрагмента большого отношения.
		assert(SizeFragmentLarge_ratio > NULL);
#ifdef DEBUG 
	cout << "SizeFragmentLarge_ratio " << SizeFragmentLarge_ratio << endl;
#endif
		Number_of_fragments = Large_ratio / (((SFastMemory - Small_ratio) - Small_ratio) / 2); // Количество фрагментов.
		assert(Number_of_fragments > 1);
#ifdef DEBUG 
	cout << "Number_of_fragments " << Number_of_fragments << endl;
#endif
		Ftml = Small_ratio / MainMemThroughput; // Указывает время, затраченное на загрузку меньшего отношения в быструю память.
		assert(Ftml > NULL);
#ifdef DEBUG 
	cout << "Ftml " << Ftml << endl;
#endif
		FragMM = 1; // указывает время, затраченное на фрагментацию данных в быстрой па-мяти;

		GDAfrag_t1 = 1; //время затраченное на получение менеджером памяти адресов подфраг-ментов хранящихся в быстрой памяти 

		Manager_of_parallel_agents* P = new Manager_of_parallel_agents;
		Query_manager* TimeFirst = new Query_manager;

		t_load = Ftml + FragMM + GDAfrag_t1 + P->GDAfrag_t2;
		assert(t_load > NULL);
#ifdef DEBUG 
	cout << "t_load " << t_load << endl;
#endif
		/*_____________________________________________________________________________________*/
	
	
	t_0 = TimeFirst->InOut + FragMM + P->t_f + P->t_g + t_load;
	assert(t_0 > NULL);
#ifdef DEBUG 
	cout << "t_0 " << t_0 << endl;
#endif


	}
};



int main()
{
	setlocale(LC_ALL, "Russian");

#ifdef DEBUG 
	cout << " DEBUG MODE!" << endl;
#endif
	
	float	Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, k1, FastMemThroughput, PerfParallelAgentManager, TFirst, TimeFinal, N_ProcessingSteps, TALL;

/*Константные переменные --------------------------------------------------------------*/
	k1 = 1000;
/*-------------------------------------------------------------------------------------*/
	
	cout << "Отношение 1 \n";
	Size1 = 170000;
	assert(Size1 > NULL);
	assert(Size1 != NULL);
	cout << "Отношение 2 \n";
	Size2 = 6000;
	assert(Size2 > NULL);
	assert(Size2 != NULL);
	cout << "Введите размер быстрой памяти \n";
	SFastMemory = 16000;
	assert(SFastMemory > NULL);
	assert(SFastMemory != NULL);
	cout << "Введите размер основной памяти \n";
	SMainMemory = 393000;
	assert(SMainMemory > NULL);
	assert(SMainMemory != NULL);
	cout << "Введите пропускную способность основной памяти \n";
	MainMemThroughput = 90000;
	assert(MainMemThroughput > NULL);
	assert(MainMemThroughput != NULL);
	cout << "Введите пропускную способность быстрой памяти \n";
	FastMemThroughput = 400000;
	assert(FastMemThroughput > NULL);
	assert(FastMemThroughput != NULL);
	cout << "Введите производительсноть менеджера паралельных агентов \n";
	PerfParallelAgentManager = 36;
	assert(PerfParallelAgentManager > NULL);
	assert(PerfParallelAgentManager != NULL);

	class Memory_manager TimeFirst;
	TimeFirst.TimeFirst(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);

	class Manager_of_parallel_agents Processing;
	Processing.Processing(k1, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput);

	TFirst = TimeFirst.t_0 + TimeFirst.t_load;
	N_ProcessingSteps = Processing.Time_j + Processing.time_j;
	TimeFinal = 1;

	cout << "Подсчет результатов  \n";
	TALL = TFirst + N_ProcessingSteps + TimeFinal;
	cout << TALL << " Условных единиц" << endl;

	system("pause");
	return 0;
}