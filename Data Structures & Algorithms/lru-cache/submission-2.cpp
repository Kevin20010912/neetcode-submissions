class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }

        auto it = mp[key];

        int value = it->second;

        cache.splice(cache.begin(), cache, it);

        return value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto it = mp[key];
            it->second = value;

            cache.splice(cache.begin(), cache, it);
            return;
        }

        if(cache.size() == capacity){
            auto lru = cache.back();
            int oldkey = lru.first;
            mp.erase(oldkey);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};
