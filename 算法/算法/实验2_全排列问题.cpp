//#include <iostream>
//using namespace std;
//int sum = 0;
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Perm(int list[], int k, int m)
//{
//	if (k == m)  // 边界条件
//	{
//		for (int i = 0; i <= m; i++)
//			cout << list[i] << " ";
//		cout << endl;
//		sum++;
//	}
//	else
//	{
//		for (int i = k; i <= m; i++)
//		{
//			swap(list[i], list[k]);
//			Perm(list, k + 1, m);
//			swap(list[i], list[k]);
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	int a[100];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		a[i] = i + 1;
//	Perm(a, 0, n-1);
//	cout << "共有" << sum << "种排列!" << endl;
//}