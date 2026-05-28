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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        vector<int> room_end;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a.start < b.start;
        });
        
        room_end.push_back(intervals[0].end);
        int room_count = 1;
        for(int i = 1; i < intervals.size(); i++){
            bool room_added = false;
            int cur_start = intervals[i].start;
            int cur_end = intervals[i].end;
            for(int j = 0; j < room_end.size(); j++){
                if(cur_start < room_end[j]){
                    continue;
                }else{
                    room_added = true;
                    room_end[j] = max(room_end[j], cur_end);
                    break;
                }
            }
            if(!room_added){
                room_end.push_back(cur_end);
                room_count++;
            }
        }
        return room_count;
    }
};








