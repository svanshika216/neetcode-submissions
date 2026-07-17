class Solution {
private:
    bool func(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= target){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int k = 1; k<=target; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(nums[i] <= k){
                    take = dp[i-1][k-nums[i]];
                }
                dp[i][k] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n ; i++){
            totalSum += nums[i];
        }
        if(totalSum % 2) return false;
        return func(nums, totalSum/2);
    }
};
