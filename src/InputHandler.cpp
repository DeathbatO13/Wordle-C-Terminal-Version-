#include "InputHandler.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>

std::string InputHandler::get_guess() {
    std::string input;
    while (true) {
        std::cout << "\n> ";
        std::cin >> input;
        utils::to_upper(input);

        if (is_valid_input(input)) {
            return input;
        }
        std::cout << "Invalid input. Please enter a 5-letter word.\n";
    }
}

bool InputHandler::is_valid_input(const std::string& input) {
    if (input.length() != 5) return false;
    return std::all_of(input.begin(), input.end(), [](char c) {
        return std::isalpha(static_cast<unsigned char>(c));
    });
}