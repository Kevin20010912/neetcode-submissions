class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        
        return res;
        
    }
    void backtrack(vector<int>& candidates, int target, int start){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }

       
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
        
    }
};
