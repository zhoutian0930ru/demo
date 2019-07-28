//homework10.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/11/17
//Example:

#include"LinkedList.h"
#include"Node.h"
#include<string>
#include<new>
using namespace std;

//main
int main() {
	//declare and initialize
	string name;
	int no;
	int choice;
	LinkedList T;
	
	cout << "Welcome to the shopping list program" << endl;
	
	//do while loop to build the list
	do{
		cout << "Please choose an option:" << endl
			<< "1.  Add a new node at the beginning" << endl
			<< "2.  Add a new node at the end" << endl
			<< "3.  Remove the beginning node" << endl
			<< "4.  Remove the end node" << endl
			<< "5.  Remove a node from the list by entering an item number" << endl
			<< "6.  Remove a node from the list by entering an item name" << endl
			<< "7.  Print out the list" << endl
			<< "8.  Quit the program" << endl;
		cout << "choice: ";
		cin >> choice;
		while (choice < 1 || choice>8) {
			cout << "choice: ";
			cin >> choice;
		}//end while
		
		//switch loop to operate the choice
		Node *newPtr = new Node;
		switch (choice) {
		case 1:
			cout << "Please enter product number to insert at beginning" << endl;
			cin >> no;
			cout << "Please enter the name for the product" << endl;
			cin >> name;
			newPtr->setNode(name, no);
			T.addToStart(newPtr);
			T.printList();
			break;
		case 2:
			cout << "Please enter product number to insert at the end" << endl;
			cin >> no;
			cout << "Please enter the name for the product" << endl;
			cin >> name;
			newPtr->setNode(name, no);
			T.addToEnd(newPtr);
			T.printList();
			break;
		case 3:
			cout << "After removing the beginning node(if it exist): " << endl;
			T.removeFromStart();
			T.printList();
			break;
		case 4:
			cout << "After removing the end node(if it exist): " << endl;
			T.removeFromEnd();
			T.printList();
			break;
		case 5:
			cout << "Please enter product number you want to delete in the list" << endl;
			cin >> no;
			T.removeNodeFromList(no);
			T.printList(); 
			break;
		case 6:
			cout << "Please enter product name you want to delete in the list" << endl;
			cin >> name;
			T.removeNodeFromList(name);
			T.printList();
			break;
		case 7:
			T.printList();
			break;
		}//end switch		

	} while (choice != 8);//end do while
	
	system("pause");
	return 0;
	
}//end main function