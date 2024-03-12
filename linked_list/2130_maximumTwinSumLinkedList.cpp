#include <iostream>
#include <stack>

using namespace std;

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
        ListNode*   fast = head;
        ListNode*   slow = head;
        stack<int>  myStack;

        // Get the first half of twins
        while (fast && fast->next) {
            myStack.push(slow->val);
            
            fast = fast->next->next;
            slow = slow->next;
        }

        // Calculate the twin sums
        int maxSum = 0;

        // slow = slow->next;
        while (slow) {
            int twin = myStack.top();
            myStack.pop();

            maxSum = max(maxSum, slow->val + twin);
            slow = slow->next;
        }
        return (maxSum);
    }
};

int main(void) {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution*   sol = new Solution();

    cout << sol->pairSum(head) << endl;

    return 0;
}