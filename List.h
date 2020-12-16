#pragma once
#include "Polinomial.h"

using namespace std;

struct Elem {
	Polinomial field;
	Elem* next;
	Elem* prev;
};

class List {
public:
	List();
	void add(int pos, Polinomial field);
	void printAll();
	void print(int pos);
	void delAll();
	void del(int pos);
	bool empty();
	Polinomial getData(int pos);
	~List();
protected:
	int count1;
	Elem *head;
	Elem *tail;
};