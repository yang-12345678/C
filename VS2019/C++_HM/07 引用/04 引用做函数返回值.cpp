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
//	// ע������
//	// 1����Ҫ���ؾֲ�����������
//
//	int& ref = test();
//
//	cout << "ref = " << ref << endl;  // ��һ����ȷ������������һ�α���
//	cout << "ref = " << ref << endl;
//
//
//	// 2�������ĵ��ÿ�����Ϊ��ֵ
//
//	int& ref2 = test2();
//	cout << "ref2 = " << ref2 << endl;
//	cout << "ref2 = " << ref2 << endl;
//
//	test2() = 1000;  // ��������ķ���ֵ�����ã���ô�������ÿ�����Ϊ��ֵ
//	cout << "ref2 = " << ref2 << endl;
//	cout << "ref2 = " << ref2 << endl;
//
//
//	system("pause");
//
//	return 0;
//}