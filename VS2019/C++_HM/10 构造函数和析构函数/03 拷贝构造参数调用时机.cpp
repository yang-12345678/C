//#include <iostream>
//using namespace std;
//
//// ���������������ʱ��
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person ��Ĭ�Ϲ��캯������" << endl;
//	}
//
//	Person(int a)
//	{
//		age = a;
//		cout << "Person ���вι��캯������" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		cout << "Person �Ŀ������캯������" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person ��������������" << endl;
//	}
//
//	int age;
//};
//
//
//// 1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//void test1()
//{
//	Person p1(20);
//	Person p2(p1);
//
//	cout << "p2������" << p2.age << endl;
//}
//
//// 2��ֵ���ݵķ�ʽ������������ֵ
//void work(Person p)  // �βο�����ʵ�ε�ֵ�������˿�������
//{
//
//}
//
//void test2()
//{
//	Person p; // Ĭ��
//	work(p);
//}
//
//// 3��ֵ��ʽ���ؾֲ�����
//Person doWork()
//{
//	Person p1;
//	return p1;  // ����ʱ�ֲ�������ֵ�ķ�ʽ���أ����ǰ���ַ�������ֿ�����һ��
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