//// P134
//
//#include <iostream>
//using namespace std;
//
//// //O(nlogn)
////int main()
////{
////	int* a, i, j, n;
////	cout << "请输入n的值:";
////	cin >> n;
////    
////	a = (int *)malloc((n + 1)*sizeof(int));
////
////	for (i = 1; i <= n; i++)
////		a[i] = 1;  // 原本所有的锁是锁上的
////
////	for (i = 1; i <= n; i++)
////		for (j = i; j <= n; j = j + i)  // 从 i 开始，公差为i
////			a[j] = 1 - a[j];
////
////	for (i = 1; i <= n; i++)
////		if (a[i] == 0)
////			cout << i << endl;
////	return 0;
////}
//
//
//
//int main()
//{
//	int s, i, j, n;
//	cout << "请输入n的值：";
//	cin >> n;
//
//	for (i = 1; i <= n; i++)
//	{
//		s = 1;
//		for (j = 2; j <= i; j++)
//			if (i % j == 0)
//				s++;
//		if (s % 2 == 1)
//			cout << i << " is free." << endl;
//	}
//	return 0;
//}