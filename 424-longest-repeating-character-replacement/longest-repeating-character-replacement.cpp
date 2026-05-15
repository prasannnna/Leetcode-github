class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>frq(26, 0);
        int left = 0, maxlen = 0, maxfrq = 0;
        for(int i = 0; i < s.size(); i++) {
            frq[s[i] - 'A']++;
            maxfrq = max(maxfrq, frq[s[i] - 'A']);
            while((i - left + 1) - maxfrq > k) {
                frq[s[left] - 'A']--;
                left++;
            }
            maxlen = max(maxlen, (i - left + 1));
        }
        return maxlen;
    }
};