//#include <iostream>
//using namespace std;
//
//// 访问权限
//// 1、public     公共权限  成员  类内可以访问  类外可以访问
//// 2、protected  保护权限  成员  类内可以访问  类外不可以访问  子类可以访问父类中的保护内容
//// 3、private    私有权限  成员  类内可以访问  类外不可以访问  子类不可以访问父类中的私有内容
//
//class Person
//{
//public:
//	string name;
//
//protected :
//	string car;
//	
//private:
//	int mima;  // 密码
//
//public:
//	void func()
//	{
//		name = "张三";
//		car = "拖拉机";
//		mima = 123456;
//	}
//};
//
//
//int main()
//{
//	Person p;
//
//	p.name = "李四";
//	//p.car = "奔驰";  // 保护内容外部不可访问
//	//p.mima = 12345678; // 私有内容也不可访问
//
//	system("pause");
//
//	return 0;
//}