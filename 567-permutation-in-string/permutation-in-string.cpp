class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        vector<int>frq1(26, 0), frq2(26, 0);
        for(int i = 0; i < n; i++) {
            frq1[s1[i] - 'a']++;
            frq2[s2[i] - 'a']++;
        }
        if(frq1 == frq2) return true;

        for(int i = n; i < m; i++) {
            frq2[s2[i] - 'a']++;
            frq2[s2[i - n] - 'a']--;
            if(frq1 == frq2) return true;
        }
        return false;
    }
};