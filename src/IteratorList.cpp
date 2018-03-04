#include "../inc/IteratorList.h"

IteratorList::IteratorList(){
	this->m_current_node=0;
}

IteratorList::IteratorList(Node* root){
    this->m_root_node=root;
	this->m_current_node=root;
}

Object* IteratorList::getCurrentValue()const{
	return this->m_current_node->getValue();
}

bool IteratorList::hasNext()const{
	if(this->m_current_node==0){
		return false;	
	}
	return true;
}

IteratorList* IteratorList::operator++(){
	this->m_current_node = this->m_current_node->getNext();
	return this;
}

IteratorList* IteratorList::operator++(int v){
	IteratorList* i = new IteratorList(this->m_current_node);
	this->m_current_node = this->m_current_node->getNext();
	return i;
}

IteratorList* IteratorList::operator--(){
	this->m_current_node = this->m_current_node->getPrevious();
	return this;
}

IteratorList* IteratorList::operator--(int v){
	IteratorList* i = new IteratorList(this->m_current_node);
	this->m_current_node = this->m_current_node->getPrevious();
	return i;
}

Node* IteratorList::getNode()const{
	return this->m_current_node;
}

void IteratorList::goToNext(){
	this->m_current_node = this->m_current_node->getNext();
}

IteratorList::~IteratorList(){
	// INFO: IteratorList class create nothing so nothing to do in this function
}

Iterator* IteratorList::operator=(const Iterator* i){
	this->m_current_node = i->getNode();
	return this;
}

void IteratorList::setNode(Node* n){
	this->m_current_node = n;
}

void IteratorList::reset(){
    this->m_current_node=m_root_node;
}

Object& IteratorList::operator*(){
    return *(this->m_current_node->getValue());
}
