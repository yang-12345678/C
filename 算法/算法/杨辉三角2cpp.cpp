//#include <iostream>
//using namespace std;
//
//// һά����ʵ��
//
//int main()
//{
//	int n;
//	int a[100];
//	cin >> n;
//	cout << 1 << endl << left;  // ��һ��
//
//	cout.width(4);
//	a[1] = a[2] = 1;  // �ڶ���
//	cout << a[1] << a[2] << left << endl;
//	for (int i = 3; i <= n; i++)
//	{
//		a[1] = a[i] = 1;
//		for (int j = i - 1; j > 1; j--)
//		{
//			a[j] = a[j] + a[j - 1];
//		}
//		for (int k = 1; k <= i; k++)
//		{
//			cout.width(4);
//			cout << a[k] << left;
//		}
//		cout << endl;
//	}
//	return 0;
//}