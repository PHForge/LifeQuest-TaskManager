#include "user.hpp"
#include <fstream>
#include <iostream>

// Constructor
User::User(const std::string& name, int lvl, int exp)
    : username(name), level(lvl), xp(exp) {}

// Getters
std::string User::getUsername() const {
    return username;
}

// Get current level and experience points
int User::getLevel() const {
    return level;
}

// Get current experience points
int User::getXp() const {
    return xp;
}

// Setters
void User::setUsername(const std::string& name) {
    username = name;
}

// Save user data to a file
void User::saveToFile(const std::string& filename) const {
    std::ofstream file("data/" + filename);
    if (file.is_open()) {
        file << username << "\n" << level << "\n" << xp << "\n";
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
    }
}

// Load user data from a file
bool User::loadFromFile(const std::string& filename) {
    std::ifstream file("data/" + filename);
    if (file.is_open()) {
        std::getline(file, username);
        file >> level >> xp;
        file.close();
        return true;
    }
    return false;
}

// Display user information
void User::display() const {
    std::cout << "User: " << username << " | Level: " << level << " | XP: " << xp << "\n";
}

// Add XP and handle level-up
void User::addXp(int amount) {
    xp += amount;
    // Level up when XP reaches 100
    while (xp >= 100) {
        xp -= 100;
        level++;
        std::cout << "Congratulations! You leveled up to Level " << level << "!\n";
    }
}