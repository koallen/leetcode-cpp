class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int length = 0;
        int maxLen = 1;
        int maxStart = 0;
        int strLength = s.length();
        
        // handle odd palindrom
        int i = 0;
        while (i < strLength) {
            start = i;
            end = i;

            // expand to the right
            while (end + 1 < strLength && s[end] == s[end+1]) ++end;
            
            // we would skip ahead to end + 1, if we do ++i, then what
            // we find in the next iteration would be a substr of what
            // we find in this iteration (when end != start)
            i = end + 1;
            
            // now expand to both sides
            while (start - 1 >= 0 && end + 1 < strLength && s[start-1] == s[end+1]) {
                --start;
                ++end;
            }
            
            length = end - start + 1;
            if (length > maxLen) {
                maxStart = start;
                maxLen = length;
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
};
