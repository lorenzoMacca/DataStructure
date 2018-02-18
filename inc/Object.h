#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
using namespace std;

class Object{

	public:
		virtual string toString() = 0 ;
		virtual int compareTo(Object*) const = 0 ;
};

#endif
