//#include <iostream>
//using namespace std;
//
//void swap(int i, int j, int arr[])
//{
//	int t;
//	t = arr[i];
//	arr[i] = arr[j];
//	arr[j] = t;
//}
//
//void quicksort(int p, int q, int arr[])
//{
//	if (p >= q)return;
//	int i = p, j = q + 1, key = arr[p];
//	while (1)
//	{
//		while (arr[++i] < key && i < q);
//		while (arr[--j] > key);
//		if (j <= i)
//			break;
//		swap(i, j, arr);
//	}
//	arr[p] = arr[j];
//	arr[j] = key;
//	quicksort(p, j - 1, arr);
//	quicksort(j + 1, q, arr);
//}
//
//int main()
//{
//	int arr[] = {4, 8, 3,2,5,6 };
//	cout << "ÅÅÐòÇ°:" << endl;
//	for (int i = 0; i < 6; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	quicksort(0, 5, arr);
//	cout << endl << "ÅÅÐòºó:" << endl;
//	for (int i = 0; i < 6; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}