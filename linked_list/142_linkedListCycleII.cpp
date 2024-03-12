#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*   fast = head;
        ListNode*   slow = head;

        // Identify the circle
        do {
            if (fast == nullptr || fast->next == nullptr)
                return (nullptr);

            fast = fast->next->next;
            slow = slow->next;
        }
        while (fast != slow);

        // Use the formula to detect the entry node
        ListNode*   cop = head;

        while (cop != slow) {
            cop = cop->next;
            slow = slow->next;
        }
        return (slow);
    }
};