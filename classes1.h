#pragma once

class Polinomial {
public:
	void setn(int n1);
	int getn();
	int* getcoeff();
	int getx();
	int getcount();

	Polinomial(int n); //create of array

	Polinomial(const Polinomial& other); //constructor of copy
	
	int calc(int n, int* coeff, int x, static int count); //The value of a polynomial of degree n of x with the coefficients

	char* toString(int n, int coeff[]); //transformation of polinomial in string view

	int pow(int x, int n); //exponentiation

	~Polinomial(); //destructor

private:
	int n;
	int* coeff;
	int x;
	static int count;
};