//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person ��Ĭ�Ϲ��캯������" << endl;
//	}
//	Person(int a, int height)
//	{
//		age = a;
//		h = new int(height);  // �������ٵĿռ䣬����ͣ�Ͳ��ͷţ����ɳ���Ա�ֶ��ͷ�
//		cout << "Person ���вι��캯������" << endl;
//	}
//
//	// �Լ�ʵ�ֿ������캯�������ǳ��������������
//	Person(const Person& p)
//	{
//		cout << "Person �������캯���ĵ���" << endl;
//		age = p.age;
//		//h = p.h; // ������Ĭ��ʵ�־������д���:ǳ����
//		// �������
//		h = new int(*p.h);
//	}
//
//	~Person()
//	{
//		// �������룬���������ٵ����ݽ����ͷ�
//	    if(h != NULL)
//		{ 
//			delete h;
//			h = NULL;
//		}
//
//		cout << "Person ��������������" << endl;
//	}
//	int age;
//	int* h; // ��� 
//
//};
//
//void test()
//{
//	Person p1(18, 160);
//
//	cout << "p1 �����䣺" << p1.age << "  ���Ϊ��" << *p1.h << endl;
//
//	Person p2(p1);  // ǳ����:�������ڴ汻�ظ��ͷ�
//	cout << "p2 �����䣺" << p2.age << "  ���Ϊ��" << *p2.h << endl;
//	// ջ�����Ƚ����ĺ��ͷ�
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