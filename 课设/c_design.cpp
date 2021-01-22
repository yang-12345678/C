//
// Created by Administrator on 2020��12��28�� 0028.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100  // ����ȡʱ���洢��


typedef struct paytable {
    long Job_number;  // ����
    char name[10];  // ����
    int base_pay;  // ��������
    int job_pay;  // ְ����
    int job_allowance;  // ְ�����
    int special_allowance;  // �������
    int month_pay;  // �¹���
} PAY;


// ���˵�/��ҳ
void menu(void) {
    printf("\n******��ӭ����ְ�����ʹ���ϵͳ******\n");
    printf("1.��Ϣ ¼��\n");
    printf("2.��Ϣ ���\n");
    printf("3.��Ϣ ɾ��\n");
    printf("4.��Ϣ �޸�\n");
    printf("5.��Ϣ ���\n");
    printf("6.��Ϣ ����\n");
    printf("7.��Ϣ ��ѯ\n");
    printf("0.�˳�\n");
}

// ��ʼ��ְ����Ϣ�ļ�������ʱֻ��ʼ��һ�Σ���������� ��ӹ��� 
void init_luru() {
    int n;  // ��ʼ¼��Ա����Ϣ����
    int i;
    FILE *fp;
    fp = fopen(".\\pay_message.txt", "w");
    if (fp == NULL) {
        printf("���ļ����������ԣ�");
        exit(0);
    }

    printf("\n�������ʼ¼��ְ����Ϣ�ĸ�����");
    scanf("%d", &n);
    PAY pay[n];

    for (i = 0; i < n; i++) {
        printf("\n�������%d��ְ����:���� ���� �������� ְ���� ��λ���� �������\n", i + 1);
        scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
              &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
        printf("");
        pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;
    }

    fprintf(fp, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%-10ld %-10s %-10d %-10d %-10d %-10d %-10d",
                pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                pay[i].special_allowance, pay[i].month_pay);
        fprintf(fp, "\n");
    }

    fflush(fp);
    fclose(fp);
}

int tianjia() {
    int n;  // ��Ӹ���
    int i;

    FILE *fp = fopen("./pay_message.txt", "a");
    if (fp == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    printf("��������Ҫ��ӵ�ְԱ��Ϣ������");
    scanf("%d", &n);
    PAY pay[n];

    for (i = 0; i < n; i++) {
        printf("\n�������%d��Ҫ��ӵ�ְ����:���� ���� �������� ְ���� ��λ���� �������\n", i + 1);
        scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
              &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
        pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%-10ld %-10s %-10d %-10d %-10d %-10d %-10d",
                pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                pay[i].special_allowance, pay[i].month_pay);
        fprintf(fp, "\n");
    }

    fflush(fp);
    fclose(fp);
    return 1;

}

int shanchu_Job_number() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}

    fclose(fp1);

//    printf("%d", n);

    printf("������Ҫɾ����ְ������:");
    int number;
    scanf("%d", &number);

    int i;
    for (i = 0; i < n; i++) {
        if (pay[i].Job_number == number) {
            printf("\n��Ҫɾ��ְ���ĵ���Ϣ�ǣ�\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    printf("\n���Ƿ�ȷ��ɾ����Y/N?");
    char ch;
    getchar();
    scanf("%c", &ch);  // ˢ�»���

    if (ch == 'Y' || (ch - 32) == 'Y') {
        int j;
        for (j = i; j < n - 1; j++) {
            pay[j] = pay[j + 1];
        }
        n = n - 1;
        printf("\nɾ���ɹ���\n");
    } else if (ch == 'N' || (ch - 32) == 'N')
        printf("\n��ȡ����\n");
    else {
        printf("������������������!\n");
        return 0;
    };

//    printf("niaho ");
//    printf("%d", n);
    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("���ļ����������ԣ�");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %10s %10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        fprintf(fp2, "%-10ld %-10s %-10d %-10d %-10d %-10d %-10d",
                pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                pay[i].special_allowance, pay[i].month_pay);
        fprintf(fp2, "\n");
    }

    fflush(fp2);
    fclose(fp2);
    return 1;

}


int shanchu_name() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
    fclose(fp1);

//    printf("%d", n);

    printf("������Ҫɾ����ְ��������");
    char name[10];
    scanf("%s", name);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(pay[i].name, name) == 0) {
            printf("\n��Ҫɾ��ְ���ĵ���Ϣ�ǣ�\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    printf("\n���Ƿ�ȷ��ɾ����Y/N?");
    char ch;
    getchar();
    scanf("%c", &ch);  // ˢ�»���
    if (ch == 'Y' || (ch - 32) == 'Y') {
        int j;
        for (j = i; j < n - 1; j++) {
            pay[j] = pay[j + 1];
        }
        n = n - 1;
        printf("\nɾ���ɹ���\n");
    } else if (ch == 'N' || (ch - 32) == 'N')
        printf("\n��ȡ����\n");
    else {
        printf("������������������!\n");
        return 0;
    };

//    printf("niaho ");
//    printf("%d", n);
    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("���ļ����������ԣ�");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %10s %10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        fprintf(fp2, "%-10ld %-10s %-10d %-10d %-10d %-10d %-10d",
                pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                pay[i].special_allowance, pay[i].month_pay);
        fprintf(fp2, "\n");
    }
    fflush(fp2);
    fclose(fp2);

    return 1;
}

