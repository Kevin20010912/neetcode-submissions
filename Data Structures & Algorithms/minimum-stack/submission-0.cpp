class MinStack {
    // pair<val, min>
    stack<pair<int, int>> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_num;
        if(!stk.empty()){
            min_num = min(stk.top().second, val);
        }else{
            min_num = val;
        }
        
        stk.push({val, min_num});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
