#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::string source, target;
    std::cin >> source >> target;

    std::transform(source.begin(), source.end(), source.begin(), ::toupper);
    std::transform(target.begin(), target.end(), target.begin(), ::toupper);
    std::set<char> good(target.begin(), target.end());
    std::set<char> bad;

    for (auto c: source) {
        if (good.count(c) == 0) {
            if(bad.count(c) == 0) {
                bad.insert(c);
                std::cout << c;
            }
        }
    }

    return 0;
}