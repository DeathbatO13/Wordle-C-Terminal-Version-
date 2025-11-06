#pragma once
#include <string>
#include <vector>
#include <unordered_set>

class WordList {
public:
    bool load(const std::string& filename);
    const std::string& random_word() const;
    bool is_valid(const std::string& word) const;

private:
    std::vector<std::string> target_words;
    std::unordered_set<std::string> valid_words;
};