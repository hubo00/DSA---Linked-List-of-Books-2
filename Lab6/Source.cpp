// Hubert Bukowski | x00161897
#include "ListOfBooks.h"
#include <iostream>

int main() {
	ListOfBooks list;

	list.insertBack(1, "The Hobbit");
	list.insertBack(2, "Harry Potter");
	list.insertBack(3, "The Da Vinci Code");
	list.displayList();
	std::cout << list.deleteFromBack() << std::endl;
	list.displayList();
	list.insertBack(4, "Skulduggery Pleasant");
	list.insertBack(5, "Merchant of Venice");
	list.insertBack(6, "The Martian");
	list.displayList();
	std::cout << list.deleteByIndex(3) << std::endl;
	list.displayList();


	list.insertFront(99, "Biography of Bukko");
	list.displayList();
	list.deleteFront();
	list.displayList();
	list.deleteBook(4);
	list.displayList();

	ListOfBooks list2(list);
	std::cout << "displaying list 2" << std::endl;
	list2.displayList();

	ListOfBooks list3 = list2;
	std::cout << "displaying list 3" << std::endl;
	list3.displayList();

	return 0;
}