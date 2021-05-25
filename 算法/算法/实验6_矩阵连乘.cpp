//#include <iostream>
//using namespace std;
//
//int r[100];         //连乘的各矩阵的大小
//int com[100][100];  //com[i][j]最小时k的值
//
//int course(int i, int j)
//{
//	int u, t, k;
//	/** i和j相等则返回值0   */
//	if (i == j)   return 0;
//	/** 计算i和j相邻的情况   */
//	if (i == j - 1)
//	{
//		com[i][i + 1] = i;
//		return (r[i] * r[i + 1] * r[i + 2]);
//	}
//	/**  k=i时的递归调用 */
//	u = course(i, i) + course(i + 1, j) + r[i] * r[i + 1] * r[j + 1];
//	com[i][j] = i;
//	/**  k=i+1 到 k=j-1 时的递归调用 */
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
//	printf("请输入连乘矩阵的个数: ");
//	cin >> n;
//	printf("\n请输入各连乘矩阵的大小：");
//	for (i = 1; i <= n + 1; i++)
//		cin >> r[i];
//	printf("\n矩阵连乘最小的计算量=%d \n\n", course(1, n));
//	printf("下面的二维矩阵com[i][j]记录了矩阵连乘的组合方式：");
//	for (i = 1; i <= n; i++)
//	{
//		printf("\n");
//		for (j = 1; j <= n; j++)
//		{
//			if (j >= i)
//				printf("com[%d][%d]=%d  ", i, j, com[i][j]);
//			else
//				printf("%13c", 32);  //13个空格 
//		}
//	}
//	printf("\n");
//}
//
///*
//
//
//请输入连乘矩阵的个数: 4
//
//请输入各连乘矩阵的大小：5 20 50 1 100
//
//矩阵连乘最小的计算量=1600
//
//下面的二维矩阵com[i][j]记录了矩阵连乘的组合方式：
//com[1][1]=0  com[1][2]=1  com[1][3]=1  com[1][4]=3
//			 com[2][2]=0  com[2][3]=2  com[2][4]=3
//						  com[3][3]=0  com[3][4]=3
//									   com[4][4]=0
//*/
//
//
