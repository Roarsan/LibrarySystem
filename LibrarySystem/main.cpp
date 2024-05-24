#include <iostream>
#include <limits> // For clearing input buffer
#include "LibrarySystem.h"

using namespace std;

/**
 * @brief Displays the main menu for the Library Management System.
 */
void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Remove Book\n";
    cout << "3. Add User\n";
    cout << "4. Remove User\n";
    cout << "5. Borrow Book\n";
    cout << "6. Return Book\n";
    cout << "7. Display Books\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    LibrarySystem library;

    // Example data
    Book book1("1234567890", "The Great Gatsby", "F. Scott Fitzgerald", 3);
    Book book2("0987654321", "To Kill a Mockingbird", "Harper Lee", 2);
    library.addBook(book1);
    library.addBook(book2);

    User user1(1, "Alice");
    User user2(2, "Bob");
    library.addUser(user1);
    library.addUser(user2);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add a new book
            string isbn, title, author;
            int copies;
            cout << "Enter ISBN: ";
            cin >> isbn;
            cout << "Enter Title: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Number of Copies: ";
            cin >> copies;
            Book newBook(isbn, title, author, copies);
            library.addBook(newBook);
            cout << "Book added successfully.\n";
            break;
        }
        case 2: {
            // Remove an existing book
            string isbn;
            cout << "Enter ISBN of book to remove: ";
            cin >> isbn;
            library.removeBook(isbn);
            cout << "Book removed successfully.\n";
            break;
        }
        case 3: {
            // Add a new user
            int userID;
            string name;
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter User Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            getline(cin, name);
            User newUser(userID, name);
            library.addUser(newUser);
            cout << "User added successfully.\n";
            break;
        }
        case 4: {
            // Remove an existing user
            int userID;
            cout << "Enter User ID to remove: ";
            cin >> userID;
            library.removeUser(userID);
            cout << "User removed successfully.\n";
            break;
        }
        case 5: {
            // Borrow a book
            int userID;
            string isbn, borrowDate;
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter ISBN of book to borrow: ";
            cin >> isbn;
            cout << "Enter Borrow Date (YYYY-MM-DD): ";
            cin >> borrowDate;
            if (library.borrowBook(userID, isbn, borrowDate)) {
                cout << "Book borrowed successfully.\n";
            }
            else {
                cout << "Book not available or user already borrowed the maximum number of copies.\n";
            }
            break;
        }
        case 6: {
            // Return a borrowed book
            int userID;
            string isbn;
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter ISBN of book to return: ";
            cin >> isbn;
            if (library.returnBook(userID, isbn)) {
                cout << "Book returned successfully.\n";
            }
            else {
                cout << "Book not borrowed by the user.\n";
            }
            break;
        }
        case 7: {
            // Display books in the library
            library.displayBooks();
            break;
        }
        case 8: {
            // Exit the program
            cout << "Exiting...\n";
            break;
        }
        default:
            // Handle invalid menu choice
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
