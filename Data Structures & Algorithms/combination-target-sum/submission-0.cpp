class Solution {
private:
    void func(int ind, int n, int target, vector<int>& ds, 
    vector<vector<int>>& ans, vector<int>& arr){

        if(ind == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            func(ind,n,target-arr[ind],ds,ans,arr);
            ds.pop_back();
        }

        func(ind+1,n,target,ds,ans,arr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        func(0,n,target,ds,ans,nums);
        return ans;
    }
};
