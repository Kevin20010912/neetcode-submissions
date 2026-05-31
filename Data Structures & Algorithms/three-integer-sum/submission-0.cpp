class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1, right = n - 1;
            int target = 0 - nums[i];
            while(left < right){
                int two_sum = nums[left] + nums[right];
                if(two_sum == target){
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left - 1] == nums[left]){
                        left++;
                    }
                    while(left < right && nums[right + 1] == nums[right]){
                        right--;
                    }
                }
                else if(left < right && two_sum > target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
    }
};
