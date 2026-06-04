class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> greedy(n);
        greedy[0] = nums[0];
        int max_num = nums[0];
        for(int i = 1; i < n; i++){
            greedy[i] = max(nums[i], greedy[i - 1] + nums[i]); 
            max_num = max(max_num, greedy[i]);   
        }
        return max_num;
    }
};
