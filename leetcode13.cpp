#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result { 0 };
        int pos { 0 };
        while(pos < s.length() && s.at(pos) == 'M') {
            result += 1000;
            pos++;
        }
        result += caseFunc(s, pos, 'C', 'D', 'M', 100);
        result += caseFunc(s, pos, 'X', 'L', 'C', 10);
        result += caseFunc(s, pos, 'I', 'V', 'X', 1);
        return result;
    }
    
    int caseFunc(const string& s, int& pos, const char& one, const char& five, const char& ten, int exp) {
        int result { 0 };
        if(pos < s.length() && s.at(pos) == one) {
            if(pos < s.length() - 1 && s.at(pos + 1) == five) {
                result += 4 * exp;
                pos += 2;
            }
            else if(pos < s.length() - 1 && s.at(pos + 1) == ten) {
                result += 9 * exp;
                pos += 2;
            }
            else {
                while(pos < s.length() && s.at(pos) == one) {
                    result += exp;
                    pos++;
                }
                return result;
            }
        }
        if(pos < s.length() && s.at(pos) == five) {
            result += 5 * exp;
            pos++;
            while(pos < s.length() && s.at(pos) == one) {
                result += exp;
                pos++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;
    cout << solution.romanToInt(s) << endl;
}