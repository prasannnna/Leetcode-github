class Solution {
public:
    void generate(string s, int open, int close, vector<string>&ans, int n) {
        if(s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if(open < n) {
            generate(s + "(", open + 1, close, ans, n);
        }
        if(close < open) {
            generate(s + ")", open, close + 1, ans, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate("", 0, 0, ans, n);
        return ans;
    }
};