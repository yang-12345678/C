//#include <iostream>
//using namespace std;
//int main()
//{
//	int data[50][50];       //�洢ԭʼ��Ϣ
//	int decision[50][50];   //�洢������Ϣ
//	/* ����path[i][j] �洢data[i][j]ѡ��·��,
//		ȡֵΪ0 ��ʾ����	 ȡֵΪ1��ʾ����
//	*/
//	int path[50][50];
//	int i, j, n;
//	/** ���������ж�����    */
//	cout << "�����������ж����У�";
//	cin >> n;
//	/** �����ʼ����    */
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= i; j++)
//		{
//			/** ���������е�����    */
//			cin >> data[i][j];
//			/** ��ʼ������Ϣ��ԭʼ����������ͬ    */
//			decision[i][j] = data[i][j];
//			/** ��ѡ��·���ĳ�ʼֵΪ0   */
//			path[i][j] = 0;
//		}
//	/** ��̬�滮���̵Ĵ洢    */
//	for (i = n - 1; i >= 1; i = i - 1)
//		for (j = 1; j <= i; j = j + 1)
//		{
//			/* * ����     */
//			if (decision[i + 1][j] > decision[i + 1][j + 1])
//			{
//				decision[i][j] = decision[i + 1][j] + decision[i][j];
//				path[i][j] = 0;
//			}
//			/* * �ҽ��     */
//			else
//			{
//				decision[i][j] = decision[i + 1][j + 1] + decision[i][j];
//				path[i][j] = 1;
//			}
//		}
//	/** ��̬�滮���̽���  decision[1][1]Ϊ���ֵ    */
//	cout << "max=" << decision[1][1] << endl;
//	/** ����path[i][j] �ҳ����Ž�·��  */
//	j = 1;
//	for (i = 1; i <= n - 1; i++)
//	{
//		cout << data[i][j] << " -> ";
//		j = j + path[i][j];
//	}
//	cout << data[n][j] << endl;
//}
