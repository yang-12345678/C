// 算法时间复杂度： O(n^2)

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int i, n, j, sign = 1;
//    float s, t = 1;
//    cout << "请输入n的值：";
//    cin >> n;
//    s = 1;
//    for (i = 2; i <= n; i++)
//    {
//        //cout << 1 << endl;
//        t = 1;
//        for (j = 1; j <= 2 * i - 1; j++)
//            t = t * j;
//        sign = 1;
//        for (j = 1; j <= i +1; j++)
//            sign = sign * (-1);
//        s = s + sign / t;
//    }
//    cout << "sum=" << s << endl;
//
//    system("pause");
//    return 0;
//}
