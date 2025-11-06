#pragma once
#include <string>

class InputHandler {
public:
    static std::string get_guess();
    static bool is_valid_input(const std::string& input);
};