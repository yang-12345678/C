#include <iostream>
using namespace std;

struct Person
{
	// 姓名
	string name;
	// 性别
	int sex;
	// 年龄
	int age;
	// 电话
	string number;
	// 住址
	string addr;
};

void showMenu()
{
	cout << "***************" << endl;
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

}