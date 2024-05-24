#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "BorrowHistory.h"

/**
 * @class User
 * @brief Represents a user in the library system.
 */
class User {
public:
    int userID;                      ///< The ID of the user.
    std::string name;                ///< The name of the user.
    std::vector<BorrowHistory> borrowHistory; ///< The borrow history of the user.

    /**
     * @brief Default constructor for the User class.
     */
    User() : userID(0), name("") {}

    /**
     * @brief Parameterized constructor for the User class.
     * @param userID The unique identifier for the user.
     * @param name The name of the user.
     */
    User(int userID, const std::string& name);
};

#endif // USER_H
