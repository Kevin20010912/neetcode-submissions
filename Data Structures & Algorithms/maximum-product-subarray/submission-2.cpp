class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_dp(n);
        vector<int> min_dp(n);
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];

        int res = nums[0];

        for(int i = 1; i < n; i++){
            max_dp[i] = max({nums[i], nums[i] * max_dp[i - 1], nums[i] * min_dp[i - 1]});
            min_dp[i] = min({nums[i], nums[i] * max_dp[i - 1], nums[i] * min_dp[i - 1]});
            res = max(res, max_dp[i]);
        }

        return res;

    }
};
