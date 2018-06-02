#include <stdio.h>
#include<stdlib.h>
typedef char LinkListType;
typedef struct LinkNode
{
    LinkListType data;
    struct LinkNode* next;
}LinkNode;

LinkNode*  CreateNode(LinkNode** head,LinkListType value)
{
    if(head == NULL)
    {
        return NULL;
    }
    LinkNode* new_node = (LinkNode* )malloc(sizeof(head));
    new_node->data = value;
    new_node->next = NULL;
    return  new_node;
}
void DestroyNode(LinkNode* node)
{
    free(node);
}
LinkNode* FindLastKNode(LinkNode* head,int k)
{
    if(head == NULL)
    {
        return NULL;//链表为空
    }
    LinkNode* fast = head;
    LinkNode* slow = head;
    int i = 0;
    while( i < k)
    {
        //先让快指针走k步
        if(fast == NULL)
        {
            break;
        }
        fast = fast->next;
        i++;
    }
    if(i != k)
    {
        return NULL;//k超出链表长度
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    LinkNode* head;
    LinkNode* a = CreateNode(&head,'a');
    LinkNode* b = CreateNode(&head,'b');
    LinkNode* c = CreateNode(&head,'c');
    LinkNode* d = CreateNode(&head,'d');
    LinkNode* e = CreateNode(&head,'e');
    LinkNode* f = CreateNode(&head,'f');
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;
    LinkNode* to_find = FindLastKNode(head,3);
    printf("to_find expected d,actual is %c\n",to_find->data);

    return 0;
}
