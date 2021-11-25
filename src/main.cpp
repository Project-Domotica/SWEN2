#include "argh.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    argh::parser cmdl(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);
    bool verbose = cmdl["-v"];
    if(verbose)
        std::cout << "Hello" << std::endl;
}
