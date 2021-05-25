//#include <iostream>
//using namespace std;
//int b[4] = { 1,2,3,4 };
//int sum = 0;
//
//void Perm2(int a[], int m, int n) {
//	if (m == 0) {
//		for (int i = 0; i < n; i++)
//			cout << a[i] << " ";
//		cout << endl;
//		sum++;
//	}
//	else
//		for (int j = 0; j < n; j++)
//		{
//		    if (a[j] == 0)
//		    {
//			a[j] = b[m-1];
//			Perm2(a, m - 1, n);
//			a[j] = 0;
//	    	}
//    	}
//}
//
//int main() {
//	int a[4], n = 4;
//
//	for (int i = 0; i < n; i++) a[i] = 0;
//	Perm2(a, n, n);
//	cout << "共有" << sum << "种排列！" << endl;
//}