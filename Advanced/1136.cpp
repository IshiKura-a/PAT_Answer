#include <iostream>

std::string plus(std::string a, std::string b) {
    std::string res;
    auto itX = a.rbegin();
    auto itY = b.rbegin();
    int carry = 0;
    for (; itX != a.rend() && itY != a.rend(); itX++, itY++) {
        int i = *itX - '0' + *itY - '0';
        if (i + carry >= 10) {
            res.push_back(i - 10 + carry + '0');
            carry = 1;
        } else {
            res.push_back(i + carry + '0');
            carry = 0;
        }
    }
    if (carry) {
        res.push_back('1');
    }
    return std::string(res.rbegin(), res.rend());
}

int main() {
    std::string s;
    std::cin >> s;
    int i;

    std::string sRev = std::string(s.rbegin(), s.rend());
    std::string sRes = plus(s, sRev);
    for (i = 0; i < 10; i++) {
        if (sRev == s) {
            break;
        }
        std::cout << s << " + " << sRev << " = " << sRes << std::endl;
        s = sRes;
        sRev = std::string(s.rbegin(), s.rend());
        sRes = plus(s, sRev);
    }

    if (i < 10) {
        std::cout << s << " is a palindromic number.\n";
    } else {
        std::cout << "Not found in 10 iterations.\n";
    }
    return 0;
}