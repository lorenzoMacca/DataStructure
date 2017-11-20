#ifndef IteratorList_H
#define IteratorList_H

#include "../inc/Node.h"
#include "../inc/Object.h"

class IteratorList{
	
	protected:
		Node* m_current_node;
	
	public:
		IteratorList();
		IteratorList(Node* root);
		Object* getCurrentValue()const;
		bool hasNext()const;
		IteratorList* operator++();
		IteratorList* operator++(int);
		IteratorList* operator--();
		IteratorList* operator--(int);
		Node* getNode()const;
		void goToNext();	
};

#endif
