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

    User(int userID, const std::string& name);
};

#endif // USER_H
