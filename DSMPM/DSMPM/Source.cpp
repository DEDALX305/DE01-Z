#include <iostream>  // ��� ��������� cout
#include <cassert>  // ��� ������� assert
#include <string>  // �������� ��� ������
/*==============================================*/
#define NDEBUG // ���������� �����.
using namespace std;
/*==============================================*/

class Memory_manager // ����� �������� ������.
{
public:
	float t_1, t_2, InOut, Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio;
	Memory_manager(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
		/*���������� --------------------------------------------------------------*/
		// ��� ��� ����� ������������� �� ���������� ��������� �������� ����� ���� �� �������� ���������� ����� ����� 1 ����������� ������� �������.
		FragMM = 1;// ��������� �����, ����������� �� ������������ ������ � ������� ��-����.
		GDAfrag_t1 = 1; //����� ����������� �� ��������� ���������� ������ ������� �������-������ ���������� � ������� ������. 
		ClearFM = 1;//�����, ����������� �� ������� ������� ������, �������� ����������.
		SendAF = 1; //�����, ����������� �� �������� ������� ������������� ���������� � ������� ������ ��������� ������������ �������.
		FragMM = 1; //��������� �����, ����������� �� ������������ ������ � ������� ��-����.
		t_1 = 1; // ����� ����������� �� ��������� ���������� � ������� ��������� ������������ �������.
		t_2 = 1; // ����� ����������� �� ��������� ���������� � ������� ��������� ��������� ������.
		/*-------------------------------------------------------------------------*/
		if (Size1 > Size2) // �� ������� ������������ ������ � ������� ������ ������ ������ ���������� ������� ���������.
		{
			Large_ratio = Size1; // ������� ���������
			Small_ratio = Size2; // ������� ���������
		}
		else
		{
			Large_ratio = Size2; // ������� ���������
			Small_ratio = Size1; // ������� ���������
		}
		InOut = t_1 + t_2; // ����� ����������� �� ��������� ���������� � ������� ��������� ������������ ������� t_1  � ��������� ������ t_2.

		Ftml = (Small_ratio / MainMemThroughput); // ��������� �����, ����������� �� �������� �������� ��������� � ������� ������.
		assert(Ftml > 0); 
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
		assert(SizeFragmentLarge_ratio > 0);
#ifdef DEBUG 
		cout << "SizeFragmentLarge_ratio " << SizeFragmentLarge_ratio << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		SizeResultantSubfragment = SizeFragmentLarge_ratio + Small_ratio; // ������ ��������������� ���������.
		assert(SizeResultantSubfragment > 0);
#ifdef DEBUG 
		cout << "SizeResultantSubfragment " << SizeResultantSubfragment << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		OutFragM = SizeResultantSubfragment / MainMemThroughput; // �����, ����������� �� �������� ��������������� ������������ �� ������� ������ � ��������.
#ifdef DEBUG 
		cout << "OutFragM " << OutFragM << endl;
#endif			
	}
};

class Manager_of_parallel_agents // ����� �������� ������������ �������.
{
public:
	float t_g, t_f, MesAfrag, GDAfrag_t2, ProcRequest;

