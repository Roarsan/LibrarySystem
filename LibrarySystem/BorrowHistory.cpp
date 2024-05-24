#include "BorrowHistory.h"
#include <string>
#include "Book.h"

/**
 * @brief Parameterized constructor for the BorrowHistory class.
 * @param book The book being borrowed.
 * @param borrowDate The date when the book was borrowed.
 */
BorrowHistory::BorrowHistory(const Book& book, const std::string& borrowDate)
    : book(book), borrowDate(borrowDate) {}
