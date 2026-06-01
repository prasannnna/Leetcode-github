class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int l = 0, sb_cnt = 0;
        long long pro_sb = 1;
        for(int r = 0; r < nums.size(); r++) {
            pro_sb *= nums[r];
            while(pro_sb >= k) {
                pro_sb /= nums[l];
                l++;
            }
            sb_cnt += (r - l + 1);
        }
        return sb_cnt;
    }
};