#include <unordered_map>
#include <string>
#include <algorithm>

#include "lengthOfLongestSubstring.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndexMap; // To store the index of characters
        int maxLength = 0; // Maximum length of substring without repeating characters
        int start = 0; // Start of the current window
        
        for (int end = 0; end < s.size(); ++end) {
            char currentChar = s[end];
            
            // If the character is already in the map and its index is >= start
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                // Move start to the right of the last occurrence of currentChar
                start = charIndexMap[currentChar] + 1;
            }
            
            // Update the last seen index of the current character
            charIndexMap[currentChar] = end;
            
            // Update the maximum length
            maxLength = std::max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
