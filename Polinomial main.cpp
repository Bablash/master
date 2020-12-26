#include <iostream>
#include "Polinomial.h"
#include "Degree.h"
#include "toString.h"
#include "List.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

void testAdd() {
	List D;

	Polinomial one(3);
	Degree two(5);
	String three(4);

	Polinomial* f = &one;
	if (D.add(1, one)) {
		f = &two;
		if (D.add(2, *f)) {
			f = &three;
			if (D.add(3, *f)) {
				cout << "Adding of three different elements is successful" << endl;
			}
		}

	}
	else cout << "Adding of three different elements is failed" << endl;

}

void testPrint() {
	List D;

	Polinomial one(3);
	Degree two(5);
	String three(4);

	Polinomial* f = &one;
	if (D.add(1, one)) {
		f = &two;
		if (D.add(2, *f)) {
			f = &three;
			if (D.add(3, *f)) {
				D.printAll();
				cout << "Printing all is successful" << endl;
			}
		}
	}
	else cout << "Printing all is failed" << endl;

}

void testDelete() {
	List D;

	Polinomial one(3);
	Degree two(5);
	String three(4);

	Polinomial* f = &one;
	D.add(1, one);

	f = &two;
	D.add(2, *f);

	f = &three;
	D.add(3, *f);

	D.delAll();
	if (D.getCount1() == 0)
		cout << "Deleting all is successful" << endl;
	else cout << "Deleting all is failed" << endl;

}

void testVirtualFunc(Polinomial& other, Polinomial& A, Polinomial& B) {
	cout << "Class of " << other.getNameofclass() << endl;
	cout << "Class of " << A.getNameofclass() << endl;
	cout << "Class of " << B.getNameofclass() << endl;
}

int main() {

	List L1;
	testAdd();
	testPrint();
	testDelete();

	Polinomial A(4);
	Degree H(3);
	String L(6);

	testVirtualFunc(A, H, L);

	return 0;

}