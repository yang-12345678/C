#include <iostream>
#include "swap.h"
using namespace std;

//void swap(int a, int b);
//
//void swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}


int main()
{
	int a = 20;
	int b = 30;
	swap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");

	return 0;
}

