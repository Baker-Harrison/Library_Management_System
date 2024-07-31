//
// Created by thehe on 7/31/2024.
//

#include <iostream>
#include "../include/Librarian.h"


Librarian::Librarian()
{

}


Librarian::Librarian(std::string name, int employeeId)
{
    this->name = name;
    this->employeeId = employeeId;
}

void Librarian::mangageBook(Book &book) {
    std::cout << "Book mangaged" << std::endl;
}

void Librarian::helpMember(Member &member) {
    std::cout << "Member helped" << std::endl;
}

void Librarian::printDetails() {

    std::cout << "Name: " << name << std::endl;
    std::cout << "Employee ID: " << employeeId << std::endl;
}
