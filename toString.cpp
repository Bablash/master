#include <iostream>
#include "toString.h"
using namespace std;

char* String::toString() {
	char* str = new char[255]{ "" };
	char* buff = new char[20];
	for (int i = 0; i <= n; i++)
	{
		if (coeff[i] < 0 or i == 0)
			sprintf_s(buff, 20, "%d*x^%d", coeff[i], degree[i]);
		else
			sprintf_s(buff, 20, "+%d*x^%d", coeff[i], degree[i]);
		strcat_s(str, 255, buff);
	}
	ch = str;
	return ch;
}

String::~String()
{
	delete[] ch;
}
