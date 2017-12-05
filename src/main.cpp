#include <iostream>
#include <string>
using namespace std;

#include "../inc/Node.h"
#include "../inc/List.h"
#include "../inc/TypeFoo.h"
#include "../inc/Iterator.h"
#include "../inc/Algorithms.h"

int main(){
	string s4 ("A character sequence");  

	Node n;
	
	List s;
	
	TypeFoo t1("t1", 1);
	
	cout << endl << s.toString() <<endl;

	//cout << t1.toString() << endl;
	
	List s1(&t1);
	
	s1.popBack();
	
	//cout << s1.getFirstValue()->toString() << endl;
	
	//cout << s1.getValueLastElement()->toString() << endl;
	
	s1.pushBack(new TypeFoo("t2", 2));
	
	s1.popFront();
	s1.popFront();

	s1.pushBack(new TypeFoo("t3", 3));

	s1.pushBack(new TypeFoo("t4", 4));
	
	
	s1.popBack();

	s1.pushFront(new TypeFoo("t0", 0));
	
	Iterator* i = s1.getIterator();
	while(i->hasNext()){
		string tmp = i->getCurrentValue()->toString();
		cout << tmp << endl;
		(*i)++;
	}
	
	Iterator* i2 = s1.getIterator();
	//(*i2)++;

	s1.insertBefore(i2, new TypeFoo("t5", 5));
	
	cout << endl << s1.toString() <<endl;
	
	//**********************************************
	
	cout << "Check algorithms" << endl;
	
	Algorithms* algorithms = new Algorithms();
	
	List s2;
	
	s2.pushBack(new TypeFoo("t3", 3));
	s2.pushBack(new TypeFoo("t1", 1));
	s2.pushBack(new TypeFoo("t5", 5));
	s2.pushBack(new TypeFoo("t4", 4));
	s2.pushBack(new TypeFoo("t2", 2));
    
	
	/*Iterator* i21 = s2.getIterator();
	Iterator* i22 = s2.getIterator();
	
	(*i22)++;
	(*i22)++;*/
	
	cout << endl << s2.toString() <<endl;
	
	//s2.swap(i21, i22)
	
	algorithms->insertionSort(&s2, Algorithms::ASC);
	
	cout << endl << s2.toString() <<endl;
    
    algorithms->insertionSort(&s2, Algorithms::DESC);
    
    cout << endl << s2.toString() <<endl;
    
    algorithms->insertionSort(&s2, Algorithms::ASC);
	
	cout << endl << s2.toString() <<endl;
    
	//**********************************************
	
	cout << "Check algorithms isSorted" << endl;
    
    List s3;
	
	s3.pushBack(new TypeFoo("t3", 3));
	s3.pushBack(new TypeFoo("t1", 1));
	s3.pushBack(new TypeFoo("t5", 5));
	s3.pushBack(new TypeFoo("t4", 4));
	s3.pushBack(new TypeFoo("t2", 2));
    
    algorithms->insertionSort(&s3, Algorithms::ASC);
    
    if(algorithms->isSorted(&s3, Algorithms::ASC)){
        cout << "List is sorted ASC" << endl;
    }else{
        cout << "List is NOT sorted ASC" << endl;
    }
    
    algorithms->insertionSort(&s3, Algorithms::DESC);
    if(algorithms->isSorted(&s3, Algorithms::DESC)){
        cout << "List is sorted DESC" << endl;
    }else{
        cout << "List is NOT sorted DESC" << endl;
    }
    
    List* s4_ptr=new List;

    try{
        algorithms->isSorted(s4_ptr, 5);
    }catch(int i){
        cout << "AHAHAHAHAH " << i  << endl;
    }
    
    
    
	
	return 0;
}
