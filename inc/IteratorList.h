#ifndef IteratorList_H
#define IteratorList_H

#include "../inc/Node.h"
#include "../inc/Object.h"
#include "../inc/Iterator.h"

class IteratorList: public Iterator{
	
	protected:
		Node* m_current_node;
	
	public:
		IteratorList();
		IteratorList(Node* root);
		virtual ~IteratorList();
		virtual Object* getCurrentValue()const;
		virtual bool hasNext()const;
		virtual IteratorList* operator++();
		virtual IteratorList* operator++(int);
		virtual IteratorList* operator--();
		virtual IteratorList* operator--(int);
		virtual Node* getNode()const;
		virtual void goToNext();
};

#endif
