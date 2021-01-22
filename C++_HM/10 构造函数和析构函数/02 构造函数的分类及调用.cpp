//#include <iostream>
//using namespace std;
//
//// 按参数分类：有参构造，无参构造（默认构造）
//// 按类型分类：普通构造，拷贝构造
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 的无参构造函数的调用" << endl;
//	}
//
//	Person(int a)
//	{
//		age = a;
//		cout << "Person 的有参构造函数的调用" << endl;
//	}
//
//	// 拷贝构造函数
//	Person(const Person &p)
//	{
//		// 将传入对象的属性传给本对象
//		age = p.age;
//		cout << "Person 的拷贝构造函数的调用" << endl;
//	}
//
//	// 析构函数
//	~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
//	}
//
//	int age;
//};
//
//// 调用
//void test()
//{
//	// 括号法
//	//Person P; // 默认构造函数
//	//Person P1(10); // 有参构造函数
//	//Person P2(P1); // 拷贝构造函数
//
//	// 注意事项：调用默认构造函数时，不要加 ()
//	// 下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
//	//Person P();
//
//	//cout << P1.age << endl;
//	//cout << P2.age << endl;
//
//	// 显示法
//	//Person p1;  // 默认构造
//	//Person p2 = Person(10); // 有参构造
//	//Person p3 = Person(p2); // 拷贝构造
//
//	//Person(10); // 匿名对象 特点： 当前行执行结束后，系统会立即回收掉匿名对象
//
//	// 注意事项：不要利用拷贝构造函数 初始化匿名对象
//	//Person(p1);// 错误写法，编译器会将改行代码等价于 Person p1;  重定义
//
//	// 隐式转换法
//	Person p1 = 10;  // 相当于 Person p1 = Person(10);
//	Person p2 = p1;
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//
//	return 0;
//}