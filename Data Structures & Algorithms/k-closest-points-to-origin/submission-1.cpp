class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        
        for(auto point : points){
            pair<double, pair<int, int>> len_point;
            len_point.first = sqrt(pow(point[0], 2) + pow(point[1], 2));
            len_point.second.first = point[0];
            len_point.second.second = point[1];
            pq.push(len_point);
        }

        for(int i = 0; i < k; i++){
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
