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
    ListNode* reverseList(ListNode* head) {

        // Method: Brutal force
        ListNode*   temp;
        ListNode*   prev;

        prev = nullptr;
        while (head != nullptr) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return (prev);
    }
};

/**
    1. The first idea that comes to mind is traverse the list, and
            change the pointers on the go
    
    2. Somehow change only the value of nodes without changing the pointers

*/