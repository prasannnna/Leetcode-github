class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1, maxi = 1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i]) {
                cnt++;
            } else {
                cnt = 1; 
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};