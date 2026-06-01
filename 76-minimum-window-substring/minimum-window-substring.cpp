class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128, 0);
        int l = 0, min_len = INT_MAX,cnt = t.size(), left = 0;
        for(char ch : t) {
            freq[ch]++;
        }
        for(int r = 0; r < s.size(); r++) {
            if(freq[s[r]] > 0) {
                cnt--;
            }
            freq[s[r]]--;
            while(cnt == 0) {
                freq[s[l]]++;
                if(freq[s[l]] > 0) {
                    cnt++;
                }
                if(r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    left = l;
                }
                l++; 
            }
        }
        return (min_len == INT_MAX) ? "" : s.substr(left, min_len);
    }
};