class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_map<int, int> mp;
        for(auto& num : nums){
            if(mp.count(num)){
                continue;
            }
            mp[num]++;
        }
        int res = 1;
        for(auto& p : mp){
            int num = p.first;
            if(mp.count(num - 1)){
                continue;
            }
            int cur = num;
            int count = 1;
            while(mp.count(cur + 1)){
                count++;
                cur++;
            }
            res = max(res, count);
        }
        return res;
    }
};
