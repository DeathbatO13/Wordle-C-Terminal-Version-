#pragma once
#include <string>

namespace utils {
    void to_upper(std::string& str);
    std::string get_square(char state);  // 'G', 'Y', 'X'
    void clear_screen();
}