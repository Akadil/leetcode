#include <string>
#include <iostream>

using namespace std;

struct Node {
    string val;
    Node *next;
    Node *prev;

    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(string x) : val(x), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
public:

    Node*   head;
    Node*   curr;


    BrowserHistory(string homepage) {
        Node* node = new Node(homepage);

        head = node;
        curr = node;
    }
    
    void visit(string url) {
        this->clear(this->curr->next);

        Node *newNode = new Node(url);
        if (!newNode) {
            cout << "[Visit function] Error, memory wasn't allocated" << endl;
            return ;
        }

        this->curr->next = newNode;
        newNode->prev = this->curr;
        this->curr = newNode;
    }
    
    string back(int steps) {

        while (this->curr != this->head && steps != 0) {
            this->curr = this->curr->prev;
            steps--;
        }
        return (this->curr->val);
    }
    
    string forward(int steps) {
        while (this->curr->next && steps != 0) {
            this->curr = this->curr->next;
            steps--;
        }
        return (this->curr->val);
    }

    void clear(Node *head) {
        
        Node* temp;

        while (head) {
            temp = head->next;
            delete (head);
            head = temp;
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */