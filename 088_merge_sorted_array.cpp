class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        else if (m == 0) {
            nums1 = nums2;
            return;
        }
        
        vector<int> result;
        result.reserve(m+n);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
            } else {
                result.push_back(nums2[j]);
                ++j;
            }
        }
        if (i < m)
            for (; i < m; ++i)
                result.push_back(nums1[i]);
        else
            for (; j < n; ++j)
                result.push_back(nums2[j]);
        nums1 = result;
    }
};
