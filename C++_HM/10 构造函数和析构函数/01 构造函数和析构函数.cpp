//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	// 1、构造函数：没有返回值，也不用写void,函数名 == 类名，有参数，可以重载
//	Person()
//	{
//		cout << "Person构造函数的调用" << endl;
//	}
//
//	// 2、析构函数：进行清理的操作，没有返回值，也不用写void,函数名 == 类名，名称前加 ~
//	//            没有参数，不能重载，对象销毁前自动调用析构函数，只会调用一次
//	~Person()
//	{
//		cout << "Person的析构函数调用" << endl;
//	}
//};
//
//void test()
//{
//	Person p;  // 在栈上的数据，test执行完毕后，释放这个对象
//}
//
//int main()
//{
//	//test();
//	Person p;
//
//	system("pause");
//
//	return 0;
//}
