class MyHashSet {
public:
    vector<int> hashset;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool duplicate = false;
        for (int num : hashset) {
            if (num == key) {
                duplicate = true;
            }
        }
        if (duplicate == false) {
            hashset.push_back(key);
        }
    }
    
    void remove(int key) {
        for (int i = 0; i < hashset.size(); i++) {
            if (hashset[i] == key) {
                hashset.erase(hashset.begin() + i);
            }
        }
    }
    
    bool contains(int key) {
        for (int num : hashset) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */