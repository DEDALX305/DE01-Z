#include <iostream>  // для оператора cout
#include <cassert>  // для функции assert
#include <string>  // строчный тип данных
/*==============================================*/
#define NDEBUG // Отладочный режим.
using namespace std;
/*==============================================*/

class Memory_manager // Класс менеджер памяти.
{
public:
	float t_1, t_2, InOut, Large_ratio, Small_ratio, FragMM, Number_of_fragments, SizeFragment, Ftml, GDAfrag_t1, OutFragM, SizeResultantSubfragment, SendAF, ClearFM, SizeFragmentLarge_ratio;
	Memory_manager(float Size1, float Size2, float SFastMemory, float SMainMemory, float MainMemThroughput)
	{
		/*Переменные --------------------------------------------------------------*/
		// Так как время затрачиваемое на выполнение следующих действий очень мало то значение переменных будет равно 1 виртуальной еденицы времени.
		FragMM = 1;// указывает время, затраченное на фрагментацию данных в быстрой па-мяти.
		GDAfrag_t1 = 1; //время затраченное на получение менеджером памяти адресов подфраг-ментов хранящихся в быстрой памяти. 
		ClearFM = 1;//время, затраченное на очистку быстрой памяти, задается константно.
		SendAF = 1; //время, затраченное на отправку адресов подфрагментов хранящихся в быстрой памяти менеджеру параллельных агентов.
		FragMM = 1; //указывает время, затраченное на фрагментацию данных в быстрой па-мяти.
		t_1 = 1; // Время затраченное на сообщение информации о запросе менеджеру параллельных агентов.
		t_2 = 1; // Время затраченное на сообщение информации о запросе менеджеру менеджеру памяти.
		/*-------------------------------------------------------------------------*/
		if (Size1 > Size2) // По условию поставленной задачи в быструю память всегда должно помещаться меньшее отношение.
		{
			Large_ratio = Size1; // Большое отношение
			Small_ratio = Size2; // Меньшее отношение
		}
		else
		{
			Large_ratio = Size2; // Меньшее отношение
			Small_ratio = Size1; // Большое отношение
		}
		InOut = t_1 + t_2; // Время затраченное на сообщение информации о запросе менеджеру параллельных агентов t_1  и менеджеру памяти t_2.

		Ftml = (Small_ratio / MainMemThroughput); // Указывает время, затраченное на загрузку меньшего отношения в быструю память.
		assert(Ftml > 0); 
#ifdef DEBUG 
		cout << "Ftml " << Ftml << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		Number_of_fragments = Large_ratio / (((SFastMemory - Small_ratio) - Small_ratio) / 2); // Количество фрагментов.
		assert(Number_of_fragments > 1);
#ifdef DEBUG 
		cout << "Number_of_fragments " << Number_of_fragments << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		SizeFragmentLarge_ratio = ((SFastMemory - Small_ratio) - Small_ratio) / 2; // Размер фрагмента большого отношения.
		assert(SizeFragmentLarge_ratio > 0);
#ifdef DEBUG 
		cout << "SizeFragmentLarge_ratio " << SizeFragmentLarge_ratio << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		SizeResultantSubfragment = SizeFragmentLarge_ratio + Small_ratio; // Размер результирующего отношения.
		assert(SizeResultantSubfragment > 0);
#ifdef DEBUG 
		cout << "SizeResultantSubfragment " << SizeResultantSubfragment << endl;
#endif
		/*-------------------------------------------------------------------------------------*/
		OutFragM = SizeResultantSubfragment / MainMemThroughput; // Время, затраченное на выгрузку результирующего подфрагмента из быстрой памяти в основную.
#ifdef DEBUG 
		cout << "OutFragM " << OutFragM << endl;
#endif			
	}
};

class Manager_of_parallel_agents // Класс менеджер параллельных агентов.
{
public:
	float t_g, t_f, MesAfrag, GDAfrag_t2, ProcRequest;

