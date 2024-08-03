#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int length = s.length();
        int modular = 2 * numRows - 2;
        
        if(numRows == 1) {
            return s;
        }
        for(int i { 0 }; i < numRows; i++) {
            if(i == 0) {
                int num { 0 };
                while(num * modular < length) {
                    result += s[num * modular];
                    num++;
                }
            }
            else if(i == numRows - 1) {
                int num { 0 };
                while(num * modular + numRows - 1 < length) {
                    result += s[num * modular + numRows - 1];
                    num++;
                }
            }
            else {
                int num { 0 };
                while(num * modular + i < length) {
                    result += s[num * modular + i];
                    if((num + 1) * modular - i < length) {
                        result += s[(num + 1) * modular - i];
                    }
                    num++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << solution.convert(s, numRows) << endl;
    return 0;
}