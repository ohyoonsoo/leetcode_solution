#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result { 0 };
        int pos { 0 };
        unordered_map<char, int> map;
        map.insert({'I', 1});
        map.insert({'V', 5});
        map.insert({'X', 10});
        map.insert({'L', 50});
        map.insert({'C', 100});
        map.insert({'D', 500});
        map.insert({'M', 1000});

        while(pos < s.length()) {
            if(pos < s.length() - 1 && map.at((s.at(pos))) < map.at(s.at(pos + 1))){
                result -= map.at(s.at(pos));
            }
            else {
                result += map.at(s.at(pos));
            }
            pos++;
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