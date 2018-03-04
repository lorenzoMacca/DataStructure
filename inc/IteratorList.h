#ifndef IteratorList_H
#define IteratorList_H

#include "../inc/Node.h"
#include "../inc/Object.h"
#include "../inc/Iterator.h"

class IteratorList: public Iterator{
	
	protected:
        Node* m_root_node;
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
		virtual Iterator* operator=(const Iterator*);
		virtual Node* getNode()const;
		virtual void goToNext();
		virtual void setNode(Node* );
        virtual void reset();
        virtual Object& operator*();
};

#endif
