//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int N = 110;
//int f[N][N], a[N][N];
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n, m;
//        cout << "请输入花生苗的行数和列数：";
//        cin >> n >> m;
//        cout << "输入具体花生数目：";
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++)
//                cin >> a[i][j];
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++)
//                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
//        cout << "最多可摘到的花生数目：";
//        cout << f[n][m] << endl;
//        memset(f, 0, sizeof f);
//    }
//    return 0;
//}