#include <iostream>

std::string imbed(std::string s) {
    std::string res;
    int i, j;
    for (i = 0; i < s.size(); i = j) {
        j = i + 1;
        while (s[i] == s[j] && j < s.size()) j++;
        res.push_back(s[i]);
        res.append(std::to_string(j-i));
    }
    return res;
}

int main() {
    int D, N, i;
    std::cin >> D >> N;

    std::string pre;
    pre.append(std::to_string(D));
    for (i = 1; i < N; i++) {
        pre = imbed(pre);
    }

    std::cout << pre;
    return 0;
}