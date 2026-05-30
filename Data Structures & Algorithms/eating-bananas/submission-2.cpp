class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MAX;
        int res = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int pile : piles){
                count += pile / mid;
                if(pile % mid != 0){
                    count++;
                }
            }
            if(count <= h){
                res = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }
};
