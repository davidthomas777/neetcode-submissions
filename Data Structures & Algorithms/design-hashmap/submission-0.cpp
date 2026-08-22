class MyHashMap {
public:
    vector<pair<int, int>> hashmap;
    MyHashMap() {}
    
    void put(int key, int value) {
        bool found = false;
        // if we find a match, update that pair in hashmap
        for (auto& p : hashmap) {
            if (p.first == key) {
                p.second = value;
                found = true;
            }
        }
        // if no match found, add the key value pair
        if (found == false) {
            hashmap.push_back({key, value});
        }
    }
    
    int get(int key) {
        for (auto& p : hashmap) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i = 0;
        for (auto& p : hashmap) {
            if (p.first == key) {
                hashmap.erase(hashmap.begin() + i);
            }
            i++;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */