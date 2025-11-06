#pragma once
#include "WordList.hpp"
#include <string>
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    WordList wordlist;
    std::string secret;
    std::vector<std::pair<std::string, std::string>> history;

    std::string evaluate_guess(const std::string& guess);
};