//// P90
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n, a[1000], i, k;
//	cout << "������n��ֵ��";
//	cin >> n;
//	
//	// ��һλͬѧ�ص����е�
//	for (i = 1; i <= n; i++)
//		a[i] = 0;
//
//	for (i = 2; i <= n; i++)
//	{
//		k = 1;
//		while (i * k <= n)
//		{
//			a[i * k] = 1 - a[i * k];
//			k++;
//		}
//	}
//
//	for (i = 1; i <= n; i++)
//	{
//		if (a[i] == 1)
//			cout << i << endl;
//	}
//	return 0;
//}