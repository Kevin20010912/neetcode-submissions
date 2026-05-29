class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 1){
            return 1;
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            int left, right;
            left = i;
            right = i + 1;
            while(left >= 0 && right < n){
                if(s[left] != s[right]){
                    break;
                }
                count++;
                left--;
                right++;
            }
            
            left = i;
            right = i;
            while(left >= 0 && right < n){
                if(s[left] != s[right]){
                    break;
                }
                count++;
                left--;
                right++;
            }
            
            
        }
        return count;
    }
};
