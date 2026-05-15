class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>lastIndex(256, -1);
        int left = 0, maxlen = 0;
        for(int i = 0; i < s.size(); i++) {
            if(lastIndex[s[i]] >= left) {
                left = lastIndex[s[i]] + 1;
            }
            lastIndex[s[i]] = i;
            maxlen = max(maxlen, i - left + 1);
        }
        return maxlen;
    }
};