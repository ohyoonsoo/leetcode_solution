#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            mergeSort(nums, 0, nums.size() - 1);
            for (int i { 0 }; i < nums.size(); i++) {
                if (i > 0 && nums.at(i) == nums.at(i - 1)) {
                    continue;
                }
                int j = i + 1;
                int k = nums.size() - 1;
                while (j < k) {
                    cout << i << " " << j << " " << k << endl;
                    int temp = nums.at(i) + nums.at(j) + nums.at(k);
                    if (temp > 0) {
                        k--;
                    }
                    else if (temp < 0) {
                        j++;
                    }
                    else {
                        result.push_back({nums.at(i), nums.at(j), nums.at(k)});
                        j++;
                        while (nums.at(j) == nums.at(j - 1) && j < k) {
                            j++;
                        }
                        
                    }
                }
            }
            return result;
        }
        void mergeSort(vector<int>& nums, size_t begin, size_t end) {
            auto mid = begin + (end - begin) / 2;
            auto i = begin;
            auto j= mid + 1;
            vector<int> temp;
            if (begin == end) {
                return;
            }
            mergeSort(nums, begin, mid);
            mergeSort(nums, mid + 1, end);
            while (i <= mid && j <= end) {
                if (nums.at(i) > nums.at(j)) {
                    temp.push_back(nums.at(j++));
                }
                else {
                    temp.push_back(nums.at(i++));
                }
            }
            if (i > mid) {
                while (j <= end) {
                    temp.push_back(nums.at(j++));
                }
            }
            else if (j > end) {
                while (i <= mid) {
                    temp.push_back(nums.at(i++));
                }
            }
            for (int val : temp) {
                nums.at(begin++) = val;
            }
        }

};

int main() {
    Solution solution;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = solution.threeSum(nums);
    for (vector<int> vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
}