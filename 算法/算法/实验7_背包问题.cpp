//#include<iostream>
//using namespace std;
//#define N  10
//void Sort(int n, float v[], float w[]) {
//	float pan1, pan2, tempw, tempv;
//	for (int i = 1; i <= n; i++)
//		for (int j = i + 1; j <= n; j++) {
//			pan1 = v[i] / w[i];
//			pan2 = v[j] / w[j];
//			if (pan1 < pan2) {
//				tempw = w[i]; tempv = v[i];
//				w[i] = w[j]; v[i] = v[j];
//				w[j] = tempw; v[j] = tempv;
//			}
//		}
//}
//void Knapsack(int n, float M, float v[], float w[], float x[]) {
//	int i;
//	float c;
//	Sort(n, v, w);
//	for (i = 1; i <= n; i++)
//		x[i] = 0;
//	c = M;
//	for (i = 1; i <= n; i++) {
//		if (w[i] > c) break;
//		x[i] = 1;
//		c -= w[i];
//	}
//	if (i <= n) x[i] = c / w[i];
//}
//int main() {
//	float M = 20;
//	float w[] = { 0, 18, 15, 10 };
//	float v[] = { 0, 25, 24, 15 };
//	float x[N];
//	cout << "�����������ɵ�����Ϊ��" << M << endl;
//	cout << "δ�����װ��Ʒ�������ͼ�ֵ�ֱ�Ϊ��" << endl;
//	for (int i = 1; i <= 3; i++)
//		cout << "[" << i << "]:(" << w[i] << "," << v[i] << ")" << endl;
//	Knapsack(3, M, v, w, x);
//	cout << "������װ��Ʒ�������ͼ�ֵ�ֱ�Ϊ��" << endl;
//	for (int i = 1; i <= 3; i++)
//		cout << "[" << i << "]:(" << w[i] << "," << v[i] << ")" << endl;
//	cout << "ѡ��װ�µ���Ʒ�������£�" << endl;
//	for (int i = 1; i <= 3; i++)
//		cout << "[" << i << "]:" << x[i] << endl;
//	return 0;
//}
