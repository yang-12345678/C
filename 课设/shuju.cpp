#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 100


typedef struct address_book
{
    char number[20];  // �绰����
    char name[20];  // �û���
    char address[50];  // ��ַ
    int flag;  // �жϳ�ͻ�ı�־
} Book;

typedef struct HashTable
{
    Book *elem;
    int size;
}Hash;

// ��ʼ����ϣ�� 
int InitHashTable(Hash &H)
{
    H.size = HASHSIZE;
    H.elem = (Book *)malloc(HASHSIZE * sizeof (Book));

    if(!H.elem)
    {
        printf("�ڴ�ռ����ʧ�ܣ� �����ԣ�");
        return -1;
    }

    for(int i = 0;i<H.size;i++)
    {
        H.elem[i].flag = -1;
    }
}

// ��ȡ��ֵ
int GetKey(char Num[])
{
    int len = strlen(Num);
    int key = 0;
    for (int i = 0; i< len;i++)
    {
        key += Num[i] - '0';
    }
    return key%HASHSIZE; // key, (0,99)
}

// ����̽����ɢ�д����ͻ
int InsertHash(Hash &H, char Num[])
{
    int addr;
    addr = GetKey(Num);
    int i = 0;
    while(H.elem[addr].flag != -1)
    {
        addr = (addr+1) % HASHSIZE;
    }

    return addr;
}

void menu()
{
	printf("\n******��ӭ����ͨѶ¼����ϵͳ******\n");
    printf("1.������ͨѶ¼\n");
    printf("2.����û���Ϣ\n");
    printf("3.��ѯ�û���Ϣ\n");
    printf("4.�޸��û���Ϣ\n");
    printf("5.ɾ���û���Ϣ\n");
    printf("6.��ʾ�û���Ϣ\n");
    printf("0.�˳�\n");
}
// д���ļ�
int Book_write(Hash &H, int addr[], int n)
{
    FILE *fp = fopen("./book.txt", "w");
    if (fp == NULL)
    {
        printf("���ļ����������ԣ�");
        return -1;
    }
    fprintf(fp, "%-20s %-20s %-50s \n", "����", "�绰����", "��ַ");
    int i;
    for(int i =0;i<n;i++)
    {
        fprintf(fp, "%-20s %-20s %-50s",
                H.elem[addr[i]].name, H.elem[addr[i]].number, H.elem[addr[i]].address);
        fprintf(fp, "\n");
    }

    fflush(fp);
    fclose(fp);
    return 1;
}

// �����µ�ͨѶ¼
int Creat()
{
	Hash Table;
    InitHashTable(Table);
    
    char name[20];
    char number[20];
    char address[50];

    int n; // �û�����

    printf("�������µ�ͨѶ¼���û�������");
    scanf("%d", &n);
    int addr[n]; // ��ϣ���ŵ�ַ
    for(int i =0; i< n;i++)
    {
        printf("\n�������%dλ�û���������", i+1);
        scanf(" %s", name);
        printf("\n�������%dλ�û��ĵ绰���룺", i+1);
        scanf(" %s", number);
        printf("\n�������%dλ�û��ĵ�ַ��", i+1);
        scanf(" %s", address);

        addr[i] = InsertHash(Table, number);
        strcpy(Table.elem[addr[i]].name, name);
        strcpy(Table.elem[addr[i]].number, number);
        strcpy(Table.elem[addr[i]].address, address);
        Table.elem[addr[i]].flag = 0;
    }

    Book_write(Table, addr, n);
    printf("\n�����ɹ���\n");
}

int Append()
{
	Hash Table;
    InitHashTable(Table);

    char name[20];
    char number[20];
    char address[50];

    int n; // �û�����
    
    printf("\n��������Ҫ��ӵ��û��ĸ�����");
	scanf("%d", &n);
	int addr[n];
	for(int i =0; i< n;i++)
    {
        printf("\n������Ҫ��ӵĵ�%dλ�û���������", i+1);
        scanf(" %s", name);
        printf("\n������Ҫ��ӵĵ�%dλ�û��ĵ绰���룺", i+1);
        scanf(" %s", number);
        printf("\n������Ҫ��ӵĵ�%dλ�û��ĵ�ַ��", i+1);
        scanf(" %s", address);

        addr[i] = InsertHash(Table, number);
        strcpy(Table.elem[addr[i]].name, name);
        strcpy(Table.elem[addr[i]].number, number);
        strcpy(Table.elem[addr[i]].address, address);
        Table.elem[addr[i]].flag = 0;
    }
    
    FILE *fp = fopen("./book.txt", "a");
    if (fp == NULL)
    {
        printf("���ļ����������ԣ�");
        return -1;
    }
    int i;
    for(int i =0;i<n;i++)
    {
        fprintf(fp, "%-20s %-20s %-50s",
                Table.elem[addr[i]].name, Table.elem[addr[i]].number, Table.elem[addr[i]].address);
        fprintf(fp, "\n");
    }

    fflush(fp);
    fclose(fp);
    printf("\n��ӳɹ���\n");
    return 1;
}

