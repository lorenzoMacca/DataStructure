#ifndef LIST_H
#define LIST_H

#include "../inc/Node.h"
#include "../inc/Object.h"
#include "../inc/IteratorList.h"

class List{
	protected:
		Node* m_first_element;
		Node* m_last_element;

	public:
		List();
		List(Object*);
		~List();
		Object* getFirstValue()const;
		Object* getValueLastElement()const;
		bool pushBack(Object* t);
		bool pushFront(Object* t);
		Object* popBack();
		Object* popFront();
		bool isEmpty()const;
		Iterator* getIterator();
		string toString()const;
		Node* getFirstNode()const;
		Node* getLastNode()const;
		bool insertAfter(Iterator*, Object*);
		bool insertBefore(Iterator*, Object*);
		void swap(Iterator*, Iterator*);
};

#endif
