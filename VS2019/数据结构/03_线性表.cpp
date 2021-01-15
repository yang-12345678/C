//# include <stdio.h>
//# include <malloc.h>
//# include <stdlib.h>
//
//// ������һ���������ͣ�����struct arr
//struct Array
//{
//	int* Base;  // �洢�������Ա���׵�ַ
//	int len;  // ���Ա��������ɵ����Ԫ�صĸ���
//	int cnt;  // ��ǰ�������Ч����
//};
//
//void init_arr(struct Array *Parr, int length);  // ��ʼ��
//
//bool append_arr(struct Array* Parr, int val);  // ׷��
//bool insert_arr(struct Array* Parr, int pos, int val);  // ����,�ڵ�pos��Ԫ�ش�����val
//bool remove_arr(struct Array* Parr, int pos, int *Pvol);  // ɾ��
//bool is_empty(struct Array* Parr);
//bool is_full(struct Array* Parr);
//void show_arr(struct Array *Parr);
//void reverse_arr(struct Array* Parr);
//
//// ������
//int main()
//{
//	struct Array arr;  // ����һ�����Ա�
//	int val;
//	
//	init_arr(&arr, 6);  // ��ʼ�����Ա�, ����Ϊ6
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
//		printf("ɾ���ɹ���\n");
//		printf("��ɾ����Ԫ���ǣ�%d\n", val);
//	}
//	else
//		printf("ɾ��ʧ�ܣ�");*/
//
//
//	/*if (append_arr(&arr, 3))
//	{
//		printf("׷�ӳɹ���");
//	}
//	else
//	{
//		printf("׷��ʧ�ܣ�");
//	}*/
//
//
//	show_arr(&arr);  // ������Ա�
//
//	
//
//
//	return 0;
//}
//
//// ��ʼ��
//void init_arr(struct Array *Parr, int length)
//{
//	Parr->Base = (int*)malloc(sizeof(int) * length);
//	if (Parr->Base == NULL)
//	{
//		printf("�ڴ����ʧ�ܣ�\n");
//		exit(-1);
//	}
//	else
//	{
//		Parr->len = length;
//		Parr->cnt = 0;
//	}
//}
//
//// �п�
//bool is_empty(struct Array* Parr)
//{
//	if (Parr->cnt == 0)
//		return true;
//	else
//		return false;
//}
//
//// ����
//bool is_full(struct Array* Parr)
//{
//	if (Parr->cnt == Parr->len)
//		return true;
//	else
//		return false;
//}
//
//// ���
//void show_arr(struct Array* Parr)
//{
//	if (is_empty(Parr))
//		printf("�����Ա�Ϊ�գ�");
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
//	// ��ʱ����false
//	if (is_full(Parr))
//		return false;
//	
//
//	// ����ʱ׷��
//	Parr->Base[Parr->cnt] = val;
//	Parr->cnt++;
//	return true;
//}
//
//// ����
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
//// ɾ��
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
//// ����
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