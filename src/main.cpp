/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List using a user interface
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include <string>
#include "doubleLinkedList.h"
template <class T>
void LIST_MANIPULATION_MENU(string typeoflist, DoubleLinkedList<T>myList)
{
	system("cls");
	cout << "WARNING: TO AVOID ANY CRASH INSERT THE EXACT TYPE REQUESTED"<<endl;
	cout << "*************DOUBLE LINKED LIST****************" << endl;
	cout << "CURRENT LIST "; if (!myList.empty()) myList.printList(); else cout << "IS EMPTY" << endl;
	if (!myList.empty()) {
		cout << "SIZE: "<< myList.sizeOf() << endl;
		cout << "HEAD IS: "<< myList.look_head() << endl;
		cout << "CURRENT ELEMENT IS: "<< myList.look_current() << endl;
		cout << "TAIL: "<< myList.look_tail() << endl;
	}
	
	cout << "**************LIST OF " <<typeoflist<<"*****************" << endl;
	cout << "What do you want to do next?" << endl;
	cout << "1) Push an element to the head" << endl;
	cout << "2) Push an element to the tail" << endl;
	cout << "3) Push an element after the current element" << endl;
	cout << "4) Push an element before the current element" << endl;
	cout << "5) Pop the head" << endl;
	cout << "6) Pop the tail" << endl;
	cout << "7) Move the current element to the next element" << endl;
	cout << "8) Move the current element to the previous element" << endl;
	cout << "9) Sort the list" << endl;
	cout << "10) GO TO THE MAIN MENU" << endl;
	cout << "OPTION:";
}
void TYPE_OF_LIST_MENU() {
	
	system("cls");
	cout << "WARNING: TO AVOID ANY CRASH INSERT THE EXACT TYPE REQUESTED" << endl;
	cout << "*************DOUBLE LINKED LIST****************" << endl;
	cout << "What kind of list would you like to create:" << endl;
	cout << "1) LIST OF INTEGERS" << endl;
	cout << "2) LIST OF CHARACTERS" << endl;
	cout << "3) LIST OF IRRATIONAL NUMBERS " << endl;
	cout << "4) LIST OF STRINGS " << endl;
	cout << "5) EXIT"<<endl;
	cout << "OPTION:";
	
}
template <class R>
void LIST_MANIPULATION_FUNCTION(string typeoflist, DoubleLinkedList<R>myList)
{
	int option2 = 0;
	while (option2 != 10) {
		switch (option2)
		{
			case 0:
			{
				LIST_MANIPULATION_MENU(typeoflist, myList);
				cin >> option2;
				break;
			}
			case 1:
			{
				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				cout << "1) Push an element to the head" << endl;
				do {
					cout << "The value: ";
					R x;
					cin >> x;
					myList.push_front(x);
					do {
						cout << "Do you want to perform again this action? Insert y for yes and n for no: ";
						cin >> cRunOption;
						if ((cRunOption != 'y') && (cRunOption != 'n'))
						{
							cout << endl << "Wrong value. Try again" << endl;
						}
					} while ((cRunOption != 'y') && (cRunOption != 'n'));
				} while (cRunOption == 'y');
				option2 = 0;
				break;
			}
			case 2:
			{
				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				cout << "2) Push an element to the tail" << endl;
				do {
					cout << "The value: ";
					R x;
					cin >> x;
					myList.push_back(x);
					do {
						cout << "Do you want to perform again this action? Insert y for yes and n for no: ";
						cin >> cRunOption;
						if ((cRunOption != 'y') && (cRunOption != 'n'))
						{
							cout << endl << "Wrong value. Try again" << endl;
						}
					} while ((cRunOption != 'y') && (cRunOption != 'n'));
				} while (cRunOption == 'y');
				option2 = 0;
				break;
			}
			case 3:
			{
				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.empty())
				{
					cout << "The list is empty, use push to head or push to tail after using push after" << endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "3) Push an element after the current element:"<<myList.look_current() << endl;
				do {
					cout << "The value: ";
					R x;
					cin >> x;
					myList.push_after(x);
					do {
						cout << "Do you want to perform again this action? Insert y for yes and n for no: ";
						cin >> cRunOption;
						if ((cRunOption != 'y') && (cRunOption != 'n'))
						{
							cout << endl << "Wrong value. Try again" << endl;
						}
					} while ((cRunOption != 'y') && (cRunOption != 'n'));
				} while (cRunOption == 'y');
				option2 = 0;
				break;
			}
			case 4:
			{
				
				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.empty())
				{
					cout << "The list is empty, use push to head or push to tail after using push before"<<endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "4) Push an element before the current element:" <<myList.look_current() << endl;
				do {
					cout << "The value: ";
					R x;
					cin >> x;
					myList.push_before(x);
					do {
						cout << "Do you want to perform again this action? Insert y for yes and n for no: ";
						cin >> cRunOption;
						if ((cRunOption != 'y') && (cRunOption != 'n'))
						{
							cout << endl << "Wrong value. Try again" << endl;
						}
					} while ((cRunOption != 'y') && (cRunOption != 'n'));
				} while (cRunOption == 'y');
				option2 = 0;
				break;
			}
			case 5:
			{

				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.empty())
				{
					cout << "The list is empty" << endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "5) Pop the head:" << myList.look_head() << endl;
					do {
						cout << "Are you sure y for yes, n for no: ";
						cin >> cRunOption;
						if ((cRunOption != 'y') && (cRunOption != 'n'))
						{
							cout << endl << "Wrong value. Try again" << endl;
						}
						else {
							if (cRunOption == 'y')
							{
								cout << "The current head was delete and a new head was updated." << endl;
								myList.pop_head();
							}
							else {
								cout << "The action has been cancelled with success!" << endl;
							}
							system("pause");
						}
					} while ((cRunOption != 'y') && (cRunOption != 'n'));
				option2 = 0;
				break;
			}
			case 6:
			{

				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.empty())
				{
					cout << "The list is empty" << endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "6) Pop the tail:" << myList.look_tail() << endl;
				do {
					cout << "Are you sure y for yes, n for no: ";
					cin >> cRunOption;
					if ((cRunOption != 'y') && (cRunOption != 'n'))
					{
						cout << endl << "Wrong value. Try again" << endl;
					}
					else {
						if (cRunOption == 'y')
						{
							cout << "The current tail was delete and a new head was updated." << endl;
							myList.pop_tail();
						}
						else {
							cout << "The action has been cancelled with success!" << endl;
						}
						system("pause");
					}
				} while ((cRunOption != 'y') && (cRunOption != 'n'));
				option2 = 0;
				break;
			}
			case 7:
			{

				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.empty())
				{
					cout << "The list is empty" << endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "7) Move the current element to the next element. CURRENT ELEMENT:" << myList.look_current() << endl;
				do {
					cout << "Are you sure y for yes, n for no: ";
					cin >> cRunOption;
					if ((cRunOption != 'y') && (cRunOption != 'n'))
					{
						cout << endl << "Wrong value. Try again" << endl;
					}
					else {
						if (cRunOption == 'y')
						{
							myList.move_down();
							cout << "The current has been updated. Current element is " <<myList.look_current() << endl;
						}
						else {
							cout << "The action has been cancelled with success!" << endl;
						}
						system("pause");
					}
				} while ((cRunOption != 'y') && (cRunOption != 'n'));
				option2 = 0;
				break;
			}
			case 8:
			{

				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.empty())
				{
					cout << "The list is empty" << endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "8) Move the current element to the previous element. CURRENT ELEMENT: " << myList.look_current() << endl;
				do {
					cout << "Are you sure y for yes, n for no: ";
					cin >> cRunOption;
					if ((cRunOption != 'y') && (cRunOption != 'n'))
					{
						cout << endl << "Wrong value. Try again" << endl;
					}
					else {
						if (cRunOption == 'y')
						{
							myList.move_up();
							cout << "The current has been updated. Current element is " << myList.look_current() << endl;
						}
						else {
							cout << "The action has been cancelled with success!" << endl;
						}
						system("pause");
					}
				} while ((cRunOption != 'y') && (cRunOption != 'n'));
				option2 = 0;
				break;
			}
			case 9:
			{

				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				if (myList.sizeOf()<2)
				{
					cout << "The list is empty or too small" << endl;
					option2 = 0;
					system("pause");
					break;
				}
				cout << "9) Sort the list" << endl;
				do {
					cout << "Are you sure y for yes, n for no: ";
					cin >> cRunOption;
					if ((cRunOption != 'y') && (cRunOption != 'n'))
					{
						cout << endl << "Wrong value. Try again" << endl;
					}
					else {
						if (cRunOption == 'y')
						{
							char ascending;
							do {
								cout << "Enter a for ascending and d for descending:";
								cin >> ascending;
								if ((ascending != 'a') && (ascending != 'd'))
								{
									cout << endl << "Invalid value.Please try again" << endl;
								}
							} while ((ascending != 'a') && (ascending != 'd'));
							cout << "THE LIST NOW: ";myList.printList(); cout << endl;
							bool bASC = (ascending == 'a')?true:false;
							myList.sort(bASC);
							cout << "The has been sorted with success" << endl;
							cout << "THE LIST NOW: ";myList.printList(); cout << endl;
						}
						else {
							cout << "The action has been cancelled with success!" << endl;
						}
						system("pause");
					}
				} while ((cRunOption != 'y') && (cRunOption != 'n'));
				option2 = 0;
				break;
			}
			case 10:
			{

				char cRunOption = 'y';
				system("cls");
				cout << "*************DOUBLE LINKED LIST****************" << endl;
				cout << "**************LIST OF " << typeoflist << "*****************" << endl;
				cout << "11) Create a new type of list" << endl;
				do {
					cout << "The current list will be deleted.Do you want to continue y for yes, n for no: ";
					cin >> cRunOption;
					if ((cRunOption != 'y') && (cRunOption != 'n'))
					{
						cout << endl << "Wrong value. Try again" << endl;
					}
					else {
						if (cRunOption == 'y')
						{
							myList.deleteList();
							cout << "The list has been deleted with success!" << endl;
							cout << "You are redirected to the main menu" << endl;
						}
						else {
							cout << "The action has been cancelled with success!" << endl;
						}
						system("pause");
					}
				} while ((cRunOption != 'y') && (cRunOption != 'n'));
				break;
				system("pause");
			}
			default:
			{
				cout << "Invalid option pls try again" << endl;
				system("pause");
				option2 = 0;
			}
		}
	}
}
int main() /** Entry point for the application */
{
	bool bRun = true;
	char option = '0';
	string typeoflist;
	DoubleLinkedList<int>intList;
	DoubleLinkedList<char>charList;
	DoubleLinkedList<double>doubleList;
	DoubleLinkedList<string>stringList;
	while (bRun)
	{
		switch (option)
		{
			case '0':
			{
				TYPE_OF_LIST_MENU();
				cin >> option;
				break;
			}
			case '1':
			{
				LIST_MANIPULATION_FUNCTION("INTEGERS", intList);
				option = '0';
				break;
			}
			case '2':
			{
				LIST_MANIPULATION_FUNCTION("CHARACTERS", charList);
				option = '0';
				break;
			}
			case '3':
			{
				LIST_MANIPULATION_FUNCTION("RATIONAL NUMBERS", doubleList);
				option = '0';
				break;
			}
			case '4':
			{
				LIST_MANIPULATION_FUNCTION("STRINGS", stringList);
				option = '0';
				break;
			}
			case '5':
			{
				system("cls");
				cout << "BYE BYE"<<endl;
				bRun = false;
				break;
			}
			default:
			{
				cout << "Invalid Option please try again" << endl;
				system("pause");
				option = '0';
				break;
			}
		}
	}
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 0;
}
