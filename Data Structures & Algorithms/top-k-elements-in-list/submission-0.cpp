class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto& p : mp){
            pq.push({p.second, p.first});
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
