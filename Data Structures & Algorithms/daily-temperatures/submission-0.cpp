class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        for(int ind = temperatures.size() - 1; ind >= 0; ind--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[ind]){
            st.pop();
        }
            if(st.empty()){
                res[ind] = 0;
            }
            else{
                res[ind] = st.top() - ind; 
            }
            st.push(ind);
        }
        return res;
    }
};
