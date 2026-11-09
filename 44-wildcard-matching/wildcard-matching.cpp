#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, matchIdx = -1;
        
        while (sIdx < s.length()) {
            // Case 1: Direct match or '?'
            if (pIdx < p.length() && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } 
            // Case 2: Encountered '*' - record its position and current string index
            else if (pIdx < p.length() && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++;
            } 
            // Case 3: Mismatch, but we saw a '*' previously - backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                matchIdx++;
                sIdx = matchIdx;
            } 
            // Case 4: Mismatch and no '*' to fall back on
            else {
                return false;
            }
        }
        
        // Check remaining characters in pattern (must all be '*')
        while (pIdx < p.length() && p[pIdx] == '*') {
            pIdx++;
        }
        
        return pIdx == p.length();
    }
};