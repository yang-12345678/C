//# include <stdio.h>
//# include <malloc.h>
//
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };  // 静态的，长度固定，不可变
//
//	// 动态的使用数组：可以增加和释放内存
//	int len;
//	printf("请输入你要分配的数组的长度：len = ");
//	scanf_s("%d", &len);
//
//	// malloc 函数 返回申请字节的第一个字节的地址
//
//	int* p = (int *)malloc(sizeof(int) * len);
//	int i = 0;
//	if (p == NULL)
//		printf("内存分配不成功！\n");
//	*p = 4;    // 相当于 a[0] = 4;
//	p[1] = 5;    // 相当于 a[1] = 5;
//
//	for (i = 0; i < len; ++i)
//		scanf_s("%d", &p[i]);
//	for (int i = 0; i < len; i++)
//		printf("%d", p[i]);
//
//	//free(p);   // 释放 p 所指的连续内存
//
//	return 0;
//}