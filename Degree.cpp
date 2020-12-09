#include <iostream>
#include "Degree.h"
using namespace std;

int* Degree::getDegree()
{
	return degree;
}

ostream& operator<<(ostream& out, const Degree& other)
{
	out << "degree n = " << other.n << endl;
	for (int i = 0; i <= other.n; i++)
		out << other.degree[i] << " ";
	out << endl;
	out << "coeff ";
	for (int i = 0; i <= other.n; i++)
		out << other.coeff[i] << " ";
	out << endl;
	return out;
}

istream& operator>>(istream& is, Degree& other)
{
	is.seekg(11, ios::cur);
	is >> other.n;

	other.degree = new int[other.n + 1];
	for (int i = 0; i <= other.n; i++)
		is >> other.degree[i];

	other.coeff = new int[other.n + 1];
	is.seekg(8, ios::cur);
	for (int i = 0; i <= other.n; i++)
		is >> other.coeff[i];
	is.seekg(2, ios::cur);
	return is;
}


Degree& Degree::operator=(const Degree& other)
{
	delete[] coeff; //delete this coeff to fill with other elements
	delete[] degree;
	n = other.n;
	x = other.x;
	coeff = new int[other.n + 1];
	for (int i = 0; i <= other.n; i++) {
		coeff[i] = other.coeff[i];
		degree[i] = other.degree[i];
	}
	return *this;
}

void Degree::write(ofstream& filename)
{
	try {

		if (coeff == nullptr || degree == nullptr)
			throw ArrayException("Write in binary hasn't been complited ");

		if (!filename.is_open())
			cout << "error of open" << endl;

		else {

			cout << "file is open" << endl;

			filename.write((char*)& n, sizeof(n));

			for (int i = 0; i <= n; i++)
				filename.write((char*) & (coeff[i]), sizeof(coeff[i]));
			
			filename.write((char*)& x, sizeof(x));

			filename.write((char*)& value, sizeof(value));

			for (int i = 0; i <= n; i++)
				filename.write((char*) & (degree[i]), sizeof(degree[i]));
		}
		filename.close();
	}

	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << std::endl << "_______________" << std::endl;
	}
}

void Degree::read(ifstream& filename)
{
	try {

		if (coeff == nullptr)
			throw ArrayException("Read from binary hasn't been complited ");

		if (!filename.is_open())
			cout << "error of open" << endl;

		else {
			Degree A;
			cout << "file is open" << endl;
			filename.read((char*)& A.n, sizeof(A.n));

			int len = A.n + 1;
			int* newdegree = new int[len];
			
			int* newcoeff = new int[len];
			for (int i = 0; i <= n; i++)
				filename.read((char*)& newcoeff[i], sizeof(newcoeff[i]));
			A.coeff = newcoeff;

			filename.read((char*)& A.x, sizeof(A.x));

			filename.read((char*)& A.value, sizeof(A.value));

			for (int i = 0; i <= n; i++)
				filename.read((char*)& newdegree[i], sizeof(newdegree[i]));
			A.degree = newdegree;

			cout << A << endl;
		}
		filename.close();

	}

	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << std::endl << "_______________" << std::endl;
	}
}
