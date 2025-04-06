/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

#include <algorithm>

// @lc code=start
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        // reverse the second half
        ListNode* middle = reverse(find_middle_r(head));

        // traverse till the middle
        ListNode* curr = head;
        int max_sum = 0;

        while (middle) {
            max_sum = std::max(max_sum, curr->val + middle->val);

            middle = middle->next;
            curr = curr->next;
        }
        return max_sum;
    }

    /**
     * if even, return the left side (1, 2, 3, 4 -> return 3)
     */
    ListNode* find_middle_r(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
// @lc code=end

