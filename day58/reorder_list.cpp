#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
     
};
class Solution {
public:
    void reorderList(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* pre = NULL;
        while(mid != NULL)
        {
            ListNode* next = mid->next;
            mid->next = pre;
            pre = mid;
            mid = next;
        }
        ListNode* cur = head;
        while(cur != NULL && pre != NULL)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = pre->next;
            cur->next->next = next;
            cur = next;
        }
    }
//    void reorderList(ListNode *head) {
//        ListNode* left = head;
//        ListNode* right = head;
//        if(head != NULL || head ->next != NULL)
//        {
//            while(right->next != NULL)
//            {
//                right = right->next;
//
//            }
//            ListNode* right_pre = head;
//            while(right_pre->next != NULL && right_pre->next->next != NULL)
//            {
//                right_pre = right_pre->next;
//
//            }
//
//            while(left->next != NULL && left->next->next != NULL && left < right)
//            {
//                right->next = left->next;
//                left->next = right;
//                right_pre = NULL;
//                right = right_pre;
//
//                left = left->next->next;
//
//            }
//
//        }
//
//    }

};
int main()
{
    return 0;
}
