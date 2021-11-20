// Hubert Bukowski | x00161897
#pragma once
#include "NodeOfBook.h"
#include <iostream>

/*
Class ListOfBook which has one private member variables
head - A pointer to the first node of the list
*/
class ListOfBooks {
	friend std::ostream& operator<<(std::ostream& str, ListOfBooks& list);
private:
	NodeOfBook* head = nullptr;
public:
	void insertBack(int isbn, std::string title); // inserts a new book object
	void displayList(); // prints the list
	int deleteFromBack(); // deletes newest object
	int deleteByIndex(int pos); // deletes specified object
	bool insertFront(int isbn, std::string title);
	bool deleteFront();
	bool deleteBook(int isbnToDelete);
	bool findBook(int isbn);
	ListOfBooks();
	ListOfBooks(ListOfBooks& list);
	~ListOfBooks();
	ListOfBooks& operator=(const ListOfBooks& list);
};