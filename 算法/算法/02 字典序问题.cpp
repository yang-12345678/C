//// ϰ�� 1-2 ������
//
//#include <iostream>
//using namespace std;
//
////f(i,k)����iλ�ַ���ͷ��k���ַ����ܸ���
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
//            sum += f(j, k - 1);//�������������ɿ�֪f(i,k)= �ۼ�f(j,k-1) ,j��i+1��26
//        }
//        return sum;
//    }
//}
////����Ϊkλ�������ַ����ܸ���
//int g(int k)
//{
//    int sum = 0;
//    for (int i = 1; i <= 26; i++)
//    {
//        sum += f(i, k);
//    }
//    return sum;
//}
////�õ�����ֵ
//int getvalue(string a)
//{
//    int n = a.length();
//    int sum = 0;
//    for (int i = 1; i < n; i++)
//    {
//        sum += g(i);//��һ������������С��nλ���ַ������ܺ�
//    }
//    int s = a[0] - 'a' + 1;
//    for (int i = 1; i < s; i++)
//    {
//        sum += f(i, n);//�ڶ����������� s�ַ�֮ǰ���ַ� ��ͷ����Ϊn���ַ����������ӵ�sum��
//    }
//    //��������������s�ַ���ͷ��ʣ�µ����е��ַ�������
//    for (int i = 1, temp = s; i < n; i++)
//    {
//        int l = a[i] - 'a' + 1;//��ǰ��λ��ĸ
//        int len = n - i;//��ȡ��ǰ�ַ�������
//        for (int j = temp + 1; j < l; j++)
//        {
//            sum += f(j, len);
//        }
//        temp = l;//���ܷ�����һ��ѭ�����Ϊ����һ��ѭ����ִ�е�ʱ����ôtemp����������һλ
//    }
//    return sum + 1;//������ԭ�ַ���
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
