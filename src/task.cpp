// Task.cpp
#include "Task.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

// Constructor
Task::Task(const std::string& taskTitle, bool isCompleted)
    : title(taskTitle), completed(isCompleted), xp(generateRandomXp()) {}

// Getters
std::string Task::getTitle() const {
    return title;
}

bool Task::isCompleted() const {
    return completed;
}

int Task::getXp() const {
    return xp;
}

// Setters
void Task::setCompleted(bool status) {
    completed = status;
}

// Generate random XP between 10 and 100
int Task::generateRandomXp() const {
    static std::random_device rd;  // Random device for seeding
    static std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<> dis(10, 100); // Range [10, 100]
    return dis(gen);
}

// Save task to a file
void Task::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app); // Append mode
    if (file.is_open()) {
        file << title << "|" << (completed ? "1" : "0") << "|" << xp << "\n";
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
    }
}

// Load task from a file line
Task Task::loadFromFile(const std::string& filename, const std::string& taskLine) {
    std::istringstream iss(taskLine);
    std::string title;
    bool completed;
    int xp;
    std::string temp;

    // Parse the line: title|completed|xp
    std::getline(iss, temp, '|');
    title = temp;
    iss >> completed;
    iss.ignore(1, '|'); // Skip the delimiter
    iss >> xp;

    return Task(title, completed);
}

// Display task
void Task::display() const {
    std::cout << (completed ? "[*] " : "[ ] ") << title << " (" << xp << " XP)\n";
}