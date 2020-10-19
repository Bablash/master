#pragma once

class Polinomial {
public:
	void setN(int n1);
	void setX(int x1);
	int getN();
	int getValue();
	int* getCoeff();
	int getX();
	int getCount();

	Polinomial();

	Polinomial(int n); //create of array

	Polinomial(const Polinomial& other); //constructor of copy
	
	int calc(); //The value of a polynomial of degree n of x with the coefficients

	char* toString(); //transformation of polinomial in string view

	int pow(int x, int n); //exponentiation

	~Polinomial(); //destructor

private:
	int n;
	int* coeff;
	int x;
	static int count;
	int value;
};