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
            data.splice(data.end(), data, tmp);
            dict[key] = prev(data.end());
            return tmp->val;
        }
        else 
            return -1;
    }
    
    void set(int key, int value) {
        if (dict.find(key) != dict.end())
        {
            auto tmp = dict[key];
            data.splice(data.end(), data, tmp);
            tmp->val = value;
        }    
        else if (size < capacity)
        {
            ++size;
            data.push_back(Node(key, value));
        }
        else
        {
            auto tmp = data.begin();
            data.pop_front();
            dict.erase(tmp->key);
            data.push_back(Node(key, value));
        }
        dict[key] = prev(data.end());
    }
};
