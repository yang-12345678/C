#include <iostream>
using namespace std;

void Perm(int list[], int k, int m)
{
    if (m==0)
    {
        int i = 0;
        while (list[i] != 0)
        {
            cout << list[i] << " ";
            i++;
        }
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            if (list[i] == 0)
            {
                list[i] = m+1;
                Perm(list, k, m-1);
                list[i] = 0;
            }
        }
    }
}

int main()
{
    int n;
    int a[100] = { 0 };
    cin >> n; 
    Perm(a, 0,n - 1);
      
    return 0;
}
