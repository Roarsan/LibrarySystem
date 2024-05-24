#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "BorrowHistory.h"

class User {
public:
    int userID;
    std::string name;
    std::vector<BorrowHistory> borrowHistory;

    User() : userID(0), name("") {}  // Default constructor
    User(int userID, const std::string& name);
};

#endif // USER_H
