#include <iostream>  // ��� ��������� cout
#include <cassert>  // ��� ������� assert
#include <string>  // �������� ��� ������
/*==============================================*/
#define NDEBUG
using namespace std;
/*==============================================*/

class Memory_manager
{
public:
	float t_1, t_2, InOut, Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio;
	Memory_manager(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
		/*����������� ���������� --------------------------------------------------------------*/
		FragMM = 1;// ��������� �����, ����������� �� ������������ ������ � ������� ��-����;
		GDAfrag_t1 = 1; //����� ����������� �� ��������� ���������� ������ ������� �������-������ ���������� � ������� ������ 
		ClearFM = 1;//�����, ����������� �� ������� ������� ������, �������� ����������;
		SendAF = 1; //�����, ����������� �� �������� ������� ������������� ���������� � ������� ������ ��������� ������������ �������.
		FragMM = 1; //��������� �����, ����������� �� ������������ ������ � ������� ��-����;
		t_1 = 1; // ����� ����������� �� ��������� ���������� � ������� ��������� ������������ ������� 
		t_2 = 1; // ����� ����������� �� ��������� ���������� � ������� ��������� ��������� ������ 
		/*-------------------------------------------------------------------------------------*/
		if (Size1 > Size2)
		{
			Large_ratio = Size1;
			Small_ratio = Size2;
		}
		else
		{
			Large_ratio = Size2;
			Small_ratio = Size1;
		}
		InOut = t_1 + t_2;

		Ftml = (Small_ratio / MainMemThroughput); // ��������� �����, ����������� �� �������� �������� ��������� � ������� ������.
		assert(Ftml > NULL);
#ifdef DEBUG 
		cout << "Ftml " << Ftml << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		Number_of_fragments = Large_ratio / (((SFastMemory - Small_ratio) - Small_ratio) / 2); // ���������� ����������.
		assert(Number_of_fragments > 1);
#ifdef DEBUG 
		cout << "Number_of_fragments " << Number_of_fragments << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		SizeFragmentLarge_ratio = ((SFastMemory - Small_ratio) - Small_ratio) / 2; // ������ ��������� �������� ���������.
		assert(SizeFragmentLarge_ratio > NULL);
#ifdef DEBUG 
		cout << "SizeFragmentLarge_ratio " << SizeFragmentLarge_ratio << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		SizeResultantSubfragment = SizeFragmentLarge_ratio + Small_ratio; // ������ ��������������� ���������
		assert(SizeResultantSubfragment > NULL);
#ifdef DEBUG 
		cout << "SizeResultantSubfragment " << SizeResultantSubfragment << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		OutFragM = SizeResultantSubfragment / MainMemThroughput;
#ifdef DEBUG 
		cout << "OutFragM " << OutFragM << endl;
#endif			
	}
};

class Manager_of_parallel_agents
{
public:
	float t_g, t_f, MesAfrag, GDAfrag_t2, ProcRequest, k2;

