//
// Created by thehe on 7/31/2024.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
#define LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H


#include <vector>
#include "Book.h"
#include "Person.h"

class Member: public Person {
private:
    std::vector<Book> borrowedBooks;
public:

    Member(std::string name);

    void borrowBook(Book book);
    void returnBook(std::string bookName) ;
    void listBorrowedBooks();
    void printDetails() override;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
