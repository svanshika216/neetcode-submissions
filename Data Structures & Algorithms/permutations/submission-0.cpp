class Solution {
private: 
    void Permute(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, int freq[]){
        if(ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i< arr.size(); i++){
            if(!freq[i]){
                ds.push_back(arr[i]);
                freq[i] = 1;
                Permute(arr,ans,ds,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }   
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        int freq[n];
        for(int i = 0; i< n; i++){
            freq[i] = 0;
        }
        Permute(nums,ans,ds,freq);
        return ans;
    }
};
