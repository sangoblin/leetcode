class Node{
public:
    int val, key;
    Node(int x, int y) : val(y), key(x) {} 
};

class LRUCache{
private:
    int capacity, size;
    unordered_map<int, list<Node>::iterator> dict;
    list<Node> data;
    
public:
    LRUCache(int capacity) {
       this->capacity = capacity; 
       size = 0;
       dict.clear();
       data.clear();
    }
    
    int get(int key) {
        if (dict.find(key) != dict.end())
        {
            auto tmp = dict[key];
            data.splice(data.begin(), data, tmp);
            dict[key] = data.begin();
            return tmp->val;
        }
        else 
            return -1;
    }
    
    void set(int key, int value) {
        if (dict.find(key) != dict.end())
        {
            auto tmp = dict[key];
            data.splice(data.begin(), data, tmp);
            tmp->val = value;
        }    
        else 
        {
            if (size < capacity)
                ++size;
            else
            {
                dict.erase(data.back().key);
                data.pop_back();
            }
            data.push_front(Node(key, value));
        }
        dict[key] = data.begin();
    }
};
