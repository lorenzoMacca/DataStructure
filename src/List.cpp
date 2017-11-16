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
	//TODO: implement push front
	return  false;
}

Iterator* List::getIterator(){
	return new Iterator(this->m_first_element);
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
	this->m_last_element=this->m_last_element->getPreviout();
	if(this->m_last_element!=0){
		this->m_last_element->getNext()->setPrevious(0);
		this->m_last_element->setNext(0);
	}else{
		this->m_first_element=0;
	}
	return valueToBeReturned;
}

string List::toString()const{
	if(this->isEmpty()){
		return "[List: The List is empty]";
	}
	string mess = "[List: ";
	Iterator* i = new Iterator(this->m_first_element);
	while(i->hasNext()){
		mess += i->getNode()->toString() + " - ";
		++(*i);
	}
	mess += "]";
	delete i;
	return mess;
}

