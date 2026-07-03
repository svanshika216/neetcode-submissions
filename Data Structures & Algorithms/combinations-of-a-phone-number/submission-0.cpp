class Solution {
private:
    void func(int ind, string s, string digits, vector<string>& ans, string combs[]){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
    

        int digit = digits[ind] - '0';
        for(int i = 0; i< combs[digit].size();i++){
            func(ind+1,s+combs[digit][i],digits,ans,combs);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        string s= "";
        string combs[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        func(0,s,digits,ans,combs);
        return ans;
    }
};
