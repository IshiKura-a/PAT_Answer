#include <iostream>
#include <vector>

int main() {
    std::string num;
    std::cin >> num;
    std::vector<std::string> digit = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    std::vector<std::string> item = {"Qian", "Bai", "Shi"};
    std::vector<std::string> res;

    if (num[0] == '-') {
        res.emplace_back("Fu");
        num = num.substr(1, num.length() - 1);
    }

    if (num.length() > 8) {
        res.push_back(digit[num[0] - '0']);
        res.emplace_back("Yi");
        num = num.substr(1, num.length() - 1);
    }

    bool flag = false;
    if (num.length() > 4) {
        auto p = num.substr(0, num.length() - 4);
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '0') {
                flag = true;
            } else {
                if (flag) {
                    res.emplace_back("ling");
                    flag = false;
                }
                res.push_back(digit[p[i] - '0']);
                if (i + 4 - p.size() < item.size()) res.push_back(item[i + 4 - p.size()]);
            }
        }
        res.emplace_back("Wan");
        num = num.substr(p.length(), 4);
    }

    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '0') {
            flag = true;
        } else {
            if (flag) {
                res.emplace_back("ling");
                flag = false;
            }
            res.push_back(digit[num[i] - '0']);
            if (i + 4 - num.size() < item.size()) res.push_back(item[i + 4 - num.size()]);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if (i) printf(" ");
        std::cout << res[i];
    }

    if (!res.size()) printf("ling");
    return 0;
}