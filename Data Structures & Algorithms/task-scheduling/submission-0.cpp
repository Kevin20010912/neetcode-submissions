class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> freq(26, 0);

        for(char task : tasks){
            freq[task - 'A']++;
        }
        
        for(int f : freq){
            if(f > 0){
                pq.push(f);
            }
        }

        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            int cycle = n + 1;

            for(int i = 0; i < cycle; i++){
                if(!pq.empty()){
                    int cnt = pq.top();
                    pq.pop();
                    
                    cnt--;
                    if(cnt > 0){
                        temp.push_back(cnt);
                    }
                    
                }
                time++;

                if(pq.empty() && temp.empty()){
                    break;
                }
            }

            for(int cnt : temp){
                pq.push(cnt);
            }
        }
        return time;

    }
};
