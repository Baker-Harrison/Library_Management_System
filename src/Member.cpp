//
// Created by thehe on 7/31/2024.
//

#include "../include/Member.h"

void Member::printDetails() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Number of Borrowed Books: " << borrowedBooks.size() << std::endl;
}

void Member::listBorrowedBooks() {
    for (Book book : borrowedBooks) {

        std::cout << "Book Name: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "ISBN: " << book.getIsbn() << std::endl << std::endl;
    }
}

void Member::returnBook(std::string bookName) {
    for (int i = 0; i < borrowedBooks.size(); i++) {

        if (borrowedBooks[i].getTitle() == bookName) {

            borrowedBooks.erase(borrowedBooks.begin() + i);
        }
    }
}

void Member::borrowBook(Book book) {

    borrowedBooks.push_back(book);
}

Member::Member(std::string name)
{
    this->name = name;
    this->borrowedBooks = borrowedBooks;
}
