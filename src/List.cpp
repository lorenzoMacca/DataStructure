#include "../inc/List.h"

List::List(){
	this->m_first_element=0;
	this->m_last_element=0;
    this->m_current_element_numbers = 0;
}

List::List(Object* o){
	this->m_first_element=new Node(o);
	this->m_last_element=this->m_first_element;
    this->m_current_element_numbers=1;
}

List::~List(){
	//TODO: implement distructor
    Iterator* i = this->getIterator();
    while(i->hasNext()){
        delete i->getCurrentValue();
        (*i)++;
    }
}

Object* List::getFirstValue()const{
	if(this->m_first_element != 0){
		return this->m_first_element->getValue();
	}
	return 0;
}

Object* List::getValueLastElement()const{
	if(this->m_last_element != 0){
		return this->m_last_element->getValue();
	}
	return 0;
}

bool List::pushBack(Object* o){
	if(o!=0){
		Node* n = new Node(o);
		n->setPrevious(this->m_last_element);
		if(this->m_last_element!=0){
			this->m_last_element->setNext(n);
		}else{
			this->m_first_element=n;
		}
		this->m_last_element=n;
        this->m_current_element_numbers++;
		return true;
	}
	return false;
}

void List::pushBack(List* l){
    if(l != 0 && l->size() > 0 && this!=l){
        if(this->size() == 0){
            this->m_first_element = l->m_first_element;
            this->m_last_element = l->m_last_element;
            this->m_current_element_numbers = l->m_current_element_numbers;
            //REMARK: The pointer l is passed as copy! if you do staff like this l=0 you will set to NULL just the copy of l!
        }else{
            Node* n = l->getFirstNode();
            n->setPrevious(this->m_last_element);
            if(this->m_last_element!=0){
                this->m_last_element->setNext(n);
            }else{
                this->m_first_element=n;
            }
            this->m_last_element=l->getLastNode();
            this->m_current_element_numbers++;
        }
        l->m_first_element = 0;
        l->m_last_element = 0;
        l->m_current_element_numbers = 0;
    }
}

bool List::pushFront(Object* o){
	if(o!=0){
		Node* n = new Node(o);
		n->setNext(this->m_first_element);
		if(this->m_first_element!=0){
			this->m_first_element->setPrevious(n);
		}else{
			this->m_last_element=n;
		}
		this->m_first_element=n;
        this->m_current_element_numbers++;
		return true;
	}
	return  false;
}

void List::pushFront(List* l){
    if(l != 0 && l->size() > 0 && this!=l){
        if(this->size() == 0){
            this->m_first_element = l->m_first_element;
            this->m_last_element = l->m_last_element;
            this->m_current_element_numbers = l->m_current_element_numbers;
            //REMARK: The pointer l is passed as copy! if you do staff like this l=0 you will set to NULL just the copy of l!
        }else{
            Node* n = l->getLastNode();
            n->setNext(this->m_first_element);
            if(this->m_first_element!=0){
                this->m_first_element->setPrevious(n);
            }else{
                this->m_last_element=n;
            }
            this->m_first_element=l->getFirstNode();
            this->m_current_element_numbers++;
        }
        l->m_first_element = 0;
        l->m_last_element = 0;
        l->m_current_element_numbers = 0;
    }
}

Iterator* List::getIterator()const{
	return new IteratorList(this->m_first_element);
}

bool List::isEmpty()const{
	if(this->m_first_element == 0){
		return true;
	}
	return false;
}

Object* List::popBack(){
	if(this->isEmpty()){
		return 0;
	}
	Object* valueToBeReturned=this->m_last_element->getValue();
	this->m_last_element=this->m_last_element->getPrevious();
	if(this->m_last_element!=0){
		this->m_last_element->getNext()->setPrevious(0);
		this->m_last_element->setNext(0);
	}else{
		this->m_first_element=0;
	}
    this->m_current_element_numbers--;
	return valueToBeReturned;
}

Object* List::popFront(){
	if(this->isEmpty()){
		return 0;
	}
	Object* valueToBeReturned=this->m_first_element->getValue();
	this->m_first_element=this->m_first_element->getNext();
	if(this->m_first_element!=0){
		this->m_first_element->getPrevious()->setNext(0);
		this->m_first_element->setPrevious(0);
	}else{
		this->m_last_element=0;
	}
    this->m_current_element_numbers--;
	return valueToBeReturned;
}

string List::toString()const{
	if(this->isEmpty()){
		return "[List: The List is empty]";
	}
	string mess = "[List: \n";
	IteratorList* i = new IteratorList(this->m_first_element);
	while(i->hasNext()){
		mess += i->getNode()->toString() + " - " + "\n";
		++(*i);
	}
	mess += "]";
	delete i;
	return mess;
}

Node* List::getFirstNode()const{
	return this->m_first_element;
}

Node* List::getLastNode()const{
	return this->m_last_element;
}

bool List::insertAfter(Iterator* i, Object* o ){
	//TODO: check if the iterator is compatible
	if(o==0){
		return false;
	}else if( i->getNode()==0){
		return false;
	}else if(this->isEmpty() || i->getNode()->getNext() == 0){
		return this->pushBack(o);
	}
	Node* n = new Node(o);
	n->setNext(i->getNode()->getNext());
	n->setPrevious(i->getNode());
	i->getNode()->getNext()->setPrevious(n);
	i->getNode()->setNext(n);
    this->m_current_element_numbers++;
	return true;
}

bool List::insertBefore(Iterator* i, Object* o ){
	//TODO: check if the iterator is compatible
	if(o==0){
		return false;
	}else if( i->getNode()==0){
		return false;
	}else if(this->isEmpty() || i->getNode()->getPrevious() == 0){
		return this->pushFront(o);
	}
	Node* n = new Node(o);
	n->setNext(i->getNode());
	n->setPrevious(i->getNode()->getPrevious());
	i->getNode()->getPrevious()->setNext(n);
	i->getNode()->setPrevious(n);
    this->m_current_element_numbers++;  
	return true;
}

void List::swap(Iterator* i1, Iterator* i2){
	//TODO: check if the iterator is compatible
	if(i1 != 0 && i2 != 0 && i1->getNode()!=0 && i2->getNode()!=0){
		Object* o = i1->getNode()->getValue();
		i1->getNode()->setValue(i2->getNode()->getValue());
		i2->getNode()->setValue(o);
	}
}

int List::size()const{
    return this->m_current_element_numbers;
}

ostream& operator<<(ostream& os, const List& l){
    Iterator* i = l.getIterator();
    while(i->hasNext()){
        string tmp = i->getCurrentValue()->toString();
        os << tmp << endl;
        (*i)++;
    }
    return os;
}

int List::compareTo(Object*) const{
    return -2;
}

List* List::search(Object* o)const{
    if(o == 0) return new List;
    List* l = new List;
    IteratorList* i = (IteratorList*)this->getIterator();
    while (i->hasNext()) {
        Node* n = i->getNode();
        if(n->getValue()->compareTo(o) == 0){
            l->pushBack(n);
        }
        (*i)++;
    }
    
    return l;
}

