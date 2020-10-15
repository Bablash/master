#pragma once

class Polinomial {
public:
	void setn(int n1);
	void setx(int x1);
	int getn();
	int getvalue();
	int* getcoeff();
	int getx();
	int getcount();

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