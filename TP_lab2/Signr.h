#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<conio.h>
#include <Windows.h>
using namespace std;
class Sign
{
	string name;
	string surname;
	string znak;
	int dat[3];
public:
	Sign();
	
	Sign operator = (const Sign& other);
	

	string getZnak();

	int getMonth();
	

	void copyDat(int a, int b, int  c);
	
	void razdel(string data);
	
	void inic(int val = 0);
	
	void show();
	

	friend ostream& operator <<(ostream& os, const Sign& el);
	friend istream& operator >>(istream& os, Sign& el);
};