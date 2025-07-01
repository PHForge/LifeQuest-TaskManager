/*
 * LifeQuest
 * Task manager that gamifies productivity by assigning random XP to tasks, allowing users to level up upon completion.
 *
 * Dev with passion by: PHForge
 * License: MIT License
 * Version: 0.0.2
 */

// main.cpp
#include "User.hpp"
#include "Task.hpp"
#include <iostream>
#include <string>

int main() {
    User user;
    const std::string userFilename = "user_data.txt";
    const std::string tasksFilename = "tasks.txt";

    // Load or create user
    if (!user.loadFromFile(userFilename)) {
        // First launch: prompt for username
        std::string username;
        std::cout << "Welcome! Please enter your username: ";
        std::getline(std::cin, username);
        user.setUsername(username);
        user.saveToFile(userFilename);

        // Prompt for first task
        std::string taskTitle;
        std::cout << "Enter your first task: ";
        std::getline(std::cin, taskTitle);
        Task task(taskTitle);
        task.saveToFile(tasksFilename);
    }

    // Display user information
    user.display();

    // Create and display a test task
    Task testTask("Test task");
    testTask.display();

    getchar(); // Wait for user input before exiting
    std::cout << "Press Enter to exit..." << std::endl;

    return 0;
}