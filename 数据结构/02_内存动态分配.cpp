//# include <stdio.h>
//# include <malloc.h>
//
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };  // ��̬�ģ����ȹ̶������ɱ�
//
//	// ��̬��ʹ�����飺�������Ӻ��ͷ��ڴ�
//	int len;
//	printf("��������Ҫ���������ĳ��ȣ�len = ");
//	scanf_s("%d", &len);
//
//	// malloc ���� ���������ֽڵĵ�һ���ֽڵĵ�ַ
//
//	int* p = (int *)malloc(sizeof(int) * len);
//	int i = 0;
//	if (p == NULL)
//		printf("�ڴ���䲻�ɹ���\n");
//	*p = 4;    // �൱�� a[0] = 4;
//	p[1] = 5;    // �൱�� a[1] = 5;
//
//	for (i = 0; i < len; ++i)
//		scanf_s("%d", &p[i]);
//	for (int i = 0; i < len; i++)
//		printf("%d", p[i]);
//
//	//free(p);   // �ͷ� p ��ָ�������ڴ�
//
//	return 0;
//}