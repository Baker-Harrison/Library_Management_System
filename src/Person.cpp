//
// Created by thehe on 7/31/2024.
//

#include "../include/Person.h"

Person::Person()
{}


Person::Person(std::string name)
{
    this->name = name;

}

std::string Person::getName() const {
    return name;
}


void Person::printDetails() {
    std::cout << "Name: " << name << std::endl;

}
