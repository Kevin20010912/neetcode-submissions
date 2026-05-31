class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int l_max = heights[left];
        int r_max = heights[right];
        int res = 0;
        while(left < right){
            int cur_amt = (right - left) * min(heights[left], heights[right]);
            cout << left << " " << right << endl;
            res = max(cur_amt, res);
            if(heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};
