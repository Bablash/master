#include <iostream>
#include "Polinomial.h"
#include <string>
#include <stdio.h>
#include <exception>

using namespace std;

void Polinomial::setN(int n1) {
	n = n1;
}

void Polinomial::setX(int x1) {
	x = x1;
}

int Polinomial::getValue() {
	return value;
}

int Polinomial::getN() {
	return n;
}

int Polinomial::getX() {
	return x;
}

int* Polinomial::getCoeff() {
	return coeff;
}

int Polinomial::getCount() {
	return count;
}

Polinomial::Polinomial() {
	coeff = NULL;
}

int Polinomial::pow(int x, int n) {
	int poww = 1;
	for (int i = n; i > 0; i--)
		poww *= x;
	return poww;
}

Polinomial operator+(const Polinomial& thiss, const Polinomial& other)
{
	Polinomial sum;
	if (thiss.n > other.n) {  //if the arrays are of different lengths, the length of the resulting array is equal to the length of the larger array. 
		sum.n = thiss.n;		//Its first elements are written to the final array without changes until the counter shifts by their difference
		sum.coeff = new int[thiss.n + 1];
		for (int i = 0; i < thiss.n - other.n; i++) {
			sum.coeff[i] = thiss.coeff[i];
			for (int k = 0, i = thiss.n - other.n; i <= thiss.n; i++, k++)
				sum.coeff[i] = thiss.coeff[i] + other.coeff[k];
		}
	}
	else {
		sum.n = other.n;
		sum.coeff = new int[other.n + 1];
		for (int i = 0; i < other.n - thiss.n; i++) {
			sum.coeff[i] = other.coeff[i];
			for (int k = 0, i = other.n - thiss.n; i <= other.n; i++, k++)
				sum.coeff[i] = thiss.coeff[k] + other.coeff[i];
		}
	}
	return sum;
}

Polinomial Polinomial::operator-(const Polinomial& other)
{
	Polinomial diff;
	if (n > other.n) {
		diff.n = n;
		diff.coeff = new int[n + 1];
		for (int i = 0; i < n - other.n; i++) {
			diff.coeff[i] = coeff[i];
			for (int k = 0, i = n - other.n; i <= n; i++, k++)
				diff.coeff[i] = coeff[i] - other.coeff[k];
		}
	}
	else {
		diff.n = other.n;
		diff.coeff = new int[other.n + 1];
		for (int i = 0; i < other.n - n; i++) {
			diff.coeff[i] = other.coeff[i];
			for (int k = 0, i = other.n - n; i <= other.n; i++, k++)
				diff.coeff[i] = coeff[k] - other.coeff[i];
		}
	}
	return diff;
}

int* Polinomial::operator++(int degree)
{
	n++;
	int* newcoeff = new int[n + 1];
	newcoeff[0] = rand() % 201 - 100;	//add the new element for new degree
	for (int i = 1; i <= n; i++)
		newcoeff[i] = coeff[i - 1];		//shifting the original array one to the right
	coeff = newcoeff;
	return coeff;
}

int* Polinomial::operator--(int degree)
{
	try {
		if (n <= 0) {
			throw n;
			//return;
		}
		n--;
		int* newcoeff = new int[n + 1];
		for (int i = 0; i <= n + 1; i++)
			newcoeff[i] = coeff[i + 1]; //shifting the original array one to the left
		coeff = newcoeff;
	}
	catch (int n) {
		cerr << "Caught an int exception with value: " << n << endl;
	}
	return coeff;
}

int& Polinomial::operator[](int index) {
	
	if (index > n or index < 0)
	throw ArrayException("Invalid index");
	return coeff[index];
}


//int& Polinomial::operator[](int index)
//{
//	try {
//		if (index > n or index < 0)
//			throw index;
//		return coeff[index];
//	}
//	catch(int index){
//		cerr << "Array Index out of Bounds: ";
//		return index;
//	}
//}

int* Polinomial::operator=(const Polinomial& other)
{
	delete[] coeff; //delete this coeff to fill with other elements
	n = other.n;
	x = other.x;
	coeff = new int[other.n + 1];
	for (int i = 0; i <= other.n; i++) {
		coeff[i] = other.coeff[i];
	}
	return coeff;
}

int Polinomial::operator()()
{
	value = calc();
	return value;
} 

int Polinomial::calc() {
	int value1 = 0;
	for (int i = 0, k = n; i <= n && k >= 0; k--, i++) {
		value1 += coeff[i] * pow(x, k);
	}
	value = value1;
	return value1;
}

char* Polinomial::toString() {
	char* str = new char[255]{ "" };
	char* buff = new char[20];
	for (int i = 0; i <= n; i++)
	{
		if (coeff[i] < 0 or i == 0)
			sprintf_s(buff, 20, "%d*x^%d", coeff[i], n - i);
		else
			sprintf_s(buff, 20, "+%d*x^%d", coeff[i], n - i);
		strcat_s(str, 255, buff);
	}
	char* ch = str;
	return ch;
}

Polinomial::Polinomial(int n1) {
	n = n1;
	coeff = new int[n1 + 1];
	for (int i = 0; i <= n1; i++) {
		coeff[i] = rand() % 201 - 100;
	}
	count++;
}

Polinomial::Polinomial(const Polinomial& other) {
	n = other.n;
	x = other.x;
	coeff = new int[other.n + 1];
	for (int i = 0; i <= other.n; i++) {
		coeff[i] = other.coeff[i];
	}
	count++;
}

Polinomial::~Polinomial() {
	delete[] coeff;
	count--;
}

ArrayException::ArrayException(const char* error)
	{
		m_error = error;
	}

const char* ArrayException::getError() { return m_error; }
