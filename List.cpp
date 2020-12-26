#include <iostream>
#include "List.h"
using namespace std;

List::List() {
	head = tail = NULL;
	count1 = 0;
}

int List::getCount1() {
	return count1;
}

bool List::add(int pos, Polinomial field) {
	try
	{
		if (pos < 1 || pos > count1 + 1) {
			throw ArrayException("Invalid index");
		}
		Elem* temp = new Elem;
		if (head == NULL || tail == NULL) {
			temp->next = temp;
			temp->prev = temp;
			temp->field = field;
			head = tail = temp;
			count1++;
			return true;
		}
		if (pos == 1 && head != NULL && tail != NULL) {
			temp->next = tail;
			temp->field = field;
			temp->prev = head;
			head->next = temp;
			tail->prev = temp;
			head = temp;
			count1++;
			return true;
		}
		if (pos == count1 + 1) {
			temp->next = tail;
			temp->field = field;
			temp->prev = head;
			tail->prev = temp;
			head->next = temp;
			tail = temp;
			count1++;
			return true; 
		}
		int i = 1;
		Elem* Ins = head;
		while (i < pos) {
			Ins = Ins->prev;
			i++;
		}
		Elem* NextIns = Ins->next;
		NextIns->prev = temp;
		temp->next = NextIns;
		temp->prev = Ins;
		Ins->next = temp;
		temp->field = field;
		count1++;
		return true;
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << endl << endl;
		return false;
	}
}

void List::printAll()
{
	try
	{
		if (count1 == 0) {
			throw ArrayException("List is empty");
		}
		Elem* temp = head;
		for (int i = 0; i < count1; i++)
		{
			temp->field.toString();
			temp = temp->prev;
		}

		temp->field.toString();
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << endl << endl;
	}
}

void List::print(int pos) {
	Elem* temp;
	temp = head;
	int i = 1;

	while (i < pos)
	{
		temp = temp->prev;
		i++;
	}
	temp->field.toString();
}

void List::delAll()
{
	while (count1 != 0)
		del(1);
}

void List::del(int pos) {
	try
	{
		if (pos < 1 || pos > count1 + 1) {
			throw ArrayException("Invalid index");
		}
		if (count1 == 1) {
			Elem* del = head;
			delete del;
			count1--;
			return;
		}
		if (pos == 1) {
			Elem* del = head;
			Elem* prevdel = del->prev;
			Elem* nextdel = del->next;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = prevdel;
			delete del;
			count1--;
			return;
		}
		if (pos == count1 + 1) {
			Elem* del = tail;
			Elem* nextdel = del->next;
			Elem* prevdel = del->prev;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = nextdel;
			delete del;
			count1--;
			return;
		}
		int i = 1;
		Elem* del = head;
		while (i < pos) {
			del = del->prev;
			i++;
		}
		Elem* prevdel = del->prev;
		Elem* nextdel = del->next;
		prevdel->next = nextdel;
		nextdel->prev = prevdel;
		delete del;
		count1--;
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << endl << endl;
	}
}

bool List::empty() {
	if (count1 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

Polinomial List::getData(int pos) {
	Elem* temp;
	temp = head;
	int i = 1;

	while (i < pos)
	{
		temp = temp->prev;
		i++;
	}
	return temp->field;
}

List::~List() {
	delAll();
}