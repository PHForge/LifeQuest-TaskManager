#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
private:
    std::string username; // User's pseudonym
    int level;           // User's current level
    int xp;              // User's current experience points

public:
    // Constructor
    User(const std::string& name = "Player", int lvl = 1, int exp = 0);

    // Getters
    std::string getUsername() const;
    int getLevel() const;
    int getXp() const;

    // Setters
    void setUsername(const std::string& name);

    // Save user data to a file
    void saveToFile(const std::string& filename) const;

    // Load user data from a file
    bool loadFromFile(const std::string& filename);

    // Display user information
    void display() const;

    // Add XP and handle level-up
    void addXp(int amount);
};

#endif