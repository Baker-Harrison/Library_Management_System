#include <iostream>
#include <string>
#include "include/Library.h"
#include "include/Book.h"
#include "include/Member.h"
#include "include/Librarian.h"

// Function prototypes
void displayMenu();
void handleAddBook(Library& library);
void handleAddMember(Library& library);
void handleAddLibrarian(Library& library);
void listBooks(const Library& library);
void listMembers(const Library& library);
void listLibrarians(const Library& library);
void handleBorrowBook(Library& library);

void printBorrowedBooks(const Library& library) ;

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

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
                handleBorrowBook(library);
                break;
            case 8:
                std::cout << "Exiting program." << std::endl;
                break;
            case 9:
                printBorrowedBooks(library);


            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 8);

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
    std::cout << "7. Borrow Book" << std::endl;
    std::cout << "8. return book" << std::endl;
    std::cout << "9. Get borrowed books for member" << std::endl;
    std::cout << "10. Exit" << std::endl;
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
    std::cin.ignore();  // Clear newline character from input buffer

    Member member(name);
    library.addMember(member);
    std::cout << "Member added successfully." << std::endl;
}

void handleAddLibrarian(Library& library) {
    std::string name;
    int employeeId;
    std::cout << "Enter librarian name: ";
    std::getline(std::cin, name);
    std::cout << "Enter employee ID: ";
    std::cin >> employeeId;
    std::cin.ignore();  // Clear newline character from input buffer

    Librarian librarian(name, employeeId);
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

                  << std::endl;
    }
}



void printBorrowedBooks(const Library& library) {
    listMembers(library);
    std::cout << "Enter the member's name you want to check or 'exit' to exit: ";
    std::string name;
    std::getline(std::cin, name);
    std::cin.ignore();
    if (name == "exit")
    {
        return;
    }
    for (const Member& member : library.getMembers()) {
        if (member.getName() == name) {
            member.listBorrowedBooks();
            return;
        }
    }
    std::cout << "Member not found." << std::endl;
}

void handleBorrowBook(Library& library) {
    listBooks(library);
    std::cout << "Enter book title or 'exit' to exit: ";
    std::string title;
    std::getline(std::cin, title);

    if (title == "exit")
    {
        return;
    }
    Book book = library.findBook(title);


    listMembers(library);
    std::cout << "Enter member name: ";
    std::string name;
    std::getline(std::cin, name);
    for (Member member : library.getMembers()) {

        if (member.getName() == name) {
            member.borrowBook(book);
            std::cout << "Book borrowed successfully." << std::endl;
            return;
        }
    }
    std::cout << "Member not found." << std::endl;
}