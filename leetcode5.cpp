#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        string max_s;
        for (int i = 1; i < 2 * length; i++) {
            int center = i / 2;
            if (i % 2 == 1) {
                int radius { 1 };
                while (center - radius >= 0 && center + radius < length) {
                    if (s[center - radius] != s[center + radius]) { break; }
                    else { radius++;}
                }
                string ss = s.substr(center - radius + 1, 2 * radius - 1);
                if(max_s.length() < ss.length()) { max_s = ss; }
            }
            else {
                int radius { 1 };
                while (center - radius >= 0 && center + radius <= length) {
                    if(s[center - radius] != s[center + radius - 1]) { break; }
                    else { radius++; }
                }
                if(radius == 1) {
                    continue;
                }
                else {
                    string ss = s.substr(center - radius + 1, 2 * radius - 2);
                    if(max_s.length() < ss.length()) { max_s = ss;}
                }
            }
        }
        return max_s;
    }
};

int main() {
    Solution solution;
    string input;
    cin >> input;
    cout << solution.longestPalindrome(input) << endl;
    return 0;
}