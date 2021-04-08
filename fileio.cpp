//
// Created by Lenovo on 2021/4/8.
//  文件读写
//
#include <fstream>
#include <iostream>

using namespace std;

//写文件
void test01() {
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "my first file" << endl;
    ofs << "my first file";
    ofs << "my first file" << endl;
    ofs << "my first file" << endl;
    ofs.close();
}

//读文件
void test02() {
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (ifs.is_open()) {
        char buff[1024];
        //第一种方式  遇到空格也会当成一行
        /* while (ifs >> buff) {
             cout << buff << endl;
         }*/

        //第二种方式  每次读一行
        /*while (ifs.getline(buff,sizeof (buff))){
            cout << buff << endl;
        }*/

        //第三种 全局的函数
        string str;
        while (getline(ifs, str)) {
            cout << str << endl;
        }
        ifs.close();
    } else {
        cout << "open file fail" << endl;
    }
}

class Person {
public:
    char name[64];
    int age;
};

//写入二进制文件
void test03() {
    //1、添加头文件
    //2、创建流对象
    ofstream ofs;
    //3、打开文件
    ofs.open("test.txt", ios::out | ios::binary);
    //4、开始写入
    /*ofs << "姓名：张健" << endl;
    ofs << "性别：男" << endl;
    ofs << "职业：安卓开发" << endl;*/
    Person p = {"zhangsan", 22};
    ofs.write((const char *) &p, sizeof(Person));
    Person p1 = {"lisi", 33};
    ofs.write((const char *) &p1, sizeof(Person));
    //5、关闭流对象
    ofs.close();
}

//读取二进制文件
void test04() {
    ifstream ifs;
    ifs.open("test.txt", ios::in | ios::binary);
    if (ifs.is_open()) {
        Person p{};
        while (ifs.read((char *) &p, sizeof(Person))) {
            cout << p.name << p.age << endl;
        }
    } else {
        cout << "文件打开失败" << endl;
    }
    ifs.close();
}

int main() {
    test04();
    return -1;
}
