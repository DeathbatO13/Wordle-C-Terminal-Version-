#include "Game.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include <algorithm>
#include <iostream>
#include <filesystem>

Game::Game() {

    std::filesystem::path exePath = std::filesystem::current_path();
    if (exePath.filename() == "build") {
        exePath = exePath.parent_path();
    }
    std::filesystem::path wordFile = exePath / "words" / "words.txt";

    if (!wordlist.load(wordFile.string())) {
        std::cerr << "Error: Failed to load word list from: " << wordFile << "\n";
        std::exit(1);
    }
    secret = wordlist.random_word();

}

void Game::run() {
    Renderer::show_welcome();

    while (history.size() < 6) {
        Renderer::show_board(history);

        std::string guess = InputHandler::get_guess();
        if (!wordlist.is_valid(guess)) {
            std::cout << "Invalid word.\n";
            continue;
        }

        std::string feedback = evaluate_guess(guess);
        history.emplace_back(guess, feedback);

        if (feedback == "GGGGG") {
            Renderer::show_board(history);
            Renderer::show_result(true, secret);
            return;
        }
    }

    Renderer::show_board(history);
    Renderer::show_result(false, secret);
}

std::string Game::evaluate_guess(const std::string& guess) {
    std::string feedback(5, 'X');
    std::string target = secret;
    std::vector<bool> used(5, false);

    // Green first
    for (int i = 0; i < 5; ++i) {
        if (guess[i] == target[i]) {
            feedback[i] = 'G';
            used[i] = true;
            target[i] = '*';
        }
    }

    // Yellow
    for (int i = 0; i < 5; ++i) {
        if (feedback[i] == 'G') continue;
        auto pos = target.find(guess[i]);
        if (pos != std::string::npos && !used[pos]) {
            feedback[i] = 'Y';
            used[pos] = true;
        }
    }
    return feedback;
}