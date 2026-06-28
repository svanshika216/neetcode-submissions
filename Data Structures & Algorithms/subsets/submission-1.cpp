class Solution {
private:
    vector<vector<int>> ans;
    void printF(int ind, int n, vector<int> &ds, vector<int>& nums){
        if(ind >= n){
            ans.push_back(ds);
            return;
        }
       
        ds.push_back(nums[ind]);
        printF(ind+1,n,ds,nums);
        ds.pop_back();
        printF(ind+1,n,ds,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        int n = nums.size();
        printF(0,n,ds,nums);
        return ans;
    }
};
