#include <iostream>

int main() {
    // Define ANSI color codes
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string WHITE = "\033[37m";

    // Print ASCII art entirely in red
    std::cout << RED << "                 .`''''.   .'''``.                \n";
    std::cout << RED << "                 `tttttt\\?xuuuuuu`                \n";
    std::cout << RED << "                 '(|\\\\tftruuurrrf`                \n";
    std::cout << RED << "                       .`<^.                      \n";
    std::cout << WHITE << "                                                  \n";
    std::cout << WHITE << "                 .III;`     `;III.                \n";
    std::cout << WHITE << "                 .llll:     :llll.                \n";
    std::cout << WHITE << "                 .llll:     :llll.                \n";
    std::cout << WHITE << "                 .lllll.    Illll.                \n";
    std::cout << WHITE << "                  \"llli];,:]>lll,                 \n";
    std::cout << WHITE << "                   `lli{{{{{>ll`                  \n";
    std::cout << WHITE << "                                \n";
    std::cout << RESET;

    return 0;
}
