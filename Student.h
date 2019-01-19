#pragma once
#include <string>
#include "Oceny.h"
#include "Osoba.h"
using namespace std;

class Student : public virtual Osoba {
	public:
		Student(string imie, string nazwisko, string data_ur, int nr_ind);
		int getNrIndeksu()const { return m_nr_ind; };
		void getOceny();
		vector<Oceny> oceny;
	private:
		int m_nr_ind;
		
};

ostream& operator <<(ostream& o, const Student& student);