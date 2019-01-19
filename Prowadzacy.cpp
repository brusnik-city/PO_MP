#include "Prowadzacy.h"
#include <iostream>
using namespace std;


Prowadzacy::Prowadzacy(string imie, string nazwisko, string data_ur, string st_naukowy, string przedmiot) 
	: Osoba(imie, nazwisko, data_ur), m_st_naukowy(st_naukowy), m_przedmiot(przedmiot) {
	
};

ostream& operator <<(ostream& o,const Prowadzacy& prowadzacy) {
	o << "===============================================" << endl;
	o << prowadzacy.getImie() << " " << prowadzacy.getNazwisko()<<endl
	<< "data urodzenia: " << prowadzacy.getData_ur()<<endl
	<< "stopien naukowy: " << prowadzacy.getStopien()<<endl
	<< "prowadzony przedmiot: "<<prowadzacy.getPrzedmiot() << endl;
	return o;
}
