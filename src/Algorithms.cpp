#include "../inc/Algorithms.h"

void Algorithms::insertionSort(List* l, int mode){
	Iterator* i = l->getIterator();
	while(i->hasNext()){
		Iterator* j = new IteratorList();
		Object* key = i->getNode()->getValue();
		j->setNode(i->getNode());
		(*j)--;
		while(j->hasNext()){
			int res = i->getNode()->getValue()->compareTo(j->getNode()->getValue());
			if(res = -1){
				i->getNode()->setValue(j->getNode()->getValue());
			}else{
				j->getNode()->setValue(key);
				break;
			}
			(*j)--;
		}
		(*i)++;
	}
	
	delete i;
	
}
