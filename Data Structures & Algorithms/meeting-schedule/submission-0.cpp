/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()){
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a.start < b.start;
        });

        int past_start = intervals[0].start;
        int past_end = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++){
            int cur_start = intervals[i].start;
            int cur_end = intervals[i].end;
            if(cur_start < past_end){
                return false;
            }
            past_end = max(cur_end, past_end);
        }
        return true;
    }
};
