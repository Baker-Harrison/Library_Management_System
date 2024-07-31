#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"

// Function prototypes
void displayMenu();
void handleAddBook(Library& library);
void handleAddMember(Library& library);
void handleAddLibrarian(Library& library);
void listBooks(const Library& library);
void listMembers(const Library& library);
void listLibrarians(const Library& library);

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                handleAddBook(library);
                break;
            case 2:
                handleAddMember(library);
                break;
            case 3:
                handleAddLibrarian(library);
                break;
            case 4:
                listBooks(library);
                break;
            case 5:
                listMembers(library);
                break;
            case 6:
                listLibrarians(library);
                break;
            case 7:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    std::cout << "\nLibrary Management System Menu:" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Add Member" << std::endl;
    std::cout << "3. Add Librarian" << std::endl;
    std::cout << "4. List Books" << std::endl;
    std::cout << "5. List Members" << std::endl;
    std::cout << "6. List Librarians" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void handleAddBook(Library& library) {
    std::string title, author, isbn;
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter book ISBN: ";
    std::getline(std::cin, isbn);

    Book book(title, author, isbn);
    library.addBook(book);
    std::cout << "Book added successfully." << std::endl;
}

void handleAddMember(Library& library) {
    std::string name;
    int id;
    std::cout << "Enter member name: ";
    std::getline(std::cin, name);
    std::cout << "Enter member ID: ";
    std::cin >> id;
    std::cin.ignore();  // Clear newline character from input buffer

    Member member(name, id);
    library.addMember(member);
    std::cout << "Member added successfully." << std::endl;
}

void handleAddLibrarian(Library& library) {
    std::string name;
    int id;
    std::cout << "Enter librarian name: ";
    std::getline(std::cin, name);
    std::cout << "Enter librarian ID: ";
    std::cin >> id;
    std::cin.ignore();  // Clear newline character from input buffer

    Librarian librarian(name, id);
    library.addLibrarian(librarian);
    std::cout << "Librarian added successfully." << std::endl;
}

void listBooks(const Library& library) {
    std::cout << "\nBooks in Library:" << std::endl;
    for (const Book& book : library.getBooks()) {
        std::cout << "Title: " << book.getTitle()
                  << ", Author: " << book.getAuthor()
                  << ", ISBN: " << book.getIsbn()
                  << std::endl;
    }
}

void listMembers(const Library& library) {
    std::cout << "\nMembers of Library:" << std::endl;
    for (const Member& member : library.getMembers()) {
        std::cout << "Name: " << member.getName()
                  << std::endl;
    }
}

void listLibrarians(const Library& library) {
    std::cout << "\nLibrarians of Library:" << std::endl;
    for (const Librarian& librarian : library.getLibrarians()) {
        std::cout << "Name: " << librarian.getName()
                  << ", ID: " << librarian.getId()
                  << std::endl;
    }
}
