class Solution {
private:
    long long int solve(vector<int>& arr){
        int prev2 = 0; 
        int prev = arr[0];
        for(int i = 1; i< arr.size(); i++){
            int take = arr[i];
            if(i>1) take += prev2;
            int notTake = prev;
            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
        return max (solve(temp1), solve(temp2));
    }
};
