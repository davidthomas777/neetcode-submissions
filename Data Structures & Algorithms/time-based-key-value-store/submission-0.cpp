class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        const auto& v = mp[key];
        int l = 0;
        int r = v.size() - 1;
        string res = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m].second <= timestamp) {
                res = v[m].first;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return res;
    }
};
