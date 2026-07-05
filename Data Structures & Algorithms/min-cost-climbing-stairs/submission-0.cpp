class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev = cost[1];
        for(int i = 2; i<n; i++){
            int curri = cost[i] + min(prev,prev2);
            prev2 = prev;
            prev = curri;
        }
        return min(prev,prev2);
    }
};
