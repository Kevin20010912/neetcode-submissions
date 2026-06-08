class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int len = INT_MAX;
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char c : t){
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        while(right < s.size()){
            char c = s[right];
            window[c]++;
            if(need.count(c)){
                if(window[c] == need[c]){
                    valid++;
                }
            }
            right++;
            while(valid == need.size()){
                if(len > right - left){
                    res = s.substr(left, right - left);
                    len = right - left;
                }

                char k = s[left];
            
                if(need.count(k)){
                    if(window[k] == need[k]){
                        valid--;
                    }
                      
                }
                window[k]--; 
                
                left++;
            }
            
        }
        return res;

    }
};
