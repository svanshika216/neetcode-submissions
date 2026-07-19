class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i = 0; i<strs.size(); i++){
            int length = strs[i].length();
            ans += (to_string(length));
            ans += '#';
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()){
            string num = "";
            while(s[i] != '#'){
                num += s[i];
                i++;
            }
            int len = stoi(num);
            i++;
            string word = s.substr(i, len);
            res.push_back(word);
            i += len;
        }
        return res;
    }
};
