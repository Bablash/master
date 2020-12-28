#pragma once

#include "Polinomial.h"

using namespace std;

class Degree : public Polinomial { //наследник класса Polinomial, в котором хранятся степени при коэффициентах многочлена в массиве;
public:
	int* getDegree();
	Degree(int n1) : Polinomial(n1) {
		n = n1;
		coeff = new int[n1 + 1];
		degree = new int[n1 + 1];
		for (int i = 0; i <= n1; i++) {
			coeff[i] = rand() % 201 - 100;
			degree[i] = n1 - i; //new
		}
		count++;
	}

	Degree(const Degree& other) : Polinomial(other) {
		n = other.n;
		x = other.x;
		coeff = new int[other.n + 1];
		for (int i = 0; i <= other.n; i++) {
			coeff[i] = other.coeff[i];
			degree[i] = other.degree[i]; //new
		}
		count++;
	}

	Degree() : Polinomial() {
		coeff = NULL;
		degree = NULL;
	}
	Degree& operator = (const Degree& other);

	friend ostream& operator<< (ostream& out, const Degree& coeff);

	friend istream& operator>> (istream& is, Degree& coeff);

	void write(ofstream& filename);

	void read(ifstream& filename);

	char* toString() override;

	~Degree();

protected:
	int* degree;
};
