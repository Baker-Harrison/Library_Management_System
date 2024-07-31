//
// Created by thehe on 7/31/2024.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_PERSON_H
#define LIBRARY_MANAGEMENT_SYSTEM_PERSON_H

#include <iostream>

class Person {
protected:
    std::string name;

public:
    Person();
    Person(std::string name);
    std::string getName() const;
    virtual void printDetails();
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_PERSON_H
