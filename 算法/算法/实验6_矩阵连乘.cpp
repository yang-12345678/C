//#include <iostream>
//using namespace std;
//
//int r[100];         //���˵ĸ�����Ĵ�С
//int com[100][100];  //com[i][j]��Сʱk��ֵ
//
//int course(int i, int j)
//{
//	int u, t, k;
//	/** i��j����򷵻�ֵ0   */
//	if (i == j)   return 0;
//	/** ����i��j���ڵ����   */
//	if (i == j - 1)
//	{
//		com[i][i + 1] = i;
//		return (r[i] * r[i + 1] * r[i + 2]);
//	}
//	/**  k=iʱ�ĵݹ���� */
//	u = course(i, i) + course(i + 1, j) + r[i] * r[i + 1] * r[j + 1];
//	com[i][j] = i;
//	/**  k=i+1 �� k=j-1 ʱ�ĵݹ���� */
//	for (k = i + 1; k < j; k++)
//	{
//		t = course(i, k) + course(k + 1, j) + r[i] * r[k + 1] * r[j + 1];
//		if (t < u)
//		{
//			u = t;
//			com[i][j] = k;
//		}
//	}
//	return u;
//}
//int main()
//{
//	int n, i, j;
//	printf("���������˾���ĸ���: ");
//	cin >> n;
//	printf("\n����������˾���Ĵ�С��");
//	for (i = 1; i <= n + 1; i++)
//		cin >> r[i];
//	printf("\n����������С�ļ�����=%d \n\n", course(1, n));
//	printf("����Ķ�ά����com[i][j]��¼�˾������˵���Ϸ�ʽ��");
//	for (i = 1; i <= n; i++)
//	{
//		printf("\n");
//		for (j = 1; j <= n; j++)
//		{
//			if (j >= i)
//				printf("com[%d][%d]=%d  ", i, j, com[i][j]);
//			else
//				printf("%13c", 32);  //13���ո� 
//		}
//	}
//	printf("\n");
//}
//
///*
//
//
//���������˾���ĸ���: 4
//
//����������˾���Ĵ�С��5 20 50 1 100
//
//����������С�ļ�����=1600
//
//����Ķ�ά����com[i][j]��¼�˾������˵���Ϸ�ʽ��
//com[1][1]=0  com[1][2]=1  com[1][3]=1  com[1][4]=3
//			 com[2][2]=0  com[2][3]=2  com[2][4]=3
//						  com[3][3]=0  com[3][4]=3
//									   com[4][4]=0
//*/
//
//
