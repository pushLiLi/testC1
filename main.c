#include<stdio.h>
#include <malloc.h>

typedef  struct LinkList {
    int data;
    struct LinkList *next;
}Node,*LinkList;

void init_linklist(LinkList *l){
    //空链表L定义初始化（利用链表初始化函数）
    *l=(LinkList)malloc(sizeof(Node));
    (*l)->next=NULL;
}

void CreateFromHead(LinkList L){
    //给链表赋初值：包含5个以上任意整数（利用头插法或尾插法
    Node  *s;
    char c;
    int flag=1;
    while(flag){   /* flag初值为1，当输入"$"时，置flag为0，建表结束*/
        c = getchar();
        if(c!='$'){
            s = (Node*)malloc(sizeof(Node)); /*建立新结点s*/
            s -> data = c;
            s -> next = L->next;/*将s结点插入表头*/
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
    int   flag =1; /*设置一个标志，初值为1，当输入"$"时，flag为0，建表结束*/
    r=L;                /*r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点*/
    while(flag)         /*循环输入表中元素值，将建立新结点s插入表尾*/
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
            r->next=NULL;   /*将最后一个结点的next链域置为空，表示链表的结束*/
        }
    }
}


void PrintList(LinkList head) {
    Node *cur =  head->next;
    printf("现在的函数为：");
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
    printf("当前列表的长度为:%d \n",ans);
}

Node * Get (LinkList  L, int i)
/*在带头结点的单链表L中查找第i个结点，若找到(1≤i≤n)，则返回该结点的存储位置; 否则返回NULL*/
{
    int j;
    Node  *p;
    p=L;
    j=0;   /*从头结点开始扫描*/
    while ((p->next!=NULL)&&(j<i))
    {
        p=p->next;    /* 扫描下一结点*/
        j++;   /* 已扫描结点计数器 */
    }
    if(i == j)
        return p;   /* 找到了第i个结点 */
    else
        return NULL;   /* 找不到，i≤0或i>n */
}

int step = 0;
Node *Locate( LinkList L,int key)
/*在带头结点的单链表L中查找其结点值等于key的结点，若找到则返回该结点的位置p，否则返回NULL*/
{
    Node *p;
    p=L->next;    /*从表中第一个结点开始 */
    step = 0;
    while (p!=NULL)
    {
        step++;
        if (p->data == key) {
            p->data = key; //这里是借用p结点的data找到处于第几个位置
            return p ;
        }
        p = p->next;

    }
    return NULL;
}

int InsList(LinkList L,int i,int e)
/*在带头结点的单链表L中第i个位置插入值为e的新结点s*/
{
    Node *pre,*s;
    int k;
    pre = L;
    k = 0;                     /*从"头"开始，查找第i-1个结点*/
    while(pre!=NULL&& k < i - 1)  /*表未查完且未查到第i-1个时重复，找到pre指向第i-1个*/
    {
        pre = pre -> next;
        k = k + 1;
    }									/*查找第i-1结点*/
    if(!pre)      /*如当前位置pre为空表已找完还未数到第i个，说明插入位置不合理*/
    {
        printf("插入位置不合理!");
        return 0;
    }
    s=(Node*)malloc(sizeof(Node));   /*申请一个新的结点S */
    s->data=e;                       /*值e置入s的数据域*/
    s->next=pre->next;				/*修改指针，完成插入操作*/
    pre->next=s;
    return 1;
}

int DelList(LinkList L,int i,int *e)
/*在带头结点的单链表L中删除第i个元素，并将删除的元素保存到变量*e中*/
{
    Node *pre,*r;
    int k;
    pre = L;
    k = 0;
    while(pre->next!=NULL && k<i-1)	/*寻找被删除结点i的前驱结点i-1使p指向它*/
    {
        pre=pre->next;
        k=k+1;
    }								/*查找第i-1个结点*/
    if(!(pre->next))     /* 即while循环是因为p->next=NULL或i<1而跳出的,而是因为没有找到合法的前驱位置，说明删除位置i不合法。*/
    {
        printf("删除结点的位置i不合理!");
        return 0;
    }
    r=pre->next;
    pre->next=pre->next->next;    /*修改指针，删除结点r*/
    *e = r->data;
    free(r);    /*释放被删除的结点所占的内存空间*/
    printf("成功删除结点!");
    return 1;
}

int main () {
    LinkList head;       //实例化
    init_linklist(&head);
    printf("初始化完成\n");

    printf("头插入，开始输入列表的值：");
    CreateFromHead(head);
    PrintList(head);

    PrintListLength(head);

//    printf("尾插入，开始输入列表的值：");
//    CreateFromTail(head);
//    PrintList(head);
//
//    PrintListLength(head);

    printf("输入你要查找第几个元素:");
    int i;
    scanf("%d",&i);
    Node* node = Get(head,i);
    printf("你指定的第%d个元素地址为: %p ,值为：%d\n",i,node,node->data - '0');

    printf("输入你要查找的元素的值:");
    int v;
    scanf("%d",&v);
    Node* node1 = Locate(head,v + '0');
    if (node1 == NULL) {
        printf("没有找到你指定的结点\n");
    } else {
        printf("你指定的值为:%d的结点的地址为:%p,在链表的第%d个位置\n",v,node1,step);
    }

    printf("\n请输入您想在第几个元素前插入:");
    scanf("%d",&i);
    printf("值为:");
    scanf("%d",&v);
    InsList(head,i,v+'0');
    PrintList(head);

    printf("输入你想删除第几个结点:");
    scanf("%d",&i);
    int e;
    DelList(head,3,&e);
    printf("\n你删除的结点的值为:%d:",e);
    printf("\n当前链表为:");
    PrintList(head);
}