#include "NodeOfBook.h"

NodeOfBook::NodeOfBook() {
	theBook.setIsbn(NULL);
	theBook.setTitle("Default");
	next = nullptr;
}