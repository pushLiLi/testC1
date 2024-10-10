#include<stdio.h>
#include <malloc.h>

typedef struct LinkList {
    int data;
    struct LinkList *next;
} Node, *LinkList;

// 初始化链表
void init_linklist(LinkList *l) {
    *l = (LinkList)malloc(sizeof(Node));
    (*l)->next = NULL;
}

// 从尾部创建链表
void CreateFromTail(LinkList L) {
    Node *r, *s;
    char c;
    int flag = 1;  // 当输入"$"时，结束输入
    r = L;  // 指向链表的尾部
    while (flag) {
        c = getchar();
        if (c != '$') {
            s = (Node*)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        } else {
            flag = 0;
            r->next = NULL;  // 链表结束
        }
    }
}

// 打印链表
void PrintList(LinkList head) {
    Node *cur = head->next;
    while (cur != NULL) {
        printf("%d -> ", cur->data - '0');  // 打印数字
        cur = cur->next;
    }
    printf("NULL\n");
}

// 拆分链表
void SplitList(LinkList L, LinkList *L1, LinkList *L2) {
    Node *cur = L->next;
    Node *tailL1 = *L1;
    int count = 1;

    while (cur != NULL) {
        if (count % 2 != 0) {  // 奇数位置节点给 L1
            tailL1->next = cur;
            tailL1 = cur;
        } else {  // 偶数位置节点逆序插入 L2
            Node *nextNode = cur->next;
            cur->next = *L2;
            *L2 = cur;
            cur = nextNode;
            count++;
            continue;
        }
        cur = cur->next;
        count++;
    }
    //为L2添加头结点
    cur = *L2;
    Node *node;
    init_linklist(&node);
    node->next = cur;
    *L2 = node;

    tailL1->next = NULL;

    //删除L2的尾结点，进来的是一个指针，在尾结点，打印会遍历到，要删除
    cur = *L2;
    while(cur->next->next != NULL) {
        cur = cur->next;
    }
    cur->next = NULL;
}

int main() {
    // 初始化链表
    Node *L, *L1, *L2;
    init_linklist(&L);
    init_linklist(&L1);  // L1 使用 L 的头节点
//    init_linklist(&L2);  // L2 头节点

    printf("请输入链表（以$结束）：\n");
    CreateFromTail(L);

    printf("\n原链表:\n");
    PrintList(L);

    // 拆分链表
    SplitList(L, &L1, &L2);

    // 输出拆分后的链表
    printf("\nL1:\n");
    L->next = L1->next;
    PrintList(L);

    printf("\nL2:\n");
    PrintList(L2);

    return 0;
}
