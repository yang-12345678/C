//// P90
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n, a[1000], i, k;
//	cout << "请输入n的值：";
//	cin >> n;
//	
//	// 第一位同学关掉所有灯
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