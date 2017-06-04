#include <iostream>  // ��� ��������� cout
#include <cassert>  // ��� ������� assert
#include <string>  // �������� ��� ������
/*==============================================*/
#define NDEBUG
using namespace std;
/*==============================================*/

class Query_manager
{
public:
	float t_1, t_2, InOut;
	Query_manager() 
	{
		/*����������� ���������� --------------------------------------------------------------*/
		t_1 = 1;
		t_2 = 1;
		/*-------------------------------------------------------------------------------------*/
		InOut = t_1 + t_2;	
	};
};

class Memory_manager
{
public:
	float Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio;
	Memory_manager(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
		/*����������� ���������� --------------------------------------------------------------*/
		FragMM = 1;// ��������� �����, ����������� �� ������������ ������ � ������� ��-����;
		GDAfrag_t1 = 1; //����� ����������� �� ��������� ���������� ������ ������� �������-������ ���������� � ������� ������ 
		ClearFM = 1;//�����, ����������� �� ������� ������� ������, �������� ����������;
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

		Ftml = Small_ratio / MainMemThroughput; // ��������� �����, ����������� �� �������� �������� ��������� � ������� ������.
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
	float t_g, t_f, MesAfrag,  GDAfrag_t2, ProcRequest;
	
	Manager_of_parallel_agents(float k1, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput)
	{
		/*---------------------------����������� ����������-----------------------------------*/
		t_g = 1;// ����� ����������� �� �������� ������ �������.
		t_f = 1; // ����� �������� ��������� ����������� �����������. 
		GDAfrag_t2 = 1;// ����� ����������� �� �������� ���������� ������ ������� ������������� ���������� � ������� ������ ��������� ������������ �������.
		MesAfrag = 1;// �����, ����������� �� ��������� ������� ������������� ���������� � ������� ������ ������ ������������ �������.
		/*-------------------------------------------------------------------------------------*/

		ProcRequest = (k1 / FastMemThroughputm * 1000) / PerfParallelAgentManager;
		assert(ProcRequest > NULL);	
#ifdef DEBUG 
	cout << "ProcRequest " << ProcRequest << endl;
#endif
	}
};

class InputData 
{
public: 
	float	TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps, TALL, t_0, k1, Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, FastMemThroughput, PerfParallelAgentManager;
	string _Treads_N;
	void Data() 
	{
		/*-------------------------------------------------------------------------------------------------*/
		TimeFinal = 1;
		k1 = 25000000;
		/*-------------------------------------------------------------------------------------------------*/
		cout << "��������� 1 \n";
		//cin >> Size1;
		Size1 = 2000000;
		assert(Size1 > NULL);
		assert(Size1 != NULL);
		cout << "��������� 2 \n";
		//cin >> Size2;
		Size2 = 100000;
		assert(Size2 > NULL);
		assert(Size2 != NULL);
		cout << "������� ������ ������� ������ \n";
		//cin >> SFastMemory;
		SFastMemory = 800000;
		assert(SFastMemory > NULL);
		assert(SFastMemory != NULL);
		cout << "������� ������ �������� ������ \n";
		//cin >> SMainMemory;
		SMainMemory = 800000;
		assert(SMainMemory > NULL);
		assert(SMainMemory != NULL);
		cout << "������� ���������� ����������� �������� ������ \n";
		//cin >> MainMemThroughput;
		MainMemThroughput = 110000;
		assert(MainMemThroughput > NULL);
		assert(MainMemThroughput != NULL);
		cout << "������� ���������� ����������� ������� ������ \n";
		//cin >> FastMemThroughput;
		FastMemThroughput = 110000;
		assert(FastMemThroughput > NULL);
		assert(FastMemThroughput != NULL);
		cout << "������� ������������������ ��������� ����������� ������� \n";
		//cin >> PerfParallelAgentManager;

		Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
		Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput);
		Query_manager* query_manager = new Query_manager();
		/*-------------------------------TimeFirst - ���������������� ���-----------------------------------*/
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
		cout << "������� �����������  \n";
		TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
		cout << TALL << " �������� ������" << endl;
		/*-------------------------------------------------------------------------------------------------*/
	}
};

