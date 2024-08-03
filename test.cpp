#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

template<typename Iter>
void print(const Iter& beg, const Iter& end, bool new_line = true)
{
    std::for_each(beg, end, [](auto& i) { std::cout << i << " "; });
    if (new_line) {
        std::cout << std::endl;
    }
}

template<typename Iter>
void merge(Iter beg, Iter mid, Iter end)
{
    std::vector<typename Iter::value_type> temp;
    temp.reserve(std::distance(beg, end));

    std::cout << "merge "; print(beg, mid, false); std::cout << "↔ "; print(mid, end);
    Iter left = beg;
    Iter right = mid;
    while (left != mid and right != end) {
        if (*right < *left) {
            temp.emplace_back(*right++);
        }
        else {
            temp.emplace_back(*left++);
        }
    }
    temp.insert(temp.end(), left, mid);
    temp.insert(temp.end(), right, end);

    std::move(temp.begin(), temp.end(), beg);
    std::cout << " ⇒    "; print(beg, end);
}

template<typename Iter>
void merge_sort(Iter beg, Iter end)
{
    std::cout << "sort  "; print(beg, end);

    int size = std::distance(beg, end);
    if (size <= 1) {
        return;
    }

    auto mid = std::next(beg, size / 2);
    // sort left half
    merge_sort(beg, mid);
    // sort right half
    merge_sort(mid, end);
    // merge halves
    merge(beg, mid, end);
}

int main(int argc, const char* argv[])
{
    std::list<int> l = {2, 5, 1, 7, 9, 2, 4, 3, 8, 11};
    merge_sort(l.begin(), l.end());
    std::cout << "done  "; print(l.begin(), l.end());
    return 0;
}