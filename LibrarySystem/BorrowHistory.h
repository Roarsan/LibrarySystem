#ifndef BORROW_HISTORY_H
#define BORROW_HISTORY_H

#include <string>
#include "Book.h"

/**
 * @class BorrowHistory
 * @brief Represents the borrowing history of a book.
 */
class BorrowHistory {
public:

    /**
     * @brief Parameterized constructor for the BorrowHistory class.
     * @param book The borrowed book.
     * @param borrowDate The date when the book was borrowed.
     */
    BorrowHistory(const Book& book, const std::string& borrowDate);
};

#endif // BORROW_HISTORY_H
