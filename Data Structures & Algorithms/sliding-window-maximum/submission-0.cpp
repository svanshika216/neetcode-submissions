class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n - k + 1);
        deque<int> dq;
        int l = 0;
        int r = 0;
        while( r < n ){
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            //just checking if we have passed the first index that is present at the front of our deque
            if(l > dq.front()){
                dq.pop_front();
            }
            //window size check and pushing the output
            if((r+1) >= k){
                output[l] = nums[dq.front()];
                l++;
            }
            r++;
        }
        return output;
    }
};
