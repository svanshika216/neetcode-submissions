class Solution {
private:
    int max_ele(vector<int>& piles){
        int maxel = INT_MIN;
        for(int i = 0; i< piles.size();i++){
            maxel = max(piles[i],maxel);
        }
        return maxel;
    }
    long long func(vector<int>& piles, int hourly){
        long long totalhrs = 0;
        for(int i = 0; i<piles.size();i++){
            totalhrs += ceil((double) piles[i] / (double) hourly);
        }
        return totalhrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = max_ele(piles);
        int ans = 0;
        while(low<=high){
            int mid = (low + high)/2;
            long long totalhrs = func(piles,mid);
            if(totalhrs <= h) {
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
