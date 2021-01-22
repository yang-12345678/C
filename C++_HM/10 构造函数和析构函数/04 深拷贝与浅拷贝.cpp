//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 的默认构造函数调用" << endl;
//	}
//	Person(int a, int height)
//	{
//		age = a;
//		h = new int(height);  // 堆区开辟的空间，程序不停就不释放，须由程序员手动释放
//		cout << "Person 的有参构造函数调用" << endl;
//	}
//
//	// 自己实现拷贝构造函数，解决浅拷贝带来的问题
//	Person(const Person& p)
//	{
//		cout << "Person 拷贝构造函数的调用" << endl;
//		age = p.age;
//		//h = p.h; // 编译器默认实现就是这行代码:浅拷贝
//		// 深拷贝操作
//		h = new int(*p.h);
//	}
//
//	~Person()
//	{
//		// 析构代码，将堆区开辟的数据进行释放
//	    if(h != NULL)
//		{ 
//			delete h;
//			h = NULL;
//		}
//
//		cout << "Person 的析构函数调用" << endl;
//	}
//	int age;
//	int* h; // 身高 
//
//};
//
//void test()
//{
//	Person p1(18, 160);
//
//	cout << "p1 的年龄：" << p1.age << "  身高为：" << *p1.h << endl;
//
//	Person p2(p1);  // 浅拷贝:堆区的内存被重复释放
//	cout << "p2 的年龄：" << p2.age << "  身高为：" << *p2.h << endl;
//	// 栈区，先进来的后释放
//
//}
//
//
//int main()
//{
//	test();
//
//	system("pause");
//
//	return 0;
//}