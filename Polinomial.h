#pragma once
#include <fstream>

using namespace std;
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

	friend Polinomial operator +(const Polinomial& thiss, const Polinomial& other);
	Polinomial operator -(const Polinomial& other);
	Polinomial operator ++(int degree);
	Polinomial operator --(int degree);
	int& operator [](int index);
	Polinomial& operator = (const Polinomial& other);
	int operator ()();

	friend ostream& operator<< (ostream& out, const Polinomial& coeff);

	friend istream& operator>> (istream& is, Polinomial& coeff);

	void write(ofstream& filename);

	void read(ifstream& filename);

	~Polinomial(); //destructor

protected:
	int n;
	int* coeff;
	int x;
	static int count;
	int value;
};

class ArrayException
{
public:
	ArrayException(const char* error);
	const char* getError();

private:
	const char* m_error;
};

Polinomial operator +(const Polinomial& thiss, const Polinomial& other);


