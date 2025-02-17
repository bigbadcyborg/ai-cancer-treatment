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
    Person person("Alice", 30);

    // Open a binary file for writing
    ofstream ofs("person.dat", ios::binary);
    if (!ofs) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    // Write the name length and name
    size_t name_length = person.name.size();
    ofs.write(reinterpret_cast<const char*>(&name_length), sizeof(name_length));
    ofs.write(person.name.c_str(), name_length);

    // Write the age
    ofs.write(reinterpret_cast<const char*>(&person.age), sizeof(person.age));

    ofs.close();
    return 0;
}
