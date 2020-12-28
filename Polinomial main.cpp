#include <iostream>
#include "Polinomial.h"
#include "Degree.h"
#include "toString.h"
#include "List.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

void testInsert() {
	List D;

	Polinomial one(3);
	Degree two(5);
	String three(4);

	Polinomial* f = &one;
	if (D.Insert(1, one)) {
		f = &two;
		if (D.Insert(2, *f)) {
			f = &three;
			if (D.Insert(3, *f)) {
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

	Polinomial &f = one;
	if (D.Insert(1, f)) {
		f = two;
		if (D.Insert(2, f)) {
			f = three;
			if (D.Insert(3, f)) {
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
	D.Insert(1, one);

	f = &two;
	D.Insert(2, *f);

	f = &three;
	D.Insert(3, *f);

	D.ClearList();
	if (D.getCount1() == 0)
		cout << "Deleting all is successful" << endl;
	else cout << "Deleting all is failed" << endl;

}

int main() {

	List L1;
	testInsert();
	testPrint(); //Virtual!!
	testDelete();
	return 0;

}