#include <stdio.h>
#include<stdlib.h>
typedef char LinkNodeType;
typedef struct LinkNode
{
    LinkNodeType data;
    struct LinkNode* next;
}LinkNode;

LinkNode* CreateLinkNode(LinkNodeType value)
{
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

int LinkListSize(LinkNode* pHead)
{
    if(pHead == NULL)
    {
        return 0;
    }
    int count = 1;
    LinkNode* cur = pHead;
    while(cur != NULL)
    {
        cur = cur->next;
        count++;
    }
    return count;
}
LinkNode* FindFirstCommonNode(LinkNode* pHead1,LinkNode* pHead2)
{
    if(pHead1 == NULL||pHead2 == NULL)
    {
        return NULL;
    }
    LinkNode* cur1 = pHead1;
    LinkNode* cur2 = pHead2;
    int len1 = LinkListSize(pHead1);
    int len2 = LinkListSize(pHead2);
    int offset = 0;
    if(len1 > len2)
    {
        offset = len1 - len2;
    }
    int i = 1;
    while(i <= offset)
    {
        cur1 = cur1->next;
        i++;
    }
    if(len1 < len2)
    {
        offset = len2 - len1;
    }
    i = 1;
    while(i <= offset)
    {
        cur2 = cur2->next;
        i++;
    }
    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1 == cur2)
        {
            return cur1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return NULL;
}
int main()
{
    LinkNode* a = CreateLinkNode('a');
    LinkNode* b = CreateLinkNode('b');
    LinkNode* c = CreateLinkNode('c');
    LinkNode* d = CreateLinkNode('d');
    LinkNode* e = CreateLinkNode('e');
    LinkNode* f = CreateLinkNode('f');
    LinkNode* m = CreateLinkNode('m');
    LinkNode* n = CreateLinkNode('n');
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;
    m->next = n;
    n->next = c;

    LinkNode* common_node = FindFirstCommonNode(a,m);
    if(common_node != NULL)
    {
        printf("找到了第一个公共结点：%c\n",common_node->data);
    }
    else
    {
        printf("没有找到公共结点\n");
    }
    return 0;
}
