#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string roman;
        if (num >= 1000) {
            int thousands = num / 1000;
            for (int i  { 0 }; i < thousands; i++) {
                roman += 'M';
            }
            num %= 1000;
        }
        if (num >= 100) {
            int hundreds = num / 100;
            caseFunc(roman, "C", "D", "M", hundreds);
            num %= 100;
        }
        if (num >= 10) {
            int tens = num / 10;
            caseFunc(roman, "X", "L", "C", tens);
            num %= 10;
        }
        if (num != 0) {
            caseFunc(roman, "I", "V", "X", num);
        }
        return roman;
    }
    void caseFunc(string& roman, const string& one, const string& five, const string& ten, int num) {
        switch(num) {
            case 1: [[fallthrough]];
            case 2: [[fallthrough]];
            case 3: 
                for (int i { 0 }; i < num; i++) {
                    roman += one;
                }
                break;
            case 4:
                roman += (one + five);
                break;
            case 5: [[fallthrough]];
            case 6: [[fallthrough]];
            case 7: [[fallthrough]];
            case 8:
                roman += five;
                for (int i { 5 }; i < num; i++) {
                    roman += one;
                }
                break;
            case 9:
                roman += (one + ten);
                break;
            default: roman = one + " error";
        }
    }
};


int main() {
    Solution solution;
    int num;
    cin >> num;
    cout << solution.intToRoman(num) << endl;
}