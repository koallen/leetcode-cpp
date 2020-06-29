class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnVal(2, 0);
        unordered_map<int, int> numToIndex(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            numToIndex[nums[i]] = i;
        }
        
        int numNeeded;
        for (int i = 0; i < nums.size(); ++i) {
            numNeeded = target - nums[i];
            auto it = numToIndex.find(numNeeded);
            if (it != numToIndex.end() && it->second != i) {
                returnVal[0] = i;
                returnVal[1] = it->second;
                return returnVal;
            }
        }
        return returnVal;
    }
};
