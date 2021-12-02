/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList<int> myList;

	myList.push_back(50);
	cout << myList.look_tail()<<endl;
	myList.push_back(65);
	cout << myList.look_tail() << endl;
	myList.push_back(43);
	cout << myList.look_tail() << endl;
	myList.push_back(72);
	cout << myList.look_tail() << endl;
	myList.sort(true);



	
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 0;
}
