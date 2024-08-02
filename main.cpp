#include <iostream>
#include <string>
#include "include/Library.h"
#include "include/Book.h"
#include "include/Member.h"
#include "include/Librarian.h"
#include <unistd.h>

// Function prototypes
void displayMenu();
void handleAddBook(Library& library);
void handleAddMember(Library& library);
void handleAddLibrarian(Library& library);
void listBooks(const Library& library);
void listMembers(Library library);
void listLibrarians(const Library& library);
void handleBorrowBook(Library& library);
void handleReturnBook(Library& library);

void printBorrowedBooks(Library library) ;
void getAllPeopleInLibrary(Library& library);

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
                sleep(2);
                break;
            case 2:
                handleAddMember(library);
                sleep(2);
                break;
            case 3:
                handleAddLibrarian(library);
                sleep(2);
                break;
            case 4:
                listBooks(library);
                sleep(2);
                break;
            case 5:
                listMembers(library);
                sleep(2);
                break;
            case 6:
                listLibrarians(library);
                sleep(2);
                break;
            case 7:
                handleBorrowBook(library);
                sleep(2);
                break;
            case 8:
                handleReturnBook(library);
                break;
            case 9:
                printBorrowedBooks(library);
                sleep(2);
                break;
            case 10:
                getAllPeopleInLibrary(library);
                sleep(2);
                break;
            case 11:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 11);

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
    std::cout << "10. Get all people in library" << std::endl;
    std::cout << "11. Exit the program" << std::endl;
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

void listMembers(Library library) {
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



void printBorrowedBooks(Library library) {
    listMembers(library);
    std::cout << "Enter the member's name you want to check or 'exit' to exit: ";
    std::string name;
    std::getline(std::cin, name);
    if (name == "exit")
    {
        return;
    }
    for (const Member& member : library.getMembers()) {
        if (name == member.getName()) {
            int counter = 1;
            for (const Book& book : member.getBorrowedBooks()) {
                std::cout << "Book " << counter++ << ":" << std::endl;
                std::cout << "Book Name: " << book.getTitle() << std::endl;
                std::cout << "Author: " << book.getAuthor() << std::endl;
                std::cout << "ISBN: " << book.getIsbn() << std::endl << std::endl;
            }
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
    for (Member &member : library.getMembers()) {
        if (member.getName() == name) {
            member.borrowBook(book);
            std::cout << "Book borrowed successfully." << std::endl;
            return;
        }
    }
    std::cout << "Member not found." << std::endl;
}

void handleReturnBook(Library& library) {
    std::cout << "________________________" << std::endl;
    listMembers(library);
    std::cout << "________________________" << std::endl;
    std::cout << "Enter member name: ";
    std::string name;
    std::getline(std::cin, name);
    bool isFound = false;
    for (Member& member : library.getMembers()) {
        if (member.getName() == name) {
            member.listBorrowedBooks();
            isFound = true;
            break;
        }

    }

    if (!isFound) {
        std::cout << "Member not found." << std::endl;
        return;
    }


    std::cout << "Enter book title or 'exit' to exit: ";
    std::string title;
    std::getline(std::cin, title);
    if (title == "exit")
    {
        return;
    }
    Book book = library.findBook(title);
    for (Member& member : library.getMembers()) {
        member.returnBook(title);
    }
    std::cout << "Book returned successfully." << std::endl;
}

void getAllPeopleInLibrary(Library& library)
{

    for (Person* person : library.getAllPeople())
    {
        std::cout << "------------------------------------" << std::endl;
        person->printDetails();
    }
}