#include<stdio.h>
#include <malloc.h>

typedef  struct LinkList {
    int data;
    struct LinkList *next;
}Node,*LinkList;

void init_linklist(LinkList *l){
    //������L�����ʼ�������������ʼ��������
    *l=(LinkList)malloc(sizeof(Node));
    (*l)->next=NULL;
}

void CreateFromHead(LinkList L){
    //��������ֵ������5��������������������ͷ�巨��β�巨
    Node  *s;
    char c;
    int flag=1;
    while(flag){   /* flag��ֵΪ1��������"$"ʱ����flagΪ0���������*/
        c = getchar();
        if(c!='$'){
            s = (Node*)malloc(sizeof(Node)); /*�����½��s*/
            s -> data = c;
            s -> next = L->next;/*��s�������ͷ*/
            L -> next = s;
        }
        else
            flag = 0;
    }
    printf("\n");
}

void CreateFromTail(LinkList L)
{
    Node *r, *s;
    char c;
    int   flag =1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
    r=L;                /*rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���*/
    while(flag)         /*ѭ���������Ԫ��ֵ���������½��s�����β*/
    {
        c=getchar();
        if(c!='$')
        {
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            r->next=s;
            r=s;
        }
        else
        {
            flag=0;
            r->next=NULL;   /*�����һ������next������Ϊ�գ���ʾ����Ľ���*/
        }
    }
}


void PrintList(LinkList head) {
    Node *cur =  head->next;
    printf("���ڵĺ���Ϊ��");
    while(cur != NULL) {
        printf("%d ",cur->data-'0');
        cur = cur->next;
    }
    printf("\n");
}

void PrintListLength(LinkList head) {
    int ans = 0;
    Node* cur = head->next;
    while (cur != NULL) {
        ans++;
        cur = cur->next;
    }
    printf("��ǰ�б�ĳ���Ϊ:%d \n",ans);
}

Node * Get (LinkList  L, int i)
/*�ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬���ҵ�(1��i��n)���򷵻ظý��Ĵ洢λ��; ���򷵻�NULL*/
{
    int j;
    Node  *p;
    p=L;
    j=0;   /*��ͷ��㿪ʼɨ��*/
    while ((p->next!=NULL)&&(j<i))
    {
        p=p->next;    /* ɨ����һ���*/
        j++;   /* ��ɨ��������� */
    }
    if(i == j)
        return p;   /* �ҵ��˵�i����� */
    else
        return NULL;   /* �Ҳ�����i��0��i>n */
}

int step = 0;
Node *Locate( LinkList L,int key)
/*�ڴ�ͷ���ĵ�����L�в�������ֵ����key�Ľ�㣬���ҵ��򷵻ظý���λ��p�����򷵻�NULL*/
{
    Node *p;
    p=L->next;    /*�ӱ��е�һ����㿪ʼ */
    step = 0;
    while (p!=NULL)
    {
        step++;
        if (p->data == key) {
            p->data = key; //�����ǽ���p����data�ҵ����ڵڼ���λ��
            return p ;
        }
        p = p->next;

    }
    return NULL;
}

int InsList(LinkList L,int i,int e)
/*�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��s*/
{
    Node *pre,*s;
    int k;
    pre = L;
    k = 0;                     /*��"ͷ"��ʼ�����ҵ�i-1�����*/
    while(pre!=NULL&& k < i - 1)  /*��δ������δ�鵽��i-1��ʱ�ظ����ҵ�preָ���i-1��*/
    {
        pre = pre -> next;
        k = k + 1;
    }									/*���ҵ�i-1���*/
    if(!pre)      /*�統ǰλ��preΪ�ձ������껹δ������i����˵������λ�ò�����*/
    {
        printf("����λ�ò�����!");
        return 0;
    }
    s=(Node*)malloc(sizeof(Node));   /*����һ���µĽ��S */
    s->data=e;                       /*ֵe����s��������*/
    s->next=pre->next;				/*�޸�ָ�룬��ɲ������*/
    pre->next=s;
    return 1;
}

int DelList(LinkList L,int i,int *e)
/*�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��*/
{
    Node *pre,*r;
    int k;
    pre = L;
    k = 0;
    while(pre->next!=NULL && k<i-1)	/*Ѱ�ұ�ɾ�����i��ǰ�����i-1ʹpָ����*/
    {
        pre=pre->next;
        k=k+1;
    }								/*���ҵ�i-1�����*/
    if(!(pre->next))     /* ��whileѭ������Ϊp->next=NULL��i<1��������,������Ϊû���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��i���Ϸ���*/
    {
        printf("ɾ������λ��i������!");
        return 0;
    }
    r=pre->next;
    pre->next=pre->next->next;    /*�޸�ָ�룬ɾ�����r*/
    *e = r->data;
    free(r);    /*�ͷű�ɾ���Ľ����ռ���ڴ�ռ�*/
    printf("�ɹ�ɾ�����!");
    return 1;
}

int main () {
    LinkList head;       //ʵ����
    init_linklist(&head);
    printf("��ʼ�����\n");

    printf("ͷ���룬��ʼ�����б��ֵ��");
    CreateFromHead(head);
    PrintList(head);

    PrintListLength(head);

//    printf("β���룬��ʼ�����б��ֵ��");
//    CreateFromTail(head);
//    PrintList(head);
//
//    PrintListLength(head);

    printf("������Ҫ���ҵڼ���Ԫ��:");
    int i;
    scanf("%d",&i);
    Node* node = Get(head,i);
    printf("��ָ���ĵ�%d��Ԫ�ص�ַΪ: %p ,ֵΪ��%d\n",i,node,node->data - '0');

    printf("������Ҫ���ҵ�Ԫ�ص�ֵ:");
    int v;
    scanf("%d",&v);
    Node* node1 = Locate(head,v + '0');
    if (node1 == NULL) {
        printf("û���ҵ���ָ���Ľ��\n");
    } else {
        printf("��ָ����ֵΪ:%d�Ľ��ĵ�ַΪ:%p,������ĵ�%d��λ��\n",v,node1,step);
    }

    printf("\n�����������ڵڼ���Ԫ��ǰ����:");
    scanf("%d",&i);
    printf("ֵΪ:");
    scanf("%d",&v);
    InsList(head,i,v+'0');
    PrintList(head);

    printf("��������ɾ���ڼ������:");
    scanf("%d",&i);
    int e;
    DelList(head,3,&e);
    printf("\n��ɾ���Ľ���ֵΪ:%d:",e);
    printf("\n��ǰ����Ϊ:");
    PrintList(head);
}