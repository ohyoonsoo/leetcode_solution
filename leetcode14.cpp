#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonStr;
        for (int i { 0 }; i < strs.size(); i++) {
            if (i == 0) {
                commonStr = strs.at(i);
            }
            else {
                while(commonStr.length() > 0) {
                    if(strs.at(i).find(commonStr) == 0) {
                        break;
                    }
                    else {
                        commonStr = commonStr.substr(0, commonStr.length() - 1);
                    }
                }
                if(commonStr.length() == 0) {
                    return "";
                }
            }
       }
       return commonStr;
    }
};


int main() {
    Solution solution;
    vector<string> strs {"c","acc","ccc"};
    cout << solution.longestCommonPrefix(strs) << endl;
}