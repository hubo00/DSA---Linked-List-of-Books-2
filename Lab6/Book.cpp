// Hubert Bukowski | x00161897
#include "Book.h"
#include <iostream>

Book::Book() {
	isbn = NULL;
	title = "default";
}

int Book::getIsbn() { return isbn; }

std::string Book::getTitle() { return title; }

void Book::setIsbn(int newIsbn) { isbn = newIsbn; }

void Book::setTitle(std::string newTitle) { title = newTitle; }