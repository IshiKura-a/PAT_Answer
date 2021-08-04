#include <iostream>
#include <vector>

int main() {
    std::string n;
    std::string map[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    std::cin >> n;
    int sum = 0;
    for (char c: n) {
        sum += c - '0';
    }

    std::vector<std::string> res;
    while (sum != 0) {
        res.push_back(map[sum % 10]);
        sum /= 10;
    }

    for (auto it = res.rbegin(); it != res.rend(); it++) {
        if (it != res.rbegin()) std::cout << ' ';
        std::cout << *it;
    }

    return 0;
}