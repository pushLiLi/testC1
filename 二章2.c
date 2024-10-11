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

int main() {
    //实例化，赋值
    LinkList head;
    init_linklist(&head);
    printf("输入值:");
    CreateFromTail(head);

    //找最大值
    Node* cur = head->next;
    int a = 0,v = cur->data ;
    while (cur != NULL) {
        if (cur->data > v) {
            a = cur->data;
            v = a;
        }
        cur = cur->next;
    }
    //删除最大值结点
    Node * c = head;
    Node * d;
    while (c->next->data != a) {
        //存放删除的元素的上一个元素
        c = c->next;
    }
    d = c->next;
    c->next = c->next->next;
    //释放内存
    free(d);

    PrintList(head);
   

}
