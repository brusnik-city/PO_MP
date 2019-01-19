#include "Oceny.h"
#include <random>
using namespace std;
Oceny::Oceny(string Przedmiot) :m_przedmiot(Przedmiot)
{
	for (int i = 0; i < rand() % 10; i++)
	{
		m_oceny.push_back((rand() % 4) + 2);
	}
}


ostream& operator <<(ostream& o, const Oceny& ocena)
{
	o << ocena.getPrzedmiot() << ": ";
	for (int i = 0; i < ocena.size(); i++)
		o << ocena.getOcena(i) << " ";
	o << endl;
	return o;
};