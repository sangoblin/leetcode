class Node{
public:
    Node *prev, *next; //form a doubly linked list
    int val, key;
    Node(int x, int y) : val(x), key(y) {
        prev = next = nullptr;
    }
};

class LRUCache{
private:
    int capacity, size;
    unordered_map<int, Node*> data;
    Node *head, *tail;
    
public:
    LRUCache(int capacity) {
       this->capacity = capacity; 
       size = 0;
       data.clear();
       head = new Node(-1, -1);
       tail = head;
    }
    
    int get(int key) {
        if (data.find(key) != data.end())
            return update(key)->val;
        else 
            return -1;
    }
    
    void set(int key, int value) {
        if (data.find(key) != data.end())
            update(key)->val = value;
        else if (size < capacity)
        {
            ++size;
            insert(key, value);  
        }
        else
        {
            data.erase(head->next->key);
            auto tmp = head->next;
            head->next = tmp->next;
            if (nullptr != tmp->next) tmp->next->prev = head;
            else    tail = head;
            delete tmp;
            insert(key, value);
        }
    }
    
    Node* update(int key)
    {
        auto cur = data[key];
       
        if (cur->next)
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
            tail->next = nullptr;
        }
        return cur;
    }
    
    void insert(int key, int value)
    {
        auto tmp = new Node(value, key);
        data[key] = tmp;
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
        tail->next = nullptr;
    }
    
    ~LRUCache(){
        while (head)
        {
            auto back = head->next;
            delete head;
            head = back;
        }
    }
};
