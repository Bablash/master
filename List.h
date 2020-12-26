#pragma once
#include "Polinomial.h"

using namespace std;

template<typename T>
struct Elem {
	T field;
	Elem<T>* next;
	Elem<T>* prev;
};

template<typename T>
class List {
public:
	List();
	int getCount1();
	void add(int pos, T field);
	void printAll();
	void delAll();
	void del(int pos);
	~List();
protected:
	int count1;
	Elem<T>* head;
	Elem<T>* tail;
};

template<typename T>
inline List<T>::List() {
	head = tail = NULL;
	count1 = 0;
}

template<typename T>
inline int List<T>::getCount1() {
	return count1;
}

template<typename T>
inline void List<T>::add(int pos, T field) {
	try
	{
		if (pos < 1 || pos > count1 + 1) {
			throw ArrayException("Invalid index");
		}
		Elem<T>* temp = new Elem<T>;
		if (head == NULL || tail == NULL) {
			temp->next = temp;
			temp->prev = temp;
			temp->field = field;
			head = tail = temp;
			count1++;
			return;
		}
		if (pos == 1 && head != NULL && tail != NULL) {
			temp->next = tail;
			temp->field = field;
			temp->prev = head;
			head->next = temp;
			tail->prev = temp;
			head = temp;
			count1++;
			return;
		}
		if (pos == count1 + 1) {
			temp->next = tail;
			temp->field = field;
			temp->prev = head;
			tail->prev = temp;
			head->next = temp;
			tail = temp;
			count1++;
			return;
		}
		int i = 1;
		Elem<T>* Ins = head;
		while (i < pos) {
			Ins = Ins->prev;
			i++;
		}
		Elem<T>* NextIns = Ins->next;
		NextIns->prev = temp;
		temp->next = NextIns;
		temp->prev = Ins;
		Ins->next = temp;
		temp->field = field;
		count1++;
		return;
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << endl << endl;
	}
}

template<typename T>
inline void List<T>::printAll()
{
	try
	{
		if (count1 == 0) {
			throw ArrayException("List is empty");
		}
		Elem<T>* temp = head;
		for (int i = 0; i < count1; i++)
		{
			cout << temp->field << " ";
			temp = temp->prev;
		}

		cout << endl;
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << endl << endl;
	}
}

template<typename T>
inline void List<T>::delAll()
{
	while (count1 != 0)
		del(1);
}

template<typename T>
inline void List<T>::del(int pos) {
	try
	{
		if (pos < 1 || pos > count1 + 1) {
			throw ArrayException("Invalid index");
		}
		if (count1 == 1) {
			Elem<T>* del = head;
			delete del;
			count1--;
			return;
		}
		if (pos == 1) {
			Elem<T>* del = head;
			Elem<T>* prevdel = del->prev;
			Elem<T>* nextdel = del->next;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = prevdel;
			delete del;
			count1--;
			return;
		}
		if (pos == count1 + 1) {
			Elem<T>* del = tail;
			Elem<T>* nextdel = del->next;
			Elem<T>* prevdel = del->prev;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = nextdel;
			delete del;
			count1--;
			return;
		}
		int i = 1;
		Elem<T>* del = head;
		while (i < pos) {
			del = del->prev;
			i++;
		}
		Elem<T>* prevdel = del->prev;
		Elem<T>* nextdel = del->next;
		prevdel->next = nextdel;
		nextdel->prev = prevdel;
		delete del;
		count1--;
	}
	catch (ArrayException& exception) {

		std::cerr << "Error: " << exception.getError() << endl << endl;
	}
}

template<typename T>
inline List<T>::~List() {
	delAll();
}