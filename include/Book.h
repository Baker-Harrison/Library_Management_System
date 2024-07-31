
//
// Created by thehe on 7/31/2024.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOK_H


#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
public:
    Book(const std::string &title, const std::string &author, const std::string &isbn);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
