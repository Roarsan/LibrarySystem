#include "LibrarySystem.h"
#include <iostream> 

void LibrarySystem::addBook(const Book& book) {
    books.emplace(book.isbn, book);
}

void LibrarySystem::removeBook(const std::string& isbn) {
    books.erase(isbn);
}

void LibrarySystem::addUser(const User& user) {
    users.emplace(user.userID, user);
}
void LibrarySystem::removeUser(int userID) {
    users.erase(userID);
}

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
void LibrarySystem::displayBooks() {
    std::cout << "\nBooks in the library:\n";
    for (const auto& pair : books) {
        const Book& book = pair.second;
        std::cout << "ISBN: " << book.isbn << ", Title: " << book.title << ", Author: " << book.author << ", Copies: " << book.copies << std::endl;
    }
}