	Manager_of_parallel_agents(float k1, float k2, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput, float Virtual_cores)
	{
		/*���������� --------------------------------------------------------------*/
		t_g = 1;// ����� ����������� �� �������� ������ �������.
		t_f = 1; // ����� �������� ��������� ����������� �����������. 
		GDAfrag_t2 = 1;// ����� ����������� �� �������� ���������� ������ ������� ������������� ���������� � ������� ������ ��������� ������������ �������.
		MesAfrag = 1;// �����, ����������� �� ��������� ������� ������������� ���������� � ������� ������ ������ ������������ �������.
		/*-------------------------------------------------------------------------*/

		ProcRequest = (((k1 / FastMemThroughputm * 700) / Virtual_cores)*PerfParallelAgentManager) * k2; // ������� ����� 21.
		assert(ProcRequest != 0 || ProcRequest > 0);
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
	cout << "===============================================================================" << endl;
	cout << "	������: DSMPM" << endl;
	cout << "	���� : ������������� �������� ���������� � ������������ ����, " << endl;
	cout << "	����������� �� ������������ ����������� ���������� INTEL XEON PHI" << endl;
	cout << "	Database System on Manycore Processor Model(DSMPM)" << endl;
	cout << "	����������� : ����������� �.�." << endl;
	cout << "	������������ : ����������� �.�." << endl;
	cout << "	���� ��������� : 03.06.2017" << endl;
	cout << "===============================================================================" << endl;

	float TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps, TALL, t_0, k1, k2, Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, FastMemThroughput, PerfParallelAgentManager, Virtual_cores;
	string _Treads_N;
	float _treads_N, Treads_N[100], Result[100];
	/*-------------------------------------------------------------------------*/
	TimeFinal = 1; // ����� ���������� ����.
	k1 = 25000000; // �����������.
	k2 = 40; // �����������.
	/*-------------------------------------------------------------------------*/

	cout << "������� ������ ��������� S: ";
	cin >> Size1;
	assert(Size1 != 0 || Size1 > 0);
	cout << "������� ������ ��������� R: ";
	cin >> Size2;
	assert(Size2 != 0 || Size2 > 0);
	cout << "������� ������ ������� ������: ";
	cin >> SFastMemory;
	assert(SFastMemory != 0 || SFastMemory > 0);
	cout << "������� ������ �������� ������: ";
	cin >> SMainMemory;
	assert(SMainMemory != 0 || SMainMemory > 0);
	cout << "������� ���������� ����������� �������� ������: ";
	cin >> MainMemThroughput;
	assert(MainMemThroughput != 0 || MainMemThroughput > 0);
	cout << "������� ���������� ����������� ������� ������: ";
	cin >> FastMemThroughput;
	assert(FastMemThroughput != 0 || FastMemThroughput > 0);
	cout << "������� ������������������ ��������� ����������� �������: ";
	cin >> PerfParallelAgentManager;
	assert(PerfParallelAgentManager != 0 || PerfParallelAgentManager > 0);

	cout << "������� ���������� �������� �����: ";
	cin >> _treads_N;
	assert(_treads_N != 0 || _treads_N > 0);

	for (int i = 0; i < _treads_N; i++)
	{
		cout << "������� ���������� ����������� ���� " << i << " �����: ";
		cin >> Treads_N[i];
	}

	for (int i = 0; i < _treads_N; i++)
	{
		Virtual_cores = Treads_N[i];
		assert(Virtual_cores != 0 || Virtual_cores > 0);

		Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
		Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, k2, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput, Virtual_cores);

		/*-------------------------------TimeFirst - ���������������� ���-----------------------------------*/
		t_load = memory_manager->Ftml + memory_manager->FragMM + memory_manager->GDAfrag_t1 + manager_of_parallel_agents->GDAfrag_t2; // ������� ����� 18.
		assert(t_load > 0);
#ifdef DEBUG 
		cout << "t_load: " << t_load << endl;
#endif
		t_0 = memory_manager->InOut + memory_manager->FragMM + manager_of_parallel_agents->t_f + manager_of_parallel_agents->t_g + t_load; // ������� ����� 17.
		assert(t_0 > 0);
#ifdef DEBUG 
		cout << "t_0 " << t_0 << endl;
#endif
		TimeFirst = t_0 + t_load;
		/*--------------------------------Processing_steps - ���� ���������--------------------------------*/
		Time_j = manager_of_parallel_agents->MesAfrag + manager_of_parallel_agents->ProcRequest; // ������� ����� 20.
		assert(Time_j > 0);
#ifdef DEBUG 
		cout << "Time_j " << t_load << endl;
#endif
		time_j = memory_manager->OutFragM + memory_manager->ClearFM + memory_manager->SendAF; // ������� ����� 22.
		assert(time_j > 0);
#ifdef DEBUG 
		cout << "time_j " << t_load << endl;
#endif
		N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments; // ����� ����������� �� ��������� ���� �����������.
#ifdef DEBUG 
		cout << "N_ProcessingSteps " << N_ProcessingSteps << endl;
#endif
		/*-------------------------------TimeFinal - ����������� ���---------------------------------------*/
		TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
		Result[i] = TALL;
	}

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "� ���������� �������������� ���� �������� ��������� ����������: " << endl << endl;
	for (int i = 0; i < _treads_N; i++)
	{
		cout << "��� " << Treads_N[i] << " ����������� ����:  " << Result[i] << " �������� ��������� ������;" << endl;
	}
	cout << "-------------------------------------------------------------------------------" << endl;
	system("Pause");
	return 0;
}