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
	Query_manager() 
	{
/*Константные переменные --------------------------------------------------------------*/
		t_1 = 1;
		t_2 = 1;
/*-----------------------------------------------------------------------*/		
		InOut = t_1 + t_2;	
	};
};

class Memory_manager
{
public:
	float Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio;
	
	Memory_manager(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
/*Константные переменные --------------------------------------------------------------*/
		FragMM = 1;
		GDAfrag_t1 = 1;
		ClearFM = 1;
		SendAF = 1;
		FragMM = 1; //(Large_ratio / Number_of_fragments);
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

		Ftml = Small_ratio / MainMemThroughput;
		assert(Ftml > NULL);
#ifdef DEBUG 
		cout << "Ftml " << Ftml << endl;
#endif
		
		Number_of_fragments = Large_ratio / (((SFastMemory - Small_ratio) - Small_ratio) / 2);
		assert(Number_of_fragments > 1);
#ifdef DEBUG 
		cout << "Number_of_fragments " << Number_of_fragments << endl;
#endif
		
		
		SizeFragmentLarge_ratio = ((SFastMemory - Small_ratio) - Small_ratio) / 2;
		assert(SizeFragmentLarge_ratio > NULL);
#ifdef DEBUG 
		cout << "SizeFragmentLarge_ratio " << SizeFragmentLarge_ratio << endl;
#endif
		

		SizeResultantSubfragment = SizeFragmentLarge_ratio + Small_ratio;
		assert(SizeResultantSubfragment > NULL);
#ifdef DEBUG 
		cout << "SizeResultantSubfragment " << SizeResultantSubfragment << endl;
#endif
		

		OutFragM = SizeResultantSubfragment / MainMemThroughput;
#ifdef DEBUG 
		cout << "OutFragM " << OutFragM << endl;
#endif
			
	}
};

class Manager_of_parallel_agents
{
public:
	float t_g, t_f, MesAfrag,  GDAfrag_t2, ProcRequest;
	
	Manager_of_parallel_agents(float k1, float k2, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput)
	{
/*Константные переменные --------------------------------------------------------------*/
		t_g = 1;
		t_f = 1;
		GDAfrag_t2 = 1;
		MesAfrag = 1;
/*-------------------------------------------------------------------------------------*/
		
		/*ProcRequest = (k1 / FastMemThroughputm * k2 / MainMemThroughput) * PerfParallelAgentManager;*/
		ProcRequest = (k1 / FastMemThroughputm ) * PerfParallelAgentManager;
		assert(ProcRequest > NULL);
		cout << "ProcRequest " << ProcRequest << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DEBUG 
	cout << " DEBUG MODE!" << endl;
#endif
	
	float	Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps;
	float	N_ProcRequest, TALL, FastMemThroughput, PerfParallelAgentManager, t_0, k1, k2, SizeCort;
/*Константные переменные --------------------------------------------------------------*/
	TimeFinal = 1;
	k1 = 1000;
	k2 = 9000;
/*-------------------------------------------------------------------------------------*/

	//cout << "Введите размер отношений \n" ;
	//cout << "Отношение 1 \n";
	//cin >> Size1;
	//cout << "Отношение 2 \n";
	//cin >> Size2;
	//cout << "Введите размер быстрой памяти \n";
	//cin >> SFastMemory;
	//cout << "Введите размер основной памяти \n";
	//cin >> SMainMemory;
	//cout << "Введите пропускную способность основной памяти \n";
	//cin >> MainMemThroughput;
	//cout << "Введите пропускную способность быстрой памяти \n";
	//cin >> FastMemThroughput;
	//cout << "Введите производительсноть менеджера паралельных агентов \n";
	//cin >> PerfParallelAgentManager;
	
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

	Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
	Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, k2, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput);
	Query_manager* query_manager = new Query_manager();
/*TimeFirst - подготовительный шаг------------------------------------------------------------------*/
	t_load = memory_manager->Ftml + memory_manager->FragMM + memory_manager->GDAfrag_t1 + manager_of_parallel_agents->GDAfrag_t2;
	assert(t_load > NULL);
#ifdef DEBUG 
	cout << "t_load " << t_load << endl;
#endif
	
	t_0 = query_manager->InOut + memory_manager->FragMM + manager_of_parallel_agents->t_f + manager_of_parallel_agents->t_g + t_load;
	assert(t_0 > NULL);
#ifdef DEBUG 
	cout << "t_0 " << t_0 << endl;
#endif
	
	TimeFirst = t_0 + t_load;
/*Processing_steps - Шаги обработки----------------------------------------------------------------*/
	Time_j = manager_of_parallel_agents->MesAfrag + manager_of_parallel_agents->ProcRequest;
	assert(Time_j > NULL);
	time_j = memory_manager->OutFragM + memory_manager->ClearFM + memory_manager->SendAF;
	assert(time_j > NULL);
	N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments;
/*TimeFinal - Завершающий шаг ---------------------------------------------------------------------*/
	cout << "Подсчет результатов  \n";
	TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
	cout << TALL << " Условных единиц" << endl;

	


/*-------------------------------------------------------------------------------------------------*/
	
	system("pause");
	return 0;
}