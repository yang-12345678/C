////最优装载问题//输入物体的个数n及重量Wi,及能承受的最大装载重量C
////输出最多的装载数量
//
//#include <iostream>
//#include <algorithm>//为了使用排序函数sort()从小到大排序
//
//#define NUM 100
//using namespace std;
//double weight[NUM];
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int n;//物体的数量
//	int c;//最大载重量
//	cout << "请输入物体的数量n" << endl;
//	cin >> n;
//	cout << "请输入船最大的载重量c" << endl;
//	cin >> c;
//	cout << "依次输入每个物品的重量: 用空格分开" << endl;
//	for (int i = 0; i < n; i++) {
//		cin >> weight[i];//
//	}
//	sort(weight, weight + n);//从小到大排列
//	//运用贪心算法求解
//	int ans = 0;//记录加载的个数
//	double weight_num = 0.0;//记录加载的重量
//
//	//开始时候想用while来实现,结果漏洞百出
//	//究其原因就是脱离了抽象出来的数据结构
//	for (int i = 0; i < n; i++) {
//		weight_num += weight[i];
//		if (weight_num <= c)ans++;
//		else break;
//	}
//
//	cout << "可装载的最大数量为" << ans << endl;
//	return 0;
//}
