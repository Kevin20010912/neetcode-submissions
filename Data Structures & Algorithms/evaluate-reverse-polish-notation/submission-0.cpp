class Solution {
    int cal(int a, int b, string c){
        if(c == "+") return a + b;
        if(c == "-") return a - b;
        if(c == "*") return a * b;
        return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int ans;
        for(int i = 0 ; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                stk.push(cal(a, b, tokens[i]));
            }else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
        
    }
};
