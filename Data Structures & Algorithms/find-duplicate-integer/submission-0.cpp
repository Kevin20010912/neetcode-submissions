class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> visited(10001, false);
        for(int i = 0; i < nums.size(); i++){
            if(visited[nums[i]]){
                return nums[i];
            }
            visited[nums[i]] = true;
        }
        return 0;
    }
};
