#include <string>
#include <cstring>
using namespace std;
// EnumSerialization is a Global Static Class which allows for 
// enum Type serialization for piping object Types between scripts.
class EnumSerialization {
public:
	EnumSerialization() = delete; // Prevent initialization
	
	template <typename T>
	static T deserialize( const string& );
	
	template <typename T>
	static void serializeAndPipe( T );
};

// Deserialize
template <typename T>
T EnumSerialization::deserialize( const string& serialized_data ) {
    T value;
    memcpy(&value, serialized_data.data(), sizeof(T)); // Copy the byte data back into the enum
    return value;
}

// SerializeAndPipe
template <typename T>
void EnumSerialization::serializeAndPipe( T value ) {
	// pipe to cout
    cout.write(reinterpret_cast<const char*>(&value), sizeof(value));
	cout.flush();
}