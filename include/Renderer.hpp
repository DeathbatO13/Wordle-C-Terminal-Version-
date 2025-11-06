#pragma once
#include <string>
#include <vector>

class Renderer {
public:
    static void show_board(const std::vector<std::pair<std::string, std::string>>& history);
    static void show_welcome();
    static void show_result(bool won, const std::string& word);
};