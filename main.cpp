#include <iostream>
#include <vector>
#include "classDemo.h"

using namespace std;
//typedef 给数据类型取别名   优点：易于移植
//格式 typedef 旧的类型名 新的类型名
//exp:typedef int INT;
//exp: typedef struct my_student {
//    string name;
//    int age;
//} Student;
//定义常量
#define PI 3.1415

int main() {
    /*  int *pInt;
      pInt = (int *) malloc(10 * sizeof(int));
  //    pInt = static_cast<int *>(calloc(10, 10 * sizeof(int)));
      for (int i = 0; i < 10; ++i) {
          *(pInt + i) = i;
          cout << *(pInt + i) << endl;
      }
      cout << "-------" << endl;
      pInt = static_cast<int *>(realloc(pInt, 20 * sizeof(int)));
      for (int i = 0; i < 20; ++i) {
          cout << *(pInt + i) << endl;
      }
      free(pInt);
      pInt = NULL;
      cout << "-------" << endl;*/

//    int *pInt1;
//    calloc(pInt1,44);

//c 的动态内存分配
//malloc(); 分配内存，申请的内存需要程序员调用free()释放
//calloc() 分配内存，有默认值，申请的内存需要程序员调用free()释放
//realloc() 重新分配，原有的数据还在，申请的内存需要程序员调用free()释放
//free() 手动释放内存
//alloca() 分配在栈区，方法执行完，则内存自动释放


    //变量  指针=new 类型 空间
    int *pInt1 = new int(10);
    cout << *pInt1 << endl;
    delete pInt1;
    cout << &pInt1 << endl;
    //一维数组
    int *p = new int[5];
    for (int i = 0; i < 5; ++i) {
        *(p + i) = i;
    }
    for (int i = 0; i < 5; ++i) {
        cout << *(p + i) << endl;
    }
    delete[] p;
    //多维数组
    int (*pp)[3] = new int[3][3];

//C++ 动态内存分配
//new 需要做是否申请内存成功判断 NULL判断
//delete 用new申请，必须用delete释放，delete p ***p保存的必须是new分配的首地址*** 并将p=NULL，防止野指针的出现
    //指针数组 和 数组指针
    //指针数组：装了指针的数组
    int *arr1[3];
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    arr1[0] = &a1;
    arr1[1] = &a2;
    arr1[2] = &a3;
    for (int i = 0; i < 3; ++i) {
        cout << *arr1[i] << endl;
    }
    //数组指针：说白了就是装了数组指针的数组
    int a[3][4] = {{12,  31,  341, 35},
                   {121, 321, 341, 33},
                   {121, 313, 341, 32}};
    int (*arr2)[4];
    arr2 = a;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << *(*(arr2 + i) + j) << endl;
        }
    }
    void test();
    test();
    auto d = new classDemo();
    delete d;
    system("pause");
    return 0;
}

typedef struct test_struct {
    string name;
    int age{};
} MyStruct;


int isInterface(int a, int b = 10) {
    return a + b;
}

int doInterface(int (isInterface(int, int)), int ia, int ib) {
    return isInterface(ia, ib);
}

void test() {
//    MyStruct myStruct = {"zhangsan", 12}; //声明了则占空间
    test_struct myStruct = {"zhangsan", 12};
    cout << "name is :" << myStruct.name << ",age is :" << myStruct.age << endl;
    auto *pDouble = new MyStruct;
    cout << "name is :" << &pDouble << "----" << sizeof(pDouble) << endl;
    cout << "name is :" << &(*pDouble) << "----" << sizeof(*pDouble) << endl;
    cout << "a+b=" << doInterface(isInterface, 20, 10) << "----" << endl;
    cout << "isInterface = " << sizeof(&isInterface) << "----" << endl;
    int a = 10;
    int &b = a;
    cout << "别名：" << a << "----" << b << endl;
    cout << "别名：" << &a << "----" << &b << endl;
}