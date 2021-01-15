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
    int length;  // ��ǰ����
}Hash;

int InitHashTable(Hash &H)
{
    H.size = HASHSIZE;
    H.length = 0;  // ��ǰʹ�ó���Ϊ0
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
    while(H.elem[i].flag != -1)
    {
        addr = (addr+1) % HASHSIZE;
    }

    return addr;
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
    fprintf(fp, "%-20s %-20s %-50s", "����", "�绰����", "��ַ");
    int i;
    for(int i =0;i<n;i++)
    {
        fprintf(fp, "%-20s %-20s %-50s",
                H.elem[addr[i]].name, H.elem[addr[i]].number, H.elem[addr[i]].address);
        fprintf(fp, "\n");
    }

    fflush(fp);
    fclose(fp);
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
        printf("�������%dλ�û���������", i+1);
        scanf("%s", name);
        printf("�������%dλ�û��ĵ绰���룺", i+1);
        scanf("%s", number);
        printf("�������%dλ�û��ĵ�ַ��", i+1);
        scanf("%s", address);

        addr[i] = InsertHash(Table, number);
        strcpy(Table.elem[addr[i]].name, name);
        strcpy(Table.elem[addr[i]].number, number);
        strcpy(Table.elem[addr[i]].address, address);
        Table.elem[addr[i]].flag = 0;
        Table.length++;
    }

    Book_write(Table, addr, n);
    printf("�����ɹ���");
}




int main()
{
    Creat();
    return 0;
}

