#pragma once
#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"
using namespace std;

const int MAX_STACK = 10;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:	
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack
	
public:
	 ArrayStack();             // Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const;	
	 ~ArrayStack() {};
}; // end ArrayStack

#include "ArrayStack.cpp"
#endif
