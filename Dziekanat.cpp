#include "Dziekanat.h"
#include <fstream>

Dziekanat::Dziekanat()
{

	ifstream plik1("Prowadzacy.txt");
	while (!plik1.eof())
	{
		string tab[12];
		for (int i = 0; i < 12; i++)
			plik1 >> tab[i];
		if(!plik1.eof())
			m_prowadzacy.push_back(Prowadzacy(tab[1], tab[2], tab[5], tab[8], tab[11]));
	}
	plik1.close();
	ifstream plik2("Studenci.txt");
	while (!plik2.eof())
	{
		string tab[9];
		for (int i = 0; i < 9; i++)
			plik2 >> tab[i];
		if (!plik2.eof())
			m_studenci.push_back(Student(tab[1], tab[2], tab[5], stoi(tab[8])));
	}
	plik2.close();
	ifstream plik3("Doktoranci.txt");
	while (!plik3.eof())
	{
		string tab[15];
		for (int i = 0; i < 15; i++)
			plik3 >> tab[i];
		if (!plik3.eof())
			m_doktoranci.push_back(Doktorant(tab[1], tab[2], tab[5], tab[11], stoi(tab[8]),tab[13]));
	}
	plik3.close();

}
// studenci
void Dziekanat::dodajStudenta()
{
	string imie,nazwisko,data_ur;
	int nr_indeksu;
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj date urodzenia: ";
	cin >> data_ur;
	cout << "Podaj numer indeksu: ";
	cin >> nr_indeksu;

	m_studenci.push_back(Student(imie, nazwisko, data_ur, nr_indeksu));
	cout << "Dodano studenta."<<endl<<endl;
	ofstream plik("Studenci.txt", ios::app);
	plik << m_studenci[m_studenci.size()-1];


}

void Dziekanat::wyszukajStudenta()
{
	int nr_indeksu;
	cout << "Podaj numer indeksu: ";
	cin >> nr_indeksu;
	vector<Student>::iterator i;
	for (i = m_studenci.begin(); i != m_studenci.end(); i++)
	{
		if (i->getNrIndeksu() == nr_indeksu)
		{
			cout << *i;
		}
	}
}

void Dziekanat::wyszukajStudentaPoImieniu()
{
	string imie;
	string nazwisko;
	cout << "Podaj imie studenta: ";
	cin >> imie;
	cout << "Podaj nazwisko studenta: ";
	cin >> nazwisko;
	vector<Student>::iterator i;
	for (i = m_studenci.begin(); i != m_studenci.end(); i++)
	{
		if ((imie == i->getImie()) && (nazwisko == i->getNazwisko()))
		{
			cout << *i;
		}
	}
}

void Dziekanat::wyswietlStudentow()
{
	vector<Student>::iterator i;
	for (i = m_studenci.begin(); i != m_studenci.end(); i++)
	{
		cout << *i;
	}
}

void Dziekanat::bazaStudentow()
{
	system("cls");
	int a;
	cout << "===============================================" << endl
		<< "=                                             =" << endl
		<< "=             Co chcesz zrobic?               =" << endl
		<< "=                                             =" << endl
		<< "= 1. Wyswietl wszystkich studentow.           =" << endl
		<< "= 2. Wyszukaj studenta po numerze indeksu.    =" << endl
		<< "= 3. Wyszukaj studenta po imieniu i nazwisku. =" << endl
		<< "= 4. Dodaj do bazy nowego studenta.           =" << endl
		<< "= 5. Wyswietl oceny studenta.                 =" << endl
		<< "=                                             =" << endl
		<< "===============================================" << endl;
	cout << "Wybrana opcja: ";
	cin >> a;

	switch (a) {
	case 1:
		wyswietlStudentow();
		break;
	case 2:
		wyszukajStudenta();
		break;
	case 3:
		wyszukajStudentaPoImieniu();
		break;
	case 4:
		dodajStudenta();
		break;
	case 5:
		wyswietlOcenyStudenta();
		break;
	default:
		cout << "Podaj wlasciwe dane!" << endl;
		break;
	}
}

