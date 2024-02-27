#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int     key;
        int     value;
        Node*   next;

        Node(int key, int value): key(key), value(value), next(nullptr) {}
};

class HashTable {
public:
    HashTable(int capacity): capacity(capacity), size(0) {
        table.resize(capacity, nullptr);
    }

    void insert(int key, int value) {
        int     index = hashFunction(key);
        Node*   node = table[index];

        if (node == nullptr) {
            table[index] = new Node(key, value);
            size++;
        } else {
            Node* prev = nullptr;

            while (node) {
                if (node->key == key) {
                    node->value = value;
                    return ;
                }
                prev = node;
                node = node->next;
            }
            prev->next = new Node(key, value);
            size++;
        }

        if ((float)size / capacity >= 0.5) {
            // cout << "I was here " << capacity << " " << size << " " << (float)size / capacity << endl;
            resize();
        }
    }

    int get(int key) {
        int     index = hashFunction(key);
        Node*   node = table[index];

        if (node == nullptr)
            return (-1);
        while (node->next && node->key != key) {
            node = node->next;
        }
        if (node->key == key)
            return (node->value);
        return (-1);
    }

    bool remove(int key) {
        int     index = hashFunction(key);
        Node*   node = table[index];
        Node*   prev = nullptr;

        while (node && node->key != key) {
            prev = node;
            node = node->next;
        }

        if (node == nullptr) {
            return (false);
        }
        else if (prev == nullptr) {
            table[index] = node->next;
        } 
        else {
            prev->next = node->next;
        }

        delete node;
        size--;
        return (true);
    }

    int getSize() const {
        return (size);
    }

    int getCapacity() const {
        return (capacity);
    }

    void resize() {
        int newCapacity = capacity * 2;
        vector<Node*> newTable(newCapacity, nullptr);

        for (Node* node : table) {
            while (node) {
                int index = node->key % newCapacity;

                addEnd(newTable, new Node(node->key, node->value), index);
                Node*   toDelete = node;
                node = node->next;
                delete toDelete;
            }
        }
        capacity = newCapacity;
        table = newTable;
    }

private:
    vector<Node*>   table;
    int             capacity;
    int             size;

    int hashFunction(int key) {
        return (key % this->capacity);
    }

    void addEnd(vector<Node*>& table, Node* adder, int index) {
        Node*   node = table[index];
        
        if (node == nullptr) {
            table[index] = adder;
        }
        else {
            while (node->next) {
                node = node->next;
            }
            node->next = adder;
        }
    }
};
