#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int closest = nums.at(0) + nums.at(1) + nums.at(2);
            mergeSort(nums, 0, nums.size() - 1);
            for (int i { 0 }; i < nums.size(); i++) {
                while (i > 0 && i < nums.size() && nums.at(i) == nums.at(i - 1)) {
                    i++;
                }
                int j = i + 1;
                int k = nums.size() - 1;
                int temp;
                while (j < k) {
                    cout << i << " " << j << " " << k << endl;
                    temp = nums.at(i) + nums.at(j) + nums.at(k);
                    if (temp > target) {
                        if (abs(temp - target) < abs(closest - target)) {
                        cout << "closest updata : " << closest << " --> " << temp << endl;
                        closest = temp;
                        }
                        k--;
                    }
                    else if (temp < target) {
                        if (abs(temp - target) < abs(closest - target)) {
                        cout << "closest updata : " << closest << " --> " << temp << endl;
                        closest = temp;
                        }
                        j++;
                    }
                    else {
                        return temp;
                    }
                }
            }
            return closest;
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
    vector<int> nums = {2,3,8,9,10};
    int target = 16;
    cout <<solution.threeSumClosest(nums, target) << endl;
}