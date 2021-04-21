#include <iostream>
using namespace std;

int f[10000];

int main()
{
	int s1, s2, s3;
	cout << "请输入三个骰子的面数（s1, s2, s3）：";
	cin >> s1 >> s2 >> s3;

	for (int i = 1;i <= s1;i++)
	{
		for (int j = 1; j <= s2; j++)
		{
			for (int k =1;k<=s3;k++)
			{ 
				f[i + j + k]++;
			}
		}
	}
	int max = 0;
	int s;
	for (int i = 1; i <= 10000; i++)
	{
		if (max < f[i])
		{
			max = f[i];
				s = i;
		}
	}

	cout << s << endl;


	system("pause");
	return 0;
}

// 2021.4.21
