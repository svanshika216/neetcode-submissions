class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map <int,int>freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& it: freq){
            buckets[it.second].push_back(it.first);
        }

        vector<int> results;
        for(int i = buckets.size()-1; i>=0 && results.size()<k; i--){
            for(int num : buckets[i]){
                results.push_back(num);
                if(results.size() == k){
                    break;
                }
            }
        }
        return results;
         
    }

   
};
