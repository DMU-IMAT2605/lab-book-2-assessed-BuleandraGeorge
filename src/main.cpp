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

void main() /** Entry point for the application */
{
	DoubleLinkedList myList;
	myList.push_before(1000);
	cout<<myList.look_head();
	
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
