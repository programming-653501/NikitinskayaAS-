#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#include <iostream>
#include <string>
#include <vcl.h>
#include <errno.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

using namespace std;

double Check();
int CheckForInt();

struct Apartment;

struct Client
{
	Client* Next;
	Client* Previous;

	string Surname;
	string Name;
	string Phone;

	Apartment* Apartments[1];

	void Display()
	{
		cout << "\n" << Surname << "\n" << Name << "\n" << Phone << "\n\n";
	}

	Client(string surname, string name, string phone)
	{
		Surname = surname;
		Name = name;
		Phone = phone;
		Apartments[0] = NULL;
	}

	Client(const Client* info)
	{
		Surname = info -> Surname;
		Name = info -> Name;
		Phone = info -> Phone;
		Apartments[0] = info -> Apartments[0];
	}
};

struct Apartment
{
	// pointers
	Apartment* Next;
	Apartment* Previous;

	// properties
	string Region;
	string Address;
	string Type;
	int Floor;
	int Cost;
	double Area;
	Client** Clients;

	// output
	void Display()
	{
		cout << "\nРегион: " << Region << "\nАдрес: " << Address << "\nЭтаж: " \
		<< Floor << "\nПлощадь: " << Area << "\nТип планировки: " << Type \
		<< "\nЦена: " << Cost << "\n\n";
	}

	// constructor
	Apartment(string region, string address, int floor, \
	double area, string type, int cost)
	{
		Region = region;
		Address = address;
		Type = type;
		Floor = floor;
		Area = area;
		Cost = cost;

		Clients = new Client*[1];
		Clients[0] = NULL;

	}

	// copying constructor
	Apartment(const Apartment* info)
	{
		Region = info -> Region;
		Address = info -> Address;
		Floor = info -> Floor;
		Area = info -> Area;
		Type = info -> Type;
		Cost = info -> Cost;
		Clients = new Client*[1];
		Clients[0] = info -> Clients[0];

	}
};

struct Base
{
	Client* FirstClient;
	Client* LastClient;

	// list of apartments
	Apartment* FirstApartment;
	Apartment* LastApartment;

	// operations with clients
	void AddClient(const Client* info)
	{
		LastClient -> Next = new Client(info);
		LastClient -> Next -> Previous = LastClient;
		LastClient = LastClient -> Next;
	}

	Client* FindClient(string surname, string name)
	{
		Client* Temp = FirstClient;
		while (Temp != NULL)
		{
			if (Temp -> Surname == surname && Temp -> Name == name)
				return Temp;
			else
				Temp = Temp -> Next;
		}
		return NULL;
	}
	bool RemoveClient(Client* info)
	{
		// checking NULL
		if (info == NULL || FindClient(info -> Surname, info -> Name) == NULL)
		{
			cout << "Ошибка.\n";
			return false;
		}

		// deleting the reader
		if (info == LastClient)
		{
			LastClient = LastClient -> Previous;
			info -> Previous -> Next = NULL;
		}
		else if (info == FirstClient)
		{
			FirstClient = FirstClient -> Next;
			info -> Next -> Previous = NULL;
		}
		else
		{
			info -> Previous -> Next = info -> Next;
			info -> Next -> Previous = info -> Previous;
		}

		delete info;
		return true;
	}

	void DisplayClients()
	{
		Client* Temp = FirstClient;
		Temp -> Display();

		while (Temp -> Next != NULL)
		{
			Temp -> Next -> Display();
			Temp = Temp -> Next;
		}
	}

	void SaveClients()
	{
		FILE *p = fopen("D:\\DZ\\2 sem\\Proga\\Apartment2.txt", "w");
		Client* Temp = FirstClient;

		while (Temp != NULL)
		{
			fprintf(p, "%s %s %s\n", Temp -> Surname.c_str(), \
				Temp -> Name.c_str(), Temp -> Phone.c_str());
			Temp = Temp -> Next;
		}
		fclose(p);
	}

