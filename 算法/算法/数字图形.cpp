//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a[100][100], n;
//	cin >> n;
//	int k = 1;
//	for(int i =1;i<=n;i++)
//		for (int j = 1; j <= n + 1 - i; j++)
//		{
//			a[i - 1 + j][j] = k;
//			k++;
//		}
//
//	for (int i = 1; i <= n; i++)
//	{ 
//		for (int j = 1; j <= i; j++)
//			cout << a[i][j];
//		cout << endl;
//	}
//	return 0;
//}