class LRUCache {
public:
    int cap;
    std::list<std::pair<int, int>> cache; // {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;

    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            // Move the accessed element to the front of the list manually
            cache.push_front(*(it->second));
            cache.erase(it->second);
            m[key] = cache.begin();
            return m[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            // Update the value and move the element to the front manually
            cache.erase(it->second);
        } else if (cache.size() == cap) {
            // Remove the least recently used element
            int lru_key = cache.back().first;
            cache.pop_back();
            m.erase(lru_key);
        }
        // Insert the new element at the front
        cache.emplace_front(key, value);
        m[key] = cache.begin();
    }
};
