#include <iostream>
#include <string>
using namespace std;

#include "../inc/Node.h"
#include "../inc/List.h"
#include "../inc/TypeFoo.h"

int main(){
	string s4 ("A character sequence");  

	Node n;
	
	List s;
	
	TypeFoo t;

	cout << t.toString() << endl;
	
	List s1(&t);
	
	cout << s1.getFirstValue()->toString() << endl;
	
	cout << s1.getValueLastElement()->toString() << endl;
	
	return 0;
}
