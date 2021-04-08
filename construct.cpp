//
// Created by Lenovo on 2021/4/8.
//
#include <iostream>

using namespace std;

class Person {
public:
    Person(string name) {
        cout << "Person" << endl;
        this->name = new string(name);
    }

    string *name;
    int age;

    bool operator==(const Person &p) const {
        return *(this->name) == *p.name;
    }

    void operator()(const string &str) {
        cout << str << endl;
    }

    ~Person() {
        cout << "~Person" << endl;
        if (name != NULL) {
            delete name;
            name = NULL;
        }
    }
};

void print(const Person &p) {
    cout << *p.name << endl;
}

int main() {
    Person p("zj");
    Person p2("zj");
    cout << "p==p1?" << p.operator==(p2) << endl;
    cout << sizeof(bool) << endl;
    print(p);
    p2.operator()("test  () жиди");
    p2("test2  () жиди");
    return -1;
}