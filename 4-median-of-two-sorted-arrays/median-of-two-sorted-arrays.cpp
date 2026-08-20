class Solution {
public:
    vector<int>merge(vector<int>&nums1, vector<int>&nums2) {
        vector<int>tmp;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                tmp.push_back(nums1[i++]);
            } else {
                tmp.push_back(nums2[j++]);
            }
        }
        while(i < m) {
            tmp.push_back(nums1[i++]);
        }
        while(j < n) {
            tmp.push_back(nums2[j++]);
        }
        return tmp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr = merge(nums1, nums2);
        int mid = arr.size() / 2;
        if(arr.size() % 2 == 0) {
            return (double)(arr[mid] + arr[mid - 1]) / 2;
        } 
        return (double)arr[mid];

    }
};