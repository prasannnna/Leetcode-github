class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int max_len = 0, l = 0;
        for(int r = 0; r < fruits.size(); r++) {
            mp[fruits[r]]++;
            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            max_len = max(r - l + 1, max_len);
        }
        return max_len;
    }
};