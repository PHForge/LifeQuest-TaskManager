#include "TaskManager.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

// Constructor
TaskManager::TaskManager(User& u, const std::string& tasksFile, const std::string& historyFile)
    : user(u), tasksFilename("data/" + tasksFile), historyFilename("data/" + historyFile) {
    loadTasks();
    loadHistory();
}

// Add a new task
void TaskManager::addTask(const std::string& title) {
    tasks.emplace_back(title);
    saveTasks();
}

// Mark a task as completed by index
void TaskManager::completeTask(size_t index) {
    if (index < tasks.size()) {
        tasks[index].setCompleted(true);
        // Add XP to user
        user.addXp(tasks[index].getXp());
        history.push_back(tasks[index]);
        tasks.erase(tasks.begin() + index);
        saveTasks();
        saveHistory();
        user.saveToFile("user_data.txt"); // Save updated user data
    } else {
        std::cerr << "Error: Invalid task index.\n";
    }
}

// Load tasks from file
void TaskManager::loadTasks() {
    std::ifstream file(tasksFilename);
    if (file.is_open()) {
        tasks.clear(); // Clear existing tasks
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                tasks.push_back(Task::loadFromFile(tasksFilename, line));
            }
        }
        file.close();
    }
}

// Save tasks to file
void TaskManager::saveTasks() const {
    std::ofstream file(tasksFilename, std::ios::trunc); // Overwrite mode
    if (file.is_open()) {
        for (const auto& task : tasks) {
            task.saveToFile(tasksFilename);
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << tasksFilename << " for writing.\n";
    }
}

// Load history from file
void TaskManager::loadHistory() {
    std::ifstream file(historyFilename);
    if (file.is_open()) {
        history.clear(); // Clear existing history
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                history.push_back(Task::loadFromFile(historyFilename, line));
            }
        }
        file.close();
    }
}

// Save history to file
void TaskManager::saveHistory() const {
    std::ofstream file(historyFilename, std::ios::trunc); // Overwrite mode
    if (file.is_open()) {
        for (const auto& task : history) {
            task.saveToFile(historyFilename);
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << historyFilename << " for writing.\n";
    }
}

// Display tasks with user info and separator
void TaskManager::display() const {
    // Display user info
    user.display();

    // Display separator
    std::cout << std::string(50, '-') << "\n";

    // Display tasks
    if (tasks.empty()) {
        std::cout << "No tasks available. Add a new task!\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            tasks[i].display();
        }
    }
}

// Display history of completed tasks
void TaskManager::displayHistory() const {
    // Display user info
    user.display();

    // Display separator
    std::cout << std::string(50, '-') << "\n";

    // Display history
    if (history.empty()) {
        std::cout << "No completed tasks in history.\n";
    } else {
        std::cout << "Completed Tasks:\n";
        for (size_t i = 0; i < history.size(); ++i) {
            std::cout << i + 1 << ". ";
            history[i].display();
        }
    }
}

// Get task by index
const Task& TaskManager::getTask(size_t index) const {
    if (index < tasks.size()) {
        return tasks[index];
    }
    throw std::out_of_range("Invalid task index");
}