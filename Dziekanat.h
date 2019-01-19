#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Prowadzacy.h"
#include "Doktorant.h"

using namespace std;

class Dziekanat {
	public:
		Dziekanat();
		void wybor();
		void dodajStudenta();
		void dodajProwadzacego();
		void dodajDoktoranta();
		void wyszukajStudenta();
		void wyszukajStudentaPoImieniu();
		void wyszukajProwadzacego();
		void wyszukajDoktoranta();
		void wyszukajDoktorantaPoImieniu();
		void bazaStudentow();
		void bazaProwadzacych();
		void bazaDoktorantow();
		void wyswietlStudentow();
		void wyswietlDoktorantow();
		void wyswietlProwadzacych();
		void wyswietlOcenyStudenta();
		void wyswietlOcenyDoktoranta();



	private:
		vector<Student> m_studenci;
		vector<Prowadzacy> m_prowadzacy;
		vector<Doktorant> m_doktoranci;
};