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