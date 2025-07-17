# Changelog

All notable changes to the LifeQuest project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.2] - 2025-07-17

### Added
- Initial project structure with `User`, `Task`, and `TaskManager` classes for managing a user, tasks, and task history using object-oriented programming (OOP).
- User management with persistent storage of username, level, and XP in `data/user_data.txt`.
- Task management with title, completion status, and random XP (10–100) per task, stored in `data/tasks.txt`.
- Task history to track completed tasks, stored in `data/history.txt`.
- Interactive console menu to add tasks, change username, view task history, complete tasks, and exit.
- Gamification system: Completing tasks earns XP, with 100 XP per level-up, updating user data.
- Detailed documentation with `README.md` including a professional **System Requirements** section with a table and setup instructions.
- MIT License file for open-source usage.
- `.gitignore` file to exclude generated files and executables.
- `CMakeLists.txt` for cross-platform build configuration, automatically creating the `data/` directory.
- Organized project structure with `src/` for source files and `data/` for persistent files.

### Changed
- Improved user interface with confirmation messages and robust error handling for invalid inputs.
- Moved file paths to `data/` directory for better organization.
- Added detailed comments in all source files for clarity.
- Updated `README.md` with a polished, professional layout, including badges and a detailed **System Requirements** section.
- Removed test suite from `main.cpp` to create a clean, production-ready version.
- Updated `CMakeLists.txt` to include all source files (`User.cpp`, `Task.cpp`, `TaskManager.cpp`) and support the `src/` directory structure.

### Fixed
- Corrected `std::getline` issue in `main.cpp` for proper input handling in the interactive menu.

## [0.1] - 2025-07-14

### Added
- Initial project structure with `User`, `Task`, and `TaskManager` classes for managing a user, tasks, and task history using object-oriented programming (OOP).
- User management with persistent storage of username, level, and XP in `data/user_data.txt`.
- Task management with title, completion status, and random XP (10–100) per task, stored in `data/tasks.txt`.
- Task history to track completed tasks, stored in `data/history.txt`.
- Interactive console menu to add tasks, change username, view task history, complete tasks, and exit.
- Gamification system: Completing tasks earns XP, with 100 XP per level-up, updating user data.
- Detailed documentation with `README.md` and a `.gitignore` file.
- Basic test suite in `main.cpp` to validate task addition, completion, and username changes.
- Organized project structure with `src/` for source files and `data/` for persistent files.

### Changed
- Improved user interface with confirmation messages and robust error handling for invalid inputs.
- Moved file paths to `data/` directory for better organization.
- Added detailed comments in all source files for clarity.

## [Unreleased]

### Planned
- Add option to delete or edit tasks.
- Implement task sorting by XP or creation date.
- Add task creation/completion timestamps.
- Export task history to JSON format.
- Enhance console output with colors (Windows-compatible).

---

## Notes
- This project was developed as a learning exercise for C++ and OOP, targeting a portfolio for job opportunities.
- Contributions or suggestions are welcome via GitHub issues or pull requests.