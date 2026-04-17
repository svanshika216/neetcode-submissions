class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
            string t = tokens[i];
        

            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int op2 = stk.top(); stk.pop();
                int op1 = stk.top(); stk.pop();
            

            switch(t[0]){
                case '+': stk.push(op1 + op2); break;
                case '-': stk.push(op1-op2); break;
                case '*': stk.push(op1*op2); break;
                case '/': stk.push(op1/op2); break;
            }

         }

         else{
            stk.push(stoi(t));
         }

        }

        return stk.top();
    }
};
