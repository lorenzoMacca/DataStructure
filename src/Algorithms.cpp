#include "../inc/Algorithms.h"

void Algorithms::insertionSort(List* l, int mode){
	Iterator* i = l->getIterator();
	while(i->hasNext()){
		Iterator* j = new IteratorList();
		Object* key = i->getNode()->getValue();
		cout << "checking:" << key->toString() << endl;
		j->setNode(i->getNode()->getPrevious());
		while(j->hasNext()){
			int res = key->compareTo(j->getNode()->getValue());
			//cout << i->getNode()->getValue()->toString() << " " << j->getNode()->getValue()->toString() <<endl;
			if(res = -1){
				i->getNode()->setValue(j->getNode()->getValue());
			}else{
				j->getNode()->setValue(key);
				break;
			}
			if(j->getNode()->getPrevious() == 0){
				j->getNode()->setValue(key);
			}
			cout << endl << l->toString() << endl;
			(*j)--;
		}
		cout << "end while" << endl;
		
		(*i)++;
	}
	
	delete i;
	
}
