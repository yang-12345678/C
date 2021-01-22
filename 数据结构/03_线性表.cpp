//# include <stdio.h>
//# include <malloc.h>
//# include <stdlib.h>
//
//// 定义了一个数据类型，叫做struct arr
//struct Array
//{
//	int* Base;  // 存储的是线性表的首地址
//	int len;  // 线性表所能容纳的最大元素的个数
//	int cnt;  // 当前数组的有效个数
//};
//
//void init_arr(struct Array *Parr, int length);  // 初始化
//
//bool append_arr(struct Array* Parr, int val);  // 追加
//bool insert_arr(struct Array* Parr, int pos, int val);  // 插入,在第pos个元素处插入val
//bool remove_arr(struct Array* Parr, int pos, int *Pvol);  // 删除
//bool is_empty(struct Array* Parr);
//bool is_full(struct Array* Parr);
//void show_arr(struct Array *Parr);
//void reverse_arr(struct Array* Parr);
//
//// 主函数
//int main()
//{
//	struct Array arr;  // 创建一个线性表
//	int val;
//	
//	init_arr(&arr, 6);  // 初始化线性表, 长度为6
//	//printf("%d", arr.len);
//
//	append_arr(&arr, 1);
//	append_arr(&arr, 2);
//	append_arr(&arr, 3);
//	append_arr(&arr, 4);
//	append_arr(&arr, 5);
//
//	//insert_arr(&arr, 2, 99);
//
//	reverse_arr(&arr);
//
//	/*if (remove_arr(&arr, 1, &val))
//	{
//		printf("删除成功！\n");
//		printf("您删除的元素是：%d\n", val);
//	}
//	else
//		printf("删除失败！");*/
//
//
//	/*if (append_arr(&arr, 3))
//	{
//		printf("追加成功！");
//	}
//	else
//	{
//		printf("追加失败！");
//	}*/
//
//
//	show_arr(&arr);  // 输出线性表
//
//	
//
//
//	return 0;
//}
//
//// 初始化
//void init_arr(struct Array *Parr, int length)
//{
//	Parr->Base = (int*)malloc(sizeof(int) * length);
//	if (Parr->Base == NULL)
//	{
//		printf("内存分配失败！\n");
//		exit(-1);
//	}
//	else
//	{
//		Parr->len = length;
//		Parr->cnt = 0;
//	}
//}
//
//// 判空
//bool is_empty(struct Array* Parr)
//{
//	if (Parr->cnt == 0)
//		return true;
//	else
//		return false;
//}
//
//// 判满
//bool is_full(struct Array* Parr)
//{
//	if (Parr->cnt == Parr->len)
//		return true;
//	else
//		return false;
//}
//
//// 输出
//void show_arr(struct Array* Parr)
//{
//	if (is_empty(Parr))
//		printf("该线性表为空！");
//	else
//	{
//		for (int i = 0; i < Parr->cnt; i++)
//			printf("%-4d", Parr->Base[i]);	
//	}
//
//}
//
//bool append_arr(struct Array* Parr, int val)
//{
//	// 满时返回false
//	if (is_full(Parr))
//		return false;
//	
//
//	// 不满时追加
//	Parr->Base[Parr->cnt] = val;
//	Parr->cnt++;
//	return true;
//}
//
//// 插入
//bool insert_arr(struct Array* Parr, int pos, int val)
//{
//	int i;
//
//	if (is_full(Parr))
//	    return false;
//
//	if (pos<1 || pos>Parr->cnt +1)
//	     return false;
//
//	for (i = Parr->cnt - 1; i >= pos - 1; i--)
//	{
//		Parr->Base[i + 1] = Parr->Base[i];
//	}
//	Parr->Base[pos - 1] = val;
//	Parr->cnt++;
//	return true;
//}
//
//// 删除
//bool remove_arr(struct Array* Parr, int pos, int* Pval)
//{
//	if (is_empty(Parr))
//	    return false;
//	if (pos<1 || pos>Parr->cnt)
//		return false;
//
//	*Pval = Parr->Base[pos - 1];
//	for (int i = pos; i < Parr->cnt; i++)
//	{
//		Parr->Base[i - 1] = Parr->Base[i];
//	}
//	Parr->cnt--;
//	
//}
//
//// 倒置
//void reverse_arr(struct Array* Parr)
//{
//	for (int i = 0; i < Parr->cnt / 2; i++)
//	{
//		int j;
//		j = Parr->Base[i];
//		Parr->Base[i] = Parr->Base[Parr->cnt - 1 - i];
//		Parr->Base[Parr->cnt - 1 - i] = j;
//
//	}
//}