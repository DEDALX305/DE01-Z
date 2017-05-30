#include <iostream>
#include <time.h>
#include <cstring>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<windows.h>
using namespace std;

int univers;

class Query_manager
{
public:
	float t_1, t_2, InOut;
	Query_manager() 
	{
/*����������� ���������� --------------------------------------------------------------*/
		t_1 = 1;
		t_2 = 1;
/*-----------------------------------------------------------------------*/
		if (univers == 1) {


		}
		else
		{
			InOut = t_1 + t_2;
		}
		
	};
};

class Memory_manager
{
public:
	float Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio;
	
	Memory_manager(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
/*����������� ���������� --------------------------------------------------------------*/
		FragMM = 1;
		GDAfrag_t1 = 1;
		ClearFM = 1;
		SendAF = 1;
/*-------------------------------------------------------------------------------------*/
		if (univers == 1)
		{
	
		}
		else 
		{

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
			Number_of_fragments = Large_ratio / (((SFastMemory - Small_ratio) - Small_ratio) / 2);
			FragMM = 1; //(Large_ratio / Number_of_fragments);
			SizeFragmentLarge_ratio = Number_of_fragments;
			SizeResultantSubfragment = SizeFragmentLarge_ratio + Large_ratio;
			OutFragM = SizeResultantSubfragment / MainMemThroughput;
		}	
	}
};

class Manager_of_parallel_agents
{
public:
	float t_g, t_f, MesAfrag,  GDAfrag_t2, ProcRequest;
	
	Manager_of_parallel_agents(float k1, float k2, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput)
	{
/*����������� ���������� --------------------------------------------------------------*/
		t_g = 1;
		t_f = 1;
		GDAfrag_t2 = 1;
		MesAfrag = 1;
/*-------------------------------------------------------------------------------------*/
		if (univers == 1) {

			ProcRequest = (k1 / MainMemThroughput) * PerfParallelAgentManager;
		}
		else
		{
			ProcRequest = (k1 / FastMemThroughputm * k2 / MainMemThroughput) * PerfParallelAgentManager;
			
		}
		
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	float	Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps;
	float	N_ProcRequest, TALL, FastMemThroughput, PerfParallelAgentManager, t_0, k1, k2, SizeCort;
	string str;
/*����������� ���������� --------------------------------------------------------------*/
	TimeFinal = 1;
	k1 = 1;
	k2 = 1;
/*-------------------------------------------------------------------------------------*/

	//cout << "������� ������ ��������� \n" ;
	//cout << "��������� 1 \n";
	//cin >> Size1;
	//cout << "��������� 2 \n";
	//cin >> Size2;
	//cout << "������� ������ ������� ������ \n";
	//cin >> SFastMemory;
	//cout << "������� ������ �������� ������ \n";
	//cin >> SMainMemory;
	//cout << "������� ���������� ����������� �������� ������ \n";
	//cin >> MainMemThroughput;
	//cout << "������� ���������� ����������� ������� ������ \n";
	//cin >> FastMemThroughput;
	//cout << "������� ������������������ ��������� ����������� ������� \n";
	//cin >> PerfParallelAgentManager;

	cout << "������������� ����� Yes / No ? \n";
	cin >> str;
	if (str == "Yes")
	{
		univers = 1;
		cout << "���������� �������� \n";
		Size1 = 50000;
		cout << "������� ������ �������� ������ \n";
		SMainMemory = 16393;
		cout << "������� ������ 1 �� ������� \n";
		SizeCort = 1000;
		cout << "������� ���������� ����������� �������� ������ \n";
		MainMemThroughput = 15000;
		cout << "������� ������������������ ��������� ����������� ������� \n";
		PerfParallelAgentManager = 8;


		TimeFirst = (Size1 + Size1) / 10000;

		cout << TimeFirst << " �������� ������" << endl;
	}
	else 
	{
		univers = 0;
		cout << "��������� 1 \n";
		Size1 = 50000;
		cout << "��������� 2 \n";
		Size2 = 6000;
		cout << "������� ������ ������� ������ \n";
		SFastMemory = 16394;
		cout << "������� ������ �������� ������ \n";
		SMainMemory = 16394;
		cout << "������� ���������� ����������� �������� ������ \n";
		MainMemThroughput = 15000;
		cout << "������� ���������� ����������� ������� ������ \n";
		FastMemThroughput = 15000;
		cout << "������� ������������������ ��������� ����������� ������� \n";
		PerfParallelAgentManager = 526;
		Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
		Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, k2, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput);
		Query_manager* query_manager = new Query_manager();
		/*TimeFirst - ���������������� ���------------------------------------------------------------------*/
		t_load = memory_manager->Ftml + memory_manager->FragMM + memory_manager->GDAfrag_t1 + manager_of_parallel_agents->GDAfrag_t2;
		t_0 = query_manager->InOut + memory_manager->FragMM + manager_of_parallel_agents->t_f + manager_of_parallel_agents->t_g + t_load;
		TimeFirst = t_0 + t_load;
		/*Processing_steps - ���� ���������----------------------------------------------------------------*/
		N_ProcRequest = manager_of_parallel_agents->ProcRequest;
		Time_j = manager_of_parallel_agents->MesAfrag + N_ProcRequest;
		time_j = memory_manager->OutFragM + memory_manager->ClearFM + memory_manager->SendAF;
		N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments;
		/*TimeFinal - ����������� ��� ---------------------------------------------------------------------*/
		cout << "������� �����������  \n";
		TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
		cout << TALL << " �������� ������" << endl;
		/*-------------------------------------------------------------------------------------------------*/
	}
	
	
	
	system("pause");
	return 0;
}