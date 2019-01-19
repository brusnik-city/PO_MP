#pragma once
#include <string>
#include <vector>
#include "Osoba.h"
using namespace std;

class Prowadzacy : public virtual Osoba { 
	public: 
		Prowadzacy(string imie, string nazwisko, string data_ur, string st_naukowy,string przedmiot);
		string getPrzedmiot()const { return m_przedmiot; };
		string getStopien()const { return m_st_naukowy; };

	
	private:
		string m_st_naukowy;
		string m_przedmiot;
		vector<string> przedmiot;

};

ostream& operator <<(ostream& o, const Prowadzacy& prowadzacy);