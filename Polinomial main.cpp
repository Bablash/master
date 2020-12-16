#include <iostream>
#include "Polinomial.h"
#include "Degree.h"
#include "toString.h"
#include "List.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

void testAdd(Polinomial other, List L) {
	try {
		L.add(1, other);
		if (L.getData(1) == other)
			cout << "Add Test is successful" << endl;
		else throw ArrayException("Add Test is failed");
	}
	
	catch (ArrayException& exception) {
		cout << "Error" << endl;
	}
}

void testDelete(Polinomial one, Polinomial two, List L) {
	try {
		L.add(1, one);
		L.add(2, two);
		L.del(1);
		if (L.getData(1) == two)
			cout << "Delete is successful" << endl;
		else throw ArrayException("Delete is failed");
	}
	catch (ArrayException& exception) {
		cout << "Error" << endl;
	}
		
}

void testDeleteAll(Polinomial one, Polinomial two, Polinomial three , List L) {
	try {
		L.add(1, one);
		L.add(2, two);
		L.add(3, three);
		L.delAll();
		if (L.empty() == 1) {
			cout << "Delete of all is successful" << endl;
		}
		else {
			throw ArrayException("Delete of all is failed");
		}
	}
	catch (ArrayException& exception) {
		cout << "Error" << endl;
	}
}

void test_virtual_func(Polinomial& other) {
	cout << "Class of " << other.getNameofclass() << endl;
}

int main() {
	
	Polinomial test(2);
	Degree first(3);
	Degree second(6);
	Degree third(7);

	test_virtual_func(first);

	List L1;
	testAdd(first,L1);
	testDelete(first, second, L1);
	testDeleteAll(first, second, third, L1);

	return 0;

}