// Lab 08 - command-line driver for HVACController
//
//   hvac_cli A B C D     prints F for one input condition, e.g.  hvac_cli 1 1 0 0  ->  1
//   hvac_cli --all       prints all 16 conditions as "A B C D F", one per line
//
// Inputs may be written as 1/0, T/F or true/false.
// Exit code 0 on success, 2 on bad arguments.

#include <iostream>
#include <string>
#include "hvac_controller.hpp"

static bool parseBit(const std::string& s, bool& out)
{
    if (s == "1" || s == "T" || s == "t" || s == "true")  { out = true;  return true; }
    if (s == "0" || s == "F" || s == "f" || s == "false") { out = false; return true; }
    return false;
}

int main(int argc, char* argv[])
{
    HVACController controller;

    if (argc == 2 && std::string(argv[1]) == "--all") {
        for (int m = 15; m >= 0; --m) {
            bool a = m & 8, b = m & 4, c = m & 2, d = m & 1;
            std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' '
                      << controller.evaluateSmokePurge(a, b, c, d) << '\n';
        }
        return 0;
    }

    bool in[4];
    if (argc != 5 || !parseBit(argv[1], in[0]) || !parseBit(argv[2], in[1])
                  || !parseBit(argv[3], in[2]) || !parseBit(argv[4], in[3])) {
        std::cerr << "usage: hvac_cli A B C D   (each 1/0)\n"
                  << "       hvac_cli --all\n";
        return 2;
    }
    std::cout << controller.evaluateSmokePurge(in[0], in[1], in[2], in[3]) << '\n';
    return 0;
}