int shanchu() {
    printf("\n��ѡ��ɾ���ķ�ʽ��\n");
    int select;

    do {
        printf("\n0.�˳�");
        printf("\n1.������ɾ��\n");
        printf("2.������ɾ��\n\n");
        printf("��������ţ�");
        scanf("%d", &select);
        switch (select) {
            case 0:
                return 0;
            case 1:
                shanchu_Job_number();
                break;
            case 2:
                shanchu_name();
                break;
        }
    } while (1);

    return 1;
}

int xiugai_Job_number() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    printf("\n������Ҫ�޸���Ϣ��ְ�����ţ�");

    int number;

    scanf("%d", &number);
    int i;


    for (i = 0; i < n; i++) {
        if (pay[i].Job_number == number) {
            printf("\n��Ҫ�޸�ְ���ĵ���Ϣ�ǣ�\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    if (i >= n) {

        printf("\n�����ڸ�ְ������Ϣ�������ԣ�\n");
        return 0;
    }

    printf("\n�������޸ĺ�ĸ�ְ�������� ���� �������� ְ���� ��λ���� �������\n");
    scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
          &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
    pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;

    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("���ļ����������ԣ�");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        fprintf(fp2, "%-10ld %-10s %-10d %-10d %-10d %-10d %-10d",
                pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                pay[i].special_allowance, pay[i].month_pay);
        fprintf(fp2, "\n");
    }
    fflush(fp2);
    fclose(fp2);
    return 1;
}


int xiugai_name() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    printf("\n������Ҫ�޸���Ϣ��ְ��������");

    char name[10];

    scanf("%s", name);
    int i;


    for (i = 0; i < n; i++) {
        if (strcmp(pay[i].name, name) == 0) {
            printf("\n��Ҫ�޸�ְ���ĵ���Ϣ�ǣ�\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    if (i >= n) {

        printf("\n�����ڸ�ְ������Ϣ�������ԣ�\n");
        return 0;
    }

    printf("\n�������޸ĺ�ĸ�ְ�������� ���� �������� ְ���� ��λ���� �������\n");
    scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
          &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
    pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;

    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("���ļ����������ԣ�");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        fprintf(fp2, "%-10ld %-10s %-10d %-10d %-10d %-10d %-10d",
                pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                pay[i].special_allowance, pay[i].month_pay);
        fprintf(fp2, "\n");
    }
    fflush(fp2);
    fclose(fp2);
    return 1;
}

int xiugai() {
    int select;

    do {
        printf("\n0.�˳��޸�");
        printf("\n1.�������޸���Ϣ\n");
        printf("2.�������޸���Ϣ\n\n");
        printf("��������ţ�");
        scanf("%d", &select);
        switch (select) {
            case 0:
                return 0;
            case 1:
                xiugai_Job_number();
                break;
            case 2:
                xiugai_name();
                break;

        }
    } while (1);
    return 1;
}

int sort_Job_number() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    int i;
    int j;

    PAY temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {

            if (pay[i].Job_number > pay[j].Job_number) {
                temp = pay[i];
                pay[i] = pay[j];
                pay[j] = temp;
            }

        }
    printf("\n�������������Ϊ:\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
               pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
               pay[i].special_allowance, pay[i].month_pay);
    }

    return 1;
}


