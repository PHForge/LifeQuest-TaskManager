// main.cpp
#include "User.hpp"
#include "TaskManager.hpp"
#include <iostream>
#include <string>

int main() {
    User user;
    const std::string userFilename = "user_data.txt";

    // Load or create user
    if (!user.loadFromFile(userFilename)) {
        // First launch: prompt for username
        std::string username;
        std::cout << "Welcome! Please enter your username: ";
        std::getline(std::cin, username);
        user.setUsername(username);
        user.saveToFile(userFilename);
    }

    TaskManager taskManager(user);

    // First launch: prompt for first task
    if (taskManager.getTasks().empty()) {
        std::string taskTitle;
        std::cout << "Enter your first task: ";
        std::getline(std::cin, taskTitle);
        taskManager.addTask(taskTitle);
    }

    // Display tasks
    taskManager.display();

    // Test completing a task (for demonstration)
    if (!taskManager.getTasks().empty()) {
        std::cout << "Completing first task for testing...\n";
        taskManager.completeTask(0);
        taskManager.display();
    }

    getchar(); // Wait for user input before exiting
    std::cout << "Press Enter to exit..." << std::endl;

    return 0;
}