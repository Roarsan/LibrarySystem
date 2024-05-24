
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string isbn;
    std::string title;
    std::string author;
    int copies;

    Book() : isbn(""), title(""), author(""), copies(0) {}  // Default constructor
    Book(const std::string& isbn, const std::string& title, const std::string& author, int copies);
};

#endif // BOOK_H


