//
// Created by thehe on 7/31/2024.
//

#include "../include/Book.h"

std::string Book::getTitle() const{
    return title;
}

std::string Book::getAuthor() const{
    return author;
}

std::string Book::getIsbn() const {
    return isbn;
}

Book::Book(const std::string &title, const std::string &author, const std::string &isbn) : title(title), author(author),
                                                                                           isbn(isbn) {}
