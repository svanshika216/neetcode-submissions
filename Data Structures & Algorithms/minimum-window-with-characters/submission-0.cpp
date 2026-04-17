class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char,int>hash;
        int count = 0;
        int minlen = INT_MAX;
        int s_index = -1;
        int n = s.size();
        int m = t.size();
        for(int i = 0; i<m;i++){
            hash[t[i]]++;
        }
        while(right < n){
            hash[s[right]]--;
            if(hash[s[right]] >= 0){
                count++;
            }

            while(count == m){
                if(right-left+1 < minlen){
                    minlen = right-left+1;
                    s_index = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return s_index == -1 ? "" : s.substr(s_index, minlen);
    }
};
