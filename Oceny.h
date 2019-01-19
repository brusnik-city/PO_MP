#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Oceny
{
public:
	Oceny(string Przedmiot);
	Oceny(string Przedmiot,int* tab);
	string getPrzedmiot()const { return m_przedmiot; }
	int getOcena(int i)const { return m_oceny[i]; }
	int size()const { return m_oceny.size(); }
private:
	string m_przedmiot;
	vector<int> m_oceny;
};

ostream& operator <<(ostream& o, const Oceny& ocena);
