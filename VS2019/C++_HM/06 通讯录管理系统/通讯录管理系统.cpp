#include <iostream>
using namespace std;

struct Person
{
	// ����
	string name;
	// �Ա�
	int sex;
	// ����
	int age;
	// �绰
	string number;
	// סַ
	string addr;
};

void showMenu()
{
	cout << "***************" << endl;
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
	cout << "***************" << endl;
}

int main()
{
	int select;
	while (true)
	{
		showMenu();

	    cin >> select;

	    switch (select)
	    {
		case 1: 
			break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

}