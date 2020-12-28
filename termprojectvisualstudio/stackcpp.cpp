#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Header.h"

using namespace std;
template<class T>
class mystack 
{

public:
	DoublyLinkedList <string> dll;
	int length;
	

	mystack()
	{
		length =dll.getSize();
		
	}
	
	void push(T value) {
	
	}
	int top() {
		return dll.firstEl();
	}
	int pop()
	{
		length--;
		return dll.deleteFromDLLHead();
	}

	int getSize() {
		return length;
	}
	void print() {
		length.printAll();
	}

};