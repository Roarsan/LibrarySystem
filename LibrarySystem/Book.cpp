#include "Book.h"

Book::Book(const std::string& isbn, const std::string& title, const std::string& author, int copies)
    : isbn(isbn), title(title), author(author), copies(copies) {}
