#ifndef BOOK_H
#define BOOK_H

#include <string>

/**
 * @class Book
 * @brief Represents a book in the library system.
 */
class Book {
public:
    std::string isbn;    ///< The ISBN of the book.
    std::string title;   ///< The title of the book.
    std::string author;  ///< The author of the book.
    int copies;          ///< The number of copies available.

    /**
     * @brief Default constructor for the Book class.
     * Initializes the book with empty strings and 0 copies.
     */
    Book() : isbn(""), title(""), author(""), copies(0) {}

    /**
     * @brief Parameterized constructor for the Book class.
     * @param isbn The ISBN of the book.
     * @param title The title of the book.
     * @param author The author of the book.
     * @param copies The number of copies available.
     */
    Book(const std::string& isbn, const std::string& title, const std::string& author, int copies);
};

#endif // BOOK_H
