/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (!head, left == right)
                return head;
            
            // Preprocess: 
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            
            // move ptr to the node before the reversable chain
            ListNode* prev = dummy;
            for (int i = 0; i < left - 1; ++i) {
                prev = prev->next;
            }
            
            // traverse the reversable chain
            ListNode* curr = prev->next;
            for (int i = 0; i < right - left; ++i) {
                ListNode* nextNode = remove_next(curr);
                add_next(prev, nextNode);
            }
            return dummy->next;
        }
        
        /**
        * returns removed node
        */
        ListNode*   remove_next(ListNode* head) {
            if (!head->next)
                return head;
            
            ListNode* nextNode = head->next;
            head->next = nextNode->next;
            nextNode->next = nullptr;
            return nextNode;
        }
        
        void    add_next(ListNode* head, ListNode* node) {
            node->next = head->next;
            head->next = node;
        }
    };
// @lc code=end

