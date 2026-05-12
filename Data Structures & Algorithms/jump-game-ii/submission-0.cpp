class Solution {
public:
    int jump(vector<int>& nums) {
        int maxindex = 0;
        int curend = 0;
        int jumps = 0;
        for(int i = 0; i< nums.size() - 1; i++){
            maxindex = max(maxindex, i+nums[i]);
            if( i == curend){
                jumps++;
                curend = maxindex;
            }
        }
        return jumps;
    }
};
