class MinStack {
public:
        stack<int> stk;
        stack<int> minstk;
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        val = min(val, minstk.empty() ? val : minstk.top());
                minstk.push(val);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
       return minstk.top();
    }
};
