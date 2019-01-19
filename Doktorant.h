#pragma once
#include <string>
#include "Student.h"
#include "Prowadzacy.h"

class Doktorant : public Student,public Prowadzacy {
	public:
		Doktorant(string imie, string nazwisko, string data_ur, string st_naukowy, int nr_ind,string przedmiot);
		void getOceny();
};

ostream& operator<<(ostream& o, const Doktorant& doktorant);