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
	bool pushFront(T* t);
	T* popBack();
	T* popFrom();
	bool isEmpty()const;
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
bool List<T>::pushFront(T* t){
	if(t==0)
		return false;
	NodeList<T>* newNode = new NodeList<T>(t);
	newNode->setNext(this->m_root);
	this->m_root->setPrevious(newNode);
	this->m_root=newNode;
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

template<class T>
T* List<T>::popBack(){
	if(this->isEmpty())
		return 0;
	T* valueToBeReturned=this->m_lastElement->getValue();
	this->m_lastElement=this->m_lastElement->getPreviout();
	if(this->m_lastElement!=0){
		this->m_lastElement->getNext()->setPrevious(0);
		this->m_lastElement->setNext(0);
	}else{
		this->m_root=0;
	}
	return valueToBeReturned;
}

template<class T>
T* List<T>::popFrom(){
	return 0;
}

template<class T>
bool List<T>::isEmpty()const{
	if(this->m_root==0 && this->m_lastElement==0)
		return true;
	return false;
}

#endif
