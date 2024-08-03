#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> data;
        vector<string> result;
        unordered_set<string> set;
        unordered_set<string> new_set;
    
        data.push_back({"a", "b", "c"});        // 2
        data.push_back({"d", "e", "f"});        // 3
        data.push_back({"g", "h", "i"});        // 4
        data.push_back({"j", "k", "l"});        // 5
        data.push_back({"m", "n", "o"});        // 6
        data.push_back({"p", "q", "r", "s"});   // 7
        data.push_back({"t", "u", "v"});        // 8
        data.push_back({"w", "x", "y", "z"});   // 9

        for (int i { 0 }; i < digits.length(); i++) {
            int input = static_cast<int>(digits[i]) - static_cast<int>('0');
            if (i == 0) {
                for (auto val : data.at(input - 2)) {
                    set.insert(val);
                }
            }
            else {
                for (auto val : data.at(input - 2)) {
                    for(auto str : set) {
                        // for (int j { 0 }; j < str.length(); j++) {
                        //     string temp = str.substr(0, j) + val + str.substr(j);
                        //     new_set.insert(temp);
                        // }
                        new_set.insert(str + val);
                    }
                }
                set = new_set;
                new_set.clear();
            }
        }
        for(auto val : set) {
            result.push_back(val);
        }
        return result;
    }
};

int main() {
    Solution solution;
    string digits;
    cin >> digits;
    vector<string> result = solution.letterCombinations(digits);

    for(auto val : result) {
        cout << val << " ";
    }
    cout << endl;
}