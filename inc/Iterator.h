#ifndef ITERATOR_H
#define ITERATOR_H

#include "../inc/Node.h"
#include "../inc/Object.h"

class Iterator{
	
	protected:
		Node* m_current_node;
	
	public:
		Iterator();
		Iterator(Node* root);
		Object* getCurrentValue()const;
		bool hasNext()const;
		Iterator* operator++();
		Iterator* operator++(int);
		Iterator* operator--();
		Iterator* operator--(int);
		Node* getNode()const;
		void goToNext();	
};

#endif
