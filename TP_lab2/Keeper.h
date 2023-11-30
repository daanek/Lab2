#pragma once
#include"Signr.h"
class keeper {

	Sign* array;
	int n;
public:
	keeper();
	
	keeper(const keeper& other);
	void showAll();
	keeper operator ++(int val);

	keeper operator - (int val);
	void outputZnak();
	void mecych();
	void redak();
	
};