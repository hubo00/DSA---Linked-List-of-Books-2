#include "ListOfBooks.h"
#include "NodeOfBook.h"
#include <iostream>

// Default constructor for ListOfBooks which sets the head to null
ListOfBooks::ListOfBooks() :head(NULL) {}

ListOfBooks::ListOfBooks(ListOfBooks& list) {
	head = NULL;
	*this = list;
}

// Default Destructor for ListOfBooks
ListOfBooks::~ListOfBooks() {
	NodeOfBook* tempPtr;
	while (head) {
		tempPtr = head;
		head = head->next;
		delete tempPtr;
	}
}

// insertBack() method which takes isbn and title as parameter and creates a new book object and node
void ListOfBooks::insertBack(int isbn, std::string title) {
	NodeOfBook* newNode = new NodeOfBook();
	newNode->theBook.setIsbn(isbn);
	newNode->theBook.setTitle(title);
	NodeOfBook* pointer;
	if (!head) {
		head = newNode;
	}
	else {
		for (pointer = head; pointer->next; pointer = pointer->next);
		pointer->next = newNode;
	}
}

// displayList() method which iterates through the List and displays each object
void ListOfBooks::displayList() {
	NodeOfBook* pointer = head;
	while (pointer != nullptr) {
		std::cout << pointer->theBook.getIsbn() << "-" << pointer->theBook.getTitle() << " | ";
		pointer = pointer->next;
	}
	std::cout << std::endl;
}

// deleteMostRecent() method which deletes the newest object in the array
int ListOfBooks::deleteFromBack() {
	NodeOfBook* pointer = head;
	NodeOfBook* pointerBehind = nullptr;
	int deletedValue = NULL;
	if (head) {
		if (!head->next) { // If there is just one object in the list
			deletedValue = pointer->theBook.getIsbn();
			delete pointer;
			pointer = nullptr;
			head = nullptr;
		}
		else {
			while (pointer->next != nullptr) {
				pointerBehind = pointer;
				pointer = pointer->next;
			}
			if (pointer->next == nullptr) {
				deletedValue = pointer->theBook.getIsbn();
				delete pointer;
				pointer = nullptr;
				pointerBehind->next = nullptr;
			}
		}
	}
	else {
		std::cout << "List is empty" << std::endl;
		return -1;
	}
	if (deletedValue) {
		return deletedValue;
	}
	else {
		std::cout << "Error" << std::endl;
		return -1;
	}
}

// deleteByIndex() method which takes an index position as a parameter and returns the value at that position
int ListOfBooks::deleteByIndex(int pos) {
	NodeOfBook* pointer = head;
	NodeOfBook* pointerBehind = nullptr;
	int deletedValue = NULL;
	int currentPos = NULL;
	if (head) {
		while (currentPos != pos) {
			pointerBehind = pointer;
			pointer = pointer->next;
			currentPos++;
		}
		if (currentPos == pos) {
			if (pointer == head) {
				head = head->next;
				deletedValue = pointer->theBook.getIsbn();
				delete pointer;
			}
			else {
				deletedValue = pointer->theBook.getIsbn();
				pointerBehind->next = pointer->next;
				delete pointer;
			}
			return deletedValue;
		}
	}
	else {
		std::cout << "Array is empty" << std::endl;
		return 0;
	}
}

// insertFront() method which takes as parameters values for new Book objects, and inserts the object at the front of the list
bool ListOfBooks::insertFront(int isbn, std::string title) {
	bool finished = false;

	if (head) {
		NodeOfBook* newNode = new NodeOfBook();
		newNode->theBook.setIsbn(isbn);
		newNode->theBook.setTitle(title);
		newNode->next = head;
		head = newNode;
		finished = true;
	}
	
	return finished;
}

// deleteFront() method which removes the first element in the linked list
bool ListOfBooks::deleteFront() {
	bool finished = false;

	if (head) {
		NodeOfBook* tempNode;
		tempNode = head->next;
		delete head;
		head = tempNode;
	}
	return finished;
}

// deleteBook() method which takes an isbn code as parameter and deletes the object with a matching code
bool ListOfBooks::deleteBook(int isbnToDelete) {
	bool finished = false;

	if (head) {
		NodeOfBook* pointer = head;
		NodeOfBook* pointerBehind = nullptr;
		if (head->theBook.getIsbn() == isbnToDelete) {
			head = head->next;
			delete pointer;
			finished = true;
		}
		else {
			while (pointer != NULL && pointer->theBook.getIsbn() != isbnToDelete) {
				pointerBehind = pointer;
				pointer = pointer->next;
			}
		}
		if (pointer != NULL) {
			pointerBehind->next = pointer->next;
			delete pointer;
			finished = true;
		}
	}
	else {
		std::cout << "Array is empty" << std::endl;
	}
	return finished;
}

ListOfBooks& ListOfBooks::operator=(const ListOfBooks& list) {
	if (this != &list) {
		if (head != NULL) {
			while (head) {
				deleteFromBack();
			}
		}
		NodeOfBook* copyPtr = NULL;
		NodeOfBook* pointer = list.head;

		while (pointer != NULL) {
			if (head == NULL) {
				copyPtr = new NodeOfBook();
				copyPtr->theBook.setIsbn(pointer->theBook.getIsbn());
				copyPtr->theBook.setTitle(pointer->theBook.getTitle());
				head = copyPtr;
			}
			else {
				copyPtr->next = new NodeOfBook();
				copyPtr->next->theBook.setIsbn(pointer->theBook.getIsbn());
				copyPtr->next->theBook.setTitle(pointer->theBook.getTitle());
				copyPtr = copyPtr->next;
			}
			pointer = pointer->next;
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& str, ListOfBooks& list) {
	list.displayList();
	return str;
}