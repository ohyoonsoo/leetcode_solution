#include <iostream>
#include <vector>
#include <cmath>

class Solution {
    public:
        int reverse(int x) {
            int max = pow(2, 31) - 1;
            int min = (-1) * pow(2, 31);
            int exp;
            int result { 0 };
            std::vector<int> vec = createVec(x);
            std::vector<int> max_vec = createVec(max);
            std::vector<int> min_vec = createVec(min);
            max_vec = changeOrder(max_vec);
            min_vec = changeOrder(min_vec);
            
            // Validation check
            if (x > 0) {
                if (vec.size() > max_vec.size()) {
                    return 0;
                }
                else if (vec.size() == max_vec.size()) {
                    for(int i { 0 }; i < vec.size(); i++) {
                        if(vec.at(i) < max_vec.at(i)) {
                            break;
                        }
                        else if (vec.at(i) == max_vec.at(i)) {
                            continue;
                        }
                        else {
                            return 0;
                        }
                    }
                }
            }
            else {
                if (vec.size() > min_vec.size()) {
                    return 0;
                }
                else if(vec.size() == min_vec.size()) {
                    for(int i { 0 }; i < vec.size(); i++) {
                        if(vec.at(i) > min_vec.at(i)) {
                            break;
                        }
                        else if (vec.at(i) == min_vec.at(i)) {
                            continue;
                        }
                        else {
                            return 0;
                        }
                    }
                }
            }
            exp = vec.size() - 1;
            for(auto& val : vec) {
                result += val * pow(10, exp);
                exp--;
            }
            return result;
        }

        std::vector<int> createVec(int x) {
            std::vector<int> result;
            if (x > 0){
                while(x >= 10) {
                    result.push_back(x % 10);
                    x /= 10;
                }
            }
            else {
                while(x <= -10) {
                    result.push_back(x % 10);
                    x /= 10;
                }
            }

            result.push_back(x);
            return result;
        }
        std::vector<int> changeOrder(std::vector<int>& vec) {
            for (int i { 0 }; i < vec.size() / 2; i++) {
                int temp = vec.at(i);
                vec.at(i) = vec.at(vec.size() - 1 - i);
                vec.at(vec.size() - 1 - i) = temp;
            }
            return vec;
        }
};

int main() {
    Solution solution;
    int x;
    std::cin >> x;
    std::cout << solution.reverse(x) << std::endl;
}