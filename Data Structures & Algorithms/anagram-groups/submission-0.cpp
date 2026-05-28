class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto& str : strs){
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& p : mp){
            res.push_back(p.second);            
        }
        return res;
    }
};
