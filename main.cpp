#include <iostream>
#include <string>
#include "lib/tsnl.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Check if the correct amount of arguments are taken
    if (argc != 2) {
        cerr << "Usage: tsnode <arg> (file extension is optional)" << std::endl;
        return 1;
    }

    // Convert argv[1] to a string
    string arg = argv[1];

    // Call the cmdd function from the library
    int cmdd_result = cmdd(arg);

    // Check the result of cmdd
    if (cmdd_result != 0) {
        cerr << "cmdd function failed. Exiting program." << endl;
        return cmdd_result;
    }

    // Call the node execution function
    int noderesult = run_node(arg);

    // Check if the node command was successful
    if (noderesult != 0) {
        cerr << "Error: Failed to execute the node command." << endl;
        return noderesult;
    }

    // Call the delete function
    int deleteresult = delete_file(arg);

    // Check if the delete command was successful
    if (deleteresult != 0) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return deleteresult;
    }

    return 0;
}
