#include<stdio.h>
#include <malloc.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType elem[MAXSIZE];
    int last;
}SeqList;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void Insert(SeqList *list) {
    if (list->last == MAXSIZE - 1) {
        printf("顺序表已满，无法插入。\n");
        return;
    }
    int v;
    printf("输入要添加的值：");
    scanf("%d",&v);
    printf("\n");
    int i;
    for (i = list->last; i >= 0 && list->elem[i] > v; i--) {
        list->elem[i + 1] = list->elem[i];
    }
    list->elem[i+1] = v;
    list->last++;
}

Node *new;

void InsertList(Node* head,Node* InsertNum) {
    Node *cur = head->next;
    Node *max_node = cur;
    Node *pre = head;
    while (cur != NULL) {
        if (cur->data > max_node->data) {
            max_node = cur;
            pre = cur;
        }
        cur = cur->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = max_node;
    pre->next = newNode;
}

void CreateNewNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("输入新添加的节点的值的大小:\n");
    int v;
    scanf("%d",&v);
    newNode->data = v;
    newNode->next = NULL;
}

void OutputSeq(SeqList *list) {
    for (int i = 0; i <= list->last; i++) {
        printf("%d ",list->elem[i]);
    }
}

void OutputListNode(Node *head) {
    Node *cur = head->next;
    while (cur != NULL) {
        printf("%d ",cur->data);
        cur = cur->next;
    }
}

int main () {
    SeqList list;
    Node head;
    list.last = -1; // 初始为空表
    head.next = NULL; // 初始为空链表

    Insert(&list);
    OutputSeq(&list);

    CreateNewNode();
    InsertList(&head,new);
    OutputListNode(&head);

    return 0;
}
