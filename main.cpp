#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // Check if the correct amount of arguments are taken
    if (argc != 2) {
        cerr << "Usage: tsnode <arg> (file extension is optional)" << std::endl;
        return 1;
    }

    // Convert argv[1] to a string
    string arg = argv[1];

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

    // Construct the command string for node
    string nodecmd = "node " + arg + ".js";

    // Execute the node command
    int noderesult = system(nodecmd.c_str());

    // Check if the node command was successful
    if (noderesult == -1) {
        cerr << "Error: Failed to execute the node command." << endl;
        return 1;
    }

    // Construct the command string for delete
    string deletecmd = "del " + arg + ".js";

    // Execute the delete command
    int deleteresult = system(deletecmd.c_str());

    // Check if the delete command was successful
    if (deleteresult == -1) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return 1;
    }

    return 0;
}
