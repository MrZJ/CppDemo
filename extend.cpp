//
// Created by Lenovo on 2021/4/8.
//
#include <iostream>

using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal creat" << endl;
    }

    int sex;

    virtual void eat(string food) {
        cout << "Animal eat" << food << endl;
    }

    virtual void move() {
        cout << "move" << endl;
    }

    ~Animal() {
        cout << "Animal destroy" << endl;
    }
};

enum Sex {
    M = 1,
    W = 0
};

class Dog : virtual public Animal {
public:

    Dog() {
        cout << "Dog creat" << endl;
    }

    void eat(string food) override {
        cout << "Dog eat" << food << endl;
    }

    ~Dog() {
        cout << "Dog destroy" << endl;
    }
};

class Person : virtual public Animal {
public:
    void move() override {
        cout << "Person move" << endl;
    }
};

class Monster : public Person, public Dog {

};

void test1() {
    Dog dog;
    dog.sex = Sex::M;
    dog.eat("shit");
    Monster monster;
    monster.sex;
    cout << "sex is =" << dog.sex << endl;
}

int main() {
    test1();
    return -1;
}