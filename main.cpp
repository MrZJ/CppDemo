#include <iostream>
#include <vector>
#include "classDemo.h"

using namespace std;
//typedef ����������ȡ����   �ŵ㣺������ֲ
//��ʽ typedef �ɵ������� �µ�������
//exp:typedef int INT;
//exp: typedef struct my_student {
//    string name;
//    int age;
//} Student;
//���峣��
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

//c �Ķ�̬�ڴ����
//malloc(); �����ڴ棬������ڴ���Ҫ����Ա����free()�ͷ�
//calloc() �����ڴ棬��Ĭ��ֵ��������ڴ���Ҫ����Ա����free()�ͷ�
//realloc() ���·��䣬ԭ�е����ݻ��ڣ�������ڴ���Ҫ����Ա����free()�ͷ�
//free() �ֶ��ͷ��ڴ�
//alloca() ������ջ��������ִ���꣬���ڴ��Զ��ͷ�


    //����  ָ��=new ���� �ռ�
    int *pInt1 = new int(10);
    cout << *pInt1 << endl;
    delete pInt1;
    cout << &pInt1 << endl;
    //һά����
    int *p = new int[5];
    for (int i = 0; i < 5; ++i) {
        *(p + i) = i;
    }
    for (int i = 0; i < 5; ++i) {
        cout << *(p + i) << endl;
    }
    delete[] p;
    //��ά����
    int (*pp)[3] = new int[3][3];

//C++ ��̬�ڴ����
//new ��Ҫ���Ƿ������ڴ�ɹ��ж� NULL�ж�
//delete ��new���룬������delete�ͷţ�delete p ***p����ı�����new������׵�ַ*** ����p=NULL����ֹҰָ��ĳ���
    //ָ������ �� ����ָ��
    //ָ�����飺װ��ָ�������
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
    //����ָ�룺˵���˾���װ������ָ�������
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
//    MyStruct myStruct = {"zhangsan", 12}; //��������ռ�ռ�
    test_struct myStruct = {"zhangsan", 12};
    cout << "name is :" << myStruct.name << ",age is :" << myStruct.age << endl;
    auto *pDouble = new MyStruct;
    cout << "name is :" << &pDouble << "----" << sizeof(pDouble) << endl;
    cout << "name is :" << &(*pDouble) << "----" << sizeof(*pDouble) << endl;
    cout << "a+b=" << doInterface(isInterface, 20, 10) << "----" << endl;
    cout << "isInterface = " << sizeof(&isInterface) << "----" << endl;
    int a = 10;
    int &b = a;
    cout << "������" << a << "----" << b << endl;
    cout << "������" << &a << "----" << &b << endl;
}