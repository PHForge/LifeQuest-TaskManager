#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
private:
    std::string title;   // Task description
    bool completed;      // Task status (true if completed, false otherwise)
    int xp;              // Experience points awarded for completing the task

public:
    // Constructor
    Task(const std::string& taskTitle, bool isCompleted = false);

    // Getters
    std::string getTitle() const;
    bool isCompleted() const;
    int getXp() const;

    // Setters
    void setCompleted(bool status);

    // Save task to a file
    void saveToFile(const std::string& filename) const;

    // Load task from a file (static method to create a task from file data)
    static Task loadFromFile(const std::string& filename, const std::string& taskLine);

    // Display task with [ ] or [*] format
    void display() const;

private:
    // Generate random XP between 10 and 100
    int generateRandomXp() const;
};

#endif