void Dziekanat::wyswietlOcenyStudenta()
{
	string imie;
	string nazwisko;
	cout << "Podaj imie studenta: ";
	cin >> imie;
	cout << "Podaj nazwisko studenta: ";
	cin >> nazwisko;
	vector<Student>::iterator i;
	for (i = m_studenci.begin(); i != m_studenci.end(); i++)
	{
		if ((imie == i->getImie()) && (nazwisko == i->getNazwisko()))
		{
			(i)->getOceny();
		}
	}
}

//prowadzacy
void Dziekanat::dodajProwadzacego()
{
	string imie, nazwisko, data_ur,stopien,przedmiot;
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj date urodzenia: ";
	cin >> data_ur;
	cout << "Podaj stopien naukowy: ";
	cin >> stopien;
	cout << "Podaj prowadzony przedmiot: ";
	getline(cin, przedmiot);
	getline(cin, przedmiot);

	m_prowadzacy.push_back(Prowadzacy(imie, nazwisko, data_ur, stopien,przedmiot));
	cout << "Dodano prowadzacego." << endl << endl;
	ofstream plik("Prowadzacy.txt", ios::app);
	plik << m_prowadzacy[m_prowadzacy.size() - 1];
}

void Dziekanat::wyszukajProwadzacego()
{
	string imie;
	string nazwisko;
	cout << "Podaj imie prowadzacego: ";
	cin >> imie;
	cout << "Podaj nazwisko prowadzacego: ";
	cin >> nazwisko;
	vector<Prowadzacy>::iterator i;
	for (i = m_prowadzacy.begin(); i != m_prowadzacy.end(); i++)
	{
		if ((imie == i->getImie()) && (nazwisko == i->getNazwisko()))
			cout << *i;
	}
}

void Dziekanat::wyswietlProwadzacych()
{
	vector<Prowadzacy>::iterator i;
	for (i = m_prowadzacy.begin(); i != m_prowadzacy.end(); i++)
	{
		cout << *i;
	}
}

void Dziekanat::bazaProwadzacych()
{
	system("cls");
	int a;
	cout << "===============================================" << endl
		<< "=                                             =" << endl
		<< "=             Co chcesz zrobic?               =" << endl
		<< "=                                             =" << endl
		<< "= 1. Wyswietl wszystkich prowadzacych.        =" << endl
		<< "= 2. Wyszukaj prowadzacego.                   =" << endl
		<< "= 3. Dodaj do bazy nowego prowadzacego.       =" << endl
		<< "=                                             =" << endl
		<< "===============================================" << endl;
	cout << "Wybrana opcja: ";
	cin >> a;

	switch (a) {
	case 1:
		wyswietlProwadzacych();
		break;
	case 2:
		wyszukajProwadzacego();
		break;
	case 3:
		dodajProwadzacego();
		break;
	default:
		cout << "Podaj wlasciwe dane!" << endl;
		break;
	}
}


//doktoranci
void Dziekanat::dodajDoktoranta()
{
	string imie, nazwisko, data_ur, stopien,przedmiot;
	int nr_ind;
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj date urodzenia: ";
	cin >> data_ur;
	cout << "Podaj stopien naukowy: ";
	cin >> stopien;
	cout << "Podaj numer indeksu: ";
	cin >> nr_ind;
	cout << "Podaj prowadzony przedmiot: ";
	std::getline(std::cin, przedmiot);
	std::getline(std::cin, przedmiot);
	

	m_doktoranci.push_back(Doktorant(imie, nazwisko, data_ur, stopien, nr_ind,przedmiot));
	cout << "Dodano doktoranta." << endl << endl;
	ofstream plik("Doktoranci.txt", ios::app);
	plik << m_doktoranci[m_doktoranci.size() - 1];
}

