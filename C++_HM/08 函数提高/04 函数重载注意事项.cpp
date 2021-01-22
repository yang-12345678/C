#include <iostream>
using namespace std;

// 函数重载的注意事项
// 1、引用作为重载的注意事项

void func(int &a)
{
    cout << "fun(int &a) 的调用" << endl;
}

void func(const int &a)
{
    cout << "func(int &a) const 调用" << endl;
}


// 2、函数重载遇到默认参数

void func2(int a, int b = 10)
{
    cout << "func2(int a, int b) 的调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 的调用" << endl;
}

int main()
{

    /*int a = 10;
    func(a);
    func(10);*/

    //func2(10);  // 出现二义性

    system("pause");

    return 0;
}