#include <iostream>
#include "Polinomial.h"
#include <string>
#include <stdio.h>

using namespace std;

void Polinomial::setN(int n1) {
	n = n1;
}

int Polinomial::getValue(){
	return value;
}
int Polinomial::getN() {
	return n;
}

int Polinomial::getX() {
	return x;
}

void Polinomial::setX(int x1) {
	x = x1;
}

int* Polinomial::getCoeff() {
	return coeff;
}

int Polinomial::pow(int x, int n) {
	int poww = 1;
	for (int i = n; i > 0; i--)
		poww *= x;
	return poww;
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
	char* str = new char[255]{""};
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
		coeff[i] = rand() % 201-100;
	}
	count++;
}

Polinomial::Polinomial() {
	coeff = NULL;
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

int Polinomial::getCount() { 
	return count; 
}

Polinomial::~Polinomial() {
	delete[] coeff;
	count--;
}