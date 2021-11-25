#include "argh.h"

#include <string>
#include <iostream>

#define HELP_STR "usage: sort [--help] [--verbose]\n\t<--algorithm <algorithm>> <args>\n\navailable algorithms\n\tbubble\n\tmerge\n\theap\n"

int main(int argc, char* argv[]) {
    argh::parser cmdl(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);
    bool verbose = cmdl["-v"];
    
    // if help was specified
    if (cmdl[{ "-h", "--help" }])
    {
        std::cout << HELP_STR;
        return 0;
    }

    // if no algorithm was specified
    if (!(cmdl({ "-a", "--algorithm" })))
    {
        std::cout << HELP_STR << std::endl;
        std::cout << "error: please specify an algorithm.";
        return 0;
    }
}
