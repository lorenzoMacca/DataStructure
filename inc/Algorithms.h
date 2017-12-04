#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "../inc/List.h"

class Algorithms{
	
	public:
		static const int ASC=0;
		static const int DESC=1;
		
		void insertionSort(List*, int mode = Algorithms::ASC);

};

#endif
