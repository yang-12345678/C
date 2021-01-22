#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 100


typedef struct address_book
{
    char number[20];  // 电话号码
    char name[20];  // 用户名
    char address[50];  // 地址
    int flag;  // 判断冲突的标志
} Book;

typedef struct HashTable
{
    Book *elem;
    int size;
}Hash;

// 初始化哈希表 
int InitHashTable(Hash &H)
{
    H.size = HASHSIZE;
    H.elem = (Book *)malloc(HASHSIZE * sizeof (Book));

    if(!H.elem)
    {
        printf("内存空间分配失败， 请重试！");
        return -1;
    }

    for(int i = 0;i<H.size;i++)
    {
        H.elem[i].flag = -1;
    }
}

// 获取键值
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

// 线性探测再散列处理冲突
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
	printf("\n******欢迎进入通讯录管理系统******\n");
    printf("1.创建新通讯录\n");
    printf("2.添加用户信息\n");
    printf("3.查询用户信息\n");
    printf("4.修改用户信息\n");
    printf("5.删除用户信息\n");
    printf("6.显示用户信息\n");
    printf("0.退出\n");
}
// 写入文件
int Book_write(Hash &H, int addr[], int n)
{
    FILE *fp = fopen("./book.txt", "w");
    if (fp == NULL)
    {
        printf("打开文件错误，请重试！");
        return -1;
    }
    fprintf(fp, "%-20s %-20s %-50s \n", "姓名", "电话号码", "地址");
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

// 创建新的通讯录
int Creat()
{
	Hash Table;
    InitHashTable(Table);
    
    char name[20];
    char number[20];
    char address[50];

    int n; // 用户数量

    printf("请输入新的通讯录的用户数量：");
    scanf("%d", &n);
    int addr[n]; // 哈希表存放地址
    for(int i =0; i< n;i++)
    {
        printf("\n请输入第%d位用户的姓名：", i+1);
        scanf(" %s", name);
        printf("\n请输入第%d位用户的电话号码：", i+1);
        scanf(" %s", number);
        printf("\n请输入第%d位用户的地址：", i+1);
        scanf(" %s", address);

        addr[i] = InsertHash(Table, number);
        strcpy(Table.elem[addr[i]].name, name);
        strcpy(Table.elem[addr[i]].number, number);
        strcpy(Table.elem[addr[i]].address, address);
        Table.elem[addr[i]].flag = 0;
    }

    Book_write(Table, addr, n);
    printf("\n创建成功！\n");
}

int Append()
{
	Hash Table;
    InitHashTable(Table);

    char name[20];
    char number[20];
    char address[50];

    int n; // 用户数量
    
    printf("\n请输入你要添加的用户的个数：");
	scanf("%d", &n);
	int addr[n];
	for(int i =0; i< n;i++)
    {
        printf("\n请输入要添加的第%d位用户的姓名：", i+1);
        scanf(" %s", name);
        printf("\n请输入要添加的第%d位用户的电话号码：", i+1);
        scanf(" %s", number);
        printf("\n请输入要添加的第%d位用户的地址：", i+1);
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
        printf("打开文件错误，请重试！");
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
    printf("\n添加成功！\n");
    return 1;
}

int chaxun()
{
	Hash Table;
    InitHashTable(Table);
    
	char number[20];  // 电话号码
    char name[20];  // 用户名
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("打开文件错误， 请重试！");
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
		printf("\n请输入所查询用户的姓名或电话号码：");
	    char ch[20];
	    scanf(" %s", ch);
	    int i; 
	    for(i =0;i<n;i++)
	    {
		    if(strcmp(ch,Table.elem[addr[i]].name) == 0)
		    {
		        printf("\n该用户信息为：\n\n");
		        printf("%-20s %-20s %-50s \n\n", "姓名", "电话号码", "地址");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
                break;
			}
		    if (strcmp(ch,Table.elem[addr[i]].number) == 0)
		    {
		        printf("\n该用户信息为：\n\n");
		        printf("%-20s %-20s %-50s \n\n", "姓名", "电话号码", "地址");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
		        break;
			} 
		}
		
		if (i == n)
	    {
		    printf("\n未找到该用户信息！\n");
		    return 0;
    	}
	    
	    do
		{
		    printf("\n您是否继续查询，Y/N?");
	    	char c;
		    getchar();
		    scanf("%c", &c);
		    if (c == 'Y' || (c - 32) == 'Y') 
		        break;
	        
	        else if (c == 'N' || (c - 32) == 'N')
	            return 0;
			else
			{
			    printf("\n请输入正确字符！\n");	
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
    
	char number[20];  // 电话号码
    char name[20];  // 用户名
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("打开文件错误， 请重试！");
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
		printf("\n请输入将要修改用户的姓名或电话号码：");
	    char ch[20];
	    scanf(" %s", ch);
	    int i; 
	    for(i =0;i<n;i++)
	    {
//		    printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].number);
		    if(strcmp(ch,Table.elem[addr[i]].name) == 0)
		    {
		        printf("\n该用户信息为：\n\n");
		        printf("%-20s %-20s %-50s \n", "姓名", "电话号码", "地址");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
                break;
			}
		    if (strcmp(ch,Table.elem[addr[i]].number) == 0)
		    {
		        printf("\n该用户信息为：\n\n");
		        printf("%-20s %-20s %-50s \n", "姓名", "电话号码", "地址");
		        printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
		        break;
			} 
		}
		
		if (i >= n)
	    {
		    printf("\n未找到该用户信息！\n");
		    return 0;
    	}
    	
    	printf("\n请按提示输入要修改的信息!\n"); 
    	printf("姓名：");
    	scanf(" %s", Table.elem[addr[i]].name);
		printf("电话号码：");
    	scanf(" %s", Table.elem[addr[i]].number);
        printf("地址：");
    	scanf(" %s", Table.elem[addr[i]].address);
    	
    	if(Book_write(Table, addr, n));
    	    printf("\n\n修改成功！\n");
    	
    	do
		{
			printf("\n您是否继续修改，Y/N?");
	    	char c;
		    getchar();
		    scanf("%c", &c);
		    if (c == 'Y' || (c - 32) == 'Y') 
		        break;
	        
	        else if (c == 'N' || (c - 32) == 'N')
	            return 0;
			else
			{
			    printf("\n请输入正确字符！\n");	
			    continue;
			}
		}while(1);
    } 
    
 } 
 
int shanchu()
{
    Hash Table;
    InitHashTable(Table);
    
	char number[20];  // 电话号码
    char name[20];  // 用户名
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("打开文件错误， 请重试！");
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
	
	    printf("\n请输入将要删除用户的姓名或电话号码：");
		char ch[20];
		scanf(" %s", ch);
		int i; 
		for(i =0;i<n;i++)
		{
			if(strcmp(ch,Table.elem[addr[i]].name) == 0)
			{
			    printf("\n该用户信息为：\n\n");
			    printf("%-20s %-20s %-50s \n", "姓名", "电话号码", "地址");
			    printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
	            break;
			}
			if (strcmp(ch,Table.elem[addr[i]].number) == 0)
			{
			    printf("\n该用户信息为：\n\n");
			    printf("%-20s %-20s %-50s \n", "姓名", "电话号码", "地址");
			    printf("%-20s %-20s %-50s\n", Table.elem[addr[i]].name,Table.elem[addr[i]].number,Table.elem[addr[i]].address);
			    break;
			} 
		}
			
		if (i >= n)
		{
			printf("\n未找到该用户信息！\n");
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
			printf("\n您是否确定要删除，Y/N?"); 
			char b;
		    getchar();
		    scanf("%c", &b);
		    if (b == 'Y' || (b - 32) == 'Y')
		    {
		    	Book_write(Table, addr, n);
		    	printf("\n删除成功!\n");
		    	break;
			}
			else if (b == 'N' || (b - 32) == 'N')
	            return 0;
	        else
	        {
	            printf("\n请输入正确字符！\n");	
			    continue;
			}
    	}while(1);
    	do
		{
	    	printf("\n您是否继续删除，Y/N?");
	    	char c;
		    getchar();
		    scanf("%c", &c);
		    if (c == 'Y' || (c - 32) == 'Y') 
		        break;
	        
	        else if (c == 'N' || (c - 32) == 'N')
	            return 0;
			else
			{
			    printf("\n请输入正确字符！\n");	
			    continue;
			}
        }while(1);
    }
	
}

int xianshi()
{
	Hash Table;
    InitHashTable(Table);
    
	char number[20];  // 电话号码
    char name[20];  // 用户名
    char address[50];
    
    int addr[HASHSIZE];
	FILE *fp = fopen("./book.txt","r");
	if (fp==NULL)
	{
		printf("打开文件错误， 请重试！");
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
    	printf("\n该通讯录的所有信息如下:\n\n"); 
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
		
		printf("%-20s %-20s %-50s \n\n", "姓名", "电话号码", "地址");
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
    	printf("请输入对应的操作序号：");
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