	Manager_of_parallel_agents(float k1, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput)
	{
		/*---------------------------����������� ����������-----------------------------------*/
		t_g = 1;// ����� ����������� �� �������� ������ �������.
		t_f = 1; // ����� �������� ��������� ����������� �����������. 
		GDAfrag_t2 = 1;// ����� ����������� �� �������� ���������� ������ ������� ������������� ���������� � ������� ������ ��������� ������������ �������.
		MesAfrag = 1;// �����, ����������� �� ��������� ������� ������������� ���������� � ������� ������ ������ ������������ �������.
		/*-------------------------------------------------------------------------------------*/

		ProcRequest = (((k1 / FastMemThroughputm * 700) / PerfParallelAgentManager)*k2) * 40;
		assert(ProcRequest > NULL);
#ifdef DEBUG 
		cout << "ProcRequest " << ProcRequest << endl;
#endif
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DEBUG 
	cout << " DEBUG MODE!" << endl;
#endif
	cout << "==================================================================================" << endl;
	cout << "	������: DSMPM" << endl;
	cout << "	���� : ������������� �������� ���������� � ������������ ����, " << endl;
	cout << "	����������� �� ������������ ����������� ���������� INTEL XEON PHI" << endl;
	cout << "	Database System on Manycore Processor Model(DSMPM)" << endl;
	cout << "	����������� : ����������� �.�." << endl;
	cout << "	������������ : ����������� �.�." << endl;
	cout << "	���� ��������� : 03.06.2017" << endl;
	cout << "===================================================================================" << endl;

	float	TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps, TALL, t_0, k1, Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, FastMemThroughput, PerfParallelAgentManager;
	string _Treads_N;
	//*-------------------------------------------------------------------------------------------------*/
	TimeFinal = 1;
	k1 = 25000000; // �����������
	//*-------------------------------------------------------------------------------------------------*/

	cout << "������� ������ ��������� S: ";
	cin >> Size1;
	assert(Size1 > NULL);
	assert(Size1 != NULL);
	cout << "������� ������ ��������� R: ";
	cin >> Size2;
	assert(Size2 > NULL);
	assert(Size2 != NULL);
	cout << "������� ������ ������� ������: ";
	cin >> SFastMemory;
	assert(SFastMemory > NULL);
	assert(SFastMemory != NULL);
	cout << "������� ������ �������� ������: ";
	cin >> SMainMemory;
	assert(SMainMemory > NULL);
	assert(SMainMemory != NULL);
	cout << "������� ���������� ����������� �������� ������: ";
	cin >> MainMemThroughput;
	assert(MainMemThroughput > NULL);
	assert(MainMemThroughput != NULL);
	cout << "������� ���������� ����������� ������� ������: ";
	cin >> FastMemThroughput;
	assert(FastMemThroughput > NULL);
	assert(FastMemThroughput != NULL);
	cout << "������� ������������������ ��������� ����������� �������: ";
	cin >> PerfParallelAgentManager;

	float _treads_N, Treads_N[100], Result[100];
	cout << "������� ���������� �������� �����:" << endl;
	cin >> _treads_N;
	assert(_treads_N > NULL);
	assert(_treads_N != NULL);

	for (int i = 0; i < _treads_N; i++)
	{
		cout << "������� ���������� ������� " << i << " �����:" << endl;
		cin >> Treads_N[i];
	}

	for (int i = 0; i < _treads_N; i++)
	{
		PerfParallelAgentManager = Treads_N[i];
		assert(PerfParallelAgentManager > NULL);
		assert(PerfParallelAgentManager != NULL);

		Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
		Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput);
		/*-------------------------------TimeFirst - ���������������� ���-----------------------------------*/
		t_load = memory_manager->Ftml + memory_manager->FragMM + memory_manager->GDAfrag_t1 + manager_of_parallel_agents->GDAfrag_t2;
		assert(t_load > NULL);
#ifdef DEBUG 
		cout << "t_load " << t_load << endl;
#endif
		t_0 = memory_manager->InOut + memory_manager->FragMM + manager_of_parallel_agents->t_f + manager_of_parallel_agents->t_g + t_load;
		assert(t_0 > NULL);
#ifdef DEBUG 
		cout << "t_0 " << t_0 << endl;
#endif
		TimeFirst = t_0 + t_load;
		/*--------------------------------Processing_steps - ���� ���������--------------------------------*/
		Time_j = manager_of_parallel_agents->MesAfrag + manager_of_parallel_agents->ProcRequest;
		assert(Time_j > NULL);
#ifdef DEBUG 
		cout << "Time_j " << t_load << endl;
#endif
		time_j = memory_manager->OutFragM + memory_manager->ClearFM + memory_manager->SendAF;
		assert(time_j > NULL);
#ifdef DEBUG 
		cout << "time_j " << t_load << endl;
#endif
		N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments;
#ifdef DEBUG 
		cout << "N_ProcessingSteps " << N_ProcessingSteps << endl;
#endif
		/*-------------------------------TimeFinal - ����������� ���---------------------------------------*/
		TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
		Result[i] = TALL;
	}

	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "� ���������� �������������� ���� �������� ��������� ����������: " << endl << endl;
	for (int i = 0; i < _treads_N; i++)
	{
		cout << "��� " << Treads_N[i] << " �������:  " << Result[i] << " �������� ��������� ������;" << endl;
	}
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	system("Pause");
	return 0;
}