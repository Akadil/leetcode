#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            Node*   node = map[key];

            remove(node);
            add_back(node);
            return (map[key]->value);
        }
        return (-1);
    }
    
    void put(int key, int value) {

        if (map.find(key) != map.end()) {       // update existing one
            Node*   node = map[key];

            node->value = value;
            remove(node);
            add_back(node);
        }
        else {                                  // Add a new one
            Node*   node = new Node(key, value);
            
            map[key] = node;

            if (size == capacity) {
                Node*   to_delete;

                to_delete = front;
                map.erase(to_delete->key);
                remove(to_delete);
                delete to_delete;
                size--;
            }
            size++;
            add_back(node);
        }
    }

private:
    unordered_map<int, Node*> map;
    Node*                   front = nullptr;          // The least recent
    int                     capacity;
    int                     size;

    void    add_back(Node* to_add) {

        if (front == nullptr) {         // if front doesn't exist
            front = to_add;
        } else if (front->next != nullptr) {         // if there are several elements
            Node*   last;

            last = front->prev;
            last->next = to_add;
            to_add->prev = last;
            front->prev = to_add;
            to_add->next = front;
        } 
        else {                          // if there is only one element
            front->next = to_add;
            front->prev = to_add;
            to_add->next = front;
            to_add->prev = front;
        }
    }

    void    remove(Node* to_remove) {
        Node*   node;

        if (size == 1) {
            front = nullptr;
        } 
        else if (size == 2) {
            front = to_remove->next;

            front->next = nullptr;
            front->prev = nullptr;
        } 
        else {
            if (front == to_remove) {
                front = to_remove->next;
            }
            to_remove->prev->next = to_remove->next;
            to_remove->next->prev = to_remove->prev;
        }
    }

};

int main() {
    // {
    //     // Recreate this case:
    //     /*
    //         Input
    //         ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    //         [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    //         Output
    //         [null, null, null, 1, null, -1, null, -1, 3, 4]
    //     */

    //     LRUCache*   obj = new LRUCache(2);

    //     obj->put(1, 1);
    //     obj->put(2, 2);
    //     cout << "obj->get(1): " << obj->get(1) << endl;
    //     obj->put(3, 3);
    //     cout << "obj->get(2): " << obj->get(2) << endl;
    //     obj->put(4, 4);
    //     cout << "obj->get(1): " << obj->get(1) << endl;
    //     cout << "obj->get(3): " << obj->get(3) << endl;
    //     cout << "obj->get(4): " << obj->get(4) << endl;
    // }
    {
        // Recreate this case:
        /*
            ["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
[[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]
        */

        LRUCache*   obj = new LRUCache(3);

        obj->put(1, 1);
        obj->put(2, 2);
        obj->put(3, 3);
        obj->put(4, 4);
        cout << "obj->get(4): " << obj->get(4) << endl;
        cout << "obj->get(3): " << obj->get(3) << endl;
        cout << "obj->get(2): " << obj->get(2) << endl;
        cout << "obj->get(1): " << obj->get(1) << endl;
        obj->put(5, 5);
        cout << "obj->get(1): " << obj->get(1) << endl;
        cout << "obj->get(2): " << obj->get(2) << endl;
        cout << "obj->get(3): " << obj->get(3) << endl;
        cout << "obj->get(4): " << obj->get(4) << endl;
        cout << "obj->get(5): " << obj->get(5) << endl;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */