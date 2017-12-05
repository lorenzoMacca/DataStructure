#include "../inc/Algorithms.h"

void Algorithms::insertionSort(List* l, int mode){
    if(l==0){
        throw Algorithms::NULL_POINT;
    }
    int compare = -2;
    if(mode == Algorithms::ASC){
        compare = 1;
    }else if(mode == Algorithms::DESC){
        compare = -1;
    }else{
        throw Algorithms::INVALID_MODE;
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


bool Algorithms::isSorted(List* l, int mode){
    if(l==0){
        throw Algorithms::NULL_POINT;
    }
    int compare = -2;
    if(mode==Algorithms::ASC){
        compare=1;
    }else if(mode==Algorithms::DESC){
        compare=-1;
    }
    if(compare==-2){
        throw Algorithms::INVALID_MODE;
    }
    Iterator* i = l->getIterator();
    while(i->hasNext()){
        if(i->getNode() != 0 && i->getNode()->getNext() != 0){
            int res = i->getNode()->getValue()->compareTo(i->getNode()->getNext()->getValue());
            if(res != compare){
                return false;
            }
        }
        (*i)++;
    }
    return true;
}