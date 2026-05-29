class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1){
            return s;
        }
        int count = -1;
        string res = "";
        for(int i = 0; i < n - 1; i++){
            int left, right;
            left = i;
            right = i + 1;
            while(left >= 0 && right < n){
                if(s[left] != s[right]){
                    break;
                }
                left--;
                right++;
            }
            if(right - left - 2 > count){
                count = right - left - 2;
                res = s.substr(left + 1, right - left - 1);
            }
            
            left = i;
            right = i;
            while(left >= 0 && right < n){
                if(s[left] != s[right]){
                    break;
                }
                left--;
                right++;
            }
            if(right - left - 2 > count){
                count = right - left - 2;
                res = s.substr(left + 1, right - left - 1);
            }
            
        }
        return res;
    }
};
