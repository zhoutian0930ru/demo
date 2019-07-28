//LinkedList.cpp
//Name:Zhou Tian

#include"LinkedList.h"
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

//constructor
LinkedList::LinkedList()
{
	mySize = 0;
	myHead = myTail = 0;
}//end constructor

//function size
int LinkedList::size()
{
	return mySize;
}//end function size

//function addToStart
void LinkedList::addToStart(Node *newPtr)
{
	if (size() == 0)
		myHead = myTail = newPtr;
	else {
		newPtr->next = myHead;
		myHead = newPtr;
	}
	mySize++;
}//end function addToStart

//function addToEnd
void LinkedList::addToEnd(Node *newPtr)
{
	if (size() == 0)
		myHead = myTail = newPtr;
	else {
		myTail->next = newPtr;
		myTail = newPtr;
	}
	mySize++;
}//end function addToEnd

//function removeFromStart
bool LinkedList::removeFromStart()
{
	if (size() == 0)
		return false;
	else {
		Node *tempPtr = myHead;
		if (myHead == myTail)
			myHead = myTail = 0;
		else
			myHead = myHead->next;

		delete tempPtr;
		mySize--;

		return true;
	}
}//end function removeFromStart

 //function removeFromEnd
bool LinkedList::removeFromEnd()
{
	if (size() == 0)
		return false;
	else {
		Node *tempPtr = myTail;
		if (myHead == myTail)
			myHead = myTail = 0;
		else {
			Node *current = myHead;
			while (current->next != myTail)
				current = current->next;

			myTail = current;
			current->next = 0;
		}

		delete tempPtr;
		mySize--;

		return true;
	}
}//end function removeFromEnd

//function removeNodeFromList(int)
void LinkedList::removeNodeFromList(int noValue)
{
	Node *tempPtr;
	if (size() == 0)
		cout << "The No of product is not exist in the list." << endl;
	else {
		Node *scanPtr;
		Node *prescanPtr;
		if (size() == 1) {
			if (myHead->getNo()==noValue) {
				myHead = myTail = 0;
				mySize = 0;
				return;
			}
			else 
				cout << "The No of product is not exist in the list." << endl;
		}
		else {
			scanPtr = myHead;
			prescanPtr = myHead;
			
			for (int i = size() ; i > 0 ; i-- )  {
				if (scanPtr->getNo() == noValue) {
					if (scanPtr == myHead) {
						removeFromStart();
						return;
					}						
					else {
						if (scanPtr == myTail) {
							removeFromEnd();
							return;
						}		
						else {
							prescanPtr->next = scanPtr->next;
							mySize--;
							delete scanPtr;
							return;
						}
					}				
				}
				else {
					prescanPtr = scanPtr;
					scanPtr = scanPtr->next;
				}
			}
			cout << "The No of product is not exist in the list." << endl;
		}
	}
	return;
}//end function removeNodeFromList(int)

//function removeNodeFromList(string)
void LinkedList::removeNodeFromList(string scanname)
{
	Node *tempPtr;
	if (size() == 0)
		cout << "The No of product is not exist in the list." << endl;
	else {
		Node *scanPtr;
		Node *prescanPtr;
		if (size() == 1) {
			if (scanname.compare(myHead->getName())==0) {
				myHead = myTail = 0;
				mySize = 0;
				return;
			}
			else
				cout << "The Name of product is not exist in the list." << endl;
		}
		else {
			scanPtr = myHead;
			prescanPtr = myHead;

			for (int i = size(); i > 0; i--) {
				if (scanname.compare(scanPtr->getName()) == 0) {
					if (scanPtr == myHead) {
						removeFromStart();
						return;
					}
					else {
						if (scanPtr == myTail) {
							removeFromEnd();
							return;
						}
						else {
							prescanPtr->next = scanPtr->next;
							mySize--;
							delete scanPtr;
							return;
						}
					}
				}
				else {
					prescanPtr = scanPtr;
					scanPtr = scanPtr->next;
				}
			}

			cout << "The No of product is not exist in the list." << endl;
		}
	}
	return;
}//end function removeNodeFromList(string)

//function printList
void LinkedList::printList()
{
	int count = size();
	if (size() == 0) {
		cout<< "The list is empty\n\n";
		return;
	}

	Node *currentPtr = myHead;
	cout << " The list is: " << endl;
	cout << setw(10) << "item No" << setw(10) << "item Name" << endl;
	while (count > 0) {
		cout << setw(10) << currentPtr->itemNo << setw(10) << currentPtr->itemName << endl;
		currentPtr = currentPtr->next;
		count--;
	}
}//end function printList

//destructor
LinkedList::~LinkedList()
{
	if (size() != 0) {
		Node *currentPtr = myHead;
		Node *tempPtr;

		while (currentPtr != myTail) {
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
		delete myTail;
	}
}//end destructor