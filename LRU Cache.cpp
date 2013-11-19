class Node{
public:
    int val, key;
    Node(int x, int y) : val(y), key(x) {} 
};

class LRUCache{
private:
    int capacity;
    unordered_map<int, list<Node>::iterator> dict;
    list<Node> data;
    
public:
    LRUCache(int capacity) {
       this->capacity = capacity; 
       dict.clear();
       data.clear();
    }
    
    int get(int key) {
        if (dict.find(key) != dict.end())
        {
            data.splice(data.begin(), data, dict[key]);
            dict[key] = data.begin();
            return dict[key]->val;
        }
        else 
            return -1;
    }
    
    void set(int key, int value) {
        if (dict.find(key) != dict.end())
        {
            data.splice(data.begin(), data, dict[key]);
            dict[key]->val = value;
        }    
        else 
        {
            if (data.size() == capacity)
            {
                dict.erase(data.back().key);
                data.pop_back();
            }
            data.push_front(Node(key, value));
        }
        dict[key] = data.begin();
    }
};
