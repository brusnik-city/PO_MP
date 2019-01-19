#pragma once
#include <string>
using namespace std;

class Osoba {

	public:
		Osoba(string imie, string nazwisko, string data_ur);
		string getImie()const { return m_imie; };
		string getNazwisko()const { return m_nazwisko; };
		string getData_ur()const { return m_data_ur; };

	private:
		string m_imie;
		string m_nazwisko;
		string m_data_ur;

 };