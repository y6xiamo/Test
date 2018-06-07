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
LinkNode* LinkListMeetNode(LinkNode* pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    LinkNode* fast = pHead;
    LinkNode* slow = pHead;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
LinkNode* FindCycleEntry(LinkNode* pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    LinkNode* meet_node = LinkListMeetNode(pHead);

    if(meet_node == NULL)
    {
        return NULL;
    }
    LinkNode* cur1 = pHead;
    LinkNode* cur2 = meet_node;
    while(cur1 != cur2)
    {
        if(cur1 == cur2)
        {
            break;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}
int main()
{
    LinkNode* a = CreateLinkNode('a');
    LinkNode* b = CreateLinkNode('b');
    LinkNode* c = CreateLinkNode('c');
    LinkNode* d = CreateLinkNode('d');
    LinkNode* e = CreateLinkNode('e');
    LinkNode* f = CreateLinkNode('f');
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = d;

    LinkNode* entry = FindCycleEntry(a);
    if(entry == NULL)
    {
        printf("该链表不带环\n");
    }
    else
    {
        printf("该链表环的入口点为:%c\n",entry->data);

    }
    return 0;
}
