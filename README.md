# LifeQuest: Task Manager with Gamification 🏁​

**LifeQuest** is a console-based task management application written in C++ using object-oriented programming (OOP) principles. It allows users to manage tasks, mark them as completed, and earn experience points (XP) to level up, introducing a gamification element to motivate productivity. Data is persistently stored in text files, ensuring tasks and user progress are saved between sessions.

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Version](https://img.shields.io/badge/Version-0.1-brightgreen.svg)

<br>

## Features 📋

- **Task Management**: Create, complete, and view tasks with a simple console interface.
- **Gamification**: Earn random XP (10–100) for completing tasks, leveling up every 100 XP.
- **Persistent Storage**: Save user data (username, level, XP) and tasks in text files (`data/user_data.txt`, `data/tasks.txt`, `data/history.txt`).
- **Interactive Menu**: Navigate options to add tasks, change username, view completed task history, complete tasks, or exit.
- **Robust Error Handling**: Validates user inputs to prevent crashes and ensure a smooth experience.
- **Clean OOP Design**: Modular classes (`User`, `Task`, `TaskManager`) with clear separation of concerns.
- **Automated Tests**: Basic test suite to validate core functionalities (task creation, completion, and username changes).

<br>

## System Requirements ⚙️

The following components are required to build, run, or contribute to LifeQuest:

| Component          | Requirement                              | Notes                                      |
|--------------------|------------------------------------------|--------------------------------------------|
| **Language**       | C++17                                    | Core language used for the project, leveraging STL for file handling and random number generation |
| **Compiler**       | GCC (via MSYS2 UCRT64)                   | Ensure G++ is installed; other compilers like Clang or MSVC may work with CMake |
| **Libraries**      | Standard C++ Library (STL)               | No external libraries required; uses `<string>`, `<vector>`, `<fstream>`, `<random>`, etc. |
| **Build System**   | CMake 3.10 or higher                     | Used for cross-platform build configuration |
| **IDE/Editor**     | VS Code (recommended) or any C++-compatible IDE/terminal | Configured with `tasks.json` and `launch.json` for compilation and debugging |
| **Debugger**       | GDB (via MSYS2 UCRT64)                   | For debugging in VS Code                   |
| **Version Control**| Git                                      | Required to clone the repository           |
| **OS**             | Windows (tested with MSYS2 UCRT64, AZERTY keyboard) | CMake ensures cross-platform compatibility; UTF-8 terminal encoding recommended for proper character display |

> [!TIP]
> For an optimal setup on Windows, install [MSYS2 UCRT64](https://www.msys2.org/) and use the following command to install dependencies:
> ```bash
> pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-gdb
> ```
> On Linux/macOS, use package managers like `apt` or `brew` to install `g++`, `cmake`, and `git`. Ensure UTF-8 terminal encoding for compatibility with special characters.

<br>

## Installation </>

1. **Clone the Repository**:
  ```bash
	git clone https://github.com/your-username/lifequest.git
  cd lifequest
	```

2. **Build the project:**:
	```bash
	cmake --build .
	```

3. **Run the executable:**:
	- Windows: `./LifeQuest.exe`
	- Linux: `./LifeQuest`

<br>

## Project Structure 🗂️

```bash
lifequest/
├── header/
│   ├── User.hpp            # User class for username, level, and XP
│   ├── Task.hpp            # Task class for task details and XP
│   └── TaskManager.hpp     # Manages tasks and history
├── src/
│   ├── main.cpp            # Entry point and interactive menu
│   ├── User.cpp            # User class for username, level, and XP
│   ├── Task.cpp            # Task class for task details and XP
│   └── TaskManager.cpp     # Manages tasks and history
├── data/
│   ├── user_data.txt       # Stores username, level, and XP
│   ├── tasks.txt           # Stores active tasks
│   └── history.txt         # Stores completed tasks
├── CHANGELOG.md            # Tracks project changes
├── README.md               # Project documentation
├── .gitignore              # Ignores generated files
└── CMakeLists.txt          # Build configuration
```

<br>

## Contributing 🤝

Contributions are welcome! To contribute:

- Fork the repository.
- Create a new branch (`git checkout -b feature/your-feature`).
- Make your changes and commit them (`git commit -m "Add your feature"`).
- Push to the branch (`git push origin feature/your-feature`).
- Open a pull request on GitHub.

Please ensure your code follows the project's coding style and includes appropriate documentation.

<br>

## License 🧾

This project is licensed under the **MIT License** - see the LICENSE file for details.

<br>

## Crédits ☕

> Developed by PHForge. 
> Feel free to reach out via [GitHub](https://github.com/PHForge) for feedback or collaboration ideas!

> Special thanks ❤️ to my wife and son for their patience and love.