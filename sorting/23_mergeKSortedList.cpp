#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            Normally, I will merge lists one by one:

                1 + 2, (1 + 2) + 3, (1 + 2 + 3) + 4, and etc
            
            But, it is not efficient, it more like an insertion sort, which
            is not the optimal one, so we are going to use the merge sort 
            algorithm

            Merge ((1 + 8) + (2 + 7)) + ((3 + 6) + (4 + 5))
        */

        int n = lists.size();

        if (n == 0)
            return (nullptr);

        // Traverse till only one sorted list left
        while (n > 1) {

            // Merge the first and last
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeLists(lists[i], lists[n - i - 1]);
            }

            // Get the index of the last merged list
            n = (n + 1) / 2;
        }
        return (lists[0]);
    }


    ListNode*   mergeLists(ListNode* left, ListNode* right) {
        if (left == nullptr && right == nullptr)
            return (nullptr);
        else if (left == nullptr)
            return (right);
        else if (right == nullptr) 
            return (left);
        
        ListNode    *head = nullptr;
        ListNode    *tail = nullptr;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                addNode(left, &head, &tail);
                left = left->next;
            } else {
                addNode(right, &head, &tail);
                right = right->next;
            }
        }

        if (right != nullptr) {
            addNode(right, &head, &tail);
        } else if (left != nullptr) {
            addNode(left, &head, &tail);
        }
        return (head);
    }


    void    addNode(ListNode *node, ListNode **head, ListNode **tail) {
        if (*head == nullptr) {
            *head = node;
            *tail = node;
        } else {
            (*tail)->next = node;
            *tail = node;
        }
    }
};


class SolutionOld {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode    *head = nullptr;
        ListNode    *tail = nullptr;
        int         length = get_length(lists);


        // Loop till all elements sorted
        while (length != 0) {
         
            // traverse through each list, and find the minimal
            int index_min = -1;
            
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == nullptr)
                    continue ;
                if (index_min == -1) {
                    index_min = i;
                } else {
                    if (lists[i]->val < lists[index_min]->val)
                        index_min = i;
                }
            }

            // Retrieve the minimal node
            ListNode    *node = lists[index_min];
            lists[index_min] = lists[index_min]->next;

            push_node(node, &head, &tail);
            length--;
        }
        return (head);
    }

    void    push_node(ListNode *node, ListNode **head, ListNode **tail) {
        if (*head == nullptr) {
            *head = node;
            *tail = node;
        } else {
            (*tail)->next = node;
            *tail = node;
        }
    }

    int get_length(vector<ListNode*>& lists) {
        int length;

        length = 0;
        for (int i = 0; i < lists.size(); ++i) {
            length += get_length_listNode(lists[i]);
        }
        return (length);
    }

    int get_length_listNode(ListNode *node) {
        int len = 0;

        while (node) {
            node = node->next;
            len++;
        }
        return (len);
    }
};