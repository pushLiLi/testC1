#include<stdio.h>
#include <wingdi.h>
#define MAXSIZE 100 //��󳤶�
#define OK 1
#define ERROR 0
typedef int ElemType ; //˳���L����
typedef struct {
    ElemType elem[MAXSIZE]; //���Ա�ռ�õ�����ռ�
    int last;   //���һ��Ԫ���������е��±�, �ձ�Ϊ-1
}SeqList;

//�Զ������뺯������˳�����ֵ������12, 10, 60, 30, 11, 17, 80��Ԫ��
/*��˳���L�е�i������Ԫ��֮ǰ����һ��Ԫ��e��
����ǰ��n=L->last+1�� i�ĺϷ�ȡֵ��Χ�� 1��i��L->last+2 */
int n;
void InsertIntoSeqElement (SeqList *list) {
    int i = 0;
    printf("��������Ԫ�ص�������");
    scanf("%d",&n);
    list->last = n;
    printf("\n������Ҫ�����Ԫ�أ�\n");
    while (i < n) {
        scanf("%d",&list->elem[i]);
        i++;
    }
}

void OutputSeqElement(SeqList *list) {
    printf("�����ѭ������£�\n");
    for (int i = 0 ; i < n ;++i) {
        printf("%d ",list->elem[i]);
    }
}

void PrintLengthOfSeqTables () {
    printf("˳���ĳ���Ϊ��%d\n",n);
}

void PrintGivenIndexElement (SeqList *list) {
    int index;
    printf("����Ҫ��ӡ�ڼ���Ԫ��\n");
    scanf("%d",&index);
    printf("%d\n",list->elem[--index]);
}

int Locate(SeqList *L, ElemType e){
    int i = 0;
    /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
    while ((i <= L->last)&&(L->elem[i] != e))/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
        i++;
    if (i <= L->last)
        return(i+1); /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
    else
        return(-1); /*��û�ҵ����򷵻ؿ����*/
}

/*��˳���L�е�i������Ԫ��֮ǰ����һ��Ԫ��e��
����ǰ��n=L->last+1�� i�ĺϷ�ȡֵ��Χ�� 1��i��L->last+2 */
int InsList(SeqList *L,int i,ElemType e) {
    int k;
    if((i < 1) || (i > L->last+2)) /*�����жϲ���λ���Ƿ�Ϸ�*/
    {
        printf("����λ��iֵ���Ϸ�");
        return (ERROR);
    }
    if(L->last >= MAXSIZE-1) {
        printf("�������޷�����");
        return(ERROR);
    }
    for(k=L->last;k>=i-1;k--) /*Ϊ����Ԫ�ض��ƶ�λ��*/
        L->elem[k+1]=L->elem[k];
    L->elem[i-1]=e; /*��C���������У���i��Ԫ�ص��±�Ϊi-1*/
    L->last++;
    n++;
    return (OK);
}

int DelList(SeqList *L,int i,ElemType *e) {
    /*��˳���L��ɾ����i������Ԫ�أ�����ָ�����e������ֵ��i�ĺϷ�ȡֵΪ1��i��L.last+1 */
    int k;
    if((i < 1)||(i > L->last+1)) {
        printf("ɾ��λ�ò��Ϸ�!");
        return(ERROR);
    }
    *e = L->elem[i-1]; /* ��ɾ����Ԫ�ش�ŵ�e��ָ��ı�����*/
    for(k=i; k<=L->last; k++)
        L->elem[k-1] = L->elem[k]; /*�������Ԫ������ǰ��*/
    L->last--;
    n--;
    return(OK);
}

int main () {
    //init
    SeqList list;
    //�Զ������뺯������˳�����ֵ������12, 10, 60, 30, 11, 17, 80��Ԫ��
    InsertIntoSeqElement(&list);
    //�Զ������������ ��ӡ��˳���L
    OutputSeqElement(&list);
    //��ӡ��˳���ĳ��ȣ�7
    PrintLengthOfSeqTables();
    //��ӡ�����Ա��3��Ԫ�أ�60
    PrintGivenIndexElement(&list);
    //���ø�����������ӡ��12��λ�ã�1
    printf("����Ҫ���ҵ�Ԫ��\n");
    int e;
    scanf("%d",&e);
    printf("ֵΪ��%d���±�Ϊ��%d\n",e,Locate(&list,e));
    //���ø�����������ֵΪ60������ǰ����Ԫ��999
    printf("������Ҫ�� ? Ԫ��֮ǰ���룺\n");
    scanf("%d",&e);
    int index = Locate(&list,e) - 1;
    printf("������Ҫ�����Ԫ��:\n");
    scanf("%d",&e);
    InsList(&list,index ,e);
    //��ӡ�����Ա� 12 10 999 60 30 11 17 80
    OutputSeqElement(&list);
    //���ø���������ɾ��L�ĵ�4��Ԫ��
    printf("\n������Ҫɾ���� ? ��Ԫ��:\n");
    int a;
    scanf("%d",&a);
    DelList(&list,a,&e);
    //��ӡ�����Ա�L
    OutputSeqElement(&list);
}