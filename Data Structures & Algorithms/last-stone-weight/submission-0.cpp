class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int cur1 = pq.top();
            pq.pop();
            int cur2 = pq.top();
            pq.pop();

            if(cur1 == cur2){
                continue;
            }
            int diff = abs(cur1 - cur2);
            pq.push(diff);
        }
        if(pq.size()){
            return pq.top();
        }else{
            return 0;
        }
    }
};
