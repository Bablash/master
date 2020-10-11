#include <iostream>
#include "classes1.h"

using namespace std;
int Polinomial::count = 0;

bool test1(int x) { //test for the degree = 0
	Polinomial test(0);
	int expected = *test.getcoeff(); //since the degree of the polynomial is 0, it will only have a coefficient multiplied by x^0 and it's equal to 1 -> we get a coefficient*1
	cout << endl << endl << "Test 1";
	cout << endl << "The expected result for degree n = 0 is ----------> " << expected;
	cout << endl << "The result of the programm for degree n = 0 is ---> " << test.calc(0, test.getcoeff(), x, test.getcount());
	for (int n = 0; ; )
		if (test.calc(n, test.getcoeff(), x, test.getcount()) == expected) 
			return true;
		else 
			return false;
}

bool test2(int x) { //test for the degree = - 1
	Polinomial test(-1);
	int expected = 0;
	cout << endl << endl << "Test 2";
	cout << endl << "The expected result for degree n = - 1 is --------> " << expected;
	cout << endl << "The result of the programm for degree n = -1 is ---> " << test.calc(-1, test.getcoeff(), x, test.getcount());
	for (int n = - 1; ; )
		if (test.calc(n, test.getcoeff(), x, test.getcount()) == expected) //if the degree of the polynomial is negative, the program will not enter the array of its filling and the polynomial will take the value set initially, i.e. 0
			return true;
		else
			return false;
}

bool test3(int x) { ////test for the degree = 4
	Polinomial test(4);
	int expected = -345;
	cout << endl << endl << "Test 3";
	cout << endl << "The expected result for degree n = 4 is ----------> " << expected;
	cout << endl << "The result of the programm for degree n = 4 is ---> " << test.calc(4, test.getcoeff(), x, test.getcount());
	for (int n = 4; ; )
		if (test.calc(n, test.getcoeff(), x, test.getcount()) == expected)
			return true;
		else
			return false;
}

int main() {
	Polinomial first (5);
	first.setn(5);
	int n = first.getn();
	int x = first.getx();
	Polinomial copy(first);
	cout << first.toString(n, copy.getcoeff());
	cout << endl << "The value of a polynomial of degree 5 of x = 3:  " << first.calc(n, copy.getcoeff(), x, first.getcount());

	if (test1(x))
		cout << endl << "Test 1 is true";
	else cout << "Test 1 is false";

	if (test2(x))
		cout << endl << "Test 2 is true";
	else cout << "Test 2 is false";

	if (test3(x))
		cout << endl << "Test 3 is true";
	else cout << endl << "Test 3 is false";

	return 0;
}
