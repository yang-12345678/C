#include <stdio.h>
#include <string.h>

struct Student {
	// �������ݵ��ֽ���֮���ǽṹ����ֽ���
	int sid;
	char name[20];
	int age;
};  // �ֺŲ���ʡ��


//int main() 
//{
//	struct Student st = { 1000, "������", 20 };
//	printf("%d  %s  %d", st.sid, st.name, st.age);
//
//	st.sid = 99;
//	strcpy(st.name, "������");
//	//st.name = "lisi";
//	st.age = 22;
//	printf("%d  %s  %d", st.sid, st.name, st.age);
//
//
//	return 0;
//}


//void main()
//{
//	struct Student st = { 100, "zhangsan", 20 };
//
//	struct Student *pst;  // �ֽ�������ͽṹ������
//	pst = &st;
//	//(*pst).sid = 99;
//	pst->sid = 99;
//
//}