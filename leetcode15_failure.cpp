#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int zeroPos1 { 0 }, zeroPos2 { 0 }, x, y, z;
        
        // sort the given input integer vetor.
        mergeSort(nums, 0, nums.size() - 1);

        for (auto val : nums) {
            cout << val << " ";
        }
        cout << endl;

        // find the zeros' position.
        while (zeroPos1 < nums.size() && nums.at(zeroPos1) < 0) {
            zeroPos1++;
        }
        zeroPos2 = zeroPos1;
        while (zeroPos2 < nums.size() && nums.at(zeroPos2) == 0) {
            zeroPos2++;
        }
        zeroPos2--;
        // now let's find the triples.

        // case 1. three zeros

        if (zeroPos2 - zeroPos1 >= 2){
            cout << "case 1 input : " << 0 << " " << 0 << " " << 0 << endl;
            push_noDup(result, {0, 0, 0});
        }

        // if there's no negative int, or no positive int
        cout << zeroPos1 << endl;
        if(zeroPos1 == 0 || zeroPos1 == nums.size()) {
            return result;
        }

        // case 2. one negative, one zero, one positive
        cout << "case 2" << endl;
        x = zeroPos1 - 1;
        z = zeroPos2 + 1;
        if(zeroPos1 <= zeroPos2) {
            while (x >= 0 && z <= nums.size() - 1) {
                cout << "x : " << x << ", y : zero" << ", z : " << z << endl;
                if (nums.at(x) + nums.at(z) == 0) {
                    cout << "case 2 input : " << nums.at(x) << " " << 0 << " " << nums.at(z) << endl;
                    push_noDup(result, {nums.at(x), 0, nums.at(z)});
                    x--;
                }
                else if (nums.at(x) + nums.at(z) > 0) {
                    x--;
                }
                else {
                    z++;
                }
            }
        }

        // case 3. two negative, one positive
        cout << "case 3" << endl;
        for (z = zeroPos2 + 1; z < nums.size(); z++) {
            for (y = zeroPos1 - 1; y > 0; y--) {
                for (x = y - 1; x >= 0; x--) {
                    cout << "x : " << x << ", y : " << y << ", z : " << z << endl;
                    int temp = nums.at(x) + nums.at(y) + nums.at(z);
                    if(temp == 0) {
                        cout << "case 3 input : " << nums.at(x) << " " << nums.at(y) << " " << nums.at(z) << endl;
                        push_noDup(result, {nums.at(x), nums.at(y), nums.at(z)});
                    }
                    else if (temp < 0) {
                        goto nextZ;
                    }
                }
                nextZ:
            }
        }

        // case4. one negative, two positive
        cout << "case 4" << endl;
        for (x = zeroPos1 - 1; x >= 0; x--) {
            for (y = zeroPos2 + 1; y < nums.size() - 1; y++) {
                for (z = y + 1; z < nums.size(); z++) {
                    cout << "x : " << x << ", y : " << y << ", z : " << z << endl;
                    int temp = nums.at(x) + nums.at(y) + nums.at(z);
                    if(temp == 0) {
                        cout << "case 4 input : " << nums.at(x) << " " << nums.at(y) << " " << nums.at(z) << endl;
                        push_noDup(result, {nums.at(x), nums.at(y), nums.at(z)});
                    }
                    else if (temp  > 0) {
                        goto nextX;
                    }
                }
                nextX:
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
    void push_noDup(vector<vector<int>>& vec, vector<int> element) {
        bool duplicate { false };
        for (vector<int> mvec : vec) {
            for(int i { 0 }; i < 3; i++) {
                if(mvec.at(i) != element.at(i)) {
                    break;
                }
                else {
                    if(i == 2) {
                        cout << "duplicated vector insert occured" << endl; // debug
                        return;
                    }
                }
            }
        }
        vec.push_back(element);
    } 
};

int main() {
    Solution solution;
    vector<int> nums = {-4,-2,-1};
    try {
    vector<vector<int>> result = solution.threeSum(nums);
    
    cout << "result : " << endl;
    for (vector<int> vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    } catch (const out_of_range& arg) {
        cout << arg.what() << endl;
    }
}