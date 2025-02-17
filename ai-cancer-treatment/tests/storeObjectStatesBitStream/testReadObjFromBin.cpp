#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    // Overload << operator for easy output (optional)
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }
};

int main() {
    Person person;

    // Open a binary file for reading
    ifstream ifs("person.dat", ios::binary);
    if (!ifs) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    // Read the name length and name
    size_t name_length;
    ifs.read(reinterpret_cast<char*>(&name_length), sizeof(name_length));
    char* name_buffer = new char[name_length + 1];
    ifs.read(name_buffer, name_length);
    name_buffer[name_length] = '\0';  // Add null-terminator
    person.name = string(name_buffer);
    delete[] name_buffer;

    // Read the age
    ifs.read(reinterpret_cast<char*>(&person.age), sizeof(person.age));

    ifs.close();

    // Output the read object
    cout << person << endl;

    return 0;
}
