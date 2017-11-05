#include "list.h"
#include <iostream>
using namespace std;

int main(){

	int a=4;
	List<int> l1(&a);
	int b=3;
	l1.pushBack(&b);
	int c=2;
	l1.pushBack(&c);
	int d=1;
	l1.pushBack(&d);

	cout << *(l1.getRootValue()) << endl;
	
	
	Iterator<int>* i = l1.getIterator();
	while(i->hasNext()){
		//i->getNode()->printAll();		
		int tmp = *(i->getCurrentValue());
		cout << tmp << endl;
		//++i;
		//i->goToNext();
		++(*i);
	}

	cout << *(l1.getValueLastElement()) << endl;

	return 0;
}
