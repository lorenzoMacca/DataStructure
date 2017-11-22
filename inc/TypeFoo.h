#ifndef TYPE_FOO_H
#define TYPE_FOO_H

#include "../inc/Object.h"


class TypeFoo: public Object{

	public:
		string name;
		int value;

		TypeFoo(string name, int value){
			this->name=name;
		}

		virtual string toString(){
			string s = "Hi! I am a dummy " + this->name + " class";
			return s;
		};
		
		virtual int compareTo(Comparable* c){return 0;}
};

#endif
