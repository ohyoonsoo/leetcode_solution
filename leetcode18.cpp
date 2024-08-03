#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i { 0 }; i < nums.size(); i++) {
            if (i > 0 && nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            for (int j { i + 1 }; j < nums.size(); j++) {
                if (j > i + 1 && nums.at(j) == nums.at(j - 1)) {
                    continue;
                }
                int k = j + 1;
                int p = nums.size() - 1;
                while (k < p) {
                    long long temp = static_cast<long long>(nums.at(i)) + nums.at(j) + nums.at(k) + nums.at(p);
                    if (temp > target) {
                        p--;
                    }
                    else if (temp < target) {
                        k++;
                    } 
                    else {
                        result.push_back({nums.at(i), nums.at(j), nums.at(k), nums.at(p)});
                        k++;
                        while(k < p && nums.at(k) == nums.at(k - 1)) {
                            k++;
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    vector<vector<int>> result;
    int input { 0 };
    int target;
    cout << "enter the integer vector" << endl;
    while(true) {
        cin >> input;
        if(input == -100) {
            break;
        }
        nums.push_back(input);
    }
    cout << "enter the target value" << endl;
    cin >> target;
    result = solution.fourSum(nums, target);
    cout << "result" << endl;
    for(vector<int> mvec : result) {
        for(int val : mvec) {
            cout << val << " ";
        }
        cout << endl;
    }
    
}