class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left = {1};
        vector<int> right= {1};
        int left_prod = 1;
        int right_prod = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            left_prod *= nums[i];
            right_prod *= nums[nums.size() - 1 - i];
            left.push_back(left_prod);
            right.push_back(right_prod);
        }
        reverse(right.begin(), right.end());
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int prod = left[i] * right[i];
            
            res.push_back(prod);
        }
        return res;
    }
};
