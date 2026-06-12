class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> count_s1(26);
        vector<int> count_s2(26);
        for(char c : s1){
            int idx = c - 'a';
            count_s1[idx]++;
        }

        int left = 0, right = 0;
        while(right < n2){
            count_s2[s2[right] - 'a']++;
            right++;
            if(right - left  == n1){
                if(count_s1 == count_s2){
                    return true;
                }
                count_s2[s2[left] - 'a']--;
                left++;
            }
        }
        
        return false;
    }
};
