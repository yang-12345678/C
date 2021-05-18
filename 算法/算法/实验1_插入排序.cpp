//#include<iostream>
//using namespace std;
//void InsertSort(int a[], int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i] < a[i - 1])
//		{
//			int j = i -  1;
//			int x = a[i];
//			while (j > -1 && x < a[j])
//			{
//				a[j + 1] = a[j];
//				j--;
//			}
//			a[j + 1] = x;
//		}
//		cout << i << ":  ";
//		for (int k = 0; k < n; k++)
//			cout << a[k] << " ";
//		cout << endl;
//	}
//	
//}
//int main()
//{
//	int a[10] = { 10,2,8,6,7,9,5,3,1,2 };
//	cout << "插入排序过程如下：" << endl;
//	InsertSort(a, 10);
//	return 0;
//}