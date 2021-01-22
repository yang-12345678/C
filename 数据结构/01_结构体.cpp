#include <stdio.h>
#include <string.h>

struct Student {
	// 各个数据的字节数之和是结构体的字节数
	int sid;
	char name[20];
	int age;
};  // 分号不能省略


//int main() 
//{
//	struct Student st = { 1000, "刘嘉琪", 20 };
//	printf("%d  %s  %d", st.sid, st.name, st.age);
//
//	st.sid = 99;
//	strcpy(st.name, "杨鹏宇");
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
//	struct Student *pst;  // 字节数不会和结构体的相等
//	pst = &st;
//	//(*pst).sid = 99;
//	pst->sid = 99;
//
//}