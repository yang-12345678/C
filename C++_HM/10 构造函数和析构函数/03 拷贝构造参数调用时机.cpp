//#include <iostream>
//using namespace std;
//
//// 拷贝构造参数调用时机
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 的默认构造函数调用" << endl;
//	}
//
//	Person(int a)
//	{
//		age = a;
//		cout << "Person 的有参构造函数调用" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		cout << "Person 的拷贝构造函数调用" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person 的析构函数调用" << endl;
//	}
//
//	int age;
//};
//
//
//// 1、使用一个已经创建完毕的对象来初始化一个新对象
//void test1()
//{
//	Person p1(20);
//	Person p2(p1);
//
//	cout << "p2的年龄" << p2.age << endl;
//}
//
//// 2、值传递的方式给函数参数传值
//void work(Person p)  // 形参拷贝了实参的值，调用了拷贝函数
//{
//
//}
//
//void test2()
//{
//	Person p; // 默认
//	work(p);
//}
//
//// 3、值方式返回局部对象
//Person doWork()
//{
//	Person p1;
//	return p1;  // 结束时局部变量按值的方式返回，不是按地址，所以又拷贝了一个
//}
//
//void test3()
//{
//	Person p = doWork();
//}
//
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//
//	system("pause");
//
//	return 0;
//}