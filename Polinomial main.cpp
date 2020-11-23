#include <iostream>
#include "Polinomial.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

bool test_original_file(Polinomial& A) {

	const int expected[4] = {-59, 76, 3, 69};

	try {

		if (A.getCoeff() == NULL) { throw "Test hasn't been complited "; }
		else {

			fstream fs;

			fs.open("txt.txt", fstream::in | fstream::out | fstream::app);

			if (!fs.is_open()) {

				cout << "Error of open" << endl;
			}
			else {

				cout << "File is open" << endl;

				fs << A;
			}
			fs.close();


			fs.open("txt.txt", fstream::in | fstream::out | fstream::app);

			if (!fs.is_open()) {

				cout << "Error of open" << endl;
			}
			else {

				cout << "file is open" << endl;

				int len = A.getN() - 3;

				fs.seekg(-len, ios::end);
				fs >> A;
				cout << A << endl;
			}
			fs.close();

			if (*A.getCoeff() == *expected) {

				return true;
			}
			else {

				return false;
			}
		}
	}
	catch (ArrayException& exception) {

		std::cerr << "Error" << exception.getError() << std::endl << std::endl;
		return 0;
	}
}


bool test_binary_file(Polinomial& A, fstream& filename) {

	const int expected[4] = { -59, 76, 3, 69 };

	try {

		if (A.getCoeff() == nullptr && !A.getCoeff()) { throw "Test hasn't been complited "; }
		else {

			if (*A.getCoeff() == *expected && A.read_binary(filename) && A.write_binary(filename)) 
				return true;
			else 
				return false;

		}
		
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << std::endl << "_______________" << std::endl;
		return 0;
	}
}

int main() {
	Polinomial first(3);
	Polinomial second(5);
	cout << "The first polinomial: " << first << endl;
	cout << "The second polinomial: " << second << endl << endl;
	cout << std::boolalpha;
	cout << "Test 1 is " << test_original_file(first) << endl << endl;

	fstream namefile("dat.dat", fstream::in | fstream::out | fstream::app | fstream::binary);
	cout << "Test 2 is " << test_binary_file(first, namefile) << endl << endl;
	return 0;

}
