#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"
#include "NodeList.h"


template<class T>
class Iterator{

	protected:
		NodeList<T>* m_currentNode;
	
	public:
		Iterator();
		Iterator(NodeList<T>* root);
		T* getCurrentValue()const;
		bool hasNext()const;
		Iterator<T>* operator++();
		NodeList<T>* getNode()const;
		void goToNext();
};

template<class T>
Iterator<T>::Iterator(){
	this->m_currentNode=0;
}

template<class T>
NodeList<T>* Iterator<T>::getNode()const{
	return this->m_currentNode;
}

template<class T>
	Iterator<T>::Iterator(NodeList<T>* root){
	this->m_currentNode=root;
}

template<class T>
T* Iterator<T>::getCurrentValue()const{
	return this->m_currentNode->getValue();
}

template<class T>
bool Iterator<T>::hasNext()const{
	//this->m_currentNode->printAll();
	if(this->m_currentNode==0)
		return false;
	return true;
}

template<class T>
void Iterator<T>::goToNext(){
	this->m_currentNode = this->m_currentNode->getNext();
}

template<class T>
Iterator<T>* Iterator<T>::operator++(){
	this->m_currentNode = this->m_currentNode->getNext();
	return this;
}

#endif
