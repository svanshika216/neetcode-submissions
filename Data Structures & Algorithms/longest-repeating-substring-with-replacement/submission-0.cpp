class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0; int right = 0;
        int n = s.size();
        int hash[26] = {0};
        int maxlen = 0;
        int mfreq = 0;
        while(right < n){
            hash[s[right] - 'A']++;
            mfreq = max(mfreq, hash[s[right] - 'A']);
            if((right - left + 1) - mfreq > k){
                hash[s[left] - 'A']--;
                left = left + 1;
            }
            maxlen = max(maxlen, right- left + 1);
            right = right + 1;
        }
        return maxlen;
    }
};