int chaxun()
{
	Hash Table;
    InitHashTable(Table);
    
	char number[20];  // �绰����
    char name[20];  // �û���
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("���ļ����� �����ԣ�");
		return -1; 
	}
	
	int n;
	
	for(n=0;fscanf(fp, "%s %s %s", name,number,address) != EOF;n++)
	    {
	    	if (n >= 1)
			{
				addr[n-1] = InsertHash(Table, number);
				strcpy(Table.elem[addr[n-1]].name, name);
                strcpy(Table.elem[addr[n-1]].number, number);
                strcpy(Table.elem[addr[n-1]].address, address);
                Table.elem[addr[n-1]].flag = 0;
			 } 
		} 
	fflush(fp);
	fclose(fp);
		
	n = n-1;
	
	while(1)
	{
		printf("\n����������ѯ�û���������绰���룺");
	    char ch[20];
	    scanf(" %s", ch);
	    int i; 
	    for(i =0;i<n;i++)
	    {
		    if(strcmp(ch,Table.elem[addr[i]].name) == 0)
		    {
		        printf("\n���û���ϢΪ��\n\n");
		        printf("%-20s %-20s %-50s \n\n", "����", "�绰����", "��ַ");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
                break;
			}
		    if (strcmp(ch,Table.elem[addr[i]].number) == 0)
		    {
		        printf("\n���û���ϢΪ��\n\n");
		        printf("%-20s %-20s %-50s \n\n", "����", "�绰����", "��ַ");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
		        break;
			} 
		}
		
		if (i == n)
	    {
		    printf("\nδ�ҵ����û���Ϣ��\n");
		    return 0;
    	}
	    
	    do
		{
		    printf("\n���Ƿ������ѯ��Y/N?");
	    	char c;
		    getchar();
		    scanf("%c", &c);
		    if (c == 'Y' || (c - 32) == 'Y') 
		        break;
	        
	        else if (c == 'N' || (c - 32) == 'N')
	            return 0;
			else
			{
			    printf("\n��������ȷ�ַ���\n");	
			    continue;
			}
		}while(1);
	}	
	
	return 1;	    	
}

int xiugai()
{
	Hash Table;
    InitHashTable(Table);
    
	char number[20];  // �绰����
    char name[20];  // �û���
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("���ļ����� �����ԣ�");
		return -1; 
	}
	
	int n;
	
	for(n=0;fscanf(fp, "%s %s %s", name,number,address) != EOF;n++)
	    {
	    	if (n >= 1)
			{
				addr[n-1] = InsertHash(Table, number);
				strcpy(Table.elem[addr[n-1]].name, name);
                strcpy(Table.elem[addr[n-1]].number, number);
                strcpy(Table.elem[addr[n-1]].address, address);
                Table.elem[addr[n-1]].flag = 0;
			 } 
		} 
	fflush(fp);
	fclose(fp);
    
    n = n-1;
    
    while(1)
	{
		printf("\n�����뽫Ҫ�޸��û���������绰���룺");
	    char ch[20];
	    scanf(" %s", ch);
	    int i; 
	    for(i =0;i<n;i++)
	    {
//		    printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].number);
		    if(strcmp(ch,Table.elem[addr[i]].name) == 0)
		    {
		        printf("\n���û���ϢΪ��\n\n");
		        printf("%-20s %-20s %-50s \n", "����", "�绰����", "��ַ");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
                break;
			}
		    if (strcmp(ch,Table.elem[addr[i]].number) == 0)
		    {
		        printf("\n���û���ϢΪ��\n\n");
		        printf("%-20s %-20s %-50s \n", "����", "�绰����", "��ַ");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
		        break;
			} 
		}
		
		if (i >= n)
	    {
		    printf("\nδ�ҵ����û���Ϣ��\n");
		    return 0;
    	}
    	
    	printf("\n�밴��ʾ����Ҫ�޸ĵ���Ϣ!\n"); 
    	printf("������");
    	scanf(" %s", Table.elem[addr[i]].name);
		printf("�绰���룺");
    	scanf(" %s", Table.elem[addr[i]].number);
        printf("��ַ��");
    	scanf(" %s", Table.elem[addr[i]].address);
    	
    	if(Book_write(Table, addr, n));
    	    printf("\n\n�޸ĳɹ���\n");
    	
    	do
		{
			printf("\n���Ƿ�����޸ģ�Y/N?");
	    	char c;
		    getchar();
		    scanf("%c", &c);
		    if (c == 'Y' || (c - 32) == 'Y') 
		        break;
	        
	        else if (c == 'N' || (c - 32) == 'N')
	            return 0;
			else
			{
			    printf("\n��������ȷ�ַ���\n");	
			    continue;
			}
		}while(1);
    } 
    
 } 
 
