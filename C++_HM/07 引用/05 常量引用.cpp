#include <iostream>
using namespace std;

void show(const int &a)
{
	//a = 100; ��const ֮�󲻿��޸�
	cout << "val = " << a << endl;

}

int main()
{
	// �������ã������βΣ���ֹ�����
	int a = 10;
	// ����const ֮�󣬱������������޸�Ϊ��int temp = 10; const int &ref = temp;
	const int& ref = 10;  // ���ñ�����һ��Ϸ����ڴ�ռ�
	//ref = 20; // ����const ֮�󣬱�Ϊֻ���������޸�
	cout << "ref=" << ref << endl;
	show(a);
	cout << "a = " << a << endl;
	system("pause");

	return 0;
}