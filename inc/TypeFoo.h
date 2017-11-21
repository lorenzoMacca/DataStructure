#ifndef TYPE_FOO_H
#define TYPE_FOO_H

#include "../inc/Object.h"


class TypeFoo: public Object{

	private:
		string name;

	public:
		TypeFoo(string name){
			this->name=name;
		}

		virtual string toString(){
			string s = "Hi! I am a dummy " + this->name + " class";
			return s;
		};
		
		virtual int compareTo(Comparable* c){return 0;}
};

#endif
