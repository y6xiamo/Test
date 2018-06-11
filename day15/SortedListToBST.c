#include <stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ListNode;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

ListNode* CreateListNode(int val)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void DestroyListNode(ListNode* node)
{
    free(node);
    return;
}

TreeNode* CreateTreeNode(int val)
{
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void DestroyTreeNode(TreeNode* node)
{
    free(node);
}
TreeNode* SortListToBST(ListNode* head)
{
//    printf("hahaha\n");
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return CreateTreeNode(head->val);
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* pre = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
//        printf("fast: %d",fast->val);
        pre = slow;
        slow = slow->next;
        
    }
 //   printf("slow: %d",slow->val);
    fast = slow->next;
    slow->next = NULL;

    TreeNode* cur_root = CreateTreeNode(slow->val);
    pre->next = NULL;
    if(slow->val != head->val)
    {
        cur_root->left = SortListToBST(head);
    }
    cur_root->right = SortListToBST(fast);
    return cur_root;
}

void PreOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->val);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void InOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ",root->val);
    InOrder(root->right);
    return;
}
int main()
{
    ListNode* node_1 = CreateListNode(1);
    ListNode* node_2 = CreateListNode(2);
    ListNode* node_3 = CreateListNode(3);
    ListNode* node_4 = CreateListNode(4);
    ListNode* node_5 = CreateListNode(5);
    ListNode* node_6 = CreateListNode(6);
    ListNode* node_7 = CreateListNode(7);

    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    node_6->next = node_7;
    node_7->next = NULL;

   TreeNode* root =  SortListToBST(node_1);

   printf("\n[先序遍历：]\n");
   PreOrder(root);
   printf("\n[中序遍历：]\n");
   InOrder(root);
   printf("\n");
     return 0;
}
