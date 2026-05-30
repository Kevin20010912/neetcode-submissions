class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int upper = 0, lower = m - 1;
        int left = 0, right = n - 1;
        int hi = -1;
 
        while(upper <= lower){
            int mid = upper + (lower - upper) / 2;
            if(matrix[mid][n - 1] > target){
                lower = mid - 1;
            }else if(matrix[mid][n - 1] < target){
                upper = mid + 1;
            }else{
                return true;
            }

        }

        hi = upper;
        
        if(hi == m){
            return false;
        }
        

        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[hi][mid] > target){
                right = mid - 1;
            }else if(matrix[hi][mid] < target){
                left = mid + 1;
            }else{
                return true;
            }
        }
        return false;  
    }
};
