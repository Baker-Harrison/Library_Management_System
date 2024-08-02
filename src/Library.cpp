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

std::vector<Member>& Library::getMembers() {  // Return reference
    return members;
}

std::vector<Librarian> Library::getLibrarians() const {
   return librarians;
}

Book Library::findBook(std::string title) {
    for (Book &book : books)
    {
        if (title == book.getTitle())
        {
            return book;
        }
    }
}

std::vector<Person*> Library::getAllPeople()
{
    std::vector<Person*> people;


    for (Member &member : members)
    {
        bool exists = false;
        for (Person* &person : people)
        {
            if (person->getName() == member.getName())
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            people.push_back(new Member(member));
        }
    }


    for (Librarian &librarian : librarians)
    {
        bool exists = false;
        for (Person* &person : people)
        {
            if (person->getName() == librarian.getName())
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            people.push_back(new Librarian(librarian));
        }
    }

    return people;
}
