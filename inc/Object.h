#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
using namespace std;

#include "../inc/Comparable.h"

class Object: public Comparable{

	public:
		virtual string toString() = 0 ;
		virtual int compareTo(Comparable*) = 0 ;
};

#endif
