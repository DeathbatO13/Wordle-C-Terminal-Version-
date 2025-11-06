#include "Utils.hpp"
#include <iostream>
#include <cctype>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <cstdlib>
#endif

namespace utils {
    void to_upper(std::string& str) {
        for (char& c : str) c = std::toupper(static_cast<unsigned char>(c));
    }

    std::string get_square(char state) {
        switch (state) {
            case 'G': return "🟩";
            case 'Y': return "🟨";
            case 'X': return "⬜";
            default:  return "⬛";
        }
    }

    void clear_screen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
}