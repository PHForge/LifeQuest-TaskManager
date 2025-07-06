#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include "Task.hpp"
#include "User.hpp"
#include <vector>
#include <string>

class TaskManager {
private:
    User& user;                      // Reference to the user
    std::vector<Task> tasks;         // List of active tasks
    std::vector<Task> history;       // List of completed tasks
    const std::string tasksFilename; // File for active tasks
    const std::string historyFilename; // File for completed tasks

public:
    // Constructor
    TaskManager(User& u, const std::string& tasksFile = "tasks.txt", 
                const std::string& historyFile = "history.txt");

    // Add a new task
    void addTask(const std::string& title);

    // Mark a task as completed by index
    void completeTask(size_t index);

    // Load tasks from file
    void loadTasks();

    // Save tasks to file
    void saveTasks() const;

    // Load history from file
    void loadHistory();

    // Save history to file
    void saveHistory() const;

    // Display tasks with user info and separator
    void display() const;

    // Display history of completed tasks
    void displayHistory() const;

    // Get reference to user
    User& getUser() { return user; }

    // Get const reference to tasks (for checking if empty)
    const std::vector<Task>& getTasks() const { return tasks; }
};

#endif // TASK_MANAGER_HPP