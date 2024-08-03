#include <iostream>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string open = "({[";
        string close = ")}]";
        for (int i { 0 }; i < s.length(); i++) {
            int pos;
            if ((pos = close.find(s.at(i))) != string::npos) {
               if (!st.empty() && st.top() == open.at(pos)) {
                st.pop();
               } 
               else {
                return false;
               }
            }
            else {
                st.push(s.at(i));
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string s = "()[]{}";
    std::cout << (solution.isValid(s) ? "true" : "false") << std::endl;

    return 0;
}