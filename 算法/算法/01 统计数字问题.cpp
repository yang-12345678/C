// ϰ�� 1-1 ������

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "�����������ҳ������";
	cin >> n;
	int f[10] = { 0 };  // δ��ֵ��Ԫ���Զ���ֵΪ0
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