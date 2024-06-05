#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // Check if the correct amount of arguments are taken
    if (argc != 2) {
        cerr << "Usage: tsnode.exe <arg> (dont add the file extension)" << std::endl;
        return 1;
    }

    // Construct the command string
    string cmd = "tsc ";
    cmd += argv[1];
    cmd += ".ts";

    // Execute the command
    int result = system(cmd.c_str());

    // Check if the command was successful
    if (result == -1) {
        cerr << "Error: Failed to execute the command." << endl;
        return 1;
    }

    // Construct the command string
    string nodecmd = "node ";
    nodecmd += argv[1];
    nodecmd += ".js";

    // Execute the command
    int noderesult = system(nodecmd.c_str());

    // Check if the command was successful
    if (noderesult == -1) {
        cerr << "Error: Failed to execute the command." << endl;
        return 1;
    }

    // Construct the command string
    string deletecmd = "del ";
    deletecmd += argv[1];
    deletecmd += ".js";

    // Execute the command
    int deleteresult = system(deletecmd.c_str());

    // Check if the command was successful
    if (deleteresult == -1) {
        cerr << "Error: Failed to execute the command." << endl;
        return 1;
    }

    return 0;
}