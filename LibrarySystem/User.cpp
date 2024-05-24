#include "User.h"

/**
 * @brief Constructs a User object with a given userID and name.
 *
 * @param userID The unique identifier for the user.
 * @param name The name of the user.
 */
User::User(int userID, const std::string& name)
    : userID(userID), name(name) {}
