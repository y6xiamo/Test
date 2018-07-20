#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* swapPairs(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
            //非法输入
        }
        if(head->next == NULL)
        {
            return head;
            //只有一个节点，不用返回
        }
        ListNode* pre = head;
        ListNode* next = head->next;
        while(pre != NULL || pre->next != NULL)
        {
            ListNode* temp = head->next;
            head->next = next->next;
            next->next = temp;
            head = head->next;
            next = head->next->next;
        }
    }
};
int main()
{
    return 0;
}
