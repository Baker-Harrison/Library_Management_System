//
// Created by thehe on 7/31/2024.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARIAN_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARIAN_H




#include "Book.h"
#include "Member.h"

class Librarian: public Person {
private:
int employeeId;

public:
    Librarian();
    Librarian(std::string name, int employeeId);
    void mangageBook(Book &book);
    void helpMember(Member &member);
    void printDetails() override;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARIAN_H
