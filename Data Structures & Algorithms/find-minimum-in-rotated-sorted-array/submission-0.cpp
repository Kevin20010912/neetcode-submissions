class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int res = 1000;
        while(left < right){
            int mid = left + (right - left) / 2;
            cout << left << " " << mid << " " << right << endl;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                
                right = mid;
            }
        }
        
        return nums[left];
    }
};
