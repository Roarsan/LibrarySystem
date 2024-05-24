#ifndef BORROW_HISTORY_H
#define BORROW_HISTORY_H

#include <string>
#include "Book.h"

class BorrowHistory {
public:
    Book book;
    std::string borrowDate;

    BorrowHistory(const Book& book, const std::string& borrowDate);
};

#endif // BORROW_HISTORY_H
