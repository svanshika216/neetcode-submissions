class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev = nullptr;
        Node* next = nullptr;

        Node(int key_, int val_){
            key = key_;
            val = val_;
        }
    };
    int cap;
    unordered_map<int, Node*> m;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next= temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }
    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int res = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
            delete existingNode;
        }
        if(m.size() == cap){
            Node* delenode = tail->prev;
            m.erase(delenode->key);
            deleteNode(delenode);
            delete delenode;
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};
