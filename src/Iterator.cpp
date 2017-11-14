#include "../inc/Iterator.h"

Iterator::Iterator(){
	this->m_current_node=0;
}

Iterator::Iterator(Node* root){
	this->m_current_node=root;
}

Object* Iterator::getCurrentValue()const{
	return this->m_current_node->getValue();
}

bool Iterator::hasNext()const{
	if(this->m_current_node==0){
		return false;	
	}
	return true;
}

Iterator* Iterator::operator++(){
	this->m_current_node = this->m_current_node->getNext();
	return this;
}

Node* Iterator::getNode()const{
	return this->m_current_node;
}

void Iterator::goToNext(){
	this->m_current_node = this->m_current_node->getNext();
}
