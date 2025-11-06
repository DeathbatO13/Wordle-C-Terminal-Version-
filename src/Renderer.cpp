#include "Renderer.hpp"
#include "Utils.hpp"
#include <iostream>

void Renderer::show_board(const std::vector<std::pair<std::string, std::string>>& history) {
    utils::clear_screen();
    std::cout << "════════════════════════\n";
    std::cout << "        WORDLE          \n";
    std::cout << "════════════════════════\n\n";

    for (int i = 0; i < 6; ++i) {
        if (i < history.size()) {
            const auto& [word, feedback] = history[i];
            for (size_t j = 0; j < 5; ++j) {
                std::cout << utils::get_square(feedback[j]);
            }
            std::cout << "\n";
        } else {
            std::cout << "⬜⬜⬜⬜⬜\n";
        }
    }
    std::cout << "\n";
}

void Renderer::show_welcome() {
    std::cout << "¡Welcome to Wordle!\n";
    std::cout << "Guess the 5-letter word in 6 attempts.\n\n";
}

void Renderer::show_result(bool won, const std::string& word) {
    if (won) {
        std::cout << "¡CONGRATULATIONS! You guessed: " << word << "\n";
    } else {
        std::cout << "GAME OVER. The word was: " << word << "\n";
    }
}