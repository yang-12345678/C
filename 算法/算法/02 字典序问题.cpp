//// 习题 1-2 王晓东
//
//#include <iostream>
//using namespace std;
//
////f(i,k)：第i位字符开头，k个字符的总个数
//int f(int i, int k)
//{
//    int sum = 0;
//    if (k == 1)
//    {
//        return 1;
//    }
//    else
//    {
//        for (int j = i + 1; j <= 26; j++)
//        {
//            sum += f(j, k - 1);//由上述分析规律可知f(i,k)= 累加f(j,k-1) ,j从i+1到26
//        }
//        return sum;
//    }
//}
////长度为k位的所有字符的总个数
//int g(int k)
//{
//    int sum = 0;
//    for (int i = 1; i <= 26; i++)
//    {
//        sum += f(i, k);
//    }
//    return sum;
//}
////得到编码值
//int getvalue(string a)
//{
//    int n = a.length();
//    int sum = 0;
//    for (int i = 1; i < n; i++)
//    {
//        sum += g(i);//第一步：计算所有小于n位的字符串的总和
//    }
//    int s = a[0] - 'a' + 1;
//    for (int i = 1; i < s; i++)
//    {
//        sum += f(i, n);//第二步：计算以 s字符之前的字符 打头长度为n的字符串个数并加到sum上
//    }
//    //第三步：计算以s字符开头，剩下的所有的字符串个数
//    for (int i = 1, temp = s; i < n; i++)
//    {
//        int l = a[i] - 'a' + 1;//当前首位字母
//        int len = n - i;//获取当前字符串长度
//        for (int j = temp + 1; j < l; j++)
//        {
//            sum += f(j, len);
//        }
//        temp = l;//不能放在上一个循环里，因为当上一个循环不执行的时候，那么temp不能跳到下一位
//    }
//    return sum + 1;//最后加上原字符串
//}
//int main()
//{
//    int n, i;
//    string a;
//    cin >> n;
//    for (i = 0; i < n; i++)
//    {
//        cin >> a;
//        int s = getvalue(a);
//        cout << s << endl;
//    }
//    return 0;
//}
