//homework6:Main_Tian.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/19
//Example:

#include<iostream>
using namespace std;

#include "Booklist_Tian.h"

int main() {
	Booklist_Tian booklist;  //declare a class type
	int choice;              //declare the choice number
	int element;             //declare the element in the list
	int position;            //declare the position in the list

	//welcome sentence
	cout << "Welcome to the Book list program." << endl;

	//Using do while loop to make sure the program have to run once.
	do {
		cout << "what would you like to do?" << endl;
		cout << "     1. add an element to end of list" << endl;
		cout << "     2. add an element at a location" << endl;
		cout << "     3. find an element by ISBN number (linear search)" << endl;
		cout << "     4. find an element by ISBN number (binary search)" << endl;
		cout << "     5. delete an element at position" << endl;
		cout << "     6. delete an element by ISBN number" << endl;
		cout << "     7. sort the list (using selection sort)" << endl;
		cout << "     8. sort the list (using bubble sort)" << endl;
		cout << "     9. print the list" << endl;
		cout << "     0. exit" << endl;
		//enter the choice number using in the swich loop
		cout << "Please enter your choice: ";
		cin >> choice;

		switch (choice) {
		//Insert new element at the end of the list
		case 1:
			cout << "Please enter the element: ";
			cin >> element;
			booklist.insert(element);
			cout << "Your list in now: " << endl;
			booklist.print();
			break;
		//Insert new element at a certain position
		case 2:
			cout << "Please enter the element: ";
			cin >> element;
			cout << "Please enter the position you will insert at: ";
			cin >> position;
			booklist.insert_at(position, element);
			cout << "Your list in now: " << endl;
			booklist.print();
			break;
		//Find an element (with its ISBN number and list its position) using linear search
		case 3:
			cout << "Please enter the element you want to find: ";
			cin >> element;
			cout << "The list number of element: " << element << " is: " << booklist.find_linear(element) + 1 << endl;
			break;
		//Find an element (with its ISBN number and list its position) of a sorted list using binary search
		case 4:
		//judge whether the list is sorted
			if (booklist.sorted()) {
				cout << "Please enter the element you want to find: ";
				cin >> element;
				cout << "The list number of element: " << element << " is: " << booklist.find_binary(element) + 1 << endl;
				cout << "(-1 means no element is equal to element: " << element << ")" << endl;
			}
			else
				cout << "The list is not sorted." << endl;
			break;
		//Delete an element that is at a certain position
		case 5:
			cout << "Please enter the position of element you want to delete: ";
			cin >> position;
			booklist.delete_item_position(position);
			cout << "Your list in now: " << endl;
			booklist.print();
			break;
		//Delete an element by using its ISBN number
		case 6:
			cout << "Please enter the ISBN number of element you want to delete: ";
			cin >> element;
			booklist.delete_item_isbn(element);
			cout << "Your list in now: " << endl;
			booklist.print();
			break;
		//Sort the list by the ISBN numbers (using selection sort) ¨C Use pointers for accessing array elements
		case 7:
			booklist.sort_list_selection();
			cout << "Your list in now: " << endl;
			booklist.print();
			break;
		//Sort the list by the ISBN numbers (using bubble sort) ¨C Use pointers for accessing array elements
		case 8:
			booklist.sort_list_bubble();
			cout << "Your list in now: " << endl;
			booklist.print();
			break;
		//Print out the list
		case 9:
			cout << "Your list in now: " << endl;
			booklist.print();
			break;

		}
		cout << endl;
	} while (choice != 0);

	system("pause");

	return (0);

}