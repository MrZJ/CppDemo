//
// Created by Lenovo on 2021/4/8.
//
#include <iostream>

using namespace std;

class Person {
public:
    int age;
    int score;

    //局部函数实现重载
    Person operator+(Person p) const {
        Person t{};
        t.age = this->age + p.age;
        t.score = this->score + p.score;
        return t;
    }
};

//全局函数实现重载
Person operator+(Person a, Person b) {
    Person tem{};
    tem.age = a.score + b.age;
    tem.score = a.score + b.score;
    return tem;
}

int main() {
    Person a = {10, 30};
    Person b = {20, 20};
    Person c = a.operator+(b);
    cout << "name is ：" << c.age << ",score is：" << c.score << endl;
    c = operator+(a, b);
    cout << "name is ：" << c.age << ",score is：" << c.score << endl;
    //简化
//    c = a + b;
    return -1;
}