class MyLinkedList {
    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    void print(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }

        cout << endl;
    }
    
    int get(int index) {
        if (index > size || size == 0) return -1;

        int pos = 0;
        ListNode* curr = head;
        while (pos != index) {
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

        // print(head);
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            size++;

            // print(head);
            return;
        }

        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
        size++;

        // print(head);
    }
    
    void addAtIndex(int index, int val) {        
        // can t add the new node
        if (index > size) {
            return;
        }

        ListNode* newNode = new ListNode(val);

        // ad the head
        if (size == 0) {
            head = newNode;
            size++;
            // print(head);
            return;
        }

        if (index == 0) {
            ListNode* next = head->next;
            head = newNode;
            newNode->next = next;
            size++;
            // print(head);
            return;
        }

        int pos = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (pos != index) {
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if (curr == nullptr) {
            // add at tail case
            prev->next = newNode;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }

        size++;

        print(head);
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || size == 0) {
            return;
        }

        // check if we have to delete the head
        if (size > 0 && index == 0) {
            if (head->next != nullptr) {
                head = head->next;
            } else {
                head = nullptr;
            }
            size--;
            return;
        }

        int pos = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (pos != index) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

        // check if we have to delete the tail
        if (curr->next == nullptr) {
            prev->next = nullptr;
            size--;
            return;
        } else {
            prev->next = curr->next;
            size--;
            return;
        }
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