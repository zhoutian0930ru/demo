//Booklist_Tian.h
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/19
//Example:
// prevent multiple inclusions of header file
#ifndef BOOKLIST_TIAN_H#define BOOKLIST_TIAN_H
// Booklist_Tian abstract data type definition
class Booklist_Tian
{

public:
	Booklist_Tian();              //constructor 
	void insert(int);
	void insert_at(int, int);
	int find_linear(int);
	int find_binary(int);
	void delete_item_position(int);
	void delete_item_isbn(int);
	void sort_list_selection();
	void sort_list_bubble();
	void print();
	bool sorted();

private:
	int list[20];
	int listNumber;

};

#endif
