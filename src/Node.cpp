#include "../inc/Node.h"

Node::Node(){
	this->m_value=0;
	this->m_previous_element=0;
	this->m_next_element=0;
}

Node::Node(Object* o){
	this->m_value=o;
	this->m_previous_element=0;
	this->m_next_element=0;
}

Node::~Node(){

}

Node::Node(const Node& n){
	//TODO: implement copy constructor
}

Object* Node::getValue()const{
	return this->m_value;
}

Node* Node::getNext()const{
	return this->m_next_element;
}

Node* Node::getPreviout()const{
	return this->m_previous_element;
}

bool Node::setNext(Node* n){
	this->m_next_element = n;
	return true;
}

bool Node::setPrevious(Node* n){
	this->m_previous_element = n;
	return true; 
}

