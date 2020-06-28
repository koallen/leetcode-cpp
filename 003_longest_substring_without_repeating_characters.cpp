class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        
        int length = s.length();
        int start = 0, longestLength = 0, currLength = 0;
        for (int i = 0; i < length; ++i) {
            auto it = seen.find(s[i]);
            if (it != seen.end() && it->second >= start) {
                // we have seen this before
                currLength = i - start;
                longestLength = max(longestLength, currLength);
                start = it->second + 1; //advance start
            }
            seen[s[i]] = i;
        }
        
        longestLength = max(longestLength, (length - start));
        return longestLength;
    }
};
