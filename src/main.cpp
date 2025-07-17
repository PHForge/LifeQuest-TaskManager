/*
 * LifeQuest  
 * A simple task management application with xp and level system.
 *
 * Dev with passion by: PHForge
 * License: MIT License
 * Version: 0.1
 */

#include "User.hpp"
#include "TaskManager.hpp"
#include <iostream>
#include <string>
#include <limits>

// Clears input buffer to prevent issues with getline
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Displays menu and handles user input
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
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                std::string taskTitle;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskTitle);
                if (!taskTitle.empty()) {
                    taskManager.addTask(taskTitle);
                    std::cout << "Task added successfully!\n";
                } else {
                    std::cout << "Error: Task description cannot be empty.\n";
                }
                break;
            }
            case 2: {
                std::string newUsername;
                std::cout << "Enter new username: ";
                std::getline(std::cin, newUsername);
                if (!newUsername.empty()) {
                    taskManager.getUser().setUsername(newUsername);
                    taskManager.getUser().saveToFile("user_data.txt");
                    std::cout << "Username changed successfully!\n";
                } else {
                    std::cout << "Error: Username cannot be empty.\n";
                }
                break;
            }
            case 3: {
                taskManager.displayHistory();
                std::cout << "Press Enter to return to menu...";
                std::string dummy;
                std::getline(std::cin, dummy);
                break;
            }
            case 4: {
                taskManager.display();
                if (taskManager.getTasks().empty()) {
                    std::cout << "No tasks to complete.\n";
                    break;
                }
                std::cout << "Enter task number to complete: ";
                int taskIndex;
                if (!(std::cin >> taskIndex)) {
                    std::cout << "Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                if (taskIndex > 0 && static_cast<size_t>(taskIndex) <= taskManager.getTasks().size()) {
                    taskManager.completeTask(taskIndex - 1);
                    std::cout << "Task completed successfully!\n";
                } else {
                    std::cout << "Error: Invalid task number.\n";
                }
                break;
            }
            case 5:
                std::cout << "Goodbye!\n";
                return;
            default:
                std::cout << "Error: Please enter a number between 1 and 5.\n";
        }
        std::cout << "\n";
    }
}

int main() {
    User user;
    const std::string userFilename = "user_data.txt";

    // Load or create user
    if (!user.loadFromFile(userFilename)) {
        std::string username;
        std::cout << "Welcome! Please enter your username: ";
        std::getline(std::cin, username);
        if (username.empty()) {
            username = "Player";
        }
        user.setUsername(username);
        user.saveToFile(userFilename);
    }

    TaskManager taskManager(user, "tasks.txt", "history.txt");

    // First launch: prompt for first task
    if (taskManager.getTasks().empty()) {
        std::string taskTitle;
        std::cout << "Enter your first task: ";
        std::getline(std::cin, taskTitle);
        if (!taskTitle.empty()) {
            taskManager.addTask(taskTitle);
            std::cout << "First task added successfully!\n";
        }
    }

    // Start interactive menu
    displayMenu(taskManager);

    return 0;
}