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
    Book* elem;
    int size;
    int length;  // 当前长度
}Hash;

int InitHashTable(Hash* H)
{
    H->size = HASHSIZE;
    H->length = 0;  // 当前使用长度为0
    H->elem = (Book*)malloc(HASHSIZE * sizeof(Book));

    if (!H->elem)
    {
        printf("内存空间分配失败， 请重试！");
        return -1;
    }

    for (int i = 0; i < H->size; i++)
    {
        H->elem[i].flag = -1;
    }

    return 1;
}

// 获取键值
int GetKey(char Num[])
{
    int len = strlen(Num);
    int key = 0;
    for (int i = 0; i < len; i++)
    {
        key += Num[i] - '0';
    }
    return key % HASHSIZE; // key, (0,99)
}

// 线性探测再散列处理冲突
int InsertHash(Hash* H, char Num[])
{
    int addr;
    addr = GetKey(Num);
    int i = 0;
    while (H->elem[addr].flag != -1)
    {
        addr = (addr + 1) % HASHSIZE;
    }

    return addr;
}

// 写入文件
int Book_write(Hash* H, int addr[], int n)
{
    FILE* fp = fopen("./book.txt", "w");
    if (fp == NULL)
    {
        printf("打开文件错误，请重试！");
        return -1;
    }

    fprintf(fp, "%-20s %-20s %-50s", "姓名", "电话号码", "地址");

    int i;
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%-20s %-20s %-50s",
            H->elem[addr[i]].name, H->elem[addr[i]].number, H->elem[addr[i]].address);
        fprintf(fp, "\n");
    }

    fflush(fp);
    fclose(fp);
}

// 创建新的通讯录
int Creat()
{
    Hash* Table;
    InitHashTable(Table);

    char name[20];
    char number[20];
    char address[50];

    int n; // 用户数量
    

    printf("请输入新的通讯录的用户数量：");
    scanf_s("%d", &n);
    int addr[100]; // 哈希表存放地址
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d位用户的姓名：", i + 1);
        scanf_s("%s", name);
        printf("请输入第%d位用户的电话号码：", i + 1);
        scanf_s("%s", number);
        printf("请输入第%d位用户的地址：", i + 1);
        scanf_s("%s", address);

        addr[i] = InsertHash(Table, number);
        strcpy(Table->elem[addr[i]].name, name);
        strcpy(Table->elem[addr[i]].number, number);
        strcpy(Table->elem[addr[i]].address, address);
        Table->elem[addr[i]].flag = 0;
        Table->length++;
    }

    Book_write(Table, addr, n);

    return 1;

}


int main()
{
    printf("");
    Creat();
    return 0;
}
