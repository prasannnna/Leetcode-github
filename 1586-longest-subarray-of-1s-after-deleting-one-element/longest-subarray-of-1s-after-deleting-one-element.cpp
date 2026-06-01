class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, max_len = 0, zeroes = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] == 0) {
                zeroes++;
            }
            while(zeroes > 1) {
                if(nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            max_len = max(max_len, r - l);
        }
        return max_len;
    }
};