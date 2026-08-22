class LRUCache {
private:
    vector<pair<int, int>> cache;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i]. first == key) {
                // store current pait
                pair<int, int> tmp = cache[i];
                // erase from current position
                cache.erase(cache.begin() + i);
                // put it in most recently used index (rightmost)
                cache.push_back(tmp);
                return tmp.second; // return value associated with key
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);    // remove old position
                cache.push_back({key, value});     // insert updated value at end
                return;
            }
        }

        if (cache.size() == capacity) {
            cache.erase(cache.begin()); // remove least recently used (first element)
        }

        cache.push_back({key, value}); // insert as most recently used
    }
};
