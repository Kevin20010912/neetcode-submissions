class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(char c : s){
            mp1[c]++;
        }
        for(char c : t){
            mp2[c]++;
        }
        if(mp1 == mp2){
            return true;
        }
        return false;
    }
};
