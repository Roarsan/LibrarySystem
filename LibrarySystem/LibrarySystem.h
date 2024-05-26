#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <string>
#include <unordered_map>
#include "Book.h"
#include "User.h"
#include <string>

#include "BorrowHistory.h"

/**
 * @class LibrarySystem
 * @brief Represents the library management system.
 */
class LibrarySystem {
public:
    /**
     * @brief Adds a book to the library.
     * @param book The book to add.
     */
    void addBook(const Book& book);

    /**
     * @brief Removes a book from the library.
     * @param isbn The ISBN of the book to remove.
     */
    void removeBook(const std::string& isbn);

    /**
     * @brief Adds a user to the library system.
     * @param user The user to add.
     */
    void addUser(const User& user);

    /**
     * @brief Removes a user from the library system.
     * @param userID The ID of the user to remove.
     */
    void removeUser(int userID);

    /**
     * @brief Allows a user to borrow a book from the library.
     * @param userID The ID of the user borrowing the book.
     * @param isbn The ISBN of the book to borrow.
     * @param borrowDate The date when the book is borrowed.
     * @return True if the book was successfully borrowed, false otherwise.
     */
    bool borrowBook(int userID, const std::string& isbn, const std::string& borrowDate);

    /**
     * @brief Allows a user to return a borrowed book to the library.
     * @param userID The ID of the user returning the book.
     * @param isbn The ISBN of the book to return.
     * @return True if the book was successfully returned, false otherwise.
     */
    bool returnBook(int userID, const std::string& isbn);

    /**
     * @brief Displays the list of books in the library.
     */
    void displayBooks();

private:
    std::unordered_map<std::string, Book> books; ///< The collection of books in the library.
    std::unordered_map<int, User> users;         ///< The collection of users in the library.
};

#endif // LIBRARY_SYSTEM_H
