#pragma once
#include <iostream>

/*
Class Book which has two private member variables
isbn - An integer value
title - A string value
*/
class Book {
	friend class NodeOfBook;
private:
	int isbn;
	std::string title;
public:
	int getIsbn(); // Accessor for isbn
	std::string getTitle(); // Accessor for title
	void setIsbn(int newIsbn); // Mutator for isbn
	void setTitle(std::string newTitle); // Mutator for title
	Book();
};