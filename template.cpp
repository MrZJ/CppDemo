//
// Created by Lenovo on 2021/4/8.
//模板
//
#include <iostream>

using namespace std;

template<typename T>
void mySwap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

class Person {
public:
    /*  bool operator==(Person &p) const {
          if (this->age == p.age) {
              return true;
          } else {
              return false;
          }
      }
  */
    int age;
};

template<class T>
bool mCompare(T &a, T &b) {
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

//模板重载
template<>
bool mCompare(Person &a, Person &b) {
    return a.age == b.age;
}

template<class T>
class Container {
public:
    T arr[100];
    int current;

    void remove(int a) {
        current--;
        cout << "删除元素" << a << endl;
    }

    void add(T a) {
        current++;
        cout << "添加元素" << a << endl;
    }

    void get(int p) {
        cout << "添加元素" << arr[p] << endl;
    }
};

template<class T_NAME, class T_AGE=int>
class Student {
public:
    T_NAME name;
    T_AGE age;
};

int main() {
    int a = 20;
    int b = 30;
    cout << a << "---" << b << endl;
    mySwap(a, b);
    cout << a << "---" << b << endl;
    double c = 20.11;
    double d = 30.33;
    cout << c << "---" << d << endl;
    mySwap(c, d);
    cout << c << "---" << d << endl;
    cout << c << "---" << d << endl;
    string str1 = "2131zj";
    string str2 = "1zj";
    cout << mCompare(str1, str2) << endl;
    Person p1 = {30};
    Person p2 = {20};
    cout << mCompare(p1, p2) << endl;
    Student<string> student = {"zj", 22};
    cout << "name is =" << student.name << ",age is =" << student.age << endl;
    return -1;
}
