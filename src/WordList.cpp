#include "WordList.hpp"
#include "Utils.hpp"
#include <fstream>
#include <random>
#include <algorithm>

bool WordList::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;

    std::string word;
    target_words.clear();
    valid_words.clear();

    while (std::getline(file, word)) {
        utils::to_upper(word);
        if (word.length() == 5) {
            target_words.push_back(word);
            valid_words.insert(word);
        }
    }
    return !target_words.empty();
}

const std::string& WordList::random_word() const {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, target_words.size() - 1);
    return target_words[dist(rng)];
}

bool WordList::is_valid(const std::string& word) const {
    return valid_words.count(word) > 0;
}