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
    string command = "tsc ";
    command += argv[1];
    command += ".ts";

    // Execute the command
    int result = system(command.c_str());

    // Check if the command was successful
    if (result == -1) {
        cerr << "Error: Failed to execute the command." << endl;
        return 1;
    }

    // Construct the command string
    string nodcmd = "node ";
    nodcmd += argv[1];
    nodcmd += ".js";

    // Execute the command
    int nodres = system(nodcmd.c_str());

    // Check if the command was successful
    if (nodres == -1) {
        cerr << "Error: Failed to execute the command." << endl;
        return 1;
    }

    // Construct the command string
    string delcmd = "del ";
    delcmd += argv[1];
    delcmd += ".js";

    // Execute the command
    int delres = system(delcmd.c_str());

    // Check if the command was successful
    if (delres == -1) {
        cerr << "Error: Failed to execute the command." << endl;
        return 1;
    }

    return 0;
}