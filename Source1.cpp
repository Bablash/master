#include <iostream>
#include "classes1.h"

using namespace std;
int Polinomial::count = 0;

bool test1(int x) { //test for the degree = 0
	Polinomial test(0);
	test.setx(x);
	int expected = *test.getcoeff(); //since the degree of the polynomial is 0, it will only have a coefficient multiplied by x^0 and it's equal to 1 -> we get a coefficient*1
	cout << endl << endl << "Test 1";
	cout << endl << test.toString();
	cout << endl << "The expected result for degree n = 0 is ----------> " << expected;
	cout << endl << "The result of the programm for degree n = 0 is ---> " << test.calc();
	if (test.getvalue() == expected) 
		return true;
	else 
		return false;
}

bool test2(int x) { //test for the degree = - 1
	Polinomial test(-1);
	int expected = 0;
	cout << endl << endl << "Test 2";
	cout << endl << test.toString();
	cout << endl << "The expected result for degree n = - 1 is --------> " << expected;
	cout << endl << "The result of the programm for degree n = -1 is ---> " << test.calc();
	if (test.getvalue() == expected) //if the degree of the polynomial is negative, the program will not enter the array of its filling and the polynomial will take the value set initially, i.e. 0
		return true;
	else
		return false;
}

bool test3(int x) { ////test for the degree = 4
	Polinomial test(4);
	int expected = -95;
	cout << endl << endl << "Test 3";
	cout << endl << test.toString();
	cout << endl << "The expected result for degree n = 4 is ----------> " << expected;
	cout << endl << "The result of the programm for degree n = 4 is ---> " << test.calc();
	if (test.getvalue() == expected)
		return true;
	else
		return false;
}

int main() {
	Polinomial first (5);
	first.setx(3);
	Polinomial copy(first);
	Polinomial firstf;
	cout << copy.toString();
	cout << endl << "The value of a polynomial of degree 5 of x = 3:  " << first.calc();

	if (test1(3))
		cout << endl << "Test 1 is true";
	else cout << "Test 1 is false";

	if (test2(3))
		cout << endl << "Test 2 is true";
	else cout << "Test 2 is false";

	if (test3(3))
		cout << endl << "Test 3 is true";
	else cout << endl << "Test 3 is false";

	cout << endl << endl << "the count of objects" << first.getcount();

	return 0;
}