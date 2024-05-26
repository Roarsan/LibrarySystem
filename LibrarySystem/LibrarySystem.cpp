#include "LibrarySystem.h"
#include <iostream>
#include <string>

/**
 * @brief Adds a new book to the library.
 * @param book The book to be added.
 */
void LibrarySystem::addBook(const Book& book) {
    books.emplace(book.isbn, book);
}

/**
 * @brief Removes a book from the library using its ISBN.
 * @param isbn The ISBN of the book to be removed.
 */
void LibrarySystem::removeBook(const std::string& isbn) {
    books.erase(isbn);
}

/**
 * @brief Adds a new user to the library system.
 * @param user The user to be added.
 */
void LibrarySystem::addUser(const User& user) {
    users.emplace(user.userID, user);
}

/**
 * @brief Removes a user from the library system using their userID.
 * @param userID The ID of the user to be removed.
 */
void LibrarySystem::removeUser(int userID) {
    users.erase(userID);
}

/**
 * @brief Allows a user to borrow a book if available.
 * @param userID The ID of the user borrowing the book.
 * @param isbn The ISBN of the book to be borrowed.
 * @param borrowDate The date when the book is borrowed.
 * @return true if the book was successfully borrowed, false otherwise.
 */
bool LibrarySystem::borrowBook(int userID, const std::string& isbn, const std::string& borrowDate) {
    auto userIt = users.find(userID);
    auto bookIt = books.find(isbn);

    if (userIt != users.end() && bookIt != books.end() && bookIt->second.copies > 0) {
        userIt->second.borrowHistory.push_back(BorrowHistory(bookIt->second, borrowDate));
        bookIt->second.copies--;
        return true;
    }

    return false;
}

/**
 * @brief Allows a user to return a borrowed book.
 * @param userID The ID of the user returning the book.
 * @param isbn The ISBN of the book to be returned.
 * @return true if the book was successfully returned, false otherwise.
 */
bool LibrarySystem::returnBook(int userID, const std::string& isbn) {
    auto userIt = users.find(userID);
    auto bookIt = books.find(isbn);

    if (userIt != users.end() && bookIt != books.end()) {
        for (auto it = userIt->second.borrowHistory.begin(); it != userIt->second.borrowHistory.end(); ++it) {
            if (it->book.isbn == isbn) {
                userIt->second.borrowHistory.erase(it);
                bookIt->second.copies++;
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Displays the list of all books in the library.
 */
void LibrarySystem::displayBooks() {
    std::cout << "\nBooks in the library:\n";
    for (const auto& pair : books) {
        const Book& book = pair.second;
        std::cout << "ISBN: " << book.isbn << ", Title: " << book.title << ", Author: " << book.author << ", Copies: " << book.copies << std::endl;
    }
}
