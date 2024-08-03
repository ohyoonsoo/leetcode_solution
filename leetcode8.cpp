#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int length = s.length();
        int pos { 0 };
        int max = pow(2, 31) - 1;
        int min = (-1) * pow(2, 31);
        int result { 0 };
        int exp;
        vector<int> max_vec = makeVec(max);
        vector<int> min_vec = makeVec(min);
        bool posSign { true };
        vector<int> vec;

        // std::cout << length << std::endl;

        // ignore the space
        while (s[pos] == ' ') {
            pos++;
        }

        // check the sign
        if (s[pos] == '+') {
            pos++;
        }
        else if (s[pos] == '-') {
            posSign = false;
            pos++;
        }

        //ignore the 0
        while(s[pos] == '0') {
            pos++;
        }

        // main process
        for (int i { pos }; i < length; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                vec.push_back(static_cast<int>(s[i]) - static_cast<int>('0'));
            }
            else {
                break;
            }
        }
        if(vec.empty()) {
            vec.push_back(0);
        }

        std::cout << "printing vec" << std::endl; // debug
        for(auto& val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        // validation check
        if (posSign) {
            if (vec.size() > max_vec.size()) {
                return max;
            }
            else if (vec.size() == max_vec.size()) {
                for (int i { 0 }; i < vec.size(); i++) {
                    if (vec[i] < max_vec[i]) {
                        break;
                    }
                    else if (vec[i] == max_vec[i]) {
                        continue;
                    }
                    else {
                        return max;
                    }
                }
            }

        }
        else {
            for(auto& val : vec) {
                val *= (-1);
            }
            if(vec.size() > min_vec.size()) {
                return min;
            }
            else if(vec.size() == min_vec.size()) {
                for(int i { 0 }; i < vec.size(); i++) {
                    if(vec[i] > min_vec[i]) {
                        break;
                    }
                    else if(vec[i] == min_vec[i]) {
                        continue;
                    }
                    else {
                        return min;
                    }
                }
            }
        }

        // calculate result
        exp = vec.size() - 1;
        for (int i { 0 }; i < vec.size(); i++) {
            result += vec[i] * pow(10, exp);
            exp--;
        }

        return result;
    }

    std::vector<int> makeVec(int s) {
        std::vector<int> result;
        if(s > 0) {
            while (s >= 10) {
                result.push_back(s % 10);
                s /= 10;
            }
        }
        else {
            while(s <= -10) {
                result.push_back(s % 10);
                s /= 10;
            }
        }
        result.push_back(s);
        for (int i { 0 }; i < result.size() / 2; i++) {
            int temp = result[i];
            result[i] = result[result.size() - 1 - i];
            result[result.size() - 1 - i] = temp;
        }
        // debug
        // for (auto& val : result) {
        //     std::cout << val << "\t";
        // }
        // std::cout << std::endl;
        return result;
    }
};


int main() {
    Solution solution;
    string s = "  0000000000012345678";
    std::cout << solution.myAtoi(s) << std::endl;

    return 0;
}