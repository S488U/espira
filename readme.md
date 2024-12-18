# Espira Programming Language 🚀

Welcome to **Espira**, a modern, versatile, and evolving programming language designed to be intuitive, lightweight, and powerful. Espira offers a scripting-like syntax with the potential to scale into a full-fledged programming language supporting both simplicity and robustness.

---

## 📜 Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Current Status](#current-status)
- [Installation & Usage](#installation--usage)
- [Advantages](#advantages)
- [Disadvantages](#disadvantages)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

Espira is a modern programming language that draws inspiration from scripting languages while maintaining flexibility for general-purpose programming. Its design philosophy is simplicity, modularity, and ease of learning, making it ideal for prototyping, automation, and system development.

Espira offers scripting capabilities (similar to languages like Python, JavaScript) while aiming to integrate advanced programming paradigms over time.

---

## Features

Here are the primary features of the Espira programming language:

- ✅ **Dynamic Typing**: No need to declare strict types unless specified.
- ✅ **Interpreted Nature**: Espira runs directly from scripts without compilation overhead.
- ✅ **Mathematical Expression Support**: Evaluate mathematical expressions on-the-fly.
- ✅ **Error Handling**: Built-in mechanisms for error handling during execution.
- ✅ **Simple & Readable Syntax**: Espira focuses on developer experience with minimal boilerplate.
- ✅ **Standard Utility Libraries**: Standard utilities such as string manipulation, math operations, and basic I/O.

---

## Current Status

**Espira is currently in active development**, transitioning from a lightweight scripting language to a fully-fledged programming language with:
- Support for modular programming.
- Integration of advanced programming paradigms (OOP, functional programming).
- Multi-threading, network support, and compiler optimizations in progress.

### Language Features Implemented
- Expression evaluation (arithmetic, boolean expressions).
- Variable declarations & assignments.
- Dynamic `echo` (printing) support.
- Parsing mathematical expressions and logical constructs.

---

## Installation & Usage

Follow these steps to get started:

### Prerequisites
1. **C++ Compiler**: Make sure you have **C++17 or higher** installed.
2. **Dependencies**: Standard C++ dependencies (`unordered_map`, `std::variant`, etc.).

---

### Build Process
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-repository-name>/espira.git
   cd espira
    ```
2. Compile the interpreter:
    ```
    g++ -std=c++17 -o espira main.cpp
    ```

3. Compile the interpreter:
    ```
    ./espira example.esp
    ```

### Usage

Write scripts using the `.esp` extension, e.g., `example.esp`. Below is an example:
```
let int x = 5
let float y = 6.8
echo "Hello, x is {x} and y is {y}"
echo "The result of 3 + 4 = 3"
```

Execute the script:
```
./espira example.esp
```

Output:
```
Copy code
Hello, x is 5 and y is 6.8
The result of 3 + 4 = 3
```

## Advantages

- Simplicity & Intuition: Minimal boilerplate code required, making it beginner-friendly.
- Interpreted Environment: No need for lengthy compilation processes for smaller scripts.
- Highly Scalable: Designed with extensibility in mind — can evolve into a full programming language over time.
- Dynamic Typing: Variables are dynamically typed, with automatic type conversion support.
- Cross-Platform: Based on standard C++, runs across platforms with minimal adjustments.

## Disadvantages

- Performance Overhead: Being an interpreted language adds runtime overhead compared to compiled languages.
- Limited Features: As of now, many programming paradigms (object-oriented programming, multithreading) are still being implemented.
- Learning Curve: While syntax is simple, new developers may struggle with debugging or extending features due to lack of full documentation.

## Examples

Below are some simple use-cases with Espira:

1. Variable Declaration:
    ```
    let int a = 10
    let float b = 2.5
    echo "Value of a: {a}, b: {b}"
    ```
2. Mathematical Expression:
    ```
    echo "3 + 4 = {3 + 4}"
    ```

3. Error Handling (planned feature)
    ```
    try {
        let int result = 10 / 0
    } catch (error) {
        echo "Division by zero encountered!"
    }
    ```

## Contributing

We welcome contributions! If you are interested in helping the Espira project grow, follow these steps:

1. Fork this repository.
2. Clone your forked repository to your local machine.
3. Create a branch with a meaningful name:
    ```
    git checkout -b feature/your-feature-name
    ```
4. Make changes and commit them.
5. Push your branch:
    ```
    git push origin feature/your-feature-name
    ```

6. Open a pull request.

We will review your contributions and merge them after thorough testing.

## License

This project is licensed under the [BSD 3-Clause License](https://opensource.org/licenses/BSD-3-Clause).

**Key Terms:**
- **Free to Use:** You are free to use, modify, and distribute this project for personal or non-commercial purposes.
- **Commercial Restrictions:** Redistribution or selling the software under your name or as a proprietary product is strictly prohibited without written permission from the original author.
- **No Misrepresentation:** You cannot represent this software as your own creation.

For complete license details, refer to the [BSD 3-Clause License](https://opensource.org/licenses/BSD-3-Clause).


## Contact
If you have questions, issues, or feedback, please reach out:

Email: shahabassabbu12@gmail.com

GitHub Issues: [https://github.com/espira/issues](https://github.com/S488U/espira/issues)


###  Build it. Test it. Evolve it. Espira is just the beginning of a new programming journey. Join the movement! 
