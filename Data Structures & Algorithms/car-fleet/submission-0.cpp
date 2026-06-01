class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i = 0; i < n; i++){
            double time = ((double)target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        int fleet = 0;
        double curTime = 0;
        for(int i = 0; i < n; i++){
            double time = cars[i].second;
            if(time <= curTime){
                continue;
            }
            fleet++;
            curTime = time;
        }
        return fleet;
    }
};
