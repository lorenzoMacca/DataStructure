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
		
		virtual int compareTo(Object* o){
			if(o == 0) return -2;
			if(this == 0) return 0;
			if(this->value == ((TypeFoo*)o)->value) return 0;
			if(this->value > ((TypeFoo*)o)->value) return -1;
			if(this->value < ((TypeFoo*)o)->value) return 1;
		}
};

#endif
