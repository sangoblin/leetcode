class LRUCache{
private:
    int capacity;
    unordered_map<int, int> data;
    vector<int> keys;
    
public:
    LRUCache(int capacity) {
       this->capacity = capacity; 
       data.clear();
       keys.clear();
    }
    
    int get(int key) {
        if (data.find(key) != data.end())
        {
            auto index = find(keys.begin(), keys.end(), key);
            keys.erase(index);
            keys.push_back(key);
            return data[key];
        }
        else 
            return -1;
    }
    
    void set(int key, int value) {
        if (data.find(key) != data.end())
        {
            auto index = find(keys.begin(), keys.end(), key);
            keys.erase(index);
            keys.push_back(key);
            data[key] = value;
        }
        else if (keys.size() < capacity)
        {
            data[key] = value;
            keys.push_back(key);
        }
        else
        {
            int tmp = keys[0];
            keys.erase(keys.begin());
            keys.push_back(key);
            data.erase(tmp);
            data[key] = value;
        }
    }
};
