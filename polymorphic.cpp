//
// Created by Lenovo on 2021/4/8.
//多态
//
#include <iostream>

using namespace std;

class Animal {
public:
    virtual void speak() = 0;

    //利用虚析构可以解决父类指针释放子类资源不干净的问题
    //虚析构
    virtual ~Animal() {

    }
    //纯虚析构
//    virtual  ~Animal()=0;
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Dog speak" << endl;
    }

    ~Dog() {

    }
};

void doSpeak(Animal &animal) {
    animal.speak();
}

void test1() {
    cout << sizeof(Animal) << endl;
    cout << sizeof(Dog) << endl;
    Dog dog;
    doSpeak(dog);
}

int main() {
    test1();
    return -1;

}