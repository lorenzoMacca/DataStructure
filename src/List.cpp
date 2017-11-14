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
