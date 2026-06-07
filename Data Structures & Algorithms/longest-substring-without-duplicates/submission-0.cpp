class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int count = 0;
        unordered_map<char, int> mp;
        while(right < s.size()){
            char c = s[right];
            mp[c]++;
            right++;
            while(mp[c] > 1){
                mp[s[left]]--;
                left++;
            }
            count = max(count, right - left);
        }
        return count;
    }
};
