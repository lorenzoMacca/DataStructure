#ifndef LIST_H
#define LIST_H

#include "NodeList.h"
#include "iterator.h"
#include <iostream>
using namespace std;

template<class T>
class List{

protected:
	NodeList<T>* m_root;
	NodeList<T>* m_lastElement;
	
public:
	List();
	List(T*);
	~List();
	T* getRootValue()const;
	T* getValueLastElement()const;
	bool pushBack(T* t);
	Iterator<T>* getIterator();
};

template<class T>
List<T>::List(){
	this->root=0;
	this->m_lastElement=0;
}

template<class T>
List<T>::List(T* t){
	this->m_root=new NodeList<T>(t);
	this->m_lastElement=this->m_root;
}

template<class T>
List<T>::~List(){
	//TODO: check how to implement the distructor
}

template<class T>
bool List<T>::pushBack(T* t){
	if(t==0)
		return false;
	NodeList<T>* newNode = new NodeList<T>(t);
	newNode->setPrevious(this->m_lastElement);
	this->m_lastElement->setNext(newNode);
	this->m_lastElement=newNode;
	return true;
}

template<class T>
T* List<T>::getRootValue()const{
	if(this->m_root==0)
		return 0;
	return this->m_root->getValue();
}

template<class T>
T* List<T>::getValueLastElement()const{
	if(this->m_lastElement==0)
		return 0;
	return this->m_lastElement->getValue();
}

template<class T>
Iterator<T>* List<T>::getIterator(){
	return new Iterator<T>(this->m_root);
}

#endif
