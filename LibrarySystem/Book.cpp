#include "Book.h"
#include <string>

/**
 * @brief Parameterized constructor for the Book class.
 * @param isbn The ISBN of the book.
 * @param title The title of the book.
 * @param author The author of the book.
 * @param copies The number of copies of the book.
 */
Book::Book(const std::string& isbn, const std::string& title, const std::string& author, int copies)
    : isbn(isbn), title(title), author(author), copies(copies) {}
