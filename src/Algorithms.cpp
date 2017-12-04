#include "../inc/Algorithms.h"

void Algorithms::insertionSort(List* l, int mode){
    int compare = -2;
    if(mode == Algorithms::ASC){
        compare = 1;
    }else if(mode == Algorithms::DESC){
        compare = -1;
    }else{
        return;
    }
	Iterator* i = l->getIterator();
	while(i->hasNext()){
		Iterator* j = new IteratorList();
		Object* key = i->getNode()->getValue();
		j->setNode(i->getNode()->getPrevious());
		//cout << "Checking " << key->toString() << endl;
		Iterator* rem = new IteratorList();
		rem->setNode(j->getNode());
        bool keyIsShifted = false;
		while(j->hasNext()){
			int res = key->compareTo(j->getNode()->getValue());	
			//cout << "Comparing: " << key->toString() << " with " << j->getNode()->getValue()->toString() << "res=" << res <<endl;
			if(res==compare){
				//cout << "KK " <<  j->getNode()->getValue()->toString() << " > " << key->toString() <<endl;
				j->getNode()->getNext()->setValue(j->getNode()->getValue());
                keyIsShifted = true;
                rem->setNode(j->getNode());
			}
			(*j)--;
		}
		if(keyIsShifted && rem->hasNext()){
			rem->getNode()->setValue(key);
		}
        delete (IteratorList*)rem;
        delete (IteratorList*)j;
		(*i)++;
        //cout << l->toString() << endl;
	}
	delete (IteratorList*)i;
	
}
