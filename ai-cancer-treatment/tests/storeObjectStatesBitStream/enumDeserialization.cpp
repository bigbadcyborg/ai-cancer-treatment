#include "../../variableList/conclusionTypes.h"
#include <iostream>
#include <cstring> // for memcpy

using namespace std;

// Deserialization function
template<typename T>
T deserialize_enum(const string& serialized_data) {
    T value;
    memcpy(&value, serialized_data.data(), sizeof(T)); // Copy the byte data back into the enum
    return value;
}

int main() {
    // Read serialized data from stdin (pipe input)
    string serialized_data;
    getline(cin, serialized_data, '\0');  // Read till null character

    // Deserialize the enum value back from the byte stream
    ConclusionType deserialized_conclusion = deserialize_enum<ConclusionType>(serialized_data);

    // Output the deserialized value (as an integer)
    cout << "Deserialized Enum Value: " << deserialized_conclusion << endl;
	
	if ( deserialized_conclusion == BRAIN_CANCER )
		cout << "Serialized Object Recovered: Brain Cancer" << endl;

    return 0;
}
