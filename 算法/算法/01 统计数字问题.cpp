// 习题 1-1 王晓东

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "请输入书的总页码数：";
	cin >> n;
	int f[10] = { 0 };  // 未赋值的元素自动赋值为0
	/*for (int i = 0; i < 10; i++)
		f[i] = 0;*/
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (j)
		{
			f[j % 10]++;
			j = j / 10;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << f[i] << endl;
	system("pause");
	return 0;
}