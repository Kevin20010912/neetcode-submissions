class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            int x = i;
            int count = 0;
            while(x != 0){
                x = x & (x - 1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
