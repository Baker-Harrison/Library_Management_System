//
// Created by thehe on 7/31/2024.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H


#include "Member.h"
#include "Librarian.h"
#include "Book.h"
#include <iostream>



#include <vector>

class Library {
private:
    std::vector<Member> members;
    std::vector<Librarian> librarians;
    std::vector<Book> books;
public:
    void addMember(Member &member);
    void addLibrarian(Librarian &librarian);
    void addBook(Book &book);
    std::vector<Book> getBooks() const;
    std::vector<Member> getMembers() const;
    std::vector<Librarian> getLibrarians() const;
    Book findBook(std::string title);
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
