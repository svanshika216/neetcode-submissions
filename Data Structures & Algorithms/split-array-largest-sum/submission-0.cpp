class Solution {
private:
    int NoOfSubarr(vector<int>& nums, long long k){
        int subarr = 1;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= k){
                sum += nums[i];
            }
            else{
                subarr++;
                sum = nums[i];
            }
        }
        return subarr;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        while(low <= high){
            long long mid = low + (high - low)/2;
            int nos = NoOfSubarr(nums, mid);
            if(nos > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};