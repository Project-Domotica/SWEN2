#include "argh.h"

#include "heap_sort.h"
#include "bubble_sort.h"
#include "merge_sort.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

#define HELP_STR "usage: sort [--help] [--verbose]\n\t<--algorithm <algorithm>> <args>\n\navailable algorithms\n\tbubble\n\tmerge\n\theap\n"

void print_vector(std::vector<int> v)
{
    std::ostringstream ss;
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<int>(ss, ", "));
        ss << v.back();
    }
    std::cout << ss.str() << "\n";
}

bool check_number(std::string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

int main(int argc, char* argv[])
{
    // create argparser (argh)
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

    // create vector with args
    std::vector<int> args;
    for (auto& pos_arg : cmdl.pos_args())
    {
        if (check_number(pos_arg))
            args.push_back(std::stoi(pos_arg));
    }

    // string of the selected algorithm
    std::string selected_algorithm = static_cast<std::string>(cmdl({ "-a", "--algorithm" }).str());
    // to lowercase
    std::transform(selected_algorithm.begin(), selected_algorithm.end(), selected_algorithm.begin(), [](unsigned char c) { return std::tolower(c); });

    // check amount of ints
    if (args.size() < 2)
    {
        std::cout << HELP_STR << std::endl;
        std::cout << "error: please enter two or more integers to sort.";
        return 0;
    }

    // check algorithm
    if (selected_algorithm == "bubble")
    {
        // bubble
        bubbleSort(args);
        std::cout << "values sorted with bubble sort:" << std::endl;
        print_vector(args);
        return 0;
    }
    else if (selected_algorithm == "merge")
    {
        // merge
        mergeSort(args, 0, args.size() - 1);
        std::cout << "values sorted with merge sort:" << std::endl;
        print_vector(args);
        return 0;
    }
    else if (selected_algorithm == "heap")
    {
        // heap
        heapSort(args);
        std::cout << "values sorted with heap sort:" << std::endl;
        print_vector(args);
        return 0;
    }
    else
    {
        // invalid algorithm
        std::cout << HELP_STR << std::endl;
        std::cout << selected_algorithm << " is an invalid algorithm";
        return 0;
    }
    return EXIT_SUCCESS;
}
