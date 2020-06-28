class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        
        int length = s.length();
        int start = 0;
        int longestLength = 0;
        int currLength = 0;
        for (int i = 0; i < length; ++i) {
            if (seen.find(s[i]) != seen.end() && seen[s[i]] >= start) {
                // we have seen this before
                currLength = i - start;
                longestLength = max(longestLength, currLength);
                start = seen[s[i]] + 1; //advance start
            }
            seen[s[i]] = i;
        }
        
        longestLength = max(longestLength, (length - start));
        return longestLength;
    }
};
