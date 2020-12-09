#include <iostream>
#include "Polinomial.h"
#include "Degree.h"
#include "toString.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

bool test_original_file(Degree& A, Degree& B) {

	try {
		Degree newobj[2];
		if (A.getCoeff() == NULL)
			throw "Test hasn't been complited ";
		else {

			ofstream fs;

			fs.open("txt.txt", fstream::out | fstream::app);

			if (!fs.is_open())
				cout << "Error of open" << endl;

			else {
				cout << "File is open" << endl;
				fs << A;
				fs << B;
			}

			fs.close();


			ifstream fs1;
			fs1.open("txt.txt", fstream::in | fstream::app);
			if (!fs1.is_open())
			{
				cout << "Error of open" << endl;
				return false;
			}

			else {
				cout << "file is open" << endl;
				for (int i = 0; i < 2; i++)
					fs1 >> newobj[i];
				return true;
			}
			fs1.close();
		}
	}
	catch (ArrayException& exception) {

		cerr << "Error" << exception.getError() << endl << endl;
		return 0;
	}
}


bool test_binary_file(Degree& A, ifstream& filename1, ofstream& filename2) {

	int* expected = A.getCoeff();

	try {

		if (A.getCoeff() == NULL)
			throw "Test hasn't been complited ";
		else {
			A.write(filename2);
			A.read(filename1);
			if (A.getCoeff() == expected)
				return true;
			else
				return false;
		}
	}
	catch (ArrayException& exception) {

		cerr << "Error: " << exception.getError() << endl << endl;
		return 0;
	}
}

int main() {
	Degree first(3);
	Degree second(6);
	cout << "The first polinomial " << first << endl;
	cout << "The second polinomial " << second << endl;

	String third(5);
	cout << third.toString() << endl << endl;


	cout << std::boolalpha;
	cout << "Test 1 is " << test_original_file(first, second) << endl << endl;

	ifstream namefile1("dat.dat", fstream::in | fstream::app | fstream::binary);
	ofstream namefile2("dat.dat", fstream::out | fstream::app | fstream::binary);

	cout << "Test 2 is " << test_binary_file(first, namefile1, namefile2) << endl << endl;

	return 0;

}