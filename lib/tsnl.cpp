#include "tsnl.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to execute a command to compile TypeScript
int cmdd(string& arg) {
    // Check if the argument ends with ".ts" and remove it if present
    if (arg.size() > 3 && arg.substr(arg.size() - 3) == ".ts") {
        arg = arg.substr(0, arg.size() - 3);
    }

    // Construct the command string for tsc
    string cmd = "tsc " + arg + ".ts";

    // Execute the tsc command
    int result = system(cmd.c_str());

    // Check if the tsc command was successful
    if (result == -1) {
        cerr << "Error: Failed to execute the tsc command." << endl;
        return 1;
    }

    return 0;
}

// Function to run the Node.js command
int run_node(const string& arg) {
    string nodecmd = "node " + arg + ".js";
    int result = system(nodecmd.c_str());

    if (result == -1) {
        cerr << "Error: Failed to execute the node command." << endl;
        return 1;
    }

    return 0;
}

// Function to delete the generated JavaScript file
int delete_file(const string& arg) {
    string deletecmd = "del " + arg + ".js";
    int result = system(deletecmd.c_str());

    if (result == -1) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return 1;
    }

    return 0;
}
