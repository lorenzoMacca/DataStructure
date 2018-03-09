#ifndef LIST_H
#define LIST_H

#include "../inc/Node.h"
#include "../inc/Object.h"
#include "../inc/IteratorList.h"

class List : public Object{
	protected:
		Node* m_first_element;
		Node* m_last_element;
        int m_current_element_numbers;

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
		Iterator* getIterator()const;
		Node* getFirstNode()const;
		Node* getLastNode()const;
		bool insertAfter(Iterator*, Object*);
		bool insertBefore(Iterator*, Object*);
		void swap(Iterator*, Iterator*);
        int size()const;
        friend ostream& operator<<(ostream&, const List&);
        void pushBack(List*);
        void pushFront(List*);
    
        //from Object
        string toString()const;
        int compareTo(Object*) const;
};

#endif
