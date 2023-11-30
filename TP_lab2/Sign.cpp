#include"Signr.h"


	Sign::Sign()
	{
		name = "Dany";
		surname = "Skakun";
		znak = "bliznec";
		copyDat(13, 6, 2003);

	}
	Sign 	Sign::operator = (const Sign& other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->znak = other.znak;
		for (int i = 0; i < 3; i++)
		{
			dat[i] = other.dat[i];
		}

		return*this;
	}

	string Sign::getZnak()
	{
		return znak;
	}
	int	Sign::getMonth()
	{
		return dat[1];
	}

	void	Sign::copyDat(int a, int b, int  c)
	{
		dat[0] = a;
		dat[1] = b;
		dat[2] = c;
	}
	void	Sign::razdel(string data)
	{
		string buf = "";
		int j = 0;
		for (int i = 0; i < data.size(); i++)
		{
			buf.append(string(1, data[i]));
			if (data[i] == '.')
			{
				dat[j] = stoi(buf);
				j++;
				buf = "";
			}
		}
		dat[j] = stoi(buf);
	}
	void	Sign::inic(int val )
	{
		string buf;
		if (val == 0 || val == 1)
		{
			cout << "input name" << endl;
			getline(cin, buf);
			name = buf;

			cout << "input surname" << endl;
			getline(cin, buf);
			surname = buf;
		}
		if (val == 0 || val == 2)
		{
			cout << "input znak" << endl;
			getline(cin, buf);

			znak = buf;

		}
		if (val == 0 || val == 3)
		{
			cout << "input date (format 20.13.2000)" << endl;
			getline(cin, buf);
			razdel(buf);
		}


	}
	void	Sign::show()
	{
		cout << name << ' ' << surname << endl;
		cout << znak << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << dat[i] << ' ';
		}
		cout << endl;
	}
	