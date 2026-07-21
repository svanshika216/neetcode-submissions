class Solution {
public:
    int countNoOfWays(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> prev(target + 1, 0), cur(target + 1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;

        for(int i = 1; i < n; i++){
            for(int k = 0; k <= target; k++){
                int nottake = prev[k];
                int take = 0;
                if(nums[i] <= k){
                    take = prev[k - nums[i]];
                }
                cur[k] = take + nottake;
            }
            prev = cur;
        }
        return prev[target];
    }
    int partition(vector<int>& nums, int diff){
        int totalsum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalsum += nums[i];
        }
        if(totalsum - diff < 0 || (totalsum - diff)% 2) return 0;
        return countNoOfWays(nums, (totalsum - diff) / 2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return partition(nums, target);
    }
};
