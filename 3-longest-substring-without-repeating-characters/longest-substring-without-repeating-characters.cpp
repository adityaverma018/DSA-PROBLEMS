#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        
        std::unordered_map<char, int> charMap;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

           
            if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left) {
               
                left = charMap[currentChar] + 1;
            }

           
            charMap[currentChar] = right;

           
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
