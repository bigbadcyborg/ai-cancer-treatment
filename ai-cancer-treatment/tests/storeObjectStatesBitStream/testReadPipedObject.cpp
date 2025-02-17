#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Command to run the external executable
    const char* cmd = "backwardChaining.exe";  // Adjust path if necessary
    
    // Run the command and capture the output
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        cerr << "Error: Could not open pipe." << endl;
        return 1;
    }

    // Read the output into a stringstream
    stringstream output;
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        output << buffer;
    }

    // Close the pipe
    fclose(pipe);

    // Get the serialized object (assuming it's a string for simplicity)
    string serializedData = output.str();

    // For now, just print the serialized data
    cout << "Received serialized data: " << endl;
    cout << serializedData << endl;

    // TODO: Deserialize the object if needed
    // This part depends on how the serialized object is formatted.
    // Example: If it's JSON, you could use a library like nlohmann/json to deserialize it.

    return 0;
}
