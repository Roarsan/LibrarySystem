
#ifndef BOOK_H
#define BOOK_H

#include <string>

/**
 * @class Book
 * @brief Represents a book in the library system.
 */
class Book {
public:

    Book(const std::string& isbn, const std::string& title, const std::string& author, int copies);
};

#endif // BOOK_H


