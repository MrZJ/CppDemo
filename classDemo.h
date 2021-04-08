//
// Created by Lenovo on 2021/4/7.
//


#include <iostream>

using namespace std;

class classDemo {
public:
    classDemo() {
        cout << "class constructor worked" << endl;
    }

    int age;
    double score;

    double getScore() {
        return score;
    }

    ~classDemo() {
        cout << "class  ~classDemo worked" << endl;
    }


private:
    int num;
};
