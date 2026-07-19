class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), cur(amount+1, 0);

        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            }
            else{
                prev[i] = 1e9;
            }
        }

        for(int i = 1; i<n; i++){
            for(int tar = 0; tar <= amount; tar++){
                int notTake = prev[tar];
                int take = 1e9;
                if(coins[i] <= tar){
                    take = 1 + cur[tar - coins[i]];
                }
                cur[tar] = min(take, notTake);
            }
            prev = cur;
        }

        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};