int sort_month_pay() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    int i;
    int j;

    PAY temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {

            if (pay[i].month_pay > pay[j].month_pay) {
                temp = pay[i];
                pay[i] = pay[j];
                pay[j] = temp;
            }

        }
    printf("\n���¹����������Ϊ��\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "�¹���", "����", "����", "��������", "ְ����", "��λ����", "�������");
    for (i = 0; i < n; i++) {
        printf("%-10d %-10ld %-10s %-10d %-10d %-10d %-10d \n",
               pay[i].month_pay, pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
               pay[i].special_allowance);
    }

    return 1;
}

int sort_name() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    int i;
    int j;
    PAY temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++)
            if (strcmp(pay[i].name, pay[j].name) > 0) {
                temp = pay[i];
                pay[i] = pay[j];
                pay[j] = temp;
            }
    }
    printf("\n�������������Ϊ��\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    for (i = 0; i < n; i++) {
        printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
               pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
               pay[i].special_allowance, pay[i].month_pay);
    }

    return 1;

}

int sort() {
    int select;

    do {
        printf("\n0.�˳����");
        printf("\n1.�������������\n");
        printf("2.���¹����������\n");
        printf("3.�������ֵ��������\n\n");
        printf("��������ţ�");
        scanf("%d", &select);
        switch (select) {
            case 0:
                return 0;
            case 1:
                sort_Job_number();
                break;
            case 2:
                sort_month_pay();
                break;
            case 3:
                sort_name();
                break;
        }
    } while (1);

    return 1;

}

int liulan() {
    printf("\n����ѡ������ķ�ʽ��������ż���\n");
    sort();

    return 1;
}

int chaxun_Job_number() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    printf("\n������Ҫ��ѯְ���Ĺ��ţ�");
    long num;
    scanf("%d", &num);

    int i;
    for (i = 0; i < n; i++) {
        if (num == pay[i].Job_number)
            break;
    }

    if (i >= n) {
        printf("\nû���ҵ���ְ���������ԣ�");
        return 0;
    }

    printf("\n��ְ����ϢΪ��\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
           pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
           pay[i].special_allowance, pay[i].month_pay);
    return 1;
}

int chaxun_name() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("���ļ����������ԣ�");
        return 0;
    }

    int n;
    fscanf(fp1, "%s %s %s %s %s %s %s", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
           &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay);
    for (n = 0; fscanf(fp1, "%d %s %d %d %d %d %d", &pay[n].Job_number, pay[n].name, &pay[n].base_pay,
                       &pay[n].job_pay, &pay[n].job_allowance, &pay[n].special_allowance, &pay[n].month_pay) !=
                EOF; n++) {}
//    printf("%d", n);
    fclose(fp1);

    printf("\n������Ҫ��ѯְ����������");
    char name[10];
    scanf("%s", name);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(name, pay[i].name) == 0)
            break;
    }

    if (i >= n) {
        printf("\nû���ҵ���ְ���������ԣ�\n");
        return 0;
    }

    printf("\n��ְ����ϢΪ��\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "����", "����", "��������", "ְ����", "��λ����", "�������", "�¹���");
    printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
           pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
           pay[i].special_allowance, pay[i].month_pay);
    return 1;
}


int chaxun() {
    int select;

    do {
        printf("\n0.�˳���ѯ");
        printf("\n1.�����Ų�ѯ\n");
        printf("2.��������ѯ\n\n");
        printf("��������ţ�");
        scanf("%d", &select);
        switch (select) {
            case 0:
                return 0;
            case 1:
                chaxun_Job_number();
                break;
            case 2:
                chaxun_name();
                break;
        }
    } while (1);

    return 1;
}


int main() {
    int a;
    do {
        menu();
        printf("�������Ӧ�Ĳ�����ţ�");
        scanf("%d", &a);
        switch (a) {
            case 0:
                exit(0);
                break;
            case 1:
                init_luru();
                break;
            case 2:
                tianjia();
                break;
            case 3:
                shanchu();
                break;
            case 4:
                xiugai();
                break;
            case 5:
                liulan();
                break;
            case 6:
                sort();
                break;
            case 7:
                chaxun();
                break;


        }
    } while (1);

    return 0;
}
