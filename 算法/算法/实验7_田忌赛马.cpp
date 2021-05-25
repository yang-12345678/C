//#include<iostream>  
//#include<algorithm> 
//#include<vector>
//using namespace std;
//bool MaxToMin(const int& a, const int& b);
//
//int main()
//{
//	int n, n1, n2;
//	int i, j, k;
//	int speed;
//	int WinTimes, LoseTimes, money;
//	vector<int> TianHorse;
//	vector<int> KingHorse;
//	while (cin >> n)
//	{
//		if (0 == n)
//			break;
//		money = WinTimes = LoseTimes = 0;
//		n1 = n2 = n - 1;
//		TianHorse.clear();
//		KingHorse.clear();
//		for (i = 0; i < n; i++)
//		{
//			cin >> speed;
//			TianHorse.push_back(speed);
//		}
//		for (i = 0; i < n; i++)
//		{
//			cin >> speed;
//			KingHorse.push_back(speed);
//		}
//		sort(TianHorse.begin(), TianHorse.end(), MaxToMin);
//		sort(KingHorse.begin(), KingHorse.end(), MaxToMin);
//		i = j = 0;
//		for (k = 0; k < n; k++)
//		{
//			if (TianHorse[n1] > KingHorse[n2])
//			{
//				n1--;
//				n2--;
//				WinTimes++;
//			}
//			else if (TianHorse[n1] < KingHorse[n2])
//			{
//				LoseTimes++;
//				n1--;
//				j++;
//			}
//			else
//			{
//				if (TianHorse[i] > KingHorse[j])
//				{
//					WinTimes++;
//					i++;
//					j++;
//				}
//				else if (TianHorse[n1] < KingHorse[j])
//				{
//					LoseTimes++;
//					n1--;
//					j++;
//				}
//				else
//					break;
//			}
//		}
//		money = (WinTimes - LoseTimes) * 200;
//		cout << "可能赢得钱最多为：" << money << endl;
//	}
//	return 0;
//}
//bool MaxToMin(const int& a, const int& b)
//{
//	if (a >= b)
//		return true;
//	else
//		return false;
//}