#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string open { "({["};
        string close {")}]"};
        if(s.empty()) {
            return true;
        }
        for (int i { 0 }; i < s.length(); i++) {
            int pos;
            if((pos = close.find(s.at(i))) != string::npos) {
                if(i > 0 && s.at(i - 1) == open.at(pos)) {
                    string next_s;
                    next_s = (i == 1) ? "" : s.substr(0, i - 1);
                    next_s += (i == s.length() - 1) ? "" : s.substr(i + 1); 
                    return isValid(next_s);
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "({})";
    std::cout << (solution.isValid(s) ? "true" : "false") << std::endl;
    

    return 0;
}