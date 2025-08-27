class MyLinkedList {
    ListNode* head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size || size == 0) return -1;

        int pos = 0;
        ListNode* curr = head;
        while (pos < index) {
            curr = curr->next;
            pos++;
        }

        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }

            curr->next = newNode;
        }

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        ListNode* newNode = new ListNode(val);

        int pos = 0;
        ListNode* curr = head;
        while (pos < index - 1) {
            curr = curr->next;
            pos++;
        }

        ListNode* nextNode = curr->next;
        curr->next = newNode;
        newNode->next = nextNode;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || size == 0) return;

        if (index == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            return;
        }


        int pos = 0;
        ListNode* curr = head;
        while (pos < index - 1) {
            curr = curr->next;
            pos++;
        }

        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        size--;
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