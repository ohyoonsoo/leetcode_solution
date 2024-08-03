#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        poistionOfEachChar(s);
        return lengthOfLongestSubstring(0, 0, s.length() - 1);      
    }
    void poistionOfEachChar(string s) {
        std::vector<char> char_vect;
        for (int i { 0 }; i < s.length(); i++) {
            bool find { false };
            for (int j { 0 }; j < char_vect.size(); j++) {
                if(char_vect.at(j) == s.at(i)) {
                    m_pos_vect.at(j)->push_back(i);
                    find = true;
                }
            }
            if(!find) {
                char_vect.push_back(s.at(i));
                m_pos_vect.push_back(new std::vector<int>);
                m_pos_vect.back()->push_back(i);
            }
        }
        std::cout << "postionOfEachChar called : " << std::endl;
        for (auto& vect : m_pos_vect) {
            for (auto& val : *vect) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    int lengthOfLongestSubstring(int level, int front, int end) {
        int max { 0 };
        int first_position, last_position;
        if(true) {
        std::cout << "lengthOfLongestSubstring called : " << level << " " << front << " " << end << std::endl;
        }
        if(level == m_pos_vect.size()) {
            std::cout << end - front + 1 << std::endl;
            return end - front + 1; 
        }
        vector<int> vect = *m_pos_vect.at(level);
        first_position = vect.size() - 1;
        last_position = 0;
        for (int i { 0 }; i < vect.size(); i++) {
            if(first_position > i && vect.at(i) >= front) {
                first_position = i;
            }
            if(last_position < i && vect.at(i) <= end) {
                last_position = i;
            }
        }
        // std::cout << "first positon : " << first_position << ", last_position : " << last_position << std::endl;
        if (first_position == vect.size() - 1 && last_position == 0) { // can't find the position in the range.
            return lengthOfLongestSubstring(level + 1, front, end);
        }
        else if (first_position == last_position) { // find only one positon in the range.
            return lengthOfLongestSubstring(level + 1, front, end);
        }
        for (int i { first_position }; i <= last_position; i++) {
            int next_front, next_end;
            int length;
            if (i == first_position) {
                next_front = front;
                next_end = vect.at(i + 1) - 1;
            }
            else if(i == last_position) {
                next_front = vect.at(i - 1) + 1;
                next_end = end;
            }
            else {
                next_front = vect.at(i - 1) + 1;
                next_end = vect.at(i + 1) - 1;
            }
            length = lengthOfLongestSubstring(level + 1, next_front, next_end);

            if (max < length) {
                max = length;
            }
        }
        return max;
    }

    private:
        std::vector<std::vector<int>*> m_pos_vect;
        int m_level { 0 };
};

int main() {
    Solution sol;
    string input;
    cin >> input;
    std::cout << "lenght of input : " << input.length() << std::endl;
    std::cout << sol.lengthOfLongestSubstring(input) << std::endl;
}