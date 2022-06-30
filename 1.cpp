#include <iostream>
#include <string>

using namespace std;

struct Person 
{
    string name;
    int age;
};

ostream& operator << (ostream &os, const Person &person)
{
    return os << person.name << " aged " << person.age << endl;
}

int main() 
{
    Person person;
    person.age = 17;
    person.name = "Vladimir";
    cout << person;
    return 0;
}