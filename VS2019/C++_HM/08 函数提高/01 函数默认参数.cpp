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
//// ����Ĭ�ϲ���
//// ��������Լ��������ݣ������Լ������ݣ����û�У���ô����Ĭ��ֵ
//
//// ע������
//// 1�����ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴����Ҷ�������Ĭ��ֵ
//// 2������������ʵ��ֻ����һ����Ĭ�ϲ���
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