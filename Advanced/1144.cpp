#include <iostream>
#include <set>

int main() {
    int N, i, n;
    std::set<int> a;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> n;
        a.insert(n);
    }
    int index = 1;
    if(index > *a.rbegin()) {
        std::cout << index;
    } else {
        for(int s:a) {
            if(index == s) {
                index++;
            } else if(index < s) {
                std::cout << index;
                return 0;
            }
        }
        std::cout << index;
    }
    return 0;
}
