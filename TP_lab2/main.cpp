#include"Signr.h"
#include"Keeper.h"
using namespace std;




int main()
{
	keeper one;
	setlocale(LC_ALL, "");

	int z;
	string buf;
	char mennu[8][40];

	strcpy(mennu[0], "Option: \n");
	strcpy(mennu[1], "1) �������� �������  \n");
	strcpy(mennu[2], "2) ������� �������   \n");
	strcpy(mennu[3], "3) �������� \n");
	strcpy(mennu[4], "4) ����� �� ������  \n");
	strcpy(mennu[5], "5) ���������� �� ����� �������\n");
	strcpy(mennu[6], "6) �������������� \n");
	strcpy(mennu[7], "0) ����� \n");
	HANDLE hStdout;
	WORD foregroundColor;
	WORD foregroundColor1;
	WORD backgroundColor;
	foregroundColor = FOREGROUND_INTENSITY |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE;
	foregroundColor1 = FOREGROUND_INTENSITY |
		FOREGROUND_BLUE |
		FOREGROUND_GREEN |
		FOREGROUND_RED;
	backgroundColor = 0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int flag = 1;
	char s = 0;
	int bb;
	while (1)
	{
		flag = 1;
		s = 0;
		while (s != 13)
		{
			system("cls");
			if (s == -32) { s = _getch(); }
			if (s == 72)
			{
				if (flag == 1)
					flag = 7;
				else
					flag--;
			}
			if (s == 80)
			{
				if (flag == 7)
				{
					flag = 1;
				}
				else
					flag++;
			}
			for (int i = 0; i < 8; i++)
			{
				if (i == flag)
				{
					printf(" ");
					SetConsoleTextAttribute(hStdout, foregroundColor | backgroundColor);
					printf(" %s", mennu[i]);

					SetConsoleTextAttribute(hStdout, foregroundColor1);
				}
				else
					printf("%s", mennu[i]);
			}
			s = _getch();
		}
		switch (flag) {
		case 1:
		{
			one++;
			break;
		}
		case 2:
		{
			one.showAll();
			cout << "����� ������� �������?" << endl;
			getline(cin, buf);
			bb=stoi(buf);
			one - bb;
			break;
		}
		case 3:
		{
			one.showAll();
			system("pause");
			break;
		}
		case 4:
		{
			one.mecych();
			system("pause");
			break;
		}
		case 5:
		{
			one.outputZnak();
			system("pause");
			break;
		}
		case 6:
		{
			one.redak();
			break;
		}
		case 7: {return 0; break; }
		}
	}
}



