#ifndef NODE_H
#define NODE_H

#include "../inc/Object.h"

class Node{

	protected:
		Object* m_value;
		Node* m_previous_element;
		Node* m_next_element;

	public:
		Node();
		Node(Object*);
		~Node();
		Node(const Node& n);
		Object* getValue()const;
		Node* getNext()const;
		Node* getPrevious()const;
		bool setNext(Node*);
		bool setPrevious(Node*);
		string toString()const;
};

#endif
