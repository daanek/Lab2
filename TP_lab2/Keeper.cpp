#include"Keeper.h"

	keeper::keeper()
	{
		n = 2;
		array = new Sign[n];
	}

	keeper::keeper(const keeper& other)
	{
		this->n = other.n;
		this->array = new Sign[n];

		for (int i = 0; i < n; i++)
		{
			array[i] = other.array[i];
		}
	}
	void keeper::showAll()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " ";
			cout << array[i];
			cout << "____________________" << endl;
		}
	}
	keeper keeper:: operator ++(int val)
	{
		keeper buf(*this);
		delete[] array;
		n++;
		array = new Sign[n];

		for (int i = 0; i < n - 1; i++)
		{
			array[i] = buf.array[i];
		}
		cin >> array[n - 1];
		delete[] buf.array;
		return *this;
	}//proverka

	keeper  keeper::operator - (int val)
	{

		keeper buf(*this);
		try
		{
			if (n == 0)
				throw 3;
			if (val > n)
				throw 5;
			n--;
			delete[] array;
			array = new Sign[n];
			int j = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == val - 1) { j++; }
				array[i] = buf.array[j];

				j++;
			}
			return *this;
		}
		catch (int val)
		{
			if (val == 3)
			{
				cout << "В списке нет элементов " << endl;
				system("pause");
			}
			else if (val == 5)
			{
				cout << "Выбранный элемент не соответсвует списку " << endl;
				system("pause");
			}
		}
	}
	void keeper::outputZnak()
	{
		string buf = "";
		keeper one(*this);
		int i = 0;
		string bufZnak;
		for (int i = 0; i < n; i++)
		{
			bufZnak = one.array[i].getZnak();
			if (buf.find(bufZnak))
			{

				buf.append(bufZnak);
				buf.append(" ");

				for (int j = 0; j < n; j++)
				{
					if ((one.array[j].getZnak() == bufZnak))
					{
						one.array[j].show();
					}
				}
			}

		}
	}

	void keeper::mecych()
	{
		string buf;
		int month;
		int a = 0;
		cout << "input number month";
		getline(cin, buf);
		month = stoi(buf);
		for (int i = 0; i < n; i++)
		{
			if (array[i].getMonth() == month)
			{
				array[i].show();
				a++;
			}
		}
		if (a == 0)
		{
			cout << "nothigth informashion" << endl;
		}

	}
	void keeper::redak()
	{
		showAll();
		int bufel, bufwhat;
		string bufstr;
		cout << "what element redak" << endl;
		getline(cin, bufstr);
		bufel = stoi(bufstr);
		bufel--;
		cout << "what box redak" << endl;
		cout << " 1 - name" << endl;
		cout << "2 - zodiac" << endl;
		cout << "3 - data" << endl;
		getline(cin, bufstr);
		bufwhat = stoi(bufstr);

		switch (bufwhat)
		{
		case 1:
		{
			array[bufel].inic(1);
			break;
		}

		case 2:
		{
			array[bufel].inic(2);
			break;
		}

		case 3:
		{
			array[bufel].inic(3);
			break;
		}
		}


};