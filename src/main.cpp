#include <iostream>
#include <string>
using namespace std;

#include "../inc/Node.h"
#include "../inc/List.h"
#include "../inc/TypeFoo.h"
#include "../inc/Iterator.h"

int main(){
	string s4 ("A character sequence");  

	Node n;
	
	List s;
	
	TypeFoo t1("t1");

	//cout << t1.toString() << endl;
	
	List s1(&t1);
	
	//cout << s1.getFirstValue()->toString() << endl;
	
	//cout << s1.getValueLastElement()->toString() << endl;
	
	s1.pushBack(new TypeFoo("t2"));

	s1.pushBack(new TypeFoo("t3"));

	s1.pushBack(new TypeFoo("t4"));

	Iterator* i = s1.getIterator();
	while(i->hasNext()){
		string tmp = i->getCurrentValue()->toString();
		cout << tmp << endl;
		++(*i);
	}
	
	return 0;
}
