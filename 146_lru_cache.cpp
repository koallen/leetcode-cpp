class LRUCache {
public:
    unordered_map<int, list<pair<int, int> >::iterator> location;
    list<pair<int, int> > lru;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = location.find(key);
        if (it != location.end()) {
            int val = it->second->second;
            if (it->second != lru.begin()) {
                lru.erase(it->second);
                lru.emplace_front(key, val);
                location[key] = lru.begin();
            }
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = location.find(key);
        if (it != location.end()) {
            // we have the key already, remove the existing one in list and put the new one in front
            lru.erase(it->second);
        } else if (lru.size() == cap) {
            // we need to delete one element
            auto elem_to_remove = lru.back();
            lru.pop_back();
            location.erase(elem_to_remove.first);
        }
        // add the new value for the key
        lru.emplace_front(key, value);
        location[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
