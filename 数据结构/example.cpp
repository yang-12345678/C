#include<stdio.h>
#define N 30 
void menu();
void luru();//1¼�� 
void tianjia();//2��� 
void chuli();//3���� 
void chaxun();//4��ѯ 
void shanchu();//5ɾ�� 
void paixu();//6���� 
void liulan();//7��� 
void exit();//8�˳� 
typedef struct date
{
	int year;
	int month;
	int day;
}DATE;
typedef struct traffic
{
	long fdhm;//�������� 
	char cph; //���ƺ�
	long kdjjhm;//������������
	DATE cfday;//��������
	int cfzt;//����״̬ 1Ϊû���� 0Ϊ�Ѵ���  
}TRAFFIC;

void menu()
{
	printf("\t\t��ӭ���뽻ͨ������ϵͳ");
	printf("\t\t\t\t1.��Ϣ¼��\n");
	printf("\t\t\t\t2.��Ϣ���\n");
	printf("\t\t\t\t3.��Ϣ�޸�\n");
	printf("\t\t\t\t4.��Ϣ��ѯ\n");
	printf("\t\t\t\t5.��Ϣɾ��\n");
	printf("\t\t\t\t6.��Ϣ����\n");
	printf("\t\t\t\t7.��Ϣ���\n");
	printf("�������������Ӧ����(1-7)��[  ]\b\b");
}

void luru()
{
	int n, i;
	long fdhm;
	DATE da1, da2;
	TRAFFIC  tra1, tra2;
	scanf("%d", &n);
	printf("�������µķ���");
	scanf("%ld", &tra1.fdhm);//��������
	scanf("%s", tra1.cph);//���ƺ�
	scanf("%ld", &tra1.kdjjhm);//������������
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
