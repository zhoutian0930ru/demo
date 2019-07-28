//Booklist_Tian.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/19
//Example:

#include<iostream>
using namespace std;

#include "Booklist_Tian.h"

Booklist_Tian::Booklist_Tian()
{
	list[25] = { 0 };
	listNumber=0;
}

void Booklist_Tian::insert(int element)
{
	if (listNumber > 19) {
		cout << "The list has already 20 books.";
	}
	else {
		list[listNumber] = element;
		listNumber = listNumber + 1;
	}
}

void Booklist_Tian::insert_at(int position, int element)
{
	if (listNumber > 19) {
		cout << "The list has 20 books.";
	}
	else {
		if (position > listNumber + 1)
			cout << "The position is not exist." << endl;
		else {
			for (int i = listNumber; i > position - 2; i--) {
				list[i] = list[i - 1];
			}
			list[position - 1] = element;
			listNumber++;
		}
	}
}

int Booklist_Tian::find_linear(int element)
{
	int listNumber_find_linear = -1;
	for (int i = 0; i < listNumber; i++) {
		if (list[i] == element)
			listNumber_find_linear = i;
	}

	return listNumber_find_linear;
}

int Booklist_Tian::find_binary(int element)
{
	int listNumber_find_binary = -1;
	int i = 0, j = listNumber, m;
	while (i != j && listNumber_find_binary == -1)
	{
		m = (i + j) / 2;
		if (list[m] == element) {
			listNumber_find_binary = m;
			break;
		}
		else if (list[m] > element)
			j = m;
		else
			i = m + 1;
	}

	return listNumber_find_binary;
}

void Booklist_Tian::delete_item_position(int position)
{
	if (position > listNumber) {
		cout << "The position at: " << position << " is not exist in the list." << endl;
	}
	else {
		for (int i = position; i < listNumber; i++)
			list[i - 1] = list[i];

		listNumber--;
	}
}

void Booklist_Tian::delete_item_isbn(int element)
{
	int position_delete;
	position_delete = find_linear(element);
	if (position_delete == -1)
		cout << "The isnb number: " << element << " is not an element in the list." << endl;
	else {
		for (int i = position_delete; i < listNumber; i++)
			list[i] = list[i + 1];

		listNumber--;
	}
}

void Booklist_Tian::sort_list_selection()
{
	int minValue;
	int minNum;
	int hold;
	for (int i = 0; i < listNumber; i++) {
		minValue = list[i];
		minNum = i;
		for (int j = i; j < listNumber; j++) {
			if (list[j] < minValue) {
				minValue = list[j];
				minNum = j;
			}
		}
		hold = list[i];
		list[i] = list[minNum];
		list[minNum] = hold;
	}
}

void Booklist_Tian::sort_list_bubble()
{
	int hold;
	for (int i = listNumber - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				hold = list[j];
				list[j] = list[j + 1];
				list[j + 1] = hold;
			}
		}
	}
}

void Booklist_Tian::print()
{
	for (int i = 0; i < listNumber; i++) {
		cout << i + 1 << ". " << list[i] << endl;
	}
}

bool Booklist_Tian::sorted()
{
	bool list_sorted = 1;
	for (int i = 0; i < listNumber - 1; i++) {
		if (list[i] > list[i + 1])
			list_sorted = 0;
	}

	return list_sorted;
}

