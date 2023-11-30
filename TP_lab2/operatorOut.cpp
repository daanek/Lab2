#include"Signr.h"
ostream& operator <<(ostream& os, const Sign& el)
{
	os << el.name << ' ' << el.surname << endl;
	os << el.znak << endl;
	for (int i = 0; i < 3; i++)
	{
		os << el.dat[i] << ' ';
	}
	os << endl;
	return os;
}