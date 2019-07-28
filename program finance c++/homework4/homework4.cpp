//homework4.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/09
//Example:

#include<iostream>
using namespace std;

//declaration of nine functions
void insert(int[], int, int);
void insert_at(int[] , int , int , int);
int find_linear(int[] , int , int );
int find_binary(int[] , int , int );
void delete_item_position(int[] , int , int );
void delete_item_isbn(int[], int, int);
void sort_list_selection(int&, int);
void sort_list_bubble(int&, int );
void print(int[] , int );

//declaration of sorted function to judge whether the list is sorted
bool sorted(int[], int);

//the quantity of number in the list
int listNumber=0;

int main(){
	int *list = new int;  //declare a dynamic array
	int choice;           //declare the choice number
	int element;          //declare the element in the list
	int position;         //declare the position in the list
	
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
			insert(list, listNumber, element);
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;
		//Insert new element at a certain position
		case 2:
			cout << "Please enter the element: ";
			cin >> element;
			cout << "Please enter the position you will insert at: ";
			cin >> position;
			insert_at(list, listNumber, position , element);
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;
	    //Find an element (with its ISBN number and list its position) using linear search
		case 3:
			cout << "Please enter the element you want to find: ";
			cin >> element;
			cout << "The list number of element: " << element << " is: " << find_linear(list, listNumber, element) + 1 << endl;
			break;
		//Find an element (with its ISBN number and list its position) of a sorted list using binary search
		case 4:
			//judge whether the list is sorted
			if (sorted(list, listNumber)) {
				cout << "Please enter the element you want to find: ";
				cin >> element;
				cout << "The list number of element: " << element << " is: " << find_binary(list, listNumber, element) + 1 << endl;
				cout << "(-1 means no element is equal to element: " << element << ")" << endl;
			}
			else
				cout << "The list is not sorted." << endl;		
			break;
		//Delete an element that is at a certain position
		case 5:
			cout << "Please enter the position of element you want to delete: ";
			cin >> position;
			delete_item_position(list, listNumber, position);
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;
		//Delete an element by using its ISBN number
		case 6:
			cout << "Please enter the ISBN number of element you want to delete: ";
			cin >> element;
			delete_item_isbn(list, listNumber, element);
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;
		//Sort the list by the ISBN numbers (using selection sort) ¨C Use pointers for accessing array elements
		case 7:
			sort_list_selection(list[0],listNumber);
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;
		//Sort the list by the ISBN numbers (using bubble sort) ¨C Use pointers for accessing array elements
		case 8:
			sort_list_bubble(list[0], listNumber);
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;
		//Print out the list
		case 9:
			cout << "Your list in now: " << endl;
			print(list, listNumber);
			break;

		}
		cout << endl;
	} while (choice != 0);

	//delete[] list;

	system("pause");

	return (0);
	
}

void insert(int mylist[], int num_in_list, int new_element)
{
	mylist[num_in_list]=new_element;
	listNumber=listNumber + 1;
}

void insert_at(int mylist[], int num_in_list, int at_position, int new_element)
{
	if (at_position > num_in_list + 1)
		cout << "The position is not exist." << endl;
	else {
		for (int i = num_in_list; i > at_position - 2; i--) {
			mylist[i] = mylist[i - 1];
		}
		mylist[at_position - 1] = new_element;
		listNumber++;
	}	
}

int find_linear(int mylist[], int num_in_list, int new_element)
{
	int listNumber_find_linear = -1;
	for (int i = 0; i < listNumber; i++) {
		if (mylist[i] == new_element)
			listNumber_find_linear = i;
	}

	return listNumber_find_linear;

}

int find_binary(int mylist[], int num_in_list, int new_element)
{
	int listNumber_find_binary=-1;
	int i = 0, j = num_in_list, m;
	while (i != j && listNumber_find_binary == -1)
	{
		m = (i + j) / 2;
		if (mylist[m] == new_element) {
			listNumber_find_binary = m;
			break;
		}
		else if (mylist[m] > new_element)
			j = m;
		else
			i = m+1;
	}

	return listNumber_find_binary;
}

void delete_item_position(int mylist[], int num_in_list, int position)
{
	if (position > num_in_list) {
		cout << "The position at: " << position << " is not exist in the list." << endl;
	}
	else {
		for (int i = position; i < num_in_list; i++)
			mylist[i - 1] = mylist[i];

		listNumber--;
	}	
}

void delete_item_isbn(int mylist[], int num_in_list, int element)
{
	int position_delete;
	position_delete = find_linear(mylist, num_in_list, element);
	if (position_delete == -1)
		cout << "The isnb number: " << element << " is not an element in the list." << endl;
	else {
		for (int i = position_delete; i < num_in_list; i++)
			mylist[i] = mylist[i + 1];
		
		listNumber--;
	}
}

void sort_list_selection(int &mylist, int num_in_list)
{
	int minValue;
	int minNum;
	int hold;
	for (int i = 0; i < num_in_list; i++) {
		minValue = *((&mylist)+i);
		minNum = i;
		for (int j = i; j < num_in_list; j++) {
			if (*((&mylist)+j) < minValue) {
				minValue = *((&mylist)+j);
				minNum = j;
			}		
		}
		hold = *((&mylist)+i);
		*((&mylist)+i) = *((&mylist)+minNum);
		*((&mylist)+minNum) = hold;
	}
}

void sort_list_bubble(int &mylist, int num_in_list) 
{
	int hold;
	for (int i = num_in_list-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (*((&mylist) + j) > *((&mylist) + j + 1)) {
				hold = *((&mylist) + j);
				*((&mylist) + j) = *((&mylist) + j + 1);
				*((&mylist) + j + 1) = hold;
			}
		}
	}
}




void print(int mylist[], int num_in_list)
{
    for (int i = 0; i < num_in_list; i++) {
	    cout << i+1 << ". " << mylist[i] << endl;
    }
}

bool sorted(int mylist[], int num_in_list)
{
	bool list_sorted = 1;
	for (int i = 0; i < num_in_list-1; i++) {
		if (mylist[i] > mylist[i + 1])
			list_sorted = 0;
	}

	return list_sorted;
}