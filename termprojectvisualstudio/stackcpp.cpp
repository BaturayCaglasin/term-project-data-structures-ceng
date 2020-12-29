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
	
	string push(string value) {
		dll.addToDLLHead(value);
		return 0;
	}

	string top() {
		return dll.firstEl();
	}
	string pop()
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