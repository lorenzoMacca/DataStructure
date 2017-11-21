#include "../inc/List.h"

List::List(){
	this->m_first_element=0;
	this->m_last_element=0;
}

List::List(Object* o){
	this->m_first_element=new Node(o);
	this->m_last_element=this->m_first_element;
}

List::~List(){
	//TODO: implement distructor
	
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
		return true;
	}
	return false;
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
		return true;
	}
	return  false;
}

Iterator* List::getIterator(){
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
	return true;
}
