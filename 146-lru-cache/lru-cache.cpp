class LRUCache {
public:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*>mp;
    LRUCache(int capacity) {
       this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        removeNode(mp[key]);
        addNode(mp[key]);
        
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key]->value = value;
            removeNode(mp[key]);
            addNode(mp[key]);
            
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        addNode(node);
        if(mp.size() > capacity) {
            Node* lru = head->next;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */