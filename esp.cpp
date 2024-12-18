#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <variant>
#include <cctype>
#include <stdexcept>
#include <functional>

// Define variable types for dynamic type storage
using VarType = std::variant<int, float, bool, std::string, std::monostate>;

// Variable storage mechanism
std::unordered_map<std::string, VarType> variables;

// Utility function to trim spaces
std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

// Mathematical expression evaluator
float evaluate_math_expression(const std::string &expr) {
    std::istringstream iss(expr);
    float result = 0;
    float num = 0;
    char op = '+';

    while (iss >> num) {
        switch (op) {
            case '+': result += num; break;
            case '-': result -= num; break;
            case '*': result *= num; break;
            case '/': 
                if (num != 0) {
                    result /= num;
                } else {
                    throw std::runtime_error("Division by zero!");
                }
                break;
        }
        iss >> op;
    }
    return result;
}

// Expression evaluation logic
VarType evaluate_expression(const std::string &expr) {
    // Direct variable fetch
    if (variables.find(expr) != variables.end()) {
        return variables[expr];
    }

    // Math expression fallback
    if (expr.find_first_of("+-*/") != std::string::npos) {
        return evaluate_math_expression(expr);
    }

    // Integer/float conversion
    if (isdigit(expr[0]) || expr[0] == '-') {
        return std::stoi(expr);
    } else if (expr.find('.') != std::string::npos) {
        return std::stof(expr);
    }

    // Handle boolean
    if (expr == "true") return true;
    if (expr == "false") return false;

    // Handle literal strings
    return expr;
}

// Handle dynamic echo command
void handle_echo(const std::string &content) {
    size_t start = 0;

    while (true) {
        size_t open_brace = content.find("{", start);
        if (open_brace == std::string::npos) {
            std::cout << content.substr(start) << std::endl;
            break;
        }

        size_t close_brace = content.find("}", open_brace);
        if (close_brace == std::string::npos) {
            std::cerr << "Malformed expression" << std::endl;
            break;
        }

        // Print text before opening brace
        std::cout << content.substr(start, open_brace - start);

        // Evaluate the expression
        std::string expr = content.substr(open_brace + 1, close_brace - open_brace - 1);
        VarType value = evaluate_expression(expr);

        // Dynamically resolve type and print
        if (std::holds_alternative<int>(value)) {
            std::cout << std::get<int>(value);
        } else if (std::holds_alternative<float>(value)) {
            std::cout << std::get<float>(value);
        } else if (std::holds_alternative<std::string>(value)) {
            std::cout << std::get<std::string>(value);
        } else if (std::holds_alternative<bool>(value)) {
            std::cout << (std::get<bool>(value) ? "true" : "false");
        }

        // Update pointer
        start = close_brace + 1;
    }
}

// Handle variable assignments
void handle_variable_assignment(const std::string &line) {
    std::istringstream iss(line);
    std::string keyword, var_type, identifier, eq_sign, value;

    iss >> keyword >> var_type >> identifier >> eq_sign >> value;

    if (keyword == "let" || keyword == "var" || keyword == "const") {
        if (var_type == "int") {
            variables[identifier] = std::stoi(value);
        } else if (var_type == "float") {
            variables[identifier] = std::stof(value);
        } else if (var_type == "string") {
            variables[identifier] = value;
        } else if (var_type == "boolean") {
            variables[identifier] = (value == "true");
        }
    }
}

// Command Executor
void execute_line(const std::string &line) {
    if (line.find("echo") == 0) {
        std::string content = line.substr(4);
        handle_echo(content);
    } else if (line.find("let") == 0 || line.find("var") == 0 || line.find("const") == 0) {
        handle_variable_assignment(line);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.esp>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        execute_line(trim(line));
    }

    file.close();
    variables.clear();
    return 0;
}