	// operations with apartments
	void AddApartment(const Apartment* info)
	{
		Apartment* NewApartment;

		LastApartment -> Next = new Apartment(info);
		LastApartment -> Next -> Previous = LastApartment;
		LastApartment = LastApartment -> Next;
	}

	Apartment* FindApartment(string info)
	{
		Apartment* Temp = FirstApartment;
		while (Temp != NULL)
		{
			if (Temp -> Address == info)
				return Temp;
			else
				Temp = Temp -> Next;
		}
		return NULL;
	}

	Apartment* FindApartmentRegion(string region1, string region0, string type, \
	int floor1, int floor0, int price1, int price0)
	{
		Apartment* Temp = FirstApartment;
		bool check = false;
		while(Temp != NULL)
		{
			if (Temp -> Type == type || type == "")
			{
				if (Temp -> Region == region1 || region1 == "")
				{
					if (Temp -> Region != region0 || region0 == "")
					{
						if (Temp -> Floor == floor1 || floor1 == 0)
						{
							if (Temp -> Floor != floor0 || floor0 == 0)
							{
								if (Temp -> Cost >= price1 || price1 == 0)
								{
									if (Temp -> Cost <= price0 || price0 == 0)
									{
										check = true;
										Temp -> Display();
									}
								}
							}
						}
					}
				}
			}
			Temp = Temp -> Next;
		}
		if (!check)
			cout << "Ничего не найдено. Попробуйте изменить параметры поиска.\n";
		return NULL;
	}

	bool RemoveApartment(Apartment* info)
	{
		// checking NULL
		if (info == NULL || FindApartment(info -> Address) == NULL)
		{
			cout << "Ошибка.\n";
			return false;
		}

		// deleting
		if (info == LastApartment)
		{
			LastApartment = LastApartment -> Previous;
			info -> Previous -> Next = NULL;
		}
		else if (info == FirstApartment)
		{
			FirstApartment = FirstApartment -> Next;
			info -> Next -> Previous = NULL;
		}
		else
		{
			info -> Previous -> Next = info -> Next;
			info -> Next -> Previous = info -> Previous;
		}

		delete info;
		return true;
	}

	void DisplayApartments()
	{
		Apartment* Temp = FirstApartment;
		Temp -> Display();

		while (Temp -> Next != NULL)
		{
			Temp -> Next -> Display();
			Temp = Temp -> Next;
		}
	}

	void SaveApartments()
	{
		FILE *p = fopen("D:\\DZ\\2 sem\\Proga\\Apartment.txt", "w");
		Apartment* Temp = FirstApartment;

		while (Temp != NULL)
		{
			fprintf(p, "%s %s %d %lf %s %d\n", Temp -> Region.c_str(), \
				Temp -> Address.c_str(), Temp -> Floor, Temp -> Area, \
				Temp -> Type.c_str(), Temp -> Cost);
			Temp = Temp -> Next;
		}

		fclose(p);
	}

	// operation with both
	bool Connect(Client* client, Apartment* apartment) {
		for (int i = 0; i < 1; i++) {
			if (client -> Apartments[i] == NULL) {
				for (int j = 0; j < 1; j++) {
					if (apartment -> Clients[j] == NULL) {
						client -> Apartments[i] = apartment;
						apartment -> Clients[j] = client;
						return true;
					}
				}
			}
		}
		return false;
	}

	void DisplayConnections() {
		Client* Temp = FirstClient;
		while (Temp != NULL) {
			for (int i = 0; i < 1; i++) {
				if (Temp -> Apartments[i] != NULL) {
					cout << Temp -> Surname << " " << Temp -> Name << " => " \
					<< Temp -> Apartments[i] -> Address << endl;
				}
			}
			Temp = Temp -> Next;
		}
	}

	void SaveConnections()
	{
		FILE *p = fopen("D:\\DZ\\2 sem\\Proga\\Apartment3.txt", "w");
		Client* Temp = FirstClient;
		while (Temp != NULL)
		{
			for (int i = 0; i < 1; i++)
			{
				if (Temp -> Apartments[i] != NULL) {
					fprintf(p, "%s %s => %s\n", Temp -> Surname.c_str(), \
					Temp -> Name.c_str(), Temp -> Apartments[i] -> Address.c_str());
				}
			}
			Temp = Temp -> Next;
		}

		fclose(p);
	}

