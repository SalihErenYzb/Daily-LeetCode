class LRUCache {
public:
    // store all values in a list
    // have map(key) = listnode iterator
    int cap;
    list<pair<int,int>> list2;
    unordered_map<int,list<pair<int,int>>::iterator> m;

    LRUCache(int capacity){
        cap = capacity;
    }
    int get(int key) {
        if (m.find(key) == m.end()){
            return -1;
        }
        auto element = m[key];
        list2.push_front(*element);
        list2.erase(element);
        m[key] = list2.begin();
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            auto element = m[key]; // key iterator pair
            list2.erase(element);
        }else if (cap == list2.size()){
            // delete last node
            // delete key from map
            int lastKey = list2.back().first;
            list2.pop_back();
            m.erase(lastKey);
        }
        list2.push_front({key,value});
        m[key] = list2.begin();
    }
};
