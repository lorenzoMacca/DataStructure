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
    delete this->m_value;
}

Node::Node(const Node& n){
	//TODO: implement copy constructor
}

Object* Node::getValue()const{
	return this->m_value;
}

void Node::setValue(Object* o){
	this->m_value=o;
}

Node* Node::getNext()const{
	return this->m_next_element;
}

Node* Node::getPrevious()const{
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

string Node::toString()const{
	string mess = "[Node: ";
	if(this->m_value!=0){
		mess+="[Value: " + this->m_value->toString() + "],";
	}else{
		mess+="[Value: Null],";
	}
	//check previous element
	if(this->m_previous_element == 0){
		mess+="[Previous: Previous node is null],";
	}else{
		if(this->m_previous_element->getValue() == 0){
			mess+="[Previous: value is null],";
		}else{
			mess+="[Previous value: " + this->m_previous_element->getValue()->toString() + "],";
		}
	}
	//check next value
	if(this->m_next_element == 0){
		mess+="[Next: node is null]";
	}else{
		if(this->m_next_element->getValue() == 0){
			mess+="[Next: value is null]";
		}else{
			mess+="[Next value: " + this->m_next_element->getValue()->toString() + "]";
		}
	}
	mess+="]";
	return mess;
}

int Node::compareTo(Object* o) const{
    if(o == 0 || this->m_value == 0 || ((Node*)o)->getValue() == 0)
        return -2;
    return this->m_value->compareTo(((Node*)o)->getValue());
}