	// first part of the constructor
	void InitializeClients(const char* FileClients) {
		// initializing
		FILE *p = fopen(FileClients, "r");
		char Surname[100], Name[100], Phone[100];
		Client* Temprorary = NULL;

		// first
		if (!feof(p))
		{
			if (fscanf(p, "%s %s %s", &Surname, &Name, &Phone) != EOF)
			{
				FirstClient = new Client(Surname, Name, Phone);
				LastClient = FirstClient;
			}
		}

		// other
		while (!feof(p)) {
			if (fscanf(p, "%s %s %s", &Surname, &Name, &Phone) != EOF)
			{
				LastClient -> Next = new Client(Surname, Name, Phone);
				LastClient -> Next -> Previous = LastClient;
				LastClient = LastClient -> Next;
			}
		}

		fclose(p);
	}

	// second part
	void InitializeApartments(const char* FileApartments)
	{
		// initializing
		FILE *p = fopen(FileApartments, "r");
		char Region[100], Address[100], Type[100];
		int Floor, Cost;
		double Area;
		Apartment* Temprorary = NULL;

		// first
		if (!feof(p))
		{
			if (fscanf(p, "%s %s %d %lf %s %d", &Region, &Address, &Floor, \
			&Area, &Type, &Cost) != EOF)
			{
				FirstApartment = new Apartment(Region, Address, Floor, \
					Area, Type, Cost);
				LastApartment = FirstApartment;
			}
		}

		// other
		while (!feof(p))
		{
			if (fscanf(p, "%s %s %d %lf %s %d", &Region, &Address, &Floor, \
				&Area, &Type, &Cost) != EOF)
			{
				LastApartment -> Next = new Apartment(Region, Address, Floor, \
					Area, Type, Cost);
				LastApartment -> Next -> Previous = LastApartment;
				LastApartment = LastApartment -> Next;
			}
		}

		fclose(p);
	}

	// third part
	void Initialize(const char* File)
	{
		FILE *p = fopen(File, "r");
		char surname[100], name[100], apartment[100];
		Client* ClientToSell;
		Apartment* ApartmentToSell;

		while (!feof(p))
		{
			if (fscanf(p, "%s %s => %s", &surname, &name, &apartment)!= EOF)
			{
				ClientToSell = FindClient(surname, name);
				ApartmentToSell = FindApartment(apartment);
				if (ClientToSell!= NULL && ApartmentToSell != NULL)
				{
					Connect(ClientToSell, ApartmentToSell);
				}
			}
		}

		fclose(p);
	}

	// constructor
	Base(const char* FileClients, const char* FileApartments, const char* File)
	{
		InitializeClients(FileClients);
		InitializeApartments(FileApartments);
		Initialize(File);
	}
};


struct Menu
{
	// choosing the command
	static int ChooseCommand(Base* info)
	{
		cout << "\nВыберите одну из следующих команд: \
		\n 1. Список предложений\n 2. Добавить новое предложение\n 3. Найти\n \
4. Купить\n 5. Информация о продавце\n 6. Сохранить\n 7. Выход: \n";
		int command;
		command = CheckForInt();
		if (command == 1) {
			Display(info);
			return 0;
		}
		else if (command == 2) {
			Add(info);
			return 0;
		}
		else if (command == 3) {
			Find(info);
			return 0;
		}
		else if (command == 4) {
			Delete(info);
			return 0;
		}
		else if (command == 5) {
			Information(info);
			return 0;
		}
		else if (command == 6) {
			Save(info);
			return 0;
		}
		else if (command == 7) {
			cout << "Press any key . . . ";
			getch();
			return 1;
		}
		else {
			cout << "Ошибка. Попробуйте снова.\n";
			return 0;
		}
	}

	// display function
	static void Display(Base* info)
	{
		info -> DisplayApartments();
	}

