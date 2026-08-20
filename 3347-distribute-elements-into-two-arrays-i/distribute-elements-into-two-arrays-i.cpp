class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        for(int i = 0; i < nums.size(); i++) {
           if(arr1.empty()) {
            arr1.push_back(nums[i]);
            continue;
           }
           if(arr2.empty()) {
            arr2.push_back(nums[i]);
            continue;
           }
           if(arr1.back() > arr2.back()) {
            arr1.push_back(nums[i]);
           }
           else if(arr2.back() > arr1.back()) {
            arr2.push_back(nums[i]);
           }
        }
        vector<int>arr = arr1;
        for(int i : arr2) {
            arr.push_back(i);
        }
        return arr;
    }
};