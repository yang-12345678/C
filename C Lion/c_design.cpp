//
// Created by Administrator on 2020年12月28日 0028.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100  // 都读取时最大存储数


typedef struct paytable {
    long Job_number;  // 工号
    char name[10];  // 姓名
    int base_pay;  // 基本工资
    int job_pay;  // 职务工资
    int job_allowance;  // 职务津贴
    int special_allowance;  // 特殊津贴
    int month_pay;  // 月工资
} PAY;


// 主菜单/首页
void menu(void) {
    printf("\n******欢迎进入职工工资管理系统******\n");
    printf("1.信息 录入\n");
    printf("2.信息 添加\n");
    printf("3.信息 删除\n");
    printf("4.信息 修改\n");
    printf("5.信息 浏览\n");
    printf("6.信息 排序\n");
    printf("7.信息 查询\n");
    printf("0.退出\n");
}

// 初始化职工信息文件，工作时只初始化一次，后面添加用 添加功能 
void init_luru() {
    int n;  // 初始录入员工信息个数
    int i;
    FILE *fp;
    fp = fopen(".\\pay_message.txt", "w");
    if (fp == NULL) {
        printf("打开文件错误，请重试！");
        exit(0);
    }

    printf("\n请输入初始录入职工信息的个数：");
    scanf("%d", &n);
    PAY pay[n];

    for (i = 0; i < n; i++) {
        printf("\n请输入第%d个职工的:工号 姓名 基本工资 职务工资 岗位津贴 特殊津贴\n", i + 1);
        scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
              &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
        printf("");
        pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;
    }

    fprintf(fp, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
    int n;  // 添加个数
    int i;

    FILE *fp = fopen("./pay_message.txt", "a");
    if (fp == NULL) {
        printf("打开文件错误，请重试！");
        return 0;
    }

    printf("请输入需要添加的职员信息个数：");
    scanf("%d", &n);
    PAY pay[n];

    for (i = 0; i < n; i++) {
        printf("\n请输入第%d个要添加的职工的:工号 姓名 基本工资 职务工资 岗位津贴 特殊津贴\n", i + 1);
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
        printf("打开文件错误，请重试！");
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

    printf("请输入要删除的职工工号:");
    int number;
    scanf("%d", &number);

    int i;
    for (i = 0; i < n; i++) {
        if (pay[i].Job_number == number) {
            printf("\n您要删除职工的的信息是：\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    printf("\n您是否确认删除，Y/N?");
    char ch;
    getchar();
    scanf("%c", &ch);  // 刷新缓存

    if (ch == 'Y' || (ch - 32) == 'Y') {
        int j;
        for (j = i; j < n - 1; j++) {
            pay[j] = pay[j + 1];
        }
        n = n - 1;
        printf("\n删除成功！\n");
    } else if (ch == 'N' || (ch - 32) == 'N')
        printf("\n已取消！\n");
    else {
        printf("输入有误，请重新输入!\n");
        return 0;
    };

//    printf("niaho ");
//    printf("%d", n);
    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("打开文件错误，请重试！");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %10s %10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
        printf("打开文件错误，请重试！");
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

    printf("请输入要删除的职工姓名：");
    char name[10];
    scanf("%s", name);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(pay[i].name, name) == 0) {
            printf("\n您要删除职工的的信息是：\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    printf("\n您是否确认删除，Y/N?");
    char ch;
    getchar();
    scanf("%c", &ch);  // 刷新缓存
    if (ch == 'Y' || (ch - 32) == 'Y') {
        int j;
        for (j = i; j < n - 1; j++) {
            pay[j] = pay[j + 1];
        }
        n = n - 1;
        printf("\n删除成功！\n");
    } else if (ch == 'N' || (ch - 32) == 'N')
        printf("\n已取消！\n");
    else {
        printf("输入有误，请重新输入!\n");
        return 0;
    };

//    printf("niaho ");
//    printf("%d", n);
    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("打开文件错误，请重试！");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %10s %10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
    printf("\n请选择删除的方式：\n");
    int select;

    do {
        printf("\n0.退出");
        printf("\n1.按工号删除\n");
        printf("2.按姓名删除\n\n");
        printf("请输入序号：");
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
        printf("打开文件错误，请重试！");
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

    printf("\n请输入要修改信息的职工工号：");

    int number;

    scanf("%d", &number);
    int i;


    for (i = 0; i < n; i++) {
        if (pay[i].Job_number == number) {
            printf("\n您要修改职工的的信息是：\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    if (i >= n) {

        printf("\n不存在该职工的信息，请重试！\n");
        return 0;
    }

    printf("\n请输入修改后的该职工：工号 姓名 基本工资 职务工资 岗位津贴 特殊津贴\n");
    scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
          &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
    pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;

    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("打开文件错误，请重试！");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
        printf("打开文件错误，请重试！");
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

    printf("\n请输入要修改信息的职工姓名：");

    char name[10];

    scanf("%s", name);
    int i;


    for (i = 0; i < n; i++) {
        if (strcmp(pay[i].name, name) == 0) {
            printf("\n您要修改职工的的信息是：\n");
            printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
            printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
                   pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
                   pay[i].special_allowance, pay[i].month_pay);
            break;
        }

    }

    if (i >= n) {

        printf("\n不存在该职工的信息，请重试！\n");
        return 0;
    }

    printf("\n请输入修改后的该职工：工号 姓名 基本工资 职务工资 岗位津贴 特殊津贴\n");
    scanf("%ld %s %d %d %d %d", &pay[i].Job_number, pay[i].name, &pay[i].base_pay,
          &pay[i].job_pay, &pay[i].job_allowance, &pay[i].special_allowance);
    pay[i].month_pay = pay[i].base_pay + pay[i].job_pay + pay[i].job_allowance + pay[i].special_allowance;

    FILE *fp2 = fopen("./pay_message.txt", "w");
    if (fp2 == NULL) {
        printf("打开文件错误，请重试！");
        exit(0);
    }

    fprintf(fp2, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
        printf("\n0.退出修改");
        printf("\n1.按工号修改信息\n");
        printf("2.按姓名修改信息\n\n");
        printf("请输入序号：");
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
        printf("打开文件错误，请重试！");
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
    printf("\n按工号排序浏览为:\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
        printf("打开文件错误，请重试！");
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
    printf("\n按月工资排序浏览为：\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "月工资", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴");
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
        printf("打开文件错误，请重试！");
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
    printf("\n按姓名排序浏览为：\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
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
        printf("\n0.退出浏览");
        printf("\n1.按工号排序浏览\n");
        printf("2.按月工资排序浏览\n");
        printf("3.按姓名字典排序浏览\n\n");
        printf("请输入序号：");
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
    printf("\n请您选择浏览的方式，输入序号即可\n");
    sort();

    return 1;
}

int chaxun_Job_number() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("打开文件错误，请重试！");
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

    printf("\n请输入要查询职工的工号：");
    long num;
    scanf("%d", &num);

    int i;
    for (i = 0; i < n; i++) {
        if (num == pay[i].Job_number)
            break;
    }

    if (i >= n) {
        printf("\n没有找到该职工，请重试！");
        return 0;
    }

    printf("\n该职工信息为：\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
    printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
           pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
           pay[i].special_allowance, pay[i].month_pay);
    return 1;
}

int chaxun_name() {
    PAY pay[N];

    FILE *fp1 = fopen("./pay_message.txt", "r+");
    if (fp1 == NULL) {
        printf("打开文件错误，请重试！");
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

    printf("\n请输入要查询职工的姓名：");
    char name[10];
    scanf("%s", name);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(name, pay[i].name) == 0)
            break;
    }

    if (i >= n) {
        printf("\n没有找到该职工，请重试！\n");
        return 0;
    }

    printf("\n该职工信息为：\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "工号", "姓名", "基本工资", "职务工资", "岗位津贴", "特殊津贴", "月工资");
    printf("%-10ld %-10s %-10d %-10d %-10d %-10d %-10d\n",
           pay[i].Job_number, pay[i].name, pay[i].base_pay, pay[i].job_pay, pay[i].job_allowance,
           pay[i].special_allowance, pay[i].month_pay);
    return 1;
}


int chaxun() {
    int select;

    do {
        printf("\n0.退出查询");
        printf("\n1.按工号查询\n");
        printf("2.按姓名查询\n\n");
        printf("请输入序号：");
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
        printf("请输入对应的操作序号：");
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
