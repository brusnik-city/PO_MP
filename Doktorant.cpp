#include "Doktorant.h"
#include <iostream>
using namespace std;

Doktorant::Doktorant(string imie, string nazwisko, string data_ur, string st_naukowy, int nr_ind,string przedmiot):
	Osoba(imie,nazwisko,data_ur), Student(imie, nazwisko, data_ur, nr_ind), Prowadzacy(imie, nazwisko, data_ur, st_naukowy,przedmiot) {
};

void Doktorant::getOceny()
{
	vector<Oceny>::iterator i;

	for (i = oceny.begin(); i != oceny.end(); i++)
	{
		cout << *i;
	}
}

ostream& operator<<(ostream& o, const Doktorant& doktorant) {
	o << "===============================================" << endl;
	o << doktorant.getImie() << " " << doktorant.getNazwisko() << endl
		<< "data urodzenia: " << doktorant.getData_ur() << endl
		<< "numer indeksu: " << doktorant.getNrIndeksu() << endl
		<< "stopien naukowy: " << doktorant.getStopien() << endl
		<< "prowadzony przedmiot: " << doktorant.getPrzedmiot() << endl;
	return o;
}