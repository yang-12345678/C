//#include <iostream>
//using namespace std;
//
//// 现有 Phone, 后有 Person
//// 当其他类对象作为本类成员时，构造时候先构造类对象，再构造自身
//// 析构的顺序：与构造相反
//class Phone
//{
//public:
//	Phone(string name)
//	{
//		brand = name;
//		cout << "Phone 构造函数调用" << endl;
//	}
//	string brand; // 品牌
//};
//
//class Person
//{
//public:
//	// Phone ph = pName // 隐式转换法
//	Person(string na, string nam):name(na),ph(nam)
//	{
//		cout << "Person 构造函数调用" << endl;
//	}
//
//	// 姓名
//	string name;
//	// 手机
//	Phone ph;
//
//};
//
//void test()
//{
//	Person p("张三", "MAX");
//
//	cout << p.name << p.ph.brand << endl;
//}
//
//int main()
//{
//
//	test();
//
//	system("pause");
//
//	return 0;
//}