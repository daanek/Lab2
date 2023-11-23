#include<iostream>
#include<string>
using namespace std;

//menu + proverki
//git one commit
class Sign
{
	string name;
	string surname;
	string znak;
	int dat[3];
public:
	Sign()
	{
		name = "Dany";
		surname = "Skakun";
		znak = "bliznec";
		copyDat(13, 6, 2003);

	}
	Sign operator = (const Sign & other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->znak = other.znak;
		for (int i = 0; i < 3;i++)
		{
			dat[i] = other.dat[i];
		}
		
		return*this;
	}
	string getZnak()
	{
		return znak;
	}
	int getMonth()
	{
		return dat[1];
	}

	void copyDat(int a,int b,int  c)
	{
		dat[0] = a;
		dat[1] = b;
		dat[2] = c;
	}
	void razdel(string data)
	{
		string buf ="";
		int j = 0;
		for (int i = 0; i < data.size(); i++)
		{
			buf.append(string(1,data[i]));
			if (data[i] == '.')
			{
				dat[j]=stoi(buf);
				j++;
				buf = "";
			}
		}
		dat[j] = stoi(buf);
	}
	void inic()
	{
		string buf;
		cout << "input name" << endl;
		getline(cin, buf);
		name = buf;

		cout << "input surname" << endl;
		getline(cin, buf);
		surname = buf;

		cout << "input znak" << endl;
		getline(cin, buf);

		znak = buf;

		cout << "input date (format 20.13.2000)" << endl;
		getline(cin, buf);
		razdel(buf);


	}
	void show()
	{
		cout << name << ' ' << surname << endl;
		cout << znak << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << dat[i] << ' ';
		}
		cout <<endl;
	}


};

class keeper {

	Sign* array;
	int n;
public:
	keeper()
	{
		n = 2;
		array = new Sign[n];
	}

	keeper(const keeper& other)
	{
		this->n = other.n;
		this->array = new Sign[n];

		for (int i = 0; i < n; i++)
		{
			array[i] = other.array[i];
		}
	}
	void showAll()
	{
		for (int i = 0; i < n; i++)
		{
			array[i].show();
		}
	}
	keeper operator ++(int val)
	{
		keeper buf(*this);
		delete[] array;
		n++;
		array = new Sign[n];

		for (int i = 0; i < n - 1; i++)
		{
			array[i] = buf.array[i];
		}
		array[n - 1].inic();
		delete[] buf.array;
		return *this;
	}//proverka

	keeper operator - (int val)
	{
		
		keeper buf(*this);

		n--;
		delete[] array;
		array = new Sign[n];
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == val-1){j++;}
			array[i] = buf.array[j];
		
			j++;
		}
		return *this;
	}
	void outputZnak()
	{
		string buf="";
		keeper one(*this);
		int i = 0;
		string bufZnak;
		for(int i =0;i<n;i++)
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

	void mecych()
	{
		string buf;
		int month;
		int a=0;
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
};
int main()
{
	keeper one;


	one.showAll();
	one++;
	one++;
	one++;
	one++;

	cout << endl;

	cout <<"HH"<< endl;
	one.outputZnak();
	cout <<"HH"<< endl;
	one.showAll();
}