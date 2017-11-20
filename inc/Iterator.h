#ifndef Iterator_H
#define Iterator_H

#include "../inc/Node.h"
#include "../inc/Object.h"

class Iterator{

	public:
		virtual Object* getCurrentValue()const = 0;
		virtual bool hasNext()const = 0;
		virtual Iterator* operator++() = 0;
		virtual Iterator* operator++(int) = 0;
		virtual Iterator* operator--() = 0;
		virtual Iterator* operator--(int) = 0;
		virtual Node* getNode()const = 0;
		virtual void goToNext() = 0;	
};

#endif
