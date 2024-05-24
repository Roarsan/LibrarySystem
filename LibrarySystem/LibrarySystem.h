#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "Book.h"
#include "User.h"
#include "BorrowHistory.h"

class LibrarySystem {
public:
    std::unordered_map<std::string, Book> books; // ISBN to Book mapping
    std::unordered_map<int, User> users; // UserID to User mapping

    void addBook(const Book& book);
    void removeBook(const std::string& isbn);
    void addUser(const User& user);
    void removeUser(int userID);
    bool borrowBook(int userID, const std::string& isbn, const std::string& borrowDate);
    bool returnBook(int userID, const std::string& isbn);
    void displayBooks(); // Added semicolon here

};

#endif // LIBRARY_SYSTEM_H
