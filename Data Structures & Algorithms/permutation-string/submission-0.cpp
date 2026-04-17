class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>hash;
        int left = 0;
        int right = 0;
        int count = 0;
        int m = s1.size();
        int n = s2.size();
        for(int i = 0; i<m;i++){
            hash[s1[i]]++;
        }
        while(right < n){
            hash[s2[right]]--;
            if(hash[s2[right]] >= 0){
                count++;
            }
            if(right - left + 1 == m){
            if(count == m){
                return true;

            }
            hash[s2[left]]++;
            if(hash[s2[left]] > 0){
                count--;
                
            }
            left++;
            }
            right++;
            
        }
        return false;
    }
};
