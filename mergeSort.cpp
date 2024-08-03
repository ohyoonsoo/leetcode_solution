#include <vector>
#include <iostream>

template <typename RandItr>
void mergeSort(RandItr begin, RandItr end) {
    auto mid = begin + (end - begin) / 2;
    std::vector<typename RandItr::value_type> temp;
    if (end - begin == 1) { // if it has only one element
        return;
    }
    mergeSort(begin, mid);
    mergeSort(mid, end);

    auto i { begin };
    auto j { mid };
    while (i < mid && j < end) {
        if (*i > *j) {
            temp.push_back(*j++);
        }
        else {
            temp.push_back(*i++);
        }
    }

    if (i == mid) {
        while (j < end) {
            temp.push_back(*j++);
        }
    }
    else {
        while (i < mid) {
            temp.push_back(*i++);
        }
    }
    for(int i { 0 }; i < end - begin; i++) {
        *(begin + i) = temp.at(i);
    }
}


int main() {
    std::vector<int> vec = {3, 1, 2, 4};
    mergeSort(vec.begin(), vec.end());
    for(auto val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}