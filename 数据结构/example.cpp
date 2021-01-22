#include<stdio.h>
#define N 30 
void menu();
void luru();//1录入 
void tianjia();//2添加 
void chuli();//3处理 
void chaxun();//4查询 
void shanchu();//5删除 
void paixu();//6排序 
void liulan();//7浏览 
void exit();//8退出 
typedef struct date
{
	int year;
	int month;
	int day;
}DATE;
typedef struct traffic
{
	long fdhm;//罚单号码 
	char cph; //车牌号
	long kdjjhm;//开单交警号码
	DATE cfday;//处罚日期
	int cfzt;//处罚状态 1为没处理 0为已处理  
}TRAFFIC;

void menu()
{
	printf("\t\t欢迎进入交通处罚单系统");
	printf("\t\t\t\t1.信息录入\n");
	printf("\t\t\t\t2.信息添加\n");
	printf("\t\t\t\t3.信息修改\n");
	printf("\t\t\t\t4.信息查询\n");
	printf("\t\t\t\t5.信息删除\n");
	printf("\t\t\t\t6.信息排序\n");
	printf("\t\t\t\t7.信息浏览\n");
	printf("请输入操作所对应的数(1-7)：[  ]\b\b");
}

void luru()
{
	int n, i;
	long fdhm;
	DATE da1, da2;
	TRAFFIC  tra1, tra2;
	scanf("%d", &n);
	printf("请输入新的罚单");
	scanf("%ld", &tra1.fdhm);//罚单号码
	scanf("%s", tra1.cph);//车牌号
	scanf("%ld", &tra1.kdjjhm);//开单交警号码
	scanf("%d", da1.year);
	scanf("%d", da1.month);
	scanf("%d", da1.day);
	scanf("%d", tra1.cfzt);
	printf("%10ld %8s %10ld %6d\02%d\02%d %d",
		tra1.fdhm,
		tra1.cph,
		tra1.kdjjhm,
		da1.year,
		da1.month,
		da1.day,
		tra1.cfzt);
	return;
}

int main()
{
	int n;
	void menu();
	scanf("%d", &n);
	switch (n)
	{
	case 1:luru();
		break;
	case 2:tianjia();
		break;
	case 3:chuli();
		break;
	case 4:chaxun();
		break;
	case 5:shanchu();
		break;
	case 6:paixu();
		break;
	case 7:liulan();
		break;
	case 8:exit();
	}
	void luru();


	return 0;
}
