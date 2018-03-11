#include <iostream>
#include <string>
using namespace std;

#include "Node.h"
#include "List.h"
#include "TypeFoo.h"
#include "Iterator.h"
#include "Algorithms.h"
#include "Wrapper.h"

int main(){
    
    Wrapper<int> integerT;
    Integer valInt;
    Wrapper<char> chart;
    String str("Hello Wrapper!");
    cout << "Wrapper string " << str.toString()<<endl;
    
    Integer a(5);
    cout << "Wrapper string " << a.toString()<<endl;
    
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
    
    
	
	/*Iterator* i = s1.getIterator();
	while(i->hasNext()){
		string tmp = i->getCurrentValue()->toString();
		cout << tmp << endl;
		(*i)++;
	}*/
	
	Iterator* i2 = s1.getIterator();
	//(*i2)++;

	s1.insertBefore(i2, new TypeFoo("t5", 5));
	
	cout << endl << s1.toString() <<endl;
    
    cout << "size s1: " << s1.size() << endl;
	
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
	
	//cout << endl << s2.toString() <<endl;
	
	//s2.swap(i21, i22)
	
	algorithms->insertionSort(&s2, Algorithms::ASC);
	
	//cout << endl << s2.toString() <<endl;
    
    algorithms->insertionSort(&s2, Algorithms::DESC);
    
    //cout << endl << s2.toString() <<endl;
    
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
        if(i==Algorithms::INVALID_MODE){
            cout << "the mode is invalid" << endl;
        }
    }
    
    //**********************************************
    
    cout << "Create list on a wrapper type" << endl;
    
    List* s5_ptr = new List;
    s5_ptr->pushBack(new Integer(5));
    s5_ptr->pushBack(new Integer(4));
    s5_ptr->pushBack(new Integer(3));
    s5_ptr->pushBack(new Integer(2));
    s5_ptr->pushBack(new Integer(1));
	
    cout << *s5_ptr << endl;
    
    algorithms->insertionSort(s5_ptr, Algorithms::ASC);
    
    cout << *s5_ptr << endl;
    
    //**********************************************
    
    cout << "Test compare between two nodes" << endl;
    
    Node* a_node = new Node;
    Node* b_node = new Node;
    
    int res = a_node->compareTo(b_node);
    
    cout << "res: " << res << endl;
    
    a_node->setValue(new Integer(1));
    b_node->setValue(new Integer(1));
    
    res = a_node->compareTo(b_node);
    
    cout << "res: " << res << endl;
    
    b_node->setValue(new Integer(2));
    
    res = a_node->compareTo(b_node);
    
    cout << "res: " << res << endl;
    
    b_node->setValue(new Integer(0));
    
    res = a_node->compareTo(b_node);
    
    cout << "res: " << res << endl;
    
    //**********************************************
    
    cout << "Test *operator in iterator" << endl;
    
    List* s6_ptr = new List;
    s6_ptr->pushBack(new Char('A'));
    s6_ptr->pushBack(new Char('B'));
    
    Iterator* i_s5_ptr = s6_ptr->getIterator();
    
    cout << (*(*i_s5_ptr)).toString() << endl;
    (*i_s5_ptr)++;
    cout << (*(*i_s5_ptr)).toString() << endl;
    (*i_s5_ptr)++;
    i_s5_ptr->reset();
    cout << (*(*i_s5_ptr)).toString() << endl;
    (*i_s5_ptr)++;
    cout << (*(*i_s5_ptr)).toString() << endl;
    //(*i_s5_ptr)++;
    (*i_s5_ptr)++;
    (*i_s5_ptr)++;
    ++(*i_s5_ptr);
    ++(*i_s5_ptr);
    (*i_s5_ptr)--;
    --(*i_s5_ptr);
    
     //**********************************************
    
    cout << "testing push back list empty list" << endl;
    List* s7_ptr = new List;
    List* s8_ptr = new List;
    s8_ptr->pushBack(new Char('A'));
    s8_ptr->pushBack(new Char('B'));
    s7_ptr->pushBack(s8_ptr);
    cout << "LIST s7" << endl;
    cout << *s7_ptr << endl;
    s7_ptr->getFirstNode()->setValue(new Char('C'));
    cout << "LIST s8" << endl;
    cout << *s8_ptr << endl;
    
    cout << "testing push back list not empty list" << endl;
    List* s9_ptr = new List;
    s9_ptr->pushBack(new Char('A'));
    s9_ptr->pushBack(new Char('B'));
    List* s10_ptr = new List;
    s10_ptr->pushBack(new Char('C'));
    s10_ptr->pushBack(new Char('D'));
    s9_ptr->pushBack(s10_ptr);
    cout << "LIST s9" << endl;
    cout << *s9_ptr << endl;
    cout << "LIST s10" << endl;
    cout << *s10_ptr << endl;
    cout << s9_ptr->getFirstValue()->toString();
    cout << s9_ptr->getValueLastElement()->toString() << endl;
    s9_ptr->pushBack(s9_ptr);
    cout << "LIST s9" << endl;
    cout << *s9_ptr << endl;
    
    cout << "testing push front list empty list" << endl;
    List* s11_ptr = new List;
    List* s12_ptr = new List;
    s11_ptr->pushBack(new Char('A'));
    s11_ptr->pushBack(new Char('B'));
    s12_ptr->pushFront(s11_ptr);
    cout << "LIST s11" << endl;
    cout << *s11_ptr << endl;
    cout << "LIST s12" << endl;
    cout << *s12_ptr << endl;
    
    List s13;
    s13.pushBack(new Integer(1));
    s13.pushBack(new Integer(2));
    s13.pushBack(new Integer(3));
    s13.pushBack(new Integer(4));
    s13.pushBack(new Integer(5));
    List* s14_ptr = new List;
    s14_ptr->pushFront(new Integer(-2));
    s14_ptr->pushFront(new Integer(-1));
    s14_ptr->pushFront(new Integer(0));
    s14_ptr->pushFront(&s13);
    cout << "LIST s13" << endl;
    cout << s13 << endl;
    cout << "LIST s14" << endl;
    cout << *s14_ptr << endl;
    
	return 0;
}
