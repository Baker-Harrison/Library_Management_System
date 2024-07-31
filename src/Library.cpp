//
// Created by thehe on 7/31/2024.
//

#include "../include/Library.h"

void Library::addMember(Member &member) {
    members.push_back(member);
}

void Library::addLibrarian(Librarian &librarian) {
    librarians.push_back(librarian);
}

void Library::addBook(Book &book) {
    books.push_back(book);
}

std::vector<Book> Library::getBooks() const{
    return books;
}

std::vector<Member> Library::getMembers() const {
    return members;
}

std::vector<Librarian> Library::getLibrarians() const {
   return librarians;
}

Book Library::findBook(std::string title) {
    for (Book book : books)
    {
        if (book.getTitle() == title)
        {
            return book;
        }
    }
}