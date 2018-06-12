#include <stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

ListNode* CreateListNode(int val)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void Destroy(ListNode* node)
{
    free(node);
}
int LinkListSize(ListNode* head)
{
    if(head == NULL)
    {
        return 0;
    }
    int count = 0;
    ListNode* cur = head;
    for( ;cur != NULL;cur = cur->next)
    {
        count++;
    }
    return count;
}
ListNode* removeNthFromEnd(ListNode** head,int k)
{
    if(head == NULL || *head == NULL)
    {
        return NULL;
    }

    //计算链表的长度
    int len = LinkListSize(*head);
    if(k > len)
    {
        //k不合法
        return NULL;
    }

    if(k == len)
    {
        //要删除的是头结点
        ListNode* to_delete = *head;
        *head = to_delete->next;
        to_delete = NULL;
    }
    //找到要删除元素的前一个
    int i = 0;
    ListNode* pre = *head;
    for( ;i < len - k -1;i++)
    {
        pre = pre->next;
    }
    ListNode* to_delete = pre->next;
    pre->next = to_delete->next;
    to_delete->next = NULL;
    Destroy(to_delete);
    return *head;
}

int main()
{
    ListNode* node_1 = CreateListNode(1);
    ListNode* node_2 = CreateListNode(2);
    ListNode* node_3 = CreateListNode(3);
    ListNode* node_4 = CreateListNode(4);
    ListNode* node_5 = CreateListNode(5);

    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = NULL;

    ListNode* head = removeNthFromEnd(&node_1,2);

    ListNode* cur = head;
    while(cur != NULL)
    {
        printf("%d ",cur->val);
        cur = cur->next;

    }
    printf("\n");
    return 0;
}
