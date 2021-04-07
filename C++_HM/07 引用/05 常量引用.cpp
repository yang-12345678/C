#include <iostream>
using namespace std;

void show(const int &a)
{
	//a = 100; 加const 之后不可修改
	cout << "val = " << a << endl;

}

int main()
{
	// 常量引用：修饰形参，防止误操作
	int a = 10;
	// 加上const 之后，编译器将代码修改为：int temp = 10; const int &ref = temp;
	const int& ref = 10;  // 引用必须引一块合法的内存空间
	//ref = 20; // 加入const 之后，变为只读，不可修改
	cout << "ref=" << ref << endl;
	show(a);
	cout << "a = " << a << endl;
	system("pause");

	return 0;
}