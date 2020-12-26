#include <iostream>
#include "Polinomial.h"
#include "List.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

void testInt() {
	List<int> L1;

	int* A = new int[4];
	for (int i = 1; i <= 4; i++) {
		A[i] = rand() % 201 - 100;
		L1.add(i, A[i]);
	}

	L1.printAll();
	L1.delAll();
}

void testFloat() {
	List<float> L1;

	float* A = new float[4];
	for (int i = 1; i <= 4; i++) {
		A[i] = i + 0.3;
		L1.add(i, A[i]);
	}

	L1.printAll();
	L1.delAll();
}

void testPolinomial() {
	List<Polinomial> L1;

	Polinomial a(4);
	Polinomial b(7);
	Polinomial c(2);

	L1.add(1, a);
	L1.add(2, b);
	L1.add(3, c);

	L1.printAll();
	L1.delAll();
}

int main() {

	testInt();
	testFloat();
	testPolinomial();

	return 0;
}