void Dziekanat::wyszukajDoktoranta()
{

	int nr_indeksu;
	cout << "Podaj numer indeksu: ";
	cin >> nr_indeksu;
	vector<Doktorant>::iterator i;
	for (i = m_doktoranci.begin(); i != m_doktoranci.end(); i++)
	{
		if (i->getNrIndeksu() == nr_indeksu)
			cout << *i;
	}
}

void Dziekanat::wyszukajDoktorantaPoImieniu()
{
	string imie;
	string nazwisko;
	cout << "Podaj imie doktoranta: ";
	cin >> imie;
	cout << "Podaj nazwisko doktoranta: ";
	cin >> nazwisko;
	vector<Doktorant>::iterator i;
	for (i = m_doktoranci.begin(); i != m_doktoranci.end(); i++)
	{
		if ((imie == i->getImie()) && (nazwisko == i->getNazwisko()))
			cout << *i;
	}
}

void Dziekanat::wyswietlDoktorantow()
{
	vector<Doktorant>::iterator i;
	for (i = m_doktoranci.begin(); i != m_doktoranci.end(); i++)
	{
		cout << *i;
	}
}

void Dziekanat::bazaDoktorantow()
{
	system("cls");
	int a;
	cout << "===============================================" << endl
		<< "=                                             =" << endl
		<< "=             Co chcesz zrobic?               =" << endl
		<< "=                                             =" << endl
		<< "= 1. Wyswietl wszystkich doktorantow.         =" << endl
		<< "= 2. Wyszukaj doktoranta po numerze indeksu.  =" << endl
		<< "= 3. Wyszukaj doktoranta po imieniu i nazwisku=" << endl
		<< "= 4. Dodaj do bazy nowego doktoranta.         =" << endl
		<< "= 5. Wyswietl oceny doktoranta.               =" << endl
		<< "=                                             =" << endl
		<< "===============================================" << endl;
	cout << "Wybrana opcja: ";
	cin >> a;

	switch (a) {
	case 1:
		wyswietlDoktorantow();
		break;
	case 2:
		wyszukajDoktoranta();
		break;
	case 3:
		wyszukajDoktorantaPoImieniu();
		break;
	case 4:
		dodajDoktoranta();
		break;
	case 5:
		wyswietlOcenyDoktoranta();
		break;

	default:
		cout << "Podaj wlasciwe dane!" << endl;;
		break;
	}
}

void Dziekanat::wyswietlOcenyDoktoranta()
{
	string imie;
	string nazwisko;
	cout << "Podaj imie doktoranta: ";
	cin >> imie;
	cout << "Podaj nazwisko doktoranta: ";
	cin >> nazwisko;
	vector<Doktorant>::iterator i;
	for (i = m_doktoranci.begin(); i != m_doktoranci.end(); i++)
	{
		if ((imie == i->getImie()) && (nazwisko == i->getNazwisko()))
		{
			i->getOceny();
		}
	}
}


//menu g³ówne
void Dziekanat::wybor()
{
	int a;
	cout << "===============================================" << endl
		<< "==== DZIEKANAT AKADEMII GORNICZO-HUTNICZEJ ====" << endl
		<< "===============================================" << endl
		<< "=                                             =" << endl
		<< "=              Czego szukasz?                 =" << endl
		<< "=                                             =" << endl
		<< "= 1. Baza studentow.                          =" << endl
		<< "= 2. Baza prowadzacych.                       =" << endl
		<< "= 3. Baza doktorantow.                        =" << endl
		<< "=                                             =" << endl
		<< "===============================================" << endl;

	cout << "Wybrana opcja: ";
	cin >> a;

	switch (a) {
	case 1:
		bazaStudentow();
		break;
	case 2:
		bazaProwadzacych();
		break;
	case 3:
		bazaDoktorantow();
		break;
	default:
		cout << "Podaj wlasciwe dane!" << endl;
		break;
	}
}