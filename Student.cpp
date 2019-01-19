#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string imie, string nazwisko, string data_ur, int nr_ind) 
	: Osoba(imie, nazwisko, data_ur), m_nr_ind(nr_ind) {
	oceny.push_back(Oceny("Jezyk Angielski"));
	oceny.push_back(Oceny("Programowanie Obiektowe"));
	oceny.push_back(Oceny("Analiza matematyczna"));
	oceny.push_back(Oceny("Algorytmy i struktury danych"));
};

void Student::getOceny()
{
	vector<Oceny>::iterator i;
		
	for (i = oceny.begin(); i != oceny.end(); i++)
	{
		cout << *i;
	}
}


ostream& operator <<(ostream& o,const Student& student) {
	o << "===============================================" << endl
		<< student.getImie() << " " << student.getNazwisko() << endl
		<< "data urodzenia: " << student.getData_ur() << endl
		<< "numer indeksu: " << student.getNrIndeksu() << endl;
	return o;
}