	Manager_of_parallel_agents(float k1, float k2, float FastMemThroughputm, float PerfParallelAgentManager, float MainMemThroughput, float Virtual_cores)
	{
		/*Переменные --------------------------------------------------------------*/
		t_g = 1;// Время затраченное на создание группы агентов.
		t_f = 1; // Время проверки свободных виртуальных процессоров. 
		GDAfrag_t2 = 1;// Время затраченное на отправку менеджером памяти адресов подфрагментов хранящихся в быстрой памяти менеджеру параллельных агентов.
		MesAfrag = 1;// Время, затраченное на сообщение адресов подфрагментов хранящихся в быстрой памяти группе параллельных агентов.
		/*-------------------------------------------------------------------------*/

		ProcRequest = (((k1 / FastMemThroughputm * 700) / Virtual_cores)*PerfParallelAgentManager) * k2; // Формула номер 21.
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
	cout << "	Проект: DSMPM" << endl;
	cout << "	Тема : Моделирование операции соединения в параллельной СУБД, " << endl;
	cout << "	выполняемой на многоядерном центральном процессоре INTEL XEON PHI" << endl;
	cout << "	Database System on Manycore Processor Model(DSMPM)" << endl;
	cout << "	Разработчик : Рекачинский А.И." << endl;
	cout << "	Руководитель : Костенецкий П.С." << endl;
	cout << "	Дата изменения : 03.06.2017" << endl;
	cout << "===============================================================================" << endl;

	float TimeFirst, TimeFinal, t_load, Time_j, time_j, N_ProcessingSteps, TALL, t_0, k1, k2, Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput, FastMemThroughput, PerfParallelAgentManager, Virtual_cores;
	string _Treads_N;
	float _treads_N, Treads_N[100], Result[100];
	/*-------------------------------------------------------------------------*/
	TimeFinal = 1; // Время последнего шага.
	k1 = 25000000; // Коэффициент.
	k2 = 40; // Коэффициент.
	/*-------------------------------------------------------------------------*/

	cout << "Введите размер отношения S: ";
	cin >> Size1;
	assert(Size1 != 0 || Size1 > 0);
	cout << "Введите размер отношения R: ";
	cin >> Size2;
	assert(Size2 != 0 || Size2 > 0);
	cout << "Введите размер быстрой памяти: ";
	cin >> SFastMemory;
	assert(SFastMemory != 0 || SFastMemory > 0);
	cout << "Введите размер основной памяти: ";
	cin >> SMainMemory;
	assert(SMainMemory != 0 || SMainMemory > 0);
	cout << "Введите пропускную способность основной памяти: ";
	cin >> MainMemThroughput;
	assert(MainMemThroughput != 0 || MainMemThroughput > 0);
	cout << "Введите пропускную способность быстрой памяти: ";
	cin >> FastMemThroughput;
	assert(FastMemThroughput != 0 || FastMemThroughput > 0);
	cout << "Введите производительсноть менеджера паралельных агентов: ";
	cin >> PerfParallelAgentManager;
	assert(PerfParallelAgentManager != 0 || PerfParallelAgentManager > 0);

	cout << "Укажите количество повторов теста: ";
	cin >> _treads_N;
	assert(_treads_N != 0 || _treads_N > 0);

	for (int i = 0; i < _treads_N; i++)
	{
		cout << "Введите количество виртуальных ядер " << i << " теста: ";
		cin >> Treads_N[i];
	}

	for (int i = 0; i < _treads_N; i++)
	{
		Virtual_cores = Treads_N[i];
		assert(Virtual_cores != 0 || Virtual_cores > 0);

		Memory_manager* memory_manager = new Memory_manager(Size1, Size2, SFastMemory, SMainMemory, MainMemThroughput);
		Manager_of_parallel_agents* manager_of_parallel_agents = new Manager_of_parallel_agents(k1, k2, FastMemThroughput, PerfParallelAgentManager, MainMemThroughput, Virtual_cores);

		/*-------------------------------TimeFirst - подготовительный шаг-----------------------------------*/
		t_load = memory_manager->Ftml + memory_manager->FragMM + memory_manager->GDAfrag_t1 + manager_of_parallel_agents->GDAfrag_t2; // Формула номер 18.
		assert(t_load > 0);
#ifdef DEBUG 
		cout << "t_load: " << t_load << endl;
#endif
		t_0 = memory_manager->InOut + memory_manager->FragMM + manager_of_parallel_agents->t_f + manager_of_parallel_agents->t_g + t_load; // Формула номер 17.
		assert(t_0 > 0);
#ifdef DEBUG 
		cout << "t_0 " << t_0 << endl;
#endif
		TimeFirst = t_0 + t_load;
		/*--------------------------------Processing_steps - Шаги обработки--------------------------------*/
		Time_j = manager_of_parallel_agents->MesAfrag + manager_of_parallel_agents->ProcRequest; // Формула номер 20.
		assert(Time_j > 0);
#ifdef DEBUG 
		cout << "Time_j " << t_load << endl;
#endif
		time_j = memory_manager->OutFragM + memory_manager->ClearFM + memory_manager->SendAF; // Формула номер 22.
		assert(time_j > 0);
#ifdef DEBUG 
		cout << "time_j " << t_load << endl;
#endif
		N_ProcessingSteps = (Time_j + time_j) * memory_manager->Number_of_fragments; // Время затраченное на обработку всех фграгментов.
#ifdef DEBUG 
		cout << "N_ProcessingSteps " << N_ProcessingSteps << endl;
#endif
		/*-------------------------------TimeFinal - Завершающий шаг---------------------------------------*/
		TALL = TimeFirst + N_ProcessingSteps + TimeFinal;
		Result[i] = TALL;
	}

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "В результате моделлирования были получены следующие результаты: " << endl << endl;
	for (int i = 0; i < _treads_N; i++)
	{
		cout << "При " << Treads_N[i] << " виртуальных ядер:  " << Result[i] << " условных временных едениц;" << endl;
	}
	cout << "-------------------------------------------------------------------------------" << endl;
	system("Pause");
	return 0;
}