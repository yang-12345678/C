//#include <iostream>
//using namespace std;
//int main()
//{
//	int data[50][50];       //存储原始信息
//	int decision[50][50];   //存储决策信息
//	/* 数组path[i][j] 存储data[i][j]选择路径,
//		取值为0 表示向左	 取值为1表示向右
//	*/
//	int path[50][50];
//	int i, j, n;
//	/** 输入数塔有多少行    */
//	cout << "请输入数塔有多少行：";
//	cin >> n;
//	/** 输入初始数据    */
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= i; j++)
//		{
//			/** 输入数塔中的数据    */
//			cin >> data[i][j];
//			/** 初始决策信息与原始数塔数据相同    */
//			decision[i][j] = data[i][j];
//			/** 置选择路径的初始值为0   */
//			path[i][j] = 0;
//		}
//	/** 动态规划过程的存储    */
//	for (i = n - 1; i >= 1; i = i - 1)
//		for (j = 1; j <= i; j = j + 1)
//		{
//			/* * 左结合     */
//			if (decision[i + 1][j] > decision[i + 1][j + 1])
//			{
//				decision[i][j] = decision[i + 1][j] + decision[i][j];
//				path[i][j] = 0;
//			}
//			/* * 右结合     */
//			else
//			{
//				decision[i][j] = decision[i + 1][j + 1] + decision[i][j];
//				path[i][j] = 1;
//			}
//		}
//	/** 动态规划过程结束  decision[1][1]为最大值    */
//	cout << "max=" << decision[1][1] << endl;
//	/** 根据path[i][j] 找出最优解路径  */
//	j = 1;
//	for (i = 1; i <= n - 1; i++)
//	{
//		cout << data[i][j] << " -> ";
//		j = j + path[i][j];
//	}
//	cout << data[n][j] << endl;
//}
