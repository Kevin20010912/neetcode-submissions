class KthLargest {
    int k;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            pq.push(num);
        }
    }
    
    int add(int val) {
        vector<int> temp;
        pq.push(val);
        for(int i = 0; i < k - 1; i++){
            temp.push_back(pq.top());
            pq.pop();
        }
        int ans = pq.top();
        for(int t : temp){
            pq.push(t);
        }
        return ans;
    }
};