class Calculation {
public:
	void _calculation() 
	{
		
		

	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DEBUG 
	cout << " DEBUG MODE!" << endl;
#endif
	
	float	TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps, TALL, t_0, k1, Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, FastMemThroughput, PerfParallelAgentManager;
	string _Treads_N;
	///*-------------------------------------------------------------------------------------------------*/
	//TimeFinal = 1;
	//k1 = 25000000;
	///*-------------------------------------------------------------------------------------------------*/
	InputData* _InputData = new InputData;
	//cout << "��������� 1 \n";
	////cin >> Size1;
	//Size1 = 2000000;
	//assert(Size1 > NULL);
	//assert(Size1 != NULL);
	//cout << "��������� 2 \n";
	////cin >> Size2;
	//Size2 = 100000;
	//assert(Size2 > NULL);
	//assert(Size2 != NULL);
	//cout << "������� ������ ������� ������ \n";
	////cin >> SFastMemory;
	//SFastMemory = 800000;
	//assert(SFastMemory > NULL);
	//assert(SFastMemory != NULL);
	//cout << "������� ������ �������� ������ \n";
	////cin >> SMainMemory;
	//SMainMemory = 800000;
	//assert(SMainMemory > NULL);
	//assert(SMainMemory != NULL);
	//cout << "������� ���������� ����������� �������� ������ \n";
	////cin >> MainMemThroughput;
	//MainMemThroughput = 110000;
	//assert(MainMemThroughput > NULL);
	//assert(MainMemThroughput != NULL);
	//cout << "������� ���������� ����������� ������� ������ \n";
	////cin >> FastMemThroughput;
	//FastMemThroughput = 110000;
	//assert(FastMemThroughput > NULL);
	//assert(FastMemThroughput != NULL);
	//cout << "������� ������������������ ��������� ����������� ������� \n";
	////cin >> PerfParallelAgentManager;
	
	_InputData->Data();

	cout << "��������� ���� � ������ ����������� ������� ? Y/N" << endl;
	cin >> _Treads_N;
	if (_Treads_N == "Y")
	{
		float _treads_N, Treads_N[100];
		cout << "������� ���������� ��������" << endl;
		cin >> _treads_N;
		assert(_treads_N > NULL);
		assert(_treads_N != NULL);

		for (int i = 0; i < _treads_N; i++) 
		{
			Treads_N[i] = _treads_N;
			PerfParallelAgentManager = Treads_N[i];
			assert(PerfParallelAgentManager > NULL);
			assert(PerfParallelAgentManager != NULL);

			
			_InputData->Data();
//			Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
//			Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput);
//			Query_manager* query_manager = new Query_manager();
//			/*-------------------------------TimeFirst - ���������������� ���-----------------------------------*/
//			t_load = memory_manager->Ftml + memory_manager->FragMM + memory_manager->GDAfrag_t1 + manager_of_parallel_agents->GDAfrag_t2;
//			assert(t_load > NULL);
//#ifdef DEBUG 
//			cout << "t_load " << t_load << endl;
//#endif
//			t_0 = query_manager->InOut + memory_manager->FragMM + manager_of_parallel_agents->t_f + manager_of_parallel_agents->t_g + t_load;
//			assert(t_0 > NULL);
//#ifdef DEBUG 
//			cout << "t_0 " << t_0 << endl;
//#endif
//			TimeFirst = t_0 + t_load;
//			/*--------------------------------Processing_steps - ���� ���������--------------------------------*/
//			Time_j = manager_of_parallel_agents->MesAfrag + manager_of_parallel_agents->ProcRequest;
//			assert(Time_j > NULL);
//#ifdef DEBUG 
//			cout << "Time_j " << t_load << endl;
//#endif
//			time_j = memory_manager->OutFragM + memory_manager->ClearFM + memory_manager->SendAF;
//			assert(time_j > NULL);
//#ifdef DEBUG 
//			cout << "time_j " << t_load << endl;
//#endif
//			N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments;
//#ifdef DEBUG 
//			cout << "N_ProcessingSteps " << N_ProcessingSteps << endl;
//#endif
//			/*-------------------------------TimeFinal - ����������� ���---------------------------------------*/
//			cout << "������� �����������  \n";
//			TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
//			cout << TALL << " �������� ������" << endl;
//			/*-------------------------------------------------------------------------------------------------*/
		}
	}
	else
	{
		InputData* _InputData = new InputData;
		_InputData->Data();
	}
	system("Pause");
	return 0;
}