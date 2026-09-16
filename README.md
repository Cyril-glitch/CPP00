*This project has been created as part of the 42 curriculum by cycolonn.*

# 📜 C++ Module 00 - Introduction to C++

## 📖 1. Description
**CPP00** is the introductory module of the 42 C++ curriculum. Its purpose is to transition from procedural C programming to basic object-oriented concepts, namespace organization, standard input/output streams, and class encapsulation.

This project is composed of two exercises:

- `ex00` (`Megaphone`) introduces C++ standard streams (`std::cout`) and string manipulation.
- `ex01` (`My Awesome PhoneBook`) focuses on class design, member functions, private attributes, data formatting, and simple user input parsing.

The overall goal is to build strong initial habits with standard C++ conventions, header structuring, and basic data encapsulation without manual dynamic allocations.

---

<br />

## 🚀 2. Instructions

Navigate to any exercise directory (`ex00` or `ex01`) and use the standard Makefile targets:

| Target | Description |
| :--- | :--- |
| `make` | Compiles the project using `c++` with `-Wall -Wextra -Werror -std=c++98`. |
| `make it` | Compiles and executes the binary immediately. |
| `make val` | Runs the binary under `valgrind` to verify memory integrity. |
| `make clean` / `fclean` / `re` | Standard 42 cleaning and recompilation rules. |

### Executables

Each exercise produces its own binary under the `bin/` directory:

```bash
cd ex00 && ./bin/megaphone "shhhhh... I think the students are asleep..."
cd ex01 && ./bin/phonebook
```

### Useful commands

```bash
make
make re
make clean
make fclean
```

---

<br />

## 🛠️ 3. Technical Choices & Learning Objectives
Each exercise was designed to introduce the fundamentals of the C++ standard library and class syntax.

---

<br />

* 🗣️ **Standard I/O Streams**: Replaced C-style `printf` and `scanf` with typed streams (`std::cin`, `std::cout`, `std::endl`).
* 📦 **Encapsulation & Scoping**: Implemented private attributes for `Contact` and public interfaces for `PhoneBook` to guarantee data integrity.
* 📏 **Data Formatting**: Utilized `<iomanip>` capabilities (`std::setw`) and manual string truncation to format fixed-width tabular displays.
* ⚙️ **42 Compliance**: Followed C++98 standards strictly, avoiding deprecated C functions where modern stream equivalents exist.

---

<br />

## 📚 4. Resources

* 📄 **Official Documentation**:
    * [C++ Reference - Standard Streams](https://en.cppreference.com/w/cpp/io) - Standard stream library documentation.
    * [42 C++ Modules Documentation](https://harm-smits.github.io/42docs/) - Overview of curriculum expectations.
* 🔗 **Concepts & Tutorials**:
    * [Classes and Access Specifiers](https://www.learncpp.com/cpp-tutorial/classes-and-access-specifiers/) - Guide to basic class architecture.
    * [Input with std::cin](https://www.learncpp.com/cpp-tutorial/input-with-cin-and-handling-invalid-input/) - Stream parsing and boundary validation.