	// add function
	static void Add(Base* info)
	{
			Apartment* ApartmentToAdd = new Apartment("", "", 0, 0, "", 0);
			cout << "Регион: ";
			cin >> ApartmentToAdd -> Region;
			cout << "Адрес: ";
			cin >> ApartmentToAdd -> Address;
			cout << "Этаж: ";
			ApartmentToAdd -> Floor = CheckForInt();
			cout << "Площадь: ";
			ApartmentToAdd -> Area = Check();
			cout << "Тип: ";
			cin >> ApartmentToAdd -> Type;
			cout << "Цена: : ";
			ApartmentToAdd -> Cost = Check();
			info -> AddApartment(ApartmentToAdd);

			cout << "Данные о собственнике:\n";
			Client* ClientToAdd = new Client("", "", "");
			cout << "Фамилия: ";
			cin >> ClientToAdd -> Surname;
			cout << "Имя: ";
			cin >> ClientToAdd -> Name;
			cout << "Телефон: ";
			cin >> ClientToAdd -> Phone;
			info -> AddClient(ClientToAdd);
			bool q;
			info -> Connect(ClientToAdd, ApartmentToAdd);
			FILE* p;
			p = fopen("D:\\DZ\\2 sem\\Proga\\Apartment3.txt","a");
			fprintf(p, "%s %s => %s\n", ClientToAdd -> Surname.c_str(), \
				ClientToAdd -> Name.c_str(), ClientToAdd -> Apartments[0] \
				-> Address.c_str());
			Save(info);

	}

	// find function
	static void Find(Base* info)
	{
		string region1 = "";
		string region0 = "";
		string type = "";
		int floor1 = 0, floor0 = 0;
		int price1 = 0, price0 = 0;
		cout << "\tТип: (Если есть пожелания, введите 1)\n";
		int answer;
		answer = CheckForInt();
		if (answer == 1)
		{
			cout << "\t\tТип: ";
			cin >> type;
		}

		cout << "\tРегион: (Если есть пожелания, введите 1)\n";
		int answer1;
		answer1 = CheckForInt();
		if (answer1 == 1)
		{
			cout << "\t\tПриоритетный регион: (Если есть пожелания, введите 1)\n";
			int answer1_1;
			answer1_1 = CheckForInt();
			if (answer1_1 == 1)
			{
				cout << "\t\t\tПриоритетный регион: ";
				cin >> region1;
			}

			cout << "\t\tНежелательный регион: (Если есть пожелания, введите 1)\n";
			int answer1_2;
			answer1_2 = CheckForInt();
			if (answer1_2 == 1)
			{
				cout << "\t\t\tНежелательный регион: ";
				cin >> region0;
			}
		}
		cout << "\tЭтаж: (Если есть пожелания, введите 1)\n";
		int answer2;
		answer2 = CheckForInt();
		if (answer2 == 1)
		{
			cout << "\t\tПриоритетный этаж: (Если есть пожелания, введите 1)\n";
			int answer2_1;
			answer2_1 = CheckForInt();
			if (answer2_1 == 1)
			{
				cout << "\t\t\tПриоритетный этаж: ";
				floor1 = CheckForInt();
			}

			cout << "\t\tНежелательный этаж: (Если есть пожелания, введите 1)\n";
			int answer2_2;
			answer2_2 = CheckForInt();
			if (answer2_2 == 1)
			{
				cout << "\t\t\tНежелательный этаж: ";
				floor0 = CheckForInt();
			}
		}
		cout << "\tМеньше(Больше), чем введённая вами сумма (Если есть пожелания, введите 1)\n";
		int answer3;
		answer3 = CheckForInt();
		if (answer3 == 1)
		{
			cout << "\t\tМеньше, чем: (Если есть пожелания, введите 1)\n";
			int answer3_1;
			answer3_1 = CheckForInt();
			if (answer3_1 == 1)
			{
				cout << "\t\t\tМеньше, чем: ";
				price0 = CheckForInt();
			}

			cout << "\t\tБольше, чем: (Если есть пожелания, введите 1)\n";
			int answer3_2;
			answer3_2 = CheckForInt();
			if (answer3_2 == 1)
			{
				cout << "\t\t\tБольше, чем: ";
				price1 = CheckForInt();
			}
		}
		Apartment* ApartmentToDisplay = info -> FindApartmentRegion\
			(region1, region0, type, floor1, floor0, price1, price0);
	}

