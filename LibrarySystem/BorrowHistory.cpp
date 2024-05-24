#include "BorrowHistory.h"
#include <string>
#include "Book.h"

BorrowHistory::BorrowHistory(const Book& book, const std::string& borrowDate)
    : book(book), borrowDate(borrowDate) {}
