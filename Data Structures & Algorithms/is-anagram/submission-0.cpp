class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size()){
            return false;
        }

        unordered_map<char,int>table;

        for(char c:s){
            table[c]++;
        }

        for(char c:t){
            if(table[c]==0){
                return false;
            }
            table[c]--;
        }

        return true;
    }
};
