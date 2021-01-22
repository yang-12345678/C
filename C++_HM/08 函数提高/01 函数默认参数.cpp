//#include <iostream>
//using namespace std;
//
//int func(int a, int b, int c)
//{
//	return a + b + c;
//}
//
//int func1(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
//
//// 函数默认参数
//// 如果我们自己传入数据，就用自己的数据，如果没有，那么就用默认值
//
//// 注意事项
//// 1、如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//// 2、函数声明和实现只能有一个有默认参数
//
//int func2(int a = 10, int b = 10);
//
//int func2(int a , int b )
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 10, b = 20, c = 30;
//	cout << func(a, b, c) << endl;
//	cout << func1(a) << endl;
//	cout << func1(10, 30) << endl;
//
//	cout << func2(10, 10) << endl;
//	cout << func2() << endl;
//	system("pause");
//	
//	return 0;
//}