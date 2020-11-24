#include <iostream>
#include "Polinomial.h"
#include <fstream>

using namespace std;
int Polinomial::count = 0;

bool test_original_file(Polinomial& A, Polinomial& B) {

	try {

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
			}

			fs.close();


			ifstream fs1;
			fs1.open("txt.txt", fstream::in | fstream::app);
			if (!fs1.is_open()) 
				cout << "Error of open" << endl;
		
			else {
				cout << "file is open" << endl;

				int len = A.getN();

				fs1.seekg(-len*4, ios::end);
				fs1 >> B;
				cout << B << endl;
			}
			fs1.close();
			
			if (*A.getCoeff() == *B.getCoeff()) //если записывваемый и полученный массивы равны
				return true;
			else 
				return false;
		}
	}
	catch (ArrayException& exception) {

		cerr << "Error" << exception.getError() << endl << endl;
		return 0;
	}
}


bool test_binary_file(Polinomial& A, ifstream& filename1, ofstream& filename2) {

	const int expected[4] = { -59, 76, 3, 69 };

	try {

		if (A.getCoeff() == nullptr) 
			throw "Test hasn't been complited "; 
		else {

			if (A.write(filename2) && A.read(filename1))
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
	Polinomial first(3);
	Polinomial first2(3);
	Polinomial second(5);
	cout << "The first polinomial: " << first << endl;
	cout << "The second polinomial: " << second << endl << endl;

	cout << std::boolalpha;
	cout << "Test 1 is " << test_original_file(first,first2) << endl << endl;

	ifstream namefile1("dat.dat", fstream::in | fstream::app | fstream::binary);
	ofstream namefile2("dat.dat", fstream::out | fstream::app | fstream::binary);

	cout << "Test 2 is " << test_binary_file(first, namefile1, namefile2) << endl << endl;
	return 0;

}
