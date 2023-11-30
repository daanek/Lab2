#include"Signr.h"
istream& operator >>(istream& os, Sign& el)
{
	string buf;


	cout << "input name" << endl;
	getline(os, buf);
	el.name = buf;

	cout << "input surname" << endl;
	getline(os, buf);
	el.surname = buf;


	cout << "input znak" << endl;
	getline(os, buf);

	el.znak = buf;

	cout << "input date (format 20.13.2000)" << endl;
	getline(os, buf);
	el.razdel(buf);

	return os;
}