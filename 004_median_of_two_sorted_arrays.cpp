class Solution {
public:
    double calc(vector<int>& nums1, vector<int>& nums2, int start, int end) {
        int totalNum = nums1.size() + nums2.size();
        int partX = (start + end) / 2;
        int partY = (totalNum + 1) / 2 - partX;
        
        int maxLeftX = partX == 0 ? INT_MIN : nums1[partX-1];
        int minRightX = partX == nums1.size() ? INT_MAX : nums1[partX];
        
        int maxLeftY = partY == 0 ? INT_MIN : nums2[partY-1];
        int minRightY = partY == nums2.size() ? INT_MAX : nums2[partY];
        
        // check end condition
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if (totalNum % 2 == 0) {
                // even number of total numbers
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                // odd number of total numbers
                return max(maxLeftX, maxLeftY);
            }
        }
        else if (maxLeftX > minRightY) {
            // move partX to the left
            return calc(nums1, nums2, start, partX);
        } else {
            // move partX to the right
            return calc(nums1, nums2, partX+1, end);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        return calc(nums1, nums2, 0, nums1.size());
    }
};
