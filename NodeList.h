#ifndef NODE_LIST_H
#define NODE_LIST_H

#include <iostream>
using namespace std;

template<class T>
class NodeList{

protected:
	T* m_value;
	NodeList* m_parent;
	NodeList* m_nextItem;
	
public:
	NodeList();
	NodeList(T*);
	~NodeList();
	NodeList(const NodeList<T> & n);
	T* getValue()const;
	NodeList<T>* getNext()const;
	NodeList<T>* getPreviout()const;
	bool setNext(NodeList<T>*);
	bool setPrevious(NodeList<T>*);
	void printAll()const;
};

template<class T>
NodeList<T>::NodeList(){
	this->m_parent=0;
	this->m_nextItem=0;
	this->m_value=0;
	
}

template<class T>
NodeList<T>::NodeList(T* value){
	this->m_parent=0;
	this->m_nextItem=0;
	this->m_value=value;
}

template<class T>
NodeList<T>::~NodeList(){
	//TODO: check how to implement the distructor
}

template<class T>
NodeList<T>::NodeList(const NodeList<T> & n){
	this->m_value=n.getValue();
}

template<class T>
T* NodeList<T>::getValue()const{
	return this->m_value;
}

template<class T>
NodeList<T>* NodeList<T>::getNext()const{
	return this->m_nextItem;
}

template<class T>
NodeList<T>* NodeList<T>::getPreviout()const{
	return this->m_parent;
}

template<class T>
bool NodeList<T>::setNext(NodeList<T>* n){
	if(n!=0){
		this->m_nextItem=n;
		return true;
	}
	return false;
}

template<class T>
bool NodeList<T>::setPrevious(NodeList<T>* n){
	if(n!=0){
			this->m_parent=n;
			return true;
		}
		return false;
}

template<class T>
void NodeList<T>::printAll()const{
	cout << "** start print **" << endl;
	if(this->m_value){
		cout << "value:" << *(this->m_value) << endl;
	}else{
		cout << "value is NULL" << endl;
	}
	if(this->m_nextItem){
		T* nextValue = this->m_nextItem->getValue();
		if(nextValue){
			cout << "next value:" << *(this->getNext()->getValue()) << endl;
		}else{
			cout << "next value is NULL" << endl;
		}	
	}else{
		cout << "next is null" <<endl;
	}

	if(this->m_parent){
		T* parentValue = this->m_parent->getValue();
		if(parentValue){
			cout << "parent value:" << *parentValue << endl;
		}else{
			cout << "parent value is NULL" << endl;
		}
	}else{
		cout << "parent is null" << endl;
	}
	
	cout << "** end print **" << endl;
}

#endif
