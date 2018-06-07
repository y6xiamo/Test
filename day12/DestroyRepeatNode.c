#include <stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* CreateLinkNode(int value)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

ListNode*  DestroyRepeatNode(ListNode* pHead)
{
    if(pHead == NULL || pHead->next == NULL)
    {
        return pHead;
    }
    ListNode* cur = pHead;
    ListNode* newHead = CreateLinkNode(0);
    ListNode* next = newHead;
    while(cur != NULL)
    {
        if(cur->next != NULL && cur->val == cur->next->val)
        {
            while(cur->next !=NULL && cur->val == cur->next->val)
            {
                cur = cur->next;
            } 
        }
        else
        {
            next->next = cur;
            next = next->next;
        }
        cur = cur->next;
    }
    next->next = cur;
    return newHead->next;
}
int main()
{
  //  ListNode* 1 = CreateLinkNode(1);
  //  ListNode* 2 = CreateLinkNode(2);
  //  ListNode* 2 = CreateLinkNode(2);
  //  ListNode* 3 = CreateLinkNode(3);
  //  ListNode* 3 = CreateLinkNode(3);
  //  ListNode* 4 = CreateLinkNode(4);
  //  ListNode* 5 = CreateLinkNode(5);
  //  ListNode* 6 = CreateLinkNode(6);
  //  1->next = 2;
  //  2->next = 2;
  //  2->next = 3;
  //  3->next = 3;
  //  3->next = 4;
  //  4->next = 4;
  //  4->next = 5;
  //  5->next = 6;
  //  6->next = NULL;
  //  ListNode* cur = DestroyRepeatNode(&1);
  //  while(cur != NULL)
  //  {
  //      printf("%d->",cur->val);
  //      cur = cur->next;
  //  }

    return 0;
}