	// delete function
	static void Delete(Base* info)
	{
		Apartment* ApartmentToSell = new Apartment("", "", 0, 0.0, "", 0);
		cout << "Введите адрес: ";
		cin >> ApartmentToSell -> Address;

		FILE *p = fopen("D:\\DZ\\2 sem\\Proga\\Apartment3.txt", "r");
		char surname[100], name[100], apartment[100];
		Client* ClientToDelete;
		Apartment* ApartmentToDelete;
		bool check = false;
		while (!feof(p))
		{
			ApartmentToDelete = NULL;
			if (fscanf(p, "%s %s => %s\n", &surname, &name, &apartment)!= EOF)
			{
				ApartmentToDelete = info -> FindApartment(apartment);
				if (ApartmentToDelete -> Address == ApartmentToSell -> Address)
				{
					check = true;
					ClientToDelete = info -> FindClient(surname, name);
					ApartmentToDelete = info -> FindApartment\
						(ApartmentToSell -> Address);
				}
				if (check)
				{
					if (info -> RemoveApartment(ApartmentToDelete) && \
						info -> RemoveClient(ClientToDelete))
						{
							cout << "Поздравляем с покупкой!.\n";
							Save(info);
							break;
						}
				}
			}
		}
		fclose(p);
		if(check == false)
			cout << "Ошибка. Попробуйте снова.\n";
	}
	// info function
	static void Information(Base* info)
	{
		Apartment* ApartmentToKnow = new Apartment("", "", 0, 0.0, "", 0);
		cout << "Введите адрес: ";
		cin >> ApartmentToKnow -> Address;

		FILE *p = fopen("D:\\DZ\\2 sem\\Proga\\Apartment3.txt", "r");
		char surname[100], name[100], apartment[100];
		Client* ClientToInfo;
		Apartment* ApartmentToInfo;
		bool check = false;
		while (!feof(p))
		{
			ApartmentToInfo = NULL;
			if (fscanf(p, "%s %s => %s\n", &surname, &name, &apartment)!= EOF)
			{
				ApartmentToInfo = info -> FindApartment(apartment);
				if (ApartmentToInfo -> Address == ApartmentToKnow -> Address)
				{
					check = true;
					ClientToInfo = info -> FindClient(surname, name);
					ApartmentToInfo = info -> FindApartment(ApartmentToKnow -> Address);
					fprintf(p, "");
				}
				if (check)
				{
					ClientToInfo -> Display();
					break;
				}
			}
		}
		fclose(p);
		if(check == false)
			cout << "Ошибка. Попробуйте ещё раз.\n";
	}

	// save function
	static void Save(Base* info)
	{
		info -> SaveApartments();
		info -> SaveClients();
		info -> SaveConnections();
		cout << "Success.\n";
	}
};

 int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Base* MyBase = new Base("D:\\DZ\\2 sem\\Proga\\Apartment2.txt", \
	"D:\\DZ\\2 sem\\Proga\\Apartment.txt","D:\\DZ\\2 sem\\Proga\\Apartment3.txt");
	Menu* MyInterface = new Menu();

	while (true) {
		if (MyInterface -> ChooseCommand(MyBase))
			break;
	}
	return 0;
}

 double Check()
 {
	double c;
	while (!(cin >> c) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!\nВведите верное число: ";
	}
	return c;
 }

 int CheckForInt()
 {
	int x;
	bool success = false;
	while(!success)
	{
		cin >> x ;
		if(cin.good())
		{
			success = true;
		}
		else
			cout << "Значение введено неверно. Повторите ввод" << endl;
			cin.clear();
			_flushall();
	}
	return x;
 }
