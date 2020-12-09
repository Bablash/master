#pragma once
#include "Degree.h"

using namespace std;

class String : public Degree {
public:

	char* toString(); //transformation of polinomial in string view
	String(int n1) : Degree(n1) {}
	String(const String& other) : Degree(other) {}

private:
	char* ch;
};
