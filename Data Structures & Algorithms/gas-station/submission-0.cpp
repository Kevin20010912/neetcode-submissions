class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tatol = 0;
        int tank = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];

            tatol += diff;
            tank += diff;

            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        if(tatol < 0){
            return -1;
        }
        return start;
        
        
        
    }
};
