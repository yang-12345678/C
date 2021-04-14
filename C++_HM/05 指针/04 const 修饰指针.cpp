//#include <iostream>
//using namespace std;
//
//int main()
//{
//	// 1、const 修饰指针：常量指针
//	// 特点：指针的指向可以改，指针指向的值不可以改
//	int a = 10;
//	int b = 20;
//	
//	const int* p = &a;
//	//*p = 20; // 错误
//	p = &b;
//	//*p = 30; // 错误
//
//
//	// 2、const 修饰常量：指针常量
//	// 特点：指针的指向不可以改，指针指向的值可以改
//	int* const p2 = &a;
//	//p2 = &b; // 错误
//	*p2 = 100; 
//
//
//	// const 修饰指针和常量
//	// 特点：指针的指向不可以改，指针指向的值也不可以改
//	const int* const p3 = &a;
//	system("pause");
//
//	return 0;
//}