//#include<iostream>
//using namespace std;
//int f[100001], maxx;//Ͱ��Ͱ�߽�
//int main()
//{
//	int i, j, k, s1, s2, s3;
//	cin >> s1 >> s2 >> s3;
//
//	//����ѭ�����𡤡���
//
//	for (i = 1; i <= s1; i++)
//	{
//		for (j = 1; j <= s2; j++)
//		{
//			for (k = 1; k <= s3; k++)
//			{
//				f[i + j + k]++;//����
//				maxx = max(maxx, i + j + k);//Ѱ��Ͱ����߽߱�
//			}
//		}
//	}
//	int maxl = 0, z;//maxl��Ͱ���Ĵ�����z��
//	for (i = 1; i <= maxx; i++)
//	{
//		//����̨
//		if (f[i] > maxl)
//		{
//			maxl = f[i];
//			z = i;//i���������ӵĺͣ�������
//		}
//	}
//	cout << z << endl;//���������
//	return 0;
//}