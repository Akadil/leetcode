struct ListNodeDouble {
    int val;
    ListNodeDouble *next;
    ListNodeDouble *prev;

    ListNodeDouble() : val(0), next(nullptr), prev(nullptr) {}
    ListNodeDouble(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
public:
    ListNodeDouble*   head;
    ListNodeDouble*   tail;
    int         length;

    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0; 
    }
    
    int get(int index) {
        if (checkIndex(index) == false)
            return (-1);

        return (getNodeAtIndex(index)->val);
    }
    
    void addAtHead(int val) {
        ListNodeDouble* newNode = new ListNodeDouble(val);
        
        if (this->head) {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        } else {
            this->head = newNode;
            this->tail = newNode;
        }
        this->length++;
    }
    
    void addAtTail(int val) {
        ListNodeDouble* newNode = new ListNodeDouble(val);

        if (this->tail) {
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        } else {
            this->head = newNode;
            this->tail = newNode;
        }
        this->length++;
    }
    
    void addAtIndex(int index, int val) {
        if (this->checkIndex(index) == false && index != this->length)
            return ;

        if (index == 0) {
            addAtHead(val);
        }
        else if (index == this->length) {
            addAtTail(val);
        }
        else {
            ListNodeDouble*   node = getNodeAtIndex(index);
            ListNodeDouble*   newNode = new ListNodeDouble(val);

            node->prev->next = newNode;
            newNode->prev = node->prev;
            node->prev = newNode;
            newNode->next = node;
            this->length++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (this->checkIndex(index) == false)
            return ;

        ListNodeDouble* node;

        if (index == 0) {
            node = this->head->next;
            delete (this->head);

            if (node) {
                this->head = node;
                this->head->prev = nullptr;
            } else {
                this->head = nullptr;
                this->tail = nullptr;
            }
        }
        else if (index == this->length - 1) {
            node = this->tail->prev;
            delete (this->tail);

            if (node) {
                this->tail = node;
                this->tail->next = nullptr;
            } else {
                this->head = nullptr;
                this->tail = nullptr;
            }
        }
        else {
            node = getNodeAtIndex(index);

            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete (node);
        }
        this->length--;
    }

    ListNodeDouble    *getNodeAtIndex(int index) {
        ListNodeDouble    *iter = this->head;
        
        for (int i = 0; i != index; i++) 
            iter = iter->next;

        return (iter);
    }

    bool    checkIndex(int index) {
        if (index < 0 || index + 1 > this->length)
            return (false);
        return (true);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */