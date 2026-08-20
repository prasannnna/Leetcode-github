class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high) {
            int reqDays = 1, sum = 0;
            int mid = low + (high - low) / 2;
            for(int weight : weights) {
                if(sum + weight > mid) {
                    sum = 0;
                    reqDays++;
                }
                sum += weight;
            }
            if(reqDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};