#include <iostream>
#include "classes1.h"
#include <string>

using namespace std;

void Polinomial::setn(int n1) {
	n = n1;
}

int Polinomial::getn() {
	return n;
}

int* Polinomial::getcoeff() {
	return coeff;
}

int Polinomial::pow(int x, int n) {
	int poww = 1;
	for (int i = n; i > 0; i--)
		poww *= x;
	return poww;
}

int Polinomial::calc(int n, int *coeff, int x) {
	int value = 0;
	for (int i = 0, k = n; i <= n && k >= 0; k--, i++) {
		value += coeff[i] * pow(x, k);
	}
	return value;
}

char* Polinomial::toString(int n, int coeff[]) {

	char* str = new char[n * 7 + 3];
	for (int i = 0, k = n, j = 0; k >= 0; i = i + 6, k--, j++) {
		if (coeff[j] < 0) {
			str[i] = '-';
			str[i + 1] = abs(coeff[j]) + '0';
			str[i + 2] = '*';
			str[i + 3] = 'x';
			str[i + 4] = '^';
			str[i + 5] = k + '0';
		}
		else {
			str[i] = '+';
			str[i + 1] = abs(coeff[j]) + '0';
			str[i + 2] = '*';
			str[i + 3] = 'x';
			str[i + 4] = '^';
			str[i + 5] = k + '0';
		}
	}
	str[n * 7 + 1] = '=';
	str[n * 7 + 2] = '0';
	str[n * 7 + 3] = '\0';
	return str;
}

Polinomial::Polinomial(int n) {
	coeff = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		coeff[i] = rand() % 11 - 10;
	}
}

Polinomial::Polinomial(const Polinomial& other) {
	coeff = new int[other.n + 1];
	for (int i = 0; i <= other.n; i++) {
		coeff[i] = other.coeff[i];
	}
}

Polinomial::~Polinomial() {
	delete[] coeff;
}