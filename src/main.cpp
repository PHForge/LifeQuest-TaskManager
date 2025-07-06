// main.cpp
#include "User.hpp"
#include "TaskManager.hpp"
#include <iostream>
#include <string>
#include <limits>

// Function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to display menu and handle user input
void displayMenu(TaskManager& taskManager) {
    while (true) {
        // Display current tasks
        taskManager.display();

        // Display menu options
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a new task\n";
        std::cout << "2. Change username\n";
        std::cout << "3. View task history\n";
        std::cout << "4. Complete a task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";

        int choice;
        std::cin >> choice;
        clearInputBuffer(); // Clear buffer to handle subsequent getline

        switch (choice) {
            case 1: {
                // Add a new task
                std::string taskTitle;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskTitle);
                if (!taskTitle.empty()) {
                    taskManager.addTask(taskTitle);
                } else {
                    std::cout << "Task description cannot be empty.\n";
                }
                break;
            }
            case 2: {
                // Change username
                std::string newUsername;
                std::cout << "Enter new username: ";
                std::getline(std::cin, newUsername);
                if (!newUsername.empty()) {
                    taskManager.getUser().setUsername(newUsername);
                    taskManager.getUser().saveToFile("user_data.txt");
                } else {
                    std::cout << "Username cannot be empty.\n";
                }
                break;
            }
            case 3: {
                // View task history
                taskManager.displayHistory();
                std::cout << "Press Enter to return to menu...";
                std::string dummy;
                std::getline(std::cin, dummy); // Use a named variable
                break;
            }
            case 4: {
                // Complete a task
                taskManager.display();
                if (!taskManager.getTasks().empty()) {
                    std::cout << "Enter task number to complete: ";
                    int taskIndex;
                    std::cin >> taskIndex;
                    clearInputBuffer();
                    if (taskIndex > 0 && static_cast<size_t>(taskIndex) <= taskManager.getTasks().size()) {
                        taskManager.completeTask(taskIndex - 1); // Convert to 0-based index
                    } else {
                        std::cout << "Invalid task number.\n";
                    }
                }
                break;
            }
            case 5:
                // Exit
                std::cout << "Goodbye!\n";
                return;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
        std::cout << "\n";
    }
}

int main() {
    User user;
    const std::string userFilename = "user_data.txt";

    // Load or create user
    if (!user.loadFromFile(userFilename)) {
        // First launch: prompt for username
        std::string username;
        std::cout << "Welcome! Please enter your username: ";
        std::getline(std::cin, username);
        if (username.empty()) {
            username = "Player";
        }
        user.setUsername(username);
        user.saveToFile(userFilename);
    }

    TaskManager taskManager(user);

    // First launch: prompt for first task
    if (taskManager.getTasks().empty()) {
        std::string taskTitle;
        std::cout << "Enter your first task: ";
        std::getline(std::cin, taskTitle);
        if (!taskTitle.empty()) {
            taskManager.addTask(taskTitle);
        }
    }

    // Start interactive menu
    displayMenu(taskManager);

    return 0;
}