class Solution {
public:
    int bs(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pivot = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                if(nums[mid] < nums[pivot]){
                    pivot = mid;
                }
                right = mid - 1;
            }
        }
        if(target >= nums[pivot] && target <= nums[n - 1]){
            return bs(nums, pivot, n - 1, target);
        }else{
            return bs(nums, 0, pivot - 1, target);
        }
    }
};
