// Hubert Bukowski | x00161897
#pragma once
#include "Book.h"

/*
Class NodeOfBook which has two private member variables
theBook - An object of the Book class
next - A pointer to the next NodeOfBook object
*/
class NodeOfBook {
	friend class ListOfBooks;
private:
	Book theBook;
	NodeOfBook* next;
public:
	NodeOfBook();
};