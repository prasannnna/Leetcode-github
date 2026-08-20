class Solution {
public:
    bool canSplit(vector<int>&nums, int k, int maxVal) {
        int sum = 0, parts = 1;
        for(int num : nums) {
            if(sum + num <= maxVal) {
                sum += num;
            } else {
                parts++;
                sum = num;
            }
        }
        if(parts <= k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canSplit(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};