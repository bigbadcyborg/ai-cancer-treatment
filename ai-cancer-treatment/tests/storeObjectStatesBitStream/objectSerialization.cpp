// install: sudo apt install nlohmann-json3-dev
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp> // Include nlohmann/json header 

using json = nlohmann::json;
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    // Convert to JSON
    json toJson() const {
        return json{{"name", name}, {"age", age}};
    }

    // Convert from JSON
    static Person fromJson(const json& j) {
        return Person(j.at("name").get<string>(), j.at("age").get<int>());
    }
};

int main() {
    Person person("Alice", 55);

    // Serialize to JSON string
    json jsonData = person.toJson();
    string serialized = jsonData.dump(); // Convert JSON to string

    // Write JSON string to a binary file
    ofstream ofs("person.dat", ios::binary);
    if (!ofs) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }
    size_t length = serialized.size();
    ofs.write(reinterpret_cast<const char*>(&length), sizeof(length)); // Store length
    ofs.write(serialized.c_str(), length); // Store data
    ofs.close();

    // Read from binary file
    ifstream ifs("person.dat", ios::binary);
    if (!ifs) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }
    size_t read_length;
    ifs.read(reinterpret_cast<char*>(&read_length), sizeof(read_length));

    string read_data(read_length, '\0');
    ifs.read(&read_data[0], read_length);
    ifs.close();

    // Deserialize JSON string to object
    json readJson = json::parse(read_data);
    Person deserialized_person = Person::fromJson(readJson);

    cout << "Deserialized Person: " << deserialized_person.name << ", " << deserialized_person.age << endl;

    return 0;
}
