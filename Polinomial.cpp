#include <iostream>
#include "Polinomial.h"

using namespace std;
int Polinomial::count = 0;

bool test1() {
	Polinomial first(-1);
	Polinomial second(5);
	Polinomial sum = first + second;
	int expected = *second.getCoeff(); //the first array does not exist, and the sum is equal to the second array
	if (*sum.getCoeff() == expected)
		return true;
	else return false;
}

bool test2() {
	Polinomial first(0);
	try {
		first--;
		cout << first.toString() << endl << endl;

	}
	catch (ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")" << endl;
	}
	return true;
}

int main() {
	Polinomial first(3);
	Polinomial second(5);
	Polinomial copy1(first);
	Polinomial copy2(second);
	cout << "The first polinomial: " << first.toString() << endl;
	cout << "The second polinomial: " << second.toString() << endl;

	Polinomial sum = first + second;
	cout << endl << "The sum of polynomials: " << sum.toString() << endl;
	Polinomial difference = first - second;
	cout << endl << "The difference of polynomials: " << difference.toString() << endl << endl;

	copy1++;
	cout << "The increasing of the degree of the first polinomial: " << copy1.toString() << endl << endl;
	
	cout << "The lowering of the degree of the second polinomial: ";
	try {
		copy2--;
		cout << copy2.toString() << endl << endl;

	}
	catch (ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")" << endl << endl;
	}

	first.setX(3);
	cout << "Result of calculating the first polynomial from x=3: " << first() << endl << endl;

	cout << "The value of the -1 element of first coefficients's array: ";
	try {
		cout << first[-1] << endl << endl;
	}
	catch(ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")" << endl << endl;
	}
	
	first = second;

	cout << "The value of the first polinomial after first = second: " << first.toString() << endl << endl;;

	cout << boolalpha << "Test 1 is " << test1() << endl << endl;
	cout << boolalpha << "Test 2 is " << test2() << endl << endl;

	return 0;

}
