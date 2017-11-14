#ifndef LIST_H
#define LIST_H

#include "../inc/Node.h"
#include "../inc/Object.h"

class List{
	protected:
		Node* m_first_element;
		Node* m_last_element;

	public:
		List();
		List(Object*);
		~List();
		Object* getRootValue()const;
		Object* getValueLastElement()const;
		bool pushBack(Object* t);
		bool pushFront(Object* t);
		Object* popBack();
		Object* popFrom();
		bool isEmpty()const;
		//Iterator<T>* getIterator();
};

#endif
