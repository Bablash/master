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
	Polinomial newfirst = first--;
	int expected = -33686019; //garbage
	if (*newfirst.getCoeff() == expected)
		return true;
	else return false;
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

	Polinomial newfirst = copy1++;
	cout << "The increasing of the degree of the first polinomial: " << newfirst.toString() << endl << endl;

	Polinomial newsecond = copy2--;
	cout << "The lowering of the degree of the second polinomial: " << newsecond.toString() << endl << endl;

	Polinomial value;
	cout << "Result of calculating the first polynomial from x=3: " << value(first) << endl << endl;
	

	cout << "The value of the first element of first coefficients's array: "<< first[1] << endl << endl;;
	
	first = second;

	cout << "The value of the first polinomial after first = second: " << first.toString() << endl << endl;;

	cout << boolalpha << "Test 1 is " << test1() << endl << endl;
	cout << boolalpha << "Test 2 is " << test2() << endl << endl;

	return 0;

}
