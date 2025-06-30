/*
 * LifeQuest
 * Task manager that gamifies productivity by assigning random XP to tasks, allowing users to level up upon completion.
 *
 * Dev with passion by: PHForge
 * License: MIT License
 * Version: 0.0.1
 */

#include "user.hpp"
#include <iostream>
#include <string>

int main() {
    User user;
    const std::string filename = "user_data.txt";

    // Check if user data exists
    if (!user.loadFromFile(filename)) {
        // First launch: prompt for username
        std::string username;
        std::cout << "Welcome! Please enter your username: ";
        std::getline(std::cin, username);
        user.setUsername(username);
        user.saveToFile(filename);
    }

    // Display user information
    user.display();

    getchar(); // Wait for user input before exiting

    return 0;
}