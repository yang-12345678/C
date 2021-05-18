//#include <iostream>
//using namespace std;
//
//// 二维数组实现
//
//int main()
//{
//	int n;
//	int i, j, a[100][100];
//	cin >> n;
//	cout << 1 << endl << left;
//	cout.width(4);
//	a[2][1] = a[2][2] = 1;
//	cout << a[2][1] << a[2][2] << endl << left;
//	for(i=3;i<=n;i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			if (j == i || j == 1)
//				a[i][j] = 1;
//			else
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//			cout.width(4);
//			cout << a[i][j] << left;
//		}
//
//		cout << endl;
//		
//	}
//
//	return 0;
//}