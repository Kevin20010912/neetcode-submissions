class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(res.back()[1] > intervals[i][0]){
                count++;
                if(res.back()[1] > intervals[i][1]){
                    res.pop_back();
                    res.push_back(intervals[i]);   
                } 
            }else{
                res.push_back(intervals[i]);
            }
        }
        return count;
    }
};
