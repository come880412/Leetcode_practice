class LRUCache {
public:
    int maxCapacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
    LRUCache(int capacity) {
        this -> maxCapacity = capacity;
    }
    
    int get(int key) {
        auto it = this -> map.find(key);
        if (it == this -> map.end()) return -1;
        else {
            // Move the element to the front.
            this -> cache.splice(this -> cache.begin(), this -> cache, it -> second);
            return it -> second -> second;
        }
    }
    
    void put(int key, int value) {
        auto it = this -> map.find(key);
        if (it != this -> map.end()) {
            this -> cache.erase(it -> second);
        }
        this -> cache.push_front({key, value});
        this -> map[key] = this -> cache.begin();

        if (this -> cache.size() > this -> maxCapacity) {
            auto &n = this -> cache.back();
            this -> map.erase(n.first);
            this -> cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */