//#include <iostream>
//using namespace std;
//
//int & test()
//{
//	int a = 10;
//	return a;
//}
//
//int& test2()
//{
//	static int a = 10;
//	return a;
//}
//
//int main()
//{
//	// 注意事项
//	// 1、不要返回局部变量的引用
//
//	int& ref = test();
//
//	cout << "ref = " << ref << endl;  // 第一次正确，编译器做了一次保留
//	cout << "ref = " << ref << endl;
//
//
//	// 2、函数的调用可以作为左值
//
//	int& ref2 = test2();
//	cout << "ref2 = " << ref2 << endl;
//	cout << "ref2 = " << ref2 << endl;
//
//	test2() = 1000;  // 如果函数的返回值是引用，那么函数调用可以作为左值
//	cout << "ref2 = " << ref2 << endl;
//	cout << "ref2 = " << ref2 << endl;
//
//
//	system("pause");
//
//	return 0;
//}