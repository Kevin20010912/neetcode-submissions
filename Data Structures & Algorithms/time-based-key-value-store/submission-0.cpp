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
        vector<pair<string, int>> pairs = mp[key];
        int left = 0, right = pairs.size() - 1;
        pair<string, int> res = {"", -1};
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(pairs[mid].second == timestamp){
                return pairs[mid].first;
            }else if(pairs[mid].second < timestamp){
                if(res.second < pairs[mid].second){
                    res = pairs[mid];
                }
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res.first;
    }
};
