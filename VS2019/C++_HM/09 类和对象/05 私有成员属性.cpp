#include <iostream>
using namespace std;

// ��Ա��������˽��
// 1�������Լ����ƶ�дȨ��
// 2������д�����Լ�����ݵ���Ч��

class Person
{
private:
	string name; // �ɶ���д
	int age;  // ֻ��
	string lover; // ֻд

public:
	// ��������
	void setName(string n)
	{
		name = n;
	}

	// ��ȡ����
	string getName()
	{
		return name;
	}

	// ��ȡ����
	int getAge()
	{
		age = 0;
		return age;
	}

	void setLover(string n)
	{
		lover = n;
	}
	
};

int main()
{
	Person p;

	p.setName("����");
	cout << "����Ϊ��" << p.getName() << endl;

	cout << "����Ϊ��" << p.getAge() << endl;

	p.setLover("����");
	system("pause");

	return 0;
}