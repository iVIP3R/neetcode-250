class MyHashMap {
private:
    struct ListNode {
        ListNode* next;
        int key, value;

        ListNode(int key = -1, int value = -1, ListNode* next = nullptr)
            : key(key), value(value), next(next) {}
    };

    int hash(int value) {
        return value % 10000;
    }

public:
    vector<ListNode*> vec;
    MyHashMap() {
        vec.resize(10000);
        for (int i = 0; i < 10000; i++) {
            vec[i] = new ListNode(-1, -1);
        }
    }
    
    void put(int key, int value) {
        ListNode* curr = vec[hash(key)];

        while (curr->next != nullptr) {
            curr = curr->next;
            if (curr->key == key) {
                curr->value = value;
                return;
            }
        }

        curr->next = new ListNode(key, value);
}
    
    int get(int key) {
        ListNode* curr = vec[hash(key)]->next;
        while(curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* prev = vec[hash(key)];
        ListNode* curr = prev->next;
        while(curr != nullptr) {
            if (curr->key == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */