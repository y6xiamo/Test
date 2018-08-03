#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
     
};
class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode* left = head;
        ListNode* right = head;
        if(head != NULL || head ->next != NULL)
        {
            while(right->next != NULL)
            {
                right = right->next;

            }
            ListNode* right_pre = head;
            while(right_pre->next != NULL && right_pre->next->next != NULL)
            {
                right_pre = right_pre->next;

            }

            while(left->next != NULL && left->next->next != NULL && left < right)
            {
                right->next = left->next;
                left->next = right;
                right_pre = NULL;
                right = right_pre;

                left = left->next->next;

            }

        }

    }

};
