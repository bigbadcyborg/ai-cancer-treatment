#include "../../variableList/conclusionTypes.h"
#include <iostream>
#include <sstream>
#include <cstring> // for memcpy

using namespace std;

// Serialization function
template<typename T>
string serialize_enum(T value) {
    ostringstream oss;
    oss.write(reinterpret_cast<const char*>(&value), sizeof(value));
    return oss.str();
}

int main() {
    // Serialize the enum value
    ConclusionType conclusion = BRAIN_CANCER;
    string serialized_data = serialize_enum(conclusion);

    // Print the serialized byte stream in hex to cerr for debugging
    cerr << "Serialized Enum: ";
    for (unsigned char c : serialized_data) {
        cerr << hex << (int)c << " ";
    }
    cerr << endl;

    // Write the raw serialized data to cout (for piping to the next script)
    cout.write(serialized_data.data(), serialized_data.size());
    cout.flush();

    return 0;
}
