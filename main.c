#include<stdio.h>
#include <wingdi.h>
#define MAXSIZE 100 //最大长度
#define OK 1
#define ERROR 0
typedef int ElemType ; //顺序表L定义
typedef struct {
    ElemType elem[MAXSIZE]; //线性表占用的数组空间
    int last;   //最后一个元素在数组中的下标, 空表为-1
}SeqList;

//自定义输入函数，给顺序表赋初值：包含12, 10, 60, 30, 11, 17, 80等元素
/*在顺序表L中第i个数据元素之前插入一个元素e。
插入前表长n=L->last+1， i的合法取值范围是 1≤i≤L->last+2 */
int n;
void InsertIntoSeqElement (SeqList *list) {
    int i = 0;
    printf("输入插入的元素的数量：");
    scanf("%d",&n);
    list->last = n;
    printf("\n输入你要插入的元素：\n");
    while (i < n) {
        scanf("%d",&list->elem[i]);
        i++;
    }
}

void OutputSeqElement(SeqList *list) {
    printf("输出的循序表如下：\n");
    for (int i = 0 ; i < n ;++i) {
        printf("%d ",list->elem[i]);
    }
}

void PrintLengthOfSeqTables () {
    printf("顺序表的长度为：%d\n",n);
}

void PrintGivenIndexElement (SeqList *list) {
    int index;
    printf("输入要打印第几个元素\n");
    scanf("%d",&index);
    printf("%d\n",list->elem[--index]);
}

int Locate(SeqList *L, ElemType e){
    int i = 0;
    /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
    while ((i <= L->last)&&(L->elem[i] != e))/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
        i++;
    if (i <= L->last)
        return(i+1); /*若找到值为e的元素，则返回其序号*/
    else
        return(-1); /*若没找到，则返回空序号*/
}

/*在顺序表L中第i个数据元素之前插入一个元素e。
插入前表长n=L->last+1， i的合法取值范围是 1≤i≤L->last+2 */
int InsList(SeqList *L,int i,ElemType e) {
    int k;
    if((i < 1) || (i > L->last+2)) /*首先判断插入位置是否合法*/
    {
        printf("插入位置i值不合法");
        return (ERROR);
    }
    if(L->last >= MAXSIZE-1) {
        printf("表已满无法插入");
        return(ERROR);
    }
    for(k=L->last;k>=i-1;k--) /*为插入元素而移动位置*/
        L->elem[k+1]=L->elem[k];
    L->elem[i-1]=e; /*在C语言数组中，第i个元素的下标为i-1*/
    L->last++;
    n++;
    return (OK);
}

int DelList(SeqList *L,int i,ElemType *e) {
    /*在顺序表L中删除第i个数据元素，并用指针参数e返回其值。i的合法取值为1≤i≤L.last+1 */
    int k;
    if((i < 1)||(i > L->last+1)) {
        printf("删除位置不合法!");
        return(ERROR);
    }
    *e = L->elem[i-1]; /* 将删除的元素存放到e所指向的变量中*/
    for(k=i; k<=L->last; k++)
        L->elem[k-1] = L->elem[k]; /*将后面的元素依次前移*/
    L->last--;
    n--;
    return(OK);
}

int main () {
    //init
    SeqList list;
    //自定义输入函数，给顺序表赋初值：包含12, 10, 60, 30, 11, 17, 80等元素
    InsertIntoSeqElement(&list);
    //自定义输出函数， 打印出顺序表L
    OutputSeqElement(&list);
    //打印出顺序表的长度：7
    PrintLengthOfSeqTables();
    //打印出线性表第3个元素：60
    PrintGivenIndexElement(&list);
    //调用给定函数，打印出12的位置：1
    printf("输入要查找的元素\n");
    int e;
    scanf("%d",&e);
    printf("值为：%d的下标为：%d\n",e,Locate(&list,e));
    //调用给定函数，在值为60的数据前插入元素999
    printf("输入你要在 ? 元素之前插入：\n");
    scanf("%d",&e);
    int index = Locate(&list,e);
    printf("输入你要插入的元素:\n");
    scanf("%d",&e);
    InsList(&list,index ,e);
    //打印出线性表： 12 10 999 60 30 11 17 80
    OutputSeqElement(&list);
    //调用给定函数，删除L的第4个元素
    printf("\n输入你要删除第 ? 个元素:\n");
    int a;
    scanf("%d",&a);
    DelList(&list,a,&e);
    //打印出线性表L
    OutputSeqElement(&list);
}
