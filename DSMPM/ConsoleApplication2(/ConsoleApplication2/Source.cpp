#include <iostream> // ��� ��������� cout
#include <cassert>  // ��� ������� assert

/*==============================================*/

//#include <iomanip>   // ��� ������� setw
//#include <string>  // �������� ��� ������
//#include <time.h> // ��� ������� time, clock
//#include <omp.h> // ��� ������� MPI
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
		/*TimeFirst - ���������������� ���------------------------------------------------------------------*/
		/*����������� ���������� --------------------------------------------------------------*/
		t_1 = 1;
		t_2 = 1;
		/*-----------------------------------------------------------------------*/		
		InOut = t_1 + t_2;	// ����� ����������� �� ��������� ���������� � ������� ��������� ������������ ������� t_1  � ��������� ������ t_2.
		
	};
};

class Manager_of_parallel_agents
{
public:
	float t_g, t_f, MesAfrag, GDAfrag_t2, ProcRequest, Time_j, time_j;

	void Processing(float k1, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput)
	{
		

		/*------------------------------Processing_steps - ���� ���������----------------------------------*/
		/*����������� ���������� --------------------------------------------------------------*/
		t_g = 1; // ����� ����������� �� �������� ������ �������.
		t_f = 1; // ����� �������� ��������� ����������� �����������. 
		GDAfrag_t2 = 1; // ����� ����������� �� �������� ���������� ������ ������� ������������� ���������� � ������� ������ ��������� ������������ �������.

		MesAfrag = 1; // �����, ����������� �� ��������� ������� ������������� ���������� � ������� ������ ������ ������������ �������.

		ProcRequest = (k1 / FastMemThroughputm) * PerfParallelAgentManager; // �����, ����������� �� ���������� �������� ���������� ���������� �������������:
		assert(ProcRequest > NULL);
#ifdef DEBUG 
		cout << "ProcRequest " << ProcRequest << endl;
#endif
		/*------------------------------Time_j----------------------------------*/

		/*N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments;*/
		Memory_manager* objtimefirst;
		//Memory_manager* timefirst = new Memory_manager;

		objtimefirst.SizeResultantSubfragment = timefirst->SizeFragmentLarge_ratio + timefirst->Small_ratio; // ������ ��������������� ���������
		assert(timefirst->SizeResultantSubfragment > NULL);
#ifdef DEBUG 
		cout << "SizeResultantSubfragment " << SizeResultantSubfragment << endl;
#endif
		timefirst->OutFragM = timefirst->SizeResultantSubfragment / MainMemThroughput; // �����, ����������� �� �������� ��������������� ������������ �� ������� ������ � ��������;
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
		
/*����������� ���������� --------------------------------------------------------------*/
		
		ClearFM = 1; //�����, ����������� �� ������� ������� ������, �������� ����������;
		SendAF = 1; //�����, ����������� �� �������� ������� ������������� ���������� � ������� ������ ��������� ������������ �������.
		FragMM = 1; //��������� �����, ����������� �� ������������ ������ � ������� ��-����;
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

		/*----------------------------���� t_load--------------------------------------*/
		
		
		SizeFragmentLarge_ratio = ((SFastMemory - Small_ratio) - Small_ratio) / 2; // ������ ��������� �������� ���������.
		assert(SizeFragmentLarge_ratio > NULL);
#ifdef DEBUG 
	cout << "SizeFragmentLarge_ratio " << SizeFragmentLarge_ratio << endl;
#endif
		Number_of_fragments = Large_ratio / (((SFastMemory - Small_ratio) - Small_ratio) / 2); // ���������� ����������.
		assert(Number_of_fragments > 1);
#ifdef DEBUG 
	cout << "Number_of_fragments " << Number_of_fragments << endl;
#endif
		Ftml = Small_ratio / MainMemThroughput; // ��������� �����, ����������� �� �������� �������� ��������� � ������� ������.
		assert(Ftml > NULL);
#ifdef DEBUG 
	cout << "Ftml " << Ftml << endl;
#endif
		FragMM = 1; // ��������� �����, ����������� �� ������������ ������ � ������� ��-����;

		GDAfrag_t1 = 1; //����� ����������� �� ��������� ���������� ������ ������� �������-������ ���������� � ������� ������ 

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

/*����������� ���������� --------------------------------------------------------------*/
	k1 = 1000;
/*-------------------------------------------------------------------------------------*/
	
	cout << "��������� 1 \n";
	Size1 = 170000;
	assert(Size1 > NULL);
	assert(Size1 != NULL);
	cout << "��������� 2 \n";
	Size2 = 6000;
	assert(Size2 > NULL);
	assert(Size2 != NULL);
	cout << "������� ������ ������� ������ \n";
	SFastMemory = 16000;
	assert(SFastMemory > NULL);
	assert(SFastMemory != NULL);
	cout << "������� ������ �������� ������ \n";
	SMainMemory = 393000;
	assert(SMainMemory > NULL);
	assert(SMainMemory != NULL);
	cout << "������� ���������� ����������� �������� ������ \n";
	MainMemThroughput = 90000;
	assert(MainMemThroughput > NULL);
	assert(MainMemThroughput != NULL);
	cout << "������� ���������� ����������� ������� ������ \n";
	FastMemThroughput = 400000;
	assert(FastMemThroughput > NULL);
	assert(FastMemThroughput != NULL);
	cout << "������� ������������������ ��������� ����������� ������� \n";
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

	cout << "������� �����������  \n";
	TALL = TFirst + N_ProcessingSteps + TimeFinal;
	cout << TALL << " �������� ������" << endl;

	system("pause");
	return 0;
}