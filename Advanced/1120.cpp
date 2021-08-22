#include <iostream>
#include <set>

int calID(const std::string& s) {
    int cnt = 0;
    for (auto c: s) {
        cnt += c - '0';
    }
    return cnt;
}

int main() {
    int N;
    std::set<int> friendID;
    std::cin >> N;

    std::string s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        friendID.insert(calID(s));
    }

    printf("%d\n", friendID.size());
    for (auto i: friendID) {
        if (i != *friendID.begin()) printf(" ");
        printf("%d", i);
    }

    return 0;
}