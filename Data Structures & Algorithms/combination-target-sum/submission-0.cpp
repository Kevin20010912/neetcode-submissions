class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> onPath;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            cur_sum += nums[i];
            onPath.push_back(nums[i]);
            backtrack(nums, onPath, target, cur_sum, i);
            cur_sum -= nums[i];
            onPath.pop_back();
        }
        return res;

    }
    void backtrack(vector<int>& nums, vector<int>& onPath, int target, int cur_sum, int i){
        if(cur_sum > target){
            return ;
        }else if(cur_sum == target){
            res.push_back(onPath);
            return ;
        }

        for(int j = i; j < nums.size(); j++){
            cur_sum += nums[j];
            onPath.push_back(nums[j]);
            backtrack(nums, onPath, target, cur_sum, j);
            cur_sum -= nums[j];
            onPath.pop_back();
        }
        return ;
    }
};
