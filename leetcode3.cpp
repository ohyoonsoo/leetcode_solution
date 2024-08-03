#include <string>
#include <unordered_set>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left { 0 };
        int max_length { 0 };
        unordered_set<char> charSet;
        for (int right { 0 }; right < s.length(); right++) {
            if(charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                max_length = max(max_length, right - left + 1);
            }
            else {
                while(charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        return max_length;
    }
};

int main() {
    Solution sol;
    string input;
    std::cin >> input;
    
    std::cout << sol.lengthOfLongestSubstring(input) << std::endl;
}