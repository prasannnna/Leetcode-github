class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end()), low = 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long hrs = 0;
            for(int pile : piles) {
                hrs += (pile + mid - 1) / mid;
            }
            if(hrs <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};