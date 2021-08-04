#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define NASCII 136

int main() {
    std::string A, B;
    std::getline(std::cin, A, '\n');
    std::getline(std::cin, B, '\n');
    typedef std::pair<char, int> Set;
    int dict[NASCII], i;

    memset(dict, 0, sizeof(dict));
    for (i = 0; i < A.size(); i++) {
        if (!dict[A[i]]) {
            dict[A[i]] = i + 1;
        }
    }
    for (i = 0; i < B.size(); i++) {
        if (!dict[B[i]]) {
            dict[B[i]] = i + A.size() + 1;
        }
    }

    std::vector<Set> set;
    for (i = 0; i < NASCII; i++) {
        if (dict[i]) set.emplace_back(i, dict[i]);
    }
    std::sort(set.begin(), set.end(), [](const Set &a, const Set &b) { return a.second < b.second; });
    for(Set s: set) {
        std::cout << s.first;
    }
    return 0;
}