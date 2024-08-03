#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left { 0 };
        int right = height.size() - 1;
        int maxArea { 0 };
        int currArea { 0 };
        
        while (left < right) {
            currArea = min(height.at(right), height.at(left)) * (right - left);
            maxArea = max(maxArea, currArea);

            if (height.at(right) > height.at(left)) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> height {1,1};
    cout << solution.maxArea(height) << std::endl;

    return 0;
}