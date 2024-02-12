/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode*   head;
        ListNode*   iter;

        if (list2 == nullptr && list1 == nullptr)
            return (nullptr);
        else if (list2 == nullptr)
            return (list1);
        else if (list1 == nullptr)
            return (list2);
        
        
        if (list2 == nullptr || list1->val < list2->val) {
            head = list1;
            iter = list1;
            list1 = list1->next;
        } else {
            head = list2;
            iter = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                iter->next = list1;
                list1 = list1->next;
            } else {
                iter->next = list2;
                list2 = list2->next;
            }
            iter = iter->next;
        }
        if (list2 == nullptr)
            iter->next = list1;
        else if (list1 == nullptr)
            iter->next = list2;
        return (head);
    }
};

/*
    @link       https://leetcode.com/problems/merge-two-sorted-lists/description/

    @results:   Time: 100%, Space: 25% 
*/