int shanchu()
{
    Hash Table;
    InitHashTable(Table);
    
	char number[20];  // �绰����
    char name[20];  // �û���
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("���ļ����� �����ԣ�");
		return -1; 
	}
	
	int n;
	
	for(n=0;fscanf(fp, "%s %s %s", name,number,address) != EOF;n++)
	    {
	    	if (n >= 1)
			{
				addr[n-1] = InsertHash(Table, number);
				strcpy(Table.elem[addr[n-1]].name, name);
                strcpy(Table.elem[addr[n-1]].number, number);
                strcpy(Table.elem[addr[n-1]].address, address);
                Table.elem[addr[n-1]].flag = 0;
			 } 
		} 
	fflush(fp);
	fclose(fp);
    
    n = n-1;
    while(1)
	{
	
	    printf("\n�����뽫Ҫɾ���û���������绰���룺");
		char ch[20];
		scanf(" %s", ch);
		int i; 
		for(i =0;i<n;i++)
		{
			if(strcmp(ch,Table.elem[addr[i]].name) == 0)
			{
			    printf("\n���û���ϢΪ��\n\n");
			    printf("%-20s %-20s %-50s \n", "����", "�绰����", "��ַ");
			    printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
	            break;
			}
			if (strcmp(ch,Table.elem[addr[i]].number) == 0)
			{
			    printf("\n���û���ϢΪ��\n\n");
			    printf("%-20s %-20s %-50s \n", "����", "�绰����", "��ַ");
			    printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
			    break;
			} 
		}
			
		if (i >= n)
		{
			printf("\nδ�ҵ����û���Ϣ��\n");
			return 0;
	    }
	    
	    int j;
	    for(int j=i;j<n-1;j++)
	    {
	    	addr[j] = addr[j+1];
		}
		n--; 
		
		do
		{
			printf("\n���Ƿ�ȷ��Ҫɾ����Y/N?"); 
			char b;
		    getchar();
		    scanf("%c", &b);
		    if (b == 'Y' || (b - 32) == 'Y')
		    {
		    	Book_write(Table, addr, n);
		    	printf("\nɾ���ɹ�!\n");
		    	break;
			}
			else if (b == 'N' || (b - 32) == 'N')
	            return 0;
	        else
	        {
	            printf("\n��������ȷ�ַ���\n");	
			    continue;
			}
    	}while(1);
    	do
		{
	    	printf("\n���Ƿ����ɾ����Y/N?");
	    	char c;
		    getchar();
		    scanf("%c", &c);
		    if (c == 'Y' || (c - 32) == 'Y') 
		        break;
	        
	        else if (c == 'N' || (c - 32) == 'N')
	            return 0;
			else
			{
			    printf("\n��������ȷ�ַ���\n");	
			    continue;
			}
        }while(1);
    }
	
}

int xianshi()
{
	Hash Table;
    InitHashTable(Table);
    
	char number[20];  // �绰����
    char name[20];  // �û���
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("���ļ����� �����ԣ�");
		return -1; 
	}
	
	int n;
	
	for(n=0;fscanf(fp, "%s %s %s", name,number,address) != EOF;n++)
	    {
	    	if (n >= 1)
			{
				addr[n-1] = InsertHash(Table, number);
				strcpy(Table.elem[addr[n-1]].name, name);
                strcpy(Table.elem[addr[n-1]].number, number);
                strcpy(Table.elem[addr[n-1]].address, address);
                Table.elem[addr[n-1]].flag = 0;
			 } 
		} 
	fflush(fp);
	fclose(fp);
    
    n = n-1;
    
    int i,j;
    for(int i=0;i<n;i++)
    {
    	printf("\n��ͨѶ¼��������Ϣ����:\n\n"); 
    	for(i=0;i<n-1;i++)
    	{
    		for(j=i+1;j<n;j++)
    		{
    			Book temp;
    			if(strcmp(Table.elem[addr[i]].name, Table.elem[addr[j]].name) > 0)
    			{
    				temp = Table.elem[addr[i]];
    				Table.elem[addr[i]] = Table.elem[addr[j]];
    				Table.elem[addr[j]] = temp;
				}
			}
		}
		
		printf("%-20s %-20s %-50s \n\n", "����", "�绰����", "��ַ");
		for (i=0;i<n;i++)
    	{
    		printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
		}
	}
	
	return 1;
    
}



int main()
{
    int a;
    do
    {
    	menu(); 
    	printf("�������Ӧ�Ĳ�����ţ�");
        scanf(" %d", &a);
        switch(a)
        {
        	
        	case 0: 
        	    exit(0);
        	case 1:
        		Creat();break;
        	case 2:
        		Append();break;
        	case 3:
        		chaxun();break;
        	case 4:
			    xiugai();break; 
			case 5:
			    shanchu();break; 
			case 6:
				xianshi();break;
		}
	}while(1);
    return 0;
}


