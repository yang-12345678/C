#include <iostream>
using namespace std;

// 成员属性设置私有
// 1、可以自己控制读写权限
// 2、对于写，可以检测数据的有效性

class Person
{
private:
	string name; // 可读可写
	int age;  // 只读
	string lover; // 只写

public:
	// 设置姓名
	void setName(string n)
	{
		name = n;
	}

	// 获取姓名
	string getName()
	{
		return name;
	}

	// 获取年龄
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

	p.setName("张三");
	cout << "姓名为：" << p.getName() << endl;

	cout << "年龄为：" << p.getAge() << endl;

	p.setLover("李四");
	system("pause");

	return 0;
}