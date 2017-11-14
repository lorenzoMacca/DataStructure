#ifndef TYPE_FOO_H
#define TYPE_FOO_H

#include "../inc/Object.h"

class TypeFoo: public Object{

	public:
		virtual string toString(){
			string s = "Hi! I am a dummy class";
			return s;
		};
};

#endif
