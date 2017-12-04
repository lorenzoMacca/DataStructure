#include "../inc/Algorithms.h"

void Algorithms::insertionSort(List* l, int mode){
	Iterator* i = l->getIterator();
	while(i->hasNext()){
		Iterator* j = new IteratorList();
		Object* key = i->getNode()->getValue();
		j->setNode(i->getNode()->getPrevious());
		//cout << "Checking " << key->toString() << endl;
		Iterator* rem = new IteratorList();
		rem->setNode(j->getNode());
		while(j->hasNext()){
			rem->setNode(j->getNode());
			int res = key->compareTo(j->getNode()->getValue());	
			//cout << "Comparing: " << key->toString() << " with " << j->getNode()->getValue()->toString() << "res=" << res <<endl;
			if(res==1){
				//cout << "KK " <<  j->getNode()->getValue()->toString() << " > " << key->toString() <<endl;
				j->getNode()->getNext()->setValue(j->getNode()->getValue());
			}
			(*j)--;
		}
		if(rem->hasNext()){
			rem->getNode()->setValue(key);
		}
		(*i)++;
	}
	
	delete (IteratorList*)i;
	
}
