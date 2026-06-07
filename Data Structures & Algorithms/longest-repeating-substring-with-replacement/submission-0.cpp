class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int res = 0;
        int maxFreq = 0;
        vector<int> record(26);
        while(right < s.size()){
            char c = s[right];
            int idx = c - 'A';
            record[idx]++;
            maxFreq = max(maxFreq, record[idx]);
            right++;
            while(right - left - maxFreq > k){
                record[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;

    